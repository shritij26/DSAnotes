#include <iostream>
using namespace std;

class Node
{
    public:
    int data; //first part of node storing value
    Node* next; //second part of node storing address of next node
    Node(int data)
    {
        this->data = data; 
        this->next = NULL; //this refers to data member of current class
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

}; //this ; OMGG have given so many prblm to me once



void InsertatHead (Node* &head, int d) //d valued node is insert at start(before head)
{
    Node* temp = new Node(d); //node created which we will add
    temp-> next = head; //pointer of new node points to the head node
    head = temp; //head shifted to the new node added
} 
void InsertatTail (Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail-> next = temp;
    // temp-> next = NULL; //this line is not necessary as tail = temp already does that
    tail = temp;
}
void Insertatposition(Node* &tail,Node* &head,int p, int d)// insert element after p position
{
    if(p==1) //as this logic fails if user enter p=1
    {
        InsertatHead(head,d);
        return;
    }
    Node* i = new Node(d);
    Node* temp = head;
    int c=1;
    while(c<p-1)
    {
        temp = temp->next;
        c++;
    }
    if(temp->next == NULL)//we did this because our code would have compltely be fine if p=last but our tail wouldnt have be updated
    {
        InsertatTail(tail,d);
        return;
    }
    i->next = temp->next;
    temp->next = i;
}



void deletenode(int position, Node* &head)
{
    if(position ==1) //to delete first node
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL; //free that deleted node
        delete temp;//memory free start node
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
        prev->next = curr->next;
        curr->next = NULL; //free that deleted node
        delete curr;
    }
}



Node* reverse(Node* &head, Node* &tail) //reverse the linked list
{
    tail = head; //update tail to the current head
    if(head == NULL || head->next == NULL) //if LL is empty or has only one node
        return head; //return the same LL
    Node *prev = NULL; 
    Node *curr = head; 
    Node *forward = NULL;
    while(curr != NULL) //traversing the LL
    {
        forward = curr->next; //store next node
        curr->next = prev; //reverse the link
        prev = curr; //move prev to current node
        curr = forward; //move current to next node
    }
    head = prev; //update head to the new head which is prev
    return prev; //prev will be the new head of the reversed LL
}
void reverseRECURSION(Node* &head, Node* curr, Node* prev)
{
    if(curr == NULL)
    {
        head = prev;
        return;
    }
    Node* forward = curr->next;
    reverseRECURSION(head, forward, curr);
    curr->next = prev; 
}



void print(Node* &head)
{ //method to traverse an LL
    Node* temp = head; //iterator node to traverse the LL
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main()
{
    Node* node1= new Node(5); //node creation
    /* cout<<node1->data<<endl; //gives garbge value if u havn't initialized before */
    Node* head = node1; //head pointing ot node1
    Node* tail = node1; //tail pointing ot node1......as inially it has single node so head and yail point to same
    InsertatHead (head,8); //adding a node of data 8 to that node of data 5
    InsertatTail(tail,12);
    print(head); // 8 5 12
    Insertatposition(tail,head, 2, 4);
    print(head); // 8 4 5 12
    Insertatposition(tail,head, 4, 14);
    print(head); // 8 4 5 14 12
    deletenode(3,head);
    print(head); // 8 4 14 12
    reverse(head, tail);
    print(head); // 12 14 4 8
    cout<< "head : " << head->data << " tail : " << tail->data;
}