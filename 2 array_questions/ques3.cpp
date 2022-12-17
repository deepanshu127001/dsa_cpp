#include <iostream>
int main(int argc, char const *argv[])
{
    int min=INT32_MAX;
    int arr[]={87,78,75,45,35,1,34,23};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
std::cout<<min;
    return 0;
}
