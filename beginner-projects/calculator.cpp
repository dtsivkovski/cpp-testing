#include <iostream>
using namespace std;

class Calculator {
    public:
        int add(int a, int b) {
            return (a + b);
        }
        int subtract (int a, int b) {
            return (a - b);
        }
        int multiply (int a, int b) {
            return (a * b);
        }
        double divide (int a, int b) {
            return a / (double) b;
        }
};

int main() {
    Calculator c;
    cout << c.add(7,5) << endl;
    cout << c.subtract(7,5) << endl;
    cout << c.multiply(7,5) << endl;
    cout << c.divide(7,5) << endl;
}