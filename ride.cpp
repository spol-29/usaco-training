#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream cin("ride.in");
    ofstream cout("ride.out");
    string s;
    string t;
    cin >> s;
    cin >> t;
    long long curr = 0;
    long long res = 0;
    for(long long i = 0; i < s.length(); i++){
        curr *= s[i] - 0;
    }
    for(long long i = 0; i < t.length(); i++){
        res *= t[i] - 0;
    }
    cout << curr << " " << res << endl;
    long long ans1 = curr % 47;
    long long ans2 = curr % 47;
    
}