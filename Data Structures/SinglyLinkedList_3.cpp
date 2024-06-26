#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this -> data = data;
        this -> next = nullptr;
    }

    ~Node()
    {
        int value = this -> data;
        if(this -> next != nullptr)
        {
            delete next;
            this -> next = nullptr;
        }

        cout<<"Memory is free for node with data "<< value<<endl;
    }

};

void insertAtHead(Node* &head, int data)
{
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;

}

void insertAtTail(Node* &tail, int data)
{
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

int getLength(Node* head)
{
    Node* temp = head;
    int length = 0;

    while(temp -> next != nullptr)
    {
        length ++;
        temp = temp -> next;
    }

    return length;
}

void insertAtposition(Node* &head, Node* &tail, int position, int data)
{
    int length = getLength(head);

    if(position > length + 2)
    {
        cout<<"position provided is beyond the last element"<<endl<<"Please provide correct posiition";
        return;
    }
    
    if(position == 1)
    {
        insertAtHead(head, data);
        return;
    }
    Node* temp = head;
    int count = 1;

    while(count < position - 1)
    {
        temp = temp -> next;
        count++;
    }

    if(temp -> next == nullptr)
    {
        insertAtTail(tail, data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNodeAtPosition(Node* &head, int position)
{

    if(position == 1)
    {
        Node* temp = head;
        head = head -> next;
        temp ->next = nullptr;
        delete temp;
    }
    else
    {
        Node* current = head;
        Node* previous = nullptr;
        int count = 1;

        while(count < position)
        {
            previous = current;
            current = current -> next;
            count++;
        }

        previous -> next = current -> next;
        current -> next = nullptr;
        delete current;
    }

    

}

void showList(Node* &head)
{
    Node* temp = head;

    while(temp != nullptr)
    {
        cout<<temp -> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main()
{
    Node* obj = new Node(1);
    Node* head = obj;
    Node* tail = obj;

    showList(head);
    insertAtTail(tail, 32);
    insertAtTail(tail, 9);
    showList(head);

    insertAtHead(head, 45);
    showList(head);

    insertAtposition(head, tail, 2, 65);
    insertAtposition(head, tail, 1, 322);

    showList(head);

    // cout<<head -> data<<endl;
    // cout<<tail -> data;

    deleteNodeAtPosition(head, 2);
    showList(head);

    deleteNodeAtPosition(head, 1);
    showList(head);
}
