#include <iostream>
#include <algorithm>
#include <cmath>
#include <random>
#include <map>
#include <utility>
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
 
void solve()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	us n, count = 1;
	cin >> n;
	vector<ll> x(n), h(n);
	for (us i = 0; i < n; i++)
		cin >> x[i] >> h[i];
	if (n < 3)
	{
		cout << n;
		return;
	}
	for (us i = 1; i < n - 1; i++)
	{
		if (x[i] - h[i] > x[i - 1])
		{
			count++;
			continue;
		}
		if (x[i] + h[i] < x[i + 1])
		{
			x[i] += h[i];
			count++;
			continue;
		}
	}
	if (x[n - 2] < x[n - 1])
		count++;
	cout << count;
}
 
int main()
{
	solve();
	return 0;
}
