class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int len1 = nums1.size();
        int len2 = nums2.size();
        int lent = len1 + len2;

        int i1 = 0;
        int i2 = 0;

        bool left = lent % 2;

        int a = 0, b = 0;

        for (int i = 0; i < lent; ++i) {
            b = a;
            if ( i1 < len1 && i2 < len2 ) {
                a = nums1[i1] <= nums2[i2] ? nums1[i1++] : nums2[i2++];
            }else if ( i1 == len1) {
                a = nums2[i2++];
            }else if ( i2 == len2) {
                a = nums1[i1++];
            }

            if (i == (lent/2)) break;
        }

        if (left) return a;
        else return (a+b)/2.0;
    }
};

// 类似使用归并排序， 但是多两部， 到中点时break， 而且每次保留两个历史数据， 为了应付数列长度为偶数， 中位数是中间两个的平均数。。。， b=a每个都要写所以写在最上面。
