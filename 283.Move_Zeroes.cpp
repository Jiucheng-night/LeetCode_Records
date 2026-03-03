class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;//左指针，指向已完成数的后一个位置
        int right = 0;//右指针，指向需要测试的新的数
        while (right < nums.size()){
            if (nums[right]){//如果测试的数不为零的话，就交换左指针与右指针的值
                swap(nums[left], nums[right]);
                left++;//同时由于找到一个不为零的数，需要将左指针更新位置
            }
            right++;//不管测试数是否为零，都需要更新右指针，用来遍历所有的值
        }
    }
};
//注意到这也是一个双指针的题目。
