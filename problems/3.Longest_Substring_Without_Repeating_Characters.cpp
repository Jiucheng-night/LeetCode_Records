//方法1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>occ;//创建哈希表记录每个字符是否出现过
        int n = s.size();
        int end = -1, ans = 0;//右指针在-1处，还未开始滑动
        //遍历左指针的位置
        for (int i = 0; i < n; i++){
            //第一次左指针不用移除，以后每一次循环需要将上一次的左指针指向的值删去
            if (i != 0 ){
                occ.erase(s[i-1]);
            }
            //需要满足右指针不超出界限，同时右指针指向的下一个值不能出现第二次
            while (end + 1 < n && !occ.count(s[end+1]))//!occ.count(s[end+1])数s[end+1]在前面存在的次数，如果为0，则满足条件
            {
                occ.insert(s[end+1]);//将右指针指向的下一个值插入到hash表中
                end++;//更新右指针的位置
            }
            ans = max(ans, end - i + 1);//取最大的长度
        }
        return ans;
    }
};

//方法2
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int>hash;//创建hash表记录每个字符是否出现过
        int ans = 0;
        for (int right = 0, left = 0; right < n; right++){//遍历右指针的位置
            hash[s[right]]++;//记录s[right]的出现次数，如果第一次出现就是1，第二次出现就会大于1，表示重复
            while (hash[s[right]] > 1){//出现重复时
                hash[s[left]]--;//将s[left]的出现次数减1，表示将此数去除
                left++;//更新左指针的位置
            }
            ans = max(ans, right - left +1);//取最大的值
        }
        return ans;
    }
};