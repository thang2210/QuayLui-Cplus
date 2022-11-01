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

// sinh to hop:
/*int n; int a[1000];

void Try(int i){
    for (int j = 0 ;j <= 1 ; j++){
        a[i] = j;
        if (i == n){
            for (int i =1;i <= n ; i++) cout << a[i];
                cout << endl;
        } else {
            Try(i+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    Try(1);
}*/


// sinh to hop chap k :


// int n , k;
// int a[1000];

// void Try(int i){
//     for (int j = a[i-1] + 1 ; j <= n - k +i ;j++){
//         a[i] = j;
//         if (i ==k ){
//             for (int i =1; i <= k ; i++) cout << a[i];
//             cout << endl;
//         } else Try(i+1);
//     }


// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cin >> n >> k;
//     Try(1);
// }



// quay lui hoan  vi :

/*int n; int a[1000];
bool res[100];

void Try(int i){
    for (int j = 1;j <= n ;j++){
        if (res[j] == 0){
            a[i] = j;
            res[j] = 1;
            if (i == n){
                for (int i =1;i <= n;i++) cout << a[i];
                cout << endl;
            } else {
                Try(i+1);
            }
            res[j] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    Try(1);
}
*/


int n , k; int a[1000];
int res[1000];


void Try(int sum , int pos , int cnt){
    if (sum == k){
        cout << "[";
        for(int i = 1; i < cnt ;i++){
            cout << res[i];
            if (i != cnt -1) cout << " ";
            else cout << "]";
        }
        cout << endl;
    }
    for (int i = pos ; i <= n ;i++){
        res[cnt] = a[i];
        if (sum + a[i] <= k){
            Try(sum + a[i] , i + 1, cnt +1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i =1 ;i <= n ; i++){
        cin >> a[i];
    }
    sort( a+ 1,a + n+1);
    Try(0 , 1 , 1);

}
