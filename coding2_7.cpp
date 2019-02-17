//intersection
#include<iostream>
using namespace std;

struct Node{
  char data;
  struct Node *next;
};

struct Node *newNode(char x){
  Node *temp = new Node;
  temp->data = x;
  temp->next = NULL;
  return temp;
}

int Length(Node *head){
  int i = 0;
  while(head != NULL){
    head = head->next;
    i++;
  }
  return i;
}

Node *intersection(Node *n1, Node *n2){
  while(n1 != NULL){
    Node *pt = n2;
    while(pt != NULL){
      if(n1 == pt){
        return n1;
      }
      pt = pt->next;
    }
   n1 = n1->next;
  }
  return NULL;
}

int main(){
  Node *n1= newNode('a'); 
  n1->next = newNode('b'); 
  n1->next->next = newNode('c'); 
  Node *n2= newNode('e'); 
  n2->next = newNode('b'); 
  //n2->next = n1->next; 
  n2->next->next = newNode('f'); 
  n2->next->next->next = newNode('g'); 
  Node *inter = NULL;
  inter = intersection(n1, n2);
  if(inter != NULL){
    cout << " The intersection node is: " << inter->data << endl;
  }
  else{
    cout << " There is no intersection between these two lists." << endl;

  }
}
