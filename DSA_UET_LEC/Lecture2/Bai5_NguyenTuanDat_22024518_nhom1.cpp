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

struct Stack{
    Node* bottom;
    Node* top;
};

void makeStack(Stack& st){
    st.top = NULL;
    st.bottom= NULL;
}

bool IsEmpty(Stack& st){
    return st.bottom == NULL;
}

void push(Stack& st, int x){
    Node* newNode = makeNode(x);
    if(IsEmpty(st)) st.bottom = newNode;
    else{
        Node* tmp = st.bottom;
        while(tmp->next != NULL) tmp = tmp->next;
        tmp->next = newNode;
    }
}

void pop(Stack& st){
    //TH ngan xep rong
    if(IsEmpty(st)) return;
    //TH co 1 Node
    Node* tmp = st.bottom;
    if(tmp->next == NULL){
        st.bottom = NULL;
        delete tmp;
        return;
    }
    //TH > 1 Node
    while(tmp->next->next != NULL) tmp = tmp->next;
    st.top = tmp->next;
    tmp->next = NULL;
    delete st.top;
}

void printf(Stack& st){
    Node* tmp = st.bottom;
    while(tmp != NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main(){
    int n; cin >> n;
    Stack st;

    while(n--){
        string q; 
        cin >> q;
        if(q == "push"){
            int x; 
            cin >> x;
            push(st, x);
        }else if(q == "pop"){
            if(!IsEmpty(st)) pop(st);
        }
    }
    
    printf(st);
    return 0;
}