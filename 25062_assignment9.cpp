*/
Name - Usha sree alekhya siddi

Roll no - 25062

Div - A

Batch - C
*/


#include <iostream>
using namespace std;

void Max_Heapify(int arr[],int i,int n)
{
    int j,temp;
    temp = arr[i];
    j = 2*i;
    while(j<=n)
    {
        if(j<n && arr[j+1]>arr[j])
        
        j = j+1;
        
        if(temp > arr[j])
        
        break;
        
        else if(temp <= arr[j])
        {
            arr[j/2] = arr[j];
            
            j = 2*j;
        }
    }
    
        arr[j/2] = temp;
        return;
}

void HeapSort(int arr[], int n)
{
    int i, temp;
    for(i = n ; i>=2;i--)
    {
        temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        
        Max_Heapify(arr,1,i-1);
    }
}

void Build_MaxHeap(int arr[], int n)
{
    int i;
    for(i = n/2 ; i>= 1;i--)
    
    Max_Heapify(arr,i,n);
}

int main()
{
    int n,i;
    cout<<"==============================================================="<<endl;
    cout<<"*******************Max Heap Sort Algorithm******************"<<endl;
    cout<<"==============================================================="<<endl;
    cout<<"\nEnter the number of elements to be sorted : ";
    
    cin>>n;
    n++;
    int arr[n];
    
    cout<<"Enter "<<n-1<<" Elements : ";
    for(i=1;i<n;i++)
    {
        cin>>arr[i];
    }
    
    Build_MaxHeap(arr,n-1);
    HeapSort(arr,n-1);
    cout<<"==============================================================="<<endl;
    cout<<"\nSorted Elements are : ";
    for(i=1;i<n;i++)
    
    cout<<"-->"<<arr[i];
    
    
    return 0;
}

/*


===============================================================
*******************Max Heap Sort Algorithm******************
===============================================================

Enter the number of elements to be sorted : 10
Enter 10 Elements : 14 21 76 4 33 17 87 10 54 28
===============================================================

Sorted Elements are : -->4-->10-->14-->17-->21-->28-->33-->54-->76-->87

*/

