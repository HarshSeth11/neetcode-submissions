class Twitter {
public:
unordered_map<int, priority_queue<pair<int, int>>> mp;
unordered_map<int, set<int>> following;
int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        ++time;
        mp[userId].push({time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> temp;

        priority_queue<pair<int, int>> tempq = mp[userId];

        int totalTweet = 10;


        while(!tempq.empty() && totalTweet >= 0) {
            temp.push_back(tempq.top());
            tempq.pop();
            totalTweet--;
        }

        for(int s : following[userId]) {
            tempq = mp[s];
            totalTweet = 10;
            while(!tempq.empty() && totalTweet >= 0) {
                temp.push_back(tempq.top());
                tempq.pop();
                totalTweet--;
            }
        }

        priority_queue<pair<int, int>> merge(temp.begin(), temp.end());

        vector<int> ans;

        for(int i=0; i<10 && !merge.empty(); i++) {
            ans.push_back(merge.top().second);
            merge.pop();
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        following[followerId].erase(followeeId);
    }
};
