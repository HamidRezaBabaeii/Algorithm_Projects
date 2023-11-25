#include <stdio.h>
#include <iostream>
#include <list>
#include <bits/stdc++.h>

using namespace std;

int *find_longest_increasing_subarray(int *array, int n)
{
    int *LIS;
    LIS[0] = 1;

    for (int i = 1; i < n; i++) {
        LIS[i] = 1;
        for (int j = 0; j < i; j++)
            if (array[i] > array[j])
                LIS[i] = max(LIS[j] + 1,LIS[i]);
    }
 
    return LIS;
}


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
    int* arr =  find_longest_increasing_subarray(array,n) ;

    // find max
    int index_of_max = 0;
    int max = arr[0];
    for(int i=1 ; i<n ; i++){
        if(  max < arr[i])
        {
            max = arr[i];
            index_of_max = i;
        }
    }
    cout << "Max length of Subarray: " << max << endl;

    // print subarray
    list<int> lis;
    for(int i=index_of_max ; i>=0 ; i--)
    {
        if(max == arr[i])
        {
            lis.push_back(array[i]);
            max--;
        }
    }
    lis.reverse();
    list<int>::iterator it;
    cout << "Sub Array :" << endl;
    for(it = lis.begin() ; it != lis.end() ; it++){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}