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
    if (root == NULL) return 0;
    
    int maxHeight = 0;
    for (Tree *child : root->children) maxHeight = max(maxHeight, height(child));

    return maxHeight + 1;
}

bool isBalancedBinaryTree(Tree *node)
{
    if (node == NULL) return true;

    int maxh = 0;
    int minh = 1e9 + 1;

    for (Tree *child : node->children)
    {
        int h = height(child);
        maxh = max(maxh, h);
        minh = min(minh, h);
    }

    if (maxh - minh > 1) return false;

    for (Tree *child : node->children)
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
    vector<Tree *> nodes(n);

    for (int i = 0; i < n; i++)
    {
        nodes[i] = new Tree(i);
    }

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        nodes[x]->children.push_back(nodes[y]);
    }

    Tree *root = nodes[0];

    bool isBalancedBinary = isBalancedBinaryTree(root);
    if (isBalancedBinary)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}