#pragma once
#include <iostream>
#include <string>

struct Vector3
{
public:
	float x;
	float y;
	float z;

	Vector3(float x, float y, float z);
	Vector3 operator + (Vector3 other);
	void operator += (Vector3 other);
	Vector3 operator - (Vector3 other);
	void operator -= (Vector3 other);
	Vector3 operator * (float other);
	void operator *= (Vector3 other);
	Vector3 operator / (float other);
	void operator /= (Vector3 other);
	float operator * (Vector3 other);
	bool operator == (Vector3 other);
	bool operator != (Vector3 other);
	Vector3 operator ^ (Vector3 other);

	std::string toString();

	

	//friend no es realmente un metodo de la clase. 
	//he's in the house but hes not the owner uwu rawr xd
	friend Vector3 operator * (float scalar, Vector3 vector);

	
};