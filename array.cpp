#include <iostream>
using namespace std;


int main() {
    
    int n ;
    cin >>n;
    int arr[n];
    // int ar[n];
    for(int i = 0 ; i < n ; i ++){
        cin>>arr[i];

    }
    for (int j = 0 ; j<n/2;j++){
        int temp = arr[j];       
        arr[j] = arr[n - j - 1]; 
        arr[n - j - 1] = temp;   }
        for (int i = 0 ; i<n;i++){
cout<<arr[i];
        }
        return 0;
}
