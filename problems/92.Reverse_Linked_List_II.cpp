//方法1
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
class Solution {
//206的反转链表代码
private:
    void reverseLinkedList(ListNode *head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;

        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //创建一个虚拟节点，防止因为头节点也要反转时的讨论
        ListNode *dummyNode = new ListNode(-1);
        //让虚拟节点指向head
        dummyNode->next = head;
        //将虚拟节点赋值给pre
        ListNode *pre = dummyNode;
        //找到left的前一个节点
        for (int i = 0; i < left - 1; i++){
            pre = pre->next;
        }
        //到达right节点
        ListNode *rightNode = pre;
        for (int i = 0; i < right - left + 1; i++){
            rightNode = rightNode->next;
        }
        //到达left节点
        ListNode *leftNode = pre->next;
        //保存rightNode的下一个节点
        ListNode *curr = rightNode->next;
        //阶段节点
        pre->next = nullptr;
        rightNode->next = nullptr;
        //反转left——right中间的节点
        reverseLinkedList(leftNode);//leftNode是left的位置
        //将被反转后的链表接回来
        pre->next = rightNode;//left的前一个节点的下一个节点赋值为rightNode，也就是反转后的起点
        leftNode->next = curr;//反转后的终点接上curr
        //删除new出的空间，返回整个链表的起点
        ListNode* result=  dummyNode->next;
        delete dummyNode;
        return result;
    }
};

//方法2-只需遍历链表一次
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        // 设置 dummyNode 是这一类问题的一般做法
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode *pre = dummyNode;
        for (int i = 0; i < left - 1; i++){
            pre = pre->next;
        }
        
        ListNode * curr = pre->next;
        ListNode * next;
        for(int i = 0; i < right - left; i++){
            next = curr->next;
            curr->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }

        ListNode* result =  dummyNode->next;
        delete dummyNode;
        return result;
    }
};