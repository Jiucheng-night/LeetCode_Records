//方法1-枚举法-会超时
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.size(); start ++){
            int sum = 0;
            for (int end = start; end < nums.size(); end ++){
                sum += nums[end];
                if (sum == k){
                    count += 1;
                }
            }
        }
        return count;
        
    }
};

//方法2-前缀和+哈希表
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int pre = 0;//前缀和
        unordered_map<int, int>hash;//前缀和，出现次数
        hash[0]=1;//初始化，空前缀和出现1次
        for (auto& x : nums){
            pre += x;//计算前缀和
            if ( hash.find(pre -k) != hash.end()){//注意如果j到i的子数组和为k，那么有pre[j]-pre[i-1]=k
                count += hash[pre - k];
            }
            hash[pre]++;//保存此前缀和出现的次数
        }
        return count;
    }
};