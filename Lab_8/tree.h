#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <memory>

class TreeNode {
private:
    int value_;
    TreeNode* parent_ = nullptr;  // ��������騩 㪠��⥫� �� த�⥫�
    std::vector<std::unique_ptr<TreeNode>> children_; // �������� ��⮬����

public:
    explicit TreeNode(int val, TreeNode* parent = nullptr)
        : value_(val), parent_(parent) {}

    TreeNode(const TreeNode&) = delete;
    TreeNode& operator=(const TreeNode&) = delete;

    TreeNode(TreeNode&&) = default;
    TreeNode& operator=(TreeNode&&) = default;

    TreeNode* AddChild(int child_value) {

        // C����� unique_ptr �� new � ����� � �����
        std::unique_ptr<TreeNode> node(new TreeNode(child_value, this));
        TreeNode* raw = node.get();           // ��������騩 㪠��⥫� ��� ������
        children_.push_back(std::move(node)); // ��।�� �������� � �����
        return raw;
    }

    void Print(int depth = 0) const {
        for (int i = 0; i < depth; ++i) std::cout << ' ';
        std::cout << "- " << value_ << "\n";
        for (const auto& child : children_) {
            child->Print(depth + 1);
        }
    }
};

#endif // TREE_H
