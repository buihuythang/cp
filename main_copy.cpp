#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int minss = 1000000001;

        return cal(nums, 0, m, minss);
    }

private:
    int inline cal(vector<int> &nums, int offset, int m, int minss)
    {
        int cap = nums.size() - offset - m + 1;
        cout << "considering: ";
        for_each (nums.begin() + offset,
                 nums.end(),
                 [](int i) {
                     cout << i << ' ';
                 });
        cout << endl;
        cout << "cap = " << cap << ", m = " << m << ", offset = " << offset << endl;

        if (m == 1)
        {
            auto s = accumulate(nums.begin() + offset, nums.end(), 0);
            //cout << "accm = " << s << endl;

            return s;
        }



        int maxss = 0;
        int ss1 = nums[offset];
        for (int i = 1; i <= cap; ++i)
        {
            ++offset;
            int ss2 = cal(nums, offset, m - 1, minss);
            maxss = max(ss1, ss2);
            cout << "ss1 = " << ss1 << ", ss2 = " << ss2 << ", offset = " << offset;
            cout << ", maxss = " << maxss << endl;

            minss = min(minss, maxss);
            cout << "minss = " << minss << endl;
            ss1 += nums[offset];
            cout << "new ss1 = " << ss1 << endl;
        }




        return minss;
    }
};


int main()
{
    vector<int> v2 = {7,2,5,10,8};
    Solution s2;

    s2.splitArray(v2, 3);

    return 0;
}
