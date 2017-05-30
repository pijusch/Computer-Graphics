#include<bits/stdc++.h>
#include<iostream>
#define pi 3.14159265
using namespace std;

struct face{
    double *x1,*y1,*z1;
    double *x2,*y2,*z2;
    double *x3,*y3,*z3;
    double *x4,*y4,*z4;
    int points[4];
};

struct edge{
    double *x1,*y1;
    double *x2,*y2;
    struct egde *next;
    struct edge *prev;
};
/*0.316825 0.743825
0.4932 1.3892
0.564825 1.95382
0.5632 2.4512
0.515625 2.89062
0.4452 3.2772
0.370825 3.61182
0.3072 3.8912
0.264825 4.10783
0.25 4.25*/

void func(double *a,double *b,int count){
FILE *fp = fopen("file.off","w");
    double x[10000];
    double y[10000]; 
    double z[10000];
	for(int i=0;i<count;i++){
		x[i] = a[i];
		y[i] = b[i];
		z[i]= 0;
}
    struct face f[1000];
    struct edge e[1000];
    double x1[count],y1[count],z1[count],x2[count],y2[count],z2[count];
    int c_v = count;
    int c_e = 0;
    int c_f = 0;
    for(int i=0;i<count;i++){
        x1[i]=x[i];
        y1[i]=y[i];
        z1[i]=z[i];
    }
    for(int i=0;i<360;i+=10){
        for(int j=0;j<count;j++){
            x2[j] = x1[j]*cos(pi*10/180) + z1[j]*sin(pi*10/180);
            y2[j] = y1[j];
            z2[j] = -x1[j]*sin(pi*10/180) + z1[j]*cos(pi*10/180);
        }
        for(int j=0;j<count-1;j++){
	    f[c_f].points[0] = c_v-count+j;
            f[c_f].x1 = &x[c_v-count+j];
            f[c_f].y1 = &y[c_v-count+j];
            f[c_f].z1 = &z[c_v-count+j];

	    f[c_f].points[1] = c_v-count+j+1;
            f[c_f].x2 = &x[c_v-count+j+1];
            f[c_f].y2 = &y[c_v-count+j+1];
            f[c_f].z2 = &z[c_v-count+j+1];

	    f[c_f].points[2] = c_v+j+1;
            f[c_f].x3 = &x[c_v+j+1];
            f[c_f].y3 = &y[c_v+j+1];
            f[c_f].z3 = &z[c_v+j+1];

	    f[c_f].points[3] = c_v+j;
            f[c_f].x4 = &x[c_v+j];
            f[c_f].y4 = &y[c_v+j];
            f[c_f].z4 = &z[c_v+j];

            c_f+=1;
        }
        for(int j=0;j<count;j++){
            x[c_v]=x2[j];
            y[c_v]=y2[j];
            z[c_v]=z2[j];

            x1[j]=x2[j];
            y1[j]=y2[j];
            z1[j]=z2[j];

            c_v+=1;
        }
    }

    fprintf(fp,"OFF\n");
    fprintf(fp,"%d %d %d\n",c_v,c_f,c_e);
    for(int i=0;i<c_v;i++){
	fprintf(fp,"%lf %lf %lf\n",x[i],y[i],z[i]);
    }
    for(int i=0;i<c_f;i++){
        fprintf(fp,"4 %d %d %d %d\n",f[i].points[3],f[i].points[2],f[i].points[1],f[i].points[0]);
    }
	printf("File Closed");
	fclose(fp);
}
