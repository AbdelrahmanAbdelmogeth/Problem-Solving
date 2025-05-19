#define SIMPLE_HEAP_VERSION=1  // Comment this out to use the alternative getNewsFeed implementation

struct Tweet{
    int id;
    int time;
    Tweet(int i, int t) : id(i), time(t) {}
};

struct cmp {
    bool operator()(const Tweet& a, const Tweet& b) {
        return a.time < b.time; // max heap
    }
};

class Twitter {
private:
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<Tweet>> tweetsMap;
    int time;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        // tweetsMap[userId].push_back({tweetId, time++});
        tweetsMap[userId].emplace_back(tweetId, time++);
    }
    
#ifdef SIMPLE_HEAP_VERSION
    // Simple version of getNewsFeed:
    // Collect up to last 10 tweets from each followed user (including self),
    // push all into a max heap, then pop top 10 tweets.
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        priority_queue<Tweet, vector<Tweet>, cmp> maxHeap;

        // Get all users to consider (followers + self)
        unordered_set<int> users = followMap[userId];
        users.insert(userId);

        // Push up to last 10 tweets from each user into the max heap
        for (int uid : users) {
            const auto& tweets = tweetsMap[uid];
            int start = max(0, (int)tweets.size() - 10);
            for (int i = start; i < tweets.size(); ++i) {
                maxHeap.push(tweets[i]);
            }
        }

        // Extract up to 10 most recent tweets from the heap
        while (!maxHeap.empty() && result.size() < 10) {
            result.push_back(maxHeap.top().id);
            maxHeap.pop();
        }

        return result;
    }
#else
    // Optimized version of getNewsFeed:
    // Uses a heap with pairs tracking tweet and the index within that user's tweet list.
    // This allows merging tweets from different users more efficiently,
    // by only pushing the next recent tweet when one is popped from the heap.
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        using P = pair<Tweet, pair<int, int>>; // (tweet, (userId, tweetIndex))
        
        // Lambda comparator for max heap by tweet time
        auto cmp2 = [](const P& a, const P& b) {
            return a.first.time < b.first.time;
        };
        
        priority_queue<P, vector<P>, decltype(cmp2)> pq(cmp2);

        // Set of users to consider (followers + self)
        unordered_set<int> users = followMap[userId];
        users.insert(userId);

        // Push the latest tweet from each user onto the heap
        for (int uid : users) {
            const auto& tweets = tweetsMap[uid];
            if (!tweets.empty()) {
                int lastIdx = tweets.size() - 1;
                pq.push({tweets[lastIdx], {uid, lastIdx}});
            }
        }

        // Extract up to 10 most recent tweets
        while (!pq.empty() && result.size() < 10) {
            auto [tweet, info] = pq.top();
            pq.pop();
            int uid = info.first;
            int idx = info.second;

            // Add the tweet id to the result
            result.push_back(tweet.id);

            // If there is an older tweet from this user, push it onto the heap
            if (idx > 0) {
                pq.push({tweetsMap[uid][idx - 1], {uid, idx - 1}});
            }
        }

        return result;
    }
#endif
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followMap[followerId].erase(followeeId);
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