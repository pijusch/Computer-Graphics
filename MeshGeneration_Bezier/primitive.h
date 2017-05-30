#ifndef PRIMITIVE_H
#define PRIMITIVE_H
#include <cmath>
#define EPSILON 20

struct point{
	double x,y;
	point(double xx,double yy): x(xx), y(yy)
	{

	}
	point()
	{
		x=0;
		y=0;
	}
    bool operator==(const point &other)const
    {
        return (std::abs(x-other.x)<EPSILON && std::abs(y-other.y)<EPSILON);
    }
};
#endif
