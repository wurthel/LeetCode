#include <iostream>
#include "vector"
#include "unordered_map"
#include "unordered_set"
#include "algorithm"

using namespace std;

struct Tweet {
    Tweet(int time, int tweetId) :
            time(time),
            tweetId(tweetId) {}

    int time;
    int tweetId;
};

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        Tweet *newTweet = new Tweet(time, tweetId);
        tweets[userId].push_back(newTweet);
        ++time;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> feeds;
        vector<Tweet*> news;

        for (Tweet *tweet : tweets[userId])
            news.push_back(tweet);

        for (const int &followerId: followers[userId])
            for (Tweet *tweet : tweets[followerId])
                news.push_back(tweet);

        auto comp = [](Tweet *a, Tweet *b) { return a->time > b->time; };
        sort(news.begin(), news.end(), comp);

        auto itr = news.begin();
        while(feeds.size() != 10 and itr != news.end()) {
            feeds.push_back((*itr)->tweetId);
            itr = next(itr);
        }

        return feeds;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followeeId != followerId)
            followers[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followeeId != followerId)
            followers[followerId].erase(followeeId);
    }

private:
    int time;
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<Tweet *>> tweets;
};


int main() {
    Twitter twitter;

    // User 1 posts a new tweet (id = 5).
    twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
    twitter.getNewsFeed(1);

// User 1 follows user 2.
    twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
    twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
    twitter.getNewsFeed(1);

// User 1 unfollows user 2.
    twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
    twitter.getNewsFeed(1);
    return 0;
}
