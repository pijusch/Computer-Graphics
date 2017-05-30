#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<stdio.h>
 
#define  RADDEG  57.29577951f
#include<unistd.h>
float bl=.1;
float wck = 0;
#include <iostream>
#include <cstring>
#include "camera.h"
#include "scene.h"
float deltax = 0;
float deltaz = 0;
float Ix,Iy,Iz,Rx,Ry,Rz;
float doorAngle=0;

Camera cam;
 
 
int d[4]={100,100,100,100};
 

 
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
	case '!': d[0]-=100; break;
	case '1': d[0]+=100; break;
	case '@': d[1]-=100; break;
	case '2': d[1]+=100; break;
	case '#': d[2]-=100; break;
	case '3': d[2]+=100; break;
	case '$': d[3]-=100; break;
	case '4': d[3]+=100; break;
	case 'b': bl+=0.1; break;
	case 'B': if(bl>0.1) bl-=0.1; break;
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


void redraw (void)
{
 
    glClear  (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable (GL_DEPTH_TEST);
 
 
    glDisable (GL_LIGHTING);
 

	glPushMatrix();
	wclock();
	glPopMatrix(); 
	
	glPushMatrix();
	wclockLine();
	glPopMatrix(); 
	
	glPushMatrix();
	glScalef(0.1,0.1,0.1);
	glTranslatef(-5,0,-2);
	chair();
	glPopMatrix();


	glPushMatrix();
	glScalef(0.1,0.1,0.1);
	glTranslatef(-5,0,-2);
	chairLine();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.1,0.1,0.1);
	glTranslatef(15,0,-2);
	chair();
	glPopMatrix();


	glPushMatrix();
	glScalef(0.1,0.1,0.1);
	glTranslatef(15,0,-2);
	chairLine();
	glPopMatrix();


	glPushMatrix();
			glScalef(0.1,0.1,0.1);
	glTranslatef(35,0,-2);
	chairLine();
	glPopMatrix();


	glPushMatrix();
			glScalef(0.1,0.1,0.1);
	glTranslatef(35,0,-2);
	chair();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0,0,3);
	glScalef(0.1,0.1,0.1);
	glTranslatef(-5,0,-2);
	chair();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0,0,3);
	glScalef(0.1,0.1,0.1);
	glTranslatef(-5,0,-2);
	chairLine();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,3);
	glScalef(0.1,0.1,0.1);
	glTranslatef(15,0,-2);
	chair();
	glPopMatrix();



	glPushMatrix();
	glTranslatef(0,0,3);
	glScalef(0.1,0.1,0.1);

	glTranslatef(15,0,-2);

	chairLine();

	glPopMatrix();





	glPushMatrix();
	glTranslatef(0,0,3);
			glScalef(0.1,0.1,0.1);

	glTranslatef(35,0,-2);


	chairLine();

	glPopMatrix();


	glPushMatrix();
	glTranslatef(0,0,3);
			glScalef(0.1,0.1,0.1);
	glTranslatef(35,0,-2);
	chair();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0,0,-3);
	glScalef(0.1,0.1,0.1);
	glTranslatef(-5,0,-2);
	chair();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0,0,-3);
	glScalef(0.1,0.1,0.1);
	glTranslatef(-5,0,-2);
	chairLine();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,-3);
	glScalef(0.1,0.1,0.1);

	glTranslatef(15,0,-2);

	chair();

	glPopMatrix();




	glPushMatrix();
	glTranslatef(0,0,-3);
	glScalef(0.1,0.1,0.1);
	glTranslatef(15,0,-2);

	chairLine();
	glPopMatrix();



	glPushMatrix();
	glTranslatef(0,0,-3);
			glScalef(0.1,0.1,0.1);

	glTranslatef(35,0,-2);
	chairLine();

	glPopMatrix();


	glPushMatrix();
	glTranslatef(0,0,-3);

			glScalef(0.1,0.1,0.1);
	glTranslatef(35,0,-2);


	chair();

	glPopMatrix();


	ceiling();	

		//Floor
	glPushMatrix();
	glColor3d(1.0,0.5,0);
	glTranslatef(0,0.005,0);
	floor();
	glPopMatrix();


	glPushMatrix();
	glColor3d(1.0,0.5,0);
	glTranslatef(0,0.005,0);
	floorLine();
	glPopMatrix();

	glPushMatrix();
	glColor3d(255.0/255,178.0/255,102.0/255);
	glTranslatef(-5,0,0);
	Trump();
	glPopMatrix();



	glPushMatrix();
	glColor3d(255.0/255,178.0/255,102.0/255);
	glTranslatef(5,0,0);
	Trump();
	//aircond();
	glPopMatrix();


	
	glPushMatrix();
	glColor3d(184.0/255,219.0/255,214.0/255);
	glTranslatef(0,0,-5);
	glRotatef(-90,0,1,0);
	
	Trump();
	aircond();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0,0,5);
	glRotatef(90,0,1,0);
	wallDoor();
	aircond();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-4.98,2.1,0);
	board();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.97,2.1,0);
	boardLine();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,4.5,0);
	projector();
	glPopMatrix();

		glPushMatrix();
	glTranslatef(0,4.5,0);
	projectorLine();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2,0,5);
	glRotatef(270,0,1,0);
	door();//table();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2,0,5);
	glRotatef(270,0,1,0);
	doorLine();//table();
	glPopMatrix();	

	glPushMatrix();
	glTranslatef(-3,4.5,3);
	glRotatef(doorAngle*d[0],0,1,0);
	fan();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3,4.5,3);
	glRotatef(doorAngle*d[0],0,1,0);
	fanLine();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3,4.5,3);
	glRotatef(doorAngle*d[1],0,1,0);
	fan();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3,4.5,3);
	glRotatef(doorAngle*d[1],0,1,0);
	fanLine();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3,4.5,-3);
	glRotatef(doorAngle*d[2],0,1,0);
	fan();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3,4.5,-3);
	glRotatef(doorAngle*d[2],0,1,0);
	fanLine();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3,4.5,-3);
	glRotatef(doorAngle*d[3],0,1,0);
	fan();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3,4.5,-3);
	glRotatef(doorAngle*d[3],0,1,0);
	fanLine();
	glPopMatrix();
 	
 	glPushMatrix();
 	glTranslatef(-3,0.3,0);
 	table();
 	glPopMatrix();

 	glPushMatrix();
 	glTranslatef(-3,0.3,0);
 	tableLine();
 	glPopMatrix();
 	
 	glPushMatrix();
	glTranslatef(-3,0,4.9);
	glRotatef(90,0,1,0);
	switchboard();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3,0,4.9);
	glRotatef(90,0,1,0);
	switchboardLine();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1,0,0);
	stable();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1,0,0);
	stableLine();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1,0,0);
	stable();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1,0,0);
	stableLine();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(3,0,0);
	stable();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3,0,0);
	stableLine();
	glPopMatrix();
 	
	glPushMatrix();
	glTranslatef(-1,0,3);
	stable();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1,0,3);
	stableLine();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1,0,3);
	stable();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1,0,3);
	stableLine();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(3,0,3);
	stable();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3,0,3);
	stableLine();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1,0,-3);
	stable();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1,0,-3);
	stableLine();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1,0,-3);
	stable();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1,0,-3);
	stableLine();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(3,0,-3);
	stable();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3,0,-3);
	stableLine();
	glPopMatrix();

	glPushMatrix();
	boardp();
	glPopMatrix();
	
	glPushMatrix();
	boardpLine();
	glPopMatrix();

	glPushMatrix();
	elev();
	glPopMatrix();

	glPushMatrix();
	elevLine();
	glPopMatrix();

    glutSwapBuffers();
}
 
void idle(){
	doorAngle+=0.1;
	wck+=0.1;
	glutPostRedisplay();

}

 
int main (int argc, char **argv)
{

    
    glutInit               (&argc, argv);
    glutInitWindowSize     (900, 600);
    glutInitWindowPosition (300, 300);
    glutInitDisplayMode    (GLUT_DEPTH | GLUT_DOUBLE);
 
    glutCreateWindow ("Orbital Font Demo");
    glutDisplayFunc  (   redraw   );
    glutIdleFunc(idle);
    glutKeyboardFunc (  Keyboard  );
    glutSpecialFunc  (Special_Keys);
    glClearColor (1, 1, 1, 1.0);
cam.set(Point3(3,2,0),Point3(-3,2,0),Vector3(0,1,0));
cam.setShape(45,640.0/480.0,1.0, 50.0);
    glutMainLoop   ();
 
    return 1;
}
 
