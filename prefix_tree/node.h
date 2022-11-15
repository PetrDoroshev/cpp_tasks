#include <memory>
#include <unordered_map>

struct Node{

    std::unordered_map<char, std::unique_ptr<Node>> children;
    bool is_terminal;
    int value;

    Node() {
        is_terminal = false;
        value = 0;
    };

    ~Node() {};

};