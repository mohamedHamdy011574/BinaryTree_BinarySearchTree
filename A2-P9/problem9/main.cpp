#include <iostream>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        val = 0;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int x, TreeNode *left, TreeNode *right)
    {
        val = x;
        left = left;
        right = right;
    }
};
class Solution
{
public:
    bool isFoldableInternal(TreeNode *leftNode,TreeNode *rightNode)
    {
        if(leftNode == NULL && rightNode == NULL)
        {
            return true;
        }
        if(leftNode == NULL || rightNode == NULL)
        {
            return false;
        }
        return(isFoldableInternal(leftNode->left,rightNode->right)&&isFoldableInternal(leftNode->right,rightNode->left));
    }
    bool isFoldable(TreeNode* root)
    {
        if(root == NULL)
        {
            return false;
        }
        return isFoldableInternal(root->left, root->right);
    }
};
int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(3);

    if (s.isFoldable(root))
        cout << "Foldable"<<endl;
    else
        cout << "Not Foldable"<<endl;

    ///////////////////////

    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(5);
    root1->right->right = new TreeNode(4);

    if (s.isFoldable(root1))
        cout << "Foldable"<<endl;
    else
        cout << "Not Foldable"<<endl;

    ///////////////////////

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(6);
    root2->right->right = new TreeNode(5);

    if (s.isFoldable(root2))
        cout << "Foldable"<<endl;
    else
        cout << "Not Foldable"<<endl;

    ///////////////////////

    TreeNode *root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->left->left = new TreeNode(4);
    root3->left->right = new TreeNode(6);
    root3->right->left = new TreeNode(5);

    if (s.isFoldable(root3))
        cout << "Foldable"<<endl;
    else
        cout << "Not Foldable"<<endl;

    ///////////////////////

    TreeNode *root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(3);
    root4->left->left = new TreeNode(4);
    root4->right->left = new TreeNode(5);

    if (s.isFoldable(root4))
        cout << "Foldable"<<endl;
    else
        cout << "Not Foldable"<<endl;

    /////////////////////////

    delete root;
    delete root1;
    delete root2;
    delete root3;
    delete root4;
    return 0;
}
