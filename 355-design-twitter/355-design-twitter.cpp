class Twitter {
public:
    unordered_map<int,set<int>> foll;
    unordered_map<int,vector<pair<int,int>>> news;
    int timer = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        news[userId].push_back({timer++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto &it : news[userId]){
            pq.push(it);
        }
        for(auto &ff : foll[userId]){
            for(auto &it : news[ff]){
                pq.push(it);
            }
        }
        vector<int> ans;
        int k = 10;
        while(k-- && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        foll[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        foll[followerId].erase(followeeId);
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