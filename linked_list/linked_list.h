#include <initializer_list>
#include <iostream>
#include <iterator>
#include <cstddef>

#include "list_node.h"



template <typename T>
class ListIterator: public std::iterator< std::forward_iterator_tag, T>{

public:

    ListNode<T>* ptr;
    ListIterator (ListNode<T>* _ptr): ptr(_ptr) {}

    T& operator*() const { return (ptr->value).value(); }

    ListIterator& operator++() {

        ptr = ptr->next;
        return *this; 
        
    }
    ListIterator operator++(int) { ListIterator tmp = *this; ++(*this); return tmp; }

    bool operator== (const ListIterator& other) { return ptr == other.ptr; };
    bool operator!= (const ListIterator& other) { return ptr != other.ptr; };    
    
};



template <typename T>
class List {

private:

    ListNode<T>* head;
    ListNode<T>* tail;

    std::size_t _size = 0;

    ListNode<T>* get_node(std::size_t index) const;


public:

    List(std::initializer_list<T> l);
    List();
    ~List();


    ListIterator<T> begin() { return ListIterator<T> (head->next); }
    ListIterator<T> end() {return ListIterator<T> (head); }

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
List<T>::List(){

    head = new ListNode<T>();
    tail = head;
    head->next = head;

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
void List<T>::push_front(const T& value){
    
    ListNode<T>* new_node = new ListNode(value, head->next);
    head->next = new_node;
    _size++;
}

template <typename T>
void List<T>::push_back(const T& value){

    ListNode<T>* new_node = new ListNode<T>(value, head);
    tail->next = new_node;
    tail = new_node;
    _size++;
}

template <typename T>
void List<T>::insert(std::size_t index, const T& value){

    if (index >= _size || index < 0)
        throw std::out_of_range("Out of range");

    ListNode<T>* p = get_node(index);
    ListNode<T>* new_node = new ListNode<T>(value, p->next);
    
    p->next = new_node;
    _size++; 
}

template<typename T>
void List<T>::pop_back(){
    
    if (empty())
        throw std::underflow_error("Nothing to pop");
        
    ListNode<T>* tmp = head->next;
    head->next = tmp->next;
    delete tmp;

    _size--;
}

template<typename T>
void List<T>::pop_front(){

    if (empty())
        throw std::underflow_error("Nothing to pop");

    ListNode<T>* p = get_node(_size - 1);
    ListNode<T>* removable_node = tail;
    tail = p;
    tail->next = head;

    delete removable_node;
    _size--;
}

template<typename T>
void List<T>::remove_at(std::size_t index) {

    if (index >= _size || index < 0)
        throw std::out_of_range("Out of range");

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

    if (index >= _size || index < 0)
        throw std::out_of_range("Out of range");

    return (get_node(index + 1)->value).value();

};


template<typename T>
T const& List<T>::operator[] (const std::size_t index) const { 
    
    if (index >= _size || index < 0)
        throw std::out_of_range("Out of range");

    return (get_node(index + 1)->value).value();
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

template<typename T>
T List<T>::front() const { 

    if (empty())
        throw std::underflow_error("List is empty");

    return (head->next->value).value(); 
    
}

template<typename T>
T List<T>::back() const { 
    
    if (empty())
        throw std::underflow_error("List is empty");

    return (tail->value).value(); 
}

template<typename T>
std::size_t List<T>::size() const { return _size; }

template<typename T>
bool List<T>::empty() const { return !(_size); }

