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

//function to check if a 2D array is similar to it's sorted version
bool check_grid(vector<vector<ul>>& a, vector<vector<ul>>& s_a, ul n, ul m)
{
	fo(i, n)
		fo(j, m)
			if (a[i][j] != s_a[i][j])
				return 0;
	return 1;
}

void solve()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	us t;
	in(t);
	while (t--)
	{
		us n, m;
		in(n, m);
		auto a = i2d<ul>(n, m);
    
    //sorted version of array a
		auto s_a = a;
		foea(i, s_a)
			sort(i.begin(), i.end());
    
		fo(i, n)
		{
      //check[j] = true means a[i][j] != s_a[i][j]
			map<ul, bool> check;
			fo(j, m)
				if (a[i][j] != s_a[i][j])
					check[j] = 1;
      
      //if check does not have any value, it means that the current row is similar to it's sorted version
      //since the current row is not the last row, we can skip to the next row
			if (!check.size() and i != n - 1)
				continue;
      
      //now, if check has exactly 2 values, it means there are 2 positions i and j where a[i] != s_a[i] and
      //a[j] != s_a[j] in the current row. Hence, we then swap the corresponding columns so that the current
      //row is non-decreasing
			if (check.size() == 2)
			{
        //swap the 2 columns
				foea(j, a)
					swap(j[check.begin()->first], j[check.rbegin()->first]);
        
        //check if the array's rows are all sorted
        //if yes, print the positions of the two columns
				if (check_grid(a, s_a, n, m))
				{
					out(check.begin()->first + 1, check.rbegin()->first + 1);
					break;
				}
        
        //if no, then there is nothing we can do
				out(-1);
				break;
			}
      
      //we are only allowed to execute one swap, so if there are more than 2 columns need to be swapped,
      //the task is impossible
			if (check.size() > 2)
			{
				out(-1);
				break;
			}
      
      //since all the conditions above have either "break" or "continue" at the end of them, only an array which needs
      //no swapping is able to get here. So print the default return
			out(1, 1);
		}
	}
}

int main()
{
	solve();
	return 0;
}
