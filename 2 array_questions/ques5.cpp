#include <iostream>
int main(int argc, char const *argv[])
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int sum=0;
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    std::cout<<sum;
    return 0;
}
