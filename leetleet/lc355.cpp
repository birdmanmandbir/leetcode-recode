#include "lib/general.h"
// https://leetcode-cn.com/problems/design-twitter/solution/mian-xiang-dui-xiang-she-ji-he-bing-k-ge-you-xu-li/
static int curTime = 0;
class Tweet {
public:
    int tweetId;
    int timeStamp;
    Tweet* next;
    Tweet(int id, int t)
    {
        tweetId = id;
        timeStamp = t;
        next = NULL;
    }
};
class User {
public:
    int userId;
    set<int> followers;
    Tweet* tweets;
    User(int id)
    {
        userId = id;
        follow(id);
        tweets = NULL;
    }
    void follow(int id)
    {
        followers.insert(id);
    }
    void unfollow(int id)
    {
        if (id != userId) {
            followers.erase(id);
        }
    }
    void postTweet(int tweetId)
    {
        Tweet* tmp = new Tweet(tweetId, curTime++);
        // 插入链表尾部开销大，所以插入头部
        // 这样导致最前面的是最新的
        tmp->next = tweets;
        tweets = tmp;
    }
};

class Twitter {
private:
    unordered_map<int, User*> userMap;
    struct cmp {
        bool operator()(Tweet* a, Tweet* b)
        {
            return a->timeStamp < b->timeStamp;
        }
    };

public:
    /** Initialize your data structure here. */
    Twitter()
    {
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        if (userMap.find(userId) == userMap.end()) {
            userMap[userId] = new User(userId);
        }
        userMap[userId]->postTweet(tweetId);
    }
    void myPush(
        priority_queue<Tweet*, vector<Tweet*>, cmp>& pq,
        Tweet* tweets)
    {
        if (tweets != NULL){
            pq.push(tweets);
        }
        // if (pq.size() < 10) {
        //     if (tweets != NULL)
        //         pq.push(tweets);
        // } else {
        //     if (tweets != NULL && pq.top()->timeStamp < tweets->timeStamp) {
        //         pq.pop();
        //         pq.push(tweets);
        //     }
        // }
    }
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        priority_queue<Tweet*, vector<Tweet*>, cmp> pq;
        vector<int> res;
        if (userMap.find(userId) == userMap.end()){
            return res;
        }
        set<int> userIDs = userMap[userId]->followers;
        for (auto id : userIDs) {
            User* tmp = userMap[id];
            myPush(pq, tmp->tweets);
        }
        // 由于vector已经保证输出个数，而且要求输出顺序为从大到小，所以需要用最大堆
        while (res.size() < 10 && !pq.empty()) {
            Tweet* cur = pq.top();
            res.push_back(cur->tweetId);
            myPush(pq, cur->next);
            pq.pop();
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        if (userMap.find(followerId) == userMap.end()) {
            userMap[followerId] = new User(followerId);
        }
        if (userMap.find(followeeId) == userMap.end()) {
            userMap[followeeId] = new User(followeeId);
        }
        userMap[followerId]->follow(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    // 写代码不要想当然，想好了再写
    void unfollow(int followerId, int followeeId)
    {
        if (userMap.find(followerId) != userMap.end()) {
            userMap[followerId]->unfollow(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main(){
    Twitter tw = Twitter();
    tw.postTweet(1, 5);
    tw.getNewsFeed(1);
    tw.follow(1,2);
    tw.postTweet(2, 6);
    tw.postTweet(2, 7);
    tw.postTweet(2, 8);
    tw.getNewsFeed(1);
    tw.unfollow(1,2);
    tw.getNewsFeed(1);

}