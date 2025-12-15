#include <iostream>
#include "Queue.h"

using namespace std;
void menu()
{
    cout << "WELCOME TO THE QUEUE PROGRAM!" << endl;
    cout << "1. ENQUEUE" << endl;
    cout << "2. DEQUEUE" << endl;
    cout << "3. Display" << endl;
    cout << "4. Length" << endl;
    cout << "5. Front" << endl;
    cout << "6. Rear" << endl;
    cout << "7. EXIT" << endl;
}
int main()
{
    Queue q;
    int choice;
    while (true)
    {
        system("clear");
        menu();
        cout << "\nEnter your choice [1/2/3/4/5/6/7]: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "\nYOU SELECTED ENQUEUE OPERATION\n"
                 << endl;
            int value;
            cout << "ENTER VALUE TO ENQUEUE: ";
            cin >> value;
            q.push(value);
            cout << "\nEnqueue✅! Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
        case 2:
        {
            cout << "\nYOU SELECTED DEQUEUE OPTION\n"
                 << endl;
            int data = q.pop();
            cout << "\nENQUEUE✅! DATA =" << data << " Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
        case 3:
        {
            cout << "\nYOU SELECTED DISPLAY_LIST OPTION\n"
                 << endl;
            q.display();
            cout << "\n\nDISPLAY_QUEUE✅! Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
        case 4:
        {
            cout << "\nYOU SELECTED GET_LENGTH OPTION\n"
                 << endl;
            cout << q.get_length();
            cout << "\n\nGET_LENGTH✅! Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
        case 5:
        {
            cout << "\nYOU SELECTED GET_FRONT OPTION\n"
                 << endl;
            cout << q.get_front();
            cout << "\n\nGET_FRONT✅! Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
        case 6:
        {
            cout << "\nYOU SELECTED GET_REAR OPTION\n"
                 << endl;
            cout << q.get_rear();
            cout << "\n\nGET_REAR✅! Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
        case 7:
        {
            cout << "\nTHANK YOU FOR USING OUR QUEUE PROGRAM🎉\n"
                 << endl;
            return 0;
        }
        default:
        {
            cout << "INVALID CHOICE❌! PLEASE TRY AGAIN." << endl;
            cout << "\nPress any key to continue...";
            cin.ignore();
            cin.get();
        }
        }
    }

    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // cout << "POPPED DATA: " << q.pop() << endl;
    // cout << "FRONT: " << q.get_front() << endl;
    // cout << "REAR: " << q.get_rear() << endl;
    // cout << "=========================" << endl;
    // q.display();
    // cout << "\n=========================" << endl;
    return 0;
}