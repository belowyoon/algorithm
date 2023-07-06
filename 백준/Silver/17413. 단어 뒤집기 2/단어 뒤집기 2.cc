#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    
    string c;
    string back = "";
    string front = "";
    bool flag = false;
    
    getline(cin, c);

    for (int i = 0; i < c.size(); i++){
        if (c[i] == '>') {
            front.push_back(c[i]);
            cout << front;
            front.clear();
            flag = false;
        } else if (c[i] == '<' || flag) {
            cout << back;
            back.clear();
            front.push_back(c[i]);
            flag = true;
        } else if (c[i] == ' ') {
            cout << back << " ";
            back.clear();
        }
        else {
            string temp;
            temp.push_back(c[i]);
            back.insert(0, temp);
        }
    }
    cout << back;
    return 0;
}