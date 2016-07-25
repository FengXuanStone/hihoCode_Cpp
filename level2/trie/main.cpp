//
// Created by fengxuan on 2016/7/24.
//
#include <iostream>
#include <vector>

using namespace std;

struct node {
    char value;
    int num;
    vector<node *> subNode;
};

void insert(node *&root, string str) {
    node *sRoot = root;


    for(int i = 0; i < str.length(); i++) {
        node* tmp = new node;
        tmp->num = 1;
        tmp->value = str[i];

        if(sRoot->subNode.size() == 0) {
            sRoot->subNode.push_back(tmp);
            sRoot = tmp;
        } else {
            bool flag = true;

            for(int s = 0; s < sRoot->subNode.size(); ++s) {
                auto sss = sRoot->subNode[s];
                if(sss->value == str[i]) {
                    sss->num++;
                    flag = false;
                    sRoot = sss;
                    break;
                }
            }
            if(flag) {
                sRoot->subNode.push_back(tmp);
                sRoot = tmp;
            }
        }
    }
    return;
}

int search(node *&root, string str) {
    node *sRoot = root;

    for(int i = 0; i < str.length(); ++i) {
        if(i == str.length() - 1) {
            for(int s = 0; s <sRoot->subNode.size(); ++s) {
                auto sss = sRoot->subNode[s];
                if(sss->value == str[i])
                    return sss->num;
            }
            return 0;
        } else {
            bool flag = true;
            for(int s = 0; s <sRoot->subNode.size(); ++s) {
                auto sss = sRoot->subNode[s];
                if(sss->value == str[i]) {
                    sRoot = sss;
                    flag = false;
                    break;
                }
            }

            if(flag) return 0;
        }
    }

    return 0;
}


int main() {
    int a;
    cin >> a;
    //init
    node *root = new node;

    string str;
    while(a--) {
        cin >> str;
        insert(root, str);
    }

    cin >> a;
    while (a--) {
        cin >> str;
        int result = search(root, str);
        cout << result << endl;
    }

    return 0;
}