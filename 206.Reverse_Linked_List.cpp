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
//方法1-迭代法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;//创建一个空指针
        ListNode* curr = head;//当前指针指向ListNode的开头位置
        while(curr){//当curr不是空指针时，条件为真
            ListNode* next = curr->next; //将curr的指向下一个位置的指针赋值给next
            curr->next = prev;// 将curr的指向下一个位置的指针改成指向前一个位置
            prev = curr;//将curr指针赋值给prev
            curr = next;//将next指针赋值给curr
        }
        return prev;//最后prev会指向ListNode的最后一个位置，同时也是新的ListNode的起点也就是head指针
    }
};
//head 是一个指针，它指向一个位置（内存地址），这个位置上有：
//一个值（val）- 比如 1, 2, 3
//一个指向下一个位置的指针（next）



//方法2-递归法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //这个if循环只会执行一次(包括是空链表或者一个元素的链表的情况)
        if(!head || !head->next){
            return head;
        }
        ListNode* newhead =  reverseList(head->next);//最后一次的递归结果是reverseList的结果返回指向最后一个位置的指针，然后接下来执行下面的代码
        //之所以不写newhead->next = head;是因为newhead始终指向最后一个位置
        head->next->next = head;//此时head是指向newhead的前一个位置的指针，是让head的下一个位置指向head
        head->next = nullptr;//同时head的next指针变成空，防止head和下一个位置互指
        return newhead;//返回newhead，相当于没有改变newhead的值
    }
};
//例子：1->2->3
//第一次执行，if条件不满足，执行ListNode* newhead =  reverseList(head->next)， 这一步的head指向的位置是1的位置
//第二次执行reverseList，此时函数的输入是指向2的位置的指针，同样再次执行ListNode* newhead =  reverseList(head->next)，这一步的head指向2的位置
// 第三次执行reverseList，满足if条件，返回head，此时的head是指向3的位置的指针
//得到第三次执行的结果带入到第二次中的reverseList函数，newhead为指向3的位置的指针， head->next->next = head(此时的head指向2的位置)这一步是3->2,同时2->nullptr返回newhead
//得到第二次的结果，带入到第一次中的reverseList函数，newhead为指向3的位置的指针，head->next->next = head(此时的head指向1的位置),完成2->1,1->nullptr
//最后返回newhead指向3的位置，为链表的入口
