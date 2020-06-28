学习笔记

#### 递归代码模版

```java
public void recur(int level, int param){
    // terminator
    if (level > MAX_LEVEL){
        // process result
        return;
    }
    // process current logic
    process(level, param);

    // drill down
    recur(level+1, new_param);

    // restore current status
}
```

#### 分治模版代码

```python
def divide_conquer(problem, params1, params2 ,...):
    #  recursion terminator
    if problem is None:
        print_result
        return

    # prepare data
    data = prepare_data(problem)
    subproblems = split_problem(problem, data)

    # conquer subproblems
    subresult1 = self.divide_conquer(subproblems[0], p1, p2,...)
    subresult2 = self.divide_conquer(subproblems[1], p1, p2,...)
    ...

    # process and generate final result
    result = process_result(subresult1, subresult2,...)

    # revert the current level states
```

#### 动态规划
>summay
```
- 动态规划和递归，分治没有本质的区别，关键看有没有最优子结构
1. 共性：找到重复子问题
2. 差异性：最优子节构，中途可以淘汰次优子结构
```
>动态转移方程（DP方程）

```
if a[i, j] == '空地':
    opt[i,j] = opt[i+1, j] + opt[i, j+1]
else:
    opt[i, j] = 0
```
>关键点

```
1. 最优子结构 opt[n] = best_of(opt[n-1], opt[n-2],...)
2. 储存中间状态 opt[i]
3. 递推公式 (就是dp方程)
fib: opt[i] = opt[n-1]+opt[n-2]
二位路径问题: opt[i,j] = opt[i+1, j]+opt[i, j+1]
```

> 实战：路径计数

```
int count_paths(bool[][] grid, int row, int column) {
    if (!validateSquare(grid, row, column)) return 0;
    if (is_at_end(grid, row, column)) return 1;
    return count_paths(grid, row+1, column) + count_paths(grid, row, column+1);
}
```

>遗留

```
363-矩形区域不超过 K 的最大数值和
https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/

874. 模拟行走机器人
https://leetcode-cn.com/problems/walking-robot-simulation/
```