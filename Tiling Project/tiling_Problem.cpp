#include <stdio.h>
#include <iostream>

using namespace std;

int nn;
// for count all shapes
int counter = 1;


// for debuge code
void print_it(int **array)
{
    for (int i = 0; i < nn; i++)
    {
        for (int j = 0; j < nn; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "-----------------------------------\n";
}



int **divide_And_Conquer(int nn, int locx, int locy, int **array)
{
    // for find -1 into each Square
    int row, column;

    if (nn == 2)
    {
        for (int i = 0; i < nn; i++)
        {
            for (int j = 0; j < nn; j++)
            {
                if (array[i + locx][j + locy] == 0)
                {
                    array[i + locx][j + locy] = counter;
                }
            }
        }
        counter++;
        return array;
    }

    // finde -1
    bool brk = false;
    for (int i = 0; i < nn; i++)
    {
        for (int j = 0; j < nn; j++)
        {
            if (array[i + locx][j + locy] != 0)
            {
                row = i + locx;    // find every square point that is grather than 0 
                column = j + locy; // find every square point that is grather than 0 
                brk = true;
                break;
            }
        }
        if (brk == true)
        {
            break;
        }
    }
    cout << "Tail position is " << row << " " << column << endl;

    // Detecting the location of the point and add other points to  other quarters
    if (row < (nn / 2) + locx && column < (nn / 2) + locy) // first quarter
    {
        array[locx + (nn / 2)][locy + (nn / 2)] = counter;
        array[locx + (nn / 2)][locy + (nn / 2) - 1] = counter;
        array[locx + (nn / 2) - 1][locy + (nn / 2)] = counter;
        counter++;
    }
    else if (row >= (nn / 2) + locx && column < (nn / 2) + locy) // second quarter
    {
        array[locx + (nn / 2)][locy + (nn / 2)] = counter;
        array[locx + (nn / 2) - 1][locy + (nn / 2) - 1] = counter;
        array[locx + (nn / 2) - 1][locy + (nn / 2)] = counter;
        counter++;
    }
    else if (row < (nn / 2) + locx && column >= (nn / 2) + locy) // third quarter
    {
        array[locx + (nn / 2) - 1][locy + (nn / 2) - 1] = counter;
        array[locx + (nn / 2)][locy + (nn / 2) - 1] = counter;
        array[locx + (nn / 2)][locy + (nn / 2)] = counter;
        counter++;
    }
    else if (row >= (nn / 2) + locx && column >= (nn / 2) + locy) // forth quarter
    {
        array[locx + (nn / 2) - 1][locy + (nn / 2) - 1] = counter;
        array[locx + (nn / 2)][locy + (nn / 2) - 1] = counter;
        array[locx + (nn / 2) - 1][locy + (nn / 2)] = counter;
        counter++;
    }

    print_it(array);

    divide_And_Conquer(nn / 2, locx, locy, array);

    divide_And_Conquer(nn / 2, locx, locy + (nn / 2), array);

    divide_And_Conquer(nn / 2, locx + (nn / 2), locy, array);

    divide_And_Conquer(nn / 2, locx + (nn / 2), locy + (nn / 2), array);

    return array;
}

int main()
{
    // variables and values
    cout << "Enter width and height of square : ";
    cin >> nn;
    cout << endl;
    int **array;
    array = new int *[nn];
    for (int i = 0; i < nn; i++)
        array[i] = new int[nn];

    // zero-initialized
    for (int i = 0; i < nn; i++)
        for (int j = 0; j < nn; j++)
            array[i][j] = 0;

    // get point that won't tiling
    cout << "Enter row and column that you won't tiling : ";
    int row, column;
    cin >> row;
    cout << "\nEnter row and column that you won't tiling : ";
    cin >> column;
    cout << endl;
    if (row < nn && column < nn)
    {
        array[row][column] = -1;
    }
    else
    {
        cout << "Your Point Is Out Of Matrix Size." << endl;
        return 0;
    }

    // function
    int **arr = divide_And_Conquer(nn, 0, 0, array);

    for (int i = 0; i < nn; i++)
    {
        for (int j = 0; j < nn; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
        cout << endl;
    }

    return 0;
}