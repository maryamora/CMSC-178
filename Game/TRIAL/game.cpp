#include <iostream>
#include <graphics.h>
#include <vector>
#include <math.h>
#include <conio.h>

#define PI 3.14159265

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

//POINT

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

//DRAW

class Draw {

    	int numberOfPoints;
		int currentX, currentY;
		int startingPathX, startingPathY;
		vector<Point> points;
  	public:
    	Draw ();
    	Draw (vector<Point>,int);
    	   	
    	void drawCharacter(int x, int y){
    		setcolor(6);
			Point pointa (40,60);
			Point pointb (43,60);
			Point pointc (43,10);
			Point pointd (42,5);
			Point pointe (40,10);
			Point pointf (40,60);
			
			moveTo(pointa.getX()+x,pointa.getY()+y);
    		lineTo(pointb.getX()+x,pointb.getY()+y);
    		lineTo(pointc.getX()+x,pointc.getY()+y);
    		lineTo(pointd.getX()+x,pointd.getY()+y);
    		lineTo(pointe.getX()+x,pointe.getY()+y);
    		lineTo(pointf.getX()+x,pointf.getY()+y);
    		
    		int i = 0;
    		while(true){
    			
    			if (pointa.getX()+x+i > pointb.getX()+x){
    				break;
				}else{
					moveTo(pointa.getX()+x+i, pointa.getY()+y);
	    			lineTo(pointe.getX()+x+i, pointe.getY()+y);	
				}			
				i++;
			}
			moveTo(42+x,10+y);
			lineTo(42+x,5+y);
			moveTo(41+x,10+y);
			lineTo(42+x,5+y);
			
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
	
		void createNewPath(int x, int y){
    		startingPathX = x;
    		startingPathY = y;
			currentX = x;
			currentY = y;
		}
    
    	void print(void){
    		cout << "x: "<<currentX<<", y: "<<currentY<<"."<<endl;
		}
		
		void createPath(){
			currentX = points[0].getX();
			currentY = points[0].getY();
			startingPathX = points[0].getX();
    		startingPathY = points[0].getY();
			cout<<"current x: "<<currentX<<" current y: "<<currentY<<endl;
		}
		
		void moveTo(int ex, int way){
			currentX = ex;
			currentY = way;
			cout<<"current x: "<<currentX<<" current y: "<<currentY<<endl;

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

int main(int argc, char** argv) {
	int gd = DETECT, gm, x, y;
	struct arccoordstype a, b;
  	initgraph(&gd, &gm, "C:\\TC\\BGI");
  	vector<Point> points;
  	
  	setbkcolor(9);
	cleardevice();
	setcolor(6);
	

	
	Point bga (0,350);
	Point bgb (650,350);
	points.push_back(bga);
	
	Draw background (points,1);
	for (int i = 0; i <= 150; i++){
	background.moveTo(bga.getX(),bga.getY()+i);
	background.lineTo(bgb.getX(),bgb.getY()+i);
	}
	
	Draw characters (points,2);
	

	
	for (int counter = 0; counter < 600; counter = counter+50){
		characters.drawCharacter(counter,0);	
		delay(1000);
	}
	
	for (int counter = 550; counter >= 0; counter = counter-50){
		characters.drawCharacter(counter,60);	
		delay(1000);
	}
	
	for (int counter = 0; counter < 600; counter = counter+50){
		characters.drawCharacter(counter,120);	
		delay(1000);
	}
	
	for (int counter = 550; counter >= 0; counter = counter-50){
		characters.drawCharacter(counter,180);	                                    
		delay(1000);
	}
	
	for (int counter = 0; counter < 600; counter = counter+50){
		characters.drawCharacter(counter,240);	
		delay(1000);
	}
	
	
	
	
	
	
	getch();
  	closegraph();	
	
	return 0;
}
