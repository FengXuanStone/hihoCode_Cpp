#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool IsPopOrder(vector<int> pushV,vector<int> popV) {

}

bool isShortter(const string s1, const string s2) {
    return s1.size() < s2.size();
}

string::size_type find_char(const string &s, char c, string::size_type &occurs) {
    auto ret = s.size();
    occurs = 0;
    for(decltype(ret) i = 0; i != s.size(); ++i) {
        if(s[i] == c) {
            if(ret == s.size()) {
                ret = i;
            }
            ++occurs;
        }
    }
    return ret;
}

int main() {
    vector<int> s1 = {1,2,3,4,5};
    vector<int> s2 = {4,5,3,2,1};

    cout << IsPopOrder(s1,s2) << endl;

    cout << "Hello, World!" << endl;

    string::size_type ctr = 0;
    auto index = find_char("abcdoosssy", 'o', ctr);

    cout << index << ' ' <<  ctr << endl;

    cin.setstate(cin.rdstate() & ~cin.failbit & ~cin.badbit);
    return 0;
}