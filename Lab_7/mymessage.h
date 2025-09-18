#ifndef MYMESSAGE_H
#define MYMESSAGE_H

#include <string>
#include <mutex>
#include <cstdint>
#include <iosfwd>

// ����� MyMessage ? ������ ��� ᮮ�饭�� ࠧ��� ⨯�� (�訡��, �।�०����� � �.�.)
class MyMessage {
public:

    // uint8_t ��࠭, �⮡� �������� ������ ����� (1 ����)
    enum class Type : uint8_t {
        Emergency = 0,   // �����
        Error,                  // �訡��
        Warning,             // �।�०�����
        SysInfo,              // ��⥬��� ���ଠ��
        ServiceInfo,        // �ࢨ᭠� ���ଠ��
        Debug                 // �⫠���
    };

    // ��᪠ (��⮢��) ��� ����祭��/�몫�祭�� ��।����� ⨯�� ᮮ�饭��
    using Mask = uint32_t;

    explicit MyMessage(Mask initialMask = allEnabled());

    // �᭮���� �㭪�� ? �뢮� ᮮ�饭�� ��।��񭭮�� ⨯�
    void log(Type type, const std::string& text, const char* func = nullptr);

    void enable(Type t);                 // ������� �뢮� ��।��񭭮�� ⨯�
    void disable(Type t);                // �몫���� �뢮� ��।��񭭮�� ⨯�
    void setMask(Mask m);            // ������ ���� �������
    Mask getMask() const;            // ������� ⥪���� ����

    // ����᪨� �ᯮ����⥫�� �㭪樨:
    static Mask flag(Type t);                    // �����頥� ��⮢�� ���� ��� �����⭮�� ⨯�
    static Mask allEnabled();                   // ��᪠ � ������묨 �ᥬ� ⨯���
    static const char* typeToRu(Type t); // ��ॢ�� ⨯� �� ���᪨� �� (��ப��)

private:

    // ��ନ��� ��⮢�� ��ப� ᮮ�饭�� � 㤮���⠥��� �ଠ�
    std::string formatLine(Type t, const std::string& text, const char* func) const;

    mutable std::mutex m_;  // mutex ��� ����� mask_ � �뢮�� � ��������筮� ०���
    Mask mask_;                  // ⥪��� ��᪠ �������� ⨯�� ᮮ�饭��
};

// ������ ��� ��⮬���᪮�� ���������� ����� �㭪樨
#define LOG_EMERG(logger, msg)   (logger).log(MyMessage::Type::Emergency,   (msg), __func__)
#define LOG_ERROR(logger, msg)   (logger).log(MyMessage::Type::Error,       (msg), __func__)
#define LOG_WARN(logger,  msg)   (logger).log(MyMessage::Type::Warning,     (msg), __func__)
#define LOG_SYS(logger,   msg)   (logger).log(MyMessage::Type::SysInfo,     (msg), __func__)
#define LOG_SVC(logger,   msg)   (logger).log(MyMessage::Type::ServiceInfo, (msg), __func__)
#define LOG_DBG(logger,   msg)   (logger).log(MyMessage::Type::Debug,       (msg), __func__)

#endif // MYMESSAGE_H
