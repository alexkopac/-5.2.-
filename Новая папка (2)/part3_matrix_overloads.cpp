#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    long long n;
    cout << "Введіть ціле число: ";
    cin >> n;

    long long temp = abs(n);
    int count = 0;

    if (temp == 0) {
        count = 1;
    } else {
        while (temp > 0) {
            temp /= 10;
            count++;
        }
    }

    cout << "Кількість цифр у числі: " << count << endl;
    return 0;
}