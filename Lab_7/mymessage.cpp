#include "MyMessage.h"
#include <iostream>

// �ᯮ����⥫쭠� �㭪��
namespace {
    inline std::string safe_func(const char* func) {
        return func ? std::string(func) : std::string();
    }
}

// ���樠�����㥬 ���� ࠧ����� ᮮ�饭��.
MyMessage::MyMessage(Mask initialMask) : mask_(initialMask) {}

// �᭮���� �㭪�� ����஢����
void MyMessage::log(Type type, const std::string& text, const char* func) {
    const Mask bit = flag(type);
    std::lock_guard<std::mutex> lk(m_);
    if ((mask_ & bit) == 0) return; // �⪫�祭�

    std::cout << formatLine(type, text, func) << std::endl;
}

// ����祭�� ⨯� ᮮ�饭��
void MyMessage::enable(Type t)  { std::lock_guard<std::mutex> lk(m_); mask_ |= flag(t); }

// �⪫�祭�� ⨯� ᮮ�饭��
void MyMessage::disable(Type t) { std::lock_guard<std::mutex> lk(m_); mask_ &= ~flag(t); }

// ������� ��᪨ 楫����
void MyMessage::setMask(Mask m) { std::lock_guard<std::mutex> lk(m_); mask_ = m; }

// ����祭�� ⥪�饩 ��᪨
MyMessage::Mask MyMessage::getMask() const {
    std::lock_guard<std::mutex> lk(m_);
    return mask_;
}

// �८�ࠧ�� ⨯ ᮮ�饭�� � ��� (���ਬ�� 1 << 0, 1 << 1 � �.�.)
MyMessage::Mask MyMessage::flag(Type t) {
    return Mask(1u) << static_cast<uint8_t>(t);
}

// �����頥� ����, ��� �� ⨯� ᮮ�饭�� ����祭�
MyMessage::Mask MyMessage::allEnabled() {
    return flag(Type::Emergency) | flag(Type::Error) | flag(Type::Warning) |
           flag(Type::SysInfo)   | flag(Type::ServiceInfo) | flag(Type::Debug);
}

// ��ॢ�� ⨯� ᮮ�饭�� � ��ப� (���᪨� ��)
const char* MyMessage::typeToRu(Type t) {
    switch (t) {
        case Type::Emergency:   return "�����";
        case Type::Error:            return "�訡��";
        case Type::Warning:       return "�।�०�����";
        case Type::SysInfo:        return "���⥬��� ���ଠ��";
        case Type::ServiceInfo:  return "��ࢨ᭠� ���ଠ��";
        case Type::Debug:          return "�⫠���";
        default:                           return "�������⭮";
    }
}

// ��ଠ�஢���� ��ப� ��� �뢮��
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
