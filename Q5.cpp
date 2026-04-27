#include <iostream>
#include <string>
using namespace std;

class MovieTicket
{
private:
    int ticket[101][101];
    int booked[101];

public:

    MovieTicket()
    {
        for(int i=0; i<=100; i++)
        {
            booked[i] = 0;

            for(int j=0; j<=100; j++)
            {
                ticket[i][j] = 0;
            }
        }
    }

    bool BOOK(int X, int Y)
    {
        if(ticket[Y][X] == 1 || booked[Y] == 100)
            return false;

        ticket[Y][X] = 1;
        booked[Y]++;

        return true;
    }

    bool CANCEL(int X, int Y)
    {
        if(ticket[Y][X] == 0)
            return false;

        ticket[Y][X] = 0;
        booked[Y]--;

        return true;
    }

    bool IS_BOOKED(int X, int Y)
    {
        if(ticket[Y][X] == 1)
            return true;
        else
            return false;
    }

    int AVAILABLE_TICKETS(int Y)
    {
        return 100 - booked[Y];
    }
};

int main()
{
    MovieTicket obj;

    int Q;
    cout << "Enter number of queries: ";
    cin >> Q;

    for(int i=1; i<=Q; i++)
    {
        string choice;

        cout << "\nEnter Query " << i << ": ";
        cin >> choice;

        if(choice == "BOOK")
        {
            int X, Y;
            cin >> X >> Y;

            if(obj.BOOK(X, Y))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if(choice == "CANCEL")
        {
            int X, Y;
            cin >> X >> Y;

            if(obj.CANCEL(X, Y))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if(choice == "IS_BOOKED")
        {
            int X, Y;
            cin >> X >> Y;

            if(obj.IS_BOOKED(X, Y))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if(choice == "AVAILABLE_TICKETS")
        {
            int Y;
            cin >> Y;

            cout << obj.AVAILABLE_TICKETS(Y) << endl;
        }

        else
        {
            cout << "Invalid Query" << endl;
        }
    }

    return 0;
}