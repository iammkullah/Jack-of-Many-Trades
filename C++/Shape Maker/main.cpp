#include <iostream>
#include "Geometry.h"
using namespace std;

int main(){
	
	Point p1(-1,-2);
	Point p2(10,-2);
	cout << p1.getX() << endl;

	LineSegment l(p1, p2);
	cout << l.getXmin() << " " << l.getXmax() << endl;
	cout << l.length() << endl;

	p2.translate(0,2);
	Rectangle r(p1,p2);
	r.rotate();
	cout << r.getYmin() << " " << r.getYmax() << endl;
	cout << r.area() << endl;

	Point p3(1,2,3);
	Circle c(p3, 2);
	cout << c.area() << endl;
	c.scale(10);
	cout << c.area() << endl;

	auto pp1 = make_shared<Point>(0,0);
	auto pp2 = make_shared<Point>(0,19);
	auto pp3 = make_shared<Point>(59,19);
	auto pp4 = make_shared<Point>(59,0);
	auto pp5 = make_shared<Point>(55,19);
	auto pp6 = make_shared<Point>(30,0);

	auto lp = make_shared<LineSegment>(*pp2,*pp3);
	auto rp = make_shared<Rectangle>(*pp4,*pp5);
	auto cp = make_shared<Circle>(*pp6,10);
	Scene s;
	s.addObject(pp1);
	s.addObject(lp);
	s.addObject(rp);
	s.addObject(cp);
	cout << s;

	cout << endl;

	rp->rotate();
	cp->translate(0,-5);
	cout << s;
}
