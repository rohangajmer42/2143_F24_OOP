#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

    cout << "Hello, World!" << endl;
    string f1, op, f2;
    int d1, d2, n1, n2;

    while (cin >> f1 >> op >> f2) {
        // Output the input fractions and operator
        cout << f1 << " " << op << " " << f2 << endl;

        // Find the slash positions to extract the numerator and denominator for both fractions
        size_t slashPos1 = f1.find('/');
        size_t slashPos2 = f2.find('/');

        // Parse the numerator and denominator from the input fractions
        n1 = stoi(f1.substr(0, slashPos1));  // Extract numerator of first fraction
        d1 = stoi(f1.substr(slashPos1 + 1));  // Extract denominator of first fraction
        n2 = stoi(f2.substr(0, slashPos2));  // Extract numerator of second fraction
        d2 = stoi(f2.substr(slashPos2 + 1));  // Extract denominator of second fraction

        // Output parsed numerators and denominators
        cout << n1 << " " << d1 << " " << n2 << " " << d2 << endl;

        // Perform the required operation based on the operator
        if (op == "+") {
            cout << n1 << "/" << d1 << " + " << n2 << "/" << d2 << " = "
                 << n1 * d2 + n2 * d1 << "/" << d1 * d2 << endl;
        } else if (op == "-") {
            cout << n1 << "/" << d1 << " - " << n2 << "/" << d2 << " = "
                 << n1 * d2 - n2 * d1 << "/" << d1 * d2 << endl;
        } else if (op == "*") {
            cout << n1 << "/" << d1 << " * " << n2 << "/" << d2 << " = "
                 << n1 * n2 << "/" << d1 * d2 << endl;
        } else if (op == "/") {
            cout << n1 << "/" << d1 << " / " << n2 << "/" << d2 << " = "
                 << n1 * d2 << "/" << d1 * n2 << endl;
        } else {
            cout << "Unknown operator: " << op << endl;
        }
    }

    return 0;
}
