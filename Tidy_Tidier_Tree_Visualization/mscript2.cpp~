#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    FILE *fp = fopen("out2.t","r");
    FILE *fs = fopen("mscript2.m","w");
    char s[10];
    fprintf(fs,"x2 = [ ");
    char *tok;
    while(fgets(s,10,fp)){
        int n = strlen(s);
        s[n-1]='\0';
        tok = strtok(s," ");
        while(tok!=NULL){
            fprintf(fs,"%s, ",tok);
            break;
        }
    }
    fprintf(fs,"%s ] ;\n",tok);
    fprintf(fs,"y2 = [ ");
    fclose(fp);
    fp = fopen("out2.t","r");
    while(fgets(s,10,fp)){
        int n = strlen(s);
        s[n-1]='\0';
        tok = strtok(s," ");
        tok = strtok(NULL," ");
        fprintf(fs,"%s ,",tok);
    }
    fprintf(fs,"%s ] ;",tok);
    return 0;
}
