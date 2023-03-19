#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int* Array;
    int Front, rear, currentSize, MaxSize;
public:
    Queue(int Size = 100)
    {
        MaxSize = Size;
        Array = new int[MaxSize];
        Front = -1;
        rear = -1;
        currentSize = 0;
    }
    void enqueue (int val)
    {
        if(Front == -1)
        {
            Front = rear;
        }
        rear = (rear+1) % MaxSize;
        Array[rear] = val;
        currentSize++;
    }
    int dequeue ()
    {
        if (Front == -1)
        {
            throw new exception;
        }
        int returned = Array[Front];
        Front = (Front+1) % MaxSize;
        currentSize--;
        return returned;
    }
    int getFront()
    {
        if (Front == -1)
        {
            throw new exception;
        }
        return Array[Front];
    }
    int getBack()
    {
        if (rear == -1)
        {
            throw new exception;
        }
        return Array[rear];

    }
    int getSize()
    {
        return currentSize;
    }
    void QueueEmpty()
    {
        currentSize = 0;
    }
    void print()
    {
        for(int i = Front ; i < currentSize ; i++)
        {
            cout << Array[i]<<endl;
        }
    }
    ~Queue()
    {
        delete []Array;
    }
};
class Stack
{
private:
    Queue q;
    int Size;
public:
    //push the value at the end of the stack
    //one by one dequeue stack items from queue and enqueue them
    void push(int value)
    {
        Size = q.getSize();
        q.enqueue(value);
        while(Size--)
        {
            q.enqueue(q.getFront());
            q.dequeue();
        }
    }
    //dequeue from first
    void pop()
    {
        q.dequeue();
    }
    //return the last input item in the stack
    int top ()
    {
        if (q.getSize()== 0)
            return -1;
        else
            return q.getFront();
    }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    cout<<s.top()<<endl;
    s.pop();
    s.pop();
    cout<<s.top()<<endl;
    return 0;
}
