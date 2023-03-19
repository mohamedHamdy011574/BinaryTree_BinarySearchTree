#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
        right(right) {}
};
class Solution
{
public:
    bool isSameTree(TreeNode* k, TreeNode* l)
    {
        if((k==NULL&&l!=NULL)||(l==NULL&&k!=NULL))
        {
            return false;
        }
        if(k==NULL&&l==NULL)
        {
            return true;
        }
        if(k->val!=l->val)
        {
            return false;
        }
        else
        {
            isSameTree(k->left,l->left);
            isSameTree(k->right,l->right);
        }
    }
};

int main()
{
    Solution obj;
    // bool flag;
    TreeNode *root1=new TreeNode(1);
    root1->left=new TreeNode(2);
    root1->right=new TreeNode(3);
    TreeNode *root2=new TreeNode(1);
    root2->left=new TreeNode(2);
    root2->right=new TreeNode(3);
    /////////////////////
    TreeNode *root3=new TreeNode(1);
    root3->left=new TreeNode(2);
    TreeNode *root4=new TreeNode(1);
    root4->right=new TreeNode(2);
    ///////////////////////////
    TreeNode *root5=new TreeNode(1);
    root5->right=new TreeNode(1);
    root5->left=new TreeNode(2);
    TreeNode *root6=new TreeNode(1);
    root4->right=new TreeNode(2);
    root4->left=new TreeNode(1);
    /////////////////////////
    TreeNode *root7=new TreeNode(10);
    root7->right=new TreeNode(15);
    root7->left=new TreeNode(9);
    TreeNode *root8=new TreeNode(11);
    root8->right=new TreeNode(6);
    root8->left=new TreeNode(1);
    ////////////////////////////
    TreeNode *root9=new TreeNode(18);
    root9->right=new TreeNode(6);
    root9->left=new TreeNode(20);
    TreeNode *root10=new TreeNode(18);
    root10->right=new TreeNode(6);
    root10->left=new TreeNode(20);
    cout<<obj.isSameTree(root1,root2)<<endl;
    cout<<obj.isSameTree(root3,root4)<<endl;
    cout<<obj.isSameTree(root5,root6)<<endl;
    cout<<obj.isSameTree(root7,root8)<<endl;
    cout<<obj.isSameTree(root9,root10)<<endl;
    delete root1;
    delete root2;
    delete root3;
    delete root4;
    delete root5;
    delete root6;
    delete root7;
    delete root8;
    delete root9;
    delete root10;


    return 0;
}
