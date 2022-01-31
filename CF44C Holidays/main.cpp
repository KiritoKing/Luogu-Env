#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int n,m; //n为天数 m为人数
    scanf("%d %d", &n, &m);
    int* daysRecord = new int[n]; //记录每天被浇花的次数
    memset(daysRecord, 0, sizeof(int)*n);
    for(int i = 0; i<m; i++){
        int start, end;
        scanf("%d %d", &start, &end);
        if(start <= end) {
            for(int j = start -1; j<end; j++){
                daysRecord[j]++;
            }
        }
    }
    int flag = -1;
    for(int i = 0; i < n; i++) {
        if(daysRecord[i] != 1){
            flag = i;
            break;
        }
    }
    if(flag == -1){
        printf("OK");
    }
    else{
        printf("%d %d", flag+1, daysRecord[flag]);
    }
}