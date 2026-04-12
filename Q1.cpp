#include <iostream>
using namespace std;

bool canTurnOff(string &s, int n, int k, int l)
{
    int ops = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            ops++;
            if (ops > k)
                return false;
            i += l - 1;
        }
    }
    return true;
}

int main()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int low = 1, high = n;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (canTurnOff(s, n, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << ans;

    return 0;
}