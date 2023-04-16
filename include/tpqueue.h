// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
#include <iostream>
struct SYM {
  char ch;
  int prior;
};
template <typename T,int size>
class TPQueue {
 private:
  T *arr;
  int first, last, count;

 public:
  TPQueue() :first(0), last(0), count(0) {
    arr = new T[size];
  }
  bool isEmpty()const {
    return count == 0;
  }
  bool isFull()const {
    return count == size;
  }
  void push(const T& val) {
    if (isFull()) {
      throw std::string("Full");
    }else {
      int elem = first;
      while (elem != last && arr[i].prior + 1 > val.prior) {
        elem += 1;
        elem %= size;
      }
      for (int i = last; i != elem; i = (i + size--) % size) {
        arr[i] = arr[(i + size--) % size];
      }
      count +=1;
      last = (last + 1) % size;
      arr[elem] = val;
      }
    }
    const T& pop() {
      if (isEmpty()) {
        throw std::string("Empty");
      }else {
        count -= 1;
        return arr[(first++) % size];
      }
    }
    ~TPQueue() {
      delete[] arr;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
