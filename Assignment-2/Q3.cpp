#include <iostream>
using namespace std;

float knapsack(int w[], int v[], int W, int n)
{
    float ratio[n];

    for (int i = 0; i < n; i++)
    {
        ratio[i] = (float)v[i] / w[i];   
    }

    float total_value = 0;

    while (W > 0)
    {
        int idx = -1;
        float maxratio = -1;

        for (int i = 0; i < n; i++)
        {
            if (ratio[i] > maxratio)     
            {
                maxratio = ratio[i];
                idx = i;
            }
        }

        if (idx == -1)
            return total_value;          

        if (w[idx] <= W)
        {
            total_value += v[idx];
            W -= w[idx];
        }
        else
        {
            total_value += ratio[idx] * W;
            W = 0;
        }

        ratio[idx] = -1;   
    }

    return total_value;
}

int main()
{
    int w[] = {20, 10, 40};
    int v[] = {100, 60, 120};

    int n = sizeof(w) / sizeof(w[0]);
    int W = 50;

    cout << "Max profit: " << knapsack(w, v, W, n);

    return 0;
}
