#pragma once
#ifndef STACKA_STACKA_HPP_20261123
#define STACKA_STACKA_HPP_20261123

#include <cstddef>
#include <cstdint>

class StackA final {
public:
  using T = std::int64_t;

  StackA() = default;
  StackA(const StackA& src);
  ~StackA();

  StackA& operator=(const StackA& src);

  [[nodiscard]] bool is_empty() const noexcept;

  void push(const T val);
  void pop() noexcept;

  [[nodiscard]] T& top();
  [[nodiscard]] const T& top() const;

  void clear() noexcept;

private:
  std::ptrdiff_t size_ = 0;  //!< ёмкость буфера
  T* data_ = nullptr;        //!< буфер
  std::ptrdiff_t top_ = -1;  //!< индекс вершины стека, -1 == пуст

private:
  void swap(StackA&& src) noexcept;
};

#endif