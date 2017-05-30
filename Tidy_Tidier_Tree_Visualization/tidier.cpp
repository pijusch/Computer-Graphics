#include "tidier.h"
#include <cstddef>
#define MINSEP 5
int abs(int x)
{
    return x<0?-x:x;
}
void setup(struct node *T,int LEVEL,struct extreme* lmost,struct extreme* rmost)
{
    struct node *L;
    struct node *R;
    struct extreme LL,RR,LR,RL;
    //Please check whether the comment is true.
    /*get extremes*/ //Code runs without obtaining extremes as those are never used without getting initialised in the code itself
    int cursep,
    rootsep,
    loffsum,roffsum;
    if(T==NULL)
    {
        lmost->level=-1;
        rmost->level=-1;
    }
    else
    {
        T->y = LEVEL;
        L= T->Llink;
        R= T->Rlink;
        setup(L,LEVEL+1,&LR,&LL);
        setup(R,LEVEL+1,&RR,&RL);
        if(R==NULL && L==NULL)
        {
            rmost->address= T;
            lmost->address= T;
            rmost->level=LEVEL;
            lmost->level=LEVEL;
            rmost->offset=0;
            lmost->offset=0;
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
            
            if(RL.level>LL.level || T->Llink==NULL)
            {
                lmost=&RL;
                lmost->offset=lmost->offset+T->offset;
            }
            else
            {
                lmost=&LL;
                lmost->offset=lmost->offset-T->offset;
            }
            
            if(LR.level > RR.level || T->Rlink==NULL)
            {
                rmost=&LR;
                rmost->offset=rmost->offset-T->offset;
            }
            else
            {
                rmost=&RR;
                rmost->offset=rmost->offset+T->offset;
            }
            
            if(L!=NULL && L!=T->Llink)
            {
                RR.address->thread=true;
                RR.address->offset=abs(RR.offset+T->offset-loffsum);
                if(loffsum-T->offset <= RR.offset)
                {
                    RR.address->Llink=L;
                }
                else
                {
                    RR.address->Rlink=L;
                }
            }
            else if(R!=NULL && R!=T->Rlink)
            {
                LL.address->thread=true;
                LL.address->offset=abs(LL.offset+T->offset-roffsum);
                if(roffsum+T->offset >= LL.offset)
                {
                    LL.address->Rlink=R;
                }
                else
                {
                    LL.address->Llink=L;
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