class Twitter {
public:
    stack<pair<int,int>> db;
    unordered_map<int, unordered_set<int>> follow_map;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        db.push({userId, tweetId});
        follow_map[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        if(follow_map.count(userId) == 0) return ans;
        stack<pair<int,int>> temp;
        for(int i = 0; ans.size() < 10 && db.size(); i++){
            auto cur = db.top();
            db.pop();
            if(follow_map[userId].count(cur.first)) ans.push_back(cur.second);
            temp.push(cur);
        }
        while(temp.size()){
            db.push(temp.top());
            temp.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follow_map[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follow_map[followerId].erase(followeeId);
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