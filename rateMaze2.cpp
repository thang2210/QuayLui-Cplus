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

/*string s = "DLRU";

int dx[4] = {-1 , 0 , 0 ,1};
int dy[4] = {0 , -1 , 1 , 0};
int a[100][100];
int n;
string res = "";
int ok =1;
void Try(int i , int j){
    a[i][j] =0;
    if(i == n && j == n){
        cout << res << endl;
        ok = 1;
    }
    //a[i][j] =0;
    for (int k = 0 ;k < 4; k++){
        int imoi = i + dx[k];
        int jmoi = j + dy[k];
        if (imoi >= 1 && imoi <= n && jmoi >= 1 && jmoi <= n && a[imoi][jmoi]){
            res += s[k];
            Try(imoi , jmoi);
            res.pop_back();
            a[imoi][jmoi] =1;
        }
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
    ok = 0;
    if (a[n][n] != 1){
        cout << -1;

    } else {
        Try(1 , 1);
        if (!ok) cout << -1;
    }
}
*/


int n; int a[1000][1000];
bool ok;
string res = "";
void Try(int i , int j){
    if (i == n && j == n){
        cout << res << endl;
        ok =1;
    }
    if(i + 1 <= n && a[i+1][j]){
        a[i][j] =0;
        res += "D";
        Try(i + 1, j);
        res.pop_back();
        a[i+1][j] =1;
    }
    if (j + 1 <= n && a[i][j+1]){
        a[i][j] =0;
        res += "R";
        Try(i , j+1);
        res.pop_back();
        a[i][j+1] =1;
    }
    if(j - 1 >= 1 && a[i][j-1]){
        a[i][j] =0;
        res += "L";
        Try(i , j-1);
        res.pop_back();
        a[i][j-1] =1;
    }
    if (i - 1 >= 1 && a[i-1][j]){
        a[i][j] =0;
        res += "U";
        Try(i -1 , j);
        res.pop_back();
        a[i-1][j] =1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i =1;i <= n ;i++){
        for(int j =1; j <=n ;j++){
            cin >> a[i][j];
        }
    }
    if (a[n][n] != 1) cout << -1;
    else Try(1 , 1);
}
