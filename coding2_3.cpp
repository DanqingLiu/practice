//Delete middle node
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Node *newNode(int d){
    Node *temp = new Node;
    temp->data = d;
    temp->next = NULL;
    return temp;
}

void deleteMidnode(Node *head){
    Node *prept1, *pt1, *pt2;
    pt1 = head;
    pt2 = pt1;
    while(pt2->next != NULL){
        if (pt2->next->next == NULL){
            break;
        }
        else{
            prept1 = pt1;
            pt1 = pt1->next;
            pt2 = pt2->next->next;
        }
    }
    prept1->next = pt1->next;
    delete(pt1);
}

int main(){
    Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    deleteMidnode(head);
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
