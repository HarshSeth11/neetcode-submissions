class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;
        map<int, int> mp;
        for(int i=0; i<hand.size(); i++) {
            mp[hand[i]]++;
        }

        while(mp.size() != 0) {
            int itr = mp.begin()->first;
            int i=0;
            for(;i<groupSize; i++) {
                if(mp.find(itr) == mp.end()) return false;
                mp[itr]--;
                if(mp[itr] == 0) {
                    mp.erase(itr);
                }
                itr++;
            }
            if(i != groupSize) return false;
        }

        return true;
    }
};
