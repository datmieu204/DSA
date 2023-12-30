// #include<iostream>

// using namespace std;

// //O(logn)

// long long binary_pow(int a, int n) {
//     long long res = 1;

//     while (n > 0){
//         if(n & 1) res = res * a;
//         a = a * a;
//         n >>= 1; // n /= 2;
//     }
//     return res;
// }

// long long solve_2_pow_n(int a, int n){
//     if(n == 0) return 1;

//     long long res = solve_2_pow_n(a, n/2);

//     if(n % 2 == 0){
//         return res * res;
//     }
//     else{
//         return res * res * a;
//     }
// }

// int main(){
//     int n;
//     cin >> n;
//     // cout << solve_2_pow_n(2, n) << endl;
//     cout << binary_pow(2, n) << endl;
//     return 0;
// }

// #include<iostream>

// using namespace std;

// int queue[100000], max_N = 10000;
// int size_queue = 0;

// int size(){
//     return size_queue;
// }

// bool empty(){
//     return size_queue == 0;
// }

// void push(int x){
//     if(size_queue == max_N) return;
//     queue[size_queue] = x;
//     size_queue++;
// }

// void pop(){
//     if(size_queue == 0) return;
//     for(int i = 0; i < size_queue - 1; i++){
//         queue[i] = queue[i+1];
//     }
//     --size_queue;
// }

// int front(){
//     if(size_queue == 0) return -1;
//     return queue[0];
// }

// int main(){
//     if(empty()) cout << "Empty" << endl;
//     push(1);
//     push(2);
//     push(3);
//     push(4);
//     push(5);
//     pop();
//     pop();
//     if(empty()) cout << "Empty" << endl;
//     for(int i=0; i<size(); i++){
//         cout << queue[i] << " ";
//     }
//     cout << front() << endl;
//     return 0;
// }

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
    st.push(1);
    st.push(2);
    st.pop();
    st.print();
    cout << st.top->data << endl;
    cout << st.size() << endl;
    return 0;
}

// #include <iostream>

// using namespace std;

// int Stack[100000], max_N = 10000;
// int size_stack = 0;

// int size(){
//     return size_stack;
// }

// bool empty(){
//     return size_stack == 0;
// }

// void push(int x){
//     if(size_stack == max_N) return;
//     Stack[size_stack] = x;
//     size_stack++;
// }

// void pop(){
//     if(size_stack == 0) return;
//     --size_stack;
// }

// void top(){
//     if(size_stack == 0) return;
//     cout << Stack[size_stack-1] << endl;
// }

// int main(){
//     if(empty()) cout << "Empty" << endl;
//     push(1);
//     push(2);
//     push(3);
//     push(4);
//     push(5);
//     pop();
//     pop();
//     if(empty()) cout << "Empty" << endl;
//     for(int i=0; i<size(); i++){
//         cout << Stack[i] << " ";
//     }
//     cout << endl;
// }


// #include<iostream>

// using namespace std;

// long long power_solve(int n){
//     if(n == 0) return 1;
//     if(n % 2 == 0) return power_solve(n/2) * power_solve(n/2);
//     else return power_solve((n-1)/2) * power_solve((n-1)/2) * 2;
// }

// int main(){
//     int n; cin >> n;
//     cout << power_solve(n) << endl;
//     return 0;
// }