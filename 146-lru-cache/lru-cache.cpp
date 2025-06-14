#include <unordered_map>
using namespace std;

class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = nullptr;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> mpp;
    int capacity;
    Node* head;
    Node* tail;

    void removeNode(Node* node) {
        Node* prevnode = node->prev;
        Node* nextnode = node->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }

    void insertAfterHead(Node* node) {
        Node* currafterhead = head->next;
        head->next = node;
        node->prev = head;
        node->next = currafterhead;
        currafterhead->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) {
            return -1;
        }

        Node* node = mpp[key];
        removeNode(node);
        insertAfterHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->value = value;
            removeNode(node);
            insertAfterHead(node);
        } else {
            if (mpp.size() == capacity) {
                Node* lru = tail->prev;
                mpp.erase(lru->key);
                removeNode(lru);
                delete lru;
            }

            Node* newNode = new Node(key, value);
            mpp[key] = newNode;
            insertAfterHead(newNode);
        }
    }
};
