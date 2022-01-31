// P1162 填涂颜色
#include <cstdio>

struct MatNode {
    int data;
    bool read;
};

class Matrix {
    MatNode node[31][31];
    int size;

public:
    Matrix(int size);
    void dfs(int x, int y);
    void print();
};

Matrix::Matrix(int size): size(size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            scanf("%d", &node[i][j].data);
            if(node[i][j].data == 0) node[i][j].read =false;
            else node[i][j].read = true; // 边界也标记为已读
        }
    }
}

void Matrix::dfs(int x, int y) {
    // 标记动作，依次为左右下上移动
    static const int moveX[4] = {-1,1,0,0};
    static const int moveY[4] = {0,0,-1,1};
    if(x<0||x>size||y<0||y>size||node[x][y].read==true) return;
    node[x][y].read=true; // 标记为已读
    for(int i=0; i<4; i++) dfs(x+moveX[i], y+moveY[i]);
}

void Matrix::print() {
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            if(node[i][j].read == false) printf("2 ");
            else printf("%d ", node[i][j].data);
        }
        putchar('\n');
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Matrix mat(n);
    mat.dfs(0,0);
    mat.print();
}