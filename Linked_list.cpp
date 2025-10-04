#include "linked_list.h"
#include <iostream>
using namespace std;
using namespace linked_list;
template <typename T>
void List<T>::push(T value) {
    Node<T>* new_node = new Node<T>(value);
    if (head == nullptr) {
      head = new_node;
        size = size +1;
      return;
    }
    Node<T>* current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    new_node->prev = current;
    current->next = new_node;
    size = size +1;
}
template <typename T>
T List<T>::pop() {
     if (head == nullptr) {
        cout<<"pop() on empty list"<<endl;
         return T{};
    }
     if (head->next == nullptr) {
        T value = head->value;
        delete head;
        head = nullptr;
        size = size - 1;
        return value;
    }
    Node<T>* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    T value = last->value;
    Node<T>* prev = last->prev;
    prev->next = nullptr;
    delete last;
    size = size - 1;
      return value;
}
template <typename T>
T List<T>::shift(){
if (head == nullptr) {
cout<<"out of range"<<endl;
    return T{};
    }
   Node<T>* first = head;
    T value = first->value;
    head = first->next;
 if (head != nullptr) {
        head->prev = nullptr;
    }
    delete first;
    size = size - 1;
    return value;
        
}
template <typename T>
void List<T>:: unshift(T value) {
    Node<T>* new_node = new Node<T>(value);
    new_node->next = head;
    if (head != nullptr) {
        head->prev = new_node;
    }
    head = new_node;
    size++;
}
template <typename T>
int List<T>::count() {
    return size;
}
template <typename T>
void List<T>::erase(T value) {
    Node<T>* cur = head;
    while (cur != nullptr && !(cur->value == value)) {
        cur = cur->next;
    }
    if (cur == nullptr) {
        cout<<"nothing to delete"<<endl;
        return;
    }
    Node<T>* prev = cur->prev;
    Node<T>* next = cur->next;
    if (prev) prev->next = next;
    else head = next;
    if (next) next->prev = prev;
    delete cur;
    size = size - 1;
}
namespace linked_list {
template void List<int>::push(int value);
template int  List<int>::pop();
template int  List<int>::shift();
template void List<int>::unshift(int value);
template int  List<int>::count();
template void List<int>::erase(int value);
}
