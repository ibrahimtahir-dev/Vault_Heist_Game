#pragma once

struct TreeNode {
    int id;
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(int id_, int value_)
        : id(id_), value(value_), left(nullptr), right(nullptr), parent(nullptr) {
    }
    virtual ~TreeNode() {}   
};
