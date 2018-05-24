#include<iostream>
using namespace std;
 
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int output[n]; 
    int i, count[10] = {0};
 
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 
 
int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
        if (arr[mid] == x)  
            return mid;
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
   }
   return -1;
}

int findSmallestElement(int arr[], int n){
   int temp = arr[0];
   for(int i=0; i<n; i++) {
      if(temp>arr[i]) {
         temp=arr[i];
      }
   }
   return temp;
}

int main()
{
    int numberOfRequest,initialFloor;
    cin>>numberOfRequest;
    cin>>initialFloor;
    int *a,index;
    a=new int[numberOfRequest+1];
    int i;
    for(i=0;i<numberOfRequest;i++)
    {
    	cin>>a[i];
	}
    
    a[i]=initialFloor;
    
    radixsort(a, numberOfRequest+1);
    
    cout<<"\n\n";
    index = binarySearch(a,0,numberOfRequest,initialFloor);
    cout<<"ORDER : ";
    for(int i=index;i<numberOfRequest+1;i++)
    {
    	cout<<a[i]<<" ";
	}
	for(int i=(index-1);i>=0;i--)
    {
    	cout<<a[i]<<" ";
	}
	int maximum,distance,minimum;
	maximum=getMax(a,numberOfRequest+1);
	distance=maximum-initialFloor;
	minimum=findSmallestElement(a,numberOfRequest+1);
	distance+=maximum-minimum;
	cout<<"\n\n";
	cout<<"The total distance traversed by the lift is : "<<distance;
    return 0;
}
