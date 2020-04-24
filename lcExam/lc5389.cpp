#include "../lib/general.h"
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders)
    {
        map<int, map<string, int>> m;
        set<string> foodNames;
        for (int i = 0; i < orders.size(); i++) {
            int tableNum = stoi(orders[i][1]);
            string foodName = orders[i][2];
            foodNames.insert(foodName);
            if (m.find(tableNum) == m.end()) {
                m[tableNum] = map<string, int>();
            }
            if (m[tableNum].find(foodName) == m[tableNum].end()) {
                m[tableNum][foodName] = 0;
            }
            m[tableNum][foodName]++;
        }
        vector<vector<string>> res(1);
        for (vector<string> v : res) {
            v = vector<string>();
        }
        res[0].push_back("Table");
        for (auto it = foodNames.begin(); it != foodNames.end(); it++) {
            res[0].push_back(*it);
        }
        for (auto it = m.begin(); it!=m.end(); it++){
            res.push_back(vector<string>());
            auto curPair = (*it);
            int curTable = curPair.first;
            res[res.size()-1].push_back(to_string(curTable));
            auto curFoods = curPair.second;
            for (auto s:res[0]){
                if (s=="Table"){
                    continue;
                }
                res[res.size()-1].push_back(to_string(curFoods[s]));
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<string>> input = {
        { "David", "3", "Ceviche" },
        { "Corina", "10", "Beef Burrito" },
        { "David", "3", "Fried Chicken" },
        { "Carla", "5", "Water" },
        { "Carla", "5", "Ceviche" },
        { "Rous", "3", "Ceviche" }
    };
    (new Solution())->displayTable(input);
}