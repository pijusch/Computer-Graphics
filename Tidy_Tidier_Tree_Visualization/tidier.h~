#ifndef TIDIER_H
#define TIDIER_H
struct node{
	int key;
	int height;
	struct node *Llink;
	struct node *Rlink;
	int x,y;
	int offset;
	bool thread;
};
struct extreme{
	struct node *address;
	int offset,level;
};
void setup(struct node* T,int level,struct extreme lmost,struct extreme rmost);
void petrify(struct node* T,int xpos);
#endif
