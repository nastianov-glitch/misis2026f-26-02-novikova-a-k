#include <staks/stacks.hpp> 

#include <stdexcept>
#include <cstring>
#include <utility>

// Конструктор копирования
Stacks::Stacks(const Stacks& src)
  : size_(src.size_)
  , capacity_(src.capacity_) {
  if (!src.is_empty()) {
    data_ = new int64_t[capacity_];
    std::memcpy(data_, src.data_, size_ * sizeof(int64_t));
  }
}

// Деструктор
Stacks::~Stacks() {
  delete[] data_;
}

// Оператор присваивания (Copy-and-swap)
Stacks& Stacks::operator=(const Stacks& src) {
  if (this != &src) {
    Stacks temp(src);
    std::swap(data_, temp.data_);
    std::swap(size_, temp.size_);
    std::swap(capacity_, temp.capacity_);
  }
  return *this;
}

// Проверка на пустоту
bool Stacks::is_empty() const noexcept {
  return size_ == 0;
}

// Удаление верхнего элемента
void Stacks::pop() noexcept {
  if (!is_empty()) {
    --size_;
  }
}

// Добавление элемента
void Stacks::push(const int64_t val) {
  if (size_ == capacity_) {
    std::ptrdiff_t new_cap = (capacity_ == 0) ? 1 : capacity_ * 2;
    int64_t* new_data = new int64_t[new_cap];
    
    if (size_ > 0) {
      std::memcpy(new_data, data_, size_ * sizeof(int64_t));
    }
    
    delete[] data_;
    data_ = new_data;
    capacity_ = new_cap;
  }
  data_[size_++] = val;
}

// Неконстантный top (ссылка)
int64_t& Stacks::top() {
  if (is_empty()) {
    throw std::logic_error("Stacks - try get top from empty stack.");
  }
  return data_[size_ - 1];
}

// Константный top (копия)
int64_t Stacks::top() const {
  if (is_empty()) {
    throw std::logic_error("Stacks - try get top from empty stack.");
  }
  return data_[size_ - 1];
}

// Очистка
void Stacks::clear() noexcept {
  delete[] data_;
  data_ = nullptr;
  size_ = 0;
  capacity_ = 0;
}