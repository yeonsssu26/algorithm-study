#include <iostream>
using namespace std;
int main() {
	int fixedCost, variableCost, sellingCost;
	cin >> fixedCost >> variableCost >> sellingCost;

	int productionCost, earnings;

	if (sellingCost - variableCost == 0)
		cout << -1;
	else {
		if (fixedCost / (sellingCost - variableCost) < 0)
			cout << -1;
		else {
			int breakEvenPoint = fixedCost / (sellingCost - variableCost) + 1;
			cout << breakEvenPoint;
		}
	}
	return 0;
}