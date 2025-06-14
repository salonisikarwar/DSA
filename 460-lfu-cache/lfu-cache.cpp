#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
private:
    int cap;                  // Cache capacity
    int minFreq;              // Minimum frequency of any key
    unordered_map<int, int> valueMap;                // key -> value
    unordered_map<int, int> freqMap;                 // key -> freq
    unordered_map<int, list<int>> freqListMap;       // freq -> list of keys
    unordered_map<int, list<int>::iterator> keyIter; // key -> iterator in list

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (valueMap.find(key) == valueMap.end()) return -1;

        int freq = freqMap[key];
        freqListMap[freq].erase(keyIter[key]);     // Remove from current freq list

        freqMap[key] = freq + 1;
        freqListMap[freq + 1].push_front(key);     // Insert in new freq list
        keyIter[key] = freqListMap[freq + 1].begin();

        if (freqListMap[freq].empty()) {
            freqListMap.erase(freq);
            if (minFreq == freq) minFreq++;        // Update minFreq
        }

        return valueMap[key];
    }

    void put(int key, int value) {
        if (cap == 0) return;

        // Update existing key
        if (valueMap.find(key) != valueMap.end()) {
            valueMap[key] = value;
            get(key);  // Increase frequency
            return;
        }

        // Eviction if needed
        if (valueMap.size() >= cap) {
            int keyToRemove = freqListMap[minFreq].back();  // Least recently used in minFreq
            freqListMap[minFreq].pop_back();

            valueMap.erase(keyToRemove);
            freqMap.erase(keyToRemove);
            keyIter.erase(keyToRemove);
        }

        // Insert new key
        valueMap[key] = value;
        freqMap[key] = 1;
        freqListMap[1].push_front(key);
        keyIter[key] = freqListMap[1].begin();
        minFreq = 1;
    }
};
