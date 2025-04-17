#include "String.h"

String::String(const char* word)
{
	size = GetWordSize(word);


	for (int i = 0; i < size; i++)
		this->word.push_back(word[i]);
}

String::String(std::vector<char> newWord)
{
	word = newWord;
	size = newWord.size();

}

String::~String()
{
}

int String::GetWordSize(const char* word)
{
	bool wordFinished = false;
	int pos = 0;
	do
	{
		if (word[pos] == '\0')
		{
			size = pos + 1;
			wordFinished = true;
		}
		else
			pos++;

	} while (!wordFinished);

	return size;
}

int String::GetWordSize(String string)
{
	return size;
}

std::string String::GetSTLVersion()
{
	std::string myString = "";

	for (int i = 0; i < size; i++)
	{
		myString += word[i];
	}

	return myString;
}

/*
● + para sumar dos strings.
*/

String String::operator+(String other)
{
	auto resultWord = word;

	int wordSize = other.size;

	for (int i = 0; i < other.size; i++)
		resultWord.push_back(other.word[i]);

	size += other.size;

	return String(resultWord);
}

//● + para sumar un const char* a un string.


String String::operator+(const char* other)
{
	auto resultWord = word;

	int wordSize = GetWordSize(other);

	for (int i = 0; i < wordSize; i++)
		resultWord.push_back(other[i]);

	size += wordSize;

	return String(resultWord);
}

//● += para sumarle a un string la cadena de otro string.

void String::operator+=(String other)
{
	*this = *this + other;
}

//● += para sumarle a un string la cadena de un const char* .
void String::operator+=(const char* other)
{
	*this = *this + other;
}

//●* para concatenar el contenido de un string una cantidad n de veces dentro del
//mismo string(por ejemplo, hacer “text * 3” debe hacer que la cadena que se
//	devuelva sea “Hello Hello Hello” si originalmente la variable “text” tenía “Hello”).
String String::operator*(int other)
{
	size *= other;
	//a space for each repetition
	size += other;

	auto result = word;

	auto originalString = word;

	for (int i = 0; i < other-1; i++)
	{
		result.push_back(' ');

		for (int j = 0; j < originalString.size(); j++)
			result.push_back(originalString[j]);

	}

	return String(result);
}

//● < para saber si un string debe ser ordenado alfabéticamente antes que otro.

bool String::operator<(String other)
{
	return (word[0] < other.word[0]);
}

//● > para saber si un string debe ser ordenado alfabéticamente después que otro.

bool String::operator>(String other)
{
	return (word[0] > other.word[0]);
}
