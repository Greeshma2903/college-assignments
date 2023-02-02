#include <iostream>
#include <iomanip>
using namespace std;
int mutex = 1, full = 0, empty, in = 0, out = 0, counter = 0;
int buffer_size;
int buffer[100];
int signal(int S)
{
    S++;
}
int wait(int S)
{
    while (S < 0)
    {
        cout << endl
             << "Cannot add an item";
        return 0;
    }
    S--;
}
void produce()
{
    wait(empty);
    wait(mutex);
    int next_prod;
    if (counter == buffer_size)
    {
        cout << "Storage full";
    }
    else
    {
        cout << "Enter an item to produce: ";
        cin >> next_prod;
        buffer[in] = next_prod;
        in = (in + 1) % buffer_size;
        cout << "Item produced: " << next_prod;
        counter++;
    }
    signal(mutex);
    signal(full);
}
void consume()
{
    wait(full);
    wait(mutex);
    int next_cons;
    if (counter == 0)
    {
        cout << "Storage empty" << endl;
    }
    else
    {
        next_cons = buffer[out];
        out = (out + 1) % buffer_size;
        cout << "Item consumed: " << next_cons;
        counter--;
    }
    signal(mutex);
    signal(empty);
}
int main()
{
    int choice;
    cout << "Enter buffer size: ";
    cin >> buffer_size;
    empty = buffer_size;
    do
    {
        cout << endl
             << endl
             << "Select the operation to be performed: 1.Produce 2.Consume 3.  Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            produce();
            break;
        case 2:
            consume();
            break;
        case 3:
            break;
        default:
            cout << "Select a valid option" << endl;
        }
    } while (choice != 3);
    return 0;
}
