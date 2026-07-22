class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;

        while(i < j) {
            int sum = numbers[i] + numbers[j];
            if(sum == target && i < j) return {i+1, j+1};

            if(sum > target) j--;
            else if(sum < target) i++;
        }

        return {-1,-1};
    }
};
