#include <iostream>

using namespace std;

int x[101], n;

bool cont(int k) {
	for (int i = 1; i < k; i++) {
		if (x[k] == x[i]) return false;
	}
	return true;
}

void bkt(int k) {
	int i;	
	for (i = 1; i <= n; i++) {
		x[k] = i;
		if (cont(k)) {
			if (k == n) {
				for (int j = 1; j <= k; j++) {
					cout << x[j] << " "; 
				}
				cout << endl;
			} else {
				bkt(k+1);
			}
		}
	}
}


int main() {
	cout << "n = ";
	cin >> n;
	
	bkt(3);
	
	return 0;
} 
