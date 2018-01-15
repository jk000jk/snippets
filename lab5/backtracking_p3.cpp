#include <iostream>
#include <vector>

using namespace std;

/*
 * 3. După o noapte de chef Cetăţeanul Turmentat se află în faţa unei mari probleme:
 * trebuie să urce cele n trepte până la uşa casei sale. Din cauza stării de ebrietate
 * avansate Cetăţeanul Turmentat nu poate să urce decât fie o treaptă, fie două.
 * Ajutaţi-l, indicându-i toate modurile în care el poate să urce cele n trepte,
 * precum şi câte moduri are în total la dispoziţie.
 */



void printmod(vector<int> *pasi) {
    for (unsigned i = 0; i < pasi->size(); i++) {
        cout << (*pasi)[i] << " ";
    }
    cout << endl;
}

void backtracking(vector<int> pasi, int s, int *nr) {
    if (s == 0) {
        printmod(&pasi);
        *nr = *nr+1;
    } else {
        vector<int> n1 = pasi;
        n1.push_back(1);
        backtracking(n1, s - 1, nr);
        if (s > 1) {
            vector<int> n2 = pasi;
            n2.push_back(2);
            backtracking(n2, s - 2, nr);
        }
    }
}

int main() {
    int nrpasi = 0, n;
    vector<int> r;

    cout << "n = ";
    cin >> n;

    backtracking(r, n, &nrpasi);

    cout << endl << "Moduri: " << nrpasi << endl;

    return 0;
}
