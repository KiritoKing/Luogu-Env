// P1162 填涂颜色

#include <cstdio>
#include <cstring>

int n;
int map[32][32];
void dfs(int x, int y) {
    static const int moveX[] = {-1,1,0,0};
    static const int moveY[] = {0,0,-1,1};
    if(x<0||y<0||x>n+1||y>n+1||map[x][y]!=0) return;
    map[x][y] = -1; // 在外面的0全部染色为-1
    for(int i=0; i<4; i++) dfs(x+moveX[i], y+moveY[i]);
}

int main() {
    scanf("%d", &n);
    memset(map, 0, 32*32);
    // 从1开始读取 保证外圈是0
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    dfs(0,0);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(map[i][j] == 0) printf("2 ");
            else if(map[i][j] == -1) printf("0 ");
            else printf("%d ", map[i][j]);
        }
        putchar('\n');
    }
}