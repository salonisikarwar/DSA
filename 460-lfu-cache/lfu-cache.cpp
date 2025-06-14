class LFUCache {
    // For readability, using custom classes and not pairs
    struct freqLRU {
        int freq;
        list<int> lru_list;
    };
    // Okay LRUCache used a linked list to bring accessed elements to back of list and remove from front.
    // Keep a list of unique frequencies -- Like list<pair<int -- Uniq freq, list<int>* -- Recency list>
    // Rest concepts are similar? Basically now, we remove accessed element from the (freq) list, and insert into
    // back of (freq+1) list. And when removing, we remove front.front basically
    list<freqLRU> lfu_list;

    struct val_cache_entry_t {
        int value;
        list<freqLRU>::iterator lfu_list_it;
        list<int>::iterator lru_list_it;
    };

    unordered_map<int, val_cache_entry_t> lfu_cache;
    int capacity;

    void update_list_positions(list<freqLRU>::iterator& lfu_it, list<int>::iterator& lru_it, int key) {
        int freq = lfu_it->freq;
        auto& lru_list = lfu_it->lru_list;
        // First remove lru list entry from lru list of current freq (lfu entry)
        lru_list.erase(lru_it);
        // Check if next lfu entry is of next higher freq. If not, entry does not exist, create one.
        auto next_freq_it = next(lfu_it);
        if (next_freq_it == lfu_list.end() || next_freq_it->freq != freq + 1)
            lfu_list.insert(next_freq_it, {freq+1, {}});
        // Insert lru list entry (just the key) into lru list of next higher freq (now exists guaranteed)
        next_freq_it = next(lfu_it);
        next_freq_it->lru_list.push_back(key);
        // Additional clean-up : Remove lfu entry if the underlying lru list is emptied
        if (lfu_it->lru_list.empty())
            lfu_list.erase(lfu_it);
        // Update lfu cache entry with new lru iterator and new lfu iterator
        lru_it = prev(next_freq_it->lru_list.end());       // *prev(end()) is back()
        lfu_it = next_freq_it;
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!lfu_cache.contains(key))
            return -1;
        auto& [value, lfu_it, lru_it] = lfu_cache[key];
        // Update positioning in the LFU-LRU lists ; Return the cache value
        update_list_positions(lfu_it, lru_it, key);
        return value;
    }
    
    void put(int key, int value) {
        // If capacity filled, and key does not exist in map (meaning insertion needed), must remove.
        if (lfu_cache.size() == capacity && !lfu_cache.contains(key)) {
            int rem_key = lfu_list.front().lru_list.front();
            // Remove from inner lru list first
            lfu_list.front().lru_list.pop_front();
            // If inner lru list empty, remove lfu entry as well
            if (lfu_list.front().lru_list.empty())
                lfu_list.pop_front();
            // Remove entry from cache/hashmap as well
            lfu_cache.erase(rem_key);
        }
        // Insert as 0-freq entry (TEMP) in LFU list if element does not exist
        if (!lfu_cache.contains(key)) {
            lfu_list.push_front({0, {key}});
            // Currently an Invalid CACHE entry pointing to 0-freq TEMP list entry
            lfu_cache[key] = {-1, lfu_list.begin(), lfu_list.front().lru_list.begin()};
        }
        auto& [old_value, lfu_it, lru_it] = lfu_cache[key];
        // Update positioning in the LFU-LRU lists ; Update the cache value
        update_list_positions(lfu_it, lru_it, key);
        old_value = value;
    }
};