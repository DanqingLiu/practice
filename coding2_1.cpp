// Remove Dups
//https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *NewNode(int d){
    Node *temp = new Node;
    temp->data = d;
    temp->next = NULL;
    return temp;
}

void RemoveDups(struct Node *head){
    Node *pt1, *pt2, *dup;
    pt1 = head;
    while(pt2 != NULL && pt1->next != NULL){
        pt2 = pt1;
        while(pt2->next != NULL){
            if(pt1->data == pt2->next->data){
                dup = pt2->next;
                pt2->next = dup->next;
                delete(dup);
            }
            else{
                pt2 = pt2->next;
            }
        }
        pt1 = pt1->next;
    }
}

//Creat a linked list.
int main(){
    Node *head = NewNode(3);
    head->next = NewNode(3);
    head->next->next = NewNode(5);
    head->next->next->next = NewNode(3);
    head->next->next->next->next = NewNode(3);
    RemoveDups(head);
    Node *iter = head;
    while(iter != NULL){
        cout << iter->data << endl;
        iter = iter->next;
    }
}
