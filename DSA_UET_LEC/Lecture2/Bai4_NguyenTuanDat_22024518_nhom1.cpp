#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* makeNode(int x){
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

struct Queue{
    Node* front;
    Node* end;
};

void makeQueue(Queue& q){
    q.front = NULL;
    q.end = NULL;
}

bool IsEmpty(Queue q){
    return q.front == NULL;
}

void enqueue(Queue& q, int x){
    Node* newNode = makeNode(x);

    if(q.front == NULL) q.front = newNode;
    else{
        Node* tmp = q.front;
        while(tmp->next != NULL) tmp = tmp->next;
        tmp->next = newNode;
    }
}

void dequeue(Queue& q){
    if(q.front == NULL) return;
    Node* tmp = q.front;
    q.front = q.front->next;
    delete tmp;
}

void print(Queue &q){
    Node* tmp = q.front;
    while(tmp != NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main(){
    int n; cin >> n;
    Queue q;
    Queue tmp;
    while(n--){
        string s;
        cin >> s;
        int x;
        if(s == "enqueue"){
            cin >> x;
            enqueue(q, x);
        }else if(s == "dequeue"){
            if(!IsEmpty(q)) dequeue(q);
        }
    }
    while(!IsEmpty(q)){
        enqueue(tmp, q.front->data);
        dequeue(q);
    }
    while(!IsEmpty(tmp)){
        cout << tmp.front->data << " ";
        dequeue(tmp);
    }
    return 0;
}