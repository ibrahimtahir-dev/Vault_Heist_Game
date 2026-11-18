#include "IntArray.h"

IntArray::IntArray() : data_(nullptr), size_(0), capacity_(0) {}

IntArray::IntArray(int initialCapacity) : data_(nullptr), size_(0), capacity_(0) {
    if (initialCapacity > 0) reserve(initialCapacity);
}

IntArray::IntArray(const IntArray& other) : data_(nullptr), size_(0), capacity_(0) {
    reserve(other.size_);
    for (int i = 0; i < other.size_; ++i) data_[i] = other.data_[i];
    size_ = other.size_;
}

IntArray& IntArray::operator=(const IntArray& other) {
    if (this == &other) return *this;
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
    reserve(other.size_);
    for (int i = 0; i < other.size_; ++i) data_[i] = other.data_[i];
    size_ = other.size_;
    return *this;
}

IntArray::~IntArray() { delete[] data_; }

void IntArray::reserve(int newCapacity) {
    if (newCapacity <= capacity_) return;
    int* fresh = new int[newCapacity];
    for (int i = 0; i < size_; ++i) fresh[i] = data_[i];
    delete[] data_;
    data_ = fresh;
    capacity_ = newCapacity;
}

void IntArray::push(int value) {
    if (size_ == capacity_) reserve(capacity_ == 0 ? 8 : capacity_ * 2);
    data_[size_++] = value;
}

int IntArray::pop() {
    if (size_ == 0) return 0;
    return data_[--size_];
}

int IntArray::back() const { return size_ == 0 ? 0 : data_[size_ - 1]; }
int IntArray::size() const { return size_; }
bool IntArray::empty() const { return size_ == 0; }
void IntArray::clear() { size_ = 0; }

void IntArray::swapAt(int i, int j) {
    int tmp = data_[i];
    data_[i] = data_[j];
    data_[j] = tmp;
}

int& IntArray::operator[](int index) { return data_[index]; }
const int& IntArray::operator[](int index) const { return data_[index]; }