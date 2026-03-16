class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n -1;//nums1数组最后位置的索引，用来存放最大的数
        int i = m -1;//nums1非0的最后一个数的索引
        int j = n -1;//nums2最后一个数的索引
        while (j >= 0 ){//当nums2有数的操作
            if (i >=0 && nums1[i] > nums2[j]){//当nums1还有非零数且nums1最大的数要大于nums2最大的数时，此时nums1最后的数才应该是nums1[i]
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            else{//当i<0 或者 nums1[i] > nums2[j] nums1最后的数才应该是nums2[j]
                nums1[k] = nums2[j];
                k--;
                j--;
            } // 注意k，i，j的递减关系
        }
    }
};
