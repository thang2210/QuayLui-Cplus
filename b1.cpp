//Tập hợp có tổng bằng S
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



int n , k , s;
int res;


void Try(int sum , int pos , int i){
    if(sum ==s && i == k){
        res++;
        return ;
    }
    for (int j = pos ; j <= n ; j++){
        if(sum + j <= s){
            Try(sum + j , j + 1, i +1);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> s;
    res =0;
    Try(0 , 1 , 0);
    cout << res;
}
