#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

bool My_func(int a, int b)
{
    return (a) < (b);
}

int main()
{
    // get array number
    int n;
    cout << "Please Enter the Array number:";
    cin >> n;
    cout << endl;

    // define array and get indexes values
    int array[n], sorted_Array[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\t";
        cout << "index " << i << " :";
        cin >> array[i];
        sorted_Array[i] = array[i];
    }
    cout << endl;

    int LIS[n + 1][n + 1];
    for (int i = 0; i < n + 1; i++)
        fill(LIS[i], LIS[i] + n + 1, 0);

    sort(sorted_Array, sorted_Array + n, My_func);

    int pointer_to_max_index_row = 0, pointer_to_max_index_column = 0;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                continue;

            else if (array[i-1] == sorted_Array[j-1])
            {
                LIS[i][j] = LIS[i - 1][j - 1] + 1;
                if (LIS[pointer_to_max_index_row][pointer_to_max_index_column] < LIS[i][j])
                {
                    pointer_to_max_index_row = i;
                    pointer_to_max_index_column = j;
                }
            }
            else if (array[i-1] != sorted_Array[j])
            {
                if (LIS[i][j - 1] > LIS[i - 1][j])
                    LIS[i][j] = LIS[i][j - 1];
                else
                    LIS[i][j] = LIS[i - 1][j];

                if (LIS[pointer_to_max_index_row][pointer_to_max_index_column] < LIS[i][j])
                {
                    pointer_to_max_index_row = i;
                    pointer_to_max_index_column = j;
                }
            }
        }
    }

    cout << "Longest Increasing subsquence lenght: " << LIS[pointer_to_max_index_row][pointer_to_max_index_column] << "\n";

    for(int i=0 ; i<n+1 ; i++){
        for(int j=0 ; j<n+1 ; j++){
            cout << LIS[i][j] << " ";
        }
        cout << "\n";
    }
}