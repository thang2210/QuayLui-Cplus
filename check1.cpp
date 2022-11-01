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



int n , k;
int a[1000]; int res[1000];


vector<string> ans;
void Try(int sum , int pos , int i){
    if (sum == k){
        string tm = "";
        tm += "[";
        for (int j = 0; j < i ; j++){
            tm += to_string(res[j]);
            if (j != i -1) tm += " ";
            else tm += "]";
        }
        ans.push_back(tm);
    }
    for (int j = pos ; j <= n ;j++){
        if (sum + a[j] <= k){
            res[i] = a[j];
            Try(sum + a[j] , j , i +1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i =1;i <= n ; i++){
        cin >> a[i];
    }
    sort( a  +1 , a + n +1);
    Try(0 , 1 , 0);
    if (ans.size() == 0) cout << -1;
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x << endl;
    }
}
