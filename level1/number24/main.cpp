#include <iostream>
#include <algorithm>
//
// Created by fengxuan on 2016/7/22.
//

using namespace std;

double result(const double a,const double b,const int c) {
    double result = 0.0;
    switch (c) {
        case 0: result = a + b;
            break;
        case 1: result = a - b;
            break;
        case 2: result = a * b;
            break;
        case 3: if(b) result = a / b;
            break;
        case 4: result = b - a;
            break;
        case 5: if(a) result = b / a;
            break;
    }
    return  result;
}

bool isNumber(const double num[], int i, int j, int k) {
    if(result(result(result(num[0],num[1],i),num[2],j),num[3],k)==24)return true;
    if(result(result(num[0],num[1],i), result(num[2],num[3],k),j) == 24)return true;
    return false;
}

bool solve(const double num[]) {
    for(int i=0; i<6; i++)
        for(int j=0; j<6; j++)
            for(int k=0; k<6; k++)
                if(isNumber(num, i, j, k))
                    return true;
    return false;
}



int main() {
    int a;
    cin >> a;

    while (a--) {
        double num[4];
        bool flag = false;

        for(int i = 0; i < 4; ++i) {
            cin >> num[i];
        }
        sort(num,num+4);
        do
        {
            flag = solve(num);
            if(flag) break;
        }
        while(next_permutation(num,num+4));

        if(flag) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
