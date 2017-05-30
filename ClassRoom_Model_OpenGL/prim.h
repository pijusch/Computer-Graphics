#include<bits/stdc++.h>
#include<GL/glu.h>
#include<GL/glut.h>
using namespace std;

class Point3 
{
	public: 
		
		float x,y,z;
		Point3()
		{
			x=0; y=0; z=0;
		}
		Point3(float dx, float dy, float dz)
		{
			x=dx; y=dy; z=dz;
		}
		void set(float dx, float dy, float dz)
		{
			x=dx;
			y=dy;
			z=dz;
		}
		void set(Point3 p)
		{
			x=p.x;
			y=p.y;
			z=p.z;
		}
};

class Vector3
{
	public:
		float x,y,z;
		Vector3()
		{
			x=0; y=0; z=0;
		}
		Vector3(float dx, float dy, float dz)
		{
			x=dx; y=dy; z=dz;
		}
		void set(float dx, float dy, float dz)
		{
			x=dx;
			y=dy;
			z=dz;
		}
		void set(Vector3 v)
		{
			x=v.x;
			y=v.y;
			z=v.z;
		}
		void normalize()
		{
			x=(float(x))/sqrt(x*x + y*y + z*z);
			y=(float(y))/sqrt(x*x + y*y + z*z);
			z=(float(z))/sqrt(x*x + y*y + z*z);
		}
		float dot(Vector3 b)
		{
			float result;
			result= x * b.x + y * b.y + z * b.z;
			return result;
		}
		Vector3 cross(Vector3 b)
		{
			Vector3 result;
			result.x= y* b.z - z * b.y;
			result.y= z * b.x - x * b.z;
			result.z= x * b.y - y * b.x;
			return result;
			
		}
};
