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
const ul pinf = ULLONG_MAX;
const ll ninf = LLONG_MIN;
vi memo;
 
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
 
vector<string> setup()
{
	vector<string> data(125);
	data[0] = "000";
	for (us i = 1; i * 8 < 1000; i++)
	{
		data[i] = to_string(i * 8);
	}
	return data;
}
 
void solve()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<string> first_125 = setup();
	string n;
	cin >> n;
	if (n.find("0") != string::npos)
	{
		cout << "YES\n0";
		return;
	}
	if (n.find("8") != string::npos)
	{
		cout << "YES\n8";
		return;
	}
	for (auto i : first_125)
	{
		string temp = n;
		bool found = 0;
		for (us j = 0; j < i.size(); j++)
		{
			int p = temp.find(i[j]);
			if (p < 0)
			{
				found = 0;
				break;
			}
			temp.erase(temp.begin(), temp.begin() + p + 1);
			found = 1;
		}
		if (found)
		{
			cout << "YES\n" << i;
			return;
		}
	}
	cout << "NO";
}
 
int main()
{
	solve();
	return 0;
}
