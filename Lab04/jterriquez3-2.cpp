#include <iostream>
using namespace std;

void convertToheap(int *arr, int length, int x)
{
    int largest, left, right;
 largest = x;
 left = 2 * x + 1;
 right = 2 * x + 2;

if (left < length && *(arr+left) > *(arr+largest))
largest = left;

if (right < length && *(arr+right)> *(arr+largest))
largest = right;

if (largest != x)
{
swap(*(arr+x), *(arr+largest));

convertToheap(arr, length, largest);
}
}

void heap_sort(int *arr, int len)
{
for (int i = len / 2 - 1; i >= 0; i--)
convertToheap(arr, len, i);

for (int i = len - 1; i >= 0; i--)
{
swap(*arr, *(arr+i));
convertToheap(arr, i, 0);
}
}


int main()
{
int n;
cin>>n;
int* s_array = new int[n];
for(int i=0; i<n;i++){
   cin>>*(s_array+i);
   }

heap_sort(s_array, n);
for(int i=0; i<n;i++)cout<<*(s_array+i)<<";";
}