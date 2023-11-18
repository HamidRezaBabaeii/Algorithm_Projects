#include <stdio.h>
#include <iostream>
#include <list>

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

    // structure for saving biggest length in each iterate
    int lenArray[n] = {0};
    list<int> subArray;

    // find max length and add to list if the length of sub Array is equal max
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int nummax = array[i];
        lenArray[i]++;
        subArray.push_back(nummax);
        for (int j = i + 1; j < n; j++)
        {
            if (nummax < array[j])
            {
                lenArray[i]++;
                nummax = array[j];
                subArray.push_back(nummax);
            }
        }

        if (max > lenArray[i])
        {
            for (int k = 0; k < lenArray[i]; k++)
            {
                subArray.pop_back();
            }
        }

        if (max < lenArray[i])
        {
            int size = subArray.size();
            for (int k = 0; k < size - lenArray[i]; k++)
            {
                subArray.pop_front();
            }
            max = lenArray[i];
        }
    }

    list<int>::iterator it;
    cout << " Max Sub Array Length : " << max << endl;
    int counter = 0;
    cout << "\nSub Arrays:" << endl;
    for (it = subArray.begin(); it != subArray.end(); ++it)
    {
        counter++;
        cout << *it << "\t";
        if (counter % max == 0)
        {
            cout << endl;
        }
    }
    cout << endl;

    return 0;
}