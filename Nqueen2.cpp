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

int n; int cot[100] , xuoi[100] , nguoc[100] , res[100];
int ans =0; int a[100][100];
void Try(int i){
    for (int j =1;j <= n ;j++){
        if (cot[j] == 0 && xuoi[n - j + i] == 0 && nguoc[i + j -1] == 0){
            res[i] = j;
            cot[j] = xuoi[n-j +i] = nguoc[i + j -1] = 1;
            if (i == n){
                int sum =0;
                for (int i =1; i <= n ; i++){
                    sum += a[i][res[i]];
                }
                ans = max(ans , sum);
            }  else {
                Try(i+1);
            }
            cot[j] = xuoi[n- j +i] = nguoc[i + j -1] = 0;
        }
    }
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    n = 8;
    for (int i =1; i <= 8 ; i++){
        for (int j = 1; j <= 8 ; j++){
            cin >> a[i][j];
        }
    }
    Try(1);
    cout << ans;
}
