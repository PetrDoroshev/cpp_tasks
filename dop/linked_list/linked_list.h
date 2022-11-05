#include <initializer_list>
#include <iostream>
#include "list_node.h"

template <typename T>
class List {

private:

    ListNode<T>* head;
    ListNode<T>* tail;

    std::size_t _size = 0;

    ListNode<T>* get_node(std::size_t index) const;

public:

    List(std::initializer_list<T> l);

    ~List();

    void push_back(const T& value);

    void push_front(const T& vlaue);

    void insert(std::size_t index, const T& value);

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

template<typename T>
ListNode<T>* List<T>::get_node(std::size_t index) const {

    ListNode<T>* p = head;

    for (std::size_t i = 0; i < index; i++)
        p = p->next;
    
    return p;
};

template <typename T>
List<T>::List(std::initializer_list<T> l){

    head = new ListNode<T>();
    tail = head;
    head->next = head;

    for (auto value: l)
        this->push_front(value);
}

template <typename T>
List<T>::~List(){

    ListNode<T>* p = head;
    ListNode<T>* tmp;

    for (std::size_t i = 0; i < _size + 1; i++) {

        tmp = p;
        p = p->next;
        delete tmp;
    }

}

template <typename T>
void List<T>::push_back(const T& value){
    
    ListNode<T>* new_node = new ListNode(value, head->next);
    head->next = new_node;
    _size++;
}

template <typename T>
void List<T>::push_front(const T& value){

    ListNode<T>* new_node = new ListNode<T>(value, head);
    tail->next = new_node;
    tail = new_node;
    _size++;
}
//
template <typename T>
void List<T>::insert(std::size_t index, const T& value){

    ListNode<T>* p = get_node(index + 1);
    ListNode<T>* new_node = new ListNode<T>(value, p->next);

    if (index == _size - 1)
        tail = new_node;

    p->next = new_node;
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

    ListNode<T>* p = get_node(_size - 1);
    ListNode<T>* removable_node = tail;
    tail = p;
    tail->next = head;

    delete removable_node;
    _size--;
}

template<typename T>
void List<T>::remove_at(std::size_t index) {

    ListNode<T>* p = get_node(index);
    ListNode<T>* removable_node = p->next;

    p->next = removable_node->next;

    if (index == _size - 1)
        tail = p;

    _size--;
    delete removable_node;
}


template<typename T>
T& List<T>::operator[] (const std::size_t index) {

    return (get_node(index + 1)->value).value();

};


template<typename T>
T const& List<T>::operator[] (const std::size_t index) const { 
    
    return (this->operator[](index)); 
};

template<typename T>
void List<T>::clear() {

    ListNode<T>* p = head->next;
    tail = tail->next;
    ListNode<T>* tmp;

    for (std::size_t i = 0; i < _size; i++) {
        tmp = p;
        p = p->next;
        delete tmp;

    }
    head->next = head;
    _size = 0;
}
//
template<typename T>
T List<T>::front() const { return (head->next->value).value(); }

template<typename T>
T List<T>::back() const { return (tail->value).value(); }

template<typename T>
std::size_t List<T>::size() const { return _size; }

template<typename T>
bool List<T>::empty() const { return !(_size); }

