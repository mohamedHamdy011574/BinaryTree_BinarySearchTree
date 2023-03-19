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
    bool isSymmetricInternal(TreeNode *leftNode,TreeNode *rightNode)
    {
        if(leftNode == NULL && rightNode == NULL)
        {
            return true;
        }
        if((leftNode != NULL && rightNode != NULL )&&(leftNode->val == rightNode->val))
        {
           return((isSymmetricInternal(leftNode->left,rightNode->right))&&(isSymmetricInternal(leftNode->right,rightNode->left)));
        }
            return false;
    }
    bool isSymmetric(TreeNode* root)
    {
        if(root == NULL)
        {
            return true;
        }
        return isSymmetricInternal(root->left, root->right);
    }
};
int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    if (s.isSymmetric(root))
        cout << "Symmetric"<<endl;
    else
        cout << "Not symmetric"<<endl;

    /////////////////////////////

    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->right = new TreeNode(3);
    root1->right->right = new TreeNode(3);

    if (s.isSymmetric(root1))
        cout << "Symmetric"<<endl;
    else
        cout << "Not symmetric"<<endl;

    ///////////////////////////

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->right = new TreeNode(3);
    root2->right->left = new TreeNode(3);

    if (s.isSymmetric(root2))
        cout << "Symmetric"<<endl;
    else
        cout << "Not symmetric"<<endl;


    delete root;
    delete root1;
    delete root2;
    return 0;
}
