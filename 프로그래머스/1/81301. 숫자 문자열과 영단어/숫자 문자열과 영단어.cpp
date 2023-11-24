#include <string>
#include <unordered_map> 
#include <vector>

using namespace std;

int solution(string s) {
    string num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    unordered_map<string, int> map;
    for (int i = 0; i < 10; i++) {
        map.insert({num[i], i});
    }
    int answer = 0, index = 0;
    string tmp;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9'){
            answer = (answer * 10) + s[i] - '0';
            index++;
        } else {
            tmp.push_back(s[i]);
            if (map.find(tmp) != map.end()) {
                answer = (answer * 10) + map[tmp];
                index++;
                tmp = "";
            }
        }
    }
    return answer;
}