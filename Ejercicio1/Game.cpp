#include "Game.h"


Game::Game()
{

}

Game::~Game()
{

}

/*
Crear un programa en donde se manipulen distintos strings de la clase creada, y
donde se prueben cada uno de los operadores. Dentro de la clase creada no puede usarse
el string de std. Además, la clase debe contar con un método que permita devolver la
cadena almacenada como un const char*, para permitir imprimir el contenido por
consola.
*/
void Game::Play()
{
	String* string1 = new String("Hola");
	String* string2 = new String("como");
	String* string3 = new String("estas");
	String* string4 = new String("Hola ");
	String* string5 = new String("mi amigo ");
	const char* constChar1 = "Pepito";

	std::cout << "SUM: ";
	//the space is a const char!
	std::cout << (*string1 + " " + *string2 + " " + *string3 + constChar1).GetSTLVersion() << std::endl;
	
	*string4 += *string5;
	*string4 += constChar1;
	std::cout << (*string4).GetSTLVersion() << std::endl;

	std::cout << "REPEAT: ";
	std::cout << (*string1 * 3).GetSTLVersion() << std::endl;
	
	std::cout << "Alphabetical order: ";



	delete string3;
	delete string2;
	delete string1;
}
