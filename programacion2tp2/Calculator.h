#pragma once
#include "CalculationUtils.h"
#include "Vector3.h"

class Calculator
{
public:
	Calculator();
	~Calculator();
	void Start();
private:
	void RequestValues(Vector3& vec);
	Vector3 CalculateResult(Vector3& vec1, Vector3& vec2, Operations& operation);
	Vector3 CalculateResult(Vector3& vec1, float& scalar, Operations& operation);
	Operations GetOperation(Operand& operand);
	void PrintRetryMessage();
	Operand GetOperand();
	bool IsRecalculating();
};

