#include <iostream>

using namespace std;
template <class T>
class Queue
{
private:
    T* Array;
    int Front, rear, currentSize, MaxSize;
public:
    Queue(int Size)
    {
        MaxSize = Size;
        Array = new T[MaxSize];
        Front = -1;
        rear = -1;
        currentSize = 0;
    }
    void enqueue (T val)
    {
        if(Front == -1)
        {
            Front = rear;
        }
        rear = (rear+1) % MaxSize;
        Array[rear] = val;
        currentSize++;
    }
    T dequeue ()
    {
        if (Front == -1)
        {
            throw new exception;
        }
        T returned = Array[Front];
        Front = (Front+1) % MaxSize;
        currentSize--;
        return returned;
    }
    T getFront()
    {
        if (Front == -1)
        {
            throw new exception;
        }
        return Array[Front];
    }
    T getBack()
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
    T getTime(int k)
    {
        int Count = 0;
        while(true)
        {
            for(int i = 0 ; i <  getSize(); i++)
            {
                int x = getFront();
                dequeue();
                if(x != 0)
                {
                    x--;
                    Count++;
                }
                if(x == 0 && k == i)
                {
                    return Count;
                }
                enqueue(x);
            }
        }
    }
    void QueueEmpty()
    {
        return currentSize = 0;
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
int main()
{
    Queue<int> Q(10);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(2);
    cout << Q.getTime(2)<<" seconds "<<endl;

    //////////////////

    Queue<int> q(10);
    q.enqueue(5);
    q.enqueue(1);
    q.enqueue(1);
    q.enqueue(1);
    cout << q.getTime(0)<<" seconds "<<endl;

    //////////////////

    Queue<int> q1(10);
    q1.enqueue(3);
    q1.enqueue(1);
    q1.enqueue(1);
    q1.enqueue(1);
    cout << q1.getTime(1)<<" seconds "<<endl;


    ///////////////////

    Queue<int> q2(10);
    q2.enqueue(1);
    q2.enqueue(1);
    q2.enqueue(1);
    q2.enqueue(1);
    cout << q2.getTime(2)<<" seconds "<<endl;

    /////////////////

    Queue<int> q3(10);
    q3.enqueue(2);
    q3.enqueue(2);
    q3.enqueue(3);
    q3.enqueue(4);
    cout << q3.getTime(2)<<" seconds "<<endl;
    return 0;
}
