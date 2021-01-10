#include <iostream>
#include <stack>

using namespace std;

class CQueue {
public:
    stack<int> s1, s2;
    CQueue() {
        
    }
    
    void appendTail(int value) {
        printf("s1.push %d\n", value);
        s1.push(value);
        printf("s1.push %d\n", value);
    }
    
    int deleteHead() {
        if(s2.empty() == 1) {
            printf("s12.push \n");
            if(s1.empty() == 1) {
                return -1;
            }

        }

        if(s2.empty()) {
            int n = s1.size();
                for(int i = 0; i<n; i++) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        printf("s14.push\n");
        int ret = s2.top();
        s2.pop();
        return ret;
    }
};

int main()
{
    int ret = -1;
    FILE *f;
    printf("输出 %d\n", ret);
    CQueue *q =  new CQueue();
    printf("输出 %d\n", ret);
    q->appendTail(3);

    ret = q->deleteHead();

    printf("输出 %d\n", ret);

    ret = q->deleteHead();
    printf("输出 %d\n", ret);

    getc(f);
}