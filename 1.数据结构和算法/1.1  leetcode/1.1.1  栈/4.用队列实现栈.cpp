#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:

    queue<int> q;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int n = q.size();
        // 先插入
        q.push(x);

        for(int i=1; i<=n; i++) {
            //把前面的值全部出队，然后再入队
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q.empty() == 1) {
            return -1;
        }
        int top = q.front();
        q.pop();

        return top;
    }
    
    /** Get the top element. */
    int top() {
        if(q.empty() == 1) {
            return -1;
        }

        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{
    FILE *f;
    printf("nihao\n");
    getc(f);
}