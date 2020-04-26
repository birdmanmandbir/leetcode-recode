// 官方题解 https://leetcode-cn.com/problems/lfu-cache/solution/lfuhuan-cun-by-leetcode-solution/
// 可能的问题:freq_table[freq].erase(node);这个操作不是O(1)的, 且频繁调用到;
#include <list>
#include <unordered_map>
using namespace std;
struct Node {
    int key, val, freq;
    Node(int _key, int _val, int _freq)
        : key(_key)
        , val(_val)
        , freq(_freq)
    {
    }
};

class LFUCache {
private:
    int minFreq, capacity;
    unordered_map<int, list<Node>::iterator> map;
    // <frequency, list>
    unordered_map<int, list<Node>> freqMap;

public:
    LFUCache(int _capacity)
    {
        capacity = _capacity;
    }

    int get(int key)
    {
        if (map.find(key) != map.end()) {
            // exist
            // need to change freq
            auto node = map[key];
            auto key = node->key;
            auto val = node->val;
            auto freq = node->freq;
            freqMap[freq].erase(node);
            // after that, if current list is empty
            if (freqMap[freq].empty()) {
                freqMap.erase(freq);
                // freq is not exist, so minFreq may need update
                if (minFreq == freq) {
                    minFreq++;
                }
            }
            freqMap[freq + 1].push_front(Node(key, val, freq + 1));
            map[key] = freqMap[freq + 1].begin();
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if(capacity==0)return;
        if (map.find(key) != map.end()) {
            // exist
            auto node = map[key];
            auto nodeFreq = node->freq;
            freqMap[nodeFreq].erase(node);
            // after that, if current list is empty
            if (freqMap[nodeFreq].empty()) {
                freqMap.erase(nodeFreq);
                // freq is not exist, so minFreq may need update
                if (minFreq == nodeFreq) {
                    minFreq++;
                }
            }
            freqMap[nodeFreq + 1].push_front(Node(key, value, nodeFreq + 1));
            map[key] = freqMap[nodeFreq + 1].begin();
        } else {
            // not exist
            if (capacity == map.size()) {
                // get and delete nodeToDelete
                auto nodeToDelete = freqMap[minFreq].back(); // back return object, while begin return iterator(behave like pointer)
                auto nodeFreq = nodeToDelete.freq;
                // must erase map first, otherwise nodeToDelete is freed
                map.erase(nodeToDelete.key);
                freqMap[minFreq].pop_back();
                if (freqMap[nodeFreq].empty()) {
                    freqMap.erase(nodeFreq);
                    // freq is not exist, so minFreq may need update
                    if (minFreq == nodeFreq) {
                        minFreq++;
                    }
                }
            }
            // add new node; for new node, it frequency is 1
            freqMap[1].push_front(Node(key, value, 1));
            map[key] = freqMap[1].begin();
            minFreq = 1; // if map is not empty, minFreq must larger than 1
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LFUCache* cache = new LFUCache(2 /* capacity (缓存容量) */);
    cache->put(0, 0);
    cache->get(0);
}