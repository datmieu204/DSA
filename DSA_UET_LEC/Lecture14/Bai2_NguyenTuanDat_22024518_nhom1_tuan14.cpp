#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class linkedList
{
public:
    node *head;

    linkedList()
    {
        head = NULL;
    }

    void addLast(int data)
    {
        node *nn = new node(data);
        if (head == NULL)
        {
            head = nn;
            return;
        }
        node *tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = nn;
    }

    void display()
    {
        node *tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
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

    int smallest()
    {

        int smallest = INT_MAX;

        node *tmp = head;

        while (tmp != NULL)
        {
            if (tmp->data < smallest && tmp->data % 2 != 0)
            {
                smallest = tmp->data;
            }
            tmp = tmp->next;
        }

        if (smallest == INT_MAX)
        {
            return -1;
        }

        return smallest;
    }

    void removeOdd() {
        node *tmp = head; // node hien tai
        node *prev = NULL;// node truoc node hien tai

        while (tmp != NULL) {
            if (tmp->data % 2 != 0) {
                if (prev == NULL) {
                    head = tmp->next;
                    delete tmp;
                    tmp = head;
                } else {
                    prev->next = tmp->next;
                    delete tmp;
                    tmp = prev->next;
                }
            } else {
                prev = tmp;
                tmp = tmp->next;
            }
        }
    }
};

int main()
{
    linkedList ll;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ll.addLast(x);
    }

    ll.removeOdd();
    ll.display();
    cout << ll.smallest() << endl;

    return 0;
}
