#include "stackl.hpp"
#include <stdexcept>
#include <utility>

StackL::StackL(const StackL& src) {
  if (nullptr != src.head_) {
    head_ = new Node{ src.head_->val, nullptr };
    Node* dst = head_;
    for (Node* cur = src.head_->next; nullptr != cur; cur = cur->next) {
      dst->next = new Node{ cur->val, nullptr };
      dst = dst->next;
    }
  }
}

StackL::~StackL() {
  clear();
}

StackL& StackL::operator=(const StackL& src) {
  if (this != &src) {
    StackL temp(src);
    swap(std::move(temp));
  }
  return *this;
}

void StackL::swap(StackL&& src) noexcept {
  std::swap(head_, src.head_);
}

bool StackL::is_empty() const noexcept {
  return nullptr == head_;
}

void StackL::push(const T val) {
  head_ = new Node{ val, head_ };
}

void StackL::pop() noexcept {
  if (!is_empty()) {
    Node* next = head_->next;
    delete head_;
    head_ = next;
  }
}

StackL::T& StackL::top() {
  if (is_empty()) {
    throw std::logic_error("StackL - try get top from empty stack.");
  }
  return head_->val;
}

const StackL::T& StackL::top() const {
  if (is_empty()) {
    throw std::logic_error("StackL - try get top from empty stack.");
  }
  return head_->val;
}

void StackL::clear() noexcept {
  while (!is_empty()) {
    pop();
  }
}