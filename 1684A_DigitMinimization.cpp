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
#include <memory>

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

void solve()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	us t;
	in(t);
	while (t--)
	{
		string n;
		map<char, us> cnt;
		in(n);
		if (n.size() == 2)
		{
			out(n[1]);
			continue;
		}
		for (auto& i : n)
			cnt[i]++;
		out(cnt.begin()->first);
	}
}

int main()
{
	solve();
	return 0;
}
