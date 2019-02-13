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

void deleteMidnode(Node *mid){
    Node *temp = mid->next;
    mid->data = temp->data;
    mid->next = temp->next;
    delete(temp);
}

int main(){
    Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    Node *mid = head->next->next;
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    deleteMidnode(mid);
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
