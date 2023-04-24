#include <stdbool.h>
#include "stdio.h"
#include "string.h"
char ch=0;
char strToken[100]={'0'};
int str=0;
char s[100]={'0'};//读入的字符串
int pre=0;
int flag=0;
int code;

void GetChar();
void GetBC();
void Concat();
bool IsLetter();
bool IsDigit();
int Reserve();
void Retract();

void scanner();//词法分析函数

int main(){
    scanf("%s",s);
    while(1){
        scanner();
        ch=0;
        str=0;
        if(flag==1) break;
    }
    return 0;
}

void scanner(){
    GetChar();GetBC();
    if(IsLetter()){//是字符串的情况
        while(IsLetter()||IsDigit()){
            Concat();GetChar();
        }
        Retract();
        code=Reserve();
        if(code==0) printf("$ID %s\n",strToken);
    }
    else if(IsDigit()){//是数据的情况
        while(IsDigit()){
            Concat();GetChar();
        }
        Retract();
        code=Reserve();
        if(code==0) printf("$INT %s\n",strToken);
    }
    else if(ch=='=') printf("$ASSIGN\n");
    else if(ch=='+') printf("$PLUS\n");
    else if(ch=='*') printf("$STAR\n");
    else if(ch==',') printf("$COMMA\n");
    else if(ch=='(') printf("$LPAR\n");
    else if(ch==')') printf("$RPAR\n");
    else printf("$ERR\n");

}

void GetChar(){
    ch=s[pre++];
    if(ch==0) flag=1;
}

void GetBC(){
    while(ch==' '){
        GetChar();
    }
}

void Concat(){
    strToken[str++]=ch;
    strToken[str]=0;
}

bool IsLetter(){
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')) return true;
    return false;
}

bool IsDigit(){
    if(ch>='0'&&ch<='9') return true;
    return false;
}

int Reserve(){
    if(!strcmp(strToken,"DIM")) {printf("$DIM\n"); return 1;}
    if(!strcmp(strToken,"IF")) {printf("$IF\n"); return 2;}
    if(!strcmp(strToken,"DO")) {printf("$DO\n"); return 3;}
    if(!strcmp(strToken,"STOP")) {printf("$STOP\n"); return 4;}
    if(!strcmp(strToken,"END")) {printf("$END\n"); return 5;}
    return 0;
}

void Retract(){
    pre--;
}
