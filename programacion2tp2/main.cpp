#include "Vector3.h"

using namespace std;

/*
Crear un programa que permita ingresar los valores x, y, z de dos vectores, y luego
ofrezca alguna de las siguientes opciones:
● Sumar
● Restar
● Escalar.
● Obtener producto punto.
● Obtener producto cruz.
Verificar que el resultado de la operación sea el correcto en todos los casos, y que no
se produzcan errores.
*/


enum Options
{
	SCALAR,
	VECTOR
};

enum Operations
{
	SUM,
	SUB,
	DOT,
	CRS,
	MUL,
	DIV
};

void RequestValues(Vector3& vec);
Vector3 CalculateResult(Vector3& vec1, Vector3& vec2, Operations& operation);
Vector3 CalculateResult(Vector3& vec1, float& scalar, Operations& operation);
Operations GetOperation(Options& option);
void PrintRetryMessage();
int main()
{
	Vector3 vec1{ 0,0,0 };
	Vector3 vec2{ 0,0,0 };

	Options currentOption;
	int optionInput = 0;
	float scalar;

	cout << "VECTOR CALCULATOR" << endl;
	cout << "Insert the first vector..." << endl;
	RequestValues(vec1);

	bool valid = false;
	do
	{
		cout << "Will you òperate with another vector or a scalar?" << endl;
		cout << static_cast<int>(SCALAR) << " - SCALAR" << endl;
		cout << static_cast<int>(VECTOR) << " - ANOTHER VECTOR" << endl;
		cin >> optionInput;

		if (optionInput < 0 || optionInput > static_cast<int>(VECTOR))
		{
			valid = false;
			PrintRetryMessage();
		}
		else
		{
			valid = true;
			currentOption = static_cast<Options>(optionInput);
		}

	} while (!valid);
	if (currentOption == VECTOR)
	{
		cout << "Insert the second vector..." << endl;
		RequestValues(vec2);

	}
	else
	{
		cout << "Insert the scalar..." << endl;
		cin >> scalar;
	}

	Operations operation = GetOperation(currentOption);

	Vector3 result{0,0,0};

	switch (currentOption)
	{
	case SCALAR:
		result = CalculateResult(vec1, scalar, operation);
		break;
	case VECTOR:
		result = CalculateResult(vec1, vec2, operation);
		break;
	default:
		break;
	}

	std::cin.get();
}

void RequestValues(Vector3& vec)
{
	cout << "X: ";
	cin >> vec.x;
	cout << endl << "Y: ";
	cin >> vec.y;
	cout << endl << "Z: ";
	cin >> vec.z;
	cout << endl << endl;
}

Vector3 CalculateResult(Vector3& vec1, Vector3 &vec2, Operations& operation)
{
	switch (operation)
	{
	case SUM:
		return vec1 + vec2;
		break;
	case SUB:
		return vec1 - vec2;
		break;
	case DOT:
		vec1 *= vec2;
		return vec1;
		break;
	case CRS:
		return vec1 ^ vec2;
		break;
	default:
		break;
	}
}

Vector3 CalculateResult(Vector3& vec1, float& scalar, Operations& operation)
{
	switch (operation)
	{
	case MUL:
		return vec1 * scalar;
		break;
	case DIV:
		return vec1 / scalar;
		break;
	default:
		break;
	}
}

//SUM,
//SUB,
//MUL,
//DOT,
//CRS

Operations GetOperation(Options& option)
{
	bool valid = false;

	int inserted = 0;

	do
	{
		cout << "Which operation do you wish to make?" << endl;
		cout << "(Only operations you can actually make are shown)" << endl;
		if (option == VECTOR)
		{
			cout << static_cast<int>(SUM) << " - SUM" << endl;
			cout << static_cast<int>(SUB) << " - SUBTRACT" << endl;
			cout << static_cast<int>(DOT) << " - DOT PRODUCT" << endl;
			cout << static_cast<int>(CRS) << " - CROSS PRODUCT" << endl;

		}
		else
		{
			cout << static_cast<int>(MUL) << " - MULTIPLY" << endl;
			cout << static_cast<int>(DIV) << " - DIV" << endl;
		}
		cin >> inserted;

		if (inserted < 0 || inserted > static_cast<int>(DIV))
		{
			valid = false;
			PrintRetryMessage();
		}
		else if (option == VECTOR && inserted >= static_cast<int>(MUL))
		{
			valid = false;
			PrintRetryMessage();
		}
		else if (option == SCALAR && inserted <= static_cast<int>(CRS))
		{
			valid = false;
			PrintRetryMessage();
		}
		else
			valid = true;

	} while (!valid);


	return static_cast<Operations>(inserted);
}

void PrintRetryMessage()
{
	cout << "Please try to insert the value again..." << endl;
	system("pause");
}


