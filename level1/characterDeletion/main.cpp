#include <iostream>
//
// Created by fengxuan on 2016/7/22.
//

using namespace std;

string::size_type del(string s) {
    if(s.length() == 0) return 0;

    bool flag = false;
    string::size_type count = 0;

    for(string::size_type i = 0; i < s.length(); ++i) {
        auto j = i + 1;
        while (j < s.length() && s[i] == s[j]) {
            ++j;
        }

        if(i != j - 1) {
            count = count + j - i;
            flag = true;
            if(i == 0) {
                s = s.substr(j, s.length());
                i--;
            } else {
                string s1 = s.substr(0, i);
                s1 += s.substr(j, s.length());
                s = s1;
                i--;
            }
        }
    }

    if(flag) {
        return count + del(s);
    } else {
        return 0;
    }
}

int main() {
    int a;
    cin >> a;

    while (a--) {
        string str;
        cin >> str;
        string::size_type  size = str.length();
        string::size_type max = 0;

        for(decltype(size) i = 0; i < size; ++i) {
            string news1 = str.substr(0, i);
            news1 += "A";
            news1 += str.substr(i, str.length());
            auto tmp1 = del(news1);
            max = max > tmp1 ? max : tmp1;
            string news2 = str.substr(0, i);
            news2 += "B";
            news2 += str.substr(i, str.length());
            auto tmp2 = del(news2);
            max = max > tmp2 ? max : tmp2;
            string news3 = str.substr(0, i);
            news3 += "C";
            news3 += str.substr(i, str.length());
            auto tmp3 = del(news3);
            max = max > tmp3 ? max : tmp3;
        }

        cout << max << endl;
    }
    return 0;
}


