#include "triangle.h"
void main()
{
	triangle obj1;
	double s;
	s = obj1.face();
	obj1.show("triangle1");
	cout << "The face of tr1 is S = " << s;

	triangle obj2;
	triangle* p;
	p = &obj2;
	s = p->face();
	p->show("triangle2");
	cout << "\nThe face of tr2 is S = " << s;
}