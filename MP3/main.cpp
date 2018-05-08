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
		cout << "Create"<<endl<<" 1. Circle/Oval"<<endl<<" 2. A polygon with more than 3 sides"<<endl<<" 3. Create Graphics"<<endl<<" 4. Bezier Curve "<<endl<<" 5. Exit"<<endl<<"What's your choice?: ";
		cin >> choice;
	}while(choice < 1 || choice > 5);
	
	
	if (choice == 1){
		
		int centerX = 0, centerY = 0;
		int radii1 = 0, radii2 = 0;
		
		system("cls");
		cout << "Enter center x: ";
		cin >> centerX;
		cout << "Enter center y: ";
		cin >> centerY;
		
		cout << "Enter radii 1: ";
		cin >> radii1;
		cout << "Enter radii 2: ";
		cin >> radii2;
		
		
		cout << "Enter number of points: "; //360*2 for perfect circle/oval
		cin >> numberOfPoints;
		
		cout << "Enter number of lines: "; //180*2 for perfect circle/oval
		cin >> numberOfLines;
		
		int gd = DETECT, gm, x, y;
		struct arccoordstype a, b;
  		initgraph(&gd, &gm, "C:\\TC\\BGI");
	
		
		Point firstPoint(centerX + radii1, centerY);
		Point centerPoint(centerX, centerY);
		points.push_back(firstPoint);
		points.push_back(centerPoint);
		
		
		Draw draww (points, 2);
		draww.createPath();
		draww.moveTo(centerX+radii1, centerY);
		
		for (int i = 0; i < 360*2; i++){
			double angle = i * ((PI)/(180*2));
			draww.lineTo(centerX + radii1*cos(angle), centerY + radii2 * sin(angle));			
		}
		//draww.closePath();
		
		cout << "Finished."<<endl;
   		getch();
   		closegraph();
		
	}else if (choice == 2){
		cout << "Create a shape."<< endl <<  endl << "How many points are there? ";
		cin >> numberOfPoints;
	
		system("cls");
	
		for (int i = 0; i < numberOfPoints; i++){
			int exx, wayy;
			cout << "Enter x: ";
			cin >> exx;
			cout<<endl<<"Enter y: ";
			cin >> wayy;
			Point point(exx,wayy);
			points.push_back(point);
			system("cls");
		}
	
		for (int j = 0; j < numberOfPoints; j++){
			cout << "Element[" << j << "] = ";
			points[j].print();
		}
	
		int gd = DETECT, gm, x, y;
		struct arccoordstype a, b;
  		initgraph(&gd, &gm, "C:\\TC\\BGI");
	
		Draw drawthis(points,numberOfPoints);
		drawthis.createPath();
		for (int c = 0; c < (numberOfPoints-1); c++){
			drawthis.moveTo(points[c].getX(), points[c].getY());
			drawthis.lineTo(points[c+1].getX(), points[c+1].getY());
		}
		drawthis.closePath();
	

		cout << "Finished."<<endl;
   		getch();
   		closegraph();

	}else if (choice == 3){
		system("cls");
		cout << "Creating Graphics... "<<endl;
		system("pause");
		
		int gd = DETECT, gm, x, y;
		struct arccoordstype a, b;
  		initgraph(&gd, &gm, "C:\\TC\\BGI");
	
		//Creating G
		numberOfPoints = 2;
		Point pointOne(240,150);
		Point pointTwo (260,140);
		Point pointThree(210, 140);
		Point pointFour (160, 200);
		Point pointFive (210,200);
		Point pointSix (260,175);
		Point pointSeven (220, 175);
		Point pointEight (220,190);
		Point pointNine (240,190);
		Point pointTen (240,200);
		Point pointEleven (210, 200);
		Point pointTwelve (180,140);
		Point pointThirteen (210,140);
		points.push_back(pointOne);
		points.push_back(pointTwo);
		
		Draw drawing(points,numberOfPoints);
		drawing.createPath();
		drawing.lineTo(pointTwo.getX(),pointTwo.getY());
		int radius = 50;
		drawing.lineTo(pointThree.getX(),pointThree.getY(),0,180,radius);
		drawing.lineTo(pointFour.getX(),pointFour.getY());
		drawing.lineTo(pointFive.getX(),pointFive.getY(),180,0,radius);
		drawing.lineTo(pointSix.getX(), pointSix.getY());
		drawing.lineTo(pointSeven.getX(), pointSeven.getY());
		drawing.lineTo(pointEight.getX(), pointEight.getY());
		drawing.lineTo(pointNine.getX(), pointNine.getY());
		drawing.lineTo(pointTen.getX(), pointTen.getY());
		drawing.lineTo(pointEleven.getX(),pointEleven.getY(),180,0,30);
		drawing.moveTo(180,200);
		drawing.lineTo(pointTwelve.getX(),pointTwelve.getY());
		drawing.lineTo(pointThirteen.getX(),pointThirteen.getY(),0,180,30);
		drawing.moveTo(240,140);
		drawing.closePath();
		
		//drawing r
		Point pointR1(280,150);
		Point pointR2(280,250);
		Point pointR3(300,250);
		Point pointR4(300,175);
		Point pointR5(320,175);
		Point pointR6(360,165);
		Point pointR7(320,175);
		Point pointR8(290,149);
		Point pointR9(290,137);
		Point pointR10(280,137);
		
		drawing.createNewPath(pointR1.getX(),pointR1.getY());
		drawing.lineTo(pointR2.getX(),pointR2.getY());
		drawing.lineTo(pointR3.getX(),pointR3.getY());
		drawing.lineTo(pointR4.getX(),pointR4.getY());
		drawing.lineTo(pointR5.getX(),pointR5.getY(),0,180,20);
		drawing.moveTo(340,175);
		drawing.lineTo(pointR6.getX(),pointR6.getY());
		drawing.lineTo(pointR7.getX(),pointR7.getY(),13,140,40);
		drawing.moveTo(pointR8.getX(),pointR8.getY());
		drawing.lineTo(pointR9.getX(),pointR9.getY());
		drawing.lineTo(pointR10.getX(),pointR10.getY());


		drawing.closePath();
		
		//draw a
		Point pointA1(380,170);
		Point pointA2(460,170);
		Point pointA2Circ(420,170);
		Point pointA3(460,250);
		Point pointA4(440,250);
		Point pointA5(440,225);
		Point pointA6Circ(410,225);
		Point pointA6(380,225);
		Point pointA7(380,215);
		Point pointA8Circ(410,215);
		Point pointA8(440,215);
		Point pointA9(440,170);
		Point pointA10Circ(420,170);
		Point pointA10(400,170);

		
		drawing.createNewPath(pointA1.getX(),pointA1.getY());
		drawing.lineTo(pointA2Circ.getX(),pointA2Circ.getY(),0,180,40);
		drawing.moveTo(pointA2.getX(),pointA2.getY());
		drawing.lineTo(pointA3.getX(),pointA3.getY());
		drawing.lineTo(pointA4.getX(),pointA4.getY());
		drawing.lineTo(pointA5.getX(),pointA5.getY());
		drawing.lineTo(pointA6Circ.getX(),pointA6Circ.getY(),180,0,30);
		drawing.moveTo(pointA6.getX(),pointA6.getY());
		drawing.lineTo(pointA7.getX(),pointA7.getY());
		drawing.lineTo(pointA8Circ.getX(),pointA8Circ.getY(),0,180,30);
		drawing.moveTo(pointA8.getX(),pointA8.getY());		
		drawing.lineTo(pointA9.getX(),pointA9.getY());
		drawing.lineTo(pointA10Circ.getX(),pointA10Circ.getY(),0,180,20);
		drawing.moveTo(pointA10.getX(),pointA10.getY());
		drawing.closePath();
		drawing.lineTo(410,220,0,360,10);		

	//draw p
		Point pointp1(480,130);
		Point pointp2(480,300);
		Point pointp3(500,300);
		Point pointp4(500,250);
		Point pointp5Circ(500,190);
		
		drawing.createNewPath(pointp1.getX(),pointp1.getY());
		drawing.lineTo(pointp2.getX(),pointp2.getY());
		drawing.lineTo(pointp3.getX(),pointp3.getY());
		drawing.lineTo(pointp4.getX(),pointp4.getY());
		drawing.lineTo(pointp5Circ.getX(),pointp5Circ.getY(),270,110,62);
		
		drawing.moveTo(500,160);
		drawing.lineTo(500,220);
		drawing.lineTo(500,190,270,90,33);

		//drawing.closePath();
		//drawing h
		Point pointh1(582,130);
		Point pointh2(582,250);
		Point pointh3(602,250);
		Point pointh4(602,230);
		Point pointh5Circ(622,230);
		Point pointh5(642,230);
		Point pointh6(642,250);
		Point pointh7(662,250);
		Point pointh8(662,210);
		Point pointh9Circ(632,210);
		Point pointh9(602,210);
		Point pointh10(602,130);
		
		
		drawing.createNewPath(pointh1.getX(),pointh1.getY());
		drawing.lineTo(pointh2.getX(),pointh2.getY());
		drawing.lineTo(pointh3.getX(),pointh3.getY());
		drawing.lineTo(pointh4.getX(),pointh4.getY());
		drawing.lineTo(pointh5Circ.getX(),pointh5Circ.getY(),0,180,20);
		drawing.moveTo(pointh5.getX(),pointh5.getY());
		drawing.lineTo(pointh6.getX(),pointh6.getY());
		drawing.lineTo(pointh7.getX(),pointh7.getY());
		drawing.lineTo(pointh8.getX(),pointh8.getY());
		drawing.lineTo(pointh9Circ.getX(),pointh9Circ.getY(),0,180,30);
		drawing.moveTo(pointh9.getX(),pointh9.getY());
		drawing.lineTo(pointh10.getX(),pointh10.getY());
		drawing.closePath();
		
		//drawing i
		Point pointi1(682,175);
		Point pointi2(682,250);
		Point pointi3(702,250);
		Point pointi4(702,175);
		Point pointi5Circ(692,150);
		
		
		drawing.createNewPath(pointi1.getX(),pointi1.getY());
		drawing.lineTo(pointi2.getX(),pointi2.getY());
		drawing.lineTo(pointi3.getX(),pointi3.getY());
		drawing.lineTo(pointi4.getX(),pointi4.getY());
		drawing.closePath();
		drawing.lineTo(pointi5Circ.getX(),pointi5Circ.getY(),0,360,10);
						
		//drawing c

		Point pointc1(792,130);
		Point pointc2Circ(792,190);
		Point pointc2(792,250);
		Point pointc3(792,230);
		Point pointc4(792,150);
		Point pointc4Circ(792,190);

		drawing.createNewPath(pointc1.getX(),pointc1.getY());
		drawing.lineTo(pointc2Circ.getX(),pointc2Circ.getY(),90,270,60);
		drawing.moveTo(pointc2.getX(),pointc2.getY());
		drawing.lineTo(pointc3.getX(),pointc3.getY());
		drawing.lineTo(pointc4Circ.getX(),pointc4Circ.getY(),90,270,40);
		drawing.moveTo(pointc4.getX(),pointc4.getY());
		drawing.closePath();
		
		//drawing s
		
		Point points1(820,250);
		Point points2(852,250);
		Point points3Circ(852,220);
		Point points3(852,190);
		Point points4Circ(852,170);
		Point points4(852,150);
		Point points5(882,150);
		Point points6(882,130);
		Point points7(852,130);
		Point points8Circ(852,165);
		Point points8(852,190);
		Point points9Circ(852,215);
		Point points9(852,230);
		Point points10(820,230);
		
		drawing.createNewPath(points1.getX(),points1.getY());
		drawing.lineTo(points2.getX(),points2.getY());
		drawing.lineTo(points3Circ.getX(),points3Circ.getY(),270,90,30);
		drawing.moveTo(points3.getX(),points3.getY());
		drawing.lineTo(points4Circ.getX(),points4Circ.getY(),90,270,20);
		drawing.moveTo(points4.getX(),points4.getY());
		drawing.lineTo(points5.getX(),points5.getY());
		drawing.lineTo(points6.getX(),points6.getY());
		drawing.lineTo(points7.getX(),points7.getY());
		drawing.lineTo(points8Circ.getX(),points8Circ.getY(),90,270,35);
		drawing.moveTo(points8.getX(),points8.getY());
		drawing.lineTo(points9Circ.getX(),points9Circ.getY(),270,90,15);
		drawing.moveTo(points9.getX(),points9.getY());
		drawing.lineTo(points10.getX(),points10.getY());		
		drawing.closePath();
		
		cout << "Finished."<<endl;
   		getch();
   		closegraph();
		
	}else if (choice == 4){
		int p1x, p1y, p2x, p2y, c1x, c1y, c2x, c2y;
		
		system("cls");
		cout << "Bezier Curve"<<endl;
		cout << "Enter point 1: "<<endl;
		cout << "x: ";
		cin >> p1x;
		cout << "y: ";
		cin >> p1y;
		
		cout << "Enter point 2: "<<endl;
		cout << "x: ";
		cin >> p2x;
		cout << "y: ";
		cin >> p2y;
		
		cout << "Enter control point 1: "<<endl;
		cout << "x: ";
		cin >> c1x;
		cout << "y: ";
		cin >> c1y;
		
		cout << "Enter control point 2: "<<endl;
		cout << "x: ";
		cin >> c2x;
		cout << "y: ";
		cin >> c2y;
		
		int gd = DETECT, gm, x, y;
		struct arccoordstype a, b;
  		initgraph(&gd, &gm, "C:\\TC\\BGI");
		
		int newX, newY;
		for (float t = 0.001; t < 1; t = t + 0.001){
			newX = pow((1-t),3) * p1x + 3 * pow((1-t),2) * t * c1x + 3 * (1-t) * pow(t,2) *c2x + pow(t,3) * p2x;
			newY = pow((1-t),3) * p1y + 3 * pow((1-t),2) * t * c1y + 3 * (1-t) * pow(t,2) *c2y + pow(t,3) * p2y;
			putpixel(newX,newY,RED);
		}
		
		cout << "Finished."<<endl;
   		getch();
   		closegraph();
		
	}else{
		system("cls");
		cout << "Goodbye!"<<endl;
	}
	
   
}
