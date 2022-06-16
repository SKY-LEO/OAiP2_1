#include <iostream>
#include <conio.h>

#define PRECISION 0.00001

using namespace std;

int checkInputNumberInt();
double checkInputNumberDouble();
double simple(double a);
double magicRecursion(double& a, double& x);

int main()
{
	char code;
	double a;
	double result = 0;
	do
	{
		do
		{
			cout << "Enter the number:" << endl;
			a = checkInputNumberDouble();
		} while (a < 0 || a == 0);
		double variable = 0.5 * (1 + a);
		cout << "Result: \nSimple: " << simple(a) << "\nRecursion: " << magicRecursion(a, variable) << endl;
		cout << "Do you want to continue? Y/N" << endl;
		code = _getch();
	} while (code == 'y' || code == 'Y');
}

double magicRecursion(double& a, double& x)
{
	double x_prev = x;
	x = 0.5 * (x + a / x);
	if (x_prev - x > PRECISION)
	{
		return magicRecursion(a, x);
	}
	return x;
}

double simple(double a)
{
	return sqrt(a);
}

double checkInputNumberDouble()
{
	double a;
	while (true)
	{
		cin >> a;
		if (cin.get() == '\n') {
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Error, please write int number!\n" << "Try again!" << endl;
		}
	}
	return a;
}

int checkInputNumberInt()
{
	int a;
	while (true)
	{
		cin >> a;
		if (cin.get() == '\n') {
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Error, please write int number!\n" << "Try again!" << endl;
		}
	}
	return a;
}