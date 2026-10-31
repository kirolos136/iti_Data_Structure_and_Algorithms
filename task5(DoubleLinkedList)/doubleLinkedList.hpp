#include<vector>

class Node{
    public:
    Node* prev;
    int val;
    Node* next;
};


class LinkedList{
    private:
    Node* head;
    Node* tail;

    Node* createnode(int val);
    public:
    LinkedList(const LinkedList& l) = delete;
    LinkedList(LinkedList&& l) = delete;

    LinkedList():head(nullptr),tail(nullptr){};

    void createLinkedList(std::vector<int> v);

    void insertAtBeginning(int val);

    void insertAtEnd(int val);
    
    void insertAtPos(int index,int val);

    int search(int val);

    void display();

    void deleteLinkedList();

    void deleteAtPos(int pos);
};