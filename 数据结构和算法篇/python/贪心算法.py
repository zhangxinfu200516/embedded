def coin_change_greedy(coins, amount):
    """
    使用贪心算法解决找零钱问题（针对特定硬币体系）
    :param coins: list[int], 硬币面值列表，应降序排列
    :param amount: int, 需要找零的总金额
    :return: list[int], 使用的硬币面值列表
    """
    coins.sort(reverse=True)  # 确保硬币按面值从大到小排序
    result = []  # 用于存放找零的硬币
    remaining = amount  # 剩余需要找零的金额

    for coin in coins:
        # 当当前硬币面值小于等于剩余金额时，就尽可能多地使用它
        while remaining >= coin:
            result.append(coin)
            remaining -= coin  # 从剩余金额中扣除当前硬币面值

    # 检查是否正好找开
    if remaining == 0:
        return result
    else:
        # 对于无法正好找开的情况（虽然在此硬币体系下不会发生）
        return None

# 测试数据
test_coins = [100, 50, 20, 10, 5, 1]
test_amount = 186  # 1元8角6分

change = coin_change_greedy(test_coins, test_amount)
print(f"找零 {test_amount} 分，需要硬币：{change}")
print(f"硬币数量：{len(change)} 枚")
# 输出：找零 186 分，需要硬币：[100, 50, 20, 10, 5, 1]
# 硬币数量：6 枚


def interval_scheduling(intervals):
    """
    解决最大不相交区间问题（区间调度）
    :param intervals: list of [start, end], 区间列表
    :return: list of [start, end], 被选中的区间列表
    """
    # 1. 按结束时间升序排序
    intervals_sorted = sorted(intervals, key=lambda x: x[1])
    
    selected = []  # 存放被选中的区间
    last_end_time = -float('inf')  # 初始化上一个选中区间的结束时间
    
    for interval in intervals_sorted:
        start, end = interval
        # 2. 贪心选择：如果当前区间的开始时间不早于上一个选中区间的结束时间，则选择它
        if start >= last_end_time:
            selected.append(interval)
            last_end_time = end  # 更新最后结束时间
    
    return selected

# 测试数据：每个子列表代表一个会议 [开始时间, 结束时间]
test_intervals = [
    [1, 3], [2, 4], [3, 5], [4, 6], [5, 7],
    [1, 2], [2, 3], [1, 4]
]

result = interval_scheduling(test_intervals)
print("最多可以安排的会议（按结束时间排序后）：")
for meeting in result:
    print(f"  会议 [{meeting[0]}, {meeting[1]}]")
print(f"总计 {len(result)} 个会议")
# 一种可能的输出（因为排序后顺序可能不同，但数量最优）：
# 会议 [1, 2]
# 会议 [2, 3]
# 会议 [3, 5] 或 [4, 6] 等
# 总计 4 个会议