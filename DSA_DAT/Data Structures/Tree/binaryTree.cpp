// cây nhị phân hoàn chỉnh (completeBinaryTree): tất cả các mức đều đầy, trừ mức cuối cùng có thể thiếu các nút ở bên phải
// cây nhị phân đầy đủ (fullBinaryTree): mỗi đỉnh có đúng 2 con hoặc 0 con, điền đầy hết tầng từ trái sang phải
// cây nhị phân hoàn toàn (perfectBinaryTree): tất cả các node đều có 2 con và các node lá đều ở cùng cấp (hoàn chỉnh , hoàn hảo, hoàn toàn)
// cây nhị phân cân bằng (balancedBinaryTree): cây có độ cao nhỏ hơn hoặc bằng log2(n+1), độ cao chênh nhau không quá 1
// cay nhị phân hoàn hảo là cây có độ sâu các lá là như nhau
// là các cây con tại mỗi đỉnh chứa các đường đi có độ dài như nhau
// tất cả các lá đều ở mức h hoặc h-1
// h max = n-1
// h min = log2(n)

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
    if (root == NULL)
    {
        return 0;
    }

    int maxHeight = 0;
    for (Tree *child : root->children)
    {
        maxHeight = max(maxHeight, height(child));
    }

    return maxHeight + 1;
}

bool checkBinaryTree(Tree *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->children.size() > 2)
    {
        return false;
    }

    for (Tree *child : root->children)
    {
        if (!checkBinaryTree(child))
        {
            return false;
        }
    }

    return true;
}

bool isFullBinaryTree(Tree *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->children.size() == 0)
    {
        return true;
    }
    else if (root->children.size() == 2)
    {
        return isFullBinaryTree(root->children[0]) && isFullBinaryTree(root->children[1]);
    }
    else
    {
        return false;
    }
}

bool isBalancedBinaryTree(Tree *node)
{
    if (node == NULL)
        return true;

    int maxh = 0;
    int minh = 1e9 + 1;

    for (Tree *child : node->children)
    {
        int h = height(child);
        maxh = max(maxh, h);
        minh = min(minh, h);
    }

    if (maxh - minh > 1)
        return false;

    for (Tree *child : node->children)
    {
        if (!isBalancedBinaryTree(child))
        {
            return false;
        }
    }
    return true;
}

bool checkCompleteBinaryTree(Tree *root)
{
    return true;
}

void free(vector<Tree*> nodes)
{
    for(Tree* child : nodes){
        delete child;
    }
}

int main(){
    int n; cin >> n;
    vector<Tree*> nodes(n);

    for(int i = 0; i < n; i++){
        nodes[i] = new Tree(i);
    }

    for(int i = 0; i < n - 1; i++){
        int x, y; cin >> x >> y;
        nodes[x]->children.push_back(nodes[y]);
    }

    Tree* root = nodes[0];

    bool isBinary = checkBinaryTree(root);
    if(isBinary) cout << "yes" << endl;
    else cout << "no" << endl;
}