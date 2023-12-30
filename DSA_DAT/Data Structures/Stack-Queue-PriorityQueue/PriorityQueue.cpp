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
*/
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

/*
#include <iostream>
#include <vector>
#include <utility> // Để sử dụng std::pair

using namespace std;

class PriorityQueue {
private:
    vector<pair<int, int>> heap; // Lưu trữ các thực thể (key, value)

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;

        while (index > 0 && heap[index].first > heap[parent].first) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild].first > heap[largest].first) {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild].first > heap[largest].first) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int key, int value) {
        pair<int, int> entity(key, value);
        heap.push_back(entity);
        heapifyUp(heap.size() - 1);
    }

    pair<int, int> removeMax() {
        if (heap.empty()) {
            cerr << "Priority queue is empty." << endl;
            return make_pair(-1, -1);
        }

        pair<int, int> maxEntity = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return maxEntity;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(5, 100);
    pq.insert(2, 200);
    pq.insert(8, 300);
    pq.insert(1, 400);

    pair<int, int> maxEntity = pq.removeMax();
    cout << "Max entity: key = " << maxEntity.first << ", value = " << maxEntity.second << endl;

    return 0;
}*/