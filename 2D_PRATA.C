#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

# define absx(x) x+280
# define absy(y) 240-y



#define thita(x) x*3.14/180

union REGS in,out;

/////////////////////////////////////////////////////////////////////////////////


int select(){
int x,y;
while(!kbhit()){
	in.x.ax=3;
	int86(0x33,&in,&out);
	if(out.x.bx==1){

		x=out.x.cx;
		y=out.x.dx;
	       //	outtext("asdf");
	       //	printf("%d %d",x,y);
		delay(200);

		if((x>551 && y>11) &&( x<630 && y<30)) {

		return 1;
		}

		if((x>551 && y>40) &&( x<630 && y<60)) {

	       //	printf("asd");
		return 2;
		}

		if((x>551 && y>70) &&( x<630 && y<90)) {

	       //	printf("asd");
		return 3;
		}

		if((x>551 && y>100) &&( x<630 && y<120)) {

		//printf("asd");
		return 4;
		}
		if((x>551 && y>130) &&( x<630 && y<150)) {

		//printf("asd");
		return 5;
		}
		if((x>551 && y>160) &&( x<630 && y<180)) {

		//printf("asd");
		return 9;

		}
		if((x>551 && y>190) &&( x<630 && y<210)) {

		//printf("asd");
		return 7;

		}
		}

 }
 return  0;
}


///*********************************************************///

int rs(){
int x,y;

while(!kbhit()){
	in.x.ax=3;
	int86(0x33,&in,&out);
	if(out.x.bx==1){

		x=out.x.cx;
		y=out.x.dx;
	      //	printf("%d %d ",x,y);

		if((x>5 && y>30) &&( x<57 && y<50)) {


		return 1;
		}
		if((x>5 && y>60) &&( x<57 && y<80)) {

		return 2;
		}
		if((x>5 && y>90) &&( x<57 && y<110)) {

		return 3;
	   }


	}

    }
    return 0;
}


//******************************************************///



////////////////////////////////////////////////////////////////////////
void panel(){

    rectangle(5,30,59,50);
  floodfill(7,32,11);
 outtextxy(6,31,"X-axis");
 rectangle(5,60,59,80);
   floodfill(7,61,11);

 outtextxy(6,62,"Y-axis");

 rectangle(5,90 ,59,110);

  floodfill(7,91,11);
 outtextxy(6,92,"back");

}

////////////////////////////////////////////////////////////////////////////


void initmouse(){

in.x.ax=1;
int86(0x33,&in,&out);

}



//////////////////////////////////////////////////////////////////////////////

void DrawCordinates()
{
  bar(540,0,640,getmaxy());
  setcolor(11);
  setfillstyle(HATCH_FILL,RED);

  rectangle(550,10,630,30);
  outtextxy(552,12,"Trans");
  setcolor(11);
  setfillstyle(HATCH_FILL,RED);

  rectangle(550,40,630,60);
  floodfill(556,41,11);
  outtextxy(552,42,"Rotate");


  rectangle(550,70,630,90);
  floodfill(556,71,11);
  outtextxy(552,72,"Scale");

  rectangle(550,100,630,120);
  floodfill(556,101,11);
  outtextxy(552,102,"Reflect");

  rectangle(550,130,630,150);
  floodfill(556,131,11);
  outtextxy(552,132,"Exit");


  rectangle(550,160,630,180);
  floodfill(556,161,11);
  outtextxy(552,162,"REFRESH");

  rectangle(550,190,630,210);
  floodfill(556,191,11);
  outtextxy(552,192,"RESET");


  floodfill(556,11,11);
  line(280,0,280,540);
  line(0,240,540,240);
  line(540,0,540,480);
}
///////////////////////////////////////////////////////////////////////////////









double *a[3];


void ob(int c){

int i;
	for(i=0;i<c;i++){

	if(i==c-1){
	line(absx(a[0][i]),absy(a[1][i]),absx(a[0][0]),absy(a[1][0]));

	}else
	line(absx(a[0][i]),absy(a[1][i]),absx(a[0][i+1]),absy(a[1][i+1]));
 }
}


void scale(int c){
       int i,j,k;
	double *r[3],trans[3][3],tx,ty,sx,sy,add=0;
      for(i=0;i<c;i++){
	r[i]=(double *) malloc(c*sizeof(double));
       }


	for(i=0;i<c;i++){

	if(i==c-1){
	line(absx(a[0][i]),absy(a[1][i]),absx(a[0][0]),absy(a[1][0]));

	}else
	line(absx(a[0][i]),absy(a[1][i]),absx(a[0][i+1]),absy(a[1][i+1]));
 }

    printf("Enter the value of pivot");
    scanf("%lf%lf",&tx,&ty);
     printf("Enter the values of sx,sy");
     scanf("%lf%lf",&sx,&sy);

     trans[0][0]=sx;
     trans[0][1]=0;
     trans[0][2]=tx*(1-sx);
     trans[1][0]=0;
     trans[1][1]=sy;
     trans[1][2]=ty*(1-sy);
     trans[2][0]=0;
     trans[2][1]=0;
     trans[2][2]=1;


     for(i=0;i<3;i++){
	for(j=0;j<c;j++){
		for(k=0;k<3;k++){

		     add=add+trans[i][k]*a[k][j];;
		     }
		     r[i][j]=add;
		     add=0;
		}
	  }


	for(i=0;i<3;i++){
	for(j=0;j<c;j++){
	a[i][j]=r[i][j];
	}}


	setcolor(RED);

	for(i=0;i<c;i++){

	if(i==c-1){
	line(absx(r[0][i]),absy(r[1][i]),absx(r[0][0]),absy(r[1][0]));

	}else
	line(absx(r[0][i]),absy(r[1][i]),absx(r[0][i+1]),absy(r[1][i+1]));
	 }


	}






void getob(int c){

	int i;

	printf("Enter the values of the vertices :");
	for(i=0;i<c;i++){
	   double c,b;
	   scanf("%lf%lf",&c,&b);
	   a[0][i]=c;
	   a[1][i]=b;
	   a[2][i]=1.0;
	       }

}

void ref(int c,int s){
int i,j,k,add=0;
double *r[3],trans[3][3];
	for(i=0;i<c;i++){
	r[i]=(double *) malloc(c*sizeof(double));
       }
   /*  if(s==1){
     trans[0][0]=1;
     trans[0][1]=0;
     trans[0][2]=0;
     trans[1][0]=0;
     trans[1][1]=-1;
     trans[1][2]=0;
     trans[2][0]=0;
     trans[2][1]=0;
     trans[2][2]=1;

     }
     else
     {
     trans[0][0]=-1;
     trans[0][1]=0;
     trans[0][2]=0;
     trans[1][0]=0;
     trans[1][1]=1;
     trans[1][2]=0;
     trans[2][0]=0;
     trans[2][1]=0;
     trans[2][2]=1;
     }    */
	if(s==1){

	for(i=0;i<c;i++){

	   a[1][i]=-a[1][i];
	       }

	}
	else
	{
	for(i=0;i<c;i++){

	   a[0][i]=-a[0][i];
	       }
	}




     for(i=0;i<3;i++){
	for(j=0;j<c;j++){
		for(k=0;k<3;k++){

		     add=add+trans[i][k]*a[k][j];;
		     }
		     r[i][j]=add;
		     add=0;
		}
	  }

      /*	for(i=0;i<3;i++){
	for(j=0;j<c;j++){
	a[i][j]=r[i][j];
	}}
	setcolor(RED);  */

     /*  for(i=0;i<3;i++){

	for(j=0;j<c;j++)

		printf(" %lf  ",a[i][j]);

		printf("\n");

		}   */

     setcolor(RED);
     ob(c);


}

void translate(int c){

   int i,j,k;
	double *r[3],trans[3][3],tx,ty,t,add=0;
      for(i=0;i<c;i++){
	r[i]=(double *) malloc(c*sizeof(double));
       }


	for(i=0;i<c;i++){

	if(i==c-1){
	line(absx(a[0][i]),absy(a[1][i]),absx(a[0][0]),absy(a[1][0]));

	}else
	line(absx(a[0][i]),absy(a[1][i]),absx(a[0][i+1]),absy(a[1][i+1]));
 }

    printf("Enter the value of trans cordinate");
    scanf("%lf%lf",&tx,&ty);


     trans[0][0]=1 ;
     trans[0][1]=0;
     trans[0][2]=tx;
     trans[1][0]=0 ;
     trans[1][1]=1;
     trans[1][2]=ty;
     trans[2][0]=0;
     trans[2][1]=0;
     trans[2][2]=1;


     for(i=0;i<3;i++){
	for(j=0;j<c;j++){
		for(k=0;k<3;k++){

		     add=add+trans[i][k]*a[k][j];;
		     }
		     r[i][j]=add;
		     add=0;
		}
	  }

	for(i=0;i<3;i++){
	for(j=0;j<c;j++){
	a[i][j]=r[i][j];
	}}
	setcolor(RED);
	ob(c);


}


void rotate(int c){
       int i,j,k;
	double *r[3],trans[3][3],tx,ty,t,add=0;
      for(i=0;i<c;i++){
	r[i]=(double *) malloc(c*sizeof(double));
       }


	for(i=0;i<c;i++){

	if(i==c-1){
	line(absx(a[0][i]),absy(a[1][i]),absx(a[0][0]),absy(a[1][0]));

	}else
	line(absx(a[0][i]),absy(a[1][i]),absx(a[0][i+1]),absy(a[1][i+1]));
 }

    printf("Enter the value of pivot");
    scanf("%lf%lf",&tx,&ty);
     printf("Enter the values of thita");
     scanf("%lf",&t);

     trans[0][0]=cos(thita(t));
     trans[0][1]=(-sin(thita(t)));
     trans[0][2]=tx*(1-cos(thita(t)))+ty*sin(thita(t));
     trans[1][0]=sin(thita(t));
     trans[1][1]=cos(thita(t));
     trans[1][2]=(ty*(1-cos(thita(t))))-(tx*(sin(thita(t))));
     trans[2][0]=0;
     trans[2][1]=0;
     trans[2][2]=1;


     for(i=0;i<3;i++){
	for(j=0;j<c;j++){
		for(k=0;k<3;k++){

		     add=add+trans[i][k]*a[k][j];;
		     }
		     r[i][j]=add;
		     add=0;
		}
	  }


	for(i=0;i<3;i++){
	for(j=0;j<c;j++){
	a[i][j]=r[i][j];
	}}


	setcolor(RED);
	for(i=0;i<c;i++){

	if(i==c-1){
	line(absx(r[0][i]),absy(r[1][i]),absx(r[0][0]),absy(r[1][0]));

	}else
	line(absx(r[0][i]),absy(r[1][i]),absx(r[0][i+1]),absy(r[1][i+1]));
	 }


	}

void refresh(int c){

		int gd=DETECT,gm;
		clrscr();
	       //	getob(c);
		initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		rectangle(0,0,getmaxx(),getmaxy());
		setcolor(GREEN);
		rectangle(2,2,getmaxx()-2,getmaxy()-2);
		initmouse();
		DrawCordinates();
		ob(c);
}


int main(){

     int p=0,x,gd=DETECT,gm,c,i=0,j,k,s;

     double tx,ty,sx,sy,trans[3][3],*r[3],t;
       clrscr();
S:     printf("Enter the number of vertices :");
     scanf("%d",&c);
     for(i=0;i<c;i++){

     a[i]=(double *) malloc(c*sizeof(double));



     }
	 getob(c);

       do{


	      L:	refresh(c);

		s=select();
		switch(s){

		 case 1:

			refresh(c);
			translate(c);
			x=select();
			break;

		 case 2:
			refresh(c);
			rotate(c);
			x=select();

			break;
		 case 3:
		       refresh(c);
		       scale(c);
		       x=select();
		       break;

		 case 4:
		       refresh(c);

		       panel();           // x=select();

		       p=rs();
			switch(p){

				case 1:

				// printf("1");
				ref(c,1);


				 x=select();
				break;


				case 2:


				ref(c,2);

				x=select();

				// x=select();
				break;

				case 3:
			       //	printf("3");

				goto L;


				}
			      break;


		 case 5:
			exit(0);
		   break;


		 case 7:
		 closegraph();
		 goto S;

		}




	}while(s!=6);

       getch();



 return 0;

}


