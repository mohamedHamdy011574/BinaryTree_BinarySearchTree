#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
class TreeNode
{
public:
    char data;
    TreeNode *left, *right;
    TreeNode(char data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class StackNode
{
public:
    TreeNode *treeNode;
    StackNode *next;
    StackNode(TreeNode *treeNode)
    {
        this->treeNode = treeNode;
        next = NULL;
    }
};
class ExpressionTree
{
private:
    StackNode *top;
public:
    ExpressionTree()
    {
        top = NULL;
    }
    void clear()
    {
        top = NULL;
    }
    void push(TreeNode *ptr)
    {
        if (top == NULL)
            top = new StackNode(ptr);
        else
        {
            StackNode *nptr = new StackNode(ptr);
            nptr->next = top;
            top = nptr;
        }
    }
    TreeNode *pop()
    {
        if (top == NULL)
        {
            cout<<"Underflow"<<endl;
        }
        else
        {
            TreeNode *ptr = top->treeNode;
            top = top->next;
            return ptr;
        }
    }
    // function to get top node
    TreeNode *peek()
    {
        return top->treeNode;
    }
    void insert(char val)
    {
        if (isDigit(val))
        {
            TreeNode *nptr = new TreeNode(val);
            push(nptr);
        }
        else if (isOperator(val))
        {
            TreeNode *nptr = new TreeNode(val);
            nptr->left = pop();
            nptr->right = pop();
            push(nptr);
        }
        else
        {
            cout<<"Invalid Expression"<<endl;
            return;
        }
    }
    bool isDigit(char ch)
    {
        return ch >= '0' && ch <= '9';
    }
    bool isOperator(char ch)
    {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }
    int toDigit(char ch)
    {
        return ch - '0';
    }
    void buildTree(string eqn)
    {
        for (int i = eqn.length() - 1; i >= 0; i--)
            insert(eqn[i]);
    }
    double evaluate()
    {
        return evaluate(peek());
    }

    /** function to evaluate tree */
    double evaluate(TreeNode *ptr)
    {
        if (ptr->left == NULL && ptr->right == NULL)
            return toDigit(ptr->data);
        else
        {
            double result = 0.0;
            double left = evaluate(ptr->left);
            double right = evaluate(ptr->right);
            char op = ptr->data;
            switch (op)
            {
            case '+':
                result = left + right;
                break;
            case '-':
                result = left - right;
                break;
            case '*':
                result = left * right;
                break;
            case '/':
                result = left / right;
                break;
            default:
                result = left + right;
                break;
            }
            return result;
        }
    }
};
int main()
{
    cout<<"Expression Tree Test"<<endl;
    //TEST CASE 1
    string s = "+3*4/82";
    ExpressionTree et;
    et.buildTree(s);
    cout<<"\n\nEvaluated Result : "<<et.evaluate();
    cout << endl;
    //TEST CASE 2
    string s1 = "-+8/632";
    ExpressionTree et1;
    et1.buildTree(s1);
    cout<<"\n\nEvaluated Result : "<<et1.evaluate();
    cout << endl;
    //TEST CASE 3
    string s2 = "-+7*45+20";
    ExpressionTree et2;
    et2.buildTree(s2);
    cout<<"\n\nEvaluated Result : "<<et2.evaluate();
    cout << endl;
    //TEST CASE 4
    string s3 = "+8*36";
    ExpressionTree et3;
    et3.buildTree(s3);
    cout<<"\n\nEvaluated Result : "<<et3.evaluate();
    cout << endl;
    //TEST CASE 5
    string s4 = "+9*26";
    ExpressionTree et4;
    et4.buildTree(s4);
    cout<<"\n\nEvaluated Result : "<<et4.evaluate();
    cout << endl;
    return 0;
}
