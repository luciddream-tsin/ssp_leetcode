class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        for(int i = nums.size() - 2; i >= 0; --i){
            int n = i+1;
            if (nums[i] < nums[i]+nums[n]){
                nums[i] = nums[i]+nums[n];
            }
        }

        auto max_ = max_element(nums.begin(), nums.end());

        return *max_;
    }
};



 //回忆动态规划的那几个规定步骤
 //同时，学会使用在vector的中寻找最大的函数
