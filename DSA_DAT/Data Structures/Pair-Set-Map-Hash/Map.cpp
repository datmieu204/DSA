#include <iostream>

using namespace std;

struct node
{
    int key;
    int value;
    node *next;

    node()
    {
        next = nullptr;
    }

    node(int _key, int _value)
    {
        key = _key;
        value = _value;
        next = nullptr;
    }
};

struct Map
{
private:
    node *head;

public:
    Map()
    {
        head = new node;
        head->next = nullptr;
    }

    bool empty()
    {
        if (head->next == nullptr)
        {
            return true;
        }
        return false;
    }

    void put(int key, int value)
    {
        node *n = new node(key, value);

        if (empty())
        {
            head->next = n;
        }
        else
        {
            node *it = head;
            while (true)
            {
                if (it->next != nullptr)
                {
                    if (it->next->key > key)
                    {
                        node *tmp = it->next;
                        n->next = tmp;
                        it->next = n;
                        break;
                    }
                    else if (it->next->key == key)
                    {
                        it->next->value = value;
                        break;
                    }
                    else
                    {
                        it = it->next;
                    }
                }
                else
                {
                    it->next = n;
                    break;
                }
            }
        }
    }

    void remove(int key)
    {
        if (empty())
        {
            return;
        }
        else
        {
            node *it = head;
            while (true)
            {
                if (it->next != nullptr)
                {
                    if (it->next->key == key)
                    {
                        node *tmp = it->next;
                        it->next = tmp->next;
                        delete tmp;
                        break;
                    }
                    else
                    {
                        it = it->next;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }

    void get(int key)
    {
        if (empty())
        {
            return;
        }
        else
        {
            node *it = head;
            while (true)
            {
                if (it->next != nullptr)
                {
                    if (it->next->key == key)
                    {
                        cout << it->next->value << endl;
                        break;
                    }
                    else
                    {
                        it = it->next;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }

    void print()
    {
        if (empty())
        {
            cout << "Empty Map!\n";
            return;
        }
        node *it = head->next;
        cout << "Map: ";
        while (it != nullptr)
        {
            cout << "(" << it->key << ", " << it->value  << ")" << " ";
            it = it->next;
        }
        cout << endl;
    }
};

int main()
{
    Map m;
    m.put(1, 2);
    m.put(2, 3);
    m.put(3, 4);
    m.put(4, 5);
    m.put(5, 6);
    m.put(6, 7);
    m.remove(3);
    m.print();
    m.get(2);
    return 0;
}


// MAP: 
// - là ánh xạ 1-1 giữa key và value
// - là tập hợp các cặp key-value
// - key là duy nhất, value có thể trùng nhau
// - key có thể là số nguyên, kí tự, chuỗi, còn value có thể là số nguyên, kí tự, chuỗi, mảng, tập hợp, ...
// - các phần tử trong map được sắp xếp theo thứ tự tăng dần của key
// - các phần tử trong map được lưu trữ dưới dạng cây nhị phân tìm kiếm
// - thao tác trên map: insert, remove, get, print
// - thao tác trên map có độ phức tạp là O(logn)

// MULTIMAP:
// - là ánh xạ 1-n giữa key và value
// - là tập hợp các cặp key-value
// - key có thể trùng nhau
// - key có thể là số nguyên, kí tự, chuỗi, còn value có thể là số nguyên, kí tự, chuỗi, mảng, tập hợp, ...
// - các phần tử trong multimap được sắp xếp theo thứ tự tăng dần của key

// UNORDERED MAP:
// - là ánh xạ 1-1 giữa key và value
// - là tập hợp các cặp key-value
// - key là duy nhất, value có thể trùng nhau
// - key có thể là số nguyên, kí tự, chuỗi, còn value có thể là số nguyên, kí tự, chuỗi, mảng, tập hợp, ...
// - các phần tử trong unordered map được lưu trữ dưới dạng bảng băm
// - thao tác trên unordered map: insert, remove, get, print
// - thao tác trên unordered map có độ phức tạp là O(1)
// - không tự sắp xếp các key
