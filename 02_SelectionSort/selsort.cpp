#include <stdio.h>
#include <iostream>

class Node {
public:
  int data;
  Node* next;

  Node(){
    data = 0;
    next = NULL;
  }

  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};

class LinkedList {
  Node* head;
public:
  LinkedList(){
    head = NULL;
  };

  void insertNode(int);

  void deleteNode(int);

  void displayList();
};

void LinkedList::insertNode(int data){
  Node* newNode = new Node(data);

  if (head == NULL){
    head = newNode;
    return;
  }

  Node* tempNode = head;

  while (tempNode->next != NULL){
    tempNode = tempNode->next;
  }

  tempNode->next = newNode;
  return;
}

void LinkedList::deleteNode(int nodePos){
  //Check if list is empty
  if (head == NULL){
    std::cout << "The list is empty. Cannot delete an item.\n";
    return;
  }

  Node* tempNode = head;
  Node* temp2 = NULL;

  int length = 0;

  //Check length to see if pos <= length

  while (tempNode->next != NULL){
    length++;
    tempNode = tempNode->next;
  }
  length++;

  if (nodePos >= length){
    std::cout << "The index is too high for the given list length.\n";
    return;
  } else if (nodePos < 0) {
    std::cout << "Invalid index.\n";
    return;
  } else {
    tempNode = head;
    while (nodePos-- > 1){
      temp2 = tempNode;
      tempNode = tempNode->next;
    }
    temp2->next = tempNode->next;
    delete tempNode;
  }
}

void LinkedList::displayList(){
  Node* tempNode = head;
  while (tempNode->next!=NULL){
    printf("%d\n", tempNode->data);
    tempNode = tempNode->next;
  }
  printf("%d\n", tempNode->data);
  return;
}

int main(){
  LinkedList list;

  list.insertNode(1);
  list.insertNode(2);
  list.insertNode(3);
  list.insertNode(4);

  printf("The list is: \n");
  list.displayList();

  list.deleteNode(2);

  printf("The list is: \n");
  list.displayList();

  return 0;
}
