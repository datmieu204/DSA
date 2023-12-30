#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

Node* makeNode(int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printf(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* addLast(Node* head, int x){
    Node* newNode = makeNode(x);
    if(head == NULL){
        head = newNode;
        return head;      
    }   
    Node* tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
    return head;
}

int count_triplets(Node* head, int n){
    int cnt = 0;
    if(n < 3) return 0;
    else if(n == 3){
        Node* tmp = head;
        tmp = tmp->next;

        int val1 = tmp->next->data;
        int val2 = tmp->data;
        int val3 = tmp->prev->data;
        int sum = val1 + val2 + val3;

        if(sum == 0) cnt++;
    }else{
        for(int i=1; i<= n-2; i++){
            Node* tmp = head;
            for(int j = 0; j < i; j++) tmp = tmp->next;
            
            int val1 = tmp->next->data;
            int val2 = tmp->data;
            int val3 = tmp->prev->data;
            int sum = val1 + val2 + val3;
            
            if(sum == 0) cnt++;
        }
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;
    Node* head = NULL;

    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        head = addLast(head, x);
    }
    int dem = count_triplets(head, n);
    cout << dem << endl; 
    
    return 0;
}