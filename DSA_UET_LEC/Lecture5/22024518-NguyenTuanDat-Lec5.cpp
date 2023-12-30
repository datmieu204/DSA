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