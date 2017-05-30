#include<bits/stdc++.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<string>

using namespace std;


class Plot{
	
	public:	static void init() {  
	  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	  glutInitWindowPosition(0,0);
	  glutInitWindowSize(1300, 700);
	  glutCreateWindow("My Line");
	  glClearColor(1.0,1.0,1.0,1.0f);
	  glColor3f(1.0,1.0,1.0);
	  gluOrtho2D(xmin-1000,xmax+1000,ymin-1000,ymax+1000);
	  
	}
	static void setPixel(GLint x,GLint y)
	{
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
	}

	static void plotpixel()
	{
		glClearColor(1.0f,1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);  
		glColor3f(1.0f, 0.0f, 0.0f);
		FILE* fp=fopen("pixels.txt","r");
		if(fp==NULL)
		{
			cout << "Invalid file" << endl;
			return;
		}
		char c,nextc=getc(fp);
		string s;
		int flag=0,x,y;
		while(nextc!=EOF)
		{
			c=nextc;
			if(c==' ' || c=='\0' || c=='\n')
			{
				if(s.length()!=0)
				{
					if(flag==0)
					{
						x=atoi(s.c_str());
						flag=1;
					}
					else
					{
						y=atoi(s.c_str());
						flag=0;
						setPixel(x,ymax-y);
					}
					s="";
				}
				nextc=fgetc(fp);
				continue;
			}
			s.append(1,c);
			nextc=fgetc(fp);
		}
		glFlush();
	}
};
