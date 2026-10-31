#include "doubleLinkedList.hpp"
#include <iostream>

Node *LinkedList::createnode(int val) {
  // create new node
  Node *newNode = new Node();

  // initialize it
  newNode->next = nullptr;
  newNode->prev = nullptr;
  newNode->val = val;

  return newNode;
}

void LinkedList::createLinkedList(std::vector<int> v) {
  if (v.empty())
    return;

  // if there is already a linked list delete it first
  if (head != nullptr) {
    deleteLinkedList();
  }

  head = createnode(v[0]);
  tail = head;
  Node *temp;
  for (int i = 1; i < v.size(); i++) {
    temp = tail;
    tail = createnode(v[i]);
    tail->val = v[i];
    temp->next = tail;
    tail->prev = temp;
  }

  return;
}

void LinkedList::insertAtBeginning(int val) {
  // if no node (or no list at all)
  if (head == nullptr) {
    head = createnode(val);
    tail = head;
    return;
  }

  Node *temp = createnode(val);
  temp->next = head;
  head->prev = temp;

  head = temp;

  return;
}

void LinkedList::insertAtEnd(int val) {
  // if no node (or no list at all, can be checked with either tail or head)
  if (tail == nullptr) {
    head = createnode(val);
    tail = head;
    return;
  }

  Node *temp = createnode(val);
  tail->next = temp;
  temp->prev = tail;

  tail = temp;

  return;
}

int LinkedList::search(int val) {
  int indexFound = -1;

  if (head == nullptr)
    return indexFound;
  Node *temp = head;

  int currIndex = 0;
  while (temp != nullptr) {
    if (temp->val == val) {
      indexFound = currIndex;
      return indexFound;
    }

    temp = temp->next;
    currIndex++;
  }

  return indexFound;
}

void LinkedList::insertAtPos(int index, int val) {
  // if index is out of bounds
  if (index < 0) {
    std::cout << "Position out of bound.\n";
    return;
  }

  // in case there is no node or insertion is at the beginning
  if (index == 0 || head == nullptr) {
    insertAtBeginning(val);
  }

  int count = 1;
  Node *curr = head;
  while (curr != tail) {
    if (count == index) {
      Node *temp = createnode(val);
      temp->next = curr->next;
      temp->prev = curr;
      curr->next->prev = temp;
      curr->next = temp;
      return;
    }

    curr = curr->next;
    count++;
  }

  // in case the index exceed the linkedlist (curr reached tail) -> insert at
  // the end
  insertAtEnd(val);
}

void LinkedList::display() {

  if (head == nullptr) {
    std::cout << "The LinkedList is empty.\n";
    return;
  }

  std::cout << "Current LinkedList: ";
  Node *temp = head;
  while (temp != nullptr) {
    if (temp == tail) {
      std::cout << temp->val;
    } else {
      std::cout << temp->val << " -> ";
    }

    temp = temp->next;
  }

  std::cout<<"\n";
}

void LinkedList::deleteLinkedList() {
  Node *curr = head;

  while (curr != nullptr) {
    Node *temp = curr;
    curr = curr->next;
    delete temp;
  }

  head = nullptr;
  tail = nullptr;
}

void LinkedList::deleteAtPos(int pos) {
  if (head == nullptr) {
    std::cout << "There is no linked list to delete.\n";
    return;
  }

  if (pos < 0) {
    std::cout << "Position out of bound.\n";
    return;
  }

  Node *curr = head;
  int count = 0;

  // reach the required position
  while (curr != nullptr && count < pos) {
    curr = curr->next;
    count++;
  }

  // if the required index is exceeded
  if (curr == nullptr) {
    std::cout << "Position out of bound.\n";
    return;
  }

  // if deleting the head
  if (curr == head) {
    head = head->next;

    if (head != nullptr)
      head->prev = nullptr;
    else
      tail = nullptr;
  } else if (curr == tail) {
    tail = tail->prev;
    tail->next = nullptr;
  } else {
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
  }

  delete curr;
}
