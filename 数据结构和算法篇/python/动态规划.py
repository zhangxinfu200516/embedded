#递推数组（自底向上，标准DP）
def climb_stairs_dp(n: int) -> int:
    """动态规划（自底向上）"""
    if n <= 2:
        return n
    # 1. 定义状态数组：dp[i] 表示爬到第 i 级台阶的方法数
    dp = [0] * (n + 1)
    # 2. 确定初始条件
    dp[1] = 1
    dp[2] = 2
    # 3. 状态转移：根据状态转移方程递推
    for i in range(3, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    # 4. 返回最终结果
    return dp[n]

print(f"爬到第 5 级台阶的方法数（DP）: {climb_stairs_dp(5)}")  # 输出: 8