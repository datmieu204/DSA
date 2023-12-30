#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *makeNode(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

struct Queue
{
    Node *front;
    Node *back;

    void initQueue()
    {
        front = NULL;
        back = NULL;
    }

    bool IsEmpty()
    {
        return front == NULL;
    }

    int size()
    {
        int cnt = 0;
        Node *tmp = front;
        while (tmp != NULL)
        {
            cnt++;
            tmp = tmp->next;
        }
        return cnt;
    }

    int Front()
    {
        if (IsEmpty())
            return -1;
        return front->data;
    }

    void push(int x)
    {
        Node *newNode = makeNode(x);
        if (IsEmpty())
        {
            front = newNode;
            back = newNode;
            return;
        }

        Node *tmp = front;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = newNode;
    }

    void pop()
    {
        if (IsEmpty())
            return;
        Node *tmp = front;
        front = front->next;
        delete tmp;
    }

    void print()
    {
        Node *tmp = front;
        while (tmp != NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.initQueue();
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.Front() << endl;
    q.pop();
    cout << q.Front() << endl;
    cout << q.size() << endl;
    q.print();
    return 0;
}

class node
{
public:
    int val;
    node *next;

    node()
    {
        val = 0;
        next = NULL;
    }

    node(int x)
    {
        val = x;
        next = NULL;
    }
};
//====================================================================================================================
/* QUEUE_LINKED_LIST

class Queue
{
public:
    node *head;

    Queue()
    {
        head = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void enqueue(int x)
    {
        node *nn = new node(x);
        if (isEmpty())
        {
            head = nn;
            return;
        }
        node *tmp = head;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = nn;
    }

    void dequeue()
    {
        if (isEmpty())
            return;
        node *tmp = head;
        head = head->next;
        delete tmp;
    }

    void print()
    {
        node *tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue s;
    s.enqueue(1);
    s.enqueue(2);
    s.enqueue(3);
    s.dequeue();
    s.print();
    return 0;
}


//====================================================================================================================
/* QUEUE_ARRAY
#include<iostream>

using namespace std;

int queue[100000], max_N = 10000;
int size_queue = 0;

int size(){
    return size_queue;
}

bool empty(){
    return size_queue == 0;
}

void push(int x){
    if(size_queue == max_N) return;
    queue[size_queue] = x;
    size_queue++;
}

void pop(){
    if(size_queue == 0) return;
    for(int i = 0; i < size_queue - 1; i++){
        queue[i] = queue[i+1];
    }
    --size_queue;
}

int front(){
    if(size_queue == 0) return -1;
    return queue[0];
}

int main(){
    if(empty()) cout << "Empty" << endl;
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    pop();
    pop();
    if(empty()) cout << "Empty" << endl;
    for(int i=0; i<size(); i++){
        cout << queue[i] << " ";
    }
    cout << front() << endl;
    return 0;
}

*/
