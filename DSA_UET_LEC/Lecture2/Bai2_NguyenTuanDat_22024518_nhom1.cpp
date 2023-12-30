#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int count(Node* head){
    int cnt = 0;
    while(head != NULL) {
        head = head->next;
        cnt++;
    }
    return cnt;
}

Node* makeNode(int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

Node* addLast(Node* head, int x){
    Node* newNode = makeNode(x);
    if(head == NULL) head = newNode;
    else{
        Node* tmp = head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    return head;
}

Node* addFirst(Node* head, int x){
    Node* newNode = makeNode(x);
    newNode->next = head;
    head = newNode;
    return head;
}

Node* addMid(Node* head, int pos, int x){
    int n = count(head);

    if(n < pos || n > pos+1) return 0;
    if(pos == 1) addFirst(head, x);

    Node* tmp = head;
    for(int i=0; i <= pos-2; i++) tmp = tmp->next;

    Node* newNode = makeNode(x);
    newNode->next = tmp->next;
    tmp->next = newNode;
    return head;
}

void eraseFirst(Node* &head){
    if(head == NULL) return;
    Node* tmp = head;
    head = head->next;
    delete tmp;
}

void eraseMid(Node* &head, int pos){
    int n = count(head);

    if(pos < 0 || pos > n-1) return;
    if(pos == 0) eraseFirst(head);
    else{
        Node* tmp = head;
        for(int i=0; i <= pos-2; i++) tmp = tmp->next;
        Node* NodeK = tmp->next;
        tmp->next = NodeK->next;
        delete NodeK;
    }
}
 
void printf(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->data;
        tmp = tmp->next;
        if(tmp != NULL) cout << " ";
    }
}

int main(){
    int test; cin >> test;
    Node* head = NULL;

    while(test--){
        string q;
        cin >> q;
        int p, x;
        if(q == "insert"){
            cin >> p >> x;
            if(p==0) head = addLast(head, x);
            else head = addMid(head, p, x);
        }else if(q == "delete"){
            cin >> p;
            eraseMid(head, p);
        }
    }

    printf(head);
    return 0;
}