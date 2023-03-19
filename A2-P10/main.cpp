#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node*right;
    Node*left;
    int Size;
    Node()
    {
        data=0;
        right=NULL;
        left=NULL;
        Size=0;
    }
    Node(int data)
    {
        this->data = data;
        this-> right=NULL;
        this->left=NULL;

    }
};

class BSTtree
{
    Node * root;
public:
    BSTtree(int data)
    {
        root= new Node(data);

    }
    BSTtree()
    {
        root=NULL;
    }
    void insert(int data)
    {


        if(root == NULL)
        {
            root = new Node(data);
            return;
        }

        insert(root,data);
    }
    void insert (Node *posotion,int value)
    {
        if(value < posotion->data)
        {
            if(posotion -> left == NULL)
            {
                posotion -> left = new Node(value);
            }
            else
            {
                insert( posotion -> left,value);
            }
        }

        else if(value > posotion->data)
        {
            if(posotion -> right == NULL)
            {
                posotion -> right = new Node(value);
            }
            else
            {
                insert( posotion -> right,value);
            }
        }
        if(value==posotion->data)
        {
            cout<<"cant insert this value this value aready exist "<<endl;
            return ;
        }

    }
    int finalResult(Node *root,int k,int&count)
    {

        if (root == NULL)
            return 0;
        if (count > k)
            return 0;
        int res = finalResult(root->left, k,count);
        if (count >= k)
            return res;
        res += root->data;
        //check again
        count++;
        if (count >= k)
            return res;

        // If count is less than k, return right subtree Nodes
        return res + finalResult(root->right, k,count);
    }
    int sumSmallestElement( int k)
    {
        int count = 0;
        finalResult(root, k, count);
    }
    void deleteRoot(Node*root)
    {
        if (root==NULL)
        {
            return;
        }
        deleteRoot(root->right);
        deleteRoot(root->left);
        delete root;
    }
    ~BSTtree()
    {
        deleteRoot(root);
    }
};
int main()
{
    BSTtree obj1(54);
    obj1.insert(51);
    obj1.insert(49);
    obj1.insert(52);
    obj1.insert(75);
    obj1.insert(74);
    obj1.insert(85);
    cout<<" 1 test case  "<<obj1.sumSmallestElement(3)<<endl;
    ///test case2
    BSTtree obj2(40);
    obj2.insert(30);
    obj2.insert(25);
    obj2.insert(35);
    obj2.insert(50);
    obj2.insert(45);
    obj2.insert(60);
    cout<<" 2 test case  "<<obj2.sumSmallestElement(2)<<endl;
    ///test case3
    BSTtree obj3(40);
    obj3.insert(30);
    obj3.insert(25);
    obj3.insert(35);
    obj3.insert(50);
    obj3.insert(45);
    obj3.insert(60);
    cout<<" 3 test case  "<<obj3.sumSmallestElement(3)<<endl;
    ///test case4
    BSTtree obj4(5);
    obj4.insert(2);
    obj4.insert(-4);
    obj4.insert(3);
    obj4.insert(18);
    cout<<" 4 test case  "<<obj4.sumSmallestElement(4)<<endl;
///test case5
    BSTtree obj5(5);
    obj5.insert(5);
    obj5.insert(-4);
    obj5.insert(3);
    obj5.insert(18);
    cout<<" 5 test case  "<<obj5.sumSmallestElement(4)<<endl;


    return 0;
}
