#pragma once
#ifndef STAKS_STACKS_HPP_20251128
#define STAKS_STACKS_HPP_20251128

#include <cstdint>
#include <cstddef>

class Stacks {
public:
  Stacks() = default;

  Stacks(const Stacks& src);
  ~Stacks();
  
  Stacks& operator=(const Stacks& src);

  [[nodiscard]] bool is_empty() const noexcept;
  void pop() noexcept;
  void push(const int64_t val);
  
  [[nodiscard]] int64_t& top();
  [[nodiscard]] int64_t top() const;

  void clear() noexcept;

private:
  int64_t* data_ = nullptr;
  std::ptrdiff_t size_ = 0;
  std::ptrdiff_t capacity_ = 0;
};

#endif