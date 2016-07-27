//
// Created by fengxuan on 2016/7/26.
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int maxValue = 0;
//
//struct snack {
//    double price;
//    int expect;
//
//    snack(double p, int e) {
//        price = p;
//        expect = e;
//    }
//};
//
//void maxExcept(vector<snack* > snack1, vector<snack* > snack2) {
//    maxValue = 0;
//    //snack1
//    //one
//    for(int i = 0; i < snack1.size(); ++i) {
//        snack* s1 = snack1[i];
//        //one
//        if((int)s1->price % 5 == 0 && s1->expect > maxValue) maxValue = s1->expect;
//    }
//
//    for(int j = 0; j < snack2.size(); ++j) {
//        for(int k = j; k < snack2.size(); ++k) {
//            snack* s2 = snack2[j];
//            snack* s3 = snack2[k];
//            int e = s2->expect + s3->expect;
//            if((int)(s2->price + s3->price) % 5 == 0 && e > maxValue) maxValue = e;
//        }
//    }
//
//    for(int i = 0; i < snack1.size(); ++i) {
//        for(int j = 0; j < snack2.size(); ++j) {
//            for(int k = j; k < snack2.size(); ++k) {
//                //
//                auto s1 = snack1[i], s2 = snack2[j], s3 = snack2[k];
//                int e = s1->expect + s2->expect + s3->expect;
//                //
//                if((int)(s1->price + s2->price + s3->price) % 5 == 0 && e > maxValue) maxValue = e;
//            }
//        }
//    }
//}
//
//int main() {
//    int a;
//    cin >> a;
//
//    while (a--) {
//        int num;
//        cin >> num;
//
//        vector<snack* > snack1;
//        vector<snack* > snack2;
//
//        while (num--) {
//            double p; int e;
//            cin >> p >> e;
//            snack* ss = new snack(p, e);
//            if((int)(p * 2) % 2 == 0) snack1.push_back(ss);
//            else snack2.push_back(ss);
//        }
//
//        maxExcept(snack1, snack2);
//
//        cout << maxValue << endl;
//    }
//
//    return 0;
//}
