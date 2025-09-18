#include "MyMessage.h"
#include <iostream>

// Вспомогательная функция
namespace {
    inline std::string safe_func(const char* func) {
        return func ? std::string(func) : std::string();
    }
}

// Инициализируем маску разрешённых сообщений.
MyMessage::MyMessage(Mask initialMask) : mask_(initialMask) {}

// Основная функция логирования
void MyMessage::log(Type type, const std::string& text, const char* func) {
    const Mask bit = flag(type);
    std::lock_guard<std::mutex> lk(m_);
    if ((mask_ & bit) == 0) return; // отключено

    std::cout << formatLine(type, text, func) << std::endl;
}

// Включение типа сообщений
void MyMessage::enable(Type t)  { std::lock_guard<std::mutex> lk(m_); mask_ |= flag(t); }

// Отключение типа сообщений
void MyMessage::disable(Type t) { std::lock_guard<std::mutex> lk(m_); mask_ &= ~flag(t); }

// Задание маски целиком
void MyMessage::setMask(Mask m) { std::lock_guard<std::mutex> lk(m_); mask_ = m; }

// Получение текущей маски
MyMessage::Mask MyMessage::getMask() const {
    std::lock_guard<std::mutex> lk(m_);
    return mask_;
}

// Преобразует тип сообщения в бит (например 1 << 0, 1 << 1 и т.д.)
MyMessage::Mask MyMessage::flag(Type t) {
    return Mask(1u) << static_cast<uint8_t>(t);
}

// Возвращает маску, где все типы сообщений включены
MyMessage::Mask MyMessage::allEnabled() {
    return flag(Type::Emergency) | flag(Type::Error) | flag(Type::Warning) |
           flag(Type::SysInfo)   | flag(Type::ServiceInfo) | flag(Type::Debug);
}

// Перевод типа сообщения в строку (русский язык)
const char* MyMessage::typeToRu(Type t) {
    switch (t) {
        case Type::Emergency:   return "Авария";
        case Type::Error:            return "Ошибка";
        case Type::Warning:       return "Предупреждение";
        case Type::SysInfo:        return "Системная информация";
        case Type::ServiceInfo:  return "Сервисная информация";
        case Type::Debug:          return "Отладка";
        default:                           return "Неизвестно";
    }
}

// Форматирование строки для вывода
std::string MyMessage::formatLine(Type t, const std::string& text, const char* func) const {
    std::string line;
    line.reserve(64 + text.size());
    line += typeToRu(t);
    line += ": ";
    line += text;
    const std::string f = safe_func(func);
    if (!f.empty()) {
        line += " (";
        line += f;
        line += ')';
    }
    return line;
}
