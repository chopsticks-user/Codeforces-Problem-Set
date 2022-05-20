#include <iostream>
#include <chrono>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
 
using namespace std;
using namespace chrono;
 
typedef long long int ll;
 
ll count_same_differences(vector<int>&a)
{
	ll res = 0;
	map <int, ll> count, count1;
 
	for (int i = 0; i < a.size(); i++)
	{
		if (count[a[i] - i])  count[a[i] - i] += count1[a[i] - i];
		else count[a[i] - i]++;
		count1[a[i] - i]++;
	}
 
	for (const auto& p : count)
		res += p.second - 1;
	return res;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int t, n;
	vector<int>a;
	cin >> t;
 
	auto start = high_resolution_clock::now();
 
	while (t--)
	{
		cin >> n;
		a.resize(n, 0);
		for (int& i : a)
			cin >> i;
		cout << count_same_differences(a) << '\n';
	}
 
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	//cout << "\nTime elapsed: " << duration.count() << " microseconds.\n";
	return 0;
}
