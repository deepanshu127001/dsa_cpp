#include <iostream>
int main(int argc, char const *argv[])
{
    int arr[]={12,56,89,23,53};
    int size=sizeof(arr)/sizeof(arr[0]);
    int max=INT32_MIN;
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    std::cout<<max;
    return 0;
}
