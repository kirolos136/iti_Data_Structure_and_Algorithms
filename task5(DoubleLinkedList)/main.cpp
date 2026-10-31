#include "doubleLinkedList.hpp"
#include<iostream>

int main(){
    LinkedList l;
    l.createLinkedList({0,1,2,3,4,5});
    l.display();
    l.insertAtPos(2, 1000);
    l.display();
    int numberTosearchFor = 1000;
    int index = l.search(numberTosearchFor);
    if(index == -1) std::cout<<"element not found.\n";
    else std::cout << "The number " << numberTosearchFor << " is at index :" << index <<"\n";
    l.insertAtBeginning(-1);
    l.display();
    l.insertAtEnd(100000);
    l.deleteAtPos(3);
    l.deleteLinkedList();
}