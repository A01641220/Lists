#ifndef LINKED_LIST_H
#define LINKED_LIST_H
namespace linked_list {
template <typename T>
class Node {
public:
  T value;
  Node<T>* next;
  Node<T>* prev;
  Node(T value): value(value), next(nullptr), prev(nullptr) {};
};
template <typename T>
class List {
private:
  Node<T> *head;
  int size;
public:
  List() : head(nullptr), size(0) { };
  void push(T value);
  T pop();
  T shift();
  void unshift(T value);
  int count();
  void erase(T value);
};
}
#endif
