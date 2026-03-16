//方法1-暴力解法-会超时
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n == 0){
            return 0;
        }
        int ans = __INT_MAX__;
        for (int i = 0 ; i < n ; i++){
            int sum = 0;
            for (int j = i; j < n; j++){
                sum += nums[j];
                if (sum >= target){
                    ans = min(j - i + 1, ans);
                    break;
                }
            }
        }
        return ans ==  __INT_MAX__ ? 0 : ans;
    }
};

//方法2-前缀和+二分查找
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        vector<int> sums(n + 1, 0); 
        // 为了方便计算，令 size = n + 1 
        // sums[0] = 0 意味着前 0 个元素的前缀和为 0
        // sums[1] = A[0] 前 1 个元素的前缀和为 A[0]
        // 以此类推
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            int s = target + sums[i - 1];
            auto bound = lower_bound(sums.begin(), sums.end(), s);
            if (bound != sums.end()) {
                ans = min(ans, static_cast<int>((bound - sums.begin()) - (i - 1)));
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

//方法3-滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n == 0){
            return 0;
        }
        int ans = __INT_MAX__;
        int start = 0;//开始窗口
        int end = 0;//结束窗口
        int sum = 0;//计算总和
        while (end < n){//end窗口向后滑动
            sum += nums[end];//加上end窗口指向的值，得到数组的总和
            while (sum >= target){//当sum满足条件时，进行操作
                ans = min(ans, end - start + 1);//可能有多个答案，因此需要选取最小的
                sum -= nums[start];//去除start指向的值
                start ++;//同时start窗口向后移动，保证以start开头的数组长度是最小的
            }
            end ++;//end窗口向后移动，注意无论是否满足条件，都应当进行更新操作
        }
        return ans == __INT_MAX__ ? 0: ans;
    }
};