//wap to sort an array
#include <bits/stdc++.h>
int main(int argc, char const *argv[])
{
    int arr[]={45,23,23,76,98,32};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[j-1]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
    for(int val:arr){
        std::cout<<val<<" ";
    }
    return 0;
}

/**
 * @brief approach 2

#include<set>
#include <iostream>
int main(int argc, char const *argv[])
{
    int arr[]={23,23,23,1,43,12,89};
    int size=sizeof(arr)/sizeof(arr[0]);
    std::set<int> s;
    for(int i=0;i<size;i++){
        s.emplace(arr[i]);
    }
    for(int val:s){
        std::cout<<val<<" ";
    }
    return 0;
}
 * 
 */