#include <math.h>
#include <iostream>
#include "Triangle.h"

using namespace std;


void main()
{
	Triangle tr1; //Обект tr1; извиква се конструкторът на класа
	double p, s;
	tr1.show("tr1");
	cout << "\nThe face of triangle1 is s = " << tr1.face(); //Зарежда се член-функция
	//tr1.face(); // без аргумент
	Triangle tr2; //Обект tr2; извиква се конструкторът на класа
	tr2.show("tr2");
	s = tr2.face(&p); //Зарежда се член-функция face() с аргумент
	cout << "\nThe face of triangle2 is s = " << s << ", and the perimeter is p = " << p;
}