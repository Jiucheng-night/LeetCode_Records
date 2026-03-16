class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {//遍历数组中的所有元素，当元素与val不相等时，将值放入开头， 同时j需要加1
                nums[j] = nums[i];//！！很重要，将相等的问题改为不相等的问题，很好的判断了
                j++;
            }
        }
        return j;
    }
};

