/*//: 40. 组合总和 II 对于这个回溯算法可以使用，先排序， 然后每次选择下标而不是数值， 利用排序后下标之间的关系进行剪枝.
另本题的结果集合中， 单个结果允许有重复的数值， 但是不允许有重复的结果， 这就要求不能有无意义的数只选取， 意识是， 
之前选了一个2， 然后跳过这个2， 又选取了后面一个2， 这和单纯的判断相邻 的元素是否相同然后跳过， 是不同的，这是更广义的，
这里你相邻的元素相同， 我也有可能选你， 
但只要你不是， 选一个2，然后跳过它， 下一次选下一个还是2， 这种无意义的重复， 所以我们利用选取vector中存储选取的下标， 
利用下标检查(排序后的相同元素下标都是相邻的) 来剪枝。 
*/
class Solution {
public:
    vector<int> cand;


    vector<vector<int>> r;
    int len;
    int tar;



    void func(int i, int j, int sum, vector<int> seled){
        if (i == len){
            return;
        }
        for(int t = j; t < len; ++t){
            int x = cand[t];

            if( t!=0 && cand[t] == cand[t-1] && (
                    !(bool)seled.size() ||
                    *(seled.end()-1)+1 != t

                    )){

                continue;
            }

            if(sum + x < tar){

                seled.push_back(t);
                func(i+1, t+1, sum+cand[t], seled);
                seled.erase(seled.end()-1);

            }else if(sum + x == tar){
                seled.push_back(t);

                r.push_back(seled);
                return;

            }else if(sum + x > tar){
                return;
            }

        }
    }



    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        cand = candidates;
        len = cand.size();
        tar = target;

        func(0, 0, 0, vector<int>());


        for(auto&i : r){
            for(auto &j : i){
                j = cand[j];
            }
        }
        return r;


    }
};
