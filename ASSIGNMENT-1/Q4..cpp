#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int maxsum(int a[], int p, int q)
{
    if (p == q)
        return a[p];

    int m = (p + q) / 2;

    int maxl = maxsum(a, p, m);
    int maxr = maxsum(a, m + 1, q);

    int lsum = 0, rsum = 0;
    int maxmidl = INT_MIN, maxmidr = INT_MIN;

    for (int i = m; i >= p; i--) {
        lsum += a[i];
        maxmidl = max(maxmidl, lsum);
    }

    for (int i = m + 1; i <= q; i++) {
        rsum += a[i];
        maxmidr = max(maxmidr, rsum);
    }

    int maxmid = maxmidl + maxmidr;

    return max(maxmid, max(maxl, maxr));
}

int main()
{
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxsum(arr, 0, n - 1);

    return 0;
}
