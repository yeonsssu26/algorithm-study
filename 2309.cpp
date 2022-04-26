#include <iostream>
#include <algorithm>	// next_permutation
#include <numeric>		// accumulate
using namespace std;
int arr[9];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 9; i++) cin >> arr[i];
	sort(arr, arr + 9);

	do {
		int sum = accumulate(arr, arr + 7, 0);
		if (sum == 100) break;
		
	} while (next_permutation(arr,arr+9));

	for (int i = 0; i < 7; i++) cout << arr[i] << "\n";
	return 0;
}