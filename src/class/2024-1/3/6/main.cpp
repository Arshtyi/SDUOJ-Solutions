#include "stdio.h"
#include "stdlib.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *createList(int a[], int n);

struct ListNode *sortList(struct ListNode *head);

void output(struct ListNode *head);

struct ListNode *insertNode(struct ListNode *head, int n);

struct ListNode *removeNode(struct ListNode *head, int n);

int main() {
    int a[10000];
    int n, ins, rm;
    scanf("%d", &n);
    scanf("%d", &ins);
    scanf("%d", &rm);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    struct ListNode *list = createList(a, n);
    output(list);
    list = sortList(list);
    output(list);
    list = insertNode(list, ins);
    output(list);
    list = removeNode(list, rm);
    output(list);
    return 0;
}
struct ListNode *createList(int a[], int n) {
    // TODO: 填写创建链表的函数
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    for(int i = 0;i < n;i ++){
        struct ListNode *NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        NewNode->val = a[i];
        NewNode->next = NULL;
        if(head == NULL)head = tail = NewNode;
        else{tail->next = NewNode;tail = NewNode;}
    }
    return head;
}

struct ListNode *sortList(struct ListNode *head) {
    // TODO: 填写链表排序的函数
    struct ListNode *current1 = head;
    struct ListNode *current2 = head;
    for(current1 = head;current1->next;current1=current1->next){
        for(current2=head;current2->next;current2=current2->next){
            if((current2->val) > (current2->next->val)){
                int t = current2->val;
                current2->val = current2->next->val;
                current2->next->val = t;
            }
        }
    }
    return head;
}

void output(struct ListNode *head) {
    // TODO: 填写输出每个节点值的函数
    struct  ListNode *current = head;
    while(current){
        printf("%d\n",current->val);
        current = current->next;
    }
}

struct ListNode *insertNode(struct ListNode *head, int n) {
    // TODO: 填写向有序链表插入值的函数
    if(n <= head->val){
        struct ListNode *p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->next = head;
        p->val = n;
        head = p;
    }else{
        for(struct ListNode *q = head; q->val <= n ;q=q->next){
            if(q->next){
                if(q->val <= n && n <= q->next->val){
                    struct ListNode *m =  (struct ListNode*)malloc(sizeof(struct ListNode));
                    m->next = q->next;
                    q->next = m;
                    m->val = n;
                    break;
                }
            }else {
                struct ListNode *o =(struct ListNode*)malloc(sizeof(struct ListNode));
                q->next = o;
                o->next = NULL;
                o->val = n;
                break;
            }
            
        }
    }

    return head;
}

struct ListNode *removeNode(struct ListNode *head, int n) {
    // TODO: 填写删除链表中指定值的函数
    struct ListNode *current1 = head;
    struct ListNode *last = head;
    for(current1 = head;current1;current1 = current1->next){
        if(current1->val == n){
            last->next = current1->next;
        }
        last = current1;
    }
    return head;

}