
#include <bits/stdc++.h>

using namespace std;

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

class st
{
public:
    node *top;

    st()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(int x)
    {
        node *nn = new node(x);
        if (isEmpty())
        {
            top = nn;
            return;
        }
        nn->next = top;
        top = nn;
    }

    void pop()
    {
        if (isEmpty())
            return;
        node *tmp = top;
        top = top->next;
        delete tmp;
    }

    void print()
    {
        node *tmp = top;
        while (tmp != NULL)
        {
            cout << tmp->val << endl;
            tmp = tmp->next;
        }
    }
};

int main()
{
    st s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.print();

    return 0;
}
//=========================================================================
#include <iostream>
#define MAX_SIZE 100

using namespace std;

class st
{
private:
    int a[MAX_SIZE];
    int top;

public:
    st()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX_SIZE - 1;
    }

    void push(int data)
    {
        if (isFull())
            return;
        else
            a[++top] = data;
    }

    void pop()
    {
        if (isEmpty())
            return;
        else
            a[top--];
    }

    void print()
    {
        for (int i = 0; i <= top; i++) cout << a[i] << endl;
        
    }
};

int main()
{
    st stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.pop();
    stack.print();

    return 0;
}

//=========================================================================
// #include <iostream>

// using namespace std;

// struct Node
// {
//     int data;
//     Node *next;
// };

// Node *makeNode(int x)
// {
//     Node *newNode = new Node();
//     newNode->data = x;
//     newNode->next = NULL;
//     return newNode;
// }

// struct Stack
// {
//     Node *top;
//     Node *bottom;

//     void init()
//     {
//         top = NULL;
//         bottom = NULL;
//     }

//     bool IsEmpty()
//     {
//         return top == NULL;
//     }

//     int size()
//     {
//         int cnt = 0;
//         Node *tmp = top;
//         while (tmp != NULL)
//         {
//             cnt++;
//             tmp = tmp->next;
//         }
//         return cnt;
//     }

//     void push(int x)
//     {
//         Node *newNode = makeNode(x);
//         if (IsEmpty())
//         {
//             top = newNode;
//             bottom = newNode;
//             return;
//         }
//         Node *tmp = top;
//         top = newNode;
//         newNode->next = tmp;
//     }

//     void pop()
//     {
//         if (IsEmpty())
//             return;
//         Node *tmp = top;
//         top = top->next;
//         delete tmp;
//     }

//     void print()
//     {
//         Node *tmp = top;
//         while (tmp != NULL)
//         {
//             cout << tmp->data << " ";
//             tmp = tmp->next;
//         }
//         cout << endl;
//     }
// };
//=========================================================================
// int main()
// {
//     Stack st;
//     st.init();
//     st.push(3);
//     st.push(2);
//     st.pop();
//     st.print();
//     return 0;
// }

// void initStack(Stack& st){
//     st.bottom = NULL;
//     st.top = NULL;
// }

// bool IsEmpty(Stack& st){
//     return st.bottom == NULL;
// }

// int size(Stack& st){
//     int cnt = 0;
//     Node* tmp = st.bottom;
//     while(tmp != NULL){
//         cnt++;
//         tmp = tmp->next;
//     }
//     return cnt;
// }

// void push(Stack& st, int x){
//     Node* newNode = makeNode(x);
//     if(IsEmpty(st)) st.bottom = newNode;
//     else{
//         Node* tmp = st.bottom;
//         while(tmp->next != NULL) tmp = tmp->next;
//         tmp->next = newNode;
//     }
// }

// void pop(Stack& st){
//     //TH ngan xep rong
//     if(IsEmpty(st)) return;
//     //TH ngan xep co 1 phan tu
//     Node* tmp = st.bottom;
//     if(tmp->next == NULL){
//         st.bottom = NULL;
//         delete tmp;
//         return;
//     }
//     //TH ngan xep nhieu hon 1 phan tu
//     while(tmp->next->next != NULL) tmp = tmp->next;
//     st.top = tmp->next;
//     tmp->next = NULL;
//     delete st.top;
// }
