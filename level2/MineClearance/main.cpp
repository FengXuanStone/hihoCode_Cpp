#include <iostream>
#include <algorithm>

//
// Created by fengxuan on 2016/7/24.
//

using namespace std;

void solveClearance(int nums[], int size, vector<int>& mine, vector<int>& empty) {
    vector<vector<int>> candidate;
    bool  flag;

    for(int i = 0; i < 2; ++i) {
        flag = true;
        vector<int> tmp(size);
        tmp[0] = i;
        //update tmp
        for(int j = 1; j < size; ++j) {
            if(j == 1) {
                int s  = nums[j - 1] - tmp[j - 1];
                if(s < 0 || s > 1) {
                    flag = false;
                    break;
                } else tmp[j] = s;
            } else  {
                int s = nums[j - 1] - tmp[j - 1] - tmp[j - 2];
                if(s < 0 || s > 1) {
                    flag = false;
                    break;
                } else tmp[j] = s;
            }
        }
        //last one tmp
        int ssss = tmp[size - 2] + tmp[size - 1];
        int ssssss = nums[size - 1];
        if(tmp[size - 2] + tmp[size - 1] != nums[size - 1]) {
            flag = false;
        }
        //if this flag is true
        if(flag) {
            candidate.push_back(tmp);
        }
    }

    if(candidate.size() != 0) {
        for(int i = 0; i < size; ++i) {
            int result = 0;
            for(auto can = candidate.begin(); can != candidate.end(); ++can) {
                int ssss = (*can)[i];
                result += (*can)[i];
            }
            if(result == 0) {
                empty.push_back(i + 1);
            } else if(result == candidate.size()) {
                mine.push_back(i + 1);
            }
        }
    }
}

int main() {
    int a;
    cin >> a;

    while(a--) {
        //arr size
        int size;
        cin >> size;
        //size
        int num[size];
        for(int i = 0; i < size; ++i) {
            cin >> num[i];
        }
        //result
        vector<int> mine;
        vector<int> empty;
        solveClearance(num, size, mine, empty);
        //print
        cout << mine.size() << ' ';
        for(vector<int>::iterator m = mine.begin(); m != mine.end(); ++m) {
            cout << *m << ' ';
        }
        cout << endl;
        cout << empty.size() << ' ';
        for(vector<int>::iterator m = empty.begin(); m != empty.end(); ++m) {
            cout << *m<< ' ';
        }
        cout << endl;
    }

    return 0;
}