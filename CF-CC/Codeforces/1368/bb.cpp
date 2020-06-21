#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    char c[] = {'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's'};
    string str = "";
    for(int i = 0;i < 10;i+=1) {
        for(int j=0; j<10000;j+=1){
            str +=c[i];
        }
    }
    cout << str << endl;
    return 0;
}