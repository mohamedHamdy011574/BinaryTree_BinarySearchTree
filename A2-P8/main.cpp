# include <iostream>
#include <string>
using namespace std;
 static int preIndex = 0;
class node
{
public:
    char data;
    node* left;
    node* right;
};
node* createNode(char data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return Node;
}
//search for specific items in inorder array
int Search(string arr, int startIn, int endIn, char value)
{
    int i;
    for (i = startIn; i <= endIn; i++)
    {
        if (arr[i] == value)
            return i;
    }
}
//build the tree from the inorder and preorder
node* build(string inorder,string preorder,int startIn,int endIn)
{
    if (startIn > endIn)
    {
        return NULL;
    }
    node* treeNode = createNode(preorder[preIndex++]);
    if (startIn == endIn)
    {
        return treeNode;
    }
    int inIndex = Search(inorder, startIn, endIn, treeNode->data);
    treeNode->left = build(inorder, preorder, startIn, inIndex - 1);
    treeNode->right = build(inorder, preorder, inIndex + 1, endIn);
    return treeNode;
}
void print(node* root)
{
    if (root == NULL)
        return;
    print(root->left);
    print(root->right);
    cout << root->data;
}
//print postorder
node* printPostorder(string inorder,string preorder)
{
    node* root = build(inorder, preorder, 0, inorder.size()-1);
    print(root);
    return root;
}

int main()
{
    //TEST CASE 1
    string inorder = "FBGAC";
    string preorder = "ABFGC";
    cout << "postorder traversal \n";
    printPostorder(inorder,preorder);
    cout << endl;
    preIndex = 0;
    //TEST CASE 2
    string inorder1 = "BADC";
    string preorder1 = "ABCD";
    cout << "postorder traversal \n";
    printPostorder(inorder1,preorder1);
    cout << endl;
    preIndex = 0;
    //TEST CASE 3
    string inorder2 = "BAC";
    string preorder2 = "ABC";
    cout << "postorder traversal \n";
    printPostorder(inorder2,preorder2);
    cout << endl;
    preIndex = 0;
    //TEST CASE 4
    string inorder3 = "HDIBEAFJCKGL";
    string preorder3 = "ABDHIECFJGKL";
    cout << "postorder traversal \n";
    printPostorder(inorder3,preorder3);
    cout << endl;
    preIndex = 0;
    //TEST CASE 5
    string inorder4 = "DBEAC";
    string preorder4 = "ABDEC";
    cout << "postorder traversal \n";
    printPostorder(inorder4,preorder4);
    cout << endl;
    preIndex = 0;
    return 0;

}
