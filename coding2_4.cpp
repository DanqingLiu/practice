//Partition
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
struct Node *partition(Node *head, int d){
  Node *left = NULL;
  Node *right = NULL;
  Node *pt1 = NULL;
  Node *pt2 = NULL;
  while(head != NULL){
    if(head->data < d){
      if(left == NULL){
        left = head;
      }
      else{
        if(pt1 == NULL){
          pt1 = left;
          pt1->next = head;
          pt1 = pt1->next;
        }
        else{
          pt1->next = head;
          pt1 = pt1->next;
        } 
      }
    }
    else{
      if(right == NULL){
        right = head;
      }
      else{
        if(pt2 == NULL){
          pt2 = right;
          pt2->next = head;
          pt2 = pt2->next;
        }
        else{
          pt2->next = head;
          pt2 = pt2->next;
        } 
      }
    }
  head = head->next;
  }
  pt2->next = NULL;
  pt1->next = right;
  return left;
}

int main(){
  Node *head = newNode(3);
  head->next = newNode(5);
  head->next->next = newNode(8);
  head->next->next->next = newNode(5);
  head->next->next->next->next = newNode(10);
  head->next->next->next->next->next = newNode(2);
  head->next->next->next->next->next->next = newNode(1);
  Node *newlist = partition(head, 5);
  while(newlist != NULL){
    cout << newlist->data << " ";
    newlist = newlist->next; 
  }
  cout << endl;
}
