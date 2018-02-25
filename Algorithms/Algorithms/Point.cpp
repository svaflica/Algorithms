#include "stdafx.h"
#include "Point.h"
#include <math.h>

int Point::compare(const Point& point) const
{
	double p1 = sqrt(x_ * x_ + y_ * y_);
	double p2 = sqrt(point.x_ * point.x_ + point.y_ * point.y_);

	if (p1 == p2)
		return 0;
	if (p1 > p2)
		return 1;
	return -1;
	}


Point::Point(const Point& point)
{
	x_ = point.x_;
	y_ = point.y_;
}


Point::Point(double x, double y)
{
	x_ = x;
	y_ = y;
}


Point::~Point()
{
}


void Point::setX(const double x)
{
	x_ = x;
}


void Point::setY(const double y)
{
	y_ = y;
}


double Point::getX()
{
	return x_;
}


double Point::getY()
{
	return y_;
}


double Point::getDistance(const Point& p2)
{
	return(sqrt((x_ - p2.x_) * (x_ - p2.x_) + (y_ - p2.y_) * (y_ - p2.y_)));
}


bool operator==(const Point& p1, const Point& p2)
{
	return (p1.compare(p2) == 0);
}


bool operator>(const Point& p1, const Point& p2)
{
	return (p1.compare(p2) == 1);
}


bool operator>=(const Point& p1, const Point& p2)
{
	return (p1.compare(p2) != -1);
}


bool operator<(const Point& p1, const Point& p2)
{
	return (p1.compare(p2) == -1);
}


bool operator<=(const Point& p1, const Point& p2)
{
	return (p1.compare(p2) != 1);
}


void Point::operator +=(double value)
{
	this->x_ += value;
	this->y_ += value;
}


void Point::operator -=(double value)
{
	this->x_ -= value;
	this->y_ -= value;
}


void Point::operator +=(const Point& p2)
{
	this->x_ += p2.x_;
	this->y_ += p2.y_;
	}


void Point::operator -=(const Point& p2)
{
	this->x_ -= p2.x_;
	this->y_ -= p2.y_;
	}


Point Point::operator +(double value)
{
	return Point(this->x_ + value, this->y_ + value);
}


Point Point::operator -(double value)
{
	return Point(this->x_ - value, this->y_ - value);
}


Point Point::operator +(const Point& p2)
{
	return Point(this->x_ + p2.x_, this->y_ + p2.y_);
	}


Point Point::operator -(const Point& p2)
{
	return Point(this->x_ - p2.x_, this->y_ - p2.y_);
}


Point Point::operator /(double value)
{
	return Point(x_ / value, y_ / value);
}


Point Point::operator *(double value)
{
	return Point(x_ * value, y_ * value);
}
