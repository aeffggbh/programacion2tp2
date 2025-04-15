#include "Vector3.h"

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
{}

Vector3 Vector3::operator+(Vector3 other)
{
	return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
}

void Vector3::operator+=(Vector3 other)
{
	this->x = this->x + other.x;
	this->y = this->y + other.y;
	this->z = this->z + other.z;
}

Vector3 Vector3::operator-(Vector3 other)
{
	return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
}

void Vector3::operator-=(Vector3 other)
{
	this->x = this->x - other.x;
	this->y = this->y - other.y;
	this->z = this->z - other.z;
}

Vector3 Vector3::operator*(float other)
{
	return Vector3(this->x * other, this->y * other, this->z * other);
}

void Vector3::operator*=(Vector3 other)
{
	this->x = this->x * other.x;
	this->y = this->y * other.y;
	this->z = this->z * other.z;
}

Vector3 Vector3::operator/(float other)
{
	return Vector3(this->x / other, this->y / other, this->z / other);
}

void Vector3::operator/=(Vector3 other)
{
	this->x = this->x / other.x;
	this->y = this->y / other.y;
	this->z = this->z / other.z;
}



float Vector3::operator*(Vector3 other)
{
	return this->x * other.x + this->y * other.y + this->z * other.z;
}

//dot
bool Vector3::operator==(Vector3 other)
{
	return this->x == other.x && this->y == other.y && this->z == other.z;
}

bool Vector3::operator!=(Vector3 other)
{
	return this->x != other.x || this->y != other.y || this->z != other.z;
}

//cross
Vector3 Vector3::operator^(Vector3 other)
{
	return Vector3
	(
		this->y * other.z - this->z * other.y,
		this->z * other.x - this->x * other.z,
		this->x * other.y - this->y * other.x
	);
}

std::string Vector3::toString()
{
	return ("(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")");
}

Vector3 operator*(float scalar, Vector3 vector)
{
	return vector * scalar;
}
