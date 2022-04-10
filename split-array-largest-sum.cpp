// https://leetcode.com/problems/split-array-largest-sum/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int minss = 1000000001;
        vector<vector<int>> pre(nums.size(), vector<int>(m - 1, -1));
        return cal(nums, 0, m, minss, pre);
    }



private:
    int inline cal(vector<int> &nums, int offset, int m, int minss, vector<vector<int>> &pre)
    {
        int cap = nums.size() - offset - m + 1;

        if (m == 1) return accumulate(nums.begin() + offset, nums.end(), 0);

        int ss = nums[offset];

        for (int i = 1; i <= cap; ++i)
        {
            ++offset;
            if (pre[offset][m-1] == -1)
                pre[offset][m-1] = cal(nums, offset, m - 1, minss, pre);

            int maxss = max(ss, pre[offset][m-1]);
            minss = min(minss, maxss);
            ss += nums[offset];
        }

        return minss;
    }
};

int main()
{
    vector<int> v = {7, 2, 5, 10, 8};
    Solution s;
    cout << s.splitArray(v, 3) << endl;
    return 0;
}
