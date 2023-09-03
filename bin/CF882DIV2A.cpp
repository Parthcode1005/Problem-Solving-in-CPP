#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int y;
            cin >> y;
            a.push_back(y);
        }
        vector<int> bx;
        for (int i = 0; i < n - 1; i++)
        {
            // cout<<ax[i]<<" "<<ax[i+1]<<endl;
            bx.push_back(abs(a[i] - a[i + 1]));
        }
        sort(bx.begin(), bx.end());
        int ans = 0;
        for (int j = 0; j < n - k; j++)
        {
            ans += bx[j];
        }
        cout << ans << endl;
    }
    return 0;
}