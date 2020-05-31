学习笔记

#### Heapsort

>堆的基本知识
```
- 堆的概念
堆是一种专门的树形数据结构，父节点总是大于等于(或者小于等于子节点)，分别对应着大根堆和小根堆
一般可以将堆看作是一棵树的数组对象
- 堆的实现
通常是构造二叉堆实现
- 二叉堆的特性
可以视为一棵完全二叉树，除了最底层的节点外，其余节点都是满的
```

>堆排序
```
- 基本思想
`堆排序` 就是利用堆的数据结构特性，对数据进行排序，倒序或者顺序排，可以分别使用大根堆或者小根堆，每次取出相应的最值，将剩下的值重新调整为相应的新堆，然后迭代取出最值，直到剩下最后一个数字

- 实现过程
1. 初始化 原数组为大根堆(小根堆)
2. 调整堆 排序过程需要保证堆的性质
3. 堆排序 将最值取出放入目标数组，剩下的数组重新开始步骤1，直至生一个数据

- 算法分析
*note
1. 是一种原地不稳定的排序

**Can we make any sorting algorithm stable?
Any given sorting algo which is not stable can be modified to be stable. There can be sorting algo specific ways to make it stable, but in general, any comparison based sorting algorithm which is not stable by nature can be modified to be stable by changing the key comparison operation so that the comparison of two keys considers position as a factor for objects with equal keys.

2. 堆排序的使用相比较实践表现更好的快排和归并来说，有一定的局限性，但总的来说堆排序在实践中用途也很大
*时间复杂度O(logn)
创建堆的过程时间复杂度为O(n),总体来说为O(logn)
```
>实例

```
- 初始化 建立堆的过程
Input data: 4, 10, 3, 5, 1
         4(0)
        /   \
     10(1)   3(2)
    /   \
 5(3)    1(4)

The numbers in bracket represent the indices in the array 
representation of data.

Applying heapify procedure to index 1:
         4(0)
        /   \
    10(1)    3(2)
    /   \
5(3)    1(4)

Applying heapify procedure to index 0:
        10(0)
        /  \
     5(1)  3(2)
    /   \
 4(3)    1(4)
The heapify procedure calls itself recursively to build heap in top down manner.

- 代码部分

// C++ program for implementation of Heap Sort 
#include <iostream> 
  
using namespace std; 
  
/* To heapify a subtree rooted with node i which is 
   an index in arr[]. n is size of heap 
*/
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        // 递归的将以i为根的子树初始化为目标堆，自顶向下
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    /* Build heap (rearrange array) 
       n/2-1获取到的刚好是最后一个子树的父节点的索引，然后开始一层层往上heapify数据,直到i为0为止，便可以获得初始堆
    */
    for (int i = n / 2 - 1; i >= 0; i--)   
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>0; i--) 
    { 
        // Move current root to end 
        // 将最值移到最后，相当于这部分是有序区，后边不用再处理
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        // 此时只有顶部元素不可能不符合堆的特性，从根部开始调整堆的结构
        heapify(arr, i, 0); 
    } 
} 
  
/* A utility function to print array of size n */
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 
  
// Driver program 
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    heapSort(arr, n); 
  
    cout << "Sorted array is \n"; 
    printArray(arr, n); 
} 


```

#### Hashmap

```

```