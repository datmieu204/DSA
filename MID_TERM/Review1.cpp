/*
1) A program P reads in 500 integers in the range [0..100] exepresenting the scores of 500 students.
It then prints the frequency of each score above 50. What would be the best way for P to store the frequencies? (GATE CS 2005)
    A.An array of 50 numbers
    B.An array of 100 numbers
    C.An array of 500 numbers
    D.A dynamically allocated array of 550 numbers
=> A

2)Which of the following correctly declares an array?
    A.int geeks[20];
    B.int geeks;
    C.geeks{20};
    D.array geeks[20
=> A

3)Consider a two dimensional array A[20][10]. Assume 4 words per memory cell, the base address of array A is 100, elements are stored in row-major order and first element is A[0][0]. What is the address of A[11][5] ?
    A.560
    B.460
    C.570
    D.575
=> A

4)What is the correct way to initialize values in an array?
    a) my_array [5] = (5,3,4,2,7);
    b) my_array [5] = {5;3;4;2;7};
    c) my_array [5] = {5,3,4,2,7};
=> C

5)What is the most efficient way to assign or print out arrays?
    a) loops
    b) functions
    c) pointers
=> A

6)Can an entire array be printed out at once?
    a) yes
    b) no
=> B

7)In a stack, if a user tries to remove an element from empty stack it is called _________
    a) Underflow
    b) Empty collection
    c) Overflow
    d) Garbage Collection
=> A

8)Pushing an element into stack already having five elements and stack size of 5, then stack becomes
    a) Overflow
    b) Crash
    c) Underflow
    d) User flow
=> A

9)Consider the usual algorithm for determining whether a sequence of parentheses is balanced.
The maximum number of parentheses that appear on the stack AT ANY ONE TIME when the algorithm analyzes: (()(())(())) are:
    a) 1
    b) 2
    c) 3
    d) 4 or more
=> C

10)What is the value of the postfix expression 6 3 2 4 + – *:
    a) 1
    b) 40
    c) 74
    d) -18
=> D

//=========================================================================================================================================

TÌM VỊ  TRÍ TƯƠNG ĐỐI GIỮA 2 ĐƯỜNG THẲNG => TÍNH DET = 0 -> VÔ SỐ NGHIỆM hoặc VÔ NGHIỆM, DET != 0 -> 1 NGHIỆM

class Point{
public:
    double x, y;

    Point(double x_ = 0, double y_ = 0){
        x = x_;
        y = y_;
    }

    void printf(){
        cout << x << " " << y << endl;
    }
};

double Det_x_, Det_y_, Det_;

class Line{
public:
    Point p1, p2;

    Line(const Point& p1_, const Point& p2_){
        p1 = p1_;
        p2 = p2_;
    }

    static bool checkConditionLine(const Line& l1, const Line& l2){
        double a1 = l1.p1.y - l1.p2.y;
        double b1 = l1.p2.x - l1.p1.x;
        double c1 = l1.p2.x*l1.p1.y - l1.p1.x*l1.p2.y;

        double a2 = l2.p1.y - l2.p2.y;
        double b2 = l2.p2.x - l2.p1.x;
        double c2 = l2.p2.x*l2.p1.y - l2.p1.x*l2.p2.y;

        double Det = a1*b2 - a2*b1;
        double Det_x = c1*b2 - c2*b1;
        double Det_y = a1*c2 - a2*c1;

        Det_ = Det;
        Det_x_ = Det_x;
        Det_y_ = Det_y;

        return Det == 0;
    }

    static Point checkTwoLine(const Line& l1, const Line& l2){
        if(checkConditionLine(l1, l2)){
            if(Det_x_ == 0 && Det_y_ == 0){
                return Point(0, 0); //MANY
            }else{
                return Point(1, 1); //NO
            }
        }else{
            double x = Det_x_/Det_;
            double y = Det_y_/Det_;
            return Point(x, y);
        }
    }
};

/=====================================================================================================================================
ĐẾM CẶP SỐ GIỐNG NHAU TRONG MẢNG

int main(){
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    int cnt = 0;

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(a[i] == a[j]) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

//=====================================================================================================================================
//LinkedList

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
//==================================================================================================
//Liên kết đôi
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
//=====================================================================================================
//Liên kết vòng

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

// /*
//  * Khi thêm vào đầu hoặc cuối hay giữa thì tự động cập nhật node tail
//  * Chú ý các phương thức khác cũng phải cập nhật node tail
//  
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

//==============================================================================================
//SET
#include <iostream>
#include <vector>

using namespace std;

// dung tu tuong cua merge
struct node
{
    int value;
    node *next;

    node()
    {
        next = NULL;
    }

    node(int value)
    {
        this->value = value;
        next = NULL;
    }
};

struct Set
{
private:
    node *head; // bien cam canh
public:
    Set()
    {
        head = new node;
        head->next = NULL;
    }

    bool empty()
    {
        if (head->next == NULL)
            return true;
        return false;
    }

    // chèn giá trị x vào Set khi x chưa xuất hiện.
    // duyệt list đến khi nào x nhỏ hơn 1 giá trị nào đó.
    void insert(int x)
    {
        node *n = new node(x);
        if (empty())
            head->next = n;
        else
        {
            node *it = head;
            while (true)
            {
                if (it->next != NULL)
                {
                    if (it->next->value > x)
                    {
                        node *tmp = it->next;
                        n->next = tmp;
                        it->next = n;
                        return;
                    }
                    else if (it->next->value == x)
                    {
                        return; // khi đã tồn tại giá trị x
                    }
                    else
                    {
                        it = it->next;
                    }
                }
                else
                {
                    // khi set chưa có giá trị nào hoặc đã duyệt hết set
                    // khi đó có 2th là node ở đầu hoặc ở cuối
                    it->next = n;
                    return;
                }
            }
        }
    }

    void erase(int x)
    {
        node *it = head;
        while (it->next != NULL)
        {
            if (it->next->value == x)
            {
                node *tmp = it->next->next;
                delete it->next;
                it->next = tmp;
                return;
            }
            else
            {
                it = it->next;
            }
        }
    }

    void print()
    {
        if (empty())
        {
            cout << "Empty Set!\n";
            return;
        }
        node *it = head->next;
        cout << "Set: ";
        while (it != nullptr)
        {
            cout << it->value << " ";
            it = it->next;
        }
        cout << endl;
    }

    // Hợp 2 tập hợp, giống Merge 2 danh sách liên kết
    Set Union(Set &s)
    {
        Set res;
        node *it1 = head->next; // con trỏ trỏ đến phần tử đầu danh sách 1
        node *it2 = s.head->next;// con trỏ trỏ đến phần tử đầu danh sách 2

        while (it1 != NULL && it2 != NULL)
        {
            if (it1->value < it2->value)
            {
                res.insert(it1->value);
                it1 = it1->next;
            }
            else if (it1->value > it2->value)
            {
                res.insert(it2->value);
                it2 = it2->next;
            }
            else
            {
                res.insert(it1->value);
                it1 = it1->next;
                it2 = it2->next;
            }
        }

        while (it1 != NULL)
        {
            res.insert(it1->value);
            it1 = it1->next;
        }

        while (it2 != NULL)
        {
            res.insert(it2->value);
            it2 = it2->next;
        }
        return res;
    }

    // Giao 2 tập hợp, chỉ lấy những phần tử giống nhau( = nhau)
    Set Intersection(Set &s)
    {
        Set res;
        node *it1 = head->next;
        node *it2 = s.head->next;

        while (it1 != NULL && it2 != NULL)
        {
            if (it1->value < it2->value)
            {
                it1 = it1->next;
            }
            else if (it1->value > it2->value)
            {
                it2 = it2->next;
            }
            else
            {
                res.insert(it1->value);
                it1 = it1->next;
                it2 = it2->next;
            }
        }
        return res;
    }

    // Hiệu 2 tập hợp
    Set Difference(Set &s)
    {
        Set res;
        node *it1 = head->next;
        node *it2 = s.head->next;

        while (it1 != NULL && it2 != NULL)
        {
            if (it1->value < it2->value)
            {
                res.insert(it1->value);
                it1 = it1->next;
            }
            else if (it1->value > it2->value)
            {
                it2 = it2->next;
            }
            else
            {
                it1 = it1->next;
                it2 = it2->next;
            }
        }

        while (it1 != NULL)
        {
            res.insert(it1->value);
            it1 = it1->next;
        }
        return res;
    }
};

int main()
{
    vector<int> value = {1, 5, 8, 11, 6, 6, 8};
    vector<int> value2 = {1, 2, 3, 6, 7, 8, 8, 10};
    Set s1;
    for (int i : value)
    {
        s1.insert(i);
    }
    s1.print();
    Set s2;
    for (int i : value2)
    {
        s2.insert(i);
    }
    s2.print();
    Set s3 = s2.Difference(s1);
    s3.print();
}

// /*
// #include <iostream>
// #include <set>
// #include <unordered_set>

// using namespace std;

// /*
//     SET:- tập hợp mà không cho phép có 2 phần tử giống nhau,
//         tất cả phải đều là riêng biệt
//         - Độ phức tạp: O(logn)
//         - Tự sắp xếp tăng dần
//         - Không thể truy cập trực tiếp vào phần tử
//         - Không thể thay đổi giá trị phần tử
//         - Có thể xóa phần tử = erase(id)
//         - Có thể thêm phần tử = insert(x)
//         - Có thể tìm kiếm phần tử = find(x)
//         - Có thể đếm số lượng phần tử = count(key) trả về số lần xuất hiện khóa key
//         - Có thể xóa tất cả phần tử = clear()
//         - Có thể kiểm tra rỗng = empty()
//         - Có thể lấy kích thước = size()
//         - Có thể duyệt = for(auto i : s) cout << i << " ";
//         - Có thể duyệt = for(auto i = s.begin(); i != s.end(); i++) cout << *i << " ";
//         - Có thể duyệt = for(auto i = s.rbegin(); i != s.rend(); i++) cout << *i << " ";
//         - Có thể duyệt = for(auto i = s.cbegin(); i != s.cend(); i++) cout << *i << " ";
//         - Có thể duyệt = for(auto i = s.crbegin(); i != s.crend(); i++) cout << *i << " ";
//         - Có thể duyệt = for(auto i = s.lower_bound(x); i != s.upper_bound(x); i++) cout << *i << " ";
//         - Có thể duyệt = for(auto i = s.find(x); i != s.end(); i++) cout << *i << " ";
//         - Có thể duyệt = for(auto i = s.cfind(x); i != s.cend(); i++) cout << *i << " ";
//         - Có thể duyệt = for(auto i = s.rfind(x); i != s.rend(); i++) cout << *i << " ";
//    MULTISET: 
//         - tập hợp có thể có 2 phần tử giống nhau
//         - Độ phức tạp: O(logn)
//         - Tự sắp xếp tăng dần
//    UNORDERED_SET:
//         - tập hợp mà không cho phép có 2 phần tử giống nhau,
//         tất cả phải đều là riêng biệt
//         - Độ phức tạp: O(1)
//         - Không tự sắp xếp
// 

// int main()
// {
//     // khai báo
//     // set<data_type1, data_type2> s;
//     set<int> s;

//     // thêm phần tử vào set
//     // s.insert(value . . .);
//     s.insert(1);
//     s.insert(3);
//     s.insert(5);

//     // đếm số lượng phần tử
//     s.size();

//     // con trỏ trỏ đến phần tử đầu và phần tử cuối
//     // s.begin() và s.rbegin()
//     cout << *s.begin() << " " << *s.rbegin() << endl;

//     // tìm kiếm
//     // find(value) hoặc count(value)
//     if (s.count(5) != 0)
//         cout << "Found\n";
//     if (s.find(5) != s.end())
//         cout << "found\n";

//     // Hàm xóa
//     // s.erase(value) hoặc s.erase(s.find(value))
//     s.erase
// }
//===========================================================================================

//MAP
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
//==============================================================================================================================

//HashLinearProbing

#include <iostream>

using namespace std;

class Hash
{
    int size = 0;
    int slots;
    int *table;

public:
    Hash(int slots)
    {
        this->slots = slots;
        table = new int[slots];
        for (int i = 0; i < slots; i++)
        {
            table[i] = -1e9 + 1;
        }
    }

    unsigned int hashFunction(int key)
    {
        return (2 * key + 5) % slots;
    }

    void insertItem(int key)
    {
        int index = hashFunction(key);
        if (size == slots)
        {
            cout << "Hash table is full" << endl;
            return;
        }
        while (table[index] != -1e9 + 1)
        {
            index = (index + 1) % slots;
        }
        table[index] = key;
        size++;
    }

    void deleteItem(int key)
    {
        int index = hashFunction(key);
        while (table[index] != key)
        {
            index = (index + 1) % slots;
        }
        table[index] = -1e9 + 1;
        size--;
    }

    void searchItem(int key)
    {
        int index = hashFunction(key);
        while (table[index] != key)
        {
            index = (index + 1) % slots;
        }
        cout << "Found " << key << " at index " << index << endl;
    }

    void displayHash()
    {
        for (int i = 0; i < slots; i++)
        {
            cout << i;
            if (table[i] != -1e9 + 1)
            {
                cout << "-->" << table[i];
            }
            cout << endl;
        }
    }
};

int main()
{
    int arr[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};
    int n = 11;
    Hash h(11);
    for (int i = 0; i < n; i++)
    {
        h.insertItem(arr[i]);
    }
    h.displayHash();
    return 0;
}
//===========================================================================================================

//Hash Chaining
#include <iostream>
#include <list>
#include<vector>

using namespace std;

class Hash
{
    int BUCKET;
    list<int> *table; // Table Hash duoc luu boi 1 list linkedlist

public:
    Hash(int V)
    {
        this->BUCKET = V;
        table = new list<int>[BUCKET];
    }

    int hashFunction(int x)
    {
        return (x + 3) % 17;
    }

    void insertItem(int key)
    {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteItem(int key)
    {
        int index = hashFunction(key);
        list<int>::iterator i;
        for (i = table[index].begin(); i != table[index].end(); i++)
        {
            if (*i == key)
            {
                table[index].erase(i);
                break;
            }
        }
    }

    void displayHash()
    {
        for (int i = 0; i < BUCKET; i++)
        {
            cout << i;
            for (auto x : table[i])
            {
                cout << "-->" << x;
            }
            cout << endl;
        }
    }
};

int main()
{
    int a[] = {1, 3, 18, 8, 23, 35, 11, 36, 20, 16};
    int n = 10;
    Hash h(17);
    for (int i = 0; i < n; i++)
    {
        h.insertItem(a[i]);
    }

    // h.deleteItem(12);
    h.displayHash();
    return 0;
}
//==================================================================================================================

//STACK
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *makeNode(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

struct Stack
{
    Node *top;
    Node *bottom;

    void init()
    {
        top = NULL;
        bottom = NULL;
    }

    bool IsEmpty()
    {
        return top == NULL;
    }

    int size()
    {
        int cnt = 0;
        Node *tmp = top;
        while (tmp != NULL)
        {
            cnt++;
            tmp = tmp->next;
        }
        return cnt;
    }

    void push(int x)
    {
        Node *newNode = makeNode(x);
        if (IsEmpty())
        {
            top = newNode;
            bottom = newNode;
            return;
        }
        Node *tmp = top;
        top = newNode;
        newNode->next = tmp;
    }

    void pop()
    {
        if (IsEmpty())
            return;
        Node *tmp = top;
        top = top->next;
        delete tmp;
    }

    void print()
    {
        Node *tmp = top;
        while (tmp != NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack st;
    st.init();
    st.push(3);
    st.push(2);
    st.pop();
    st.print();
    return 0;
}

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
//===========================================================================================================================

//QUEUE
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *makeNode(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

struct Queue
{
    Node *front;
    Node *back;

    void initQueue()
    {
        front = NULL;
        back = NULL;
    }

    bool IsEmpty()
    {
        return front == NULL;
    }

    int size()
    {
        int cnt = 0;
        Node *tmp = front;
        while (tmp != NULL)
        {
            cnt++;
            tmp = tmp->next;
        }
        return cnt;
    }

    int Front()
    {
        if (IsEmpty())
            return -1;
        return front->data;
    }

    void push(int x)
    {
        Node *newNode = makeNode(x);
        if (IsEmpty())
        {
            front = newNode;
            back = newNode;
            return;
        }

        Node *tmp = front;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = newNode;
    }

    void pop()
    {
        if (IsEmpty())
            return;
        Node *tmp = front;
        front = front->next;
        delete tmp;
    }

    void print()
    {
        Node *tmp = front;
        while (tmp != NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.initQueue();
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.Front() << endl;
    q.pop();
    cout << q.Front() << endl;
    cout << q.size() << endl;
    q.print();
    return 0;
}

//====================================================================================================================
/* QUEUE_ARRAY
#include<iostream>

using namespace std;

int queue[100000], max_N = 10000;
int size_queue = 0;

int size(){
    return size_queue;
}

bool empty(){
    return size_queue == 0;
}

void push(int x){
    if(size_queue == max_N) return;
    queue[size_queue] = x;
    size_queue++;
}

void pop(){
    if(size_queue == 0) return;
    for(int i = 0; i < size_queue - 1; i++){
        queue[i] = queue[i+1];
    }
    --size_queue;
}

int front(){
    if(size_queue == 0) return -1;
    return queue[0];
}

int main(){
    if(empty()) cout << "Empty" << endl;
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    pop();
    pop();
    if(empty()) cout << "Empty" << endl;
    for(int i=0; i<size(); i++){
        cout << queue[i] << " ";
    }
    cout << front() << endl;
    return 0;
}
//======================================================================================================

//Priority Queue
// Giong Queue nhung co them 1 ham so sanh ve do uu tien
// Do uu tien cao nhat duoc xe truoc, len dau hang, uu tien thap nhat duoc xe sau, cuoi hang

/*
Giả sử ta có một mảng với 5 phần tử: {4, 8, 1, 7, 3} và bạn phải chèn các phần tử này vào một hàng đợi ưu tiên theo giá trị lớn nhất.

Bước 1: Ban đầu hàng đợi rỗng, do vậy 4 được chèn vào. Hàng đợi sẽ là: {4}.

Bước 2: Chèn 8 vào hàng đợi, do 8 lớn hơn 4 lên 8 được đẩy lên đầu hàng đợi. Hàng đợi sẽ là: {8, 4}.

Bước 3: chèn 1 vào hàng đợi, 1 nhỏ hơn 4 và 8 nên 1 giữ nguyên vị trí ở cuối hàng đợi. Hàng đợi sẽ là: {8, 4, 1}.

Bước 4: Chèn 7 vào hàng đợi, 7 lớn hơn 1 và 4, nhỏ hơn 8 nên 7 được đẩy lên vị trí nằm giữa 4 và 8. Hàng đợi sẽ là: {8, 7, 4, 1}.

Bước 5: Chèn 3 vào hàng đợi, 3 lớn hơn 1 và nhỏ hơn 4 lên 3 được đẩy lên vị trí nằm giữa 1 và 4. Hàng đợi sẽ là: {8, 7, 4, 3, 1}.

Khi đó hàng đợi sẽ là: {8, 7, 3, 4, 1}.

// Độ phức tạp: O(nlogn) hoặc O(n)

#include <iostream>
using namespace std;

int N;
int a[100000];
void push(int val)
{
    N = N + 1; // tang kich thuoc hang doi len 1 khi chen them phan tu

    int i = N; // sd bien tam i

    a[i] = val; // them phan tu duoc chen vao vi tri cuoi cung hang doi

    while (i > 1 && a[i / 2] < a[i])
    {                         // neu gia tri node cha < gia tri cua no
        swap(a[i / 2], a[i]); // swap 2 node
        i = i / 2;            // tiep tuc kiem tra vi tri node cha
    }
}

void max_heap(int i)
{
    int largest;
    int left = 2 * i;      // con trai
    int right = 2 * i + 1; // con phai
    if (left <= N && a[left] > a[i])
        largest = left;
    else
        largest = i;

    if (right <= N && a[right] > a[largest])
        largest = right;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        max_heap(largest);
    }
}

int top()
{
    return a[1]; // vi tri node goc trong heap, co gia tri lon nhat
}

int pop()
{
    if (N == 0)
    {
        cout << "ko xoa dc\n";
        return -1;
    }

    int max = a[1];
    a[1] = a[N];
    N = N - 1;
    max_heap(1);
    return max;
}

void print()
{
    if (N <= 0)
        return;
    for (int i = 1; i <= N; i++)
        cout << a[i] << " ";
    cout << endl;
}

int size()
{
    return N;
}

int main()
{
    N = 0;
    push(4);
    push(8);
    push(1);
    push(7);
    push(3);
    cout << "size1 " << size() << "\n";
    print();
    push(6);
    cout << "size2 " << size() << "\n";
    print();
    pop();
    print();
    pop();
    print();
    cout << "size3 " << size() << endl;
    return 0;
}
//=====================================================================================================================

//BinaryHeapTree
// Heap Tree implementation in C++

/*
    Heap Tree là một cây nhị phân cân bằng có các tính chất sau:
        - Cây nhị phân đầy đủ (binary)
        - Mỗi nút (node) trên cây đều chứa một nhãn lớn hơn hoặc bằng các con của nó (nếu có)
        và nhỏ hơn hoặc bằng nút cha (trừ nút gốc là và nó là nút lớn nhất). (heap)
        - dc dùng để cài đặt thuật toán sắp xếp (sort) hay tìm kiếm (search) các phần tử trong một mảng
        Priority Queue là một cấu trúc dữ liệu dạng hàng đợi (queue) mà ở đó mỗi phần tử được gắn với một độ ưu tiên (priority).
        Prim, Disjkstra, Huffman, ...

    - Cây heap là một cây nhị phân thỏa mãn các đỉnh trong có giá trị khóa lớn hơn hoặc bằng giá trị khóa của các đỉnh con (Maxheap)
    Đối với MinHeap thì ngược lại




// C1
#include <bits/stdc++.h>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
void heapify(int arr[], int N, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, N, largest);
    }
}

// Function to build a Max-Heap from the given array
void buildHeap(int arr[], int N)
{
    // Index of last non-leaf node
    int startIdx = (N / 2) - 1;

    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--)
    {
        heapify(arr, N, i);
    }
}

void insert(int arr[], int N, int key)
{
    N++;
    arr[N - 1] = key;
    heapify(arr, N, N - 1);
}

// A utility function to print the array
// representation of Heap
void printHeap(int arr[], int N)
{
    cout << "Array representation of Heap is:\n";

    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver Code
int main()
{
    // Binary Tree Representation
    // of input array
    /*            1
                /    \
              3        5
            /  \     /  \
          4      6  13  10
         / \    / \
        9   8  15 17
      
    int arr[] = {2, 1, 10, 3, 8, 7, 20, 14, 0};

    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    buildHeap(arr, N);
    printHeap(arr, N);

    // Final Heap:
    /*             17
                 /    \
               15      13
              /  \     / \
             9     6  5   10
            / \   / \
           4   8 3   1
      

    return 0;
}

// ------------------- ------------------------------------
// C2
// #include <iostream>
// #include <vector>

// using namespace std;

// class Heap
// {
// private:
//     vector<int> heap;

//     void heapify(int index)
//     {
//         int left = 2 * index + 1;
//         int right = 2 * index + 2;
//         int largest = index;

//         if (left < heap.size() && heap[left] > heap[largest])
//             largest = left;
//         if (right < heap.size() && heap[right] > heap[largest])
//             largest = right;

//         if (largest != index)
//         {
//             swap(heap[index], heap[largest]);
//             heapify(largest);
//         }
//     }

// public:
//     void insert(int x)
//     {
//         heap.push_back(x); // chen vao cuoi heap

//         int index = heap.size() - 1;  // chi so cua phan tu vua chen vao
//         int parent = (index - 1) / 2; // chi so cua cha cua phan tu vua chen vao

//         // heapifyUp
//         while (index > 0 && heap[index] > heap[parent])
//         {
//             swap(heap[index], heap[parent]);
//             index = parent;
//             parent = (index - 1) / 2;
//         }
//     }

//     void remove(int x)
//     {
//         if (heap.empty())
//             return;

//         int index = 0;
//         for (int i = 0; i < heap.size(); i++)
//         {
//             if (heap[i] == x)
//             {
//                 index = i;
//                 break;
//             }
//         }

//         heap[index] = heap.back();
//         heap.pop_back();

//         heapify(index);
//     }

//     void print()
//     {
//         for (int i = 0; i < heap.size(); i++)
//             cout << heap[i] << " ";
//         cout << endl;
//     }
// };

// int main()
// {
//     Heap h;
//     h.insert(2);
//     h.insert(1);
//     h.insert(10);
//     h.insert(6);
//     h.insert(3);
//     h.insert(8);
//     h.insert(7);
//     h.insert(13);
//     h.insert(20);

//     h.print();
//     cout << endl;

//     h.insert(14);
//     h.insert(0);
//     h.insert(35);

//     h.print();
//     cout << endl;

//     h.remove(6);
//     h.remove(13);
//     h.remove(35);

//     h.print();
//     cout << endl;
//     return 0;
// }
//=====================================================================================================================

//BinarySearchTree
// BINARY SEARCH TREE

/*
    Cây nhị phân lưu trữ các phần tử riêng biệt nhau
    Cây nhị phân có 2 tính chất:
        - Tất cả các phần tử bên trái của 1 node có giá trị nhỏ hơn node đó
        - Tất cả các phần tử bên phải của 1 node có giá trị lớn hơn node đó
    Là quan hệ bố con giữa các node với mỗi nút cha có tối đa 2 node con
        + Giá trị lưu tại node đó, có thể là bất kì kiểu dữ liệu nào
        + Địa chỉ node gốc của cây con bên trái
        + Địa chỉ node gốc của cây con bên phải

    Các thao tác cơ bản:
        - Tìm kiếm
        - Thêm
        - Xóa
        - Duyệt cây

    Các loại cây nhị phân:
        + Cây nhị phân tìm kiếm:
            - Là cây nhị phân có thêm tính chất tìm kiếm
            - Tất cả các phần tử bên trái của 1 node có giá trị nhỏ hơn node đó
            - Tất cả các phần tử bên phải của 1 node có giá trị lớn hơn node đó

        + Cây nhị phân đầy đủ:
            - Là cây nhị phân mà tất cả các node đều có 2 node con hoặc không có node con nào
            - Cây nhị phân đầy đủ có số node là 2^n - 1 (n là số tầng của cây)
        + Cây nhị phân cân bằng:
            - Là cây nhị phân mà độ cao của cây là O(logn)
            - Cây nhị phân cân bằng có số node là 2^n - 1 (n là số tầng của cây)
            - số phần tử cây con bên trái chênh lệch không quá 1 so với cây con bên phải

    Bậc của 1 node là số lượng node con của node đó (Số node con có trong cây con của node đó)


// tree* search(tree* root, int x){
//     if (root == NULL || root->data == x){
//         return root;
//     }

//     if (x < root->data){
//         return search(root->left, x);
//     }
//     else{
//         return search(root->right, x);
//     }
// }

#include <iostream>

using namespace std;

class tree
{
public:
    int val;
    tree *left;
    tree *right;

    tree(int value)
    {
        val = value;
        left = NULL;
        right = NULL;
    }
};

void insert(tree *&root, int value)
{
    if (root == NULL)
    {
        root = new tree(value);
        return;
    }

    if (value < root->val)
    {
        insert(root->left, value);
    }
    else
    {
        insert(root->right, value);
    }
}


tree *findMin(tree *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

tree *findMax(tree *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

tree *remove(tree *&root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (value < root->val)
    {
        root->left = remove(root->left, value);
    }
    else if (value > root->val)
    {
        root->right = remove(root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            tree *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            tree *temp = root->left;
            delete root;
            return temp;
        }

        tree *minNode = findMin(root->right);
        root->val = minNode->val;
        root->right = remove(root->right, minNode->val);
    }

    return root;
}

void inorderTraversal(tree *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

tree *search(tree *root, int x)
{
    if (root == NULL || root->val == x)
    {
        return root;
    }

    if (x < root->val)
    {
        return search(root->left, x);
    }
    else
    {
        return search(root->right, x);
    }
}

void free(tree* root){
    if (root == NULL){
        return;
    }

    free(root->left);
    free(root->right);
    delete root;
}

int height(tree* root){
    if (root == NULL){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

void printNodeLeaf(tree* root){
    if(root != NULL){
        if (root->left == NULL && root->right == NULL){
            cout << root->val << " ";
        }
        printNodeLeaf(root->left);
        printNodeLeaf(root->right);
    }
}

void printNodeHasOneChild(tree* root){
    if(root != NULL){
        if (root->left == NULL && root->right != NULL){
            cout << root->val << " ";
        }
        else if (root->left != NULL && root->right == NULL){
            cout << root->val << " ";
        }
        printNodeHasOneChild(root->left);
        printNodeHasOneChild(root->right);
    }
}

void printNodeHasTwoChild(tree* root){
    if(root != NULL){
        if (root->left != NULL && root->right != NULL){
            cout << root->val << " ";
        }
        printNodeHasTwoChild(root->left);
        printNodeHasTwoChild(root->right);
    }
}

int main()
{
    tree *root = NULL;

    // Initial Binary Search Tree
    int initialNumbers[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    int initialSize = 9;
    for (int i = 0; i < initialSize; i++)
    {
        insert(root, initialNumbers[i]);
    }

    cout << "Initial Binary Search Tree:" << endl;
    inorderTraversal(root);
    cout << endl;

    // Inserting values: 14, 0, 35
    insert(root, 14);
    insert(root, 0);
    insert(root, 35);

    cout << "Binary Search Tree after Insertion:" << endl;
    inorderTraversal(root);
    cout << endl;

    // Deleting values: 6, 13, 35
    remove(root, 6);
    remove(root, 13);
    remove(root, 35);

    cout << "Binary Search Tree after Deletion:" << endl;
    inorderTraversal(root);
    cout << endl;

    free(root);

    return 0;
}
//===============================================================================================================================================
//BINARYTREE

// cây nhị phân hoàn chỉnh (completeBinaryTree): tất cả các mức đều đầy, trừ mức cuối cùng có thể thiếu các nút ở bên phải
// cây nhị phân đầy đủ (fullBinaryTree): mỗi đỉnh có đúng 2 con hoặc 0 con
// cây nhị phân hoàn toàn (perfectBinaryTree): tất cả các node đều có 2 con và các node lá đều ở cùng cấp
// cây nhị phân cân bằng (balancedBinaryTree): cây có độ cao nhỏ hơn hoặc bằng log2(n+1)
// là các cây con tại mỗi đỉnh chứa các đường đi có độ dài như nhau
// tất cả các lá đều ở mức h hoặc h-1

#include <iostream>
#include <vector>

using namespace std;

class Tree
{
public:
    int data;
    vector<Tree *> children;

    Tree(int value)
    {
        data = value;
    }
};

int height(Tree *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int maxHeight = 0;
    for (Tree *child : root->children)
    {
        maxHeight = max(maxHeight, height(child));
    }

    return maxHeight + 1;
}

bool checkBinaryTree(Tree *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->children.size() > 2)
    {
        return false;
    }

    for (Tree *child : root->children)
    {
        if (!checkBinaryTree(child))
        {
            return false;
        }
    }

    return true;
}

bool checkFullBinaryTree(Tree *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->children.size() != 0 && root->children.size() != 2)
    {
        return false;
    }

    for (Tree *child : root->children)
    {
        if (!checkFullBinaryTree(child))
        {
            return false;
        }
    }

    return true;
}

bool isBalancedBinaryTree(Tree *node)
{
    if (node == NULL)
        return true;

    int maxh = 0;
    int minh = 1e9 + 1;

    for (Tree *child : node->children)
    {
        int h = height(child);
        maxh = max(maxh, h);
        minh = min(minh, h);
    }

    if (maxh - minh > 1)
        return false;

    for (Tree *child : node->children)
    {
        if (!isBalancedBinaryTree(child))
        {
            return false;
        }
    }
    return true;
}

bool checkCompleteBinaryTree(Tree *root)
{
    return true;
}

void free(vector<Tree*> nodes)
{
    for(Tree* child : nodes){
        delete child;
    }
}

int main(){
    int n; cin >> n;
    vector<Tree*> nodes(n);

    for(int i = 0; i < n; i++){
        nodes[i] = new Tree(i);
    }

    for(int i = 0; i < n - 1; i++){
        int x, y; cin >> x >> y;
        nodes[x]->children.push_back(nodes[y]);
    }

    Tree* root = nodes[0];

    bool isBinary = checkBinaryTree(root);
    if(isBinary) cout << "yes" << endl;
    else cout << "no" << endl;
}
//===========================================================================================
//DUYỆT CÂY

#include <iostream>
#include <vector>

using namespace std;

class node
{
public:
    int data;
    vector<node *> children;

    node(int value)
    {
        data = value;
    }
};

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int maxHeight = 0;

    for (int i = 1; i < (int)root->children.size(); i++)
    {
        int childHeight = height(root->children[i]);
        maxHeight = max(maxHeight, childHeight);
    }

    return maxHeight + 1;
}

bool checkBinaryTree(node *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->children.size() > 2)
    {
        return false;
    }

    for (node *child : root->children)
    {
        if (!checkBinaryTree(child))
        {
            return false;
        }
    }

    return true;
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";

    for (node *child : root->children)
    {
        preorder(child);
    }
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    for (node *child : root->children)
    {
        postorder(child);
    }

    cout << root->data << " ";
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->children.size() == 0)
    {
        cout << root->data << " ";
        return;
    }

    inorder(root->children[0]);
    cout << root->data << " ";

    for (int i = 1; i < (int)root->children.size(); i++)
    {
        inorder(root->children[i]);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<node *> tree(n);

    for (int i = 0; i < n; i++)
    {
        tree[i] = new node(i + 1);
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x - 1]->children.push_back(tree[y - 1]);
    }

    node *root = tree[0];

    cout << height(root) << endl;

    bool isFullBinary = checkBinaryTree(root);


    preorder(root);
    cout << endl;

    postorder(root);
    cout << endl;

    if (isFullBinary)
    {
        inorder(root);
    }
    else
    {
        cout << "NOT BINARY TREE" << endl;
    }
    cout << endl;

    for (node *root : tree)
    {
        delete root;
    }

    return 0;
}
//========================================================================================================================
//BUBLE SORT

#include<iostream>

using namespace std;

// O(n^2) O(n)
// Cho n so, lap di lap lai (n-1) lan cac buoc sau:
// voi moi so ke nhau neu so ben trai > ben phai
// => swap
void BubbleSort(int a[], int n){
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    BubbleSort(a,n);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
}
//========================================================================================================================

//COUNTING SORT
#include<iostream>

using namespace std;

// O(n+max)
int cnt[10000001];

int main(){
    int n, a[1000], MAX = INT_MIN;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
        MAX = max(MAX, a[i]);
    }

    for(int i = 0; i <= MAX; i++){
        if(cnt[i] != 0)
            for(int j = 0; j < cnt[i]; j++)
                cout << i << " ";
    }

    return 0;
}
//========================================================================================================================

//HEAP SORT
#include<iostream>
#include<algorithm>

using namespace std;

// O(n logn)
void heapify(int a[], int n, int i){
    int largest = i; // chỉ số của số lớn nhất
    int left = 2*i + 1; // chỉ số của con trái
    int right = 2*i + 2; // chỉ số của con phải 

    if(left < n && a[left] > a[largest]) largest = left;
    if(right < n && a[right] > a[largest]) largest = right;

    if(largest != i){ 
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n){
    // bắt đầu từ nốt không phải là lá là (n/2 - 1)
    for(int i = n/2 -1; i >= 0; i--) heapify(a, n, i);

    /* phần tử a[0] là MAX_HEAP, swap với phần tử cuối 
            trong mảng và không xét phần tử cuối đó 
    for(int i = n - 1; i >= 0; i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main(){
    int n = 6;
    int a[1000];
    for(int i = 0; i <  n; i++) cin >> a[i];
    heapSort(a, n);
    for(int i = 0; i < n; i++) cout << a[i] << " " ;
    return 0;
}
//========================================================================================================================

//INSERTION SORT
#include<iostream>

using namespace std;

// O(n^2)
void InsertionSort(int a[], int n){
    for(int i=1; i<n; i++){
        int tmp = a[i];
        int j = i-1;
        while(j>=0 && tmp < a[j]){
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = tmp;
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    InsertionSort(a,n);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
}
//========================================================================================================================

//MERGE SORT

#include<iostream>
#include<vector>

using namespace std;

// O(n logn)
// Trộn 2 dãy con được sắp xếp tăng dần 
void merge(int a[], int left, int mid, int right){
    vector<int> leftarray(a+left, a+mid+1); //dãy bên trái 
    vector<int> rightarray(a+mid+1, a+right+1); //dãy bên phải
    int i=0; // chỉ số dãy trái
    int j=0; // chỉ số dãy phải 

    while(i < (int)leftarray.size() && j < (int)rightarray.size()){
        if(leftarray[i] <= rightarray[j]){
            a[left] = leftarray[i];
            ++left;
            ++i;
        }else{
            a[left] = rightarray[j];
            ++left;
            ++j;
        }
    }
    
    // in nốt phần tử của dãy bên trái (có số phần tử lớn hơn dãy bên phải)
    while(i < (int)leftarray.size()){
        a[left] = leftarray[i];
        ++left;
        ++i;
    }

    // in nốt phần tử của dãy bên phải (có số phần tử lớn hơn dãy bên trái)
    while(j < (int)rightarray.size()){
        a[left] = rightarray[j];
        ++left;
        ++j;
    }
}

void mergeSort(int a[], int left, int right){
    if(left >= right) return;
    int mid = (left + right)/2;
    mergeSort(a, left, mid); // đệ quy dãy trái
    mergeSort(a, mid+1, right); // đệ quy dãy phải 
    merge(a, left, mid, right); // trộn 2 dãy đc sắp xếp
}

int main(){
    int n, a[1000];
    cin >> n;
    for(int i = 0; i < n ; i++) cin >> a[i];

    mergeSort(a, 0, n-1);

    for(int i = 0; i < n ; i++) cout << a[i] << " " ;
    return 0;
}


// Cách trình bày khác 
/*
    void merge(int a[], int left[], int left_size, int right[], int right_size){
        int i = 0, j = 0; // index of left array anhd right array
        int k = 0; // index of array a

        // So sánh và trộn các phần tử của 2 nửa
        while(i < left_size && j < right_size){
            if(left[i] <= right[i]){
                a[k] = left[i];
                i++;
            }else{
                a[k] = right[j];
                j++;
            }
            k++;
        }

        // đưa các phần tử còn lại của hai nửa vào mảng kết quả 
        while(i < left_size){
            a[k] = left[i];
            i++;
            k++;
        }
        while(j < right_size){
            a[k] = right[j];
            j++;
            k++;
        }
    }

    void mergeSort(int a[], int size){
        if(size <= 1) return;

        int mid = size/2;
        int left[mid];
        int right[size-mid];

        // Chia mảng thành 2 nửa 
        for(int i = 0; i < mid; i++) left[i] = a[i];
        for(int i = mid; i < size; i++) right[i-mid] = a[i];

        // Đệ quy sắp xếp từng nửa 
        mergeSort(left, mid);
        mergeSort(right, size-mid);

        // Trộn 2 nửa đã sắp xếp 
        merge(a, left, mid, right, size-mid);
    }
*/

/*==================================================================================================================================================

ĐÊM SỐ CẶP NGHỊCH THẾ TRONG MẢNG = MERGE_SORT 

int merge(int a[], int l, int r, int m){
    vector<int> x(a+l, a+m+1);
    vector<int> y(a+m+1, a+r+1);

    int i = 0, j = 0;
    int cnt = 0;

    while( i < x.size() && j < y.size()){
        if(x[i] <= y[j]){
            a[l] = x[i];
            ++l;
            ++i;
        }else{
            cnt += x.size() - i; //Tong so cap nghich the 
            a[l] = y[j];
            ++l;
            ++j; 
        }
    }

    while( i < x.size()){
        a[l] = x[i];
        ++l;
        ++i;
    }

    while( j < y.size()){
        a[l] = y[j];
        ++l;
        ++j;
    }

    return cnt;
}

int mergeSort(int a[], int l, int r){
    int cnt = 0;
    if(l < r){
        int m = (r+l)/2;
        cnt += mergeSort(a, l, m); // tong cap nghich the trai
        cnt += mergeSort(a, m+1, r); // tong cap nghich the phai
        cnt += merge(a, l, r, m); // tong cap nghich the 1 phan tu trai va 1 phan tu phai0
    }
    return cnt;
}

int main(){
    int n = 6;
    int a[1000];
    for(int i = 0 ; i < n ; i++) cin >> a[i];

    int u = mergeSort(a, 0, n-1);
    cout << u << endl;
}
//==================================================================================================================================================
//QUICK SORT
#include<bits/stdc++.h>

using namespace std;

/*  O(nlogn) 
    O(n^2)
    PHÂN HOẠCH LOMUTO

int partition(int a[], int l, int r){
    int pivot = a[r]; //Chốt 
    int i = l-1;

    for(int j=l; j<r; j++){
        if(a[j] <= pivot){
            ++i;
            swap(a[j], a[i]);
        }
    }
    ++i;
    swap(a[i], a[r]);
    
    return i; //vị trí chốt 
}

void quickSort(int a[], int l, int r){
    if(l >= r) return; //điều kiện dừng khi chỉ còn 1 phần tử 
    int p = partition(a, l, r);
    quickSort(a, l, p-1);
    quickSort(a, p+1, r);
}

int main(){
    int n = 6;
    int a[1000];
    for(int i = 0; i < n; i++) cin >> a[i];
    quickSort(a, 0, n-1);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
}
//==================================================================================================================================================

//SELECTION SORT

#include<iostream>

using namespace std;

// O(n^2)
// Cho n so, lap di lap lai (n-1) buoc sau:
// Danh dau gia tri dau tien chua duoc sap xep
// Tim gia tri nho nhat trong cac so chua duoc sap xep
// => Hoan doi gia tri danh dau voi gia tri nho nhat tim dc
void SelectionSort(int a[], int n){
    for(int i = 0; i < n-1; i++){
        int min = i; //min_pos array
        //compare begin i+1 to end with min
        for(int j = i+1; j < n; j++){
            if(a[j] < a[min]) min = j;
        }
        //swap min and a[i]
        int tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    SelectionSort(a,n);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
}
*/
