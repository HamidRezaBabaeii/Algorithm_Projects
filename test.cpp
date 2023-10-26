// #include <stdio.h>
// #include <iostream>

// using namespace std;

// // for count all shapes
// int counter = 1;

// auto divide_And_Conquer(int nn, int locx, int locy, int array[8][8])
// {
//     // for find -1 into each Square
//     int row, column;

//     if (nn == 2)
//     {
//         for (int i = 0; i < nn; i++)
//         {
//             for (int j = 0; j < nn; j++)
//             {
//                 if (array[i + locx][j + locy] == 0)
//                 {
//                     array[i + locx][j + locy] = counter;
//                 }
//             }
//         }  
//         counter++;
//         return array;
//     }

//     // finde -1 
//     bool brk = false;
//     for (int i = 0; i < nn; i++)
//     {
//         for (int j = 0; j < nn; j++)
//         {
//             if (array[i + locx][j + locy] != 0)
//             {
//                row = i;
//                column = j;
//                brk = true;
//                break;
//             }
//         }
//         if(brk == true)
//         {
//             break;
//         }
//     }


//     // Detecting the location of the point and add other points to  other quarters
//     if(row < nn/2 + locx && column < nn/2 + locy) // first quarter
//     {
//         array[locx + nn/2][locy + nn/2 -1] = counter ;
//         array[locx + nn/2][locy + nn/2] = counter ;
//         array[locx + nn/2 - 1][locy + nn/2] = counter ;
//         counter++;

//     }else if(row >= nn/2 + locx && column < nn/2 + locy) // second quarter
//     {
//         array[locx + nn/2][locy + nn/2] = counter;
//         array[locx + nn/2 - 1][locy + nn/2 -1] = counter;
//         array[locx + nn/2 - 1][locy + nn/2] = counter;
//         counter++;

//     }else if(row < nn/2 + locx && column >= nn/2 + locy) // third quarter
//     {
//         array[locx + nn/2 - 1][locy + nn/2 - 1] = counter;
//         array[locx + nn/2][locy + nn/2 - 1] = counter;
//         array[locx + nn/2][locy + nn/2] = counter;
//         counter++;

//     }else if(row >= nn/2 + locx && column >= nn/2 + locy) // forth quarter
//     {
//         array[locx + nn/2 - 1][locy + nn/2 - 1]=counter;
//         array[locx + nn/2][locy + nn/2 - 1]=counter;
//         array[locx + nn/2 - 1][locy + nn/2]=counter;
//         counter++;
//     }

//      divide_And_Conquer(nn/2 , locx , locy + nn/2 , array );
//      divide_And_Conquer(nn/2 , locx , locy , array );
//      divide_And_Conquer(nn/2 , locx + nn/2 , locy , array);
//      divide_And_Conquer(nn/2 , locx + nn/2 , locy + nn/2 , array);  

//         return array; 
// }

// int main()
// {
//     // variables and values
//     cout << "Enter width and height of square : " ;
//     int nn;
//     cin >> nn;
//     cout << endl ;
//     int array[8][8];
//     // array = new int *[nn];
//     // for (int i = 0; i < nn; i++)
//     //     array[i] = new int[nn];

//     // zero-initialized
//     for (int i = 0; i < nn; i++)
//         for (int j = 0; j < nn; j++)
//             array[i][j] = 0;

//     // get point that won't tiling
//     cout << "Enter row and column that you won't tiling : ";
//     int row, column;
//     cin >> row ;
//     cout << "\nEnter row and column that you won't tiling : ";
//     cin >> column;
//     cout << endl;
//     if (row < nn && column < nn)
//     {
//         array[row][column] = -1;
//     }
//     else
//     {
//         cout << "Your Point Is Out Of Matrix Size." << endl;
//         return 0;
//     }

//     // function
//     auto arr = divide_And_Conquer(nn, 0, 0, array);

//     for(int i=0 ; i<nn ; i++)
//     {
//         for(int j=0 ; j<nn ;j++)
//         {
//             cout << arr[i][j] << "\t";
//         }
//         cout << endl;
//         cout << endl;
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
 
int size_of_grid, b, a, cnt = 0;
int arr[128][128];
 
// Placing tile at the given coordinates
void place(int x1, int y1, int x2, 
           int y2, int x3, int y3)
{
    cnt++;
    arr[x1][y1] = cnt;
    arr[x2][y2] = cnt;
    arr[x3][y3] = cnt;
}
// Quadrant names
// 1   2
// 3   4
 
// Function based on divide and conquer
int tile(int n, int x, int y)
{
    int r, c;
    if (n == 2) {
        cnt++;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[x + i][y + j] == 0) {
                    arr[x + i][y + j] = cnt;
                }
            }
        }
        return 0;
    }
    // finding hole location
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (arr[i][j] != 0)
                r = i, c = j;
        }
    }
 
    // If missing tile is 1st quadrant
    if (r < x + n / 2 && c < y + n / 2)
        place(x + n / 2, y + (n / 2) - 1, x + n / 2,
              y + n / 2, x + n / 2 - 1, y + n / 2);
 
    // If missing Tile is in 3rd quadrant
    else if (r >= x + n / 2 && c < y + n / 2)
        place(x + (n / 2) - 1, y + (n / 2), x + (n / 2),
              y + n / 2, x + (n / 2) - 1, y + (n / 2) - 1);
 
    // If missing Tile is in 2nd quadrant
    else if (r < x + n / 2 && c >= y + n / 2)
        place(x + n / 2, y + (n / 2) - 1, x + n / 2,
              y + n / 2, x + n / 2 - 1, y + n / 2 - 1);
 
    // If missing Tile is in 4th quadrant
    else if (r >= x + n / 2 && c >= y + n / 2)
        place(x + (n / 2) - 1, y + (n / 2), x + (n / 2),
              y + (n / 2) - 1, x + (n / 2) - 1,
              y + (n / 2) - 1);
 
    // dividing it again in 4 quadrants
    tile(n / 2, x, y + n / 2);
    tile(n / 2, x, y);
    tile(n / 2, x + n / 2, y);
    tile(n / 2, x + n / 2, y + n / 2);
 
    return 0;
}
// Driver program to test above function
int main()
{
    // size of box
    size_of_grid = 8;
    memset(arr, 0, sizeof(arr));
    // Coordinates which will be marked
    a = 6, b = 5;
    // Here tile can not be placed
    arr[a][b] = -1;
    tile(size_of_grid, 0, 0);
    // The grid is
    for (int i = 0; i < size_of_grid; i++) {
        for (int j = 0; j < size_of_grid; j++)
            cout << arr[i][j] << " \t";
        cout << "\n";
    }
}