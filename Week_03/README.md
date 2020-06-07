学习笔记

### 递归

>模版
```python
def recursion(level, params1, params2,...):
    #  recursion terminator 递归终结条件
    if level > MAX_LEVEL:
        process_result
        return 
    # process logic in current level 处理当前层逻辑
    process(level, data, ...)

    # drill down 下探到下一层
    self.recursion(level+1, p1, ...)

    # reverse the current level status if needed 清理当前层
```

>思维要点

```
1. 不要人肉递归
2. 找到最近简单的子问题，将其拆解成可重复的子问题
3. 数学归纳思维
```

#### 分治代码模版

```python
def divide_conquer(problem, params1, params2 ,...):
    # recursion terminator
    if problem is None:
        print_result
        return
    
    # prepare data
    data = prepare_data(problem)
    subproblems = split_problem(problem, data)

    # conquer subproblems
    subresult1 = self.divide_conquer(subproblems[0], p1, p2,...);
    subresult2 = self.divide_conquer(subproblems[1], p1, p2,...);
    subresult3 = self.divide_conquer(subproblems[2], p1, p2,...);
    ...

    # process and generate the final result
    result = process_result(subresult1, subresult2, subresult3,...)

    # revert the current level states
```