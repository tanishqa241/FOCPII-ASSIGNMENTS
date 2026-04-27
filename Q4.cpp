#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        map<int, int, greater<int>> mp;

        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }

        long long alex = 0, bob = 0;
        bool turn = true; // Alex starts

        for (auto it : mp)
        {
            int val = it.first;
            int freq = it.second;

            int times = min(freq, 2);

            for (int i = 0; i < times; i++)
            {
                if (turn)
                    alex += val;
                else
                    bob += val;

                turn = !turn;
            }
        }

        if (alex > bob)
            cout << "Alex\n";
        else
            cout << "Bob\n";
    }

    return 0;
}