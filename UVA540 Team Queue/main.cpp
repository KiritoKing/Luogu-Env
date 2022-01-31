// UVA540 Team Queue
#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;

int teams[1000001]; // 用于存储0~999999编码人员对应的队伍

int main() {
    // FILE* fp = freopen("output.txt", "w", stdout);
    int times = 1;
    while(1) {
        int teamNum;
        bool firstLineNeed = true;
        scanf("%d", &teamNum);
        if(teamNum == 0) {
            break; // 程序出口
        }
        for(int i=0; i<teamNum; i++) {
            int members;
            scanf("%d", &members);
            for(int j=0; j<members; j++) {
                int num;
                scanf("%d", &num);
                teams[num] = i; // 根据先后顺序定义团队编号
            }
        }
        queue<int> mainQueue; // 存储主队列存在的团队编号
        queue<int>* teamQueue = new queue<int>[teamNum]; // 存储每个团队内部队列
        char command[100];
        while(1) {
            scanf("%s", command);
            if(command[0] == 'E') {
                int index;
                scanf("%d", &index);
                int team = teams[index];
                if(teamQueue[team].empty()) { // 团队没有人在排队
                    mainQueue.push(team);
                }
                teamQueue[team].push(index);

            }
            else if(command[0] == 'D') {
                if(firstLineNeed) {
                    printf("Scenario #%d\n", times++);
                    firstLineNeed = false;
                }
                while(teamQueue[mainQueue.front()].empty()) mainQueue.pop();
                printf("%d\n", teamQueue[mainQueue.front()].front());
                teamQueue[mainQueue.front()].pop();
            }
            else if(command[0] == 'S') {
                printf("\n");
                break;
            }
            else break;
        }
        delete[] teamQueue;
    }
    // fclose(fp);
}