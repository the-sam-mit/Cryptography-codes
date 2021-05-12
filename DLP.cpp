#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define int long long int
// #define ull unsigned long long
#define ff first 
#define ss second
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define testcase(t) int t;cin>>t;while(t--)
#define mp(x,y) make_pair(x,y)
#define in(x) insert(x)
#define rep(i,a,b)  for (__typeof((b)) i=(a);i<=(b);i++)
#define nrep(i,a,b)  for (__typeof((b)) i=(b);i>=(a);i--)
#define PI 1.0*acos(-1.0)
#define SP(x) setprecision(x)
#define reflex ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M  1000000007 
#define sz(a) (int)a.size()
#define endl "\n"
#define all(v) v.begin(), v.end()
#define mem(arr,val) memset(arr,val,sizeof(arr)) //For "0" and "-1"                  
#define inp0(a,n) rep(i,0,n-1) cin>>a[i];
#define inp1(a,n) rep(i,1,n) cin>>a[i]; 
typedef pair<int,int> pii;
// typedef tree< int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int gcd(int a, int b, int& x, int& y){if(b == 0){x = 1;y = 0;return a;}int x1, y1;int d = gcd(b, a % b, x1, y1);x = y1;y = x1 - y1 * (a / b);return d;}
int powerM(int a,int b){if(b==0) return 1LL;  if(b==1) return a%M; int x=powerM(a,b/2)%M; if(b&1){return ((((a%M)*(x%M))%M)*(x%M))%M;}return ((x%M)*(x%M))%M;}
int power(int a,int b){if(b==0) return 1;  if(b==1) return a; int x=power(a,b/2); if(b&1){return ((((a)*(x)))*(x));}return ((x)*(x));}
int powerMod(int a,int b, int mod){if(b==0) return 1LL;  if(b==1) return a%mod; int x=powerMod(a,b/2,mod)%mod; if(b&1){return ((((a%mod)*(x%mod))%mod)*(x%mod))%mod;}return ((x%mod)*(x%mod))%mod;}
 
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.first << "," << P.second << ")";}
template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";}
template<class K, class X> ostream &operator<<(ostream& os, map<K,X> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";}
template<class T> ostream &operator<<(ostream& os, set<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";}
const int SIZE = 100005;
const int INF = (int)1e18;
 
int mminvprime(int a, int b) {return powerMod(a, b - 2, b);}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;} 

int addition(int beta, int alpha, int p){
    int ans = mod_mul(beta, mminvprime(alpha, p), p);
    return ans;
}

int multiplication(int beta, int alpha, int p){
    int i=0;
    while(i<=1000){
        int cc = powerMod(alpha, i, p);
        if(cc==beta) return i;
        i++;
    }
}

pii ElGamal_encryption(int x, int p, int alpha, int a, int k){
    int beta = powerMod(alpha, a, p);
    pii Y;
    Y.ff = powerMod(alpha, k, p);
    Y.ss =  powerMod(beta, k, p);
    Y.ss =  mod_mul(Y.ss, x, p);
    return Y;
}

int ElGamal_decryption(int y1, int y2, int p, int alpha){
    int x = powerMod(y1, alpha, p);
    x = mminvprime(x, p);
    x = mod_mul(x, y2, p);
    return x;
}

void solve(){
    cout<<"addition = "<<addition(16, 3, 17)<<endl; //to find B = iA
    cout<<"multiplication = "<<multiplication(41, 5, 47)<<endl; // to find B = A^i
    // cout<<powerMod(5, 15, 47)<<endl;
    
    int p = 31, a = 4;

    int x = 3, k = 6, alpha = 17;
    cout<<"ElGamal_encryption()= "<<ElGamal_encryption(x, p, alpha, a, k)<<endl;

    int y1 = 8, y2 = 12;
    cout<<"ElGamal_decryption()= "<<ElGamal_decryption(y1, y2, p, a)<<endl;
}

 
signed main(){
    solve();
}

