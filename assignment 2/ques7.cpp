#include <iostream>
void rotateByOne(int arr[],int size){
    if(size>1){
        int element=arr[size-1];
        for(int i=size-2;i>=0;i--){
            arr[i+1]=arr[i];
        }
        arr[0]=element;
    }
}
int main(int argc, char const *argv[])
{
    int arr[]={12,34,35,47,68,64};
    int size=sizeof(arr)/sizeof(arr[0]);
    rotateByOne(arr,size);
    for(int val:arr){
        std::cout<<val<<" ";
    }
    return 0;
}
