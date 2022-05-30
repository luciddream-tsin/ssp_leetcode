
class Solution {
public:
    int jump(vector<int>& nums) {
        

        vector<int> count(nums.size(), 1e6);
        count[count.size()-1] = 0;

        for(int i = nums.size()-2; i >= 0; --i){

            int p=i;
            for(int j = 0; j<nums[i]; ++j){
                ++p;
                int s = nums.size();
                if(p == s) break;
                int tmp = 1+count[p];
                count[i] = std::min(count[i], tmp);
            }

        }

        return count[0];
    }
};
