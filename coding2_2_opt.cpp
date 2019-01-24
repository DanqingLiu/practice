//Return Kth to last
//https://www.uow.edu.au/~lukes/TEXTBOOK/notes-cpp/functions/refparams.html
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

Node returnKtolast(struct Node*& head, int K){
    Node *prehead;
    int i = 0;
    while(i < K-1){
        prehead = head;
        head = head->next;
        delete prehead;
        //cout << head << endl;
        i++;
    }
}

int main(){
    Node *head;
    head = newNode(3);
    head->next = newNode(2);
    head->next->next = newNode(1);
    head->next->next->next = newNode(5); 
    head->next->next->next->next = newNode(7); 
    returnKtolast(head, 3);
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
