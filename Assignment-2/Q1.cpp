#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    int wt[n], val[n];
    
    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
        cin >> val[i];

    float ratio[n];
    for (int i = 0; i < n; i++)
        ratio[i] = (float)val[i] / wt[i];

    int capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    float maxValue = 0;

    while (capacity > 0)
    {
        int bestIdx = -1;
        float bestRatio = -1;

        for (int i = 0; i < n; i++)
        {
            if (ratio[i] > bestRatio)
            {
                bestRatio = ratio[i];
                bestIdx = i;
            }
        }

        if (bestIdx == -1)
            break;

        if (wt[bestIdx] <= capacity)
        {
            maxValue += val[bestIdx];
            capacity -= wt[bestIdx];
        }
        else
        {
            maxValue += ratio[bestIdx] * capacity;
            capacity = 0;
        }

        ratio[bestIdx] = -1;   // item used
    }

    cout << "Maximum value in knapsack = " << maxValue << endl;
    return 0;
}
