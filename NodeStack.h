#pragma once
#include "TreeNode.h"

class NodeStack {
public:
    NodeStack();
    ~NodeStack();

    void      push(TreeNode* node);
    TreeNode* pop();          
    TreeNode* top() const;    
    int       size() const;
    bool      empty() const;
    void      clear();

private:
    NodeStack(const NodeStack&);              
    NodeStack& operator=(const NodeStack&);   

    TreeNode** data_;
    int size_;
    int capacity_;
};
