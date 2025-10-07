// Span.cpp

#include "Span.hpp"

Span::Span(unsigned int N)
// : capacity(N)
{
  this->numbers.reserve(N);
}

Span::Span(const Span &other)
// : capacity(other.capacity)
{
  this->numbers = other.numbers;
}

Span &Span::operator=(const Span &other) {
  if (this == &other)
    return *this;

  numbers = other.numbers;
  // capacity = other.capacity;

  return *this;
}

void Span::addNumber(int n) {
  if (numbers.size() >= numbers.capacity())
    throw std::overflow_error("Cannot add more numbers, capacity reached.");
  numbers.push_back(n);
  return;
}

int Span::shortestSpan() {
  if (numbers.size() < 2)
    throw std::logic_error("Vector must contain at least 2 numbers");

  std::sort(numbers.begin(), numbers.end());

  size_t shortest = INT_MAX;
  size_t tmp;
  for (size_t i = 1; i < numbers.size(); i++) {
    tmp = numbers[i] - numbers[i - 1];
    if (tmp < shortest)
      shortest = tmp;
  }

  return shortest;
}

int Span::longestSpan() {
  if (numbers.size() < 2)
    throw std::logic_error("Vector must contain at least 2 numbers");

  std::sort(numbers.begin(), numbers.end());

  return numbers.back() - numbers.front();
}

void Span::addNumbers(int *nbr, size_t size) {
  size_t freeSpace = numbers.capacity() - numbers.size();

  if (size > freeSpace) {
    throw std::logic_error("size would exceed capacity.");
  }

  for (size_t i = 0; i < size; i++)
    numbers.push_back(nbr[i]);
}

void Span::printNumbers() {
  for (std::vector<int>::iterator it = numbers.begin(); it < numbers.end();
       it++)
    std::cout << *it << " ";

  std::cout << std::endl;
}

Span::~Span() {}
