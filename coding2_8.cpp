//loop detection
#include<iostream>
#include<map>
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

//http://www.cplusplus.com/reference/map/map/find/
Node *loop(Node *head){
  map<Node*, char> hash_table;
  map<Node*, char>::iterator it;
  while(head != NULL){
    it = hash_table.find(head);
    if(it != hash_table.end()){
      return head;
    }
    hash_table[head] = head->data;
    head = head->next;
  }
  return NULL;
}

int main(){
  Node *n1= newNode('a'); 
  n1->next = newNode('b'); 
  n1->next->next = newNode('c'); 
  n1->next->next->next = newNode('d'); 
  n1->next->next->next->next = n1->next->next; 
  Node *loop_node = NULL;
  loop_node = loop(n1);
  if(loop_node != NULL){
    cout << " The first node of the loop is: " << loop_node->data << endl;
  }
  else{
    cout << " There is no loop in this list." << endl;

  }
}
