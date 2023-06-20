#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Queue {
    public:
        int front, rear, size;
        unsigned capacity;
        int * array;
};

Queue * createQueue(unsigned capacity)
{
    Queue * queue = new Queue();
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity -1;
    queue->array = new int[queue->capacity];
    return queue;
}

int isFull(Queue * queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(Queue * queue)
{
    return (queue->size == 0);
}

void enqueue(Queue * queue, int item){
    if (isFull(queue))
    {
        cout << "Queue full" << endl;
        return;
    }

    else {
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->array[queue->rear] = item;
        queue->size = queue->size + 1;
        cout << item << " enqueued to queue" << endl;
    }
}

int dequeue(Queue * queue)
{
    if (isEmpty(queue))
    {
        cout << "Queue empty\n";
        return INT_MIN;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(Queue * queue)
{
    if (isEmpty(queue))
    {
        return INT_MIN;
    }
    return queue->array[queue->front];
}

int rear(Queue * queue)
{
    if (isEmpty(queue))
    {
        return INT_MIN;
    }
    return queue->array[queue->rear];
}



int main(int argc, char * argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Queue * q = createQueue(1000);

    enqueue(q, 43);
    enqueue(q, 32);
    enqueue(q, 23);
    enqueue(q, 123);

    cout << dequeue(q) << endl;
    cout << front(q) << endl;
    cout << rear(q) << endl;
    return 0;
}