#include<iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

float max(float a, float b) {
    return (a > b) ? a : b;
}

int main() {
    cout << "Max of 5 and 10: " << max(5, 10) << endl;
    cout << "Max of 4.2 and 3.8: " << max(4.2f, 3.8f) << endl;
    return 0;
}
