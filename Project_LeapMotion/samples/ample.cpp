#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<stdio.h>
 
#define  RADDEG  57.29577951f
#include<unistd.h>

#include <iostream>
#include <cstring>
#include "camera.h"
#include "Leap.h"

float deltax = 0;
float deltaz = 0;
float Ix,Iy,Iz,Rx,Ry,Rz;
float doorAngle=0;

using namespace Leap;


class SampleListener : public Listener {
  public:
    /*virtual void onInit(const Controller&);
    virtual void onConnect(const Controller&);
    virtual void onDisconnect(const Controller&);
    virtual void onExit(const Controller&);*/
    virtual void onFrame(const Controller&);
    /*virtual void onFocusGained(const Controller&);
    virtual void onFocusLost(const Controller&);
    virtual void onDeviceChange(const Controller&);
    virtual void onServiceConnect(const Controller&);
    virtual void onServiceDisconnect(const Controller&);*/
};

const std::string fingerNames[] = {"Thumb", "Index", "Middle", "Ring", "Pinky"};
const std::string boneNames[] = {"Metacarpal", "Proximal", "Middle", "Distal"};
const std::string stateNames[] = {"STATE_INVALID", "STATE_START", "STATE_UPDATE", "STATE_END"};

 
float XUP[3] = {1,0,0}, XUN[3] = {-1, 0, 0},
      YUP[3] = {0,1,0}, YUN[3] = { 0,-1, 0},
      ZUP[3] = {0,0,1}, ZUN[3] = { 0, 0,-1},
      ORG[3] = {0,0,0};


Camera cam;

 
float X=0,Z=0,seesawangle=0,swingangle=0,handangle=0,facing=0,gateangle=0,gameangle=0;
int flag=0,seesawflag=0,swingflag=0,handflag=0;

void limbmovements()
{
	if(handangle>60)	handflag=1; if(handangle<-60)	handflag=0; if(handflag==0)	handangle+=1; else	handangle-=1;
}

void Keyboard(unsigned char key,int x,int y){
 switch(key)
	{

	case 'f':    cam.slide(0,0, 0.2); break; // slide camera forward
	case 'F': cam.slide(0,0,-0.2); break; //slide camera back	
	// add up/down and left/right controls	
	case 'p':      cam.pitch(-1.0); break;
	case 'P': cam.pitch( 1.0); break;
	// add yaw controls
	case 'y':      cam.yaw(-1.0); break;
	case 'Y': cam.yaw( 1.0); break;
	// add roll controls
	case 'r':      cam.roll(1.0); break;
	case 'R': cam.roll(-1.0); break;
	case 'w': facing = 0; X+=0.25; limbmovements(); break;
	case 's': facing = 180; X-=0.25; limbmovements(); break;
	case 'a': facing = 90; Z+=0.25; limbmovements(); break;
	case 'd': facing = 270; Z-=0.25; limbmovements(); break;
	default: return;
	}
 glutPostRedisplay();
}



void Special_Keys (int key, int x, int y)
{
    switch (key) {
 
       case GLUT_KEY_RIGHT :  cam.slide(.2, 0, 0); break;
       case GLUT_KEY_LEFT:  cam.slide(-0.2, 0, 0); break;
       case GLUT_KEY_UP   :  cam.slide(0, .2, 0); break;
       case GLUT_KEY_DOWN :  cam.slide(0, -0.2, 0); break;
 
    }
 
    glutPostRedisplay();
}

void floor()
{
	glColor3d(33.0/255,117.0/255,3.0/255);
	glPushMatrix();
	glScalef(20,0.01,20);
	glutSolidCube(1);
	glPopMatrix();
}


void character()
	
{
	glColor3d(255.0/255,0.0/255,0.0/255);
	
	glPushMatrix();
	glTranslatef(X,0,Z);
	glRotatef(facing,0,1,0);
	//face
	glPushMatrix();
		glTranslatef(0.0,2.30,0);
		glScalef(0.5,0.5,0.5);
		glutSolidCube(1);
	glPopMatrix();
	
	//neck
	glPushMatrix();
		glTranslatef(0.0,1.9,0);
		glScalef(0.1,0.3,0.1);
		glutSolidCube(1);
	glPopMatrix();
	
	//body
	glPushMatrix();
		glTranslatef(0.0,1.375,0);
		glScalef(0.75,0.75,0.75);
		glutSolidCube(1);
	glPopMatrix();
	
	//legs
	glPushMatrix();
		glTranslatef(0.0,0.5,-0.2);
		//glRotatef(handangle,0,0,1);
		glScalef(0.2,1,0.2);
		glutSolidCube(1);
	glPopMatrix();	
	
	glPushMatrix();
		glTranslatef(0.0,0.5,0.2);
		//glRotatef(-handangle,0,0,1);
		glScalef(0.2,1,0.2);
		glutSolidCube(1);
	glPopMatrix();	
	
	//hands
	glPushMatrix();
		glTranslatef(0.0,0.4 + 1.0 ,0.7);
		glRotatef(handangle,0,0,1);
		glScalef(0.2,0.8,0.2);
		glutSolidCube(1);
	glPopMatrix();	
	
	glPushMatrix();
		glTranslatef(0.0,0.4 + 1.0 ,-0.7);
		glRotatef(-handangle,0,0,1);
		glScalef(0.2,0.8,0.2);
		glutSolidCube(1);
	glPopMatrix();	
	
	glPopMatrix();
}

void seesaw()
{
	glColor3d(255.0/255,0.0/255,0.0/255);
    
	glPushMatrix();
		glTranslatef(0.0,0.5,0);
		glScalef(0.2,1,0.2);
		glutSolidCube(1);
	glPopMatrix();	
	
	glColor3d(0.0/255,0/255,255.0/255);
	glPushMatrix();
		glTranslatef(0.0,1.05,0);
		
		glRotatef(seesawangle,1,0,0);
		glScalef(0.2,0.1,4);
		
		glutSolidCube(1);
	glPopMatrix();
}

void swing()
{
	glColor3d(0.0/255,255.0/255,255.0/255);
	
	glPushMatrix();
		glTranslatef(0.0,2,0);
		glScalef(0.2,4,0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.0,2,4);
		glScalef(0.2,4,0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glColor3d(89.0/255,31.0/255,8.0/255);	
	glPushMatrix();
		glTranslatef(0.0,4.1,2);
		glScalef(0.2,0.2,4.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();				//swing base and side chains
	
	glTranslatef(0,0,1);		
	glTranslatef(0,4,0);
	glRotatef(swingangle,0,0,1);
	glTranslatef(0,-4,0);
	
	glPushMatrix();
		glTranslatef(0.0,1.4,0);	//swing base
		glScalef(1,0.2,1);
		glutSolidCube(1);
	glPopMatrix();
	
	glColor3d(50.0/255,50.0/255,50.0/255);	
	glPushMatrix();				//two chains on either side
		glTranslatef(0.0,2.75,0.4);
		glScalef(0.2,2.5,0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.0,2.75,-0.4);
		glScalef(0.2,2.5,0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glPopMatrix();
	
	
	glPushMatrix();
	glTranslatef(0,0,2);
	glPushMatrix();				//swing base and side chains
	glColor3d(89.0/255,31.0/255,8.0/255);
	glTranslatef(0,0,1);		
	glTranslatef(0,4,0);
	glRotatef(-swingangle,0,0,1);
	glTranslatef(0,-4,0);
	
	glPushMatrix();
		glTranslatef(0.0,1.4,0);	//swing base
		glScalef(1,0.2,1);
		glutSolidCube(1);
	glPopMatrix();
	
	glColor3d(50.0/255,50.0/255,50.0/255);	
	glPushMatrix();				//two chains on either side
		glTranslatef(0.0,2.75,0.4);
		glScalef(0.2,2.5,0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.0,2.75,-0.4);
		glScalef(0.2,2.5,0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glPopMatrix();
	glPopMatrix();
	
}

void wall()
{
	glColor3d(180.0/255,180.0/255,180.0/255);
	
	glPushMatrix();
		glTranslatef(-10,2,0);
		glScalef(0.01,4,20);
		glutSolidCube(1);
	glPopMatrix();	
}

void wallgate()
{
	glColor3d(180.0/255,180.0/255,180.0/255);
	
	glPushMatrix();
		glTranslatef(10,2,-2);
		glScalef(0.01,4,16);
		glutSolidCube(1);
	glPopMatrix();
	
	//gate
	glColor3d(80.0/255,80.0/255,80.0/255);
	glPushMatrix();
		glTranslatef(10,2,6);
		glRotatef(-gateangle,0,1,0);
		glTranslatef(-10,-2,-6);
		
		glTranslatef(10,2,7);

		glScalef(0.01,4,2.0);
		glutSolidCube(1);
	glPopMatrix();	
	
	glPushMatrix();
		glTranslatef(10,2,10);
		glRotatef(gateangle,0,1,0);
		glTranslatef(-10,-2,-10);
		
		glTranslatef(10,2,9);
		glScalef(0.01,4,2.0);
		glutSolidCube(1);
	glPopMatrix();
	

}

void entrance()
{
	glColor3d(210.0/255,135.0/255,90.0/255);
	
	glPushMatrix();
		glTranslatef(10.5,2.5,6.25);
		glScalef(1,5,0.5);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(10.5,2.5,9.75);
		glScalef(1,5,0.5);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(10.5,5.25,8);
		glScalef(1,0.5,4);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(10.5,5.25,8);
		glScalef(1,0.5,4);
		glutSolidCube(1);
	glPopMatrix();	
	
	
}


void game()
{
	glPushMatrix();
	glRotatef(gameangle,0,1,0);
	glColor3d(255.0/255,135.0/255,90.0/255);
	
	
	glPushMatrix();
	GLUquadric *quad;
	quad = gluNewQuadric();
	glTranslatef(0,0.1,0);
	glScalef(1,1,1);

	glRotatef(-90,1,0,0);
	gluDisk(quad,0,2,50,20);
	glPopMatrix();
	
	
	glColor3d(1,0,0);
	glPushMatrix();
		glTranslatef(0,1.1,1.95);
		glScalef(0.1,2,0.1);
		glutSolidCube(1);
	glPopMatrix();	

	
	glPushMatrix();
		glTranslatef(0,2.1,0.95);
		glScalef(0.1,0.1,1.9);
		glutSolidCube(1);
	glPopMatrix();
	
	glColor3d(0,0,1);
	
	glPushMatrix();
		glTranslatef(0,1.1,-1.95);
		glScalef(0.1,2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	
	glPushMatrix();
		glTranslatef(0,2.1,-0.95);
		glScalef(0.1,0.1,1.9);
		glutSolidCube(1);
	glPopMatrix();
	
	
	glColor3d(1,1,0);
	glPushMatrix();
		glTranslatef(1.95,1.1,0);

		glScalef(0.1,2,0.1);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.95,2.1,0);
		glRotatef(90,0,1,0);
		glScalef(0.1,0.1,1.9);
		glutSolidCube(1);
	glPopMatrix();	
	
	glColor3d(1,165.0/255.0,0);
	glPushMatrix();
		glTranslatef(-1.95,1.1,0);
		glScalef(0.1,2,0.1);
		glutSolidCube(1);
	glPopMatrix();
	

	
	glPushMatrix();
		glTranslatef(-0.95,2.1,0);
		glRotatef(90,0,1,0);
		glScalef(0.1,0.1,1.9);
		glutSolidCube(1);
	glPopMatrix();

	glColor3d(0,0,1);
	glPushMatrix();				//centre rod
		glTranslatef(0,1.1,0);
		glScalef(0.1,2,0.1);
		glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
}

void animategame()
{
	if(gameangle>360)	gameangle=0;
	gameangle+=4;
}

void tree()
{
	glColor3d(122.0/255,57.0/255,4.0/255);
	
	//trunk
	glPushMatrix();
		glTranslatef(0,2.5,0);
		glScalef(1,5,1);
		glutSolidCube(1);
	glPopMatrix();	

	//leaves
	glColor3d(11.0/255,177.0/255,19.0/255);
	glPushMatrix();
		glTranslatef(0,5,0);
		glScalef(3,3,3);
		glutSolidCube(1);
	glPopMatrix();	
}

void bench()
{
	
}

void redraw (void)
{
    glClear  (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable (GL_DEPTH_TEST);
 	
 	if(X>8.5 && X< 11.5 && Z>6 && Z<10)
 		gateangle=70;
 	else	gateangle=0;  
 	
    glDisable (GL_LIGHTING);
 	glPushMatrix();
 	floor();
 	glPopMatrix();
 	
 	glPushMatrix();
	character();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0,0,-4);
	seesaw();
	glPopMatrix();
	
	glPushMatrix();
	entrance();
	glPopMatrix();
	
	glPushMatrix();
	wall();
	glPopMatrix();
	
 	glPushMatrix();
	glTranslatef(0,0,4);
	swing();
	glPopMatrix();	
		
	glPushMatrix();
	glRotatef(90,0,1,0);
	wall();
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(-90,0,1,0);
	wall();
	glPopMatrix();	
	
	glPushMatrix();
	wallgate();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-8.5,0,4);	
	glScalef(0.8,0.8,0.8);
	tree();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-8.5,0,-6);	
	glScalef(0.8,0.8,0.8);
	tree();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-5,0,8.5);	
	glScalef(0.8,0.8,0.8);
	tree();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(2,0,-8.5);	
	glScalef(0.8,0.8,0.8);
	tree();
	glPopMatrix();
	
	glPushMatrix();
	game();
	glPopMatrix();
	
    glutSwapBuffers();
}
 
 
void animateseesaw()
{
	if(seesawangle==30)	seesawflag=1;
	if(seesawangle==-30)	seesawflag=0;
	
	if(seesawflag==0)	seesawangle+=0.5;
	else	seesawangle-=0.5 ;

}

void animateswing()
{
	if(swingangle==30)	swingflag=1;
	if(swingangle==-30)	swingflag=0;
	
	if(swingflag==0)	swingangle+=0.5;
	else	swingangle-=0.5 ;
}

void SampleListener::onFrame(const Controller& controller) {
  const Frame frame = controller.frame();
  if(frame.fingers().extended().count()==1){ facing = 0; X+=0.025; limbmovements();}
  else if(frame.fingers().extended().count()==2){ facing = 180; X-=0.025; limbmovements(); }
  else if(frame.fingers().extended().count()==3){ facing = 90; Z+=0.025; limbmovements(); }
  else if(frame.fingers().extended().count()==4){ facing = 270; Z-=0.025; limbmovements(); }
}

void idle(){
	animateseesaw();
	animateswing();
	animategame();
	glutPostRedisplay();

}

 
int main (int argc, char **argv)
{
    glutInit               (&argc, argv);
    glutInitWindowSize     (900, 600);
    glutInitWindowPosition (300, 300);
    glutInitDisplayMode    (GLUT_DEPTH | GLUT_DOUBLE);
 
    glutCreateWindow ("Mesh Draw");
    glutDisplayFunc  (   redraw   );
    glutIdleFunc(idle);
    glutKeyboardFunc (  Keyboard  );
    glutSpecialFunc  (Special_Keys);
    glClearColor (1, 1, 1, 1.0);
	cam.set(Point3(20,2,8.5),Point3(10,2,8.5),Vector3(0,1,0));
	cam.setShape(45,640.0/480.0,1.0, 50.0);

    SampleListener listener;
    Controller controller;
    controller.addListener(listener);
    glutMainLoop   ();
 
    return 1;
}
 
