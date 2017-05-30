#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include "tidier.h"
#include <cstddef>
#include<time.h>
#define MINSEP 5 
#define right Rlink
#define left Llink
#define nd struct node
using namespace std;

FILE *fp = fopen("out.t","a");
FILE *fp2 = fopen("out2.t","a");



class LineDraw {

	public: static	void linedraw(int x0,int y0,int x1,int y1)
	{
		int a=y1-y0;
		int b=x0-x1;
		int m=abs(a/b);
		if(m<1)
		{
			int d=2*a+b;
			int incrE=2*a;
			int incrNE=2*(a+b);
			int x=x0,y=y0;
			while(x<=x1)
			{
				fprintf(fp2,"%d %d\n",x,y);
				if(d>0)
				{
					d+=incrNE;
					y++;
				}
				else
				{
					d+=incrE;
				}
				x++;
			}
		}
		else
		{
			int x2=y0,y2=x0,x3=y1,y3=x1;
			a=y3-y2;
			b=x2-x3;
			int d=2*a+b;
			int incrE=2*a;
			int incrNE=2*(a+b);
			int x=x2,y=y2;
			while(x<=x3)
			{
				fprintf(fp2,"%d %d\n",y,x);
				if(d>0)
				{
					d+=incrNE;
					y++;
				}
				else
				{
					d+=incrE;
				}
				x++;
			}
		}
	}

};

//Gives correct height value for each node
void run(struct node *T,int h){
    if(T!=NULL){
        T->offset = 0;
        T->thread = false;
        T->height = h;
        run(T->left,h+1);
        run(T->right,h+1);
    }
}
node* getNode()
{
    return (node*)malloc(sizeof (struct node));
}


#define new (nd*)malloc(sizeof(nd)
class RangeSearch{
public:
    int max(int a, int b);
    int height(struct node *N);
    struct node* newNode(int key);
    struct node *rightRotate(struct node *y);
    struct node *leftRotate(struct node *x);
    int getBalance(struct node *N);
    struct node* insert(struct node* node, int key);
    void inorder(nd *n);
    int leaf(nd *t);
    nd * find_sv(nd * root,int x,int y);
    void rsearch(nd * root,int x,int y);
};



int RangeSearch::height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

/** A utility function to get maximum of two integers
 */
int RangeSearch::max(int a, int b)
{
    return (a > b)? a : b;
}

/** Helper function that allocates a new node with the given key and
 NULL left and right pointers. */
struct node* RangeSearch::newNode(int key)
{
    struct node* node = (struct node*)
    malloc(sizeof(struct node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}

/**A utility function to right rotate subtree rooted with y
 */
struct node * RangeSearch::rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
    
    // Perform rotation
    x->right = y;
    y->left = T2;
    
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    
    // Return new root
    return x;
}

/**A utility function to left rotate subtree rooted with x
 */
struct node * RangeSearch::leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
    
    // Perform rotation
    y->left = x;
    x->right = T2;
    
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    
    // Return new root
    return y;
}

/** Get Balance factor of node N
 */
int RangeSearch::getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct node* RangeSearch::insert(struct node* node, int key)
{
    /* 1.  Perform the normal BST rotation */
    if (node == NULL)
        return(newNode(key));
    
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    

    /*node->height = max(height(node->left), height(node->right)) + 1;
    
    

    int balance = getBalance(node);
    
   
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    
   
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    
   
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
    
   
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }*/
    
    
    node->thread = false;
    return node;
}
void RangeSearch::inorder(nd *n){
    if(n==NULL) return;
    inorder(n->left);
    inorder(n->right);
    printf("%d ",n->key);
}
int RangeSearch::leaf(nd *t){
    if(t->left==NULL&&t->right==NULL) return 1;
    return 0;
}
nd * RangeSearch::find_sv(nd * root,int x,int y){
    nd* t= root;
    while(!leaf(t)&&(t->key<x||t->key>y)){
        if(t->key>y) t=t->left;
        else t=t->right;
    }
    return t;
}
void RangeSearch::rsearch(nd * root,int x,int y){
    nd *sp = find_sv(root,x,y),*t = sp->left;
    if(leaf(sp)){
        if(sp->key>=x&&sp->key<=y) printf("%d ",sp->key);
    }
    else{
        while(t!=NULL){
            if(t->key>=x){
                printf("%d ",t->key);
                inorder(t->right);
                t=t->left;
            }
            else t=t->right;
        }
        printf("%d ",sp->key);
        t = sp->right;
        while(t!=NULL){
            if(t->key<=y){
                printf("%d ",t->key);
                inorder(t->left);
                t=t->right;
            }
            else t=t->left;
        }
    }
}
int abs(int x)
{
    return x<0?-x:x;
}
struct extreme* getExtremeNode()
{
    return (struct extreme*)malloc(sizeof(struct extrme*));
}
void setup(struct node *T,int LEVEL,struct extreme **lmost,struct extreme **rmost)
{
    struct node *L;
    struct node *R;
    struct extreme *LL,*RR,*LR,*RL;
    LL=getExtremeNode();
    LR=getExtremeNode();
    RR=getExtremeNode();
    RL=getExtremeNode();
    
    //Please check whether the comment is true.
    /*get extremes*/ //Code runs without obtaining extremes as those are never used without getting initialised in the code itself
    int cursep,
    rootsep,
    loffsum,roffsum;
    if(T==NULL)
    {
        (*lmost)->level=-1;
        (*rmost)->level=-1;
    }
    else
    {
        T->y = LEVEL;
        L= T->Llink;
        R= T->Rlink;
        setup(L,LEVEL+10,&LR,&LL);
        setup(R,LEVEL+10,&RR,&RL);
        if(R==NULL && L==NULL)
        {
            (*rmost)->address= T;
            (*lmost)->address= T;
            (*rmost)->level=LEVEL;
            (*lmost)->level=LEVEL;
            (*rmost)->offset=0;
            (*lmost)->offset=0;
            T->offset=0;
        }
        else
        {
            cursep=MINSEP;
            rootsep=MINSEP;
            loffsum=0;
            roffsum=0;
            while(L!=NULL && R!=NULL)
            {
                if(cursep<MINSEP)
                {
                    rootsep=rootsep+(MINSEP-cursep);
                    cursep=MINSEP;
                }
                if(L->Rlink!=NULL)
                {
                    loffsum=loffsum+L->offset;
                    cursep=cursep-L->offset;
                    L=L->Rlink;
                }
                else
                {
                    loffsum=loffsum-L->offset;
                    cursep=cursep+L->offset;
                    L=L->Llink;
                }
                if(R->Llink!=NULL)
                {
                    roffsum=roffsum-R->offset;
                    cursep=cursep-R->offset;
                    R=R->Llink;
                }
                else
                {
                    roffsum=roffsum+R->offset;
                    cursep=cursep+R->offset;
                    R=R->Rlink;
                }
            }
            T->offset=(rootsep+1)/2;
            loffsum=loffsum-T->offset;
            roffsum=roffsum+T->offset;
            
            if(RL->level>LL->level || T->Llink==NULL)
            {
                (*lmost)=RL;
                (*lmost)->offset=(*lmost)->offset+T->offset;
            }
            else
            {
                (*lmost)=LL;
                (*lmost)->offset=(*lmost)->offset-T->offset;
            }
            
            if(LR->level > RR->level || T->Rlink==NULL)
            {
                (*rmost)=LR;
                (*rmost)->offset=(*rmost)->offset-T->offset;
            }
            else
            {
                *rmost=RR;
                (*rmost)->offset=(*rmost)->offset+T->offset;
            }
            
            if(L!=NULL && L!=T->Llink)
            {
                RR->address->thread=true;
                RR->address->offset=abs(RR->offset+T->offset-loffsum);
                if(loffsum-T->offset <= RR->offset)
                {
                    RR->address->Llink=L;
                }
                else
                {
                    RR->address->Rlink=L;
                }
            }
            else if(R!=NULL && R!=T->Rlink)
            {
                LL->address->thread=true;
                LL->address->offset=abs(LL->offset+T->offset-roffsum);
                if(roffsum+T->offset >= LL->offset)
                {
                    LL->address->Rlink=R;
                }
                else
                {
                    LL->address->Llink=L;
                }
            }
        }
    }
}
void petrify(struct node *T,int xpos)
{
    if(T!=NULL)
    {
        T->x=xpos;
        if(T->thread)
        {
            T->thread=false;
            T->Rlink=NULL;
            T->Llink=NULL;
        }
        petrify(T->Llink,xpos-T->offset);
        petrify(T->Rlink,xpos+T->offset);
    }
}
void draw(struct node *node){
 if(node!=NULL){
   if(node->left!=NULL){
     LineDraw::linedraw(node->left->x,node->left->y,node->x,node->y);
   }
   if(node->right!=NULL){
     LineDraw::linedraw(node->x,node->y,node->right->x,node->right->y);
   }
   draw(node->left);
   draw(node->right);
   fprintf(fp,"%d %d\n",node->x,node->y);
 }
}
 
int main(){
    /*struct node root;
     struct node *x = getNode();
     struct node *y = getNode();
     root.thread=false;
     root.Llink = x;
     root.Rlink = y;
     //root->left->left&right , root->right to test threading
     struct node *xx=getNode(),*xy=getNode(),*yx=getNode(),*yy=getNode();
     x->Llink=xx;
     x->Rlink=xy;
     x->thread=y->thread=xx->thread=xy->thread=root.thread=false;
     //y->Llink=yx;y->Rlink=yy;
     y->Llink=y	->Rlink=NULL; // comment this line and uncomment last to run tidier on complete binary tree of two levels
     xx->Llink=xx->Rlink=xy->Llink=xy->Rlink=yy->Llink=yy->Rlink=yx->Llink=yx->Rlink= NULL;
     struct extreme *LEFTMOST,*RIGHTMOST;
     
     setup(&root,0,LEFTMOST,RIGHTMOST);
     
     petrify(&root,0);
     
     cout<<x->x<<" "<<y->x<<endl;
     cout<<xx->x<<" "<<xy->x<<" Left Child second level"<<endl;
     //cout<<yx->x<<" "<<yy->x<<" RIght child second level\n";
     return 0;*/
    time_t t;
     	srand((unsigned) time(&t));

    RangeSearch rs;
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root =NULL;
    printf("ENTER VALUES FOR N\n");
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        root = rs.insert(root,rand()%10000);
    }
    run(root,0);
    struct extreme *LEFTMOST,*RIGHTMOST;
    setup(root,0,&LEFTMOST,&RIGHTMOST);
    
    petrify(root,0);
    draw(root);
    return 0;
    
    
}
