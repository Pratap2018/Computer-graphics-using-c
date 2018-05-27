#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>



void bsc(int x[4],int y[4])
{

 int gd=DETECT,gm;
 int i;

 double t,xt,yt;
 initgraph(&gd,&gm,"c:\\turboc3\\bgi");
 for(t=0.0;t<1.0;t=t+0.00001)
 {
 xt=(pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(1-t,1)*pow(t,2)*x[2]+pow(t,3)*x[3]);
 yt=(pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(1-t,1)*pow(t,2)*y[2]+pow(t,3)*y[3]);

//printf("%lf %lf",xt,yt);
 putpixel(xt,yt,WHITE);
 }

 for(i=0;i<4;i++)
 {
  putpixel(x[i],y[i],YELLOW);
 }

getch();

}
void main(){
  int x[4],y[4],i;

  printf("Enter 4 controll point :");
  for(i=0;i<4;i++){

  scanf("%d%d",&x[i],&y[i]);

  }

  bsc(x,y);


}