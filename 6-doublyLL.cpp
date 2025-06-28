#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
     ~Node() //DESTRUCTOR
    {
        int value = this->data;
        //memory free
        if(this->next != NULL)
        {
            delete next; //memory free
            this->next = NULL; 
        }
        cout << "Memory is free for node with value " << value << endl;//pta chlne k liye desctruvtor bulaya gya
    }
};
void print(Node* &head)
{
    Node* temp = head; //iterator node to traverse the LL
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int getlength(Node* &head)
{
    int len=0;
    Node *temp = head;
     while(temp!=NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void insertatHead(Node* &head, int d)
{
    if(head == NULL) //insertion in case of empty DLL
    {
        Node* temp = new Node(d);
        head = temp;
    }
    else
    {
        Node* temp = new Node(d);
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
}
void insertatTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}
void insertatPosition(Node* &tail, Node* &head, int position, int d)
{
    if(position==1) //as this logic fails if user enter p=1
    {
        insertatHead(head,d);
        return;
    }
    Node* i = new Node(d);
    Node* temp = head;
    int c=1;
    while(c<position-1)
    {
        temp = temp->next;
        c++;
    }
    if(temp->next == NULL)//we did this because our code would have completely be fine if p=last but our tail wouldnt have be updated
    {
        insertatTail(tail,d);
        return;
    }
    i->next = temp->next;
    temp->next->prev = i;
    temp->next = i;
    i->prev = temp;
}


void deletenode(int position, Node* &head)
{
    if(position ==1) //to delete first node
    {
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else //delete any middle or last node
    {
        Node* curr = head;
        Node* prev = NULL;
        int c=1;
        while(c<position)
        {
            prev = curr;
            curr = curr->next;
            c++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node* node1 = new Node(10); 
    Node* head = node1;
    Node* tail = node1;
    insertatHead(head,8);
    print(head); // 8 10
    insertatTail(tail,7);
    print(head); // 8 10 7
    insertatPosition(tail, head, 4, 21);
    print(head); // 8 10 7 21
    insertatPosition(tail, head, 3, 26);
    print(head); // 8 10 26 7 21

    deletenode(3,head);
    print(head); // 8 10 7 21
    cout<< "head : " << head->data << " tail : " << tail->data;
} 
                // circular waali bhai nhi likha, dekh lena vid for revision
