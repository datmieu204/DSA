// #include <iostream>
// #include <vector>
// #include <cmath>

// template <class Item>
// class Node {
// public:
//     Item data;
//     std::vector<Node<Item>*> children;

//     Node(Item value) {
//         data = value;
//     }
// };

// // Hàm tính độ cao của cây
// int calculateHeight(Node<int>* node) {
//     if (node == nullptr) {
//         return 0;
//     }

//     int maxHeight = 0;
//     for (Node<int>* child : node->children) {
//         int height = calculateHeight(child);
//         maxHeight = std::max(maxHeight, height);
//     }

//     return maxHeight + 1;
// }

// // Hàm kiểm tra xem cây có phải là cây nhị phân cân bằng hay không
// bool isBalancedBinaryTree(Node<int>* node) {
//     if (node == nullptr) {
//         return true;
//     }

//     int maxHeight = 0;
//     int minHeight = std::numeric_limits<int>::max();

//     for (Node<int>* child : node->children) {
//         int height = calculateHeight(child);
//         maxHeight = std::max(maxHeight, height);
//         minHeight = std::min(minHeight, height);
//     }

//     if (maxHeight - minHeight > 1) {
//         return false;
//     }

//     for (Node<int>* child : node->children) {
//         if (!isBalancedBinaryTree(child)) {
//             return false;
//         }
//     }

//     return true;
// }

// int main() {
//     int N;
//     std::cin >> N;

//     std::vector<Node<int>*> nodes(N);
//     for (int i = 0; i < N; i++) {
//         nodes[i] = new Node<int>(i);
//     }

//     for (int i = 0; i < N - 1; i++) {
//         int x, y;
//         std::cin >> x >> y;

//         nodes[x]->children.push_back(nodes[y]);
//     }

//     bool isBalanced = isBalancedBinaryTree(nodes[0]);
//     if (isBalanced) {
//         std::cout << "yes" << std::endl;
//     } else {
//         std::cout << "no" << std::endl;
//     }

//     // Giải phóng bộ nhớ
//     for (Node<int>* node : nodes) {
//         delete node;
//     }

//     return 0;
// }


// int getHeight(BST *root){
//         if (!root)
//             return 0;
//         return root -> height;
//     }

//     int getBalanceFactor(BST *root){
//         if (!root)
//             return 0;
//         return getHeight(root -> left) - getHeight(root -> right);
//     }






//     #include <iostream>
// #include <vector>

// using namespace std;

// class Node
// {
// public:
//     int data;
//     vector<Node *> children;

//     Node(int value)
//     {
//         data = value;
//     }
// };

// // bool isBinaryTree(Node* node) {
// //     if (node == NULL) return true;

// //     if (node->children.size() > 2) return false;

// //     for (Node* child : node->children) {
// //         if (!isBinaryTree(child)) {
// //             return false;
// //         }
// //     }

// //     return true;
// // }

// int solveheight(Node *node)
// {
//     if (node == NULL)
//         return 0;
//     int h = 0;
//     for (Node *child : node->children)
//     {
//         h = max(h, solveheight(child));
//     }
//     return h + 1;
// }

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

// bool isBalancedBinaryTree(Node *node)
// {
//     if (node == NULL)
//         return true;

//     int maxh = 0;
//     int minh = 1e9 + 1;

//     for (Node *child : node->children)
//     {
//         int height = solveheight(child);
//         maxh = max(maxh, height);
//         minh = min(minh, height);
//     }

//     if (maxh - minh > 1)
//         return false;

//     for (Node *child : node->children)
//     {
//         if (!isBalancedBinaryTree(child))
//         {
//             return false;
//         }
//     }
//     return true;
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<Node *> nodes(n);
//     for (int i = 0; i < n; i++)
//     {
//         nodes[i] = new Node(i);
//     }

//     for (int i = 0; i < n - 1; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         nodes[x]->children.push_back(nodes[y]);
//     }

//     bool isBinary = isBalancedBinaryTree(nodes[0]);
//     if (isBinary)
//         cout << "yes" << endl;
//     else
//         cout << "no" << endl;

//     return 0;
// }





// #include <iostream>
// #include <vector>

// template <class Item>
// class Node {
// public:
//     Item data;
//     std::vector<Node<Item>*> children;

//     Node(Item value) {
//         data = value;
//     }
// };

// // Hàm kiểm tra xem cây có phải là cây nhị phân đầy đủ hay không
// bool isFullBinaryTree(Node<int>* node) {
//     if (node == nullptr) {
//         return true;
//     }
    
//     // Kiểm tra đỉnh có 0 hoặc 2 đỉnh con
//     if (node->children.size() != 0 && node->children.size() != 2) {
//         return false;
//     }

//     for (Node<int>* child : node->children) {
//         if (!isFullBinaryTree(child)) {
//             return false;
//         }
//     }

//     return true;
// }

// int main() {
//     int N;
//     std::cin >> N;

//     std::vector<Node<int>*> nodes(N);
//     for (int i = 0; i < N; i++) {
//         nodes[i] = new Node<int>(i);
//     }

//     for (int i = 0; i < N - 1; i++) {
//         int x, y;
//         std::cin >> x >> y;

//         nodes[x]->children.push_back(nodes[y]);
//     }

//     bool isFullBinary = isFullBinaryTree(nodes[0]);
//     if (isFullBinary) {
//         std::cout << "yes" << std::endl;
//     } else {
//         std::cout << "no" << std::endl;
//     }

//     // Giải phóng bộ nhớ
//     for (Node<int>* node : nodes) {
//         delete node;
//     }

//     return 0;
// }

#include <iostream>

using namespace std;

class Heap {
public:
  Heap (int size) : current_size_(0), size_(size), arr_(new int [size]) {}

  // Insert a new value to the heap
  void insert (const int value) {
    if (current_size_ < size_) {
      arr_[current_size_] = value;
      current_size_++;
      if (current_size_ == size_) convertArrayIntoHeap();
    }
    else cout << "\nThe heap is full.\n";
  }

  // Retrieves the value store at the root of the tree
  int top () {
    return arr_[0];
  }

  // Extract the root value of the tree and return it as result
  int pop () {
    swap(arr_[0], arr_[current_size_ - 1]);
    heapify(current_size_ - 1, 0);
    current_size_--;

    return arr_[current_size_];
  }

private:
  // Convert a simple array in a Heap
  void convertArrayIntoHeap () {
    // Just need to process the node with children
    for (int i = current_size_ / 2 - 1; i >= 0; i--) {
      heapify(current_size_, i);
    }
  }

  /*
    Compares a node with his left and right value, if one of them is greather
    than the node value, swap the content between them and recursively does the
    same with the swaped node.
  */
  void heapify (int size, int i) {
    int max_value = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (left < size && arr_[left] > arr_[max_value]) max_value = left;
    if (right < size && arr_[right] > arr_[max_value]) max_value = right;
    if (max_value != i) {
      swap(arr_[i], arr_[max_value]);
      heapify(size, max_value);
    }
  }

  int* arr_;
  int current_size_;
  int size_;
};

int main () {
  int size, value;
  cin >> size;

  Heap heap(size);
  for (size_t i = 0; i < size; i++) {
    cin >> value;
    heap.insert(value);
  }

  for (size_t i = 0; i < size; i++) {
    cout << heap.pop() << ' ';
  }
}