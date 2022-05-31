class Solution {
public:
    string convert(string s, int n) {
        if (n ==1) return s;

        vector<string> result(n, string());

        int b = n *2 - 2;

        //test size
        for (int i = 0; i < s.length(); ++i) {
            int a = i % b;

            if (a > b/2){
                a = i - ((a - b/2) *2);
                a = a % b;
            }
            result[a] += s[i];
        }

        string str;

        for(auto s : result){
            str += s;
        }
        return str;

    }
};
//锻炼你拿草稿纸， 开始列出 索引， 及其 之间的关系, 用公式表达出来
