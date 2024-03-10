#include "main.h"

class Trie {
public:
    
    struct Node {
        char c;
        bool isEnd = false;
        vector<Node*> leafs;

        Node(char _c) : c(_c) { }
    };

    Node* root;

    Trie() {
        root = new Node(0);
    }

    void insert(string word) {
        Node* current = root;
        for (int i = 0; i < word.size(); i++) {
            Node* nextNode = getNextNode(current->leafs, word[i]);

            if (nextNode == nullptr) {
                nextNode = new Node(word[i]);
                current->leafs.push_back(nextNode);
            }

            current = nextNode;
        }
        current->isEnd = true;
    }
 
    Node* getNextNode(vector<Node*>& leafs, char& c) {
        for (Node* leaf : leafs) {
            if (leaf->c == c) return leaf;
        }
        return nullptr;
    }

    bool search(string word) {
        Node* current = root;
        for (int i = 0; i < word.size(); i++) {
            Node* nextNode = getNextNode(current->leafs, word[i]);

            if (nextNode == nullptr) return false;
            current = nextNode;
        }
        return current->isEnd;
    }

    bool startsWith(string prefix) {
        Node* current = root;
        for (int i = 0; i < prefix.size(); i++) {
            Node* nextNode = getNextNode(current->leafs, prefix[i]);

            if (nextNode == nullptr) return false;
            current = nextNode;
        }
        return true;
    }
};

void main() {
    Trie* obj = new Trie();
    obj->insert("word");
    obj->insert("was");
    obj->insert("wor");
    obj->root;

    cout << obj->search("wa") << endl;
    cout << obj->search("wor") << endl;
    cout << obj->search("worrrr") << endl;

    cout << obj->startsWith("wa") << endl;
    cout << obj->startsWith("wor") << endl;
    cout << obj->startsWith("t") << endl;

    return;

}

/**
 * Your Trie object will be instantiated and called as such:
 * 
 * 
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */



