/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
// class MinStack {
//     stack<int> x_stack;
//     stack<int> min_stack;
// public:
//     /** initialize your data structure here. */
//     MinStack() {
//         min_stack.push(INT_MAX);
//     }
    
//     void push(int x) {
//         x_stack.push(x);
//         min_stack.push(min(min_stack.top(), x));   
//     }
    
//     void pop() {
//         x_stack.pop();
//         min_stack.pop();
//     }
    
//     int top() {
//         return x_stack.top();    
//     }
    
//     int getMin() {
//         return min_stack.top();    
//     }
// };


class MinStack {
public:
    /** initialize your data structure here. */
    int size=0,capacity=5;//若不想多次扩容，可将容量初始值增大
    int* elem,*min_elem;
    MinStack() {
        elem=new int[capacity];
        min_elem=new int[capacity];
    }
    ~MinStack() {
        delete[] elem;
        delete[] min_elem;
    }
    void update(){//扩容操作，开辟更大内存保存两个数组
        if(size>capacity-2){
            capacity*=2;
            int* temp1=new int[capacity];
            int* temp2=new int[capacity];
            for(int i=0;i<size;i++){//新内存初始化
                temp1[i]=elem[i];
                temp2[i]=min_elem[i];
            }
            delete[] elem;//删除原始内存
            delete[] min_elem;//删除原始内存
            elem=temp1;//指向新内存
            min_elem=temp2;//指向新内存
            temp1=nullptr;
            temp2=nullptr;
        }
    }
    void push(int x) {
        update();//每次push时检测是否需要扩容
        elem[size]=x;
        min_elem[size]= (size == 0) ? min(INT_MAX, x) :min(min_elem[size-1],x);//顶端保存[0,size]内的最小值
        size++;
    }
    
    void pop() {
        if(size>0)
           size--;
    }
    int top() {
        return elem[size-1];
    }
    
    int getMin() {
        return min_elem[size-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// @lc code=end

