#include <initializer_list>
#include <iostream>
#include "list_node.h"


template <typename T>
class List {

private:

    ListNode<T>* head;
    std::size_t _size = 0;

public:

    ListNode<T>* tail;

    List(std::initializer_list<T> l);

    ~List();

    void push_back(T value);

    void push_front(T vlaue);

    void insert(std::size_t index, T value);

    void pop_back();

    void pop_front();

    void remove_at(std::size_t index);

    T& operator[](const std::size_t index);

    T const& operator[](const std::size_t index) const;

    std::size_t size() const;

    bool empty() const;

    void clear();

    T front() const;

    T back() const;

};

template <typename T>
List<T>::List(std::initializer_list<T> l){

    head = new ListNode<T>();
    tail = head;
    head->next = head;

    for (auto value: l){
        this->push_front(value);
    }
}

template <typename T>
List<T>::~List(){

    ListNode<T>* current_node = head;
    ListNode<T>* tmp;

    for (std::size_t i = 0; i < _size + 1; i++) {

        tmp = current_node;
        current_node = current_node->next;
        delete tmp;
    }

}

template <typename T>
void List<T>::push_back(T value){
    
    ListNode<T>* new_node = new ListNode(value, head->next);
    head->next = new_node;
    _size++;
}

template <typename T>
void List<T>::push_front(T value){

    ListNode<T>* new_node = new ListNode<T>(value, head);
    tail->next = new_node;
    tail = new_node;
    _size++;
}

template <typename T>
void List<T>::insert(std::size_t index, T value){

    ListNode<T>* current_node = head;

    for (std::size_t i = 0; i < index; i++){

        current_node = current_node->next;

    }
    ListNode<T>* new_node = new ListNode<T>(value, current_node->next);
    current_node->next = new_node;
    _size++;
}

template<typename T>
void List<T>::pop_back(){
    
    //empty delete ?

    ListNode<T>* tmp = head->next;
    head->next = tmp->next;
    delete tmp;

    _size--;

}
template<typename T>
void List<T>::pop_front(){
    
}

template<typename T>
void List<T>::remove_at(std::size_t index){

}


template<typename T>
std::size_t List<T>::size() const{
    
    return _size;
}

