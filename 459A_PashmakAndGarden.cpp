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
 
bool other_trees_exist(int& x1, int& y1, int& x2, int& y2)
{
	if (abs(x1 - x2) == abs(y1 - y2))
	{
		if (x1 != x2) { swap(y1, y2); return true; }
		else return false;
	}
 
	if (x1 == x2)
	{
		x1 += y1 - y2;
		x2 += y1 - y2;
		return true;
	}
 
	if (y1 == y2)
	{
		y1 += x1 - x2;
		y2 += x1 - x2;
		return true;
	}
 
	return false;
}
 
void find_other_trees(int& x1, int& y1, int& x2, int& y2)
{
	if (other_trees_exist(x1, y1, x2, y2))
		cout << x1 << " " << y1 << " " << x2 << " " << y2;
	else
		cout << -1;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
 
	auto start = high_resolution_clock::now();
 
	find_other_trees(x1, y1, x2, y2);
 
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	//cout << "\nTime elapsed: " << duration.count() << " microseconds.\n";
	return 0;
}
