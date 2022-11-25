#include <memory>
#include <unordered_map>

struct Node{

    std::unique_ptr<Node> children[89];
    bool is_terminal;
    int value;

    Node() {
        is_terminal = false;
        value = 0;
    };

    ~Node() {};

};