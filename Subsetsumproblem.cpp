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



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    ll a[n];
    ll sum = accumulate
    for (int i =1;i <= n ;i++){
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2 != 0){
        cout << "0";
    } else {
        sum /= 2;
        bool dp[sum +1];
        dp[0] =1;
        for (int i=1 ; i <= n ;i++){
            for (int j = sum ; j >= a[i] ; j--){
                if (dp[j-a[i]]){
                    dp[j] = true;
                }
            }
        }
        if(dp[sum]) cout << 1;
        else cout << 0;
    }
}
