#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 测试二维数组的
void test_arr()
{
  int array[2][3] = {
      {0, 1, 2},
      {3, 4, 5}};
  cout << array[0][0] << " " << array[0][1] << " " << array[0][2] << endl;
  cout << array[1][0] << " " << array[1][1] << " " << array[1][2] << endl;
}
// 力扣-二分查找
// L=0,R=size-1
class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
      int middle = left + (right - left) / 2;
      if (nums[middle] == target)
      {
        return middle;
      }
      else if (nums[middle] < target)
      {
        left = middle + 1;
      }
      else
      {
        right = middle - 1;
      }
    }
  }
};
//
class Solution1
{
public:
  int search(vector<int> &nums, int target)
  {
    int left = 0, right = nums.size();
    while (left < right)
    {
      int middle = left + (right - left) / 2;
      if (nums[middle] == target)
      {
        return middle;
      }
      else if (nums[middle] < target)
      {
        left = middle + 1;
      }
      else
      {
        right = middle;
      }
    }
  }
};
// 移除元素
// 暴力解法
class Solution3
{
public:
  int removeElement(vector<int> &nums, int val)
  {
    int size = nums.size();
    for (auto i = 0; i < size; i++) // 遍历数组查找删除元素
    {
      if (nums[i] == val)
      {
        // 将后续元素前移
        for (auto j = i + 1; j < size; j++)
        {
          /* code */
          nums[j - 1] = nums[j];
        }

        // 修改整个数组的长度
        size--;
        i--;
      }
      // for (auto j = i + 1; j < size; j++)
      // {

      // }
    }
    return size;
  };
};
// 快慢指针法
class Solution4
{
public:
  int removeElement(vector<int> &nums, int val)
  {
    int size = nums.size();
    int slow_idx = 0;
    for (auto fast_idx = 0; fast_idx < size; fast_idx++)
    {
      /* code */
      if (nums[fast_idx] != val)
      {
        nums[slow_idx] = nums[fast_idx];
        slow_idx++;
      }
    }
    return slow_idx;
  };
};
//
class Solution5
{
public:
  vector<int> sortedSquares(vector<int> &nums)
  {
    for (auto i = 0; i < nums.size(); i++)
    {
      /* code */
      nums[i] = nums[i] * nums[i];
    }
    sort(nums.begin(), nums.end());
    return nums;
  };
};
//
class Solution6
{
public:
  vector<int> sortedSquares(vector<int> &nums)
  {
    vector<int> result(size(nums), 0);
    int k = nums.size() - 1;
    for (int i = 0, j = size(nums) - 1; i <= j;)
    {
      if (nums[i] * nums[i] < nums[j] * nums[j])
      {
        result[k--] = nums[j] * nums[j];
        j--;
      }
      else
      {
        result[k--] = nums[i] * nums[i];
        i++;
      }
    }
    return result;
  };
};
class Solution7
{
public:
  int minSubArrayLen(int target, vector<int> &nums)
  {
    int size = nums.size();
    int Length = 0,minLen = size + 1;
    for (int i = 0; i < size; i++)
    {
      int sum = 0;
      for (int j = i; j < size; j++)
      {
        /* code */
        sum += nums[j];
        if (sum >= target)
        {
          Length = j - i + 1;
          if(Length < minLen)
            minLen = Length;
          break;
        }
      }
    }
    return (minLen <= size) ? minLen : 0;
  }
};
class Solution8 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;//定义滑动窗口的左边界
        int sum = 0,min_length = nums.size()+1;
        for (int j = 0; j < nums.size(); j++)
        {
          //求和
          sum += nums[j];
          //查找
          while(sum >= target)
          {
            int length = j-i+1;
            cout << length << endl;
            if(length < min_length)
            {
              min_length = length;
            }
            sum-=nums[i];//向后滑动
            i++;
          }
        }
        return min_length==(nums.size()+1) ? 0 : min_length;
    }
};
class Solution9 {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
        int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
        int loop = n / 2; // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
        int mid = n / 2; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
        int count = 1; // 用来给矩阵中每一个空格赋值
        int offset = 1; // 需要控制每一条边遍历的长度，每次循环右边界收缩一位
        int i,j;
        while (loop --) {
            i = startx;
            j = starty;

            // 下面开始的四个for就是模拟转了一圈
            // 模拟填充上行从左到右(左闭右开)
            for (; j < n - offset; j++) {
                res[i][j] = count++;
            }
            // 模拟填充右列从上到下(左闭右开)
            for (; i < n - offset; i++) {
                res[i][j] = count++;
            }
            // 模拟填充下行从右到左(左闭右开)
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            // 模拟填充左列从下到上(左闭右开)
            for (; i > startx; i--) {
                res[i][j] = count++;
            }

            // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
            startx++;
            starty++;

            // offset 控制每一圈里每一条边遍历的长度
            offset += 1;
        }

        // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};

int main()
{
 Solution9 s;
  vector<vector<int>> res = s.generateMatrix(3);
  for (auto i = 0; i < res.size(); i++)
  {
    for (auto j = 0; j < res[i].size(); j++)
    {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
}
