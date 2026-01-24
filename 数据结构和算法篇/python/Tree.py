class TreeNode:
    """二叉树节点类"""
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def __str__(self):
        return f"Node({self.value})"

def preorder_traversal(node):
    """前序遍历：根 -> 左 -> 右"""
    if node is None:
        return
    print(node.value, end=' ')  # 1. 访问当前节点
    preorder_traversal(node.left)   # 2. 遍历左子树
    preorder_traversal(node.right)  # 3. 遍历右子树
# 创建节点
root = TreeNode(1)
node2 = TreeNode(2)
node3 = TreeNode(3)
node4 = TreeNode(4)
node5 = TreeNode(5)
node6 = TreeNode(6)

# 构建连接关系 (Links)
root.left = node2
root.right = node3
node2.left = node4
node2.right = node5
node3.right = node6

#print(root)
preorder_traversal(root)
preorder_traversal(node2)