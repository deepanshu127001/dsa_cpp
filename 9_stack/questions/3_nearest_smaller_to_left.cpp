#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> findNSL(vector<int> arr)
{
    vector <int> ans;
    stack<int> s;
    for(int i=0;i<arr.size();i++){
        if(s.empty()){
            ans.push_back(-1);
        }
        else if(s.size()>0 && s.top()<arr[i]){
            ans.push_back(s.top());
        }
        else if(s.size()>0 && s.top()>arr[i]){
            while(s.size()>0 && s.top()>arr[i])
            {
                s.pop();
            }
            if(s.size()==0){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<int> arr{4,5,2,10,8};
    vector<int> ans = findNSL(arr);
    for (int val : ans)
    {
        std::cout << val << " ";
    }

    return 0;
    return 0;
}
