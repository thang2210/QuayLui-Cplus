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

int n; int a[1000]; int res[1000];

vector<string> v;
void Try(int pos , int i){
    if(i >= 3){
        string tm = "";
        for (int j = 1; j < i ; j++){
            tm += to_string(res[j]) + " ";
        }
        v.push_back(tm);
    }
    for (int j = pos; j <= n ;j++){
        if (a[j] > res[i-1]){
            res[i] = a[j];
            Try(j + 1, i +1);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i=1;i <= n ;i++){
        cin >> a[i];
    }

    Try(1 , 1);
    sort(begin(v) , end(v));
    for (auto x : v){
        cout << x << endl;
    }
}
