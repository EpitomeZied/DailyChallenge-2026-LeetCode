class LRUCache {
private:
    int capacity;
    std::list<std::pair<int, int>> usage_order_list;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache_map;

public:
    LRUCache(int cache_capacity) {
        capacity = cache_capacity;
    }

    int get(int key) {
        if (cache_map.find(key) == cache_map.end()) {
            return -1;
        }

        auto iterator_to_node = cache_map[key];
        // Move the accessed item to the front to mark it as most recently used.

        usage_order_list.splice(usage_order_list.begin(), usage_order_list, iterator_to_node);

        return iterator_to_node->second;
    }

    void put(int key, int value) {
        if (cache_map.find(key) != cache_map.end()) {
            auto iterator_to_node = cache_map[key];
            iterator_to_node->second = value;
            // Move the updated item to the front to mark it as most recently used.

            usage_order_list.splice(usage_order_list.begin(), usage_order_list, iterator_to_node);
            return;
        }

        // If the cache is full, we must remove the least recently used item to make space.

        if (cache_map.size() == capacity) {
            int key_to_remove = usage_order_list.back().first;
            usage_order_list.pop_back();
            cache_map.erase(key_to_remove);
        }

        // Add the new item to the front, as it is now the most recently used.

        usage_order_list.push_front({key, value});
        cache_map[key] = usage_order_list.begin();
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
