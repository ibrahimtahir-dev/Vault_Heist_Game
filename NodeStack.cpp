#include "NodeStack.h"

NodeStack::NodeStack() : data_(nullptr), size_(0), capacity_(0) {}
NodeStack::~NodeStack() { delete[] data_; }

void NodeStack::push(TreeNode* node) {
    if (size_ == capacity_) {
        int newCap = (capacity_ == 0) ? 16 : capacity_ * 2;
        TreeNode** fresh = new TreeNode * [newCap];
        for (int i = 0; i < size_; ++i) fresh[i] = data_[i];
        delete[] data_;
        data_ = fresh;
        capacity_ = newCap;
    }
    data_[size_++] = node;
}

TreeNode* NodeStack::pop() {
    if (size_ == 0) return nullptr;
    return data_[--size_];
}

TreeNode* NodeStack::top() const { return size_ == 0 ? nullptr : data_[size_ - 1]; }
int  NodeStack::size() const { return size_; }
bool NodeStack::empty() const { return size_ == 0; }
void NodeStack::clear() { size_ = 0; }