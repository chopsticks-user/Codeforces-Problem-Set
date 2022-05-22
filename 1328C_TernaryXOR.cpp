#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <map>
 
using namespace std;
using namespace chrono;
 
typedef long long int ll;
 
class temary
{
public:
	string first;
	string second;
	temary(int n)
	{
		first.resize(n, '0');
		second.resize(n, '0');
	}
};
 
temary find_numbers(int n, const string& x)
{
	temary r(n);
	r.first[0] = '1';
	r.second[0] = '1';
	bool max_chosen = false;
 
	for (int i = 1; i < n; i++)
	{
		if (x[i] == '0')
		{
			r.first[i] = '0';
			r.second[i] = '0';
		}
		if (x[i] == '1')
		{
			if (max_chosen) { r.first[i] = '0'; r.second[i] = '1'; }
			else { r.first[i] = '1'; r.second[i] = '0'; max_chosen = true; }
		}
		if (x[i] == '2')
		{
			if (max_chosen) { r.first[i] = '0'; r.second[i] = '2'; }
			else { r.first[i] = '1'; r.second[i] = '1'; }
		}
	}
 
	return r;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int t, n;
	string x;
	cin >> t;
 
	auto start = high_resolution_clock::now();
 
	while (t--)
	{
		cin >> n >> x;
		temary temp(n);
		temp = find_numbers(n, x);
		cout << temp.first << '\n' << temp.second << '\n';
	}
 
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	//cout << "\nTime elapsed: " << duration.count() << " microseconds.\n";
	return 0;
}
