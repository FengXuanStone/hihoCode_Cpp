//
// Created by fengxuan on 2016/7/26.
//
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 9;
int graph[MAXN], visit[MAXN], result[MAXN];
int flag = 0;

bool isNine() {
    //行
    for(int i = 0; i < 9; i = i + 3) {
        if(graph[i] + graph[i + 1] + graph[i + 2] != 15) {
            return false;
        }
    }
    //列
    for(int i = 0; i < 3; ++i) {
        if(graph[i] + graph[i + 3] + graph[i + 6] != 15) {
            return false;
        }
    }
    //对角线
    if((graph[0] + graph[4] + graph[8] != 15) ||
            (graph[2] + graph[4] + graph[6] != 15)) {
        return false;
    }

    return true;
}

void numberNine(int index) {
    if(index == 9) {
        if(isNine()) {
            flag++;
            if(flag == 1) {
                for(int i = 0; i < 9; ++i) {
                    result[i] = graph[i];
                }
            }
            return;
        }
    } else if(index < 9) {
        int next = index + 1;
        if(graph[index]) {
            numberNine(next);
        } else {
            for(int i = 0; i < 9; ++i) {
                if(visit[i] == 1) continue;
                visit[i] = 1;
                graph[index] = i + 1;
                numberNine(next);
                visit[i] = 0;
                graph[index] = 0;
            }
        }
    }

    return;
}

int main() {
    for(int i = 0; i < 9; i++) {
        int a;
        cin >> a;
        graph[i] = a;
        visit[a - 1] = 1;
    }

    numberNine(0);

    if(flag == 1) {
        for(int i = 0; i < 9; i = i + 3) {
            cout << result[i] << ' ' << result[i + 1] << ' ' << result[i + 2] << endl;
        }
    } else {
        cout << "Too Many" << endl;
    }

    return 0;
}
