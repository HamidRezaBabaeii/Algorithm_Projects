#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    // get array number
    int n;
    cout << "Please Enter the Array number:";
    cin >> n;
    cout << endl;

    // define array and get indexes values
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\t";
        cout << "index " << i << " :";
        cin >> array[i];
    }
    cout << endl;

    int LIS[n];
    fill(LIS, LIS + n, 1);

    int finalArray[n];
    fill(finalArray, finalArray + n, -1);

    int max_LIS_index = LIS[0];
    for (int i = 1; i < n; i++)
    {
        int max = 0;
        for (int j = 0; j < i; j++)
        {
            if (array[j] < array[i] && LIS[j] > max)
            {
                max = LIS[j];
                finalArray[i]=j;
            }
        }
        LIS[i] = max + 1;
        if (LIS[i] > max_LIS_index)
        {
            max_LIS_index = LIS[i];
        }
    }

    cout << max_LIS_index << "\n";
}