#include <iostream>
#include <graphics.h>
#include <vector>
#include <math.h>
#include <conio.h>


#define PI 3.14159265

using namespace std;

//class point is the class that determines what point in the drawing is the current pointer
class Point {
    int x, y;
  public:
    Point ();
    Point (int,int);
    
    void print(void){
    	cout << "x: "<<x<<", y: "<<y<<"."<<endl;
	}
	
	int getX(void){
		return x;
	}
	
	int getY(void){
		return y; 
	}
	
	void setX(int ex){
		x = ex;
	}	
	void setY(int way){
		y = way;
	}
	void changePosition(int ex, int way){
		x = ex;
		y = way;
	}

};

Point::Point () {
  x = 0;
  y = 0;
}

Point::Point (int a, int b) {
  x = a;
  y = b;
}

//class draw is the class that enables drawing of the characters
//includes methods: moveTo(), lineTo(), createNewPath(), closePath(), and curve()

class Draw {

    	int numberOfPoints;
		int currentX, currentY;
		int startingPathX, startingPathY;
		vector<Point> points;


  	public:
    	Draw ();
    	Draw (vector<Point>,int);
   		
    	void drawBackground();
    	
    	void createNewPath(int x, int y){
    		startingPathX = x;
    		startingPathY = y;
			currentX = x;
			currentY = y;
		}
    
    	void print(void){
    		cout << "x: "<<currentX<<", y: "<<currentY<<"."<<endl;
		}
		
		void createPath(int exx, int wayy){
			startingPathX = exx;
			startingPathY = wayy;
		}
		
		void moveTo(int ex, int way){
			currentX = ex;
			currentY = way;
		}
		
		void lineTo(int x, int y){
			line(currentX, currentY, x, y);		
			currentX = x;
			currentY = y;
		}
		
		void lineTo(int destinationX, int destinationY, int startingAngle, int endAngle, int radius){
			if (startingAngle < endAngle){
				currentX = destinationX - radius;
				currentY = destinationY;
			}else{
				currentX = destinationX + radius;
				currentY = destinationY;
			}
			
			arc(destinationX, destinationY,startingAngle, endAngle,radius);
			
		}
		
		void closePath(){
			line(currentX, currentY, startingPathX,startingPathY);
		}
		
		void curve(int p1x, int p1y, int p2x, int p2y, int c1x, int c1y, int c2x, int c2y){
			int newX, newY;
			for (float t = 0.001; t < 1; t = t + 0.001){
				newX = pow((1-t),3) * p1x + 3 * pow((1-t),2) * t * c1x + 3 * (1-t) * pow(t,2) *c2x + pow(t,3) * p2x;
				newY = pow((1-t),3) * p1y + 3 * pow((1-t),2) * t * c1y + 3 * (1-t) * pow(t,2) *c2y + pow(t,3) * p2y;
				putpixel(newX,newY,RED);
			}
		}
		
		void setCurrentX(int x){currentX = x;}
		void setCurrentY(int y){currentY = y;}

};

Draw::Draw () {
  currentX = 0;
  currentY = 0;
}

Draw::Draw (vector<Point> arr, int n) {
  points = arr;
  numberOfPoints = n;
  currentX = 0;
  currentY = 0;
}

//class Menu shows the things the main menu should show
//includes characters that are displayed

class Menu {
	public:
		Menu();
		
		void createBackground(void){
			setbkcolor(LIGHTCYAN); 	
		}
		
		void createStore(void){
			int trans = -15;
			cleardevice();
			setcolor(0);
			
			Point point1 (100,25);
			Point point2 (530,25);
			Point point3 (555,75);
			Point point4 (75,75);
			
			vector<Point> pointss;
			
			pointss.push_back(point1);
			pointss.push_back(point2);
			
			Point point5 (95,95);
			Point point6 (115,75);
			Point point7 (135,95);
			Point point8 (155,75);
			Point point9 (175,95);
			Point point10 (195,75);
			Point point11 (215,95);
			Point point12 (235,75);
			Point point13 (255,95);
			Point point14 (275,75);
			Point point15 (295,95);
			Point point16 (315,75);
			Point point17 (335,95);
			Point point18 (355,75);
			Point point19 (375,95);
			Point point20 (395,75);
			Point point21 (415,95);
			Point point22 (435,75);
			Point point23 (455,95);
			Point point24 (475,75);
			Point point25 (495,95);
			Point point26 (515,75);
			Point point27 (535,95);
			Point point28 (555,75);
			
			Point point29 (115,75);
			Point point30 (115,300);
			Point point31 (135,300);
			Point point32 (135,95);
			Point point33 (515,75);
			Point point34 (515,300);
			Point point35 (495,300);
			Point point36 (495,95);
			Point point37 (85,300);
			Point point38 (545,300);
			Point point39 (545,310);
			Point point40 (85,310);
			
			Point point41 (95,310);
			Point point42 (95,500);
			Point point43 (100,500);
			Point pointCircleA (150,500);
			Point point44 (535,310);
			Point point45 (535,500);
			Point point46 (530,500);
			Point point47 (520,525);
			Point point48 (480,525);
			Point point49 (470,500);
			Point pointCirc50 (500,525);
			Point point51 (200,500);
				
			Draw drawThis (pointss, 2);
				
			drawThis.createNewPath(point1.getX()+trans,point1.getY()+trans);
			drawThis.lineTo(point2.getX()+trans, point2.getY()+trans);
			drawThis.lineTo(point3.getX()+trans, point3.getY()+trans);
			drawThis.lineTo(point4.getX()+trans, point4.getY()+trans);
			drawThis.closePath();
			
			drawThis.moveTo(point4.getX()+trans, point4.getY()+trans);
			drawThis.lineTo(point5.getX()+trans, point5.getY()+trans);
			drawThis.lineTo(point6.getX()+trans, point6.getY()+trans);
			drawThis.lineTo(point7.getX()+trans, point7.getY()+trans);
			drawThis.lineTo(point8.getX()+trans, point8.getY()+trans);
			drawThis.lineTo(point9.getX()+trans, point9.getY()+trans);
			drawThis.lineTo(point10.getX()+trans, point10.getY()+trans);
			drawThis.lineTo(point11.getX()+trans, point11.getY()+trans);
			drawThis.lineTo(point12.getX()+trans, point12.getY()+trans);
			drawThis.lineTo(point13.getX()+trans, point13.getY()+trans);
			drawThis.lineTo(point14.getX()+trans, point14.getY()+trans);
			drawThis.lineTo(point15.getX()+trans, point15.getY()+trans);
			drawThis.lineTo(point16.getX()+trans, point16.getY()+trans);
			drawThis.lineTo(point17.getX()+trans, point17.getY()+trans);
			drawThis.lineTo(point18.getX()+trans, point18.getY()+trans);
			drawThis.lineTo(point19.getX()+trans, point19.getY()+trans);
			drawThis.lineTo(point20.getX()+trans, point20.getY()+trans);
			drawThis.lineTo(point21.getX()+trans, point21.getY()+trans);
			drawThis.lineTo(point22.getX()+trans, point22.getY()+trans);
			drawThis.lineTo(point23.getX()+trans, point23.getY()+trans);
			drawThis.lineTo(point24.getX()+trans, point24.getY()+trans);
			drawThis.lineTo(point25.getX()+trans, point25.getY()+trans);
			drawThis.lineTo(point26.getX()+trans, point26.getY()+trans);
			drawThis.lineTo(point27.getX()+trans, point27.getY()+trans);
			drawThis.lineTo(point28.getX()+trans, point28.getY()+trans);
			
			drawThis.moveTo(point29.getX()+trans, point29.getY()+trans);
			drawThis.lineTo(point30.getX()+trans, point30.getY()+trans);
			drawThis.lineTo(point31.getX()+trans, point31.getY()+trans);
			drawThis.lineTo(point32.getX()+trans, point32.getY()+trans);
			drawThis.moveTo(point33.getX()+trans, point33.getY()+trans);
			drawThis.lineTo(point34.getX()+trans, point34.getY()+trans);
			drawThis.lineTo(point35.getX()+trans, point35.getY()+trans);
			drawThis.lineTo(point36.getX()+trans, point36.getY()+trans);
			drawThis.moveTo(point37.getX()+trans, point37.getY()+trans);
			drawThis.lineTo(point38.getX()+trans, point38.getY()+trans);
			drawThis.lineTo(point39.getX()+trans, point39.getY()+trans);
			drawThis.lineTo(point40.getX()+trans, point40.getY()+trans);
			drawThis.lineTo(point37.getX()+trans, point37.getY()+trans);
			
			drawThis.moveTo(point41.getX()+trans, point41.getY()+trans);
			drawThis.lineTo(point42.getX()+trans, point42.getY()+trans-80);
			drawThis.lineTo(point43.getX()+trans, point43.getY()+trans-80);
			drawThis.lineTo(pointCircleA.getX()+trans, pointCircleA.getY()+trans-80,0,360,50);
			drawThis.moveTo(point44.getX()+trans, point44.getY()+trans);
			drawThis.lineTo(point45.getX()+trans, point45.getY()+trans-80);
			drawThis.lineTo(point46.getX()+trans, point46.getY()+trans-80);
			drawThis.lineTo(point47.getX()+trans, point47.getY()+trans-80);
			drawThis.lineTo(point48.getX()+trans, point48.getY()+trans-80);
			drawThis.lineTo(point49.getX()+trans, point49.getY()+trans-80);
			drawThis.lineTo(pointCirc50.getX()+trans, pointCirc50.getY()+trans-80,184,353,15);
			drawThis.moveTo(point49.getX()+trans, point49.getY()+trans-80);
			drawThis.lineTo(point51.getX()+trans, point51.getY()+trans-80);
			drawThis.lineTo(point46.getX()+trans, point46.getY()+trans-80);
		}
		
		void createTextMenu(void){
			settextstyle(10,0,5);
			setcolor(BLACK);
			outtextxy(170,200,"PLAY");
			outtextxy(330,200,"EXIT");
		
		}

		void choice(int x, int y){
		
				vector<Point> points;
				setcolor(6);
				Point pointa (40,60);
				Point pointb (43,60);
				Point pointc (43,10);
				Point pointd (42,5);
				Point pointe (40,10);
				Point pointf (40,60);
				
				points.push_back(pointa);
				Draw draw(points,1);
				
				draw.moveTo(pointa.getX()+x,pointa.getY()+y);
	    		draw.lineTo(pointb.getX()+x,pointb.getY()+y);
	    		draw.lineTo(pointc.getX()+x,pointc.getY()+y);
	    		draw.lineTo(pointd.getX()+x,pointd.getY()+y);
	    		draw.lineTo(pointe.getX()+x,pointe.getY()+y);
	    		draw.lineTo(pointf.getX()+x,pointf.getY()+y);
	    		
	    		int i = 0;
	    		while(true){
	    			
	    			if (pointa.getX()+x+i > pointb.getX()+x){
	    				break;
					}else{
						draw.moveTo(pointa.getX()+x+i, pointa.getY()+y);
		    			draw.lineTo(pointe.getX()+x+i, pointe.getY()+y);	
					}			
					i++;
				}
				draw.moveTo(42+x,10+y);
				draw.lineTo(42+x,5+y);
				draw.moveTo(41+x,10+y);
				draw.lineTo(42+x,5+y);
				
				setcolor(15);
				
				circle(42+x,20+y,6);
	    		setfillstyle(SOLID_FILL,WHITE);
	    		floodfill(42+x,20+y,WHITE);
	    		
	    		setcolor(15);
				
				circle(42+x,32+y,6);
	    		setfillstyle(SOLID_FILL,WHITE);
	    		floodfill(42+x,32+y,WHITE);
	    		
	    		setcolor(15);
				
				circle(42+x,44+y,6);
	    		setfillstyle(SOLID_FILL,WHITE);
	    		floodfill(42+x,44+y,WHITE);
    		
		}


};

Menu::Menu(){
	//nothing
}

//order is the white paper placing the orders of the people

class Order{
	int speed = 1;
	int left, right, top, bottom;
	int movement1;
	int movement2;
	int movement3;
	int movement4;
	int movement5;
	int movement6;
	int state = 1;
	public:
		Order();
		
		void setSpeed(int speedChange){
			speed = speedChange;
		}
		
		void create(){
			setcolor(WHITE);

			if (right + movement1 > 600 && top == 105 && state == 1){
				state = 2;
			} else if (right+movement2 < 65 && state == 2){
				state = 3;
			} else if (state == 3 && right+movement3 > 600){
				state = 4;
			} else if (state == 4 && right+movement4 < 65){
				state = 5;
			} else if (state == 5 && right+movement5 > 600){
				state = 6;
			}
		
			if (state == 1){
				setfillstyle(1,WHITE);
				rectangle(left+movement1,top,right+movement1,bottom);
				floodfill(left+1+movement1,top+1,WHITE);
				movement1+=speed;
				movement2 = movement1;
				
				setcolor(BLACK);		
				settextstyle(10,0,1);
				outtextxy(left+movement1+3,top+3,"1");
				setcolor(WHITE);
		
			}else if (state == 2){
				setfillstyle(1,WHITE);
				rectangle(left+movement2,top+60,right+movement2,bottom+60);
				floodfill(left+1+movement2,top+1+60,WHITE);
				movement2-=speed;	
				movement3 = movement2;
			
				setcolor(BLACK);		
				settextstyle(10,0,1);
				outtextxy(left+movement2+5,top+63,"1");
				setcolor(WHITE);
		
			}   else if (state == 3){
				setfillstyle(1,WHITE);
				rectangle(left+movement3,top+120,right+movement3,bottom+120);
				floodfill(left+1+movement3,top+1+120,WHITE);
				movement3+=speed;		
				movement4 = movement3;
		
				setcolor(BLACK);		
				settextstyle(10,0,1);
				outtextxy(left+movement3+3,top+123,"1");
				setcolor(WHITE);
		
			}else if (state == 4){
				setfillstyle(1,WHITE);
				rectangle(left+movement4,top+180,right+movement4,bottom+180);
				floodfill(left+1+movement4,top+1+180,WHITE);
				movement4-=speed;		
				movement5 = movement4;
				
				setcolor(BLACK);		
				settextstyle(10,0,1);
				outtextxy(left+movement4+5,top+183,"1");
				setcolor(WHITE);
		
			}else if (state == 5){
				setfillstyle(1,WHITE);
				rectangle(left+movement5,top+240,right+movement5,bottom+240);
				floodfill(left+1+movement5,top+1+240,WHITE);
				movement5+=speed;			
				movement6 = movement5;
				
				setcolor(BLACK);		
				settextstyle(10,0,1);
				outtextxy(left+movement5+3,top+243,"1");
				setcolor(WHITE);
		
			}else if (state == 6){
				setfillstyle(1,WHITE);
				rectangle(left+movement6,top+300,right+movement6,bottom+300);
				floodfill(left+1+movement6,top+1+300,WHITE);
				movement6-=speed;		
			
				setcolor(BLACK);		
				settextstyle(10,0,1);
				outtextxy(left+movement6+5,top+303,"1");
				setcolor(WHITE);
		
					
			}
		}
		
		int getX(void){
			return left+movement1;
		}
		
		int getY(void){
			return top;
		}
		
		int getState(void){
			return state;
		}
		
		int getLeftX(void){
			if (state == 6){
				return left+movement6;
			}else{
				return 0;
			}
		}
		
		int getLeft(){
			if (state == 1){
				return left+movement1+209;
			}else if (state == 2){
				return left+movement2+209;
			}else if (state == 3){
				return left+movement3+209;
			}else if (state == 4){
				return left+movement4+209;
			}else if (state == 5){
				return left+movement5+209;
			}else if (state == 6){
				return left+movement6+209;
			}
		}
		int getRight(){
			if (state == 1){
				return right+movement1+209;
			}else if (state == 2){
				return right+movement2+209;
			}else if (state == 3){
				return right+movement3+209;
			}else if (state == 4){
				return right+movement4+209;
			}else if (state == 5){
				return right+movement5+209;
			}else if (state == 6){
				return right+movement6+209;
			}
		}
		int getTop(){
			if (state == 1){
				return top;		
			}else if (state == 2){
				return top+60;
			}else if (state == 3){
				return top+120;
			}else if (state == 4){
				return top+180;
			}else if (state == 5){
				return top+240;
			}else if (state == 6){
				return top+300;
			}
		}
		int getBottom(){
			if (state == 1){
				return bottom;
			}else if (state == 2){
				return bottom+60;
			}else if (state == 3){
				return bottom+120;
			}else if (state == 4){
				return bottom+180;
			}else if (state == 5){
				return bottom+240;
			}else if (state == 6){
				return bottom+300;
			}
		}
		
};

Order::Order(){
	//nothing
	left = 15;
	top = 105;
	right = 65;
	bottom = 150;
	movement1 = 0;
	movement2 = 0;
	movement3 = 0;
	movement4 = 0;
	movement5 = 0;
	movement6 = 0;
}

//Play has all the methods for the play mode

class Play{
	int life;
	int points;
	int x,y;
	int totalBullets;
	int currentBullets;
	
	public:
		Play();
		
		void totalBulletss(int tb){
			totalBullets = tb;
		}
		
		void currentBulletss(int cb){
			currentBullets = cb;
		}
		
		void addPoints(int newPoints){
			points = newPoints;
		}
		
		void changeLife(int newLife){
			life = newLife;
		}
				
		void createBackground(void){
			setbkcolor(CYAN);
		}
		
		void createLife(void){
			setcolor(WHITE);	
			//create life bars
		
						
					char msg[128];
					sprintf(msg, "POINTS: %d", points);
					char msg2[128];
					sprintf(msg2, "%d/", currentBullets);
					char msg3[128];
					sprintf(msg3, "%d ", totalBullets);
					//outtextxy(xmin, ymid, msg);				
					
					settextstyle(10,0,2);
					outtextxy(10,10,"LIFE");
					outtextxy(10,40,msg);
					outtextxy(500,10,msg2);
					outtextxy(535,10,msg3);
				
				for(int counter = life, lifeX = 0; counter > 0; counter--, lifeX+=20){
					if (life == 3){
						setfillstyle(1,BLUE);	
					}else if (life == 2){
						setfillstyle(1,13);	

					}else if (life == 1){
						setfillstyle(1,RED);
					}
					
					circle(90+lifeX,20,6);
					floodfill(91+lifeX,21,WHITE);
					
				}
			
		}
		
		void createOrderBars(void){
		
			setcolor(8);
			
			for (int numberOfBars = 5, tempYY = 0; numberOfBars > 0; numberOfBars--, tempYY+=60){
				setfillstyle(1,8);
				rectangle(10,100+tempYY,620,110+tempYY);
				floodfill(11,101+tempYY,8);
	
				setfillstyle(1,8);
				pieslice(10,105+tempYY,90,270,5);
			
				setfillstyle(1,8);
				pieslice(620,105+tempYY,270,90,5);		
			}
			setcolor(6);
		}
		
		void createSmallStore(int ex){
			x +=ex;
			//setfillstyle(1,6);
			//rectangle(300,420,310,470);
			//floodfill(301,421,6);
			
			
			setcolor(6);
			Point pointa (40,60);
			Point pointb (43,60);
			Point pointc (43,10);
			Point pointd (42,5);
			Point pointe (40,10);
			Point pointf (40,60);
			
			vector<Point> pointsss;
			pointsss.push_back(pointa);
			Draw dr(pointsss,1);	
				
			dr.moveTo(pointa.getX()+x,pointa.getY()+y);
	    	dr.lineTo(pointb.getX()+x,pointb.getY()+y);
	    	dr.lineTo(pointc.getX()+x,pointc.getY()+y);
	    	dr.lineTo(pointd.getX()+x,pointd.getY()+y);
	    	dr.lineTo(pointe.getX()+x,pointe.getY()+y);
	    	dr.lineTo(pointf.getX()+x,pointf.getY()+y);
	    		
	    	int i = 0;
	    	while(true){
	    		
	    		if (pointa.getX()+x+i > pointb.getX()+x){
	    			break;
				}else{
					dr.moveTo(pointa.getX()+x+i, pointa.getY()+y);
		    		dr.lineTo(pointe.getX()+x+i, pointe.getY()+y);	
				}			
				i++;
			}
			dr.moveTo(42+x,10+y);
			dr.lineTo(42+x,5+y);
			dr.moveTo(41+x,10+y);
			dr.lineTo(42+x,5+y);
			
			setcolor(15);
			
			circle(42+x,20+y,6);
	    	setfillstyle(SOLID_FILL,WHITE);
	    	floodfill(42+x,20+y,WHITE);
	    	
	    	setcolor(15);
			
			circle(42+x,32+y,6);
	    	setfillstyle(SOLID_FILL,WHITE);
	    	floodfill(42+x,32+y,WHITE);
	    	
	    	setcolor(15);
			
			circle(42+x,44+y,6);
	    	setfillstyle(SOLID_FILL,WHITE);
	    	floodfill(42+x,44+y,WHITE);
			
		}
		
		int getShooterX(void){
			return x+43;
		}
		int getShooterY(void){
			return y+60;
		}
	
};

Play::Play(){
	//nothing
	life = 3;
	points = 0;
	x = 263;
	y = 405;
	totalBullets = 20;
	currentBullets = 0;
}

//bullet class is the bullet itself and what it can do

class Bullet{
	int x, y;
	int bulletSpeed;
	public:
		Bullet();
		
		void setBullet(int exx, int way){
			x = exx;
			y = way;
		}
		
		void moveBullet(){
			setcolor(6);
			Point pointa (40,60);
			Point pointb (43,60);
			Point pointc (43,10);
			Point pointd (42,5);
			Point pointe (40,10);
			Point pointf (40,60);
			
			vector<Point> pointsss;
			pointsss.push_back(pointa);
			Draw dr(pointsss,1);	
				
			dr.moveTo(pointa.getX()+x,pointa.getY()+y-bulletSpeed);
	    	dr.lineTo(pointb.getX()+x,pointb.getY()+y-bulletSpeed);
	    	dr.lineTo(pointc.getX()+x,pointc.getY()+y-bulletSpeed);
	    	dr.lineTo(pointd.getX()+x,pointd.getY()+y-bulletSpeed);
	    	dr.lineTo(pointe.getX()+x,pointe.getY()+y-bulletSpeed);
	    	dr.lineTo(pointf.getX()+x,pointf.getY()+y-bulletSpeed);
	    		
	    	int i = 0;
	    	while(true){
	    		
	    		if (pointa.getX()+x+i > pointb.getX()+x){
	    			break;
				}else{
					dr.moveTo(pointa.getX()+x+i, pointa.getY()+y-bulletSpeed);
		    		dr.lineTo(pointe.getX()+x+i, pointe.getY()+y-bulletSpeed);	
				}			
				i++;
			}
			dr.moveTo(42+x,10+y-bulletSpeed);
			dr.lineTo(42+x,5+y-bulletSpeed);
			dr.moveTo(41+x,10+y-bulletSpeed);
			dr.lineTo(42+x,5+y-bulletSpeed);
			
			setcolor(15);
			
			circle(42+x,20+y-bulletSpeed,6);
	    	setfillstyle(SOLID_FILL,WHITE);
	    	floodfill(42+x,20+y-bulletSpeed,WHITE);
	    	
	    	setcolor(15);
			
			circle(42+x,32+y-bulletSpeed,6);
	    	setfillstyle(SOLID_FILL,WHITE);
	    	floodfill(42+x,32+y-bulletSpeed,WHITE);
	    	
	    	setcolor(15);
			
			circle(42+x,44+y-bulletSpeed,6);
	    	setfillstyle(SOLID_FILL,WHITE);
	    	floodfill(42+x,44+y-bulletSpeed,WHITE);
			
			bulletSpeed+=4;
			
		}
		
		int getX(void){
			return x;
		}
		int getY(void){
			return y-bulletSpeed;
		}
		
};

Bullet::Bullet(){
	x = 0;
	y = 0;
	bulletSpeed = 10;
}


int main(int argc, char** argv) {
	
	//variables
	int page = 0; 
	int display = 1;	//display determines whether the program goes to the menu, game over or the play mode
	int choiceMenu = 1; //choice menu determines where the the pointer is pointing
	int tempChoice = 1; // tempChoice is not the final choiceMenu
	int leftOrRight = 0; // leftOrRight determines the direction of the pointer
	int life = 3; // life is the number of lives of the player
	int movementX = 0; //movement of the shotoer 
	int currentShooterX = 262+movementX;; //where the current shooter's x lies
	int currentShooterY; //where the current shooter's y lies
	int speedChange = 5; //the change in speed
	int boxCounter = 0; //counter of the boxes to determine speed
	int points = 0; // points gained: 10 each hit, points lost: -5 each wasted bullet
	int limitedBullet = 10; // number of limited bullets
	int currentBullets = 0; // current used bullets
	bool musicPlay = false;
	
	vector<Order> orders; //list of orders
	vector<Bullet> bullets; //list of bullets
	
	//opening window
	int gd = DETECT,gm;
	initgraph(&gd, &gm, "C:\\TC\\bgi");
	
	Menu mainMenu;
	while(1){
		
		setactivepage(page);
		setvisualpage(1-page);
		cleardevice();
			
		if (display == 1){
		//MAIN MENU
		
		//Menu mainMenu;
		mainMenu.createBackground();
		mainMenu.createStore();
		mainMenu.createTextMenu();
		
		//to determine the choicemenu or where it would go next
		
		if (choiceMenu == 1){
			mainMenu.choice(110,180);
		}else if (choiceMenu == 2){
			mainMenu.choice(270,180);
		}
		
		if(GetAsyncKeyState(VK_LEFT)){
			if (choiceMenu == 2){
				choiceMenu = 1;
			}
		}else if(GetAsyncKeyState(VK_RIGHT)){
			if (choiceMenu == 1){
				choiceMenu = 2;
			}
		}
		
		if(GetAsyncKeyState(VK_SPACE)){
			display = choiceMenu+1;
		}
		
		
		//creating background
		
			
		}else if (display == 2){
			//play mode
			
		
			
			setactivepage(page);
			setvisualpage(1-page);
			cleardevice();
			
			//creating the constant displays
			Play play;
			play.addPoints(points);	
			play.changeLife(life);
			play.currentBulletss(currentBullets);
			play.totalBulletss(limitedBullet);

			play.createBackground();
			play.createLife();
			play.createOrderBars();
			
			// if the shooter moves
			if(GetAsyncKeyState(VK_LEFT) && currentShooterX > 0){
				movementX-=5;
				currentShooterX = 262+movementX;
			}else if(GetAsyncKeyState(VK_RIGHT) && currentShooterX < 560){
				movementX+=5;
				currentShooterX = 262+movementX;
			}
			if(GetAsyncKeyState(VK_SPACE) && bullets.size() < limitedBullet){
				Bullet tempBullet;
				tempBullet.setBullet(currentShooterX, 400);
				//create bullets	
				bullets.push_back(tempBullet);
				//printf("pressed space");
				currentBullets++;
			
			}
			vector<int> toDelete;
			
			//method to find out which bullets hit orders
			
			for (int b = 0; b < bullets.size(); b++){
				for (int o = 0; o < orders.size();o++){
					if ((bullets[b].getX()+252) > orders[o].getLeft() && (bullets[b].getX()+252) < orders[o].getRight() && (bullets[b].getY()+7) > orders[o].getTop() && (bullets[b].getY()+7) < orders[o].getBottom()){
						//add to to be deleted
						points+=10;
						orders.erase(orders.begin()+o);
						o--;
						toDelete.push_back(b);		
					}
				}
				
			}
			
			//delete unnecesary bullets
			
			for (int bb = 0; bb < toDelete.size(); bb++){
				if (toDelete[bb] == 0){
					bullets.erase(bullets.begin()+0);
				}else{
					bullets.erase(bullets.begin()+(toDelete[bb]-bb));				
				}
			}
			
			for (int t = 0; t < bullets.size(); t++){
				if (bullets[t].getY() <= 0){
					bullets.erase(bullets.begin()+t);
					points-=5;
					t--;
				}else{
					bullets[t].moveBullet();	
				}
			}
			currentBullets = bullets.size();
			play.createSmallStore(movementX);
			
			//orders
						
			if (orders.size() == 0){
				Order orderr;
				orders.push_back(orderr);
			}
			
			for (int i = 0; i < orders.size(); i++){
				orders[i].create();
			}
			bool createNew = true;
			
			for (int z = 0; z < orders.size(); z++){
				if (orders[z].getX() < 100 && orders[z].getY() == 105){
			
						createNew = false;
				}					
			}
			
			//everytime a new order is needed
			
			if (createNew){
				Order ordertemp;
				orders.push_back(ordertemp);
				boxCounter++;
				if (boxCounter%20 == 0){
					speedChange+=3;
					if (limitedBullet < 20){			
						limitedBullet+=5;
					}			
				}
			}
			
			//if shooter is hit by order
			for (int u = 0; u < orders.size();u++){
				orders[u].setSpeed(speedChange);
				if (orders[u].getState() == 6){
					if (orders[u].getLeftX()-25 <= currentShooterX){
						life--;
						play.changeLife(life);
						orders.erase(orders.begin()+u);
						break;
					}
				}
			}

			if (life <= 0){
				display = 3;
			}
			
		}else if (display == 3){
			
			
			setactivepage(page);
			setvisualpage(1-page);
			cleardevice();
			
			setbkcolor(LIGHTBLUE);
			mainMenu.createStore();
			
			char message[128];
			sprintf(message, "%d",points);			
					
			settextstyle(10,0,5);
			outtextxy(190,80,"GAME OVER!");
			outtextxy(240,160,"SCORE");
			outtextxy(270,230,message);
			settextstyle(10,0,2);
			outtextxy(170,330,"press enter to continue...");
			
			if(GetAsyncKeyState(VK_RETURN)){
				break;
			}
			
		}
		
		page = 1-page;
		delay(40);
	
			
	}
	getch();
	
	
	return 0;
}
