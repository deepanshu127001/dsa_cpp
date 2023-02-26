#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
// find nearest greater to right || next largest element (gfg)
vector<int> findNGR(vector<int> &arr){
    vector<int> ans;
    stack<int> s;
    for(int i=arr.size()-1;i>=0;--i){
        //if stack is empty put -1 in ans and current element in stack 
        if(s.empty()){
            ans.push_back(-1);
        }
        //if top of the stack is greater than the current element then put top of the stack in ans array and push the current element in stack  
        else if (s.top()>arr[i] && s.size()>0){
            ans.push_back(s.top());
        }
        else if (s.top()<arr[i]){
            while(s.size()>0 && s.top()<=arr[i]){
                s.pop();
            }
            if(s.size()==0)
                ans.push_back(-1);
            else
                ans.push_back(s.top());
        }
        s.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans; 
}
int main(int argc, char const *argv[])
{
    vector <int> arr {1,3,2,4};
    vector<int> ans = findNGR(arr);
    for(int val : ans){
        std::cout<<val<<" ";
    }
    return 0;
}
