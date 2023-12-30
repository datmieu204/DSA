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

tree *TreeSearch( int x, tree *root)
{
    if (root == NULL || root->val == x)
    {
        return root;
    }

    if (x < root->val)
    {
        return TreeSearch(x, root->left);
    }
    else
    {
        return TreeSearch(x, root->right);
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

int main() {
    tree *root = NULL;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        insert(root, x);
    }

    inorderTraversal(root);
    cout << endl;

    int x;
    cin >> x;

    tree *res = TreeSearch(x, root);

    if (res == NULL){
        cout << "Not found" << endl;
    } else {
        cout << "Found" << endl;
    }

    free(root);
    return 0;
}