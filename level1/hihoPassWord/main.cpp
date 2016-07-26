//
// Created by fengxuan on 2016/7/26.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a;
    cin >> a;

    vector<int> vec(a);

    for(int i = 0; i < a; ++i) {
        cin >> vec[i];
    }

    int flag = 0;

    for(int i = a - 2; i > 0; --i) {
        if(vec[i] >= vec[i + 1]) {
            flag = i;
            break;
        }
    }

    for(int i = 0; i <= flag; ++i) {
        cout << vec[i] << ' ';
    }
    cout << endl;

    return 0;
}