#include <bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int maxx; 
 
void lengthOfLIS(vector<int>& nums)
{
    int tempArray[nums.size()]; // we will store index of nums array
    fill(tempArray, tempArray+nums.size(), 0);

    int finalArray[nums.size()]; // we will store index of previous index on sub sequence 
    fill(finalArray,finalArray+nums.size(), -1);

    int len = 0 , max_index = 0;
    int pointer_To_index = 0;
    tempArray[pointer_To_index]=0;
    len++;
    pointer_To_index++;

    for(int i=1 ; i<nums.size() ; i++)
    {
        if(nums[i]>nums[tempArray[pointer_To_index-1]])
        {
            len++;
            tempArray[pointer_To_index]=i;
            finalArray[i]=tempArray[pointer_To_index-1];
            if(finalArray[i]>finalArray[max_index])
            {
                max_index = i;
            }
            pointer_To_index++;   
        }else{

            // binary search
            int low = 0; //0
            int higth = pointer_To_index-1;//2
            while (low < higth)
            {
                int mid =low + (higth-low)/2;
                if(nums[tempArray[mid]]<nums[i])
                {
                    low = mid+1;
                }else{
                    higth = mid;
                }
            }
            tempArray[low]=i;
            if(low-1>-1)
                finalArray[i]=tempArray[low-1];
        }
    }
    maxx = max_index;
    cout <<"\n\nThe maximum length of subsquence is: " << len << "\n";
    
    int k = maxx;
    while(k!=-1)
    {
        cout << nums[k] ;
        int i = finalArray[k];
        k = i;
        if(k!=-1) cout << " > ";
        
    }
    cout << "\n";

}

int main()
{
    int n;
    cout << "Enter the number of array: ";
    cin >> n;
    cout << "\n";
    vector<int> nums;
    for(int i=0 ; i<n ; i++)
    {
        int number ;
        cout << "\tEnter value of index " << i << " :";
        cin >> number;
        cout << "\n";
        nums.push_back(number);
    }
    lengthOfLIS(nums);
    return 0;
    //{3,4,-1,5,8,2,3,12,7,9,10} {5,6,3,5,7,8,9,1,2}
}