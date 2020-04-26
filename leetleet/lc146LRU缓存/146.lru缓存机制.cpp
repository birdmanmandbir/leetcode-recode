#include <unordered_map>
#include <list>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

// @lc code=start
class LRUCache
{
public:
    LRUCache(int capacity) {_cap=capacity;}

    int get(int key)
    {
        if (map.find(key) != map.end())
        {
            auto result = *map[key];
            cache.erase(map[key]);
            cache.push_front(result);
            map[key] = cache.begin();
            return result.second;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        // 如果map中找不到
        if (map.find(key) == map.end())
        {
            if (cache.size() + 1 > _cap)
            {
                // map 是记录cache的信息, 所以删除时候先删map
                // ??? front, back, begin, end
                map.erase(cache.back().first);
                cache.pop_back();
            }
        }
        // map 中存在
        else
        {
            cache.erase(map[key]);
            map.erase(key);
        }

        cache.push_front({key, value});
        map[key] = cache.begin();
    }

private:
    int _cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
};