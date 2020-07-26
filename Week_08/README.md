学习笔记

### 位运算

>基础概念
```
- 与 &
全1为1，有0则0
- 或 ｜
有1为1，全0为0
- 非 ～
取反
- 异或 ^
相同为1不同为0
```

>技巧
```
- 判断奇偶
x % 2 == 1 -> (x&1) == 1
x % 2 == 0 -> (x&0) == 0

- x >> 1 -> x/2
x = x/2 -> x = x>>1
mid = (left+right)/2 -> mid = (left+right)>>1

- 清零最低位的1
x=x&(x-1)

- 得到最低位的1
x&-x

- x&~x => 0
```

### bloom filetr
>基础概念
```
- 概念
一个很长的二进制向量和一系列随机映射函数
- 作用
可以用于检索一个元素是否在一个集合中，一般用作缓存过滤层，将不存在的数据直接返回，存在的元素继续向后查询是否存在 
- 优点
空间效率和查询时间都远远超过一般的算法
- 缺点
一定的错误识别率和删除困难
```
### lrucache

>demo
```python
class LRUCache(object):
    def __init__(self, capacity):
        self.dic = collections.OrderedDic()
        self.remain = capacity
    
    def get(self, key):
        if key not in self.dic:
            return -1
        v = self.dic.pop(key)
        self.dic[key] = v
        return v
    
    def put(self, key, value):
        if key in self.dic:
            self.dic.pop(key)
        else:
            if self.remain > 0:
                self.remain -= 1
            else:
                self.dic.popitem(last=False)
            self.dic[key] = value

```


### 排序算法

```
- 比较类排序
通过比较来决定元素间的相对次序，由于其时间复杂度不能突破O(logn)，因此也称为非线性时间比较类排序

-非比较类排序
不通过比较来决定元素间的相对次序，他可以突破基于比较类的时间下限，以线性时间运行
```

>初级排序O(n^2)
```
- 选择排序
每次找最小值，然后放到待排序数组的起始位置
- 插入排序
从前到后逐步构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置插入
- 冒泡排序
嵌套循环，每次查看相邻的元素如果逆序，则交换
```

>高级排序-O(Nlogn) **重点**

- 快速排序
数组取标杆pivot，将小元素放pivot左边，大元素放右边，然后依次对右边和右边的子数组继续快排

>demo
```python
def quick_sort(array, begin, end):
    if end <= begin: return
    def partition(array, begin, end):
        pivot = end, counter = begin
        for i in range(begin, end):
            if a[i] < a[pivot]: 
                a[counter], a[i] = a[i], a[counter]
                counter += 1
        a[pivot], a[counter] = a[counter], a[pivot]
        return counter

    pivot = partition(array, begin, end)
    quick_sort(array, begin, pivot -1)
    quic_sort(array, pivot+1, end)

```

- 归并排序-分治
1. 把长度为n的输入序列分成两个长度为n/2的子序列
2. 对这两个子序列分别采用归并排序
3. 将这两个排序好的子序列合并成一个最终的排序序列

>demo

```python
def merge_sort(array, left, right):
    if right <= left: return
    mid = left+(right-left)>>1

    def merge(array, left, mid, right):
        tmp = []
        i = left, j = mid+1, k = 0
        while i <= mid and j <= right:
            tmp[k] = array[i] if array[i] < array[j], i+=1 else array[j], k+=1
            k += 1
        while (i <= mid):
            tmp[k] = array[i]
            i += 1, k += 1
        while (j <= right):
            tmp[k] = array[j]
            k += 1, j += 1
        for p, d in enum(tmp):
            array[left+p] = d


    merge_sort(array, left, mid)
    merge_sort(array, mid+1, right)
    merge(array, left, mid, right)
```

>归并与快排区别

```
- 归并
先排序左右子数组，然后合并两个有序数组
- 快排
先调配出左右子数组，然后对于左右子数组排序
```

- 堆排序

插入(nlogn),取最值O(1)
1. 数组元素依次建立小顶堆
2. 依次取堆顶元素，并删除

>demo

```c++
void heap_sort(int a[], int len){
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < len; ++i){
        q.push(i);
    }

    for (int i =0:i < len; ++i){
        a[i] = q.pop();  // 返回最小值
    }
} 
```

>特殊排序O(n)
- 计数排序
要求输入的数据必须是有确定范围的整数，将输入的数据值转化为键存储在额外开辟的数组空间中，然后依次把计数于1的填充回原数组
- 桶排序
假设输入的数据服从均匀分布，将数据分到有限数量的桶里，每个桶在分别排序（可以使用别的排序算法或以递归的方式继续使用桶排序）
- 基数排序
按照低位先排序，然后收集，再按照高位排序，然后在收集，依次类推，直到最高位，