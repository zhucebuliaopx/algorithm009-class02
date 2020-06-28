学习笔记

### 深度优先算法(dfs)

>模版
```python
- 示例
def dfs(node):
    if node in visited:
        # alreaady visited
        return
    
    visited.add(node)

    # process current Node
    # ... logic here
    dfs(node.left)
    dfs(node.right)
# 也可用栈实现

- 递归写法
visited = set()
def dfs(node, visited):
    if node in visited: 
        # already visited
        return
    visited.add(node)
    # process current Node
    ...
    for next_node in node.children():
        if not next_node in visited:
            dfs(next_node, visited)
- 非递归写法
def dfs(self, tree):
    if tree.root is None:
        return
    visited, stack = [],[tree.root]

    while stack: 
        node = stack.pop()
        visited.add(node)

        process(node)
        nodes = generate_related_nodes(node)
        stack.push(nodes)

        # other process work
        ...
```

### 广度优先遍历(bfs)

> 模版
```python
def bfs(graph, start, end):
    queue = []
    queue.append([start])
    visited.add(start)

    while queue: 
        node = queue.pop()
        visited.add(node)

        process(node)

        nodes = generate_related_nodes(node)
        queue.push(nodes)
    
    # other processing work
    ...

```

>二分模版

```
left, right = 0, len(array)-1
while left <= right:
    mid = (left+right)/2
    if array[mid] == target:
        # find the target
        break or return result
    elif array[mid] < target:
        left = mid + 1
    else:
        right = mid - 1
```

>习题

```
- 使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方
思路：先找到中间位置的值mid，在使用左右指针分别指向mid的最左和最右边，每次判断mid与left，right的值大小，如果left > mid && right > mid,那么mid赋给right，如果left < mid && right < mid ,mid赋给left,依次类推，最后找到的两个值为中间无序的部分
```