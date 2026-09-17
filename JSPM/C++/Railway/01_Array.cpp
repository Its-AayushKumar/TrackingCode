#include <iostream>
using namespace std;

#define MAX 5

class Queue
{
    int queue[MAX];
    int front, rear;

public:
    
    Queue()
    {
        front = -1;
        rear = -1;
    }

    
    void enqueue(int ticketNo)
    {
        if (rear == MAX - 1)
        {
            cout << "Queue is full.\n";
            return;
        }

        if (front == -1)
            front = 0;

        queue[++rear] = ticketNo;

        cout << "Customer " << ticketNo
             << " joined the queue.\n";
    }

  
    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Customer " << queue[front]
             << " served and removed.\n";

        front++;

        if (front > rear)
            front = rear = -1;
    }

    
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Customers in queue: ";

        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";

        cout << endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);

    q.display();

    q.dequeue();

    q.display();

    return 0;
}