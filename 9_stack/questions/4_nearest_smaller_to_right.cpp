#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> findNSR(vector<int> arr){
    vector<int> ans;
    stack<int> s;
    for(int i=arr.size()-1;i>=0;i--){
        if(s.empty())
            ans.push_back(-1);
        else if(s.top()<arr[i]&&s.size()>0)
            ans.push_back(s.top());
        else if(s.top()>arr[i]&&s.size()>0){
            while (s.size()>0 && s.top()>arr[i])
            {
                s.pop();
            }
            if(s.size()==0)
                ans.push_back(-1);
            else{
                ans.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<int> arr{4,5,2,10,8};
    vector<int> ans = findNSR(arr);
    for (int val : ans)
    {
        std::cout << val << " ";
    }

    return 0;
    return 0;
}
