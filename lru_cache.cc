class LRUCache{
public:
    LRUCache(int capacity) {
        cache_map.clear();
        cache_list.clear();
        max_size = capacity;
    }
    
    int get(int key) {
        unordered_map<int, list<pair<int, int> >::iterator >::iterator p = cache_map.find(key);
        if (p != cache_map.end()) {
            cache_list.splice(cache_list.begin(), cache_list, p->second);
            p->second = cache_list.begin();
            return (p->second)->second;
        }
        return -1;
    }
    
    void set(int key, int value) {
        unordered_map<int, list<pair<int, int> >::iterator >::iterator p = cache_map.find(key);
        if (p != cache_map.end()) {
            ((p->second))->second = value;
            cache_list.splice(cache_list.begin(), cache_list, p->second);
            p->second = cache_list.begin();
        } else {
            if (cache_map.size() >= max_size) {
                cache_map.erase(cache_list.rbegin()->first);
                cache_list.pop_back();
            }
            cache_list.push_front(pair<int, int>(key, value));
            cache_map[key] = cache_list.begin();
        }
    }
private:
    unordered_map<int, list<pair<int, int> >::iterator > cache_map; 
    list<pair<int, int> > cache_list; 
    int max_size;
};