#include <stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#define RED 14
union REGS  in,out;


void initmouse(){
in.x.ax=1;
int86(0x33,&in,&out);
}
int x,y,a[2],x1,y1,x2,y2;
double xt,yt;

void location(){

	a[0]=0;
	a[1]=0;
      while(!kbhit()) {
	in.x.ax=3;
	int86(0x33,&in,&out);

	if(out.x.bx==1){

       x=out.x.cx;
       y=out.x.dx;


	break;
	}             }

	while(!kbhit()){
	in.x.ax=3;
	int86(0x33,&in,&out);

	if(out.x.bx==1){
	a[0]=out.x.cx;
	a[1]=out.x.dx;

       cleardevice();

       line(x,y,a[0],a[1]); }
       if(out.x.bx==2){
       break;
       }

}     //	return a;
}



void blend(){

	double t;
  while(!kbhit()){

	in.x.ax=3;
	int86(0x33,&in,&out);


	if(out.x.bx==2){
	x1=out.x.cx;
	y1=out.x.dx;
	cleardevice();
	line(x1,y1,x2,y2);


	  putpixel(x1+1,y1,RED);
	  putpixel(x1,y1+1,RED);
	  putpixel(x1-1,y1,RED);
	  putpixel(x1,y1-1,RED);
	  putpixel(x2+1,y2,RED);
	  putpixel(x2,y2+1,RED);
	  putpixel(x2-1,y2,RED);
	  putpixel(x2,y2-1,RED);
	  putpixel(x1+2,y1,RED);
	  putpixel(x1,y1+2,RED);
	  putpixel(x1-2,y1,RED);
	  putpixel(x1,y1-2,RED);
	  putpixel(x2+2,y2,RED);
	  putpixel(x2,y2+2,RED);
	  putpixel(x2-2,y2,RED);
	  putpixel(x2,y2-2,RED);


	for( t=0.0;t<1.0;t=t+0.001){

	 xt=(pow(1-t,3)*x+3*t*pow(1-t,2)*x2+3*pow(1-t,1)*pow(t,2)*x1+pow(t,3)*a[0]);
	 yt=(pow(1-t,3)*y+3*t*pow(1-t,2)*y2+3*pow(1-t,1)*pow(t,2)*y1+pow(t,3)*a[1]);


	 putpixel(xt,yt,WHITE);



	}



      }
      if(out.x.bx==1){
	x2=out.x.cx;
	y2=out.x.dx;
	cleardevice();
	 line(x1,y1,x2,y2);


	  putpixel(x1+1,y1,RED);
	  putpixel(x1,y1+1,RED);
	  putpixel(x1-1,y1,RED);
	  putpixel(x1,y1-1,RED);
	  putpixel(x2+1,y2,RED);
	  putpixel(x2,y2+1,RED);
	  putpixel(x2-1,y2,RED);
	  putpixel(x2,y2-1,RED);
	  putpixel(x1+2,y1,RED);
	  putpixel(x1,y1+2,RED);
	  putpixel(x1-2,y1,RED);
	  putpixel(x1,y1-2,RED);
	  putpixel(x2+2,y2,RED);
	  putpixel(x2,y2+2,RED);
	  putpixel(x2-2,y2,RED);
	  putpixel(x2,y2-2,RED);
	for( t=0.0;t<1.0;t=t+0.001){

	 xt=(pow(1-t,3)*x+3*t*pow(1-t,2)*x2+3*pow(1-t,1)*pow(t,2)*x1+pow(t,3)*a[0]);
	 yt=(pow(1-t,3)*y+3*t*pow(1-t,2)*y2+3*pow(1-t,1)*pow(t,2)*y1+pow(t,3)*a[1]);

	 putpixel(xt,yt,WHITE);

	}

       }





     }

}
void main(){


	int gd=DETECT,gm;
	a[1]=0;
	a[0]=0;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
       //	line(10,10,50,100);
	initmouse();
	location();
       //	printf("%d , %d",a[0],a[1]);

	blend();



	getch();
}