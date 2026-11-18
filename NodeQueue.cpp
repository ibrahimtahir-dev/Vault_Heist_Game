#include "NodeQueue.h"

NodeQueue::NodeQueue() : data_(nullptr), head_(0), count_(0), capacity_(0) {}
NodeQueue::~NodeQueue() { delete[] data_; }

void NodeQueue::grow() {
    int newCap = (capacity_ == 0) ? 16 : capacity_ * 2;
    TreeNode** fresh = new TreeNode * [newCap];
    for (int i = 0; i < count_; ++i) fresh[i] = data_[(head_ + i) % capacity_];
    delete[] data_;
    data_ = fresh;
    capacity_ = newCap;
    head_ = 0;
}

void NodeQueue::enqueue(TreeNode* node) {
    if (count_ == capacity_) grow();
    data_[(head_ + count_) % capacity_] = node;
    ++count_;
}

TreeNode* NodeQueue::dequeue() {
    if (count_ == 0) return nullptr;
    TreeNode* n = data_[head_];
    head_ = (head_ + 1) % capacity_;
    --count_;
    return n;
}

TreeNode* NodeQueue::front() const { return count_ == 0 ? nullptr : data_[head_]; }
int  NodeQueue::size() const { return count_; }
bool NodeQueue::empty() const { return count_ == 0; }
void NodeQueue::clear() { head_ = 0; count_ = 0; }