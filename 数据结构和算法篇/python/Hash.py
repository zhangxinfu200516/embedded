class HashTableChaining:
    """使用链地址法解决冲突的哈希表实现。"""

    def __init__(self, size=10):
        """初始化哈希表。
        :param size: 底层数组的初始大小
        """
        self.size = size
        # 创建一个大小为 `size` 的列表，每个元素初始化为一个空列表（代表链表）
        self.table = [[] for _ in range(size)]

    def _hash(self, key):
        """内部哈希函数。这里使用Python内置的hash函数并取模。"""
        return hash(key) % self.size

    def insert(self, key, value):
        """向哈希表中插入一个键值对。"""
        index = self._hash(key)
        bucket = self.table[index] # 获取该索引对应的"桶"（链表）

        # 遍历桶，检查键是否已存在
        for i, (k, v) in enumerate(bucket):
            if k == key:
                # 键已存在，更新值
                bucket[i] = (key, value)
                return
        # 键不存在，添加到链表末尾
        bucket.append((key, value))

    def get(self, key):
        """根据键获取值。如果键不存在则返回None。"""
        index = self._hash(key)
        bucket = self.table[index]

        for k, v in bucket:
            if k == key:
                return v
        return None # 键不存在

    def delete(self, key):
        """根据键删除键值对。"""
        index = self._hash(key)
        bucket = self.table[index]

        for i, (k, v) in enumerate(bucket):
            if k == key:
                del bucket[i] # 从链表中删除该节点
                return True # 删除成功
        return False # 键不存在，删除失败

    def display(self):
        """打印哈希表的所有内容。"""
        for i, bucket in enumerate(self.table):
            print(f"索引 {i}: {bucket}")

# 使用示例
print("\n--- 链地址法哈希表示例 ---")
phone_book = HashTableChaining(5)
phone_book.insert("Alice", "123-4567")
phone_book.insert("Bob", "987-6543")
phone_book.insert("Charlie", "555-1234")
# 假设"David"的哈希值与"Alice"冲突（为了演示）
phone_book.insert("David", "111-2222")

print("插入数据后的哈希表：")
phone_book.display()

print(f"\n查找 'Bob' 的电话: {phone_book.get('Bob')}")
print(f"查找不存在的 'Eve': {phone_book.get('Eve')}")

phone_book.delete("Charlie")
print("\n删除 'Charlie' 后的哈希表：")
phone_book.display()