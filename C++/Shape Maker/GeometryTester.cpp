#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Geometry.h"
#include "GeometryTester.h"

using namespace std;

GeometryTester::GeometryTester() : error_(false), funcname_("") {

	string blankline(Scene::WIDTH, ' ');
	for(int i=0;i<Scene::HEIGHT;i++) blankpage_ += (blankline + "\n");

}

// Point ctor, basics
void GeometryTester::testa() {
	funcname_ = "GeometryTester::testa";

	{
	// default depth
	Point p(0,0);
	if (p.getX() != 0)
		errorOut_("p x-coord reported as" , p.getX(), 1);
	if (p.getY() != 0)
		errorOut_("p y-coord reported as ", p.getY(), 1);
	if (p.getDepth() != 0)
		errorOut_("p depth reported as ", p.getDepth(), 1);

	// specified depth
	Point q(1,-2,3);
	if (q.getX() != 1)
		errorOut_("q x-coord reported as ", q.getX(), 2);
	if (q.getY() != -2)
		errorOut_("q y-coord reported as ", q.getY(), 2);
	if (q.getDepth() != 3)
		errorOut_("q depth reported as ", q.getDepth(), 2);
	}

	passOut_();
}

// point translate, contains
void GeometryTester::testb() {
	funcname_ = "GeometryTester::testb";

	{
	Point p(1,2);
	p.translate(3,-4);
	if (p.getX() != 4)
		errorOut_("translated p x-coord reported as ", p.getX(), 1);
	if (p.getY() != -2)
		errorOut_("translated p y-coord reported as ", p.getY(), 1);

	Point q(-1,-2);
	if (!q.contains(q))
		errorOut_("q does not contain q?", 2);
	if (q.contains(Point(1,-2)) || q.contains(Point(-1,2)) || q.contains(p))
		errorOut_("q contains another pt?", 2);

	}

	passOut_();
}

// point rotate, scale no effect
void GeometryTester::testc() {
	funcname_ = "GeometryTester::testc";

	{
	Point p(-1,-2);
	p.rotate();
	if (p.getX() != -1)
		errorOut_("rotated p x-coord reported as ", p.getX(), 1);
	if (p.getY() != -2)
		errorOut_("rotated p y-coord reported as ", p.getY(), 1);

	Point q(-5,6);
	q.scale(2);
	if (q.getX() != -5)
		errorOut_("scaled up q x-coord reported as ", q.getX(), 2);
	if (q.getY() != 6)
		errorOut_("scaled up q y-coord reported as ", q.getY(), 2);
	q.scale(0.25);
	if (q.getX() != -5)
		errorOut_("scaled down q x-coord reported as ", q.getX(), 2);
	if (q.getY() != 6)
		errorOut_("scaled down q y-coord reported as ", q.getY(), 2);

	}

	passOut_();
}

// LineSegment ctor, basics, length
void GeometryTester::testd() {
	funcname_ = "GeometryTester::testd";

	{
	// horizontal line, default depth
	Point p1(1,2);
	Point p2(5,2);
	LineSegment l1(p1,p2);
	if (l1.getXmin() != 1) errorOut_("l1 Xmin reported as ",l1.getXmin(),1);
	if (l1.getXmax() != 5) errorOut_("l1 Xmax reported as ",l1.getXmax(),1);
	if (l1.getYmin() != 2) errorOut_("l1 Ymin reported as ",l1.getYmin(),1);
	if (l1.getYmax() != 2) errorOut_("l1 Ymax reported as ",l1.getYmax(),1);
	if (l1.getDepth() != 0) errorOut_("l1 depth reported as ",l1.getDepth(),1);
	if (l1.length() != 4) errorOut_("l1 length reported as ",l1.length(),1);

	// vertical line, opp dir, specified depth
	Point p3(5,4,1);
	Point p4(5,2,1);
	LineSegment l2(p3,p4);
	if (l2.getXmin() != 5) errorOut_("l2 Xmin reported as ",l2.getXmin(),2);
	if (l2.getXmax() != 5) errorOut_("l2 Xmax reported as ",l2.getXmax(),2);
	if (l2.getYmin() != 2) errorOut_("l2 Ymin reported as ",l2.getYmin(),2);
	if (l2.getYmax() != 4) errorOut_("l2 Ymax reported as ",l2.getYmax(),2);
	if (l2.getDepth() != 1) errorOut_("l2 depth reported as ",l2.getDepth(),2);
	if (l2.length() != 2) errorOut_("l2 length reported as ",l2.length(),2);

	}

	passOut_();
}

// line segment translate, rotate
void GeometryTester::teste() {
	funcname_ = "GeometryTester::teste";

	{
	Point p1(1,2);
	Point p2(5,2);
	Point p3(5,4);
	LineSegment l1(p1,p2);
	LineSegment l2(p2,p3);

	l1.translate(2,3);
	if (l1.getXmin() != 3) errorOut_("translated l1 xmin reported as ",l1.getXmin(),1);
	if (l1.getXmax() != 7) errorOut_("translated l1 xmax reported as ",l1.getXmax(),1);
	if (l1.getYmin() != 5) errorOut_("translated l1 ymin reported as ",l1.getYmin(),1);
	if (l1.getYmax() != 5) errorOut_("translated l1 ymax reported as ",l1.getYmax(),1);

	l2.translate(-2,-3);
	if (l2.getXmin() != 3) errorOut_("translated l1 xmin reported as ",l2.getXmin(),1);
	if (l2.getXmax() != 3) errorOut_("translated l2 xmax reported as ",l2.getXmax(),1);
	if (l2.getYmin() != -1) errorOut_("translated l2 ymin reported as ",l2.getYmin(),1);
	if (l2.getYmax() != 1) errorOut_("translated l2 ymax reported as ",l2.getYmax(),1);

	l1.translate(-2,-3);
	l2.translate(2,3);

	l1.rotate();
	if (l1.getXmin() != 3) errorOut_("rotated l1 xmin reported as ",l1.getXmin(),2);
	if (l1.getXmax() != 3) errorOut_("rotated l1 xmax reported as ",l1.getXmax(),2);
	if (l1.getYmin() != 0) errorOut_("rotated l1 ymin reported as ",l1.getYmin(),2);
	if (l1.getYmax() != 4) errorOut_("rotated l1 ymax reported as ",l1.getYmax(),2);

	l2.rotate();
	if (l2.getXmin() != 4) errorOut_("rotated l2 xmin reported as ",l2.getXmin(),2);
	if (l2.getXmax() != 6) errorOut_("rotated l2 xmax reported as ",l2.getXmax(),2);
	if (l2.getYmin() != 3) errorOut_("rotated l2 ymin reported as ",l2.getYmin(),2);
	if (l2.getYmax() != 3) errorOut_("rotated l2 ymax reported as ",l2.getYmax(),2);

	}

	passOut_();
}

// line segment contains, scale
void GeometryTester::testf() {
	funcname_ = "GeometryTester::testf";

	{
	Point p1(1,2);
	Point p2(5,2);
	Point p3(5,4);
	LineSegment l1(p2,p1);
	LineSegment l2(p3,p2);

	if (!l1.contains(Point(3,2))) errorOut_("l1 does not contain (3,2)?",1);
	if (!l1.contains(Point(1,2))) errorOut_("l1 does not contain (1,2)?",1);
	if (l1.contains(Point(-1,2))) errorOut_("l1 contains (-1,2)?",1);
	if (l1.contains(Point(2,1))) errorOut_("l1 contains (2,1)?",1);

	if (!l2.contains(Point(5,3))) errorOut_("l2 does not contain (5,3)?",1);
	if (!l2.contains(Point(5,4))) errorOut_("l2 does not contain (5,4)?",1);
	if (l2.contains(Point(5,0))) errorOut_("l2 contains (5,0)?",1);
	if (l2.contains(Point(0,0))) errorOut_("l2 contains (0,0)?",1);

	l1.scale(0.5);
	if (l1.getXmin() != 2) errorOut_("scaled l1 xmin reported as ",l1.getXmin(),2);
	if (l1.getXmax() != 4) errorOut_("scaled l1 xmax reported as ",l1.getXmax(),2);
	if (l1.getYmin() != 2) errorOut_("scaled l1 ymin reported as ",l1.getYmin(),2);
	if (l1.getYmax() != 2) errorOut_("scaled l1 ymax reported as ",l1.getYmax(),2);

	l2.scale(3);
	if (l2.getXmin() != 5) errorOut_("scaled l2 xmin reported as ",l2.getXmin(),2);
	if (l2.getXmax() != 5) errorOut_("scaled l2 xmax reported as ",l2.getXmax(),2);
	if (l2.getYmin() != 0) errorOut_("scaled l2 ymin reported as ",l2.getYmin(),2);
	if (l2.getYmax() != 6) errorOut_("scaled l2 ymax reported as ",l2.getYmax(),2);

	}

	passOut_();
}

// rect ctor, basics
void GeometryTester::testg() {
	funcname_ = "GeometryTester::testg";

	{
	// BL-TR, default depth
	Point p1(2,1);
	Point q1(6,5);
	Rectangle r1(p1,q1);
	if (r1.getXmin() != 2) errorOut_("r1 xmin reported as ",r1.getXmin(),1);
	if (r1.getXmax() != 6) errorOut_("r1 xmax reported as ",r1.getXmax(),1);
	if (r1.getYmin() != 1) errorOut_("r1 ymin reported as ",r1.getYmin(),1);
	if (r1.getYmax() != 5) errorOut_("r1 ymin reported as ",r1.getYmax(),1);
	if (r1.getDepth() != 0) errorOut_("r1 depth reported as ",r1.getDepth(),1);

	// TL-BR, specified depth
	Point p2(-1,6,2);
	Point q2(1,-2,2);
	Rectangle r2(p2,q2);
	if (r2.getXmin() != -1) errorOut_("r2 xmin reported as ",r2.getXmin(),2);
	if (r2.getXmax() != 1) errorOut_("r2 xmax reported as ",r2.getXmax(),2);
	if (r2.getYmin() != -2) errorOut_("r2 ymin reported as ",r2.getYmin(),2);
	if (r2.getYmax() != 6) errorOut_("r2 ymax reported as ",r2.getYmax(),2);
	if (r2.getDepth() != 2) errorOut_("r2 depth reported as ",r2.getDepth(),2);

	}
	passOut_();
}

// rect contains, translate
void GeometryTester::testh() {
	funcname_ = "GeometryTester::testh";

	{
	Point p(2,1);
	Point q(6,5);
	Rectangle r(p,q);
	if (!r.contains(Point(3,3))) errorOut_("r does not contain (3,3)?",1);
	if (!r.contains(Point(6,3))) errorOut_("r does not contain (6.3)?",1);
	if (!r.contains(Point(4,1))) errorOut_("r does not contain (4,1)?",1);
	if (!r.contains(Point(6,1))) errorOut_("r does not contain (6,1)?",1);
	if (r.contains(Point(7,3))) errorOut_("r contains (7,3)?",1);
	if (r.contains(Point(5,0))) errorOut_("r contains (5,0)?",1);

	r.translate(-1,3);
	if (r.getXmin() != 1) errorOut_("translated r xmin reported as ",r.getXmin(),2);
	if (r.getXmax() != 5) errorOut_("translated r xmax reported as ",r.getXmax(),2);
	if (r.getYmin() != 4) errorOut_("translated r ymin reported as ",r.getYmin(),2);
	if (r.getYmax() != 8) errorOut_("translated r ymax reported as ",r.getYmax(),2);

	}

	passOut_();
}

// rect rotate, scale
void GeometryTester::testi() {
	funcname_ = "GeometryTester::testi";

	{
	Point p(6,3);
	Point q(2,1);
	Rectangle r(p,q);
	r.rotate();
	if (r.getXmin() != 3) errorOut_("rotated r xmin reported as ",r.getXmin(),1);
	if (r.getXmax() != 5) errorOut_("rotated r xmax reported as ",r.getXmax(),1);
	if (r.getYmin() != 0) errorOut_("rotated r ymin reported as ",r.getYmin(),1);
	if (r.getYmax() != 4) errorOut_("rotated r ymax reported as ",r.getYmax(),1);
	r.rotate();
	if (r.getXmin() != 2) errorOut_("rotated again r xmin reported as ",r.getXmin(),1);
	if (r.getXmax() != 6) errorOut_("rotated again r xmax reported as ",r.getXmax(),1);
	if (r.getYmin() != 1) errorOut_("rotated again r ymin reported as ",r.getYmin(),1);
	if (r.getYmax() != 3) errorOut_("rotated again r ymax reported as ",r.getYmax(),1);

	Rectangle r2(p,q);
	r2.scale(2);
	if (r2.getXmin() != 0) errorOut_("scaled r2 xmin reported as ",r2.getXmin(),2);
	if (r2.getXmax() != 8) errorOut_("scaled r2 xmax reported as ",r2.getXmax(),2);
	if (r2.getYmin() != 0) errorOut_("scaled r2 ymin reported as ",r2.getYmin(),2);
	if (r2.getYmax() != 4) errorOut_("scaled r2 ymax reported as ",r2.getYmax(),2);
	r2.scale(0.25);
	if (r2.getXmin() != 3) errorOut_("scaled again r2 xmin reported as ",r2.getXmin(),2);
	if (r2.getXmax() != 5) errorOut_("scaled again r2 xmax reported as ",r2.getXmax(),2);
	if (r2.getYmin() != 1.5) errorOut_("scaled again r2 ymin reported as ",r2.getYmin(),2);
	if (r2.getYmax() != 2.5) errorOut_("scaled again r2 ymax reported as ",r2.getYmax(),2);

	}

	passOut_();
}

// circle ctor, basics
void GeometryTester::testj() {
	funcname_ = "GeometryTester::testj";

	{
	Point p(1,2);
	Circle c(p,3);
	if (c.getX() != 1) errorOut_("c x reported as ",c.getX(),1);
	if (c.getY() != 2) errorOut_("c y reported as ",c.getY(),1);
	if (c.getR() != 3) errorOut_("c r reported as ",c.getR(),1);
	if (c.getDepth() != 0) errorOut_("c depth reported as ",c.getDepth(),1);

	Point p2(-1,-2,1);
	Circle c2(p2,3);
	if (c2.getX() != -1) errorOut_("c2 x reported as ",c2.getX(),2);
	if (c2.getY() != -2) errorOut_("c2 y reported as ",c2.getY(),2);
	if (c2.getR() != 3) errorOut_("c2 r reported as ",c2.getR(),2);
	if (c2.getDepth() != 1) errorOut_("c2 depth reported as ",c2.getDepth(),2);

	}

	passOut_();
}

// circle contains, rotate no effect
void GeometryTester::testk() {
	funcname_ = "GeometryTester::testk";

	{
	Point p(1,2);
	Circle c(p,3);
	if (!c.contains(p)) errorOut_("c does not contain p?",1);
	if (!c.contains(Point(3.9,2))) errorOut_("c does not contain (3.9,2)?",1);
	if (!c.contains(Point(3.1,4.1))) errorOut_("c does not contain (3.1,4.1)?",1);
	if (!c.contains(Point(-1.1,4.1))) errorOut_("c does not contain (-1.1,4.1)?",1);
	if (!c.contains(Point(-1.1,-0.1))) errorOut_("c does not contain (-1.1,-0.1)?",1);
	if (!c.contains(Point(3.1,-0.1))) errorOut_("c does not contain (3.1,-0.1)?",1);
	if (c.contains(Point(3.2,4.2))) errorOut_("c contains (3.2,4.2)?",1);
	if (c.contains(Point(-1.2,4.2))) errorOut_("c contains (-1.2,4.2)?",1);
	if (c.contains(Point(-1.2,-0.2))) errorOut_("c contains (-1.2,-0.2)?",1);
	if (c.contains(Point(3.2,-0.2))) errorOut_("c contains (3.2,-0.2)?",1);

	c.rotate();
	if (c.getX() != 1) errorOut_("rotated c x reported as ",c.getX(),2);
	if (c.getY() != 2) errorOut_("rotated c y reported as ",c.getY(),2);
	if (c.getR() != 3) errorOut_("rotated c r reported as ",c.getR(),2);

	}

	passOut_();
}

// circle translate, scale
void GeometryTester::testl() {
	funcname_ = "GeometryTester::testl";

	{
	Point p(1,2);
	Circle c(p,3);
	c.translate(-5,-7);
	if (c.getX() != -4) errorOut_("translated c x reported as ",c.getX(),1);
	if (c.getY() != -5) errorOut_("translated c y reported as ",c.getY(),1);
	if (c.getR() != 3) errorOut_("translated c r reported as ",c.getR(),1);

	Circle c2(p,3);
	c2.scale(3);
	if (c2.getX() != 1) errorOut_("scaled up c2 x reported as ",c2.getX(),2);
	if (c2.getY() != 2) errorOut_("scaled up c2 y reported as ",c2.getY(),2);
	if (c2.getR() != 9) errorOut_("scaled up c2 r reported as ",c2.getR(),2);

	c2.scale(0.5);
	if (c2.getX() != 1) errorOut_("scaled down c2 x reported as ",c2.getX(),2);
	if (c2.getY() != 2) errorOut_("scaled down c2 y reported as ",c2.getY(),2);
	if (c2.getR() != 4.5) errorOut_("scaled down c2 r reported as ",c2.getR(),2);

	}

	passOut_();
}

// depth
void GeometryTester::testm() {
	funcname_ = "GeometryTester::testm";

	{
	bool b;

	// point
	Point p(1,-2,3);
	b = p.setDepth(4);
	if (!b) errorOut_("p non-neg setDepth returned false", 1);
	if (p.getDepth() != 4)
		errorOut_("p new depth reported as ", p.getDepth(), 2);
	b = p.setDepth(-1);
	if (b) errorOut_("p neg setDepth returned true", 1);
	if (p.getDepth() != 4)
		errorOut_("p neg setDepth set to ", p.getDepth(), 2);

	// line
	LineSegment l(Point(0,0,5), Point(0,2,5));
	b = l.setDepth(2);
	if (!b) errorOut_("l non-neg setDepth returned false", 1);
	if (l.getDepth() != 2)
		errorOut_("l new depth reported as ", l.getDepth(), 2);
	b = l.setDepth(-2);
	if (b) errorOut_("l neg depth returned true", 1);
	if (l.getDepth() != 2)
		errorOut_("l neg setDepth set to ", l.getDepth(), 2);

	// rect
	Rectangle r(Point(-3,-4), Point(5,6));
	b = r.setDepth(3);
	if (!b) errorOut_("r non-neg setDepth returned false", 1);
	if (r.getDepth() != 3)
		errorOut_("r new depth reported as ", r.getDepth(), 2);
	b = r.setDepth(-3);
	if (b) errorOut_("r neg depth returned true", 1);
	if (r.getDepth() != 3)
		errorOut_("r neg setDepth set to ", r.getDepth(), 2);

	// circle
	Circle c(Point(0,-2,4), 10);
	b = c.setDepth(0);
	if (!b) errorOut_("c non-neg setDepth returned false", 1);
	if (c.getDepth() != 0)
		errorOut_("c new depth reported as ", c.getDepth(), 2);
	b = c.setDepth(-4);
	if (b) errorOut_("c neg depth returned true", 1);
	if (c.getDepth() != 0)
		errorOut_("c neg setDepth set to ", c.getDepth(), 2);

	// poly
	Shape* sp[4];
	sp[0] = &p; sp[1] = &l; sp[2] = &r; sp[3] = &c;
	for(int i=0;i<4;i++) {
		sp[i]->setDepth(i);
		if (sp[i]->getDepth() != i)
			errorOut_("get/setdepth wrong for sp", i, 2);
	}

	}
	passOut_();
}

// dim, polymorphic
void GeometryTester::testn() {
	funcname_ = "GeometryTester::testn";

	{
	Shape* sp[4];
	sp[0] = new Point(0,0);
	sp[1] = new LineSegment(Point(0,0), Point(4,0));
	sp[2] = new Rectangle(Point(0,0), Point(6,4));
	sp[3] = new Circle(Point(0,0), 7);

	if (sp[0]->dim() != 0)
		errorOut_("dim sp[0] reported as ",sp[0]->dim(),0);
	if (sp[1]->dim() != 1)
		errorOut_("dim sp[1] reported as ",sp[1]->dim(),0);
	if (sp[2]->dim() != 2)
		errorOut_("dim sp[2] reported as ",sp[2]->dim(),0);
	if (sp[3]->dim() != 2)
		errorOut_("dim sp[3] reported as ",sp[3]->dim(),0);

	}

	passOut_();
}

// area, polymorphic
void GeometryTester::testo() {
	funcname_ = "GeometryTester::testo";

	{
	Rectangle r(Point(-1,-2), Point(3,4));
	if (r.area() != 24) errorOut_("r area reported as ", r.area(), 1);
	Rectangle r2(Point(5,-6), Point(-7,8));
	if (r2.area() != 168) errorOut_("r2 area reported as ", r2.area(), 1);

	Circle c(Point(2,3), 10);
	if (c.area() < 314.1 || c.area() > 314.2)
		errorOut_("c area reported as ", c.area(), 2);
	Circle c2(Point(4,5), 6);
	if (c2.area() < 113.0 || c2.area() > 113.1)
		errorOut_("c2 area reported as ", c.area(), 2);

	TwoDShape& s1 = r;
	TwoDShape& s2 = c;
	if (s1.area() != 24) errorOut_("s1 area reported as ", s1.area(), 1);
	if (s2.area() < 314.1 || s2.area() > 314.2)
		errorOut_("s2 area reported as ", s2.area(), 2);

	}

	passOut_();
}

// polymorphic contains, translate
void GeometryTester::testp() {
	funcname_ = "GeometryTester::testp";

	{
	Shape* sp[4];
	sp[0] = new Point(0,0);
	sp[1] = new LineSegment(Point(0,0), Point(4,0));
	sp[2] = new Rectangle(Point(0,0), Point(6,4));
	sp[3] = new Circle(Point(0,0), 7);

	for(int i=0;i<4;i++) {
		if (!sp[i]->contains(Point(0,0)))
			errorOut_("sp" + std::to_string(i) + " not contain (0,0)?",1);
	}

	for(int i=0;i<4;i++) sp[i]->translate(3,-2);

	for(int i=0;i<4;i++) {
		if (!sp[i]->contains(Point(3,-2)))
			errorOut_("sp" + std::to_string(i) + " contains wrong after translate",2);
	}

	}

	passOut_();
}

// polymorphic rotate, scale
void GeometryTester::testq() {
	funcname_ = "GeometryTester::testq";

	{
	Shape* sp[4];
	sp[0] = new Point(1,1);
	sp[1] = new LineSegment(Point(0,3), Point(6,3));
	sp[2] = new Rectangle(Point(0,2), Point(6,4));
	sp[3] = new Circle(Point(0,0), 7);

	for(int i=0;i<4;i++) sp[i]->rotate();

	// should use dynamic_cast but won't work until you coded correctly!
	Point* p0 = static_cast<Point*>(sp[0]);
	LineSegment* p1 = static_cast<LineSegment*>(sp[1]);
	Rectangle* p2 = static_cast<Rectangle*>(sp[2]);
	Circle* p3 = static_cast<Circle*>(sp[3]);

	if (p0->getX() != 1 || p0->getY() != 1)
		errorOut_("sp[0] rotate wrong",1);
	if (p1->getXmin() != 3 || p1->getXmax() != 3 || p1->getYmin() != 0 || p1->getYmax() != 6)
		errorOut_("sp[1] rotate wrong",1);
	if (p2->getXmin() != 2 || p2->getXmax() != 4 || p2->getYmin() != 0 || p2->getYmax() != 6)
		errorOut_("sp[2] rotate wrong",1);
	if (p3->getX() != 0 || p3->getY() != 0 || p3->getR() != 7)
		errorOut_("sp[3] rotate wrong",1);

	for(int i=0;i<4;i++) sp[i]->scale(5);

	if (p0->getX() != 1 || p0->getY() != 1)
		errorOut_("sp[0] scale wrong",2);
	if (p1->getXmin() != 3 || p1->getXmax() != 3 || p1->getYmin() != -12 || p1->getYmax() != 18)
		errorOut_("sp[1] scale wrong",2);
	if (p2->getXmin() != -2 || p2->getXmax() != 8 || p2->getYmin() != -12 || p2->getYmax() != 18)
		errorOut_("sp[2] scale wrong",2);
	if (p3->getX() != 0 || p3->getY() != 0 || p3->getR() != 35)
		errorOut_("sp[3] scale wrong",2);

	}

	passOut_();
}

// point, line ctor exception
void GeometryTester::testr() {
	funcname_ = "GeometryTester::testr";

	{
	// point
	try {
		Point p(-1,-2,-1);
		errorOut_("negative depth should throw exception", 1);
	}
	catch(const std::invalid_argument& e) {}

	// line
	Point p1(1,2);
	Point p2(5,2);
	Point p3(5,4,1);
	try {
		LineSegment l(p2,p3);
		errorOut_("two endpoints diff depth should throw exception",2);
	}
	catch(const std::invalid_argument& e) {}

	try {
		LineSegment l(p1,Point(1,2));
		errorOut_("two endpoints same should throw exception",2);
	}
	catch(const std::invalid_argument& e) {}

	p3.setDepth(0);
	try {
		LineSegment l(p1,p3);
		errorOut_("line not orthogonal should throw exception",2);
	}
	catch(const std::invalid_argument& e) {}

	}

	passOut_();
}

// rect, circle ctor exception
void GeometryTester::tests() {
	funcname_ = "GeometryTester::tests";

	{
	Point p(2,1);
	Point q(1,-2,2);

	// rect
	try {
		Rectangle r(p,q);
		errorOut_("two points diff depth should throw exception",1);
	}
	catch(const std::invalid_argument& e) {}

	try {
		Rectangle r(p,Point(2,6));
		errorOut_("two points same x-coord should throw exception",1);
	}
	catch(const std::invalid_argument& e) {}

	try {
		Rectangle r(p,Point(-2,1));
		errorOut_("two points same y-coord should throw exception",1);
	}
	catch(const std::invalid_argument& e) {}

	// circle
	try {
		Circle c(p,0);
		errorOut_("circle zero r should throw exception",2);
	}
	catch(const std::invalid_argument& e) {}

	try {
		Circle c(p,-1);
		errorOut_("circle -ve r should throw exception",2);
	}
	catch(const std::invalid_argument& e) {}

	}

	passOut_();
}

// scale exception
void GeometryTester::testt() {
	funcname_ = "GeometryTester::testt";

	{
	Point p(2,1);
	Point q1(6,1);
	Point q2(6,3);
	LineSegment l(p,q1);
	Rectangle r(p,q2);
	Circle c(p,4);

	try {
		p.scale(0);
		errorOut_("p scale zero f should throw exception",1);
	} catch(const std::invalid_argument& e) {}
	try {
		p.scale(-1);
		errorOut_("p scale -ve f should throw exception",2);
	} catch(const std::invalid_argument& e) {}

	try {
		l.scale(0);
		errorOut_("l scale zero f should throw exception",1);
	} catch(const std::invalid_argument& e) {}
	try {
		l.scale(-2);
		errorOut_("l scale -ve f should throw exception",2);
	} catch(const std::invalid_argument& e) {}

	try {
		r.scale(0);
		errorOut_("r scale zero f should throw exception",1);
	} catch(const std::invalid_argument& e) {}
	try {
		r.scale(-0.5);
		errorOut_("r scale -ve f should throw exception",2);
	} catch(const std::invalid_argument& e) {}

	try {
		c.scale(0);
		errorOut_("c scale zero f should throw exception",1);
	} catch(const std::invalid_argument& e) {}
	try {
		c.scale(-0.25);
		errorOut_("c scale -ve f should throw exception",2);
	} catch(const std::invalid_argument& e) {}

	}

	passOut_();
}

// scene draw blank, point
void GeometryTester::testu() {
	funcname_ = "GeometryTester::testu";

	{
	// blank
	Scene s;
	stringstream ss;
	ss << s;
	string page = blankpage_;
	if (ss.str() != page) {
		errorOut_("blank scene drawn wrongly",1);
		cout << "Expected output:\n" << page;
		cout << "Your output:\n" << ss.str();
	}

	// point
	auto p1 = make_shared<Point>(1,2);
	s.addObject(p1);
	stringstream ss2;
	ss2 << s;
	page[17*(Scene::WIDTH+1)+1] = '*';
	if (ss2.str() != page) {
		errorOut_("point drawn wrongly",2);
		cout << "Expected output:\n" << page;
		cout << "Your output:\n" << ss2.str();
	}

	}

	passOut_();
}

// scene draw line, shared w caller
void GeometryTester::testv() {
	funcname_ = "GeometryTester::testv";

	{
	// line
	Scene s;
	auto p = make_shared<LineSegment>(Point(1,4), Point(6,4));
	s.addObject(p);
	stringstream ss;
	ss << s;

	string page = blankpage_;
	for(int i=1;i<=6;i++) page[15*(Scene::WIDTH+1)+i] = '*';
	if (ss.str() != page) {
		errorOut_("line drawn wrongly",1);
		cout << "Expected output:\n" << page;
		cout << "Your output:\n" << ss.str();
	}

	// moved line
	p->translate(0,3);
	stringstream ss2;
	ss2 << s;

	for(int i=1;i<=6;i++) {
		page[15*(Scene::WIDTH+1)+i] = ' ';
		page[12*(Scene::WIDTH+1)+i] = '*';
	}
	if (ss2.str() != page) {
		errorOut_("line after translate drawn wrongly",2);
		cout << "Expected output:\n" << page;
		cout << "Your output:\n" << ss2.str();
	}

	}

	passOut_();
}

// scene draw rect, circle
void GeometryTester::testw() {
	funcname_ = "GeometryTester::testw";

	{
	// rect
	Scene s1;
	auto p1 = make_shared<Rectangle>(Point(0,15), Point(10,19));
	s1.addObject(p1);
	stringstream ss1;
	ss1 << s1;

	string page = blankpage_;
	for(int j=0;j<5;j++)
		for(int i=0;i<=10;i++)
			page[j*(Scene::WIDTH+1)+i] = '*';
	if (ss1.str() != page) {
		errorOut_("rect drawn wrongly",1);
		cout << "Expected output:\n" << page;
		cout << "Your output:\n" << ss1.str();
	}

	// circle
	Scene s2;
	auto p2 = make_shared<Circle>(Point(30,10), 9);
	s2.addObject(p2);
	stringstream ss2;
	ss2 << s2;

	string page2 = blankpage_;
	for(int i=30;i<=30;i++) page2[0*(Scene::WIDTH+1)+i] = '*';
	for(int i=26;i<=34;i++) page2[1*(Scene::WIDTH+1)+i] = '*';
	for(int i=25;i<=35;i++) page2[2*(Scene::WIDTH+1)+i] = '*';
	for(int i=24;i<=36;i++) page2[3*(Scene::WIDTH+1)+i] = '*';
	for(int i=23;i<=37;i++) page2[4*(Scene::WIDTH+1)+i] = '*';
	for(int i=22;i<=38;i++) page2[5*(Scene::WIDTH+1)+i] = '*';
	for(int i=22;i<=38;i++) page2[6*(Scene::WIDTH+1)+i] = '*';
	for(int i=22;i<=38;i++) page2[7*(Scene::WIDTH+1)+i] = '*';
	for(int i=22;i<=38;i++) page2[8*(Scene::WIDTH+1)+i] = '*';
	for(int i=21;i<=39;i++) page2[9*(Scene::WIDTH+1)+i] = '*';
	for(int i=22;i<=38;i++) page2[10*(Scene::WIDTH+1)+i] = '*';
	for(int i=22;i<=38;i++) page2[11*(Scene::WIDTH+1)+i] = '*';
	for(int i=22;i<=38;i++) page2[12*(Scene::WIDTH+1)+i] = '*';
	for(int i=22;i<=38;i++) page2[13*(Scene::WIDTH+1)+i] = '*';
	for(int i=23;i<=37;i++) page2[14*(Scene::WIDTH+1)+i] = '*';
	for(int i=24;i<=36;i++) page2[15*(Scene::WIDTH+1)+i] = '*';
	for(int i=25;i<=35;i++) page2[16*(Scene::WIDTH+1)+i] = '*';
	for(int i=26;i<=34;i++) page2[17*(Scene::WIDTH+1)+i] = '*';
	for(int i=30;i<=30;i++) page2[18*(Scene::WIDTH+1)+i] = '*';

	if (ss2.str() != page2) {
		errorOut_("circle drawn wrongly",2);
		cout << "Expected output:\n" << page2;
		cout << "Your output:\n" << ss2.str();
	}

	}

	passOut_();
}

// scene draw overlapping, out of view
void GeometryTester::testx() {
	funcname_ = "GeometryTester::testx";

	{
	auto p1 = make_shared<Point>(0,0);
	auto p2 = make_shared<Point>(0,2);
	auto p3 = make_shared<Point>(59,2);
	auto p4 = make_shared<Point>(28,0);
	auto p5 = make_shared<Point>(32,19);
	auto p6 = make_shared<Point>(30,0);

	auto l = make_shared<LineSegment>(*p2,*p3);
	auto r = make_shared<Rectangle>(*p4,*p5);
	auto c = make_shared<Circle>(*p6,10);

	Scene s;
	s.addObject(p1);
	s.addObject(l);
	s.addObject(r);
	s.addObject(c);

	string page = blankpage_;
	for(int j=0;j<=9;j++)
		for(int i=28;i<=32;i++)
			page[j*(Scene::WIDTH+1)+i] = '*';
	for(int i=26;i<=34;i++) page[10*(Scene::WIDTH+1)+i] = '*';
	for(int i=24;i<=36;i++) page[11*(Scene::WIDTH+1)+i] = '*';
	for(int i=23;i<=37;i++) page[12*(Scene::WIDTH+1)+i] = '*';
	for(int i=22;i<=38;i++) page[13*(Scene::WIDTH+1)+i] = '*';
	for(int i=22;i<=38;i++) page[14*(Scene::WIDTH+1)+i] = '*';
	for(int i=21;i<=39;i++) page[15*(Scene::WIDTH+1)+i] = '*';
	for(int i=21;i<=39;i++) page[16*(Scene::WIDTH+1)+i] = '*';
	for(int i=0;i<=59;i++) page[17*(Scene::WIDTH+1)+i] = '*';
	for(int i=21;i<=39;i++) page[18*(Scene::WIDTH+1)+i] = '*';
	for(int i=20;i<=40;i++) page[19*(Scene::WIDTH+1)+i] = '*';
	for(int i=0;i<=0;i++) page[19*(Scene::WIDTH+1)+i] = '*';

	stringstream ss;
	ss << s;
	if (ss.str() != page) {
		errorOut_("scene drawn wrongly",0);
		cout << "Expected output:\n" << page;
		cout << "Your output:\n" << ss.str();
	}

	}

	passOut_();
}

// drawdepth
void GeometryTester::testy() {
	funcname_ = "GeometryTester::testy";

	{
	auto p1 = make_shared<Point>(0,0,10);
	auto p2 = make_shared<Point>(0,19,20);
	auto p3 = make_shared<Point>(59,0,30);
	auto p4 = make_shared<Point>(59,19,40);

	Scene s;
	s.addObject(p1);
	s.addObject(p2);
	s.addObject(p3);
	s.addObject(p4);

	// def draw depth
	stringstream ss0;
	ss0 << s;
	string page = blankpage_;
	page[0*(Scene::WIDTH+1)+0] = '*';
	page[0*(Scene::WIDTH+1)+59] = '*';
	page[19*(Scene::WIDTH+1)+0] = '*';
	page[19*(Scene::WIDTH+1)+59] = '*';
	if (ss0.str() != page) {
		errorOut_("ss0 drawn wrongly",1);
		cout << "Expected output:\n" << page;
		cout << "Your output:\n" << ss0.str();
	}

	// successively reduce drawdepth
	s.setDrawDepth(35);
	stringstream ss1;
	ss1 << s;
	page[0*(Scene::WIDTH+1)+59] = ' ';
	if (ss1.str() != page) {
		errorOut_("ss1 drawn wrongly",1);
		cout << "Expected output:\n" << page;
		cout << "Your output:\n" << ss1.str();
	}

	s.setDrawDepth(21);
	stringstream ss2;
	ss2 << s;
	page[19*(Scene::WIDTH+1)+59] = ' ';
	if (ss2.str() != page) {
		errorOut_("ss2 drawn wrongly",1);
		cout << "Expected output:\n" << page;
		cout << "Your output:\n" << ss2.str();
	}

	s.setDrawDepth(10);
	stringstream ss3;
	ss3 << s;
	page[0*(Scene::WIDTH+1)+0] = ' ';
	if (ss3.str() != page) {
		errorOut_("ss3 drawn wrongly",2);
		cout << "Expected output:\n" << page;
		cout << "Your output:\n" << ss3.str();
	}

	s.setDrawDepth(5);
	stringstream ss4;
	ss4 << s;
	page[19*(Scene::WIDTH+1)+0] = ' ';
	if (ss4.str() != page) {
		errorOut_("ss4 drawn wrongly",2);
		cout << "Expected output:\n" << page;
		cout << "Your output:\n" << ss4.str();
	}

	// change depth of points
	p1->setDepth(1); p2->setDepth(2); p3->setDepth(3); p4->setDepth(4);
	stringstream ss5;
	ss5 << s;
	page[0*(Scene::WIDTH+1)+0] = '*';
	page[0*(Scene::WIDTH+1)+59] = '*';
	page[19*(Scene::WIDTH+1)+0] = '*';
	page[19*(Scene::WIDTH+1)+59] = '*';
	if (ss5.str() != page) {
		errorOut_("ss5 drawn wrongly",2);
		cout << "Expected output:\n" << page;
		cout << "Your output:\n" << ss5.str();
	}

	}

	passOut_();
}

// reserved for new test cases
void GeometryTester::testz() {
	funcname_ = "GeometryTester::testz";

}

void GeometryTester::errorOut_(const string& errMsg, unsigned int errBit) {

	cerr << funcname_ << ":" << " fail" << errBit << ": ";
	cerr << errMsg << endl;
	error_ |= (1<<errBit);
	cerr << std::flush;
}

void GeometryTester::errorOut_(const string& errMsg, const string& errResult, unsigned int errBit) {

	cerr << funcname_ << ":" << " fail" << errBit << ": ";
	cerr << errMsg << errResult << endl;
	error_ |= (1<<errBit);
	cerr << std::flush;
}

void GeometryTester::errorOut_(const string& errMsg, int errResult, unsigned int errBit) {

	cerr << funcname_ << ":" << " fail" << errBit << ": ";
	cerr << errMsg << std::to_string(errResult) << endl;
	error_ |= (1<<errBit);
	cerr << std::flush;
}

void GeometryTester::passOut_() {

	if (!error_) {
		cerr << funcname_ << ":" << " pass" << endl;
	}
	cerr << std::flush;
}