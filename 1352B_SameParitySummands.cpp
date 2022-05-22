#include <iostream>
#include <chrono>
#include <vector>
#include <map>
 
using namespace std;
using namespace chrono;
 
typedef long long int ll;
 
void print_sum(int k, int q, int r)
{
	cout << "YES\n" << q + r << " ";
	while (--k)
		cout << q << " ";
	return;
}
 
void odd_sum(int n, int k)
{
	if (k & 1)
	{
		int q = n / k;
		int r = n % k;
		if (!(q & 1)) { q--; r += k; }
		if (!(r & 1)) { print_sum(k, q, r); return; }
		
	}
	cout << "NO";
}
 
void even_sum(int n, int k)
{
	int q = n / k;
	int r = n % k;
 
	if (k & 1) 
	{
		if (q == 1) { cout << "NO"; return; }
		if (q & 1) { q--; r += k; }
		if (r & 1) { cout << "NO"; return; }
	}
	print_sum(k, q, r);
	return;
}
 
void find_parity_sum(int n, int k)
{
	if (n < k) { cout << "NO"; return; }
	if (n & 1) return odd_sum(n, k);
	return even_sum(n, k);
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int t, n, k;
	cin >> t;
 
	auto start = high_resolution_clock::now();
 
	while (t--)
	{
		cin >> n >> k;
		find_parity_sum(n, k);
		cout << '\n';
	}
 
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	//cout << "\nTime elapsed: " << duration.count() << " microseconds.\n";
	return 0;
}
