#include <iostream>
using namespace std;
int a[100];

int binSearch(const int *Array, int start, int end, int key) {
	int left, right;
	int mid;
	left = start;
	right = end;
	while (left <= right) {
		mid = (left + right) / 2;
		if (key < Array[mid]) {
			right = mid - 1;
		} else if (key > Array[mid]) {
			left = mid + 1;
		} else
			return mid;
	}
	return -1;
}
int main() {
	int k;
	for (int i = 0; i < 100; i++) {
		a[i] = i;
	}
	while (cin >> k) {
		cout << binSearch(a, 0, 98, k);
	}
	return 0;
}
