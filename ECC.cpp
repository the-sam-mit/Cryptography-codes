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

// y^2 = x^3 + ax + b mod P and 
// 4a^3 + 27b^2 != 0 mod P
// Primitive element = alpha(x_alpha, y_alpha)
// Secret key k in {2,3,4,... #E-1}
// beta = k*alpha = (x_beta, y_beta)
// K_pub = (E,beta,alpha,p)
// K_pr = (k)
// Message M = (x_M, y_M)

/*DIGITAL SIGN

m = {2, 3, ... #E-1}
gamma = m*alpha = (x_gamma, y_gamma)
r = x_gamma mod #E, if r = 0 mod #E, go to line 62
s = inverse_m * (x_M + k*r) mod #E, if s = 0 mod#E, go to line 62

Sig_K(M,k) = (r,s)

Verification
c = inverse_s mod #E
u1 = x_M*c mod #E
u2 = r*c mod #E
delta = u1*alpha + u2*beta = (x_gamma, y_gamma)
v = x_gamma mod #E
Succesful if v = r
*/

int lambda_(int x1, int a, int y1, int p){
    int num = 3*x1*x1 + a;
    int den = 2*y1;
    num = num%p;
    den = mminvprime(den, p);
    int ans = (num*den)%p;
    return ans;
}

int lambdaUnequal_(int x1, int y1, int x2, int y2, int p){
    int lm = (y2-y1+p+p)%p;
    if(x1==x2){
        cout<<"POINT of infinity\n";
        return -100;
    }
    lm = mod_div(lm, mod_sub(x2, x1, p), p);
    return lm;
}

pii addition(int x1, int y1, int x2, int y2, int a, int p){
    int lm = 0;
    if(x1==x2 && y1==y2)
        lm = lambda_(x1,a,y1,p);
    else
        lm = lambdaUnequal_(x1, y1, x2, y2, p);
    int x3 = lm*lm;
    x3 %= p;
    x3 = x3 - x2 + p + p;
    x3 %= p;
    x3 = x3 - x1 + p + p;
    x3 %= p;
    
    int y3 = lm*(x1-x3);
    y3 = y3 + p + p;
    y3 %= p;
    y3 = y3 - y1 + p + p;
    y3 %= p;
    
    if(lm!=-100) cout<<"addn = ("<<x3<<", "<<y3<<")\n";
    return mp(x3,y3);
}

void generation(int x1, int y1, int k, int p, int a){
    int x2 = x1, y2 = y1;
    rep(i,1,k-1){
        // cout<<x1<<" "<<y1<<"  "<<x2<<" "<<y2<<endl;
        pii tmp = addition(x1, y1, x2, y2, a, p);
        x1 = tmp.ff;
        y1 = tmp.ss;
        // cout<<tmp<<endl<<endl;
    }
    return;
}

void solve(){
    // int beta = k*alpha;
    int mod_E = 13;
    int x1 = 7, y1 = 9, x2 = 3, y2 = 6;
    int a = 1, p = 11, k = 13;
    
    pii beta = addition(x1,y1,x2,y2,a,p);    

    // generation(x1, y1, k, p, a);

    // MESSAGE gmma = m*alpha
    // int m = 2;
    // int x_M = 4, y_M = 4;
    // pii gamma = addition(x1,y1,x2,y2,a,p);    
    // int r = gamma.ff % mod_E;
    // int s = mminvprime(m, mod_E);
    // s = (s * (x_M + k*r))%mod_E;
    // cout<<"SIGN = (r, s) "<<r<<", "<<s<<endl;
}

 
signed main(){
    solve();
}

