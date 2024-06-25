#include <stdio.h>
#include <iostream>

class Node {
public:
  int data;
  Node* next;

  Node(){
    this->data = 0;
    this->next = NULL;
  }

  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};

class LinkedList { 
public:
  Node* head;
  LinkedList(){
    head = NULL;
  }

  void insertNode(int);

  void deleteNode(int);

  void displayList();

  int getLength();

  int sum(Node*);

  int recursiveLength(Node*);

  int getMaximum(Node*, int);
};

int LinkedList::getLength(){
  int length = 0;
  Node* tempNode = head;

  if (head==NULL){
    return 0;
  } else if (head->next==NULL){
    return 1;
  } else {
    while (tempNode->next!=NULL){
      length++;
      tempNode = tempNode->next;
    }
    length++;
  }
  return length;
}

void LinkedList::insertNode(int data){
  Node* newNode = new Node(data);
  Node* tempNode = head;

  if (head==NULL){
    head = newNode;
    return;
  }

  while (tempNode->next!=NULL){
    tempNode = tempNode->next;
  }
  tempNode->next = newNode;
  return;
}

void LinkedList::deleteNode(int nodePos){
  Node* tempNode = head;
  Node* temp2;
  int length = getLength();

  if (head == NULL){
    std::cout << "List is empty";
    return;
  } else if (head->next == NULL){
    head = NULL;
    return;
  } else if (nodePos >= length || nodePos < 0){
    std::cout << "Invalid index.";
    return;
  } else if (nodePos==0){
    head = head->next;
  } else if (nodePos==1){
    tempNode = head->next;
    head->next = tempNode->next;
  }
  else {
    std::cout << "TEST1";
    while (nodePos-- >= 1){
      temp2 = tempNode;
      tempNode = tempNode->next;
    }
    temp2->next = tempNode->next;
    delete tempNode;
    return;
  }
}

void LinkedList::displayList(){
  Node* tempNode = head;
  while (tempNode->next!=NULL){
    printf("%d\n", tempNode->data);
    tempNode = tempNode->next;
  }
  printf("%d\n", tempNode->data);
}

int LinkedList::sum(Node* node){
  if (node->next==NULL){
    return node->data;
  } else {
    return node->data + sum(node->next);
  }
}

int LinkedList::recursiveLength(Node* node){
  if (node->next==NULL){
    return 1;
  } else {
    return 1 + recursiveLength(node->next);
  }
}

int LinkedList::getMaximum(Node* node, int max){
  int newMax;
  //printf("MAX: %d\n", max);

  if (node->next==NULL){
    return (node->data > max) ? node->data : max;
  } else {
    newMax = getMaximum(node->next, node->data);
    //printf("NEW MAX: %d\n", newMax);
    if (newMax >= max){
      max = newMax;
    }
    return max;
  }
}

int main(){
  LinkedList list;

  list.insertNode(1);
  list.insertNode(30);
  list.insertNode(2);
  list.insertNode(3);

  printf("The current list is: \n");
  list.displayList();

  printf("The sum of the items in this list is : %d\n", list.sum(list.head));

  printf("The length of this list (found recursively) is: %d\n", list.recursiveLength(list.head));

  printf("The greatest number (found recursively) is: %d\n", list.getMaximum(list.head, list.head->data));
  return 0;
}
