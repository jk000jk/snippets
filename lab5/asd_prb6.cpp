// Scrieti un program care primeste la intrare o expresie aritmetica complet parantezata,
// cu valori numerice constante si construieste arborele binar asociat expresiei.

#include <iostream>
#include <sstream>
#include <cassert>

using namespace std;

typedef struct Nod {
    string info; // operator sau operand
    int precedenta; // se aplica doar pt operator
    struct Nod *parinte;
    struct Nod *stang;
    struct Nod *drept;
} CNod, *PNod;

PNod CreazaNod(const string &x) {
    PNod p = new CNod;
    p->parinte = p->stang = p->drept = NULL;
    p->info = x;
    return p;
}

bool IsOperator(const string &x) {
    // nu luam in considerare parantezele pt ca afecteaza doar precedenta
    return ((x.length() == 1) &&
            (x[0] == '*' ||
             x[0] == '/' ||
             x[0] == '+' ||
             x[0] == '-'));
}

bool IsParentezaStanga(const string &x) {
    return x == "(";
}

bool IsParentezaDreapta(const string &x) {
    return x == ")";
}

bool IsOperand(const string &x) {
    int y;
    stringstream ss(x);
    if (ss >> y) return true;
    else return false;
}

int Precedenta(const string &x) {
    assert(IsOperator(x));
    if (x[0] == '*' || x[0] == '/') return 2;
    else return 1;
}

PNod CreazaArbore(const string &exp) {
    PNod root = CreazaNod("0"); // un root oarecare cu precedenta minima
    root->precedenta = INT_MIN;

    PNod preOperand = NULL; // operandul din inaintea operatorului curent
    PNod preOperator = root; // operatorul din inaintea operatorului curent
    int corectie = 0; // impactul parantezelor

    string token;
    stringstream ss(exp);

    while (ss >> token) {
        if (IsOperand(token)) {
            preOperand = CreazaNod(token);
        } else if (IsOperator(token)) {
            PNod p = CreazaNod(token);
            p->precedenta = Precedenta(token) + corectie;
            if (p->precedenta > preOperator->precedenta) {
                p->stang = preOperand;
                preOperator->drept = p;
                p->parinte = preOperator;
            } else {
                preOperator->drept = preOperand;
                PNod q = preOperator->parinte;
                while (p->precedenta <= q->precedenta) q = q->parinte;

                p->stang = q->drept;
                q->drept = p;
                p->parinte = q;
            }
            preOperand = NULL;
            preOperator = p;

        } else if (IsParentezaStanga(token)) {
            corectie += 2;
        } else if (IsParentezaDreapta(token)) {
            corectie -= 2;
        } else {
            cout << "caracter gresit: " << token << endl;
            break;
        }
    }

    if (preOperand == NULL)
        cout << "expresia nu poate sa se termine cu un operator: "
             << preOperator->info << endl;
    else preOperator->drept = preOperand;

    PNod realRoot = root->drept;
    delete root;
    if (realRoot) realRoot->parinte = NULL;
    return realRoot;
}

void PostOrderPrint(PNod node) {
    if (node) {
        PostOrderPrint(node->stang);
        PostOrderPrint(node->drept);
        cout << node->info << " ";
    }
}

void PreOrderPrint(PNod node) {
    if (node) {
        cout << node->info << " ";
        PostOrderPrint(node->stang);
        PostOrderPrint(node->drept);
    }
}

void InOrderPrint(PNod node) {
    if (node) {
        PostOrderPrint(node->stang);
        cout << node->info << " ";
        PostOrderPrint(node->drept);
    }
}

int main() {
    // operatori valizi: + - * / ( )
    // doar integeri si spatii intre ex: ( 1 + 2 ) * 3
    // ex. 2 * 3 / ( 2 - 1 ) + 5 * ( 4 - 1 )

    cout << "Exp: ";
    string exp;
    getline(cin, exp);
    cout << endl;

    PNod root = CreazaArbore(exp);
    cout << "Post Order: ";
    PostOrderPrint(root);
    cout << endl;

    cout << "Pre Order: ";
    PreOrderPrint(root);
    cout << endl;

    cout << "In Order: ";
    InOrderPrint(root);
    cout << endl;
}


// Exp: 2 * 3 / ( 2 - 1 ) + 5 * ( 4 - 1 )

// Post Order: 2 3 * 2 1 - / 5 4 1 - * + 
// Pre Order: + 2 3 * 2 1 - / 5 4 1 - * 
// In Order: 2 3 * 2 1 - / + 5 4 1 - * 

/*


    An operand in an infix expression belongs to either the right child of the operator in front of it, 
    or the left child of the operator behind it.

    If an operator OP2 has higher precedence than its preceding operator OP1, the previous operand x 
    becomes the left child of OP2, and OP2 becomes the right child of OP1.

    If an operator OP2 has lower precedence than its preceding operator OP1, the previous operand x 
    becomes the right child of OP1. Go up the tree from OP1, compare the precedence of each ancestor of 
    OP1 with that of OP2 until OP2 <= ancestor OP. Then OP2 becomes the right child of OP.

*/
