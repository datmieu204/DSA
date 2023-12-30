#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;
    // Khoi tao
    node()
    {
        data = 0;
        next = NULL;
    }

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Linked_List
{
public:
    node *head;

    Linked_List()
    {
        head = NULL;
    }

    int size()
    {
        int cnt = 0;
        node *tmp = head;
        while (tmp != NULL)
        {
            cnt++;
            tmp = tmp->next;
        }
        return cnt;
    }

    void print()
    {
        node *tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }

    node *getLastNode()
    {
        if (isEmpty())
            return NULL;
        node *tmp = head;
        while (tmp->next != NULL)
            tmp = tmp->next;
        return tmp;
    }

    void append(int val)
    {
        node *newNode = new node(val);
        if (isEmpty())
        {
            head = newNode;
            return;
        }
        node *lastNode = getLastNode();
        lastNode->next = newNode;
    }

    void merge(Linked_List list_two)
    {
        node *tmp = getLastNode();
        tmp->next = list_two.head;
    }

    bool search(int num)
    {
        node *tmp = head;
        while (tmp != NULL)
        {
            if (tmp->data == num)
                return true;
            tmp = tmp->next;
        }
        return false;
    }

    void addFirst(int x)
    {
        node *newNode = new node(x);
        newNode->next = head;
        head = newNode;
    }

    void addLast(int x)
    {
        node *n = new node(x);
        if (head == NULL)
        {
            head = n;
            return;
        }
        node *tmp = head;
        while (tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = n;
    }

    void addMid(int x, int pos)
    {
        int n = size();
        if (pos < 1 || pos > n + 1)
            return;
        if (pos == 1)
        {
            addFirst(x);
            return;
        }

        node *tmp = head;
        for (int i = 1; i <= pos - 2; i++)
            tmp = tmp->next;
        // tmp = pos - 1
        node *newNode = new node(x);
        newNode->next = tmp->next;
        tmp->next = newNode;
    }

    void deleteFirst()
    {
        if (head == NULL)
            return;
        // cho node head luu node 2, giai phong node dau
        node *tmp = head;
        head = head->next;
        delete tmp;
    }

    void deleteMid(int pos)
    {
        int n = size();
        if (pos < 1 || pos > n + 1)
            return;
        if (pos == 1)
            deleteFirst();
        else
        {
            node *tmp = head;
            for (int i = 1; i <= pos - 2; i++)
                tmp = tmp->next;
            // tmp = 1
            node *nodeK = tmp->next;
            tmp->next = nodeK->next;
            delete nodeK;
        }
    }

    void deleteLast()
    {
        if (head == NULL)
            return;
        node *tmp = head;
        // TH co 1 node
        while (tmp->next == NULL)
        {
            head = NULL;
            delete tmp;
            return;
        }
        // Th nhieu hon 1 node
        while (tmp->next->next != NULL)
            tmp = tmp->next;
        node *nodeLast = tmp->next;
        tmp->next = NULL;
        delete nodeLast;
    }

    void reverse()
    {
        if (isEmpty())
            return;

        node *current_node = head;
        node *prev_node = NULL;
        node *next_node = NULL;

        while (current_node != NULL)
        {
            next_node = current_node->next;
            current_node->next = prev_node;
            prev_node = current_node;
            current_node = next_node;
        }

        head = prev_node;
    }

    void sort()
    {
        for (node *i = head; i != NULL; i = i->next)
        {
            node *minNode = i;
            for (node *j = i->next; j != NULL; j = j->next)
            {
                if (minNode->data > j->data)
                    minNode = j;
            }
            int tmp = minNode->data;
            minNode->data = i->data;
            i->data = tmp;
        }
    }
};

// void toDelete(node* &head, int val){
//     //TH1: list rong
//     if(head == NULL) return;
//     //TH2: list co 1 phan tu
//     if(head->next == NULL){
//         deleteFirst(head);
//         return;
//     }
//     //TH3:
//     node* tmp = head;
//     while(tmp->next->data == val){
//         tmp = tmp->next;
//     }
//     node* todelete = tmp->next;
//     tmp->next = todelete->next;
//     delete todelete;
// }

// dao nguoc DSLK = de quy
// node *reverse_recursive(node *&head)
// {
//     if (head == NULL || head->next == NULL)
//         return head;
//     node *newhead = reverse_recursive(head->next);
//     head->next->next = head;
//     head->next = NULL;
//     return newhead;
// }

// sap xep data, khong thay doi ket noi
// void sort(node *&head)
// {
//     for (node *i = head; i != NULL; i = i->next)
//     {
//         node *minnode = i;
//         for (node *j = i->next; j != NULL; j = j->next)
//         {
//             if (minnode->data > j->data)
//                 minnode = j;
//         }
//         int tmp = minnode->data;
//         minnode->data = i->data;
//         i->data = tmp;
//     }
// }

int main()
{
    Linked_List l1;
    l1.addFirst(8);
    l1.addLast(4);
    l1.addLast(3);
    l1.print();
    cout << endl;
    l1.sort();
    l1.print();
    return 0;
}