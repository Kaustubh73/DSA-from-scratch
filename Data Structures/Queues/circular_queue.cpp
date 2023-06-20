#include <bits/stdc++.h>
using namespace std;

class CircleQ
{
    int rear, front;
    int size;
    int *arr;
    public:
        CircleQ(int s)
        {
            front = rear = -1;
            size =s;
            arr = new int[s];
        }

        void enqueue(int x)
        {
            if ((front == 0&& rear == size -1) || (rear == (front - 1) % (size -1))) {
                cout << "Queue full \n";
                return;
            }

            else if (front == -1)
            {
                front = rear = 0;
                arr[rear] = x;
            }

            else if (rear == size - 1 && front != 0)
            {
                rear = 0;
                arr[rear] = x;
            }
            else 
            {
                rear++;
                arr[rear] = x;
            }
        }

        int dequeue() {
            if (front == -1)
            {
                cout << "Queue empty" << endl;
                return INT_MIN;
            }

            int data = arr[front];
            arr[front] = -1;
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }

            else if (front == size - 1)
            {
                front = 0;
            }
            else
                front++;
            return data;
        }

        void displayQueue() {
            if (front == -1)
            {
                cout << "Queue empty\n";
            }

            cout << "Elements: ";
            if (rear >= front)
            {
                for (int i = front ; i <= rear; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
            else {
                for (int i = front ; i < size ; i++)
                {
                    cout << arr[i] << " ";
                }
                for (int i = 0 ; i <= rear; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
};

int main()
{
    CircleQ q(5);

    q.enqueue(14);
    q.enqueue(22);
    q.enqueue(13);
    q.enqueue(-6);
  
    // Display elements present in Circular Queue
    q.displayQueue();
  
    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", q.dequeue());
    printf("\nDeleted value = %d", q.dequeue());
  
    q.displayQueue();
  
    q.enqueue(9);
    q.enqueue(20);
    q.enqueue(5);
  
    q.displayQueue();
  
    q.enqueue(20);
    return 0;
}