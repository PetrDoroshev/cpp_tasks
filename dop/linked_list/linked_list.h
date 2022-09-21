template <typename T>
class List{

private:

    ListNode* head;
    ListNode* tail;


public:

    List(std::initializer_list<T>);
    ~List();
    void push_back();
    void push_front();
    
};