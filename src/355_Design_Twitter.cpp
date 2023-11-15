int global_Time = 0;
class Tweet {
public:
    int id;
    int time;
    Tweet *next;
    
    Tweet(int id) {
        this->id = id;
        this->time = global_Time++;
        next = nullptr;
    }
};

class User {
public:
    int id;
    Tweet *tweet;
    unordered_set<int> follows;

    User(int id) {
        this->id = id;
        tweet = nullptr;
    }

    void follow(int followeeId) {
        if (followeeId == id) return;
        follows.insert(followeeId);
    }

    void unfollow(int followeeId) {
        if (!follows.count(followeeId) || followeeId == id) return;
        follows.erase(followeeId);
    }

    void post(int tweetId) {
        Tweet *newTweet = new Tweet(tweetId);
        newTweet->next = tweet;
        tweet = newTweet;
    }
};

class Twitter {    
private:
    unordered_map<int, User*> user_map;
    
    bool contain(int id) {
        return user_map.find(id) != user_map.end();
    }
    
public:
    Twitter() {
        user_map.clear();
    }
    
    void postTweet(int userId, int tweetId) {
        if (!contain(userId)) {
            user_map[userId] = new User(userId);
        }
        user_map[userId]->post(tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        if (!contain(userId)) return {};

        struct cmp {
            bool operator()(const Tweet *a, const Tweet *b) {
                return a->time < b->time;
            }
        };
        
        priority_queue<Tweet*, vector<Tweet*>, cmp> q;

        //自己的推文链表
        if (user_map[userId]->tweet) {
            q.push(user_map[userId]->tweet);
        }
        
        for (int followeeId : user_map[userId]->follows) {
            if (!contain(followeeId)) {
                continue;
            }
            Tweet *head = user_map[followeeId]->tweet;
            if (head == nullptr) continue;
            q.push(head);
        }
        
        while (!q.empty()) {
            Tweet *t = q.top(); 
            q.pop();
            rs.push_back(t->id);
            if (rs.size() == 10) return rs;
            if (t->next) {
                q.push(t->next);
            }
        }
        return rs;
    }
    
    
    void follow(int followerId, int followeeId) {
        if (!contain(followerId)) {
            user_map[followerId] = new User(followerId);
        }
        
        user_map[followerId]->follow(followeeId);
    }
    
    
    void unfollow(int followerId, int followeeId) {
        if (!contain(followerId)) return;
        
        user_map[followerId]->unfollow(followeeId);
    }
};