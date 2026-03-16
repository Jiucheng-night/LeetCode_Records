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
//方法1-递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr){
            return list2;
        }
        else if (list2 == nullptr){
            return list1;
        }
        else if (list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list2->next, list1);
            return list2;
        } 
    }
};


//方法2-迭代法
//由于list1和list2都是升序的，所以比较list1和list2的最小的元素，选取其中更小的作为心链表的开头，然后不断更新两个链表
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * prehead = new ListNode(-1);
        ListNode * prev = prehead;
        while (list1 != nullptr && list2 != nullptr){
            if (list1->val < list2->val){
                prev->next = list1;
                list1 = list1->next;
            }
            else {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }
        prev->next = list1==nullptr ? list2 : list1;
        ListNode * result = prehead->next;
        delete prehead;
        return result;
    }
};