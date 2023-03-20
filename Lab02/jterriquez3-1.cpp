#include<iostream>
using namespace std;
#define inf 2147483647 //calling maximum value of int as infinity
void MERGE(int Arr[], int p, int q, int r) 
{
   //calc. n1 and n2 
   int n1 = q - p + 1;
   int n2 = r - q;
    //Temp arrays
   // indexing from 1 is 1 more element space so n1+1+1 = n1+2 similarly n2+2
   int L[n1+2], R[n2+2];
   //fill both arrays
   for(int i = 1; i <= n1; i++)
      L[i] = Arr[p+i-1];
   for(int j = 1; j <= n2; j++)
      R[j] = Arr[q+j];

    L[n1+1] = inf;
    R[n2+1] = inf;

   //merging array
   int i = 1,j=1;
   for(int k= p; k<=r; k++)
   {
       if(L[i]<=R[j]){

           Arr[k]=L[i];
            i=i+1;
                       }
       else{
           Arr[k] = R[j];
           j=j+1;
       }
   }
}
void mergeSort(int *arr, int l, int r) 
{
   int mid;
   if(l < r) {
      int mid = (l+r)/2;//calculate mid

      //calls sort function: l to mid
      mergeSort(arr, l, mid);
      
      //calls sort function:  mid+1 to r
      mergeSort(arr, mid+1, r);
      
      //merges both arrays
      MERGE(arr, l, mid, r);
   }
}
int main() {
   int numElements; //amount of numbers variable
   
   cin>>numElements;    //users input
   int arr[numElements];  // creates an array of users input
   for(int i = 0; i<numElements; i++)
      
      cin >> arr[i];

   //calls mergeSort function
   mergeSort(arr, 0, numElements-1);
   
   //printing num's
   for(int i = 0; i<numElements; i++)
            
             cout<<arr[i]<<";";
}