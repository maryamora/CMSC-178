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

//Draw Circle


int main(int argc, char** argv) {
	
	int numberOfPoints = 0;
	vector<Point> points;
	int choice = 0;
	int numberOfLines = 0;
	
	
	do{
		cout << "Choose: "<<endl<<"1. Fish ball"<<endl<<"2. Store"<<endl<<"3. Vendor"<<endl;
		cin >> choice;	
	}while (choice < 0);
	
	int gd = DETECT, gm, x, y;
	struct arccoordstype a, b;
  	initgraph(&gd, &gm, "C:\\TC\\BGI");
	
	
	if (choice == 1){
		setbkcolor(7);
		cleardevice();
		setcolor(6);
		
		Point point1 (100,500);
		Point point2 (500,100);
		Point point3 (510,95);
		Point point4 (507,105);
		Point point5 (100,510);
		Point pointCirc1(200,400);
		Point pointCirc2(300,300);
		Point pointCirc3(400,200);
		
		points.push_back(point1);
		points.push_back(point2);
		points.push_back(point3);
		points.push_back(point4);
		points.push_back(point5);

	
		Draw drawThis (points, 2);
		drawThis.createPath();
		drawThis.lineTo(point2.getX(),point2.getY());
		drawThis.lineTo(point3.getX(),point3.getY());
		drawThis.lineTo(point4.getX(),point4.getY());
		drawThis.lineTo(point5.getX(),point5.getY());
		
		for (int i = 0; i < 10; i++){
			//point 1 - 2
			drawThis.moveTo(point1.getX()+i,point1.getY());
			drawThis.lineTo(point2.getX()+i,point2.getY());
			//point 2 - 3
			drawThis.lineTo(point3.getX()-i,point3.getY()+i);
			//point 3 - 4
			drawThis.lineTo(point4.getX()-i,point4.getY());
			//point 4 - 5
			drawThis.lineTo(point5.getX()+i,point5.getY());
			//point 5 - 1
			drawThis.lineTo(point1.getX()+i,point1.getY());
		}
		
	//	drawThis.closePath();
		
		setcolor(15);

		circle(pointCirc1.getX(),pointCirc1.getY(),70);
    	setfillstyle(SOLID_FILL,WHITE);
		floodfill(pointCirc1.getX(),pointCirc1.getY(),WHITE);
		
		circle(pointCirc2.getX(),pointCirc2.getY(),70);
    	setfillstyle(SOLID_FILL,WHITE);
		floodfill(pointCirc2.getX(),pointCirc2.getY(),WHITE);
		
		circle(pointCirc3.getX(),pointCirc3.getY(),70);
    	setfillstyle(SOLID_FILL,WHITE);
		floodfill(pointCirc3.getX(),pointCirc3.getY(),WHITE);
		

		
		cout << "translate? press 1 for yes and 2 for no"<<endl;
		cin >> choice;
		
		if (choice == 1){
			setbkcolor(7);
			cleardevice();

			cout << "translate 50 points to the right";
			int translate = 1;
			for (translate = 1; translate < 50; translate++){
			setbkcolor(7);
			cleardevice();

	
			setcolor(6);
			point1.setX(point1.getX()+1);
			point2.setX(point2.getX()+1);
			point3.setX(point3.getX()+1);
			point4.setX(point4.getX()+1);
			point5.setX(point5.getX()+1);
			pointCirc1.setX(pointCirc1.getX()+1);
			pointCirc2.setX(pointCirc2.getX()+1);
			pointCirc3.setX(pointCirc3.getX()+1);
			
			points.push_back(point1);
			points.push_back(point2);
			points.push_back(point3);
			points.push_back(point4);
			points.push_back(point5);
	
		
			drawThis.moveTo(point1.getX(),point1.getY());
			drawThis.lineTo(point2.getX(),point2.getY());
			drawThis.lineTo(point3.getX(),point3.getY());
			drawThis.lineTo(point4.getX(),point4.getY());
			drawThis.lineTo(point5.getX(),point5.getY());
			
			for (int i = 0; i < 10; i++){			
				
				//point 1 - 2
				drawThis.moveTo(point1.getX()+i,point1.getY());
				drawThis.lineTo(point2.getX()+i,point2.getY());
				//point 2 - 3
				drawThis.lineTo(point3.getX()-i,point3.getY()+i);
				//point 3 - 4
				drawThis.lineTo(point4.getX()-i,point4.getY());
				//point 4 - 5
				drawThis.lineTo(point5.getX()+i,point5.getY());
				//point 5 - 1
				drawThis.lineTo(point1.getX()+i,point1.getY());
			}
			
			
			//	drawThis.closePath();
			
				setcolor(15);
		
				circle(pointCirc1.getX(),pointCirc1.getY(),70);
		    	setfillstyle(SOLID_FILL,WHITE);
				floodfill(pointCirc1.getX(),pointCirc1.getY(),WHITE);
				
				circle(pointCirc2.getX(),pointCirc2.getY(),70);
		    	setfillstyle(SOLID_FILL,WHITE);
				floodfill(pointCirc2.getX(),pointCirc2.getY(),WHITE);
				
				circle(pointCirc3.getX(),pointCirc3.getY(),70);
		    	setfillstyle(SOLID_FILL,WHITE);
				floodfill(pointCirc3.getX(),pointCirc3.getY(),WHITE);
				
				
			}
			
		}else{
			
		}
		
	}else if (choice == 2){
		
		setbkcolor(7);
		cleardevice();
		setcolor(0);
			
		Point point1 (100,25);
		Point point2 (530,25);
		Point point3 (555,75);
		Point point4 (75,75);
		
		vector<Point> pointss;
		
		pointss.push_back(point1);
		pointss.push_back(point2);
		
		Draw drawThis (pointss, 2);
		
		drawThis.createNewPath(point1.getX(),point1.getY());
		drawThis.lineTo(point2.getX(), point2.getY());
		drawThis.lineTo(point3.getX(), point3.getY());
		drawThis.lineTo(point4.getX(), point4.getY());
		drawThis.closePath();
		
		//
		
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
		
		drawThis.moveTo(point4.getX(), point4.getY());
		drawThis.lineTo(point5.getX(), point5.getY());
		drawThis.lineTo(point6.getX(), point6.getY());
		drawThis.lineTo(point7.getX(), point7.getY());
		drawThis.lineTo(point8.getX(), point8.getY());
		drawThis.lineTo(point9.getX(), point9.getY());
		drawThis.lineTo(point10.getX(), point10.getY());
		drawThis.lineTo(point11.getX(), point11.getY());
		drawThis.lineTo(point12.getX(), point12.getY());
		drawThis.lineTo(point13.getX(), point13.getY());
		drawThis.lineTo(point14.getX(), point14.getY());
		drawThis.lineTo(point15.getX(), point15.getY());
		drawThis.lineTo(point16.getX(), point16.getY());
		drawThis.lineTo(point17.getX(), point17.getY());
		drawThis.lineTo(point18.getX(), point18.getY());
		drawThis.lineTo(point19.getX(), point19.getY());
		drawThis.lineTo(point20.getX(), point20.getY());
		drawThis.lineTo(point21.getX(), point21.getY());
		drawThis.lineTo(point22.getX(), point22.getY());
		drawThis.lineTo(point23.getX(), point23.getY());
		drawThis.lineTo(point24.getX(), point24.getY());
		drawThis.lineTo(point25.getX(), point25.getY());
		drawThis.lineTo(point26.getX(), point26.getY());
		drawThis.lineTo(point27.getX(), point27.getY());
		drawThis.lineTo(point28.getX(), point28.getY());
		
		//
		
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
		
		
		drawThis.moveTo(point29.getX(), point29.getY());
		drawThis.lineTo(point30.getX(), point30.getY());
		drawThis.lineTo(point31.getX(), point31.getY());
		drawThis.lineTo(point32.getX(), point32.getY());
		drawThis.moveTo(point33.getX(), point33.getY());
		drawThis.lineTo(point34.getX(), point34.getY());
		drawThis.lineTo(point35.getX(), point35.getY());
		drawThis.lineTo(point36.getX(), point36.getY());
		drawThis.moveTo(point37.getX(), point37.getY());
		drawThis.lineTo(point38.getX(), point38.getY());
		drawThis.lineTo(point39.getX(), point39.getY());
		drawThis.lineTo(point40.getX(), point40.getY());
		drawThis.lineTo(point37.getX(), point37.getY());
		
	//
	
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
		
		
		
		drawThis.moveTo(point41.getX(), point41.getY());
		drawThis.lineTo(point42.getX(), point42.getY());
		drawThis.lineTo(point43.getX(), point43.getY());
		drawThis.lineTo(pointCircleA.getX(), pointCircleA.getY(),0,360,50);
		drawThis.moveTo(point44.getX(), point44.getY());
		drawThis.lineTo(point45.getX(), point45.getY());
		drawThis.lineTo(point46.getX(), point46.getY());
		drawThis.lineTo(point47.getX(), point47.getY());
		drawThis.lineTo(point48.getX(), point48.getY());
		drawThis.lineTo(point49.getX(), point49.getY());
		drawThis.lineTo(pointCirc50.getX(), pointCirc50.getY(),184,353,15);
		drawThis.moveTo(point49.getX(), point49.getY());
		drawThis.lineTo(point51.getX(), point51.getY());
		drawThis.lineTo(point46.getX(), point46.getY());
		
		int trans = 0;
		
		
		cout << "Transform how many points?";
		cin >> trans;
		
		setbkcolor(7);
		cleardevice();
		setcolor(0);
			
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
		drawThis.lineTo(point42.getX()+trans, point42.getY()+trans);
		drawThis.lineTo(point43.getX()+trans, point43.getY()+trans);
		drawThis.lineTo(pointCircleA.getX()+trans, pointCircleA.getY()+trans,0,360,50);
		drawThis.moveTo(point44.getX()+trans, point44.getY()+trans);
		drawThis.lineTo(point45.getX()+trans, point45.getY()+trans);
		drawThis.lineTo(point46.getX()+trans, point46.getY()+trans);
		drawThis.lineTo(point47.getX()+trans, point47.getY()+trans);
		drawThis.lineTo(point48.getX()+trans, point48.getY()+trans);
		drawThis.lineTo(point49.getX()+trans, point49.getY()+trans);
		drawThis.lineTo(pointCirc50.getX()+trans, pointCirc50.getY()+trans,184,353,15);
		drawThis.moveTo(point49.getX()+trans, point49.getY()+trans);
		drawThis.lineTo(point51.getX()+trans, point51.getY()+trans);
		drawThis.lineTo(point46.getX()+trans, point46.getY()+trans);
		
		
	}else if (choice == 3){
		
	}
	
	
	cout << "Finished."<<endl;
   	getch();
  	closegraph();	
   
}
