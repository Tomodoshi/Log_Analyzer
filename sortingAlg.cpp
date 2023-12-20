#include <bits/stdc++.h>
#include "HashTable.h"

using namespace std;

int partition(fileNode arr[],int low,int high)
{

    int pivot=arr[high].count;
    int i=(low-1);

    for(int j=low;j<=high;j++)
    {
	    if(arr[j].count<pivot)
	    {
	        i++;
	        swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}

void quickSort(fileNode arr[],int low,int high)
{
    if(low<high)
    {
	    int pi=partition(arr,low,high);
	    quickSort(arr,low,pi-1);
	    quickSort(arr,pi+1,high);
    }
}
