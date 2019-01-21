// Remove Dups
//Using hash table: https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/
#include <unordered_map>
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
    unordered_map<int,int> hash_table;
    Node *pt1,*dup;
    pt1 = head;
    int i = 0;
    hash_table[pt1->data] = 0;
    while(pt1->next != NULL){
        //cout << pt1->data << endl;
        if(hash_table.find(pt1->next->data) == hash_table.end()){
            i++;
            hash_table[pt1->next->data] = i;
            pt1 = pt1->next;
        }
        else{
            dup = pt1->next; 
            pt1->next = dup->next;
            delete(dup);
        }
    }
}

//Creat a linked list.
int main(){
    Node *head = NewNode(3);
    head->next = NewNode(3);
    head->next->next = NewNode(2);
    head->next->next->next = NewNode(3);
    head->next->next->next->next = NewNode(3);
    RemoveDups(head);
    Node *iter = head;
    while(iter != NULL){
        cout << iter->data << endl;
        iter = iter->next;
    }
}
