#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s, s_min;
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);

        if(s_min.empty() == 1) {
            s_min.push(x);
        } else {
            if(s_min.top() >= x) {
                s_min.push(x);
            }
        }
    }
    
    void pop() {
        if(s.empty() == 1) {
            return ;
        }

        if(s.top() == s_min.top()) {
            s_min.pop();
        }

        s.pop();
    }
    
    int top() {
        if(s.empty() == 1) {
            return -1;
        }

        return s.top();
    }
    
    int getMin() {
        if(s_min.empty() == 1) {
            return -1;
        }

        return s_min.top();
    }
};

int main()
{
    FILE *f;

    getc(f);
}