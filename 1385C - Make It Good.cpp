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
 
int length_of_prefix(vector<int>&a)
{
	if (a.size() <= 2) return 0;
 
	int i = a.size() - 1;
	while (i and a[i - 1] == a[i]) i--;
	while (i and a[i - 1] >= a[i]) i--;
	while (i and a[i - 1] <= a[i]) i--;
 
	return i;
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
		cout << length_of_prefix(a) << '\n';
	}
 
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	//cout << "\nTime elapsed: " << duration.count() << " microseconds.\n";
	return 0;
}
