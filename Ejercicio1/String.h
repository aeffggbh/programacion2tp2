#pragma once
/*
Crear una implementación propia de la clase string, donde la misma sea análoga a la
de std. Internamente, debe guardar la cadena en un vector de STL de chars. Para su uso,
debe contar con los siguientes operadores básicos implementados utilizando
sobrecargas:
● + para sumar dos strings.
● + para sumar un const char* a un string.
● += para sumarle a un string la cadena de otro string.
● += para sumarle a un string la cadena de un const char*.
Adicionalmente, debe tener implementaciones de los siguientes operadores:
● > para saber si un string debe ser ordenado alfabéticamente después que otro.
● < para saber si un string debe ser ordenado alfabéticamente antes que otro.
● * para concatenar el contenido de un string una cantidad n de veces dentro del
mismo string (por ejemplo, hacer “text * 3” debe hacer que la cadena que se
devuelva sea “Hello Hello Hello” si originalmente la variable “text” tenía “Hello”).
*/

#include <iostream>
#include <vector>

class String
{
private:
	std::vector<char> word;
	int size;

public:
	String(const char* word);
	String(std::vector<char> word);
	~String();
	int GetWordSize(const char* word);
	int GetWordSize(String string);
	std::string GetSTLVersion();
	String operator + (String other);
	String operator + (const char* other);
	void operator += (String other);
	void operator += (const char* other);
	String operator * (int other);
	bool operator < (String other);
	bool operator > (String other);
};

