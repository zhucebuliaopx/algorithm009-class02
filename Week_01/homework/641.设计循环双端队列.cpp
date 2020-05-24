/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
// class MyCircularDeque {  // 数组实现
// public:
//     int *data;
//     int capacity;
//     int front;
//     int rear;
//     /** Initialize your data structure here. Set the size of the deque to be k. */
//     MyCircularDeque(int k) {
//         capacity = k + 1;
//         data = new int[capacity];
//         front = rear = 0;
//     }
    
//     /** Adds an item at the front of Deque. Return true if the operation is successful. */
//     bool insertFront(int value) {
//         if (isFull()) return false;
//         front = (front - 1 +capacity)%capacity;
//         data[front] = value;
//         return true;
//     }
    
//     /** Adds an item at the rear of Deque. Return true if the operation is successful. */
//     bool insertLast(int value) {
//         if (isFull()) return false;
//         data[rear] = value;
//         rear = (rear + 1) % capacity;
//         return true;
//     }
    
//     /** Deletes an item from the front of Deque. Return true if the operation is successful. */
//     bool deleteFront() {
//         if (isEmpty()) return false;
//         front = (front + 1) % capacity;
//         return true;
//     }
    
//     /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
//     bool deleteLast() {
//         if (isEmpty()) return false;
//         rear = (rear - 1 + capacity) % capacity;  // 这里需要加一个capacity，保证当rear为0时，将rear正确移动到数组尾部索引
//         return true;
//     }
    
//     /** Get the front item from the deque. */
//     int getFront() {
//         if (isEmpty()) return -1;
//         return data[front];
//     }
    
//     /** Get the last item from the deque. */
//     int getRear() {
//         if (isEmpty()) return -1;
//         return data[(rear - 1 +capacity) % capacity];
//     }
    
//     /** Checks whether the circular deque is empty or not. */
//     bool isEmpty() {
//         return (front == rear);
//     }
    
//     /** Checks whether the circular deque is full or not. */
//     bool isFull() {
//         return ((rear+1) % capacity) == front;  // 此处rear+1是为了是判空，判满两个条件都成立，不矛盾，人为使实际容量缩小了一个单位, 同时尾部本身不添加元素
//     }
// };


class MyCircularDeque {  // 链表实现
public:
    struct Node {
        int value;
        Node *prev;
        Node *next;
        Node(): value(-1), prev(nullptr), next(nullptr){}
        Node(int value): value(value), prev(nullptr), next(nullptr){}
    };

    int size;
    int capacity;
    Node *front;
    Node *rear;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = 0;
        capacity = k;
        front = new Node();
        rear = new Node();
        front->next = rear;
        rear->prev = front;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) return false;
        Node *new_node = new Node(value);
        front->next->prev = new_node;
        new_node->next = front->next;
        front->next = new_node;
        new_node->prev = front;
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;
        Node* new_node = new Node(value);
        Node* prev = rear->prev;

        prev->next = new_node;
        new_node->prev = prev;
        new_node->next = rear;
        rear->prev = new_node;
        size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        Node* node = front->next;
        front->next = front->next->next;
        front->next->prev = front;

        delete node;  // 记得删除多余的节点
        node = NULL;
        size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        Node *node = rear->prev;
        rear->prev->prev->next = rear;
        rear->prev = rear->prev->prev;

        delete node;
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
        return front->next->value;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        return rear->prev->value;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return (front->next == rear);
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

