#include <iostream>
using namespace std;
class pizza_parlor
{
public:
    int count;
    int q[50], x, MAX;
    int rear;
    int front;
    pizza_parlor()
    {
        count = 0;
        front = 0;
        rear = -1;
        cout << "\n Maximum order accepted:";
        cin >> MAX;
    }
    void insert();
    void deleteQueue();
    void display();
} Parlor;

void pizza_parlor::insert()
{
    if (count == MAX)
    {
        cout << "\n Orders are full.";
    }
    else
    {
        cout << "\n Enter order id:";
        cin >> x;
        rear = (rear + 1) % MAX;
        q[rear] = x;
        count++;
        cout << "\n Order is placed.";
    }
}

void pizza_parlor::display()
{
    int i;
    cout << "\n Orders are:\n";
    i = front;
    do
    {
        cout << q[i]<<"\t";
        i = (i + 1) % MAX;
    } while (i != ((rear + 1) % MAX));
}

void pizza_parlor::deleteQueue()
{
    if (count == 0)
    {
        cout << "\n No order is placed.";
    }
    else
    {
        front = (front + 1) % MAX;
        count--;
        cout << "\n Order is delivered.";
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\n Menu:";
        cout << "\n 1)Place order";
        cout << "\n 2)Pending orders";
        cout << "\n 3)Deliver order";
        cout << "\n 4)Exit";

        cout << "\n Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Parlor.insert();
            break;
        case 2:
            Parlor.display();
            break;
        case 3:
            Parlor.deleteQueue();
            break;
        }
    } while (choice < 4);
}
