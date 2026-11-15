#include <iostream>
#include <math.h>
#include <iomanip>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	double x, xp, xk, dx, eps, S = 0, a;
	int n = 0;

	cout << "Введіть початкове значення x: ";
	cin >> xp;
	cout << "Введіть кінцеве значення x: ";
	cin >> xk;
	cout << "Введіть крок x: ";
	cin >> dx;
	cout << "Введіть точність eps: ";
	cin >> eps;

	cout << fixed;
	cout << "---------------------------------------------" << endl;
	cout << "|" << setw(7) << "x" << " |"
		<< setw(12) << "exp(x^2)" << " |"
		<< setw(20) << "Сума ряду" << " |"
		<< setw(5) << "n" << " |"
		<< endl;
	cout << "---------------------------------------------" << endl;

	x = xp;
	while (x <= xk + dx / 2.0)
	{
		n = 0;
		a = 1;
		S = a;
		do
		{
			n++;
			a *= pow(x, 2.0) / n;
			S += a;
		} while (abs(a) >= eps);

		cout << "|" << setw(7) << setprecision(5) << x << " |"
			<< setw(12) << setprecision(5) << exp(x * x) << " |"
			<< setw(12) << setprecision(5) << S << " |"
			<< setw(5) << n << " |" << endl;
		x += dx;
	}
	cout << "---------------------------------------------" << endl;

	return 0;
}