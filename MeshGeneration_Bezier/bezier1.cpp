#include "bezier1.h"

point interpolate(point a,point b,double t)
{
	return point(a.x+t*(b.x-a.x),a.y+t*(b.y-a.y));
}
point bezier(vector<point> control,double t)
{
	if(control.size()==1)
		return control[0];
	vector<point> n_control;
	for(int i=0;i<control.size()-1;i++)
	{
		point temp=interpolate(control[i],control[i+1],t);
		n_control.push_back(temp);
	}
	return bezier(n_control,t);
}