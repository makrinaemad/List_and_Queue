#include <iostream>
using namespace std;

class Queue
{
private:
    struct node
    {
        int item;
        node* next;
    };
    int length;
    node* front, * rear;
public:
    Queue()
    {
        front = rear = NULL;
        length = 0;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    void push(int value)
    {
        node* newnode = new node;
        newnode->item = value;
        newnode->next = NULL;
        if (length == 0)
            rear = front = newnode;
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
        length++;
    }

    void pop()
    {
        if (isEmpty())
            exit(EXIT_FAILURE);
        else if (length == 1)
        {
            delete front;
            front = rear = NULL;
        }
        else
        {
            node* temp = front;
            front = front->next;
            delete temp;
        }
        length--;
    }

    int Front()
    {
        if (isEmpty())
            exit(EXIT_FAILURE);
        else
            return front->item;
    }

    int Qsize()
    {
        return length;
    }

};


int main() {
    int n, x, k;
    Queue q1, q2;

    cout << "N = ";
    cin >> n;
    cout << "Tickets = ";
    while (n--) {
        cin >> x;
        q1.push(x);
    }
    cout << "K = ";
    cin >> k;

    int sec = 0, tickets = 0, i = 0;
    while (q1.Qsize()) {
        if (i < k) {
            q2.push(q1.Front());
        }
        else if (i == k) {
            tickets = q1.Front();
            sec += tickets;
        }
        else {
            if (q1.Front() < tickets)
                sec += q1.Front();
            else
                sec += tickets - 1;
        }
        q1.pop();
        i++;
    }
    while (q2.Qsize()) {
        if (q2.Front() <= tickets)
            sec += q2.Front();
        else
            sec += tickets;
        q2.pop();
    }

    cout << sec << " Sec\n";
    return 0;

}
