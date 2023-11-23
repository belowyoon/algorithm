#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    unsigned long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < queue2.size(); i++)  {
        sum1 += queue1[i];
        sum2 += queue2[i];
        queue1.push_back(queue2[i]);
    }
    int s = 0, e = queue2.size() - 1, qsize = queue1.size(), res = -1;
    for (int i = 0; i < qsize * 2; i++) {
        if (sum1 == sum2){
            res = i;
            break;
        }
        if (sum1 < sum2) {
            e = (e + 1 + qsize) % qsize;
            sum1 += queue1[e];
            sum2 -= queue1[e];
        } else if (sum1 > sum2) {
            sum1 -= queue1[s];
            sum2 += queue1[s];
            s = (s + 1 + qsize) % qsize;
        }
    }   
    return res;
}