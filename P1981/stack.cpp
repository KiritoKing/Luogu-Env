// P1981 [NOIP2013 普及组] 表达式求值

#include <cstdio>
#include <stack>
using namespace std;

class rollStack {
    int data[4];
    int top;

public:
    int num;
    rollStack(): top(0) {for(int i = 0; i<4; i++) data[i] = 0;};
    void push(int x);
    int pop();
    int calc() {
        num = data[3]+data[2]*10+data[1]*100+data[0]*1000;
        return num;
    }
    void clear() {
        top = 0;
        for(int i = 0; i<4; i++) data[i] = 0;
    }
    operator int() {return num;}
};

void rollStack::push(int x) {
        data[0] = data[1];
        data[1] = data[2];
        data[2] = data[3];
        data[3] = x;
}

int rollStack::pop() {
    if( top > 0 ) {
        return data[top--];
    }
    else {
        return data[top];
    }
}

int main() {
    stack<int> nums;
    char ch = getchar();
    rollStack buf;
    bool op = false; // 当运算符为乘法时为真
    while(ch != '\n') {
        if(ch != '+' && ch != '*') {
            buf.push(ch-'0');
        }
        else {
            nums.push(buf.calc());
            buf.clear();
            if(op) {
                int temp = nums.top();
                nums.pop();
                temp *= nums.top();
                temp = temp % 10000;
                nums.pop();
                nums.push(temp);
            }
            if(ch == '*') op = true;
            else op = false;
        }
        ch = getchar();
        if(ch == '\n') {
            nums.push(buf.calc());
            buf.clear();
            if(op) {
                int temp = nums.top();
                nums.pop();
                temp *= nums.top();
                temp = temp % 10000;
                nums.pop();
                nums.push(temp);
            }
        }
    }
    int res = 0;
    while(!nums.empty()) {
        res = (res + nums.top()) % 10000;
        nums.pop();
    }
    printf("%d", res);
}