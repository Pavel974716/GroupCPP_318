#include "tree.h"

// ������� �㭪�� Task_4
void Task_4() {
    TreeNode root(1);
    auto* left_son   = root.AddChild(10);
    auto* middle_son = root.AddChild(20);
    auto* right_son  = root.AddChild(30);

    left_son->AddChild(100);
    left_son->AddChild(200);
    middle_son->AddChild(300);
    right_son->AddChild(400);

    root.Print();

    // �� 㧫� ���� ��⮬���᪨ �᢮�������, �.�. ��� �࠭���� � unique_ptr ����� த�⥫��.
}




