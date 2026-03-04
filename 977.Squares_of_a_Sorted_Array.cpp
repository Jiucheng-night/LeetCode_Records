//方法1-直接排序
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;//建立一个新的vector
        for (int num : nums){//将原来的vector里的元素一个一个的平方然后放进去
            ans.push_back(num * num);
        }
        sort(ans.begin(), ans.end());//排序算法，调库
        return ans;
    }
};

// 方法2-双指针(利用nums本身是按照升序的排序条件，那样只需要将两个升序的数组归并排成升序的数组即可)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int negative = -1;
        int n = nums.size();
        //确定负数的最后一个位置
        for (int i = 0 ; i < n; i++){
            if (nums[i] < 0){
                negative ++;
            }
        }
        vector<int> ans;
        //最小的数一定在下面的两个位置之一
        int i = negative;
        int j = negative + 1;//非负数的第一个位置
        //两个升序的vector的归并
        while(i >= 0 || j < n){//因为更新是i--与j++，所以需要满足这两个条件之一
            if (i < 0){//全是非负数
                ans.push_back(nums[j] * nums[j]);
                j++;
            }
            else if (j == n){//全部是负数
                ans.push_back(nums[i] * nums[i]);
                i--;
            }
            //有负数也有非负数
            else if (nums[i] * nums[i] > nums[j] * nums[j]){
                ans.push_back(nums[j]* nums[j]);
                j++;
            }
            else {
                ans.push_back(nums[i]* nums[i]);
                i--;
            }
        }
        return ans;
    }
};

//方法3-双指针2-可能出现的最大值一定在两端
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);//由于从最大的数开始天，所以需要构建一个长度为n的vector
        //最大的数是两端之一
        for (int i = 0, j = n - 1, pose = n - 1; i <= j;){
            if (nums[i] * nums[i] < nums[j] * nums[j]){
                ans[pose] = nums[j] * nums[j];
                j--;
            }
            else{
                ans[pose] = nums[i] * nums[i];
                i++;
            }
            pose--;
        }
        return ans;
    }
};

