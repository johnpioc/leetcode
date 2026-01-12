class Twitter {
public:
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int,int>>> tweetMap;
    int count;

    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({ count++, tweetId });
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> feed;

        for (int followeeId : followMap[userId]) {
            vector<pair<int,int>> tweets = tweetMap[followeeId];

            for (pair<int, int> tweet : tweets) {
                if (feed.size() < 10) {
                    feed.push(tweet);
                } else {
                    if (tweet > feed.top()) {
                        feed.push(tweet);
                        feed.pop();
                    }
                }
            }
        }

        vector<pair<int,int>> tweets = tweetMap[userId];

        for (pair<int, int> tweet : tweets) {
            if (feed.size() < 10) {
                feed.push(tweet);
            } else {
                if (tweet > feed.top()) {
                    feed.push(tweet);
                    feed.pop();
                }
            }
        }

        vector<int> output(feed.size());
        for (int i = feed.size() - 1; i >= 0; i--) {
            output[i] = feed.top().second;
            feed.pop();
        }

        return output;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followMap.contains(followerId) && followMap[followerId].contains(followeeId)) {
            followMap[followerId].erase(followeeId);
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