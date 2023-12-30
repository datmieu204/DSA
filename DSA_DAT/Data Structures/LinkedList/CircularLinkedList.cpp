#include <iostream>
using namespace std;

// UseSingleLinkedList

class node
{
public:
    int data;
    node *next;

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

/*
 * Khi thêm vào đầu hoặc cuối hay giữa thì tự động cập nhật node tail
 * Chú ý các phương thức khác cũng phải cập nhật node tail
 */
class Circular_Linked_List
{
public:
    node *head;
    node *tail;

    Circular_Linked_List()
    {
        head = NULL;
        tail = NULL;
    }

    // check if the list is empty
    bool IsEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }

    int size()
    {
        int cnt = 0;
        if (head == NULL)
            return 0;
        else
        {
            node *tmp = head;
            tmp = tmp->next;
            cnt++;
            while (tmp != head)
            {
                cnt++;
                tmp = tmp->next;
            }
        }
        return cnt;
    }

    node *getLastNode()
    {
        if (head == NULL)
            return head;
        else
        {
            if (tail == NULL)
            {
                tail = head;
                while (tail->next != NULL)
                    tail = tail->next;
            }
            return tail;
        }
        return tail;
    }

    void print()
    {
        if (head == NULL)
        {
            cout << "List Empty!" << endl;
        }
        else
        {
            node *tmp = head;
            cout << tmp->data << " ";
            tmp = tmp->next;
            while (tmp != head)
            {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
        }
    }

    void addLast(int x)
    {
        node *n = new node(x);
        n->next = head;
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            node *last = getLastNode();
            last->next = n;
            tail = n;
        }
    }

    void addFirst(int x)
    {
        node *n = new node(x);
        n->next = head;
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            n->next = head;
            head = n;
            tail->next = head;
        }
    }

    void addMid(int x, int pos)
    {
        if (pos == 1)
            addFirst(x);
        else
        {
            node *n = new node(x);
            n->next = head;

            node *tmp = head;
            int i = 2;
            while (i < pos)
            {
                tmp = tmp->next;
                i++;
            }
            n->next = tmp->next;
            tmp->next = n;

            if (n->next == head)
                tail = n;
        }
    }

    node *searcher(int x)
    {
        int pos = 2;
        node *tmp = head;
        if (tmp->data == x)
        {
            pos = 1;
            return tmp;
        }
        else
        {
            tmp = tmp->next;
            while (tmp != head)
            {
                if (tmp->data == x)
                    break;
                else
                {
                    pos++;
                    tmp = tmp->next;
                }
            }
            return tmp;
        }
    }

    void deleteLast()
    {
        if (head == NULL)
            return;
        else
        {
            node *tmp = head;
            while (tmp->next->next != head)
                tmp = tmp->next;
            node *last = tmp->next;
            tmp->next = head;
            tail = tmp;
            delete last;
            return;
        }
    }

    void deleteFirst()
    {
        if (head == NULL)
            return;
        else
        {
            node *tmp = head;
            head = head->next;
            tail->next = head;
            delete tmp;
            return;
        }
    }

    void deleteMid(int pos)
    {
        if (pos == 1)
        {
            deleteFirst();
            return;
        }
        else
        {
            int i = 1;
            node *tmp = head;
            while (i < pos - 1)
            {
                tmp = tmp->next;
                i++;
            }

            node *tmp1 = tmp->next;
            tmp->next = tmp->next->next;

            if (tmp->next == head)
                tail = tmp;
            delete tmp1;
            return;
        }
    }
};

int main()
{
    Circular_Linked_List l1;
    l1.addLast(2);
    l1.addLast(3);
    l1.addLast(4);
    l1.addLast(5);
    l1.addFirst(6);
    l1.addFirst(8);
    l1.print();
    l1.addMid(9, 3);
    cout << endl;
    l1.print();
    cout << endl;
    cout << l1.size() << endl;
    cout << l1.searcher(9)->data;
    cout << endl;
    l1.deleteLast();
    l1.print();
    cout << endl;
    l1.deleteFirst();
    l1.print();
    cout << endl;
    l1.deleteMid(3);
    l1.print();
    cout << endl;
    l1.deleteMid(4);
    l1.print();
    return 0;
}
