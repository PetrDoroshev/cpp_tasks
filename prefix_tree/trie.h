#include <memory>
#include <string>
#include <iostream>
#include "node.h"


class Trie {

private:

    std::shared_ptr<Node> root;
    std::size_t _size = 0;

public:

    Trie(): root(std::shared_ptr<Node>(new Node)) {};
    ~Trie() {};

    void insert(const std::string& word);
    int find(const std::string& word) const;
    std::size_t size();
};

void Trie::insert(const std::string& word) {

    std::shared_ptr<Node> node_ptr = root;  

    for (auto &c: word) {

        if (!node_ptr->children.count(c))
            node_ptr->children[c] = std::shared_ptr<Node>(new Node);
        
        node_ptr = node_ptr->children[c]; 
    }
    node_ptr->is_terminal = true;
    node_ptr->value += 1;
    
    if (node_ptr->value == 1)
        _size++;

}

int Trie::find(const std::string& word) const {

    std::shared_ptr<Node> node_ptr = root;
    for (auto &c: word){
        
        if (!node_ptr->children.count(c))
            return 0;

        node_ptr = node_ptr->children[c];
    }

    return node_ptr->value;
}

std::size_t Trie::size() { return _size; }


