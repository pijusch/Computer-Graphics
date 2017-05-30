void wclock(){

	glColor3d(204.0/255,102.0/255,0/255);
	glPushMatrix();
	glTranslatef(-5+0.01,.25+4,0);
	glScalef(.01,0.5,.5);
	glutSolidCube(1);
	glPopMatrix();

	glColor3d(1,1,1);
	glPushMatrix();
	glTranslatef(-5+0.01+0.005+.05,.2+4+.025,0);
	glScalef(.01,0.4,.4);
	glutSolidCube(1);
	glPopMatrix();

	glColor3d(0,0,0);
	glPushMatrix();
	glTranslatef(-5+0.01+.005+0.005+.05,.15+4+.025+.1,0);
	glTranslatef(0,-0.15/2,0);
	glRotatef(-wck*2,1,0,0);
	glTranslatef(0,0.15/2,0);
	glScalef(.01,0.15,.01);
	glutSolidCube(1);
	glPopMatrix();

	glColor3d(0,0,0);
	glPushMatrix();
	glTranslatef(-5+0.01+.005+0.005+.05,.15+4+.025+.1-.025,0);
	glTranslatef(0,-0.1/2,0);
	glRotatef(30,1,0,0);
	glTranslatef(0,0.1/2,0);
	glScalef(.01,0.1,.01);
	glutSolidCube(1);
	glPopMatrix();

	glColor3d(0,0,0);
	glPushMatrix();
	glTranslatef(-5+0.01+.005+0.005+.05,.15+4+.025+.1,0);
	glScalef(.01,0.15,.01);
	glutSolidCube(1);
	glPopMatrix();
}

void wclockLine(){

	glColor3d(0,0,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPushMatrix();
	glTranslatef(-5+0.01,.25+4,0);
	glScalef(.01,0.5,.5);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-5+0.01+0.005+.05,.2+4+.025,0);
	glScalef(.01,0.4,.4);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-5+0.01+.005+0.005+.05,.15+4+.025+.1,0);
	glTranslatef(0,-0.15/2,0);
	glRotatef(-wck*2,1,0,0);
	glTranslatef(0,0.15/2,0);
	glScalef(.01,0.15,.01);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-5+0.01+.005+0.005+.05,.15+4+.025+.1-.025,0);
	glTranslatef(0,-0.1/2,0);
	glRotatef(30,1,0,0);
	glTranslatef(0,0.1/2,0);
	glScalef(.01,0.1,.01);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-5+0.01+.005+0.005+.05,.15+4+.025+.1,0);
	glScalef(.01,0.15,.01);
	glutSolidCube(1);
	glPopMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}

void elev(){

	glColor3d(154.0/255,154.0/255,102.0/255);
	glPushMatrix();
	glTranslatef(-5+1.5+.01,.15,0);
	glScalef(3,0.3,8);
	glutSolidCube(1);
	glPopMatrix();
}

void elevLine(){

	glColor3d(0,0,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPushMatrix();
	glTranslatef(-5+1.5+.01,.15,0);
	glScalef(3,0.3,8);
	glutSolidCube(1);
	glPopMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void projector(){
	glColor3d(240.0/255,240.0/255,240.0/255);
	glPushMatrix();
	glTranslatef(0,0.125,0);
	glScalef(0.5,0.25,1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();	
	glTranslatef(0,0.125+.25,0);
	glScalef(0.03,0.25,0.03);
	glutSolidCube(1);
	glPopMatrix();

}

void projectorLine(){

	glColor3d(0,0,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPushMatrix();
	glTranslatef(0,0.125,0);
	glScalef(0.5,0.25,1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();	
	glTranslatef(0,0.125+.25,0);
	glScalef(0.03,0.25,0.03);
	glutSolidCube(1);
	glPopMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void boardp(){

	glColor3d(1.0/2,1.0/2,1.0/2);
	glPushMatrix();
	glTranslatef(-5+.05,.125+3,-1.5);
	glScalef(0.25,0.1,3.2);
	glutSolidCube(1);
	glPopMatrix();
	
	glColor3d(1,1,1);
	glPushMatrix();
	glTranslatef(-5+.1,-bl/2+3.125,-1.5);
	glScalef(0.01,bl,3);
	glutSolidCube(1);
	glPopMatrix();
}


void boardpLine(){

	glColor3d(0,0,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPushMatrix();
	glTranslatef(-5+.05,.125+3,-1.5);
	glScalef(0.25,0.1,3.2);
	glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-5+.1,-bl/2+3.125,-1.5);
	glScalef(0.01,bl,3);
	glutSolidCube(1);
	glPopMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void ceiling(){
	glColor3d(255.0/255,250.0/255,205.0/255);
	glPushMatrix();
	glTranslatef(0.0,5.005,0);
	glScalef(10,0.01,10);
	glutSolidCube(1);
	glPopMatrix();

}

void board(){
	glColor3d(57.0/255,81.0/255,16.0/255); 		

	glPushMatrix();
	glTranslatef(0,0,0); //RED
	glScalef(0.01,0.95,2.95);
	glutSolidCube(2);
	glPopMatrix();

	glColor3d(220.0/255,182.0/255,58.0/255); 		

	glPushMatrix();
	glTranslatef(.02,1,0); //RED
	glScalef(0.04,0.07,3);
	glutSolidCube(2);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(.02,-1,0); //RED
	glScalef(0.04,0.07,3);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.02,0,-2.93); //RED
	glScalef(0.04,1,0.07);
	glutSolidCube(2);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(.02,0,2.93); //RED
	glScalef(0.04,1,0.07);
	glutSolidCube(2);
	glPopMatrix();

}

void boardLine(){
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3d(0,0,0); 		

	glPushMatrix();
	glTranslatef(0,0,0); //RED
	glScalef(0.01,0.95,2.95);
	glutSolidCube(2);
	glPopMatrix();
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void chairLine()
{	
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3d(0,0,0); 	
	
	glPushMatrix();
	glTranslatef(4,2.5,0); //RED
	glScalef(0.2,2.5,0.2);
	glutSolidCube(2);
	glPopMatrix();
	
	//glColor3d(0,1,0); 		

	glPushMatrix();
	glTranslatef(0.0,2.5,0); //GREEN
	glScalef(0.2,2.5,0.2);
	glutSolidCube(2);
	glPopMatrix();
	
	//glColor3d(0,0,1); 	
	
	glPushMatrix();
	glTranslatef(0,2.5,4); //BLUE
	glScalef(0.2,2.5,0.2);
	glutSolidCube(2);
	glPopMatrix();

	//glColor3d(0,0,0); 	
		
	glPushMatrix();
	glTranslatef(4,2.5,4); //BLACK
	glScalef(0.2,2.5,0.2);
	glutSolidCube(2);
	glPopMatrix();

	//glColor3d(0.5,0.5,0.5);
		
	glPushMatrix();
	glTranslatef(2,5.55,2);
	glScalef(1,0.2,1);
	glutSolidCube(5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.75,7.55,2);
	glScalef(0.05,1,1);
	glutSolidCube(5);
	glPopMatrix();
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}	
 
void chair()
{	
	glColor3d(152.0/255,92.0/255,30.0/255);	
	
	glPushMatrix();
	glTranslatef(4,2.5,0); //RED
	glScalef(0.2,2.5,0.2);
	glutSolidCube(2);
	glPopMatrix();
	
	//glColor3d(0,1,0); 		

	glPushMatrix();
	glTranslatef(0.0,2.5,0); //GREEN
	glScalef(0.2,2.5,0.2);
	glutSolidCube(2);
	glPopMatrix();
	
	//glColor3d(0,0,1); 	
	
	glPushMatrix();
	glTranslatef(0,2.5,4); //BLUE
	glScalef(0.2,2.5,0.2);
	glutSolidCube(2);
	glPopMatrix();

	//glColor3d(0,0,0); 	
		
	glPushMatrix();
	glTranslatef(4,2.5,4); //BLACK
	glScalef(0.2,2.5,0.2);
	glutSolidCube(2);
	glPopMatrix();

	//glColor3d(0.5,0.5,0.5);
	//glColor3d(30.0/255,40.5/255,40/255); 	
	glColor3d(255.0/255,165.0/255,79.0/255);
	glPushMatrix();
	glTranslatef(2,5.55,2);
	glScalef(1,0.2,1);
	glutSolidCube(5);
	glPopMatrix();

	//glColor3d(0.5,0.5,0.5);
	glPushMatrix();
	glTranslatef(4.75,7.55,2);
	glScalef(0.05,1,1);
	glutSolidCube(5);
	glPopMatrix();
	
}	

void floor()
{
	glColor3d(255.0/255,250.0/255,205.0/255);
	glPushMatrix();
	glScalef(10,0.01,10);
	glutSolidCube(1);
	glPopMatrix();
}

void floorLine()
{
	glColor3d(0,0,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	for(int i=0;i<25;i++){
			for(int j=0;j<25;j++){
			glPushMatrix();
			glScalef(0.5+i-12.5,0.02,0.5+j-12.5);
			glutSolidCube(1);
			glPopMatrix();
		}
	}
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}


void aircond()
{
	glColor3d(230.0/255,230.0/255,230.0/255);	
	glPushMatrix();
		glTranslatef(0,4.7,0);
		glScalef(1,0.6,10);
		glutSolidCube(1);
	glPopMatrix();
	
	glColor3d(50.0/255,50.0/255,50.0/255);	
	glPushMatrix();
		glTranslatef(0.02,4.7,0);
		glScalef(1,0.02,10);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.02,4.8,0);
		glScalef(1,0.02,10);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.02,4.9,0);
		glScalef(1,0.02,10);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.02,5.0,0);
		glScalef(1,0.02,10);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.02,4.5,0);
		glScalef(1,0.02,10);
		glutSolidCube(1);
	glPopMatrix();
	
		glPushMatrix();
		glTranslatef(0.02,4.6,0);
		glScalef(1,0.02,10);
		glutSolidCube(1);
	glPopMatrix();
}

void Trump(){ //WALL

		
	glPushMatrix();
	glTranslatef(0,2.5,0);
	glScalef(0.01,5,10);
	glutSolidCube(1);
	glPopMatrix();
}


 
 

void table(){
	glColor3d(153.0/255,76.0/255,0.0/255);
	
	glPushMatrix();
		glTranslatef(0.0,0.85,0);
		glScalef(2,0.10,3);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,0.40,0.85);
		glScalef(2,0.80,0.10);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,0.40,1.45);
		glScalef(2,0.80,0.10);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,0.40,-1.45);
		glScalef(2,0.80,0.10);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,0.40,-0.85);
		glScalef(2,0.80,0.10);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.0,0.55,1.15);
		glScalef(2,0.10,0.50);
		glutSolidCube(1);
	glPopMatrix();	
	
	glPushMatrix();
		glTranslatef(0.0,0.05,1.15);
		glScalef(2,0.10,0.50);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.0,0.05,-1.15);
		glScalef(2,0.10,0.50);
		glutSolidCube(1);
	glPopMatrix();	
	
	glPushMatrix();
		glTranslatef(0.0,0.70,0);
		glScalef(2,0.10,1.6);
		glutSolidCube(1);
	glPopMatrix();
	
	
	
	//CPU
	glColor3d(60.0/255,60.0/255,60.0/255);
	glPushMatrix();
		glTranslatef(0.1,0.35,-1.15);
		glScalef(1.5,0.50,0.4);
		glutSolidCube(1);
	glPopMatrix();	
	
	//Monitor
	glPushMatrix();
		glTranslatef(0.0,1.25,-0.45);
		glScalef(0.15,0.40,0.75);
		glutSolidCube(1);
	glPopMatrix();	
	
	glPushMatrix();
		glTranslatef(0.0,1.10,-0.45);
		glScalef(0.15,0.40,0.15);
		glutSolidCube(1);
	glPopMatrix();
		
	//keyboard
	glPushMatrix();
		glTranslatef(-0.45,0.90,-0.45);
		glScalef(0.35,0.05,0.75);
		glutSolidCube(1);
	glPopMatrix();

	glColor3d(1,1,1);
	glPushMatrix();
	glTranslatef(-0.45,0.905,-0.45);
	glScalef(0.25,0.05,0.6);
	glutSolidCube(1);
	glPopMatrix();
	
	//chalk
	glColor3d(255.0/255,255.0/255,255.0/255);
	glPushMatrix();
		glTranslatef(-0.45,0.90,0.85);
		glScalef(0.15,0.10,0.005);
		glutSolidCube(1);
	glPopMatrix();
	
	glColor3d(255.0/255,255.0/255,255.0/255);
	glPushMatrix();
		glTranslatef(-0.45,0.90,0.95);
		glScalef(0.15,0.10,0.005);
		glutSolidCube(1);
	glPopMatrix();
}

void tableLine(){
	glColor3d(0,0,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glPushMatrix();
		glTranslatef(0.0,0.85,0);
		glScalef(2,0.10,3);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,0.40,0.85);
		glScalef(2,0.80,0.10);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,0.40,1.45);
		glScalef(2,0.80,0.10);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,0.40,-1.45);
		glScalef(2,0.80,0.10);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,0.40,-0.85);
		glScalef(2,0.80,0.10);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.0,0.55,1.15);
		glScalef(2,0.10,0.50);
		glutSolidCube(1);
	glPopMatrix();	
	
	glPushMatrix();
		glTranslatef(0.0,0.05,1.15);
		glScalef(2,0.10,0.50);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.0,0.05,-1.15);
		glScalef(2,0.10,0.50);
		glutSolidCube(1);
	glPopMatrix();	
	
	glPushMatrix();
		glTranslatef(0.0,0.70,0);
		glScalef(2,0.10,1.6);
		glutSolidCube(1);
	glPopMatrix();
	
	
	
	//CPU
	glColor3d(60.0/255,60.0/255,60.0/255);
	glPushMatrix();
		glTranslatef(0.1,0.35,-1.15);
		glScalef(1.5,0.50,0.4);
		glutSolidCube(1);
	glPopMatrix();	
	
	//Monitor
	glPushMatrix();
		glTranslatef(0.0,1.25,-0.45);
		glScalef(0.15,0.40,0.75);
		glutSolidCube(1);
	glPopMatrix();	
	
	glPushMatrix();
		glTranslatef(0.0,1.10,-0.45);
		glScalef(0.15,0.40,0.15);
		glutSolidCube(1);
	glPopMatrix();
		
	//keyboard
	glPushMatrix();
		glTranslatef(-0.45,0.90,-0.45);
		glScalef(0.35,0.05,0.75);
		glutSolidCube(1);
	glPopMatrix();

	glColor3d(1,1,1);
	glPushMatrix();
	glTranslatef(-0.45,0.905,-0.45);
	glScalef(0.25,0.05,0.6);
	glutSolidCube(1);
	glPopMatrix();
	
	//chalk
	glColor3d(255.0/255,255.0/255,255.0/255);
	glPushMatrix();
		glTranslatef(-0.45,0.90,0.85);
		glScalef(0.15,0.10,0.005);
		glutSolidCube(1);
	glPopMatrix();
	
	glColor3d(255.0/255,255.0/255,255.0/255);
	glPushMatrix();
		glTranslatef(-0.45,0.90,0.95);
		glScalef(0.15,0.10,0.005);
		glutSolidCube(1);
	glPopMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}


void door(){
	glColor3d(153.0/255,76.0/255,0);	
	glPushMatrix();
	glTranslatef(0.0,1.5,0);
	glScalef(0.01,3,2);
	glutSolidCube(1);
	glPopMatrix();

	glColor3d(204.0/255,102.0/255,0);
	glPushMatrix();
	glTranslatef(-0.01,1.5,-0.75);
	glScalef(0.01,0.4,0.2);
	glutSolidCube(1);
	glPopMatrix();

	glColor3d(1,1,1);
	glPushMatrix();
	glTranslatef(-0.015,1.5,-0.67);
	glScalef(0.01,0.05,0.3);
	glutSolidCube(1);
	glPopMatrix();

} 

void doorLine(){
	glColor3d(0,0,0);	
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPushMatrix();
	glTranslatef(0.0,1.5,0);
	glScalef(0.01,3,2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.01,1.5,-0.75);
	glScalef(0.01,0.4,0.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.015,1.5,-0.67);
	glScalef(0.01,0.05,0.3);
	glutSolidCube(1);
	glPopMatrix();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
} 

void wallDoor(){

	glColor3d(184.0/255,219.0/255,214.0/255);	
	
	glPushMatrix();
	glTranslatef(0,1.5,4);
	glScalef(0.01,3,2);
	glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0,1.5,-2);
	glScalef(0.01,3,6);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,4,0);
	glScalef(0.01,2,10);
	glutSolidCube(1);
	glPopMatrix();

}



void speaker()
{
	
}

void switchboard()
{
	glColor3d(200.0/255,200.0/255,200.0/255);
	glPushMatrix();
		glTranslatef(0,2,0);
		glScalef(0.01,0.4,1.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glColor3d(10.0/255,10.0/255,10.0/255);
	glPushMatrix();
		glTranslatef(0,2,0.5);
		glScalef(0.02,0.02,0.02);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,2,0.4);
		glScalef(0.02,0.02,0.02);
		glutSolidCube(1);
	glPopMatrix();
	
	//socket :p
	glPushMatrix();
		glTranslatef(0,2.1,0.45);
		glScalef(0.02,0.02,0.02);
		glutSolidCube(1);
	glPopMatrix();
	
	glColor3d(255.0/255,255.0/255,255.0/255);
	glPushMatrix();
		glTranslatef(0.02,2.0,0.1);
		glScalef(0.02,0.25,0.1);
		glutSolidCube(1);
	glPopMatrix();
	
	glColor3d(255.0/255,255.0/255,255.0/255);
	glPushMatrix();
		glTranslatef(0.02,2.0,-0.1);
		glScalef(0.02,0.25,0.1);
		glutSolidCube(1);
	glPopMatrix();
	
		glColor3d(255.0/255,255.0/255,255.0/255);
	glPushMatrix();
		glTranslatef(0.02,2.0,-0.3);
		glScalef(0.02,0.25,0.1);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.02,2.0,-0.5);
		glScalef(0.02,0.25,0.1);
		glutSolidCube(1);
	glPopMatrix();
	
}

void switchboardLine()
{
	glColor3d(0,0,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPushMatrix();
		glTranslatef(0,2,0);
		glScalef(0.01,0.4,1.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glColor3d(10.0/255,10.0/255,10.0/255);
	glPushMatrix();
		glTranslatef(0,2,0.5);
		glScalef(0.02,0.02,0.02);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,2,0.4);
		glScalef(0.02,0.02,0.02);
		glutSolidCube(1);
	glPopMatrix();
	
	//socket :p
	glPushMatrix();
		glTranslatef(0,2.1,0.45);
		glScalef(0.02,0.02,0.02);
		glutSolidCube(1);
	glPopMatrix();
	
	glColor3d(255.0/255,255.0/255,255.0/255);
	glPushMatrix();
		glTranslatef(0.02,2.0,0.1);
		glScalef(0.02,0.25,0.1);
		glutSolidCube(1);
	glPopMatrix();
	
	glColor3d(255.0/255,255.0/255,255.0/255);
	glPushMatrix();
		glTranslatef(0.02,2.0,-0.1);
		glScalef(0.02,0.25,0.1);
		glutSolidCube(1);
	glPopMatrix();
	
		glColor3d(255.0/255,255.0/255,255.0/255);
	glPushMatrix();
		glTranslatef(0.02,2.0,-0.3);
		glScalef(0.02,0.25,0.1);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.02,2.0,-0.5);
		glScalef(0.02,0.25,0.1);
		glutSolidCube(1);
	glPopMatrix();
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
}

void fan(){
	glColor3d(200.0/255,200.0/255,200.0/255);
		glTranslatef(0,0.15,0);
	//glColor3d(1,0,0);		
		
	glPushMatrix();
	glTranslatef(0,0.005,0);
	
	glTranslatef(0,0,0.6);
	glScalef(0.1,0.01,.4);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.15,0.01,0.15);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0.2,0);
	glScalef(0.015,0.2,0.015);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0.005,0);
	glRotatef(120,0,1,0);
	glTranslatef(0,0,0.6);
	glScalef(0.1,0.01,0.4);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0.005,0);
	glRotatef(-120,0,1,0);
	glTranslatef(0,0,0.6);
	glScalef(0.1,0.01,0.4);
	glutSolidCube(2);
	glPopMatrix();

}

void fanLine(){
	glTranslatef(0,0.15,0);
	glColor3d(0,0,0);		
		
	glPushMatrix();
	glTranslatef(0,0.005,0);
	
	glTranslatef(0,0,0.6);
	glScalef(0.1,0.01,.4);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.15,0.01,0.15);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0.2,0);
	glScalef(0.015,0.2,0.015);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0.005,0);
	glRotatef(120,0,1,0);
	glTranslatef(0,0,0.6);
	glScalef(0.1,0.01,0.4);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0.005,0);
	glRotatef(-120,0,1,0);
	glTranslatef(0,0,0.6);
	glScalef(0.1,0.01,0.4);
	glutSolidCube(2);
	glPopMatrix();

}

void stable(){
	
	glColor3d(255.0/255,165.0/255,79.0/255);
	glPushMatrix();
	glTranslatef(0,.025+.75,0);
	glScalef(0.5,0.05,1);
	glutSolidCube(1);
	glPopMatrix();
	

	glColor3d(152.0/255,92.0/255,30.0/255);
	glPushMatrix();
	glTranslatef(0.25-.025,.75/2,.5-.025);
	glScalef(0.02,.75,0.02);
	glutSolidCube(1);
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(-0.25+.025,.75/2,-.5+.025);
	glScalef(0.02,.75,0.02);
	glutSolidCube(1);
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(-0.25+.025,.75/2,.5-.025);
	glScalef(0.02,.75,0.02);
	glutSolidCube(1);
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(0.25-.025,.75/2,-.5+.025);
	glScalef(0.02,.75,0.02);
	glutSolidCube(1);
	glPopMatrix();

} 

void stableLine(){
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3d(0,0,0);
	glPushMatrix();
	glTranslatef(0,.025+.75,0);
	glScalef(0.5,0.05,1);
	glutSolidCube(1);
	glPopMatrix();
	

	glPushMatrix();
	glTranslatef(0.25-.025,.75/2,.5-.025);
	glScalef(0.02,.75,0.02);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.25+.025,.75/2,-.5+.025);
	glScalef(0.02,.75,0.02);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.25+.025,.75/2,.5-.025);
	glScalef(0.02,.75,0.02);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.25-.025,.75/2,-.5+.025);
	glScalef(0.02,.75,0.02);
	glutSolidCube(1);
	glPopMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
} 


