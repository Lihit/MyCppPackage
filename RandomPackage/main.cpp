#include <iostream>
#include "Random.cpp"

using namespace std;

int main() {
    Random<double> rand;
    Matrix<double> tmp = rand.randint(8, 100, 2, 3);
    cout << tmp;
    Matrix<double> tmp1 = rand.uniform(1, 3, 2, 2);
    cout << tmp1;
    Matrix<double> tmp2 = rand.gauss(5, 5, 0, 3);
    cout << tmp2;
    double tmp11 = rand.gauss();
    cout << tmp11 << endl;
    return 0;
}