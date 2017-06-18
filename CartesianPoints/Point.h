#pragma once
#ifndef __POINT__
#define __POINT__
#include <iostream>
#include <math.h>
using namespace std;

class Point
{
public:
	//0-arg constructor
	Point() {
		//TO DO: Implement and set constructed object to (0.0,0.0)
		this->x = 0.0;
		this->y = 0.0;
	}
	//2-arg constructor
	Point(double x, double y) {
		//TO DO: Implement and set constructed object to ((x,y)
		this->x = x;
		this->y = y;
	}

	//1-arg constructor
	Point(double x) {
		//TO DO: Implement and set constructed object to ((x,0.0)
		this->x = x;
		this->y = 0.0;
	}

	//copy constructor
	Point(const Point & p) {
		//TO DO: Implement
		this->x = p.getX();
		this->y = p.getY();
	}

	//assignment overload
	const Point & operator=(const Point  & rhs) {
		//TO DO: Implement assignment right-hand side point to this point
		//             and return right-hand side object
		if (*this != rhs) {
			this->x = rhs.getX();
			this->y = rhs.getY();
		}
		return *this;
	}

	bool operator==(const Point p) const {
		//TO DO: Implement by returning true if values of p are both equal to this object, false otherwise
		if ((this->x == p.x) && (this->y == p.y)) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator!=(const Point p) const {
		//TO DO: Implementd
		if ((this->x != p.getX()) || (this->x != p.getY())) {
			return true;
		}
		else {
			return false;
		}
	}

	double distance(const Point p) {
		//TO DO: Implement using Euclidean distance
		return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
	}

	double getX()const {
		//TO DO: Implement by returning x
		return x;
	}

	double getY()const {
		//TO DO: Implement by returning y
		return y;
	}

	void setX(double x) {
		//TO DO: Implement by updating x
		this->x = x;
		return;
	}

	void setY(double y) {
		//TO DO: Implement by updating y
		this->y = y;
		return;
	}
private:
	double x;
	double y;
};  //NOTE semicolon after closing brace

	//overload >>
istream & operator >> (istream & in, Point & p) {
	double x;
	double y;
	char separator;
	in >> separator; //read past '('
	in >> x;
	in >> separator;  //read past ','
	in >> y;
	in >> separator;  //read past ')'
	p.setX(x);
	p.setY(y);
	return in;
}

//overload <<
ostream & operator<<(ostream & out, const Point p) {
	out << '(' << p.getX() << ',' << p.getY() << ')';
	return out;
}
#endif