#include <iostream>
#include <string>

using namespace std;

string solve(int n){
    string s="";
    while(n>0){
        if(n%2==1)
            s="4"+s;
        else
            s="7"+s;
        n=(n-1)/2;
    }
    return s;
}

int main() {
    #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
     #endif
    int k;
    cin >> k;
    string result = solve(k);
    cout << result << endl;
    return 0;
}