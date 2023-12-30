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
*/

// C1
#include <bits/stdc++.h>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
// void heapify(int arr[], int N, int i)
// {
//     int largest = i;   // Initialize largest as root
//     int l = 2 * i + 1; // left = 2*i + 1
//     int r = 2 * i + 2; // right = 2*i + 2

//     // If left child is larger than root
//     if (l < N && arr[l] > arr[largest])
//         largest = l;

//     // If right child is larger than largest so far
//     if (r < N && arr[r] > arr[largest])
//         largest = r;

//     // If largest is not root
//     if (largest != i)
//     {
//         swap(arr[i], arr[largest]);

//         // Recursively heapify the affected sub-tree
//         heapify(arr, N, largest);
//     }
// }

// // Function to build a Max-Heap from the given array
// void buildHeap(int arr[], int N)
// {
//     // Index of last non-leaf node
//     int startIdx = (N / 2) - 1;

//     // Perform reverse level order traversal
//     // from last non-leaf node and heapify
//     // each node
//     for (int i = startIdx; i >= 0; i--)
//     {
//         heapify(arr, N, i);
//     }
// }

// void insert(int arr[], int N, int key)
// {
//     N++;
//     arr[N - 1] = key;
//     heapify(arr, N, N - 1);
// }

// // A utility function to print the array
// // representation of Heap
// void printHeap(int arr[], int N)
// {
//     cout << "Array representation of Heap is:\n";

//     for (int i = 0; i < N; ++i)
//         cout << arr[i] << " ";
//     cout << "\n";
// }

// // Driver Code
// int main()
// {
//     // Binary Tree Representation
//     // of input array
//     /*            1
//                 /    \
//               3        5
//             /  \     /  \
//           4      6  13  10
//          / \    / \
//         9   8  15 17
//       */
//     // int arr[] = {2, 1, 10, 3, 8, 7, 20, 14, 0};
//     int arr[] = {2, 19, 38, 29, 66, 64, 72, 3, 16, 89, 15, 37, 20, 28, 73, 5};

//     int N = sizeof(arr) / sizeof(arr[0]);

//     // Function call
//     buildHeap(arr, N);
//     insert(arr, N, 5);
//     insert(arr, N, 13);
//     insert(arr, N, 9);
//     insert(arr, N, 7);
//     insert(arr, N, 24);
//     insert(arr, N, 4);
//     insert(arr, N, 6);
//     printHeap(arr, N);

//     // Final Heap:
//     /*             17
//                  /    \
//                15      13
//               /  \     / \
//              9     6  5   10
//             / \   / \
//            4   8 3   1
//       */

//     return 0;
// }

// ------------------- ------------------------------------
// C2
#include <iostream>
#include <vector>

using namespace std;

class Heap
{
private:
    vector<int> heap;

    void heapify(int index)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }

public:
    void insert(int x)
    {
        heap.push_back(x); // chen vao cuoi heap

        int index = heap.size() - 1;  // chi so cua phan tu vua chen vao
        int parent = (index - 1) / 2; // chi so cua cha cua phan tu vua chen vao

        // heapifyUp
        while (index > 0 && heap[index] > heap[parent])
        {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void remove(int x)
    {
        if (heap.empty())
            return;

        int index = 0;
        for (int i = 0; i < heap.size(); i++)
        {
            if (heap[i] == x)
            {
                index = i;
                break;
            }
        }

        heap[index] = heap.back();
        heap.pop_back();

        heapify(index);
    }

    void print()
    {
        for (int i = 0; i < heap.size(); i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main()
{
    Heap h;
    int arr[] = {12, 5 ,7 ,9, 20, 11, 56, 3 ,21, 19};

    for(int i = 0; i < 10; i++) {
        h.insert(arr[i]);
    }

    // h.insert(2);
    // h.insert(19);
    // h.insert(38);
    // h.insert(29);
    // h.insert(66);
    // h.insert(64);
    // h.insert(72);
    // h.insert(3);
    // h.insert(16);
    // h.insert(89);
    // h.insert(15);
    // h.insert(37);
    // h.insert(20);
    // h.insert(28);
    // h.insert(73);
    // h.insert(5);

    h.print();
    cout << endl;

    // h.remove(6);
    // h.remove(13);
    // h.remove(35);

    // h.print();
    // cout << endl;
    return 0;
}


//c3
/*
#include <iostream>
#include <queue>

int main()
{
    // Create a max heap with some elements using a priority_queue
    std::priority_queue<int> maxHeap;
    //     int arr[MAX] = {2, 19, 38, 29, 66, 64, 72, 3, 16, 89, 15, 37, 20, 28, 73, 5};
    //     // 5, 13, 9, 7, 24, 4, 6
    maxHeap.push(2);
    maxHeap.push(19);
    maxHeap.push(38);
    maxHeap.push(29);
    maxHeap.push(66);
    maxHeap.push(64);
    maxHeap.push(72);
    maxHeap.push(3);
    maxHeap.push(16);
    maxHeap.push(89);
    maxHeap.push(15);
    maxHeap.push(37);
    maxHeap.push(20);
    maxHeap.push(28);
    maxHeap.push(73);
    maxHeap.push(5);
    maxHeap.push(5);
    maxHeap.push(13);
    maxHeap.push(9);
    maxHeap.push(7);
    maxHeap.push(24);
    maxHeap.push(4);
    maxHeap.push(6);

    // Get the peak element (i.e., the largest element)

    for (int i = 0; i < 23; i++)
    {
        std::cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    return 0;
}

*/