/*
    Cho một struct Node biểu diễn một node
    của 1 danh sách liên kết đơn như sau:
    -----------------
    struct Node {   |
    int value;      |
    Node* next;     |
    };              |
    -----------------
    KHÔNG sử dụng mảng phụ, KHÔNG đếm số phần tử của danh sách, viết hàm void printReverse(Node* head, int k); 
    in ra k giá trị đầu tiên của danh sách liên kết theo chiều ngược, 
    các giá trị cách nhau bởi dấu cách (k lớn hơn số lượng phần tử thì in ra toàn bộ).

    For example:
    Test Input Result
    printReverse(head, 4);
    5
    4 2 1 3 5
    3 1 2 4
*/

#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *next;
};

void printReverse(Node *head, int k)
{
    if (head == NULL || k <= 0)
    {
        return;
    }

    if (k == 1 || head->next == NULL)
    {
        cout << head->value << " ";
        return;
    }

    printReverse(head->next, k - 1);
    cout << head->value << " ";
}

int main()
{
    Node *head = new Node{4, nullptr};
    Node *node1 = new Node{2, nullptr};
    Node *node2 = new Node{1, nullptr};
    Node *node3 = new Node{3, nullptr};
    Node *node4 = new Node{5, nullptr};

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    printReverse(head, 2);

    // Giải phóng bộ nhớ
    delete node4;
    delete node3;
    delete node2;
    delete node1;
    delete head;

    return 0;
}
