// P1162 填涂颜色
#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int matrix[31][31];
    for(int i=0; i<n; i++) {
        bool fill = false;
        int start = 0;
        for(int j=0; j<n; j++) {
            scanf("%d", &matrix[i][j]);
            if(!fill && matrix[i][j] == 1) { // 开始填充
                fill = true;
                start = j+1;
            }
            else {
                if(matrix[i][j] == 1) { // 结束填充计算
                    if(j == start) start++;
                    else fill = false;
                    for(int k=start; k<j; k++) matrix[i][k] = 2;
                }
            }
        }
    }
    putchar('\n');
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", matrix[i][j]);
        }
        putchar('\n');
    }
}