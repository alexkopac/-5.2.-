#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double num;
    cout << "Введіть число: ";
    cin >> num;

    if (num >= 1 && num <= 30) {
        cout << "Число належить діапазону від 1 до 30." << endl;
    } else {
        cout << "Число НЕ належить діапазону від 1 до 30." << endl;
    }

    return 0;
}