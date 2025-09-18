#include "MyMessage.h"

// ������� �㭪�� Task_4
void Task_4() {
    MyMessage logger; // �� ⨯� ����祭�

    // �ਬ��� �뢮�� ࠧ��� ⨯�� ᮮ�饭��
    LOG_EMERG(logger, "����᪠� �訡�� ����㤮�����");             // ���਩��� ᮮ�饭��
    LOG_ERROR(logger, "���������� �뤥���� ������ ��� ������"); // ᮮ�饭�� �� �訡��
    LOG_WARN(logger,  "������ ���� ���२");                                  // �।�०�����
    LOG_SYS(logger,   "���⥬� ����㦥��");                                         // ��⥬��� ���ଠ��
    LOG_SVC(logger,   "���� �ࢨ᭠� ��楤��");                          // �ࢨ᭠� ���ଠ��
    LOG_DBG(logger,   "��६����� x = 42");                                          // �⫠��筠� ���ଠ��

    // �⪫�稬 �⫠���
    logger.disable(MyMessage::Type::Debug);
    LOG_DBG(logger, "�� ��ப� 㦥 �� �뢥�����");

}

