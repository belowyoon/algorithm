#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<char>> map;
int n;
string result[3];

void preorder(char node){
    if (node == '.')
        return;
    result[0] += node;
    preorder(map[node - 'A'][0]);
    preorder(map[node - 'A'][1]);
    return;
}

void inorder(char node){
    if (node == '.')
        return;
    inorder(map[node - 'A'][0]);
    result[1] += node;
    inorder(map[node - 'A'][1]);
    return;
}

void postorder(char node){
    if (node == '.')
        return;
    postorder(map[node - 'A'][0]);
    postorder(map[node - 'A'][1]);
    result[2] += node;
    return;
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n;
    map.assign(n, vector<char>(2, '.'));
    fill(result, result+3, "");

    char c1, c2, c3;
    for (int i = 0; i < n; i++) {
        cin >> c1 >> c2 >> c3;
        map[c1 - 'A'][0] = c2;
        map[c1 - 'A'][1] = c3;
    }
    preorder('A');
    inorder('A');
    postorder('A');
    for(int i = 0; i < 3; i++) {
        cout << result[i] << '\n';
    }
    return 0;
}