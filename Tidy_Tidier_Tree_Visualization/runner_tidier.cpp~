#include "tidier.h"
#include<stdlib.h>
#include <iostream>
using namespace std;
node* getNode()
{
    return (node*)malloc(sizeof (struct node));
}
int main(){
    struct node root;
    struct node *x = getNode();
    struct node *y = getNode();
    root.thread=false;
    root.Llink = x;
    root.Rlink = y;
    //root->left->left&right , root->right to test threading
    struct node *xx=getNode(),*xy=getNode(),*yx=getNode(),*yy=getNode();
    y->Llink=xx;
    y->Rlink=xy;
    x->thread=y->thread=xx->thread=xy->thread=root.thread=false;
    //y->Llink=yx;y->Rlink=yy;
    x->Llink=x->Rlink=NULL; // comment this line and uncomment last to run tidier on complete binary tree of two levels
    xx->Llink=xx->Rlink=xy->Llink=xy->Rlink=yy->Llink=yy->Rlink=yx->Llink=yx->Rlink= NULL;
    struct extreme *LEFTMOST,*RIGHTMOST;
    
    setup(&root,0,LEFTMOST,RIGHTMOST);
    
    petrify(&root,0);
    
    cout<<x->x<<" "<<y->x<<endl;
    cout<<xx->x<<" "<<xy->x<<" Left Child second level"<<endl;
    //cout<<yx->x<<" "<<yy->x<<" RIght child second level\n";
    return 0;
}
