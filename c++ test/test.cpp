#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <unordered_map>
//#include <stack>
//#include <array>
using std::cout;
using namespace std;

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> N;
        vector<int> res;
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            if(N.count(target-num)!=0)
            {
                res.push_back(i);
                res.push_back(N[target-num]);
            }
            else
            {
                cout<<count<<"\n";
                count++;
                N[nums[i]] = i;  // index 2 = 0 
            }
        }
        return res;
    }

int main()
{
   // Solution a;
    vector<int>ans;
    vector<int>res;
    res.push_back(2);
    res.push_back(20);
    res.push_back(23);
    res.push_back(22);
    res.push_back(21);
    res.push_back(11);
    res.push_back(7);
    res.push_back(15);
    ans = twoSum(res, 9);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<"\n";
    }
    /*unordered_map<int,int> a;
    a[1] = 10;
    cout<<a.count(1)<<"\n";
    cout<<a.count(2)<<"\n";*/

    return 0;
}