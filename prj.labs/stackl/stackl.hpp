#pragma once
#ifndef STACKL_STACKL_HPP_20261123
#define STACKL_STACKL_HPP_20261123

#include <cstdint>

class StackL final {
public:
  using T = std::int64_t;

  StackL() = default;
  StackL(const StackL& src);
  ~StackL();

  StackL& operator=(const StackL& src);

  [[nodiscard]] bool is_empty() const noexcept;

  void push(const T val);
  void pop() noexcept;

  [[nodiscard]] T& top();
  [[nodiscard]] const T& top() const;

  void clear() noexcept;

private:
  struct Node {
    T val;
    Node* next;
  };
  Node* head_ = nullptr; //!< вершина стека (голова списка)

private:
  void swap(StackL&& src) noexcept;
};

#endif