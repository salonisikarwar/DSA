#include <unordered_map>
using namespace std;

class LFUCache {
private:
    struct CacheNode {
        int key, value, frequency;
        CacheNode* prev;
        CacheNode* next;

        CacheNode(int k, int v) : key(k), value(v), frequency(1), prev(nullptr), next(nullptr) {}
    };

    struct FrequencyList {
        CacheNode* head;
        CacheNode* tail;
        int size;

        FrequencyList() {
            head = new CacheNode(0, 0); // Dummy head
            tail = new CacheNode(0, 0); // Dummy tail
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void addToFront(CacheNode* node) {
            CacheNode* first = head->next;
            head->next = node;
            node->prev = head;
            node->next = first;
            first->prev = node;
            size++;
        }

        void removeNode(CacheNode* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }

        CacheNode* removeLastNode() {
            if (size == 0) return nullptr;
            CacheNode* lastNode = tail->prev;
            removeNode(lastNode);
            return lastNode;
        }
    };

    int capacity, minFrequency;
    unordered_map<int, CacheNode*> keyToNode;
    unordered_map<int, FrequencyList*> freqToList;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFrequency = 0;
    }

    int get(int key) {
        if (keyToNode.find(key) == keyToNode.end()) {
            return -1;
        }

        CacheNode* node = keyToNode[key];
        updateFrequency(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyToNode.find(key) != keyToNode.end()) {
            CacheNode* node = keyToNode[key];
            node->value = value;
            updateFrequency(node);
            return;
        }

        if (keyToNode.size() >= capacity) {
            FrequencyList* minList = freqToList[minFrequency];
            CacheNode* toRemove = minList->removeLastNode();
            keyToNode.erase(toRemove->key);
            delete toRemove;
        }

        CacheNode* newNode = new CacheNode(key, value);
        keyToNode[key] = newNode;
        minFrequency = 1;

        if (freqToList.find(1) == freqToList.end()) {
            freqToList[1] = new FrequencyList();
        }
        freqToList[1]->addToFront(newNode);
    }

private:
    void updateFrequency(CacheNode* node) {
        int oldFreq = node->frequency;
        FrequencyList* oldList = freqToList[oldFreq];
        oldList->removeNode(node);

        if (oldFreq == minFrequency && oldList->size == 0) {
            minFrequency++;
        }

        node->frequency++;
        if (freqToList.find(node->frequency) == freqToList.end()) {
            freqToList[node->frequency] = new FrequencyList();
        }
        freqToList[node->frequency]->addToFront(node);
    }
};

