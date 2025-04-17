#include "Calculator.h"
using namespace std;

Calculator::Calculator()
{

}

Calculator::~Calculator()
{

}

void Calculator::Start()
{
	Vector3 vec1{ 0,0,0 };
	Vector3 vec2{ 0,0,0 };

	Operand currentOperand;
	float scalar;

	do
	{
		system("cls");

		vec1 = { 0,0,0 };
		vec2 = { 0,0,0 };
		scalar = 0.0f;
		currentOperand = VECTOR;

		cout << "VECTOR CALCULATOR" << endl;
		cout << "Insert the first vector..." << endl;
		RequestValues(vec1);

		currentOperand = GetOperand();
		if (currentOperand == VECTOR)
		{
			cout << "Insert the second vector..." << endl;
			RequestValues(vec2);

		}
		else
		{
			bool valid = false;
			do
			{
				cout << "Insert the scalar..." << endl;
				cin >> scalar;
				if (scalar == 0)
				{
					cout << "It cannot be scaled by 0. Please try again." << endl;
					valid = false;
				}
				else
					valid = true;

			} while (!valid);
		}

		Operations operation = GetOperation(currentOperand);

		Vector3 result{ 0,0,0 };

		switch (currentOperand)
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

		cout << "Result: " << result.toString() << endl;

		std::cin.get();

	} while (IsRecalculating());

}

void Calculator::RequestValues(Vector3& vec)
{
	cout << "X: ";
	cin >> vec.x;
	cout << endl << "Y: ";
	cin >> vec.y;
	cout << endl << "Z: ";
	cin >> vec.z;
	cout << endl << endl;
}

Vector3 Calculator::CalculateResult(Vector3& vec1, Vector3& vec2, Operations& operation)
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

Vector3 Calculator::CalculateResult(Vector3& vec1, float& scalar, Operations& operation)
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

Operations Calculator::GetOperation(Operand& operand)
{
	bool valid = false;

	int inserted = 0;

	do
	{
		cout << "Which operation do you wish to make?" << endl;
		cout << "(Only operations you can actually make are shown)" << endl;
		if (operand == VECTOR)
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
		else if (operand == VECTOR && inserted >= static_cast<int>(MUL))
		{
			valid = false;
			PrintRetryMessage();
		}
		else if (operand == SCALAR && inserted <= static_cast<int>(CRS))
		{
			valid = false;
			PrintRetryMessage();
		}
		else
			valid = true;

	} while (!valid);


	return static_cast<Operations>(inserted);
}

void Calculator::PrintRetryMessage()
{
	cout << "Please try to insert the value again..." << endl;
	system("pause");
}

Operand Calculator::GetOperand()
{
	int optionInput = 0;
	bool valid = false;
	do
	{
		cout << "Will you operate with another vector or a scalar?" << endl;
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
			return static_cast<Operand>(optionInput);
		}

	} while (!valid);
}

bool Calculator::IsRecalculating()
{
	bool valid = false;
	int inserted = 0;

	do
	{
		cout << "Would you like to do another operation?" << endl;
		cout << "0 - NO" << endl;
		cout << "1 - YES" << endl;
		cin >> inserted;
		if (inserted < 0 || inserted > 1)
		{
			PrintRetryMessage();
			valid = false;
		}
		else
			return inserted;

	} while (!valid);

}


