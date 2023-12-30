//XOAY DANH SÁCH LIÊN KẾT
#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;

    node()
    {
        data = 0;
        next = NULL;
    }

    node(int d)
    {
        data = d;
        next = NULL;
    }
};
void print(node *&head)
{
    node *tmp = head;
    if (tmp == NULL)
    {
        cout << "List Empty!" << endl;
        return;
    }
    cout << tmp->data << " ";
    tmp = tmp->next;
    while (tmp != head)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int size(node *&head)
{
    if (head == NULL)
        return 0;
    int cnt = 0;
    node *tmp = head;
    tmp = tmp->next;
    cout << tmp->data << " ";
    cnt++;
    while (tmp != head)
    {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}

void rotate(node *head, int k)
{
    node *a = head;
    if (k == 0){
        print(head);
        return;
    }
    for (int i = 1; i <= k - 1; i++)
    {
        a = a->next;
    }
    cout << a->data << endl;

    node *b = a->next;
    print(b);
}

int main()
{
    node *head = new node(1);
    node *tmp = head;
    for (int i = 2; i <= 5; i++)
    {
        tmp->next = new node(i);
        tmp = tmp->next;
    }
    tmp->next = head;
    rotate(head, 0);
    // size(head);

    return 0;
}
//======================================================================================
//XÓA NODE CÔ ĐƠN
#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;

    node()
    {
        data = 0;
        next = NULL;
    }

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

node *deleteSingle(node *head)
{
    node *tmp = head;

    while (tmp->next != NULL)
    {

        if (tmp->data == tmp->next->data)
        {
            tmp = tmp->next;
        }
        else
        {
            if (head == tmp)
                head = tmp->next;
            if (tmp->next->data == tmp->next->next->data)
            {
                tmp = tmp->next;
            }
            else if (tmp->next->data != tmp->next->next->data)
            {
                node *x = tmp->next;
                tmp->next = x->next;
                delete x;
            }

        }
    }

    return head;
}

void print(node *head)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void addLast(node *&head, int x)
{
    node *n = new node(x);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = n;
}

int main()
{
    node *head = NULL;
    addLast(head, 2);
    addLast(head, 2);
    addLast(head, 2);
    addLast(head, 3);
    addLast(head, 4);
    addLast(head, 4);
    addLast(head, 5);
    head = deleteSingle(head);
    print(head);
    return 0;
}

//======================================================================================
//BINARY TREE
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    vector<Node*> children;

    Node(int value) {
        data = value;
    }
};

bool isBinaryTree(Node* node) {
    if (node == NULL) return true;

    if (node->children.size() > 2) return false;
    
    for (Node* child : node->children) {
        if (!isBinaryTree(child)) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<Node*> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i] = new Node(i);
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        nodes[x]->children.push_back(nodes[y]);
    }

    bool isBinary = isBinaryTree(nodes[0]);
    if (isBinary) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}
//======================================================================================
// CÂY CÂN BẰNG

#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;

    Node(int value)
    {
        data = value;
    }
};

// bool isBinaryTree(Node* node) {
//     if (node == NULL) return true;

//     if (node->children.size() > 2) return false;

//     for (Node* child : node->children) {
//         if (!isBinaryTree(child)) {
//             return false;
//         }
//     }

//     return true;
// }

int solveheight(Node *node)
{
    if (node == NULL)
        return 0;
    int h = 0;
    for (Node *child : node->children)
    {
        h = max(h, solveheight(child));
    }
    return h + 1;
}

// bool checkheight(Node *node)
// {
//     if (node == NULL)
//         return true;
//     if (node->children.size() == 0)
//         return true;
//     int h = solveheight(node);
//     for (Node *child : node->children)
//     {
//         if (solveheight(child) == h - 1)
//             return true;
//     }
//     return false;
// }

bool isBalancedBinaryTree(Node *node)
{
    if (node == NULL)
        return true;

    int maxh = 0;
    int minh = 1e9 + 1;

    for (Node *child : node->children)
    {
        int height = solveheight(child);
        maxh = max(maxh, height);
        minh = min(minh, height);
    }

    if (maxh - minh > 1)
        return false;

    for (Node *child : node->children)
    {
        if (!isBalancedBinaryTree(child))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    vector<Node *> nodes(n);
    for (int i = 0; i < n; i++)
    {
        nodes[i] = new Node(i);
    }

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        nodes[x]->children.push_back(nodes[y]);
    }

    bool isBinary = isBalancedBinaryTree(nodes[0]);
    if (isBinary)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}

//======================================================================================
//
#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

struct Student
{
    int id;
    string name;
    string studentClass;

    Student()
    {
        id = 0;
        name = "";
        studentClass = "";
    }
};

unordered_map<int, Student> list_students;

void insertStudent(Student &student)
{
    list_students[student.id] = student;
}

void deleteStudent(Student &student)
{
    list_students.erase(student.id);
}

void informationStudent(int id)
{
    if (list_students.find(id) != list_students.end())
    {
        cout << list_students[id].name << ","
             << list_students[id].studentClass
             << endl;
    }
    else
    {
        cout << "NA, NA";
    }
}

int main()
{
    string q;

    while (getline(cin, q))
    {
        int len = q.size();
        string check_1 = q.substr(0, 6);
        string check_2 = q.substr(0, 5);
        Student student;
        if (check_1 == "Insert")
        {
            string ans = q.substr(7, len - 8);
            stringstream ss(ans);

            int id;
            string res;
            string name, studentClass;

            string new_q = "";
            while (getline(ss, res, ','))
            {
                new_q += " " + res;
            }

            stringstream ss_2(new_q);
            ss_2 >> id >> name >> studentClass;

            student.id = id;
            student.name = name;
            student.studentClass = studentClass;

            insertStudent(student);
        }

        if (check_1 == "Delete")
        {
            string ans = q.substr(7, len - 8);
            stringstream ss(ans);
            int id;
            ss >> id;
            student.id = id;
            deleteStudent(student);
        }

        if (check_2 == "Infor")
        {
            string ans = q.substr(6, len - 7);
            stringstream ss(ans);
            int id;
            ss >> id;
            informationStudent(id);
        }
    }
    return 0;
}
//======================================================================================
//KIỂM TRA DÃY NGOẶC ĐÚNG BẰNG STACK

#include <iostream>
#include <stack>
#include <string>

bool isValidExpression(const std::string &expression)
{
    std::stack<char> stack;

    for (char c : expression)
    {
        if (c == '{' || c == '[' || c == '(')
        {
            stack.push(c);
        }
        else if (c == '}' || c == ']' || c == ')')
        {
            if (stack.empty())
            {
                return false; // Mismatched closing bracket.
            }

            char openBracket = stack.top();
            stack.pop();

            // Check if the closing bracket matches the expected open bracket.
            if ((c == '}' && openBracket != '{') ||
                (c == ']' && openBracket != '[') ||
                (c == ')' && openBracket != '('))
            {
                return false;
            }
        }
    }

    return stack.empty(); // Check if all opening brackets have been closed.
}

int main()
{
    std::string expression = "[][](){}({})";
    bool valid = isValidExpression(expression);

    if (valid)
    {
        std::cout << "The expression is valid." << std::endl;
    }
    else
    {
        std::cout << "The expression is not valid." << std::endl;
    }

    return 0;
}

//======================================================================================
//HEAP TREE BẰNG DANH SÁCH LIÊN KẾT
#include <iostream>
#include <queue>

using namespace std;

// Định nghĩa cấu trúc nút trong linked list
struct Node {
    int data;
    Node* next;
};

// Heap bằng linked list
class LinkedListHeap {
private:
    Node* head; // Nút đầu tiên của linked list

public:
    LinkedListHeap() : head(nullptr) {}

    // Thêm một phần tử vào heap
    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            // Tìm vị trí thích hợp để chèn phần tử mới vào
            Node* current = head;
            Node* previous = nullptr;
            while (current != nullptr && current->data < value) {
                previous = current;
                current = current->next;
            }

            // Chèn phần tử mới vào linked list
            if (previous == nullptr) {
                newNode->next = head;
                head = newNode;
            } else {
                previous->next = newNode;
                newNode->next = current;
            }
        }
    }

    // Kiểm tra heap có rỗng hay không
    bool isEmpty() {
        return head == nullptr;
    }

    // Lấy giá trị lớn nhất (gốc của heap)
    int getMax() {
        if (head != nullptr) {
            return head->data;
        }

        throw runtime_error("Heap is empty.");
    }

    // Xóa giá trị lớn nhất (gốc của heap)
    void removeMax() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            throw runtime_error("Heap is empty.");
        }
    }

    // In ra các phần tử trong heap
    void printHeap() {
        if (head == nullptr) {
            cout << "Heap is empty." << endl;
            return;
        }

        queue<Node*> nodeQueue;
        nodeQueue.push(head);

        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();

            for (int i = 0; i < levelSize; i++) {
                Node* current = nodeQueue.front();
                nodeQueue.pop();

                cout << current->data << " ";

                if (current->next != nullptr) {
                    nodeQueue.push(current->next);
                }
            }

            cout << endl;
        }
    }
};

int main() {
    LinkedListHeap heap;

    // Thêm các phần tử vào heap
    heap.insert(10);
    heap.insert(5);
    heap.insert(15);
    heap.insert(20);
    heap.insert(8);

    // In ra các phần tử trong heap
    cout << "Heap: " << endl;
    heap.printHeap();

    return 0;
}