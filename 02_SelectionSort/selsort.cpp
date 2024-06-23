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

  int getLength();
  
  int getData(int);

  LinkedList selSort();
};

int LinkedList::getLength(){
  Node* tempNode = head;
  int length = 0;

  while (tempNode != NULL){
    length++;
    tempNode = tempNode->next;
  } 
  return length;
}

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

  int length = getLength();

  if (nodePos >= length){
    std::cout << "The index is too high for the given list length.\n";
    delete tempNode;
    return;
  } else if (nodePos < 0) {
    std::cout << "Invalid index.\n";
    delete tempNode;
    return;
  } else if (nodePos == 0){
    head = head->next;
    return;
  } else if (nodePos == 1){
    temp2 = head;
    tempNode = tempNode->next;
    temp2->next = tempNode->next;
  } else {
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
  return;
}

LinkedList LinkedList::selSort(){
  LinkedList tempList;
  Node* tempNode;
  int length = getLength();
  int smallest, smallestIndex;

  if (head == nullptr){
    return tempList;
  } else if (head == nullptr){
    tempList.insertNode(head->data);
    return tempList;
  }

  for (int i = 0; i < length; i++){
    //find the smallest item / index
    tempNode = head;
    smallest = tempNode->data;
    smallestIndex = i;
    for (int j = i+1; j < length; j++){
      tempNode = tempNode->next;
      if (tempNode->data <= smallest){
        smallest = tempNode->data;
        smallestIndex = j;
      }
    }
    //printf("SMALLEST: %d, SMALLEST INDEX: %d\n", smallest, smallestIndex);
    tempList.insertNode(smallest);
    deleteNode(smallestIndex-i);
    //tempList.displayList();
  }
  
  return tempList;
}

int main(){
  LinkedList list, list2;

  list.insertNode(100);
  list.insertNode(23);
  list.insertNode(391);
  list.insertNode(92);
  list.insertNode(81);
  list.insertNode(53);

  printf("The unordered list is: \n");
  list.displayList();

  list2 = list.selSort();
  //list.deleteNode(1);

  printf("The sorted list is: \n");
  list2.displayList();

  return 0;
}
