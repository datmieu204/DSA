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
*/

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
    //int initialNumbers[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    //int initialSize = 9;

    int initialNumbers[] = {14, 15, 35, 62, 29, 42, 40, 80, 59, 23, 46, 57, 3, 19 };
    int initialSize = 14;

    for (int i = 0; i < initialSize; i++)
    {
        insert(root, initialNumbers[i]);
    }

    cout << "Initial Binary Search Tree:" << endl;
    inorderTraversal(root);
    cout << endl;

    // Inserting values: 14, 0, 35
    // insert(root, 14);
    // insert(root, 0);
    // insert(root, 35);

    // cout << "Binary Search Tree after Insertion:" << endl;
    // inorderTraversal(root);
    // cout << endl;

    // // Deleting values: 6, 13, 35
    remove(root, 12);
    remove(root, 42);
    remove(root, 13);

    cout << "Binary Search Tree after Deletion:" << endl;
    inorderTraversal(root);
    cout << endl;

    free(root);

    return 0;
}