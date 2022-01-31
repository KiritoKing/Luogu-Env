//P1449 后缀表达式

#include <cstdio>
using namespace std;

int main() {
    int stack[1001];
    int ira = 0;
    int numToPush = 0;
    char ch = getchar();
    while(ch != '@') {
        if(ch>='0' && ch<='9') {
            numToPush *= 10;
            numToPush += ch-'0';
        }
        else if(ch == '.') {
            stack[ira++] = numToPush;
            numToPush = 0;
        }
        else if(ch == '+') {
            stack[ira--];
            stack[ira-1] += stack[ira];
        }
        else if(ch == '-') {
            stack[ira--];
            stack[ira-1] -= stack[ira];
        }
        else if(ch == '*') {
            stack[ira--];
            stack[ira-1] *= stack[ira];
        }
        else if(ch == '/') {
            stack[ira--];
            stack[ira-1] /= stack[ira];
        }
        ch = getchar();
    }
    printf("%d", stack[0]);
    return 0;
}