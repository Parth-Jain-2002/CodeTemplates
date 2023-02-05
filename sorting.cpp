#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

// While writing arrays as function argument, makes them convert from arr[] to arr*

// Merge function is to merge two sorted arrays
// Time complexity in all cases: nlogn
// void merge(int arr[], int left,int mid, int right){
//     vector<int> a,b;
//     for(int i=left;i<=mid;i++) a.push_back(arr[i]);
//     for(int i=mid+1;i<=right;i++) b.push_back(arr[i]);

//     ll i=0,j=0,k=left;
//     while(i<a.size() && j<b.size()){
//         if(a[i]<b[j]){
//            arr[k]=a[i];
//            i++;
//         }
//         else{
//             arr[k]=b[j];
//             j++;
//         }
//         k++;
//     }
//     while(i<a.size()){
//         arr[k]=a[i];
//         i++;
//         k++;
//     }
//     while(j<b.size()){
//         arr[k]=b[j];
//         j++;
//         k++;
//     }
// }

// void mergesort(int arr[],int left,int right){
//     if(left>=right) return;
//     int mid = left + (right-left)/2;
//     mergesort(arr,left,mid);
//     mergesort(arr,mid+1,right);
//     merge(arr,left,mid,right);
// }

// The selection sort algorithm sorts an array by repeatedly finding the minimum element 
// (considering ascending order) from unsorted part and putting it at the beginning. 
// The algorithm maintains two subarrays in a given array.

// Time complexity in all cases : O(n^2)
// void selection(int arr[],int n){
//     for(int i=0;i<n-1;i++){
//         int mini=i;
//         for(int j=i;j<n;j++){
//             if(arr[mini]>arr[j]){
//                 mini=j;
//             }
//         }
//         swap(arr[mini],arr[i]);
//     }
// }

//Bubble Sort
// Best Case: O(n) if arr is sorted and worst cast is O(n^2)

int main(){
    int arr[10];
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }
    selection(arr,10);
    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}