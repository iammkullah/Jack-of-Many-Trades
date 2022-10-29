#ifndef GEOMETRY_H_
#define GEOMETRY_H_

#include <iostream>
#include <memory>
#include <math.h>
#include <vector>
using namespace std;

class Point;

class Shape {
	
protected:
	int depth;
	int dimension;
	float x;
	float y;

public:
	Shape(int d);
	Shape();
	bool setDepth(int d);
	virtual int getDepth() const=0;
	virtual int dim() const=0;
	virtual void translate(float x, float y)=0;
	virtual void rotate()=0;
	virtual void scale(float f)=0;
	virtual bool contains(const Point& p) const=0;
};

class Point : public Shape {
	friend class LineSegment;
	friend class Rectangle;
	friend class Circle;
	
public:
	Point(float x, float y, int d=0);
	Point();
	bool setDepth(int d);
	int getDepth() const;
	int dim() const;
	void translate(float x, float y);
	void rotate(); 
	void scale(float f);
	bool contains(const Point& p) const;
	void operator =(Point p1){
		this->x=p1.x;
		this->y=p1.y;
	}
	float getX() const;
	float getY() const;
};

class LineSegment : public Shape {

public:
	LineSegment(const Point& p, const Point& q);
	float getXmin() const;
	float getXmax() const;
	float getYmin() const;
	float getYmax() const;
	bool setDepth(int d);
	int getDepth() const;
	int dim() const;
	void translate(float x, float y);
	void rotate(); 
	void scale(float f);
	bool contains(const Point& p) const;
	float length() const;

protected:
	Point p1;
	Point p2;
};

class TwoDShape : public Shape {

public:
	TwoDShape();
	TwoDShape(int d);
	virtual float area() const=0;

protected:
	
private:

};

class Rectangle : public TwoDShape {

public:
	Rectangle(const Point& p, const Point& q);
	float getXmin() const;
	float getYmin() const;
	float getXmax() const;
	float getYmax() const;
	bool setDepth(int d);
	int getDepth() const;
	int dim() const; 
	float area() const;
	void translate(float x, float y);
	void rotate();
	void scale(float f);
	bool contains(const Point& p) const;
private:
	Point p1,p2,p3,p4;
};

class Circle : public TwoDShape {

public:
	Circle(const Point& c, float r);
	float getX() const;
	float getY() const;
	float getR() const;
	float area() const;
	bool setDepth(int d);
	void rotate();
	int getDepth() const;
	int dim() const;
	void scale(float f);
	bool contains(const Point& p) const;
	void translate(float x, float y);

private:
	Point p1;
	float radius;
};


class Scene {
	
public:
	
	Scene();
	void addObject(shared_ptr<Shape> ptr);
	void setDrawDepth(int d);
	static constexpr int WIDTH = 60;
	static constexpr int HEIGHT = 20;
private:
	std::vector<std::shared_ptr<Shape>> p;
	int d;
	friend std::ostream& operator<<(std::ostream& out, const Scene& s);
	
};

#endif /* GEOMETRY_H_ */