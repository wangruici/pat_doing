#include <iostream>
using namespace std;
const int maxn = 31;

int n, index = 0;
int pre[maxn], post[maxn];
bool flag = true;

struct Node {
    int data;
    Node *lchild, *rchild;
} *root;

Node *create(int preL, int preR, int postL, int postR) 
{
    if (preL > preR) return NULL;
    Node *node = new Node;
    node->data = pre[preL];
    node->lchild = NULL;
    node->rchild = NULL;
    if (preL == preR)
        return node;
    int k = 0;
    for (k = preL + 1; k <= preR; k++) 
    {
        if (pre[k] == post[postR - 1]) break;
    }
    if (k - preL > 1) 
    {
        node->lchild = create(preL + 1, k - 1, postL, postL + k - preL - 2);
        node->rchild = create(k, preR, postL + k - preL - 1, postR - 1);
    }
    else 
    {
        flag = false;
        node->rchild = create(k, preR, postL + k - preL - 1, postR - 1);
    }
    return node;
}

void inOrder(Node *node) 
{
    if (node == NULL) return;
    inOrder(node->lchild);
    if (index < n - 1)
        cout << node->data << " ";
    else cout << node->data << endl;
    index++;
    inOrder(node->rchild);
}

int main() 
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> pre[i];
    for (int i = 0; i < n; ++i) cin >> post[i];
    root = create(0, n - 1, 0, n - 1);
    if (flag) cout << "Yes\n";
    else cout << "No\n";
    inOrder(root);
    return 0;
}
