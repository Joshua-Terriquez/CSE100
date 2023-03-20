#include<iostream>
#include<vector>
using namespace std;

void countSort(vector<int> arr[], int n, int pos)
{
vector<int> * output;
int i, count[4] = {0};
  
output = new vector<int>[n];

for (i = 0; i < n; i++)
count[ arr[i][pos]%4 ]++;

for (i = 1; i < 4; i++)
count[i] += count[i - 1];

for (i = n - 1; i >= 0; i--)
{
output[count[ arr[i][pos]%4 ] - 1] = arr[i];
count[ arr[i][pos]%4 ]--;
}

for (i = 0; i < n; i++)
arr[i] = output[i];
}

void radixsort(vector<int> arr[], int n)
{
int vectorSize = 10;

for (int pos = vectorSize -1; pos >= 0 ; pos--)
countSort(arr, n, pos);
}

void print(vector<int> arr[], int n)
{
for (int i = 0; i < n; i++)
{

vector<int>::iterator v = arr[i].begin();
while( v != arr[i].end())
{
cout << *v << ";";
v++;
}
cout << endl;
}
}

int main()
{
int n;
cin >> n;
  
vector<int> *arr;
arr = new vector<int>[n];
for(int i =0;i<n;i++)
{
for(int j =0;j<10;j++)
{
int num;
cin>>num;
arr[i].push_back(num);
}
}

radixsort(arr, n);
print(arr, n);
return 0;
}