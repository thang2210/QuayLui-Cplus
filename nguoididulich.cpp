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

int n; int res[100];
bool used[100];
int a[100][100];

int ans =INT_MAX; int sum = 0;

void Try(int i){
    for (int j =2; j <= n ;j++){
        if (used[j] == 0){

            res[i] = j;
            used[j] =1;
            sum += a[res[i-1]][res[i]];
            if(i == n){
                ans = min(ans , sum + a[res[i]][1]);
            } else {
                Try(i +1);
            }
            used[j] =0;
            sum -= a[res[i-1]][res[i]];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i =1;i <= n ;i++){
        for (int j =1;j <= n ;j++){
            cin >> a[i][j];
        }
    }
    res[1] =1;
    Try(2);
    cout << ans;
}
