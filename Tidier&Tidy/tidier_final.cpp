#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include "tidier.h"
#include <cstddef>
#include<time.h>
#include<limits.h>
int xmax=INT_MIN,ymax=INT_MIN,xmin=INT_MAX,ymin=INT_MAX; 
#define nd struct node
using namespace std;
FILE *fp = fopen("pixels.txt","w");
#include "primitives.h"
#include "trees.h"
#include "input_tree.h"
#include "plotter.h"
#define new (nd*)malloc(sizeof(nd)

void run(struct node *T,int h){
    if(T!=NULL){
        T->offset = 0;
        T->thread = false;
        T->height = h;
        run(T->Llink,h+1);
        run(T->Rlink,h+1);
    }
}
/*node* getNode()
{
    return (node*)malloc(sizeof (struct node));
}
int abs(int x)
{
    return x<0?-x:x;
}*/
/*struct extreme* getExtremeNode()
{
    return (struct extreme*)malloc(sizeof(struct extrme*));
}*/
void draw(struct node *node){
 if(node!=NULL){
   if(node->x > xmax) xmax = node->x;
   if(node->x < xmin) xmin = node->x;
   if(node->y > ymax) ymax = node->y;
   if(node->y < ymin) ymin = node->y;
   if(node->Llink!=NULL){
     primitives::drawLine(point(node->x,node->y),point(node->Llink->x,node->Llink->y));
   }
   if(node->Rlink!=NULL){
     primitives::drawLine(point(node->x,node->y),point(node->Rlink->x,node->Rlink->y));
   }
   draw(node->Llink);
   draw(node->Rlink);
   primitives::drawCircle(point(node->x,node->y),15);
 }
}
 
void trav(nd* p){
	if(p!=NULL){
		if(p->Llink!=NULL) p->Llink->parent = p;
		if(p->Rlink!=NULL) p->Rlink->parent = p;
		trav(p->Llink);
		trav(p->Rlink);
	}
}
void ttt(nd* p){
	if(p!=NULL){
		p->x = p->x*50;
		p->y = p->y*100;
		ttt(p->Llink);
		ttt(p->Rlink);
	}
}

int main(int argc,char** argv){
    time_t t;
     	srand((unsigned) time(&t));

    struct node *root = (struct node *)malloc(sizeof(struct node));
    root =NULL;
    printf("ENTER VALUES FOR N\n");
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        root = RangeSearch::insert(root,rand()%10000);
    }
    struct extreme LEFTMOST,RIGHTMOST;
    Tidier::setup(root,0,LEFTMOST,RIGHTMOST);
    Tidier::petrify(root,0);
    draw(root);
    fclose(fp);
    fp = fopen("pixels2.txt","w");
    run(root,0);
    trav(root);
    Tidy::tidyTree(root);
    ttt(root);
    draw(root);
    fclose(fp);
    fp = fopen("pixels.txt","r");
    glutInit(&argc, argv);
    Plot::init();
    glutDisplayFunc(Plot::plotpixel);
    glutMainLoop();
    return 0;
    
    
}
