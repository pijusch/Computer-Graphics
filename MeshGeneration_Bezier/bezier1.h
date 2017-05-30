#ifndef BEZIER_H
#define BEZIER_H
#include "primitive.h"
#include <vector>
using namespace std;
point interpolate(point a,point b,double t);
point bezier(vector<point> control,double t);
#endif 