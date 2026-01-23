from collections import deque  # 使用Python双端队列，它提供了高效的头部和尾部操作

class Queue:
    """使用 collections.deque 实现队列"""
    def __init__(self):
        self.items = deque()

    def enqueue(self, item):
        """入队"""
        self.items.append(item)  # 从右侧（队尾）添加

    def dequeue(self):
        """出队，如果队空则返回None"""
        if not self.is_empty():
            return self.items.popleft()  # 从左侧（队头）移除
        return None

    def front(self):
        """查看队头元素"""
        if not self.is_empty():
            return self.items[0]
        return None

    def is_empty(self):
        """检查队列是否为空"""
        return len(self.items) == 0

    def size(self):
        """返回队列的大小"""
        return len(self.items)

# 应用示例：模拟打印任务
print("\n=== 队列与打印任务模拟 ===")
printer_queue = Queue()

# 模拟三个打印任务到达
tasks = ["Alice的简历.pdf", "Bob的报告.doc", "Charlie的图表.png"]
for task in tasks:
    printer_queue.enqueue(task)
    print(f"任务 '{task}' 已加入打印队列。")

# 处理打印任务
print("\n开始打印...")
while not printer_queue.is_empty():
    current_task = printer_queue.dequeue()
    print(f"正在打印: {current_task}")
    # 模拟打印耗时
print("所有打印任务已完成。")