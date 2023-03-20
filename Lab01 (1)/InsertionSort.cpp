#include <iostream>
#include <string>

using namespace std;
  
int main(int argc,char **argv) {
    int i,j,k; //variables of type int

        cin>>k;   
    int *arr= new int[k]; //creates an array of size k
    for( i= 0; i <= k; ++i){ // runs a for loop of size k and stores values
                                  //prints user instructions
        cin >> arr[i];   // save users input into array
    }
     int Valueholder;   // Variable is used to make insertion sorting
    for (int i = 1; i < k; i++) {
        for(int j = i; j > 0; j--) {
           if(arr[j] < arr[j-1]) {
               Valueholder = arr[j];
               arr[j] = arr[j-1];
               arr[j-1] = Valueholder;
           }
       }
       for(int j = 0; j <= i; ++j) {
           cout << arr[j] << ";";
       }
       cout << endl;
    
        }
        //allocates space
        delete[] arr;
        return 0;
    }




