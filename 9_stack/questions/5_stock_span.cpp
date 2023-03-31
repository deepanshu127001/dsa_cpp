#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// two changes from previous code
// 1 direction of loop
// no reversal

vector<int> findNGL(vector<int> arr)
{
    stack<pair<int, int>> stack;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        if (stack.empty())
        {
            ans.push_back(-1);
        }
        else if (stack.top().first > arr[i] && stack.size() > 0)
        {
            ans.push_back(stack.top().second);
        }
        else
        {
            while (stack.top().first < arr[i] && stack.size() > 0)
            {
                stack.pop();
            }
            if(stack.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(stack.top().second);
            }
        }
        stack.push({arr[i],i});
    }
    for(int i=0;i<ans.size();i++){
        ans[i]=i-ans[i];
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<int> arr{100, 80, 60, 70, 60, 75, 85};
    vector<int> ans = findNGL(arr);
    for (int val : ans)
    {
        std::cout << val << " ";
    }

    return 0;
}
