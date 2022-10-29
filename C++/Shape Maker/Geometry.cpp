#include <iostream>
#include "Geometry.h"
using namespace std;


// =============== Shape class ================

Shape::Shape(int d) {
	try{
		if(d<0)
			throw std::invalid_argument("Invalid argument.");
		depth=d;
	}
	catch(const std::invalid_argument& e ) {
    	cout<<"invalid argument exception occured."<<endl;
	}
}

Shape::Shape(){
	
}

bool Shape::setDepth(int d) {
	if(d<0){
		return false;
	}
	else{
		depth=d;
		return true;
	}
}

// =============== Point class ================

Point::Point(float x, float y, int d):Shape(d){
		this->x=x;
		this->y=y;
}

Point::Point(){
}


float Point::getX() const {
	return x;
}

float Point::getY() const {
	return y;
}

bool Point::setDepth(int d){
	return Shape::setDepth(d);
}

int Point::getDepth() const {
	return depth;
}

int Point::dim() const {
	return dimension;
}

void Point::translate(float x, float y) {
	this->x+=x;
	this->y+=y;
}

void Point::rotate() {
	cout<<"No effect"<<endl;
}

void Point::scale(float f){
	cout<<"No effect"<<endl;
}

bool Point::contains(const Point& p) const{
	return (p.x==x && p.y==y)? true : false;
}



// =========== LineSegment class ==============

LineSegment::LineSegment(const Point& p, const Point& q) {
	try{
		if((p.x==q.x && p.y==q.y) || p.depth!=q.depth || (p.x!=q.x && p.y!=q.y)){
			throw std::invalid_argument("Invalid argument.");
		}	
		p1=p;
		p2=q;
		dimension=1;
	}
	catch(const std::invalid_argument& e ) {
    	cout<<"invalid argument exception occured."<<endl;
	}	
}

bool LineSegment::setDepth(int d){
	return Shape::setDepth(d);
}

int LineSegment::getDepth() const{
	return depth;
}

int LineSegment::dim() const {
	return dimension;
}

void LineSegment::translate(float x, float y) {
	p1.translate(x,y);
	p2.translate(x,y);
}

void LineSegment::rotate() {
	//center point 
	Point p3;
	p3.x=(p1.x+p2.x)/2;
	p3.y=(p1.y+p2.y)/2;
	
	
	//move back to origin
	p1.translate(-p3.x,-p3.y);
	
	//rotate
	Point temp;
	temp.x=p1.x; temp.y=p1.y;
	p1.x=-temp.y; p2.y=temp.x;
	
	temp.x=p2.x; temp.y=p2.y;
	p2.x=-temp.y; p2.y=temp.x;
	
	//move to original position
	p1.x+=p3.x; p1.y+=p3.y;
	p2.x+=p3.x; p2.y+=p3.y;	
}

void LineSegment::scale(float f){
	try{
		if(f<=0)
			throw std::invalid_argument("Invalid argument.");
		float lenght;
		lenght=this->length();
		Point p3(0,0);
		float lenght2=lenght*f;
		lenght-=lenght2;
		lenght=lenght/2;
		if(p1.y==p2.y){
			p1.x=this->getXmin();
			p1.x-=lenght;
			p2.x=this->getXmax();
			p2.x+=lenght;
		}
		else if(p1.x==p2.x){
			p1.y=getXmin();
			p1.y-=lenght;
			p2.y=getXmax();
			p2.y+=lenght;
		}
	}
	catch(const std::invalid_argument& e ) {
    	cout<<"invalid argument exception occured."<<endl;
	}
}

bool LineSegment::contains(const Point& p) const {
	float lenght=length();
	float lenght1=sqrt(pow((p2.x-p.x),2)+pow((p2.y-p.y),2));
	float lenght2=sqrt(pow((p.x-p1.x),2)+pow((p.y-p1.y),2));
	if (lenght==lenght1+lenght2){
		return true;
	}
	else{
		return false;
	}
}


float LineSegment::getXmin() const {
	if(p1.x<=p2.x)
		return p1.x;
	else
		return p2.x;
}

float LineSegment::getXmax() const {
	if(p1.x>=p2.x)
		return p1.x;
	else
		return p2.x;
}

float LineSegment::getYmin() const {
	if(p1.y<=p2.y)
		return p1.y;
	else
		return p2.y;
}

float LineSegment::getYmax() const {
	if(p1.y>=p2.y)
		return p1.y;
	else
		return p2.y;
}

float LineSegment::length() const {
	return (sqrt(pow((p2.x-p1.x),2))+pow((p2.y-p1.y),2));
}

// ============ TwoDShape class ================

TwoDShape::TwoDShape(int d): Shape(d) {
	dimension=2;
}

TwoDShape::TwoDShape(){
	
}

// ============== Rectangle class ================

Rectangle::Rectangle(const Point& p, const Point& q) {
	try{
		if((p.x==q.x && p.y==q.y) || (p.x==q.x && p.y!=q.y) || (p.y==q.y && p.x!=q.x) || p.depth!=q.depth){
			throw std::invalid_argument("Invalid argument.");
		}	
		p1=p;
		p2=q;
		p3.x=p2.x; p3.y=p1.y;
		p4.x=p1.x; p4.y=p2.y;
		dimension=2;
	}
	catch(const std::invalid_argument& e ) {
    	cout<<"invalid argument exception occured."<<endl;	
	}
}

float Rectangle::area() const{
	float lenght=sqrt(pow((p2.x-p3.x),2)+pow((p2.y-p3.y),2));
	float width=sqrt(pow((p2.x-p4.x),2)+pow((p2.y-p4.y),2));
	return (lenght*width);
}
	

float Rectangle::getXmin() const {
	if(p1.x<=p2.x)
		return p1.x;
	else
		return p2.x;
}

float Rectangle::getYmin() const {
	if(p1.y<=p2.y)
		return p1.y;
	else
		return p2.y;
}

float Rectangle::getXmax() const {
	if(p1.x>=p2.x)
		return p1.x;
	else
		return p2.x;
}

float Rectangle::getYmax() const {
	if(p1.y>=p2.y)
		return p1.y;
	else
		return p2.y;
}

bool Rectangle::setDepth(int d){
	return Shape::setDepth(d);
}

int Rectangle::getDepth() const{
	return depth;
}

int Rectangle::dim() const {
	return dimension;
}

void Rectangle::translate(float x, float y) {
	p1.translate(x,y);
	p2.translate(x,y);
	p3.translate(x,y);
	p4.translate(x,y);
}

void Rectangle::rotate() {
	float centrex, centrex2, centrey, centrey2;
	if (p2.x != p1.x && p3.y != p1.y){
	centrex = fabs(p2.x + p1.x) / 2;
	centrex2 = fabs(p2.x - p1.x) / 2;
	centrey = fabs(p3.y + p1.y) / 2;
	centrey2 = fabs(p3.y - p1.y) / 2;
	}
	else if (p3.x != p1.x && p2.y != p1.y){
	centrex = fabs(p3.x + p1.x) / 2;
	centrex2 = fabs(p3.x - p1.x) / 2;
	centrey = fabs(p2.y + p1.y) / 2;
	centrey2 = fabs(p2.y - p1.y) / 2;
	}
	else if (p4.x != p1.x && p3.y != p1.y){
	centrex = fabs(p4.x + p1.x) / 2;
	centrex2 = fabs(p4.x - p1.x) / 2;
	centrey = fabs(p3.y + p1.y) / 2;
	centrey2 = fabs(p3.y - p1.y) / 2;
	}
	else if (p4.x != p1.x && p4.y != p1.y){
	centrex = fabs(p4.x + p1.x) / 2;
	centrex2 = fabs(p4.x - p1.x) / 2;
	centrey = fabs(p4.y + p1.y) / 2;
	centrey2 = fabs(p4.y - p1.y) / 2;
	}
	else if (p1.x != p2.x && p2.y != p1.y){
	centrex = fabs(p2.x + p1.x) / 2;
	centrex2 = fabs(p2.x - p1.x) / 2;
	centrey = fabs(p2.y + p1.y) / 2;
	centrey2 = fabs(p2.y - p1.y) / 2;
	}
	else{
	centrex = fabs(p2.x + p3.x) / 2;
	centrex2 = fabs(p2.x - p3.x) / 2;
	centrey = fabs(p2.y + p3.y) / 2;
	centrey2 = fabs(p2.y - p3.y) / 2;
	}
	p1.x = centrex - centrey2;
	p1.y = centrey - centrex2;
	p2.x = centrex + centrey2;
	p2.y = centrey + centrex2;
	p3.x = centrex - centrey2;
	p3.y = centrey + centrex2;
	p4.x = centrex + centrey2;
	p4.y = centrey - centrex2;
}

void Rectangle::scale(float f){
		LineSegment l1(p1,p3);
		LineSegment l2(p1,p4);
		LineSegment l3(p2,p3);
		LineSegment l4(p2,p4);
		l1.scale(f);
		l2.scale(f);
		l3.scale(f);
		l4.scale(f);
}

bool Rectangle::contains(const Point& p) const {
	bool statement = false;
	if (p1.x > p2.x && p1.y < p2.y){
		statement = true;
		if (p.x <= p1.x && p.x >= p2.x && p.y >= p1.y && p.y <= p2.y){
			return true;
		}
	}
	else if (p1.x < p2.x && p1.y < p2.y){
		statement = true;
		if (p.x >= p1.x && p.x <= p2.x && p.y >= p1.y && p.y <= p2.y){
			return true;
		}
	}
	else if (p1.x > p2.x && p1.y > p2.y){
		statement = true;
		if (p.x <= p1.x && p.x >= p2.x && p.y <= p1.y && p.y >= p2.y){
			return true;
		}	
	}
	else if (p1.x < p2.x && p1.y>p2.y){
		statement = true;
		if (p.x >= p1.x && p.x <= p2.x && p.y <= p1.y && p.y >= p2.y){
			return true;
		}
	}
	if (statement == true)
		return false;
}


// ================== Circle class ===================

Circle::Circle(const Point& c, float r) {
	try{
		if(r<=0){
			throw std::invalid_argument("Invalid argument.");
		}	
		p1=c;
		radius=r;
		dimension=2;
	}
	catch(const std::invalid_argument& e ) {
    	cout<<"invalid argument exception occured."<<endl;
	}
}

float Circle::area() const{
	return(radius*radius*3.1415926);
}

float Circle::getX() const {
	return p1.x;
}

float Circle::getY() const {
	return p1.y;
}

float Circle::getR() const {
	return radius;
}

bool Circle::setDepth(int d){
	return Shape::setDepth(d);
}

int Circle::getDepth() const{
	return depth;
}

int Circle::dim() const {
	return dimension;
}

void Circle::scale(float f){
	try{
		if(f<=0)
			throw std::invalid_argument("Invalid argument.");
		radius=radius*f;
	}
	catch(const std::invalid_argument& e ) {
    	cout<<"invalid argument exception occured."<<endl;
	}
}

bool Circle::contains(const Point& p) const {
	return (sqrt(pow(p.x - p1.x, 2) + pow(p.y - p1.y, 2)) <= radius)? true : false;
}


void Circle::translate(float x, float y) {
	p1.translate(x,y);
}

void Circle::rotate() {
	//No effect
}

// ================= Scene class ===================

Scene::Scene() {
}

void Scene::addObject(shared_ptr<Shape> ptr) {
	p.push_back(ptr);
 }

void Scene::setDrawDepth(int depth) {
	if (depth < 0){
		throw std::invalid_argument("Depth can not be negative");
	}
	else{
		d=depth;
	}
}

std::ostream& operator<<(std::ostream& out, const Scene& s) {
	for (int i = 0; i < s.HEIGHT; i++){
		for (int j = 0; j < s.WIDTH; j++){
			bool statement = false;
			Point P(j, ((s.HEIGHT-1) - i));
			for (int k = 0; k < s.p.size(); k++){
				if ((*s.p[k]).contains(P)){
					statement = true;
					cout << "*";
					break;
				}
			}
			if (statement == false){
				cout << " ";
			}
		}
		out << std::endl;
	}
	return out;
}
