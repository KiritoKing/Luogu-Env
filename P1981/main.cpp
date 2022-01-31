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
    int getTop() {return data[top];}
    int size() {return top+1;}
    int calc() {
        num = data[3]+data[2]*10+data[1]*100+data[0]*1000;
        return num;
    }
    operator int() {return num;}
};

void rollStack::push(int x) {
    if(top < 4) {
        data[3-(top++)] = x;
    }
    else {
        data[0] = data[1];
        data[1] = data[2];
        data[2] = data[3];
        data[3] = x;
    }
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
    rollStack numbers[10];
    int calcQueue[1000];
    int ira = 0;
    int calcIra = 0;
    char ch = getchar();
    int op = -1; //指定操作符 加为0 乘为1 不计算为-1
    while(ch != '\n') {
        if(ch != '+' && ch != '*') {
            numbers[ira].push(ch-'0');
        }
        else {
            numbers[ira].calc();
            if(op == 1) { //相乘
                numbers[ira-1].num = (numbers[ira-1] * numbers[ira]) & 10000;
            }
            else if(op == 0) { //相加
                numbers[ira-1].num = (numbers[ira-1] + numbers[ira]) & 10000;
            }
            else if(op == -1) {
                ira++;
            }
            switch (ch)
            {
            case '+':
                op = 0;
                break;
            case '*':
                op = 1;
                break;
            default:
                op = -1;
                break;
            }
        }
        ch = getchar();
        if(ch == '\n') {
            numbers[ira].calc();
            if(op == 1) { //相乘
                numbers[ira-1].num = (numbers[ira-1] * numbers[ira]) % 10000;
            }
            else if(op == 0) { //相加
                numbers[ira-1].num = (numbers[ira-1] + numbers[ira]) % 10000;
            }
            else if(op == -1) {
                ira++;
            }
        }
    }
    printf("%d", numbers[0].num);
}