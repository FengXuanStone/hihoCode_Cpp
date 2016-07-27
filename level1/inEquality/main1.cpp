//
// Created by fengxuan on 2016/7/27.
//
#include <iostream>

using namespace std;

#define MAXN 55
string s,op[MAXN];
int n,num[MAXN];

int main() {
    cin >> n;

    for(int i = 0; i < n; ++i) {
        int tmp;
        cin >> s >> op[i] >> tmp;
        num[i] = tmp * 2;
    }
    int maxn = 1;
    for(int x = -1;x <= 2002;x++)
    {
        int tem = 0;
        for(int k = 0;k < n;k++)
        {
            if(op[k] == "=" && x == num[k]) tem++;
            else if(op[k] == "<=" && x <= num[k]) tem++;
            else if(op[k] == ">=" && x >= num[k]) tem++;
            else if(op[k] == "<" && x < num[k]) tem++;
            else if(op[k] == ">" && x > num[k]) tem++;
        }
        maxn = max(maxn,tem);
    }
    cout << maxn << endl;

    return 0;
}