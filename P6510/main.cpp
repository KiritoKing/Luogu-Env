// P6510 奶牛排队

#include <cstdio>
#include <stack>
using namespace std;

// 获取从右到左升序单调栈序列（左边第一个比它大）
int* upStack(const int* arr, int n) {
    stack<int> bucket; // bucket存储对应序号
    int* res = new int[n];
    for(int i = 0; i<n; i++) {
        while(!bucket.empty() && arr[i] >= arr[bucket.top()]) {
            bucket.pop();
        }
        res[i] = bucket.empty()? -1: bucket.top(); //-1表示方便+1后从0开始
        bucket.push(i);
    }
    return res;
}
// 获取从左到右降序单调栈序列（右边第一个比它小）
int* downStack(const int* arr, int n) {
    stack<int> bucket;
    int* res = new int[n];
    for(int i = n-1; i>=0; i--) {
        while(!bucket.empty() && arr[i] <= arr[bucket.top()]) {
            bucket.pop();
        }
        res[i] = bucket.empty()? n: bucket.top();
        bucket.push(i);
    }
    return res;
}

int main() {
    unsigned int n; // 奶牛头数
    scanf("%u", &n);
    int* heights = new int[n];
    for(int i = 0; i<n; i++) {
        scanf("%d", &heights[i]);
    }
    // 注意序列是从右到左的
    int* up = upStack(heights, n); //左边第一个比它大的序列
    int* down = downStack(heights, n); //右边第一个比它小的序列
    int ans = 0; //存储答案的序列长度
    for(int i = n-1; i>=0; i--) {
        for(int j = up[i]+1; j<i; j++) { //不用<=因为不能长度为1
            if(down[j]>i) {
                int temp = i - j + 1;
                ans = temp > ans ? temp : ans;
            }
        }
        if(i<=ans) break; //向左遍历 若总长度小于现有最长则直接break
    }
    printf("%d", ans);
}