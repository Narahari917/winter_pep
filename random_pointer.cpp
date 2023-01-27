#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode *next;
    ListNode() : val(0),next(nullptr) {}
    ListNode(int x) : val(x),next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Node{
    public:
    int val;
    Node *next, *random;
    Node() : val(0), next(nullptr) {}
};
Node *copy(Node * head){
    if(head==NULL){
        return NULL;
    }
    Node *  ptr = head, *qtr =NULL;
    while(ptr!=NULL){
        qtr = ptr->next;
        Node * newNode = new Node(ptr->val);
        newNode->next = qtr;
        ptr->next = newNode;
        ptr = qtr;
    }
    ptr = head;
    qtr = head->next;
    while(ptr!=NULL && qtr!=NULL){
        if(ptr->random!=NULL){
            qtr->random = ptr->random->next;
        }else{
            qtr->random = NULL;
        }
        ptr = qtr->next;
    }
    Node *newHead = head->next;
    ptr = head;
    while(ptr!=NULL && ptr->next !=NULL){
        qtr = ptr -> next;
        ptr->next = qtr->next;
    }
}