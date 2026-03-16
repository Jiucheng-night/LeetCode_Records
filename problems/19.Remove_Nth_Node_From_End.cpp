/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//方法1-遍历找到第n个数
class Solution {
public:
    int get_length(ListNode* head){
        int length = 0;
        while (head){
            length++;
            head = head->next;
        }
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);  // 创建虚拟头节点
        int length = get_length(head);              // 获取链表长度
        ListNode* cur = dummy;
    
        // 移动到要删除节点的前一个节点
        for (int i = 1; i < length - n + 1; ++i) {
            cur = cur->next;
        }
        cur->next = cur->next->next;  // 执行删除操作
        ListNode* ans = dummy->next;
        delete dummy;                  // 释放虚拟头节点
        return ans;
    }   
};

//方法2-栈
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);  // 创建虚拟头节点
        stack<ListNode*> stk;
        ListNode* cur = dummy;
        while (cur){
            stk.push(cur);
            cur = cur->next;
        }
        for(int i = 0; i < n; i++){
            stk.pop();
        }
        ListNode* prev = stk.top();
        prev->next = prev->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }   
};

//方法3-快慢指针
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);  
        ListNode* first = head;
        ListNode* second = dummy;
        for (int i = 0; i < n; i++){
            first= first->next;
        }
        while (first){//当这个条件不满足时，first到达结尾，此时second的位置就是倒数第n个元素的前一个元素
            first= first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }   
};
