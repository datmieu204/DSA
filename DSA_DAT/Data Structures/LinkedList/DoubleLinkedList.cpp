#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class DoubleLinkedList
{
    node* head;
    node* tail;
public:
    DoubleLinkedList(){
        head = NULL;
        tail = NULL;
    }

    bool empty(){
        if(head == NULL) return true;
        return false;
    }

    int size(){
        int cnt = 0;
        node* tmp = head;
        while(tmp != NULL){
            cnt++;
            tmp = tmp->next;
        }
        return cnt;
    }

    void print(){
        node* tmp = head;
        while(tmp != NULL){
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }   

    void addFirst(int x){
        node* new_node = new node(x);
        new_node->next = head;
        if(head != NULL)
            head->prev = new_node;
        head = new_node;
    }

    void addMid(int x, int pos){
        int n = size();
        if(pos < 1 || pos > n + 1)
            return;

        if(pos == 1){
            addFirst(x);
            return;
        }

        node* tmp = head;
        for(int i = 1; i <= pos - 1; i++)
            tmp = tmp->next;

        node* new_node = new node(x);
        new_node->next = tmp;
        tmp->prev->next = new_node;
        new_node->prev = tmp->prev;
        tmp->prev = new_node;
    }

    void addLast(int x){
        node* nn = new node(x);
        if(head == NULL){
            head = nn;
            return;
        }
        node* tmp = head;
        while(tmp->next != NULL) tmp = tmp->next;
        tmp->next = nn;
        nn->prev = tmp;
    }

    void deleteFirst(){

    }

};




// void addMid(node *&head, int x, int pos)
// {
//     int n = size(head);
//     if (pos < 1 || pos > n + 1)
//         return;
//     if (pos == 1)
//     {
//         addFirst(head, x);
//         return;
//     }
//     node *tmp = head;
//     for (int i = 1; i <= pos - 1; i++)
//         tmp = tmp->next;

//     node *new_node = new node(x);
//     new_node->next = tmp;
//     tmp->prev->next = new_node;
//     new_node->prev = tmp->prev;
//     tmp->prev = new_node;
// }

// void addLast(node *&head, int x)
// {
//     node *new_node = new node(x);
//     if (head == NULL)
//     {
//         head = new_node;
//         return;
//     }
//     node *tmp = head;
//     while (tmp->next != NULL)
//         tmp = tmp->next;
//     tmp->next = new_node;
//     new_node->prev = tmp;
// }

// void deleteFirst()
// {
//     int x;
// }

int main()
{
    DoubleLinkedList dbl;
    dbl.addFirst(1);
    dbl.addLast(2);
    dbl.addLast(3);
    dbl.print();
    
    return 0;
}