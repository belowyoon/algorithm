#include <iostream>
#include <algorithm>

int type[26] = {0};

using namespace std;
char check(char a, char b) {
    char res;
    cout << type[a - 'A'] << type[b - 'A'] << '\n';
    if (type[a - 'A'] > type[b - 'A']) {
        res = a;
    } else if (type[a - 'A'] < type[b - 'A']) {
        res = b;
    } else {
        res = a - 'A' < b - 'A'? a : b;
    }
    return res;
}

string solution(vector<string> survey, vector<int> choices) {
    char a, b;
    for (int i = 0; i < survey.size(); i++){
        a = survey[i][0];
        b = survey[i][1];
        switch(choices[i]){
            case 1 : type[a - 'A'] += 3; break;
            case 2 : type[a - 'A'] += 2; break;
            case 3 : type[a - 'A'] += 1; break;
            case 5 : type[b - 'A'] += 1; break;
            case 6 : type[b - 'A'] += 2; break;
            case 7 : type[b - 'A'] += 3; break;
        }
    }
    string answer = "";
    answer.push_back(check('R', 'T'));
    answer.push_back(check('C', 'F'));
    answer.push_back(check('J', 'M'));
    answer.push_back(check('A', 'N'));
    return answer;
}