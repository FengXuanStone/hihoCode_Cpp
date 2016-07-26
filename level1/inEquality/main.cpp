//
// Created by fengxuan on 2016/7/26.
//
#include <iostream>

using namespace std;

const int MAX = 1001;
int num[MAX];

void insertOne(string str, int index) {
    if(str[0] == '=') {
        num[index]++;
    } else if(str[0] == '<') {
        int i;
        int ss = index < MAX ? index : MAX;
        for(i = 0; i < ss; ++i) {
            num[i]++;
        }
        if(str.length() != 1 && i != MAX)
            num[i]++;
    } else if(str[0] == '>') {
        int i;
        for(i = index + 1; i < MAX; ++i) {
            num[i]++;
        }
        if(str.length() != 1)
            num[index]++;
    }
}

int max() {
    int maxValue = 0;
    for(int i = 1; i < MAX; ++i) {
        maxValue = maxValue > num[i] ? maxValue : num[i];
    }
}

int main() {
    int a;
    cin >> a;

    string str;
    int index;

    while (a--) {
        cin >> str;
        cin >> str;
        cin >> index;

        insertOne(str, index);
    }
    cout << max() << endl;

    return 0;
}