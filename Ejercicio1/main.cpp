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
Tecnicatura Superior en Desarrollo de Videojuegos
Crear un programa en donde se manipulen distintos strings de la clase creada, y
donde se prueben cada uno de los operadores. Dentro de la clase creada no puede usarse
el string de std. Además, la clase debe contar con un método que permita devolver la
cadena almacenada como un const char*, para permitir imprimir el contenido por
consola.

*/