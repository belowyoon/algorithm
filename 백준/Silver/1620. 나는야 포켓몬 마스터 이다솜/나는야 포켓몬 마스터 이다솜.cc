#include <iostream>
#include <string>
#include <cctype> 
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int pokemonNum, testNum;
    cin >> pokemonNum >> testNum;
    unordered_map<string,int> pokemonName;
    string pokemon[100001];
    
    for (int i = 0; i < pokemonNum; i++){
        string temp;
        cin >> temp;
        pokemonName.insert(make_pair(temp,i+1));
        pokemon[i] = temp;
    }

    for (int i = 0; i < testNum; i++){
        string temp;
        cin >> temp;
        if (isdigit(temp[0]) == 1) {
            cout << pokemon[stoi(temp)-1] << '\n';
            
        } else {
            cout << pokemonName[temp] << '\n';
        }
    }
    return 0;
}