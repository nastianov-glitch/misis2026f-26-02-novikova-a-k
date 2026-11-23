#include "stacka.hpp"
#include <algorithm>
#include <stdexcept>
#include <utility>

StackA::StackA(const StackA& src) {
  if (!src.is_empty()) {
    top_ = src.top_;
    size_ = (src.top_ + 1 + 4) / 4 * 4;
    data_ = new T[size_];
    std::copy(src.data_, src.data_ + src.top_ + 1, data_);
  }
}

StackA::~StackA() {
  delete[] data_;
}

StackA& StackA::operator=(const StackA& src) {
  if (this != &src) {
    StackA temp(src);
    swap(std::move(temp));
  }
  return *this;
}

void StackA::swap(StackA&& src) noexcept {
  std::swap(size_, src.size_);
  std::swap(data_, src.data_);
  std::swap(top_, src.top_);
}

bool StackA::is_empty() const noexcept {
  return top_ < 0;
}

void StackA::push(const T val) {
  if (nullptr == data_) {
    size_ = 2;
    data_ = new T[size_];
  }
  if (top_ + 1 == size_) {
    T* buf = new T[size_ * 2];
    std::swap(buf, data_);
    std::copy(buf, buf + size_, data_);
    delete[] buf;
    size_ *= 2;
  }
  data_[++top_] = val;
}

void StackA::pop() noexcept {
  if (!is_empty()) {
    --top_;
  }
}

StackA::T& StackA::top() {
  if (is_empty()) {
    throw std::logic_error("StackA - try get top from empty stack.");
  }
  return data_[top_];
}

const StackA::T& StackA::top() const {
  if (is_empty()) {
    throw std::logic_error("StackA - try get top from empty stack.");
  }
  return data_[top_];
}

void StackA::clear() noexcept {
  top_ = -1;
}