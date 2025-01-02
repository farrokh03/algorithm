#include <iostream>
#include <cmath> 
using namespace std;

int range(unsigned long long int number) {
    if (number == 0) return 1;
    return log10(number) + 1;
}
unsigned long long int power(unsigned long long int base, int exp) {
    unsigned long long int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}

unsigned long long int multiplication(unsigned long long int a, unsigned long long int b) {
    int len1 = range(a);
    int len2 = range(b);
    int m = max(len1, len2) / 2;

    if (a == 0 || b == 0)
        return 0;
    else if (a <= 9 && b <= 9)
        return a * b;

    unsigned long long int a1 = a / power(10, m);
    unsigned long long int a2 = a % power(10, m);
    unsigned long long int b1 = b / power(10, m);
    unsigned long long int b2 = b % power(10, m);

    unsigned long long int multiplication_one = multiplication(a1, b1);
    unsigned long long int multiplication_two = multiplication(a2, b2);
    unsigned long long int cross_terms = multiplication(a1 + a2, b1 + b2) - multiplication_one - multiplication_two;

    return multiplication_one * power(10, 2 * m) + (cross_terms * power(10, m)) + multiplication_two;
}

int main() {
    unsigned long long int u, v;
    cin >> u >> v;
    unsigned long long int result = multiplication(u, v);
    cout << result ;
    return 0;
}
