#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;

int x = 50;
int y = 500;

void  Axis()
{
    setcolor(WHITE);
    line(x,0,x,1500);
    line(0,y,1500,y);
    line(0,y-200,1500,y-200);
    line(0,y-400,1500,y-400);

    setcolor(RED);
    outtextxy(x-30,y+10,"(0,0)");


    for(int i = x+75; i<=1500; i=i+75)
    {
        for(int j = y+80; j>=50; j=j-4)
            putpixel(i,j,WHITE);
    }

}

void Pulse(char S[])
{
    int ny = 100;
    int nx = x;
    setcolor(MAGENTA);
    for(int i = 0; i<strlen(S); i++)
    {
        int a = ny;
        if(S[i] == '0')
            ny = 100;
        else if(S[i] == '1')
            ny = 25;
        for(int j = a; j>=ny; j--)
            putpixel(nx,j,MAGENTA);
        for(int j = a; j<=ny; j++)
            putpixel(nx,j,MAGENTA);

        line(nx,ny,nx+75,ny);
        nx = nx+75;

        char A[3];
        sprintf(A,"%c",S[i]);
        outtextxy(nx-40,ny-20,A);
    }
}


void Base(char S[])
{
    int angle = 0;
    for(int i = x; i<=(strlen(S)*75)+50; i = i+1)
    {
        int yn = 50*sin(angle*(3.1416/180));
        int j = 300-yn;
        putpixel(i,j,YELLOW);
        delay(5);
        angle = angle+10;
    }
}


void ASK(char S[])
{
    int angle = 0;
    setcolor(LIGHTBLUE);
    for(int i=0; i<strlen(S); i++)
    {
        int k = 0;
        if(S[i] == '1')
        {
            for(int j = x; j<x+75; j = j+1)
            {
                int yn = 50*sin(angle*(3.1416/180));
                int jy = 500-yn;
                putpixel(j,jy,LIGHTBLUE);
                delay(5);
                angle = angle+10;
            }
            k++;
        }

        if(k == 0)
        {
        angle = angle + 750;
        line(x,500,x+75,500);
        }
        x = x+75;
    }

}

int main()
{
    char S[100];
    scanf("%s",S);

    initwindow(1500,700,"Main Window");

    Axis();
    Pulse(S);
    Base(S);
    ASK(S);

    getch();
}
