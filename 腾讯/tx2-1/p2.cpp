#include "lib/general.h"
#include <list>
class LRUCache {
private:
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> map;
    int capacity;

public:
    LRUCache(int capacity_){
        capacity = capacity_;
    }
    int getValue(int key)
    {
        if (map.find(key) == map.end()) {
            return -1;
        }
        int val = map[key]->second;
        cache.erase(map[key]);
        cache.push_front({key,val});
        map.erase(key);
        map[key] = cache.begin();
        return val;
    }
    void insertValue(int key, int val)
    {
        if (map.size()==capacity){
            auto nodeToDelete = cache.begin();
            map.erase(nodeToDelete->first);
            cache.pop_front();
        }
        if (map.find(key) != map.end()) {
            cache.erase(map[key]);
            map.erase(key);
        }
        cache.push_front({key, val});
        map[key] = cache.begin();
    }
};