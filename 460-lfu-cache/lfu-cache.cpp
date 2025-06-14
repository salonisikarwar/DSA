class LFUCache {
    int cap, minFreq;
    unordered_map<int, int> keyVal;                           // key -> value
    unordered_map<int, int> keyFreq;                          // key -> frequency
    unordered_map<int, list<int>> freqList;                   // freq -> list of keys
    unordered_map<int, list<int>::iterator> keyIter;          // key -> position in list

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyVal.find(key) == keyVal.end()) return -1;

        updateFreq(key);  // increase frequency
        return keyVal[key];
    }

    void put(int key, int value) {
        if (cap == 0) return;

        // If key already exists, update value and frequency
        if (keyVal.find(key) != keyVal.end()) {
            keyVal[key] = value;
            updateFreq(key);
            return;
        }

        // Evict LFU if needed
        if (keyVal.size() == cap) {
            int evictKey = freqList[minFreq].back(); // LRU in minFreq
            freqList[minFreq].pop_back();
            keyVal.erase(evictKey);
            keyFreq.erase(evictKey);
            keyIter.erase(evictKey);
        }

        // Insert new key
        keyVal[key] = value;
        keyFreq[key] = 1;
        freqList[1].push_front(key);
        keyIter[key] = freqList[1].begin();
        minFreq = 1;  // Reset minFreq for new key
    }

private:
    void updateFreq(int key) {
        int freq = keyFreq[key];
        freqList[freq].erase(keyIter[key]);

        // Clean up if list becomes empty
        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq) minFreq++;
        }

        // Move to freq + 1
        keyFreq[key]++;
        freqList[freq + 1].push_front(key);
        keyIter[key] = freqList[freq + 1].begin();
    }
};
