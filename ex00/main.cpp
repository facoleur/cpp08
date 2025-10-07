// main.cpp

#include "easyfind.hpp"

void test_vectors() {
  std::cout << "--- test vectors ---" << std::endl;
  std::cout << std::boolalpha;

  int normal[] = {1, 2, 3, 6, 5};
  int find = 3;
  std::vector<int> v_normal(normal, normal + 5);
  std::vector<int>::iterator i_normal = easyfind(v_normal, find);
  std::cout << (*i_normal == find) << std::endl;

  int start[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> v_start(start, start + 10);
  find = v_start.front();
  std::vector<int>::iterator i_start = easyfind(v_start, find);
  std::cout << (*i_start == find) << std::endl;

  int end[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> v_end(end, end + 10);
  find = v_end.back();
  std::vector<int>::iterator i_end = easyfind(v_end, find);
  std::cout << (*i_end == find) << std::endl;

  int *empty = 0;
  std::vector<int> v_empty(empty, empty);
  try {
    easyfind(v_empty, 3);
    std::cout << false << std::endl;
  } catch (const std::exception &e) {
    std::cout << true << std::endl;
  }

  int miss[] = {1, 1, 1, 1, 2, 2, 2};
  std::vector<int> v_miss(miss, miss + 7);
  try {
    easyfind(v_miss, 3);
    std::cout << false << std::endl;
  } catch (const std::exception &e) {
    std::cout << true << std::endl;
  }
}

void test_lists() {
  std::cout << "--- test lists ---" << std::endl;
  std::cout << std::boolalpha;

  int normal[] = {1, 2, 3, 6, 5};
  int find = 3;
  std::list<int> l_normal(normal, normal + 5);
  std::list<int>::iterator i_normal = easyfind(l_normal, find);
  std::cout << (*i_normal == find) << std::endl;

  int start[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::list<int> l_start(start, start + 10);
  find = l_start.front();
  std::list<int>::iterator i_start = easyfind(l_start, find);
  std::cout << (*i_start == find) << std::endl;

  int end[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::list<int> l_end(end, end + 10);
  find = l_end.back();
  std::list<int>::iterator i_end = easyfind(l_end, find);
  std::cout << (*i_end == find) << std::endl;

  std::list<int> l_empty;
  try {
    easyfind(l_empty, 3);
    std::cout << false << std::endl;
  } catch (const std::exception &) {
    std::cout << true << std::endl;
  }

  int miss[] = {1, 1, 1, 1, 2, 2, 2};
  std::list<int> l_miss(miss, miss + 7);
  try {
    easyfind(l_miss, 3);
    std::cout << false << std::endl;
  } catch (const std::exception &) {
    std::cout << true << std::endl;
  }
}

void test_deques() {
  std::cout << "--- test deques ---" << std::endl;
  std::cout << std::boolalpha;

  int normal[] = {1, 2, 3, 6, 5};
  int find = 3;
  std::deque<int> d_normal(normal, normal + 5);
  std::deque<int>::iterator i_normal = easyfind(d_normal, find);
  std::cout << (*i_normal == find) << std::endl;

  int start[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::deque<int> d_start(start, start + 10);
  find = d_start.front();
  std::deque<int>::iterator i_start = easyfind(d_start, find);
  std::cout << (*i_start == find) << std::endl;

  int end[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::deque<int> d_end(end, end + 10);
  find = d_end.back();
  std::deque<int>::iterator i_end = easyfind(d_end, find);
  std::cout << (*i_end == find) << std::endl;

  std::deque<int> d_empty;
  try {
    easyfind(d_empty, 3);
    std::cout << false << std::endl;
  } catch (const std::exception &) {
    std::cout << true << std::endl;
  }

  int miss[] = {1, 1, 1, 1, 2, 2, 2};
  std::deque<int> d_miss(miss, miss + 7);
  try {
    easyfind(d_miss, 3);
    std::cout << false << std::endl;
  } catch (const std::exception &) {
    std::cout << true << std::endl;
  }
}

int main(int, char const **) {

  test_vectors();
  test_lists();
  test_deques();

  return 0;
}
