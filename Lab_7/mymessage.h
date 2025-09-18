#ifndef MYMESSAGE_H
#define MYMESSAGE_H

#include <string>
#include <mutex>
#include <cstdint>
#include <iosfwd>

// Класс MyMessage ? логгер для сообщений разных типов (ошибки, предупреждения и т.п.)
class MyMessage {
public:

    // uint8_t выбран, чтобы занимать минимум памяти (1 байт)
    enum class Type : uint8_t {
        Emergency = 0,   // авария
        Error,                  // ошибка
        Warning,             // предупреждение
        SysInfo,              // системная информация
        ServiceInfo,        // сервисная информация
        Debug                 // отладка
    };

    // Маска (битовая) для включения/выключения определённых типов сообщений
    using Mask = uint32_t;

    explicit MyMessage(Mask initialMask = allEnabled());

    // Основная функция ? вывод сообщения определённого типа
    void log(Type type, const std::string& text, const char* func = nullptr);

    void enable(Type t);                 // включить вывод определённого типа
    void disable(Type t);                // выключить вывод определённого типа
    void setMask(Mask m);            // задать маску напрямую
    Mask getMask() const;            // получить текущую маску

    // Статические вспомогательные функции:
    static Mask flag(Type t);                    // возвращает битовую маску для конкретного типа
    static Mask allEnabled();                   // маска с включёнными всеми типами
    static const char* typeToRu(Type t); // перевод типа на русский язык (строкой)

private:

    // Формирует готовую строку сообщения в удобочитаемом формате
    std::string formatLine(Type t, const std::string& text, const char* func) const;

    mutable std::mutex m_;  // mutex для защиты mask_ и вывода в многопоточном режиме
    Mask mask_;                  // текущая маска включённых типов сообщений
};

// Макросы для автоматического добавления имени функции
#define LOG_EMERG(logger, msg)   (logger).log(MyMessage::Type::Emergency,   (msg), __func__)
#define LOG_ERROR(logger, msg)   (logger).log(MyMessage::Type::Error,       (msg), __func__)
#define LOG_WARN(logger,  msg)   (logger).log(MyMessage::Type::Warning,     (msg), __func__)
#define LOG_SYS(logger,   msg)   (logger).log(MyMessage::Type::SysInfo,     (msg), __func__)
#define LOG_SVC(logger,   msg)   (logger).log(MyMessage::Type::ServiceInfo, (msg), __func__)
#define LOG_DBG(logger,   msg)   (logger).log(MyMessage::Type::Debug,       (msg), __func__)

#endif // MYMESSAGE_H
