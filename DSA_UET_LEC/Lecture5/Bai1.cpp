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
    for (node *child : root->children)
    {
        maxHeight = max(maxHeight, height(child));
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

void postorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    for (node *child : root->children)
    {
        postorderTraversal(child);
    }

    cout << root->data << " ";
}

void inorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->children.size() >= 1)
    {
        inorderTraversal(root->children[0]);
    }

    cout << root->data << " ";

    if (root->children.size() == 2)
    {
        inorderTraversal(root->children[1]);
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

    if (isFullBinary)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "NOT BINARY TREE" << endl;
    }

    preorder(root);

    cout << endl;

    for (node *root : tree)
    {
        delete root;
    }

    return 0;
}