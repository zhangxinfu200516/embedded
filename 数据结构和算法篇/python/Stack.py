class Stack:
    """使用列表实现栈"""
    def __init__(self):
        self.items = []

    def push(self, item):
        """入栈"""
        self.items.append(item)  # 列表末尾作为栈顶

    def pop(self):
        """出栈，如果栈空则返回None"""
        if not self.is_empty():
            return self.items.pop()
        return None

    def peek(self):
        """查看栈顶元素"""
        if not self.is_empty():
            return self.items[-1]
        return None

    def is_empty(self):
        """检查栈是否为空"""
        return len(self.items) == 0

    def size(self):
        """返回栈的大小"""
        return len(self.items)

# 应用示例：括号匹配检查
def is_balanced_parentheses(expression):
    """
    检查表达式中的括号是否匹配
    例如: (()) 平衡， (() 不平衡
    """
    stack = Stack()
    # 括号匹配映射
    matching_bracket = {')': '(', ']': '[', '}': '{'}

    for char in expression:
        if char in '([{':  # 如果是左括号，入栈
            stack.push(char)
        elif char in ')]}':  # 如果是右括号
            if stack.is_empty():
                return False  # 栈空，说明右括号多了
            top_char = stack.pop()
            if matching_bracket[char] != top_char:  # 检查是否匹配
                return False
    # 循环结束后，栈应为空
    return stack.is_empty()

# 测试栈和括号匹配
print("\n=== 栈与括号匹配演示 ===")
plate_stack = Stack()
plate_stack.push("盘子1")
plate_stack.push("盘子2")
plate_stack.push("盘子3")
print(f"取出最上面的盘子: {plate_stack.pop()}")  # 输出：盘子3
print(f"现在最上面的盘子是: {plate_stack.peek()}")  # 输出：盘子2

# 测试括号匹配
test_cases = ["((1+2)*3)", "({[ ]})", "((())", ")( )"]
for test in test_cases:
    result = "平衡" if is_balanced_parentheses(test) else "不平衡"
    print(f"表达式 '{test}' 的括号是 {result} 的。")