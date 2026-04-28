#include <iostream>
#include <vector>
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
  int removeElement(vector<int> &nums, int val) {
    int size = nums.size();
    int slow_idx = 0;
    for (auto fast_idx = 0;  fast_idx < size;  fast_idx++)
    {
      /* code */
      if(nums[fast_idx] != val){
        nums[slow_idx] = nums[fast_idx];
        slow_idx++;
      }
    }
    return slow_idx;
    
  };
};
int main()
{
  Solution4 s;
  vector<int> nums = {3, 2, 2, 3};
  int val = 3;
  int result = s.removeElement(nums, val);
  cout << "result: " << result << endl;
  for (auto i = 0; i < 4; i++)
  {
    /* code */
    cout << nums[i] << " ";
  }
}
