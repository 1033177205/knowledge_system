#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    stack<int> s1;
    bool isValid(string s) {
        for (char c : s) {

            if(c == '(' || c == '[' || c == '{') {
                //等于小括号进栈
                s1.push(c);
            } else if(c == ')' || c == ']' || c == '}') {
                if(s1.empty() == 1) {
                    return false;
                }

                char c1 = s1.top();
                if( (c == ')' && c1 == '(') || (c == ']' && c1 == '[') || (c == '}' && c1 == '{') ) {
                    s1.pop();
                } else {
                    return false;
                }
            }
        }

        //判断一下栈是否空了
        if(s1.empty() == 1) {
            return true;
        } else {
            return false;
        }
        
    }
};

int main()
{
    FILE *f;

    getc(f);
}