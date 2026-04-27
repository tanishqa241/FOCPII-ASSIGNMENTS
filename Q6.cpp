#include <iostream>
#include <string>
using namespace std;

class Bank
{
private:
    int balance[101];

public:

    Bank()
    {
        for(int i = 0; i <= 100; i++)
        {
            balance[i] = -1;   // means account not created
        }
    }

    bool CREATE(int X, int Y)
    {
        if(balance[X] == -1)
        {
            balance[X] = Y;
            return true;
        }
        else
        {
            balance[X] = balance[X] + Y;
            return false;
        }
    }

    bool DEBIT(int X, int Y)
    {
        if(balance[X] == -1 || balance[X] < Y)
        {
            return false;
        }
        else
        {
            balance[X] = balance[X] - Y;
            return true;
        }
    }

    bool CREDIT(int X, int Y)
    {
        if(balance[X] == -1)
        {
            return false;
        }
        else
        {
            balance[X] = balance[X] + Y;
            return true;
        }
    }

    int BALANCE(int X)
    {
        return balance[X];
    }
};

int main()
{
    Bank obj;

    int Q;
    cout << "Enter number of queries: ";
    cin >> Q;

    for(int i = 1; i <= Q; i++)
    {
        string choice;

        cout << "\nEnter Query " << i << ": ";
        cin >> choice;

        if(choice == "CREATE")
        {
            int X, Y;
            cin >> X >> Y;

            if(obj.CREATE(X, Y))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if(choice == "DEBIT")
        {
            int X, Y;
            cin >> X >> Y;

            if(obj.DEBIT(X, Y))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if(choice == "CREDIT")
        {
            int X, Y;
            cin >> X >> Y;

            if(obj.CREDIT(X, Y))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if(choice == "BALANCE")
        {
            int X;
            cin >> X;

            cout << obj.BALANCE(X) << endl;
        }

        else
        {
            cout << "Invalid Query" << endl;
        }
    }

    return 0;
}