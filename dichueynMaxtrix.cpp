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


int n , m; int a[100][100];
int res =0;


void Try(int i , int j){
    cout << i << " " << j << endl;
    if(i == n && j == m){
        res++;
        return ;
    }
    if (i + 1 <= n && a[i+1][j]){
        a[i+1][j] =0;
        Try(i + 1, j);
        a[i+1][j] =1;
    }
    if(j + 1 <= m && a[i][j+1]){
        a[i][j+1] =0;
        Try(i , j+1);
        a[i][j+1] =1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i =1;i <= n ; i++){
        for (int j =1 ;j <= m ;j++){
            cin >> a[i][j];
        }
    }
    res =0;
    Try(1 , 1);
    cout << res;
}
