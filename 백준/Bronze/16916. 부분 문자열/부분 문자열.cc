#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    
    string full, part;
    getline(cin, full);
    getline(cin, part);

    if (strstr((char*)full.c_str(),(char*)part.c_str()) != NULL)
        cout << 1;
    else
        cout << 0;

    return 0;
}
