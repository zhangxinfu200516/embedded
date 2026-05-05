#include <iostream>
#include <vector>
using namespace std;

#ifdef AI
vector<vector<int>> Get_result(vector<int> input)
{
    vector<vector<int>> result;
    int n = input.size();
    if (n == 0)
        return result;

    // last[x] 存储值 x 最近一次出现的位置（1-indexed），初始化为 -1
    vector<int> last(n + 1, -1);
    int left = 1; // 当前窗口左边界（1-indexed）
    int max_len = 0;

    for (int right = 1; right <= n; ++right)
    {
        int val = input[right - 1]; // input 是 0-indexed，但我们要用 1-indexed 逻辑

        if (last[val] != -1)
        {
            left = max(left, last[val] + 1);
        }
        last[val] = right;

        int cur_len = right - left + 1;
        if (cur_len > max_len)
        {
            max_len = cur_len;
            result.clear();
            result.push_back({left, right});
        }
        else if (cur_len == max_len)
        {
            result.push_back({left, right});
        }
    }
    return result;
}
#endif
vector<vector<int>> Get_result(vector<int> input)
{
    vector<vector<int>> result;
    int n = input.size();
    vector<int> record(n + 1, -1);
    int left = 1, right = 1, max_length = 0;
    for (right = 1; right <= input.size(); right++)
    {
        int val = input[right - 1];
        if (record[val] != -1)
        {
            left++;
        }
        record[val] = right;
        int length = right - left + 1;
        if (length > max_length)
        {
            max_length = length;
            result.clear();
            result.push_back({left, right});
        }
        else
        {
            result.push_back({left, right});
        }
    }
    return result;
}
int main()
{
    int n;
    cin >> n;
    int x;
    vector<int> input;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        input.push_back(x);
    }

    vector<vector<int>> result = Get_result(input);
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i][0] << " " << result[i][1] << endl;
    }
}