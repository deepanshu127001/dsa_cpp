#include <iostream>
int main(int argc, char const *argv[])
{
    int arr[]={87,78,75,45,35,1,34,23};
    int target=23;
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            std::cout<<"element found at index "<<i;
            break;
        }
    }

    return 0;
}
