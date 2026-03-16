class Solution {
public:
    void reverseString(vector<char>& s) {
        int right = s.size() -1;//右指针指向需要处理的右边的元素
        for (int left = 0; left < right; left++, right--){//左指针指向左边需要处理的数
            swap(s[left], s[right]);//交换左右指针指向的元素，同时更新左指针与右指针的位置，当左指针>=右指针时停止
        }
    }
};
//双指针