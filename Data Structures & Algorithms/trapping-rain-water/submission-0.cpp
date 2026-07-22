class Solution {
public:
    int trap(vector<int>& height) {
        int i=0;
        int j=height.size()-1;

        int left_max = height[i];
        int right_max = height[j];

        int water_maxi = 0;

        while(i < j) {
            if(left_max < right_max) {
                i++;
                left_max = max(height[i], left_max);
                water_maxi += left_max - height[i];
            }
            else{
                j--;
                right_max = max(height[j], right_max);
                water_maxi += right_max - height[j];
            }
        }

        return water_maxi;
        
    }
};
