//双指针方法
//src (source pointer)：快指针，负责遍历数组
//dst (destination pointer)：慢指针，指向去重后数组的最后一个位置
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int src = 1;//指向第二个元素
        int dst = 0;//指向第一个元素
        int count = 1;//第一个元素肯定是不重复的，所以count为1
        while (src < nums.size()) {
            if (nums[src]==nums[dst]) {
                src++;//若两个数相等，则将src+1来比较后面的数
            }
            else {//若两数不相等，则将dst指向的数更新
                dst++;
                nums[dst] = nums[src];//将独特的数字赋值到慢指针上
                src++;//快指针继续更新
                count++;//独特的数字数量增加
            }
        }
        return count;
    }
};
