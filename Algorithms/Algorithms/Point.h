#pragma once
 
 class Point
{
	private:
		double x_;
		double y_;
		int compare(const Point& point) const;
		
	public:
		Point() : x_(0), y_(0) {}
		Point(const Point& point);
		Point(double x, double y);
		~Point();
		void setX(double x);
		void setY(double y);
		double getX();
		double getY();
		double getDistance(const Point& b);
		friend bool operator == (const Point& p1, const Point& p2);
		friend bool operator > (const Point& p1, const Point& p2);
		friend bool operator < (const Point& p1, const Point& p2);
		friend bool operator >= (const Point& p1, const Point& p2);
		friend bool operator <= (const Point& p1, const Point& p2);
		void operator += (double value);
		void operator -= (double value);
		void operator += (const Point &p2);
		void operator -= (const Point &p2);
		Point operator + (double value);
		Point operator - (double value);
		Point operator + (const Point &p2);
		Point operator - (const Point &p2);
		Point operator / (double value);
		Point operator * (double value);
};