#include <iostream>
#include <conio.h>

#define PRECISION 0.00001

int checkInputNumberInt();
double checkInputNumberDouble();
double simple(double a);
double magicRecursion(double& a, double& x);
using namespace std;

int main()
{
	char code;
	int variant;
	double a;
	double result = 0;
	do
	{
		do
		{
			cout << "Enter the number:" << endl;
			a = checkInputNumberDouble();
		} while (a < 1);
		do
		{
			cout << "Choose variant of calculation: \n1.Simple \n2.Recursion" << endl;
			variant = checkInputNumberInt();
		} while (variant > 2 || variant < 1);
		switch (variant)
		{
		case 1: result = simple(a);
			break;
		case 2:
			double variable = 0.5 * (1 + a);
			result = magicRecursion(a, variable);
			break;
		}
		cout << "Result: " << result << endl;
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
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error, please write int number!\n" << "Try again!" << endl;
		}
	}
	return a;
}