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

    if (maxh - minh == 0)
        return true;

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