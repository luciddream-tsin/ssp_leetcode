class Solution {
public:
    bool canJump(vector<int>& nums) {

        vector<bool> tmp(nums.size(), false);
        tmp[nums.size()-1] = true;

        for(int i = nums.size()-1; i>=0; --i){
            int s = nums[i];
            int j = i;

            while(s--){
                ++j;
                if(j <nums.size() && tmp[j]){
                    tmp[i] = true;
                    break;
                };
            }

        }

        return tmp[0];

    }
};
