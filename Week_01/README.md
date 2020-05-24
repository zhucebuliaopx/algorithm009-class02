学习笔记

###summay

>数组
```
- 时间复杂度
prepend O(1) ???? 
append O(1)
lookup O(1)
insert O(n)
delete O(n)
```

>链表
```
- 时间复杂度
prepend O(1)
append O(1)
lookup O(n)
insert O(1)
delete O(1)
```
> 链表优化加速实现::跳表
```
- 时间复杂度 O(logn)
N/2，n/4，。。。第k级索引节点个数n/(2^k),索引高h，最高级索引2个节点，n/(2^h)=2==>h=log2(n)-1
- 空间复杂度 O(n)
原始链表大小为n，每2个节点抽一个每层索引个数n/2，n/4，。。。，8，4，2,
原始链表大小为n，每3个节点抽一个每层索引个数n/3，n/9，。。。，9，3，1,
...
```

>Q&A
```
- 做题的数量增加，但是遍数跟不上
```

###Java的queue源码分析

#####PriorityQueue

>init
```
队列使用堆实现
```

>func::findSlot
```
获取一个空的slot，返回他的索引，用来存放数据，这里肯定会返回一个，不够的话会调用resize动态增大
```

>func::offer
```
完成赋值操作，并调整新节点在树上的位置
```

>func::poll
```
移除头节点，返回新的队列
```

>func::remove
```
删除指定节点，需要遍历队列
```

>func::addAll
```
合并一个指定的集合，自身不能实现合并，需要时新的集合，遍历新集合完成合并，当val不能为null
```

>func::peek
```
获取头节点，没有的话返回null
```

>func::remove(内部函数)
```

```

>func::bubbleUp（内部函数）
```
将新的节点移动到合适的位置
```

>func::resize（内部函数）
```
重置队列容量为当前的2倍
```