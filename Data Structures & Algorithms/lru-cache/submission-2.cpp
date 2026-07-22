class LRUCache {
public:
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    list<pair<int,int>> dll;
    int capacity = 0;
    int currCapacity = 0;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            int value = (*mp[key]).second;
            dll.erase(mp[key]);
            dll.push_front({key,value});
            auto it = dll.begin();
            mp[key] = it;
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            dll.erase(mp[key]);  
        }
        else {
            if(currCapacity < capacity) {
                currCapacity++;
            }
            else{
                int keyToRemove = dll.back().first;
                mp.erase(keyToRemove);
                dll.pop_back();
            }
        }
        dll.push_front({key, value});
        auto it = dll.begin();
        mp[key] = it;
    }
};
