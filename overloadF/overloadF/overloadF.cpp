#include<iostream>
using namespace std;


template <typename T1>

T1 compair(T1 a, T1 b) {
    int c;
    if (a > b)  c = 1;
	if (a == b) c = 0;
	if (a < b) c = -1;

    return c;
}

int main()

{
    setlocale(LC_ALL, "ru");
    float a, b;
    cout << "Введите первое число/символ" << endl;
    cin >> a;
    cout << "Введите второе число/символ" << endl;
    cin >> b;
    int result = compair('c', 'a');
    cout << result << endl;
    result = compair(a, b);
    cout << result << endl;
    result = compair(b, a);
    cout << result << endl;
    result = compair(b, b);
    cout << result << endl;

    return 0;
}