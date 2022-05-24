#include <iostream>
#include <algorithm>
#include <cmath>
#include <random>
#include <map>
#include <utility>
#include <list>
#include <queue>
#include <stack>
#include <array>
#include <vector>
#include <string>
#include <chrono>
#include <memory>
#include <tuple>

namespace ulti
{
	typedef unsigned us;
	typedef double db;
	typedef unsigned long long ul;
	typedef long long ll;
	typedef long double ld;
	typedef std::vector<us> vus;
	typedef std::vector<int> vi;
	typedef std::vector<ul> vul;
	typedef std::vector<ll> vll;
	typedef std::vector<db> vd;
	typedef std::vector<ld> vld;

	#define cstart auto start = high_resolution_clock::now();
	#define cstop auto stop = high_resolution_clock::now(); cout << "\nTime elapsed: " << duration_cast<microseconds>(stop - start).count() << " micsec\n";
	#define deb(x) cout << #x << " " << x << "\n"
	#define fo(x, n) for (int x = 0; x < n; x++)
	#define fok(x, k, n) for (int x = k; x < n; x++)
	#define ifo(x, n) for (int x = n; x > 0; x--)
	#define ifok(x, k, n) for (int x = n; x > k; x--)
	#define foea(x, a) for (auto& x : a)

	const db pi = acos(-1);
	const db eu = exp(1.0);

	template<typename... T>
	void in(T&... args)
	{
		((std::cin >> args), ...);
	}

	template<typename... T>
	void out(T... args)
	{
		((std::cout << args << " "), ...);
	}

	ul rand(ul min, ul max)
	{
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<ul> dist(min, max);
		return dist(rng);
	}

	template<typename T>
	std::vector<T> i1d(const us& n)
	{
		std::vector<T> a(n);
		foea(i, a)
			in(i);
		return a;
	}

	template<typename T>
	void o1d(const std::vector<T>& a)
	{
		foea(i, a)
			out(i);
	}

	template<typename T>
	std::vector<std::vector<T>> i2d(const us& n, const us& m)
	{
		std::vector<std::vector<T>> a(n, std::vector<T>(m));
		foea(i, a)
			foea(j, i)
				in(j);
		return a;
	}

	template<typename T>
	std::vector<std::vector<T>> i2d(const us& n, const us& m, const T& x)
	{
		std::vector<std::vector<T>> a(n, std::vector<T>(m, x));
		return a;
	}

	template<typename T>
	void o2d(const std::vector<std::vector<T>>& a)
	{
		foea(i, a)
			foea(j, i)
				out(j);
	}
}

using namespace std;
using namespace chrono;
using namespace ulti;

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
		ll n, k;
		ll dmg = 0;
		in(n, k);
		vll a(n), b(n);
		fo(i, n)
		{
			in(a[i]);
			dmg += a[i];
			a[i] -= n - i - 1;

		}
		sort(a.rbegin(), a.rend());
		fo(i, k)
		{
			dmg -= a[i];
		}
		out(dmg - k * (k - 1) / 2);
	}
}

int main()
{
	solve();
	return 0;
}
