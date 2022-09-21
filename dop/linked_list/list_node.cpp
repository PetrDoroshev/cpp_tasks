#include <optional>

template <typename T>
class ListNode {

public:

    std::optional<T> value;
    ListNode* next;
    
    ListNode(T value, ListNode* next);
    ListNode(ListNode* next);
    ListNode();
    ~ListNode();

};

template<typename T>
ListNode<T>::ListNode(T value, ListNode* next){

    this->value = value;
    this->next = next;
}

template<typename T>
ListNode<T>::ListNode(ListNode* next){

    this->next = next;
}

template<typename T>
ListNode<T>::ListNode(){

    this->next = nullptr;
}

template<typename T>
ListNode<T>::~ListNode(){
    
}


