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
const int SIZE = 200005;
const int INF = (int)1e18;

int mminvprime(int a, int b) {return powerMod(a, b - 2, b);}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;} 

/*
    Solve for X:
    X = 2(mod 3)
    X = 3(mod 5)
    X = 2(mod 7)
*/
int modInverse(int a, int m){
    int m0 = m;
    int y = 0, x = 1;
 
    if (m == 1)
        return 0;
 
    while (a > 1) {
        // q is quotient
        int q = a / m;
        int t = m;
 
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0)
        x += m0;
 
    return x;
}
 
// Cs = remainder in each case, Ns = mod values
void solve(){
    vector<int> Cs = {1, 2, 3};
    vector<int> Ns = {3, 4, 5};
    int N = 1;
    for(auto n:Ns){
        N = N*n;
    }
    int ans = 0;
    cout<<"N = "<<N<<endl;
    rep(i,0,sz(Cs)-1){
        int N_i = N/Ns[i];
        int d_i = modInverse(N_i, Ns[i]);
        cout<<"\nN_i = "<<N_i<<endl;
        cout<<"d_i(mod_inverse) = "<<d_i<<endl;
        ans += (Cs[i]*N_i*d_i);
    }
    cout<<"x = "<<(ans%N)<<endl;
}
 
signed main(){
    // reflex;
    // testcase(T){
        solve();
    // }
}
