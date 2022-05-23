#include <iostream>
#include <algorithm>
#include <cmath>
#include <random>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <chrono>
 
using namespace std;
using namespace chrono;
 
typedef unsigned us;
typedef double db;
typedef unsigned long long ul;
typedef long long ll;
typedef long double ld;
typedef vector<us> vus;
typedef vector<int> vi;
typedef vector<ul> vul;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef map<ul, ul> mul;
 
const db pi = acos(-1);
const db e = exp(1.0);
const ul pinf = ULLONG_MAX;
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
#define deb(x) cout << #x << " " << x << endl
#define fo(x, n) for (ul x = 0; x < n; x++)
#define fok(x, k, n) for (ul x = k; x < n; x++)
#define ifo(x, n) for (ul x = n; x > 0; x--)
#define ifok(x, k, n) for (ul x = n; x > k; x--)
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
 
ul rand(ul min, ul max)
{
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<ul> dist(min, max);
	return dist(rng);
}
 
void dp()
{
 
}
 
//END OF PRE-SOLVING
 
bool r_find_substr(string s)
{
	if (s.size() < 4) return 0;
	int r_count = s.find("BA");
	if (r_count < 0) return 0;
	s.replace(s.begin() + r_count, s.begin() + r_count + 2, " ");
	if (s.find("AB") == string::npos) return 0;
	return 1;
}
 
bool find_substr(string s)
{
	string s1 = s;
	if (s.size() < 4) return 0;
	int count = s.find("AB");
	if (count < 0) return r_find_substr(s1);
	s.replace(s.begin() + count, s.begin() + count + 2, " ");
	if (s.find("BA") == string::npos) return r_find_substr(s1);
	return 1;
}
 
void solve()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	cout << (find_substr(s) ? "YES" : "NO");
}
 
int main()
{
	solve();
	return 0;
}
