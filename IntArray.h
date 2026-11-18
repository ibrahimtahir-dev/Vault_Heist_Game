#pragma once

class IntArray {
public:
    IntArray();
    explicit IntArray(int initialCapacity);
    IntArray(const IntArray& other);              
    IntArray& operator=(const IntArray& other); 
    ~IntArray();

    void push(int value);          
    int  pop();                   
    int  back() const;            
    int  size() const;
    bool empty() const;
    void clear();                  
    void reserve(int newCapacity);
    void swapAt(int i, int j);

    int& operator[](int index);
    const int& operator[](int index) const;

private:
    int* data_;
    int  size_;
    int  capacity_;
};
