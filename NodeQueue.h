#pragma once
#include "TreeNode.h"

class NodeQueue {
public:
    NodeQueue();
    ~NodeQueue();

    void      enqueue(TreeNode* node);
    TreeNode* dequeue();       
    TreeNode* front() const;   
    int       size() const;
    bool      empty() const;
    void      clear();

private:
    NodeQueue(const NodeQueue&);              
    NodeQueue& operator=(const NodeQueue&);   
    void grow();

    TreeNode** data_;
    int head_;
    int count_;
    int capacity_;
};
