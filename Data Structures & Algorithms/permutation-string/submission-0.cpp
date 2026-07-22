class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        int k = s1.size();
        int start = 0;

        for(int i=0; i<s1.size(); i++) {
            freq1[s1[i]-'a']++;
        }

        for(int end=0; end<s2.size(); end++) {
            freq2[s2[end] - 'a']++;
            if(end - start + 1 > k) {
                freq2[s2[start]-'a']--;
                start++;
            }
            cout<<freq2[0]<<"  "<<freq2[1]<<"  "<<freq2[2]<<endl;
            if(freq1 == freq2) return true;
        }

        return false;
    }
};
