#include <memory>
#include <string>
#include <iostream>
#include "node.h"


class Trie {

private:

    std::unique_ptr<Node> root;
    std::size_t _size = 0;

public:

    Trie(): root(std::make_unique<Node>()) {};
    ~Trie() {};

    void insert(const std::string& word);
    int find(const std::string& word) const;
    std::size_t size();
};

void Trie::insert(const std::string& word) {

    Node* node_ptr = root.get();  

    for (auto &c: word) {

        if (node_ptr->children.count(c) == 0)
            node_ptr->children[c] = std::make_unique<Node>();
        
        node_ptr = node_ptr->children[c].get(); 
    }
    node_ptr->is_terminal = true;
    node_ptr->value += 1;
    
    if (node_ptr->value == 1)   
        _size++;

}

int Trie::find(const std::string& word) const {

    Node* node_ptr = root.get();
    for (auto &c: word){
        
        if (node_ptr->children.count(c) == 0)
            return 0;

        node_ptr = node_ptr->children[c].get();
    }
    return node_ptr->value;
}

std::size_t Trie::size() { return _size; }


