#include <iostream>
#include <cmath>

using namespace std;


/*
 * Fie mulţimile A={a1,a2,...,an} şi B={b1, b2,...,bn}. Să se determine o
 * permutare a elementelor mulţimii A şi respectiv o permutare a elementelor mulţimii B
 * astfel încât valoarea sumei (ak-bk)^2 să fie maximă.
 *
 */


bool cmp(int a, int b) {
    return b < a;
}

int main() {
    int i, n, smax = 0;
    int *a;
    int *b;

    cout << "N = ";
    cin >> n;
    a = new int[n];
    b = new int[n];

    for (i = 0; i < n; i++) {
        cout << "A[" << i << "] = ";
        cin >> a[i];
    }
    for (i = 0; i < n; i++) {
        cout << "B[" << i << "] = ";
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n, cmp);
    for (i = 0; i < n; i++) {
        smax += pow(a[i] - b[i], 2);
    }

    cout << "A: ";
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "B: ";
    for (i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    cout << "Suma: " << smax;

    return 0;
}
