#include<bits/stdc++.h>
using namespace std;

void moveZerosToend(int arr[],int n){
    int i=0,j=0;
    while(i<n){
        if(arr[j]!=0 && arr[i]==0){
            swap(arr[j],arr[i]);
            i++;
            j=i;
        }
        else if(arr[i]==0){
            j=(j+1);
            if(j==n){
                break;
            }
        }
        
        else{
            i++;
            j=i;
        }
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << "     ";
    }
    cout << endl;
}

int main(){
    int arr[] = {3,0,0,2,1,1,9,0,4};
    int n = sizeof(arr)/sizeof(int);
    moveZerosToend(arr,n);
}