#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<int> split(string input, char delim)
{
	vector<int> result;

	stringstream ss;		
	string temp;	
	ss.str(input);			
	
	while (getline(ss, temp, delim)){
        int t = stoi(temp);
        result.push_back(t);
    }

	return result;
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    
    string now;
    string throwTime;
    string result[3];

    getline(cin, now);
    getline(cin, throwTime);

    vector<int> splitNow = split(now, ':');
    vector<int> splitThrow = split(throwTime, ':');
    int flag = 0;

    for(int i = splitNow.size() - 1; i >= 0; i--) {
        if (splitNow[i] > splitThrow[i]) {
            if (i == 0) {
                splitThrow[0] += 24;
            } else {
                splitThrow[i] += 60;
                splitThrow[i-1]--; 
            }
        }
        int temp = splitThrow[i] - splitNow[i];
        if (temp == 0) flag++;
        if (temp < 10)
            result[i] = "0" + to_string(temp);
        else
            result[i] = to_string(temp);
    }
    if(flag == 3)
        result[0] = "24";

    cout << result[0] << ':' << result[1] << ':' << result[2];

    return 0;
}
