#include<bits/stdc++.h>


using namespace std;
using ll = long long;
using db = double;
#define MAX_SIZE 1e7
#define MIN_SIZE -1e7

const int MOD = (int) 1e9+7;
const int INF = (int) 1e9+1;
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}


bool check(char a , char b){
    return abs((a - '0') - (b -'0')) == 1;
}

bool res(string s){
    string res = "";
    for (int i = 1;i <  s.size() -1 ; i++){
        if(check(s[i] , s[i-1])|| check(s[i] , s[i+1])){
            return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    string s ="";
    for (int i = 1; i <= n ;i++){
        s += to_string(i);
    }
    vector<string> v;
    do{
        if (res(s)) v.push_back(s);
    } while(next_permutation(s.begin() , s.end()));
    for (auto x : v){
        cout << x << endl;
    }
}
