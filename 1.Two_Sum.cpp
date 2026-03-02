class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i =0; i < nums.size();i++) { // 遍历所有的数字，逐一完成加法看是否等于目标数，若等于则输出，若全部没有则输出空
            for (int j = i+ 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i,j};
                }
            }
        }
        return {};
    }
};

//哈希表做法1 two pass hash table(必须先把hash表建立完成才开始找)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;//创建一个哈希表，相当于python里的字典
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = i;//将nums里的数字和排序存入到哈希表中
        }
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];//计算当前值所需要的补值
            if (hash.find(complement) != hash.end() && hash[complement] != i) {
                //hash.find(complement) != hash.end()，找的元素在哈希表中，如果不存在指针将会指向hash.end()
                return {i,hash[complement]}; //相当于return vector<int>{i, hash[complement]};
            }
        }
        return {};
    }
};

//哈希表做法2 one pass hash table (边遍历边检查，不需要先建好整个表)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;//创建一个哈希表，相当于python里的字典
        for (int i =0; i < nums.size(); i++) {
            int complement = target - nums[i];//计算补值
            if (hash.find(complement) != hash.end()) {
                return {hash[complement], i};//如果在哈希表里面直接输出，注意这里查找的值在前面，因为哈希表是边查边建立的，所以只能从前面找数
            }
            hash[nums[i]] = i; // 不存在就将此数以及索引存入到哈希表当中
        }
        return {};// 若条件不存在则返回空
    }
};

