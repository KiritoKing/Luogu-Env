#include <cstdio>
#include <stack>
using namespace std;

int main() {
    unsigned int n;
    scanf("%u", &n);
    int* arr = new int[n];
    int* res = new int[n];
    for(int i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    stack<int> singStack;
    for(int i = n-1; i>=0; i--) {
        while(!singStack.empty() && arr[i]>=arr[singStack.top()]) {
            singStack.pop();
        }
        res[i] = singStack.empty()? 0: singStack.top();
        singStack.push(i);
    }
    for(int i = 0; i<n; i++) {
        printf("%d ", res[i]? res[i]+1: res[i]);
    }
}