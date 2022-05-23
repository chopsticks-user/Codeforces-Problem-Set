#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <chrono>
#include <ctime>
 
using namespace std;
using namespace chrono;
 
typedef unsigned us;
typedef double db;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<us> vus;
typedef vector<int> vi;
typedef vector<ull> vull;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef map<ull, ull> mull;
 
const db pi = acos(-1);
const db e = exp(1.0);
const ull pinf = ULLONG_MAX;
const ll ninf = LLONG_MIN;
vi memo;
 
#define pb push_back
#define pf push_front
#define rs resize
#define fi first
#define se second
#define si size()
#define be begin()
#define en end()
#define cstart auto start = high_resolution_clock::now();
#define cstop auto stop = high_resolution_clock::now(); cout << "\nTime elapsed: " << duration_cast<microseconds>(stop - start).count() << " micsec\n";
#define fast_input 
#define deb(x) cout << #x << " " << x << endl
#define fo(x, n) for (ull x = 0; x < n; x++)
#define fok(x, k, n) for (ull x = k; x < n; x++)
#define ifo(x, n) for (ull x = n; x > 0; x--)
#define ifok(x, k, n) for (ull x = n; x > k; x--)
#define foea(x, a) for (auto& x : a)
 
template<typename... T>
void in(T&... args)
{
	((cin >> args), ...);
}
 
template<typename... T>
void out(T... args)
{
	((cout << args << " "), ...);
}
 
ull random(ull min, ull max)
{
	srand(time(0));
	return rand() % max + min;
}
 
void dp()
{
 
}
 
//END OF PRE-SOLVING
 
void solve()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	us n;
	in(n);
	mull a;
	fo(i, n)
	{
		us x;
		in(x);
		a[x]+=x;
	}
	fok(i, 2, a.rbegin()->first + 1)
		a[i] = max(a[i - 1], a[i - 2] + a[i]);
	out(a.rbegin()->se);
}
 
int main()
{
	solve();
	return 0;
}
