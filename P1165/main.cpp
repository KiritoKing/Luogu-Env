// P1165 日志分析
#include <cstdio>
#include <stack>
using namespace std;

int main() {
    stack<int> max;
    max.push(0);
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++) {
        int op;
        scanf("%d", &op);
        if(op == 0) {
            int weight;
            scanf("%d", &weight);
            max.push(weight > max.top()? weight : max.top());
        }
        else if(op == 1) {
            if(max.size() > 1) {
                max.pop();
            }
        }
        else if(op == 2) {
            printf("%d\n",max.top());
        }
    }
}