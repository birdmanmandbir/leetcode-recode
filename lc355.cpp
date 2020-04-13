#include "lib/general.h"
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
    struct cmp{
        bool operator()(Tweet* a, Tweet* b){

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

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        return vector<int>();
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