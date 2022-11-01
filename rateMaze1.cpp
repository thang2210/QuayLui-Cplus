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


int n; int a[1000][1000];

void Try(int i , int j , string s){
    cout << i << " " << j << endl;
    if (i == n && j == n){
        cout << s << endl;
    }
    if (i + 1 <= n && a[i+1][j]){
        Try(i+ 1, j , s + "D");
    }
    if (j + 1 <= n && a[i][j+1]){
        Try(i , j + 1, s + "R");
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i =1;i <= n ;i++){
        for (int j = 1; j <= n ;j++){
            cin >> a[i][j];
        }
    }
    string tm = "";
    Try(1 , 1 , tm);
    cout << tm << endl;
}
