//Return Kth to last
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *newNode(int d){
    Node *temp = new Node;
    temp->data = d;
    temp->next = NULL;
    return temp;
}

Node *returnKtolast(struct Node *head, int K){
    Node *prehead;
    int i = 0;
    while(i < K-1){
        prehead = head;
        head = head->next;
        delete prehead;
        //cout << head << endl;
        i++;
    }
    return head;
}

int main(){
    Node *head, *newhead;
    head = newNode(3);
    head->next = newNode(2);
    head->next->next = newNode(1);
    head->next->next->next = newNode(5); 
    head->next->next->next->next = newNode(7); 
    newhead = returnKtolast(head, 3);
    while(newhead != NULL){
        cout << newhead->data << " ";
        newhead = newhead->next;
    }
    cout << endl;
}
