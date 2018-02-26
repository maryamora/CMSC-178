#include <windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;
#define PI 3.14159265

void drawLine(HDC hdc, int pointAX, int pointAY, int pointBX, int pointBY, COLORREF color){
	int midCirX, midCirY, topMidAX, topMidAY, rightMidAX, rightMidAY;
	int radiusOne, radiusTwo;
	
	for (int i = pointAX; i < pointBX; i++){
	    SetPixel(hdc, i, pointAY, color);
	    SetPixel(hdc, i, pointBY, color);

	}
	for (int i = pointAY; i < pointBY; i++ ){
	    SetPixel(hdc, pointAX, i, color); 
	    SetPixel(hdc, pointBX, i, color); 

	}
	
	//drawCircle
	
	midCirX = (pointAX + pointBX)/2;
	midCirY = (pointAY + pointBY)/2;
	
	topMidAX = midCirX;
	topMidAY = pointAY;
	
	rightMidAX = pointBX;
	rightMidAY = midCirY;
	
	radiusOne = sqrt(((topMidAX - midCirX) * (topMidAX - midCirX) ) + ((topMidAY - midCirY)*(topMidAY - midCirY)));
	radiusTwo = sqrt(((rightMidAX - midCirX) * (rightMidAX - midCirX) ) + ((rightMidAY - midCirY)*(rightMidAY - midCirY) ));
	
	int x, y;
	for (int i = 0; i <= (360*2); i++){
		x = (midCirX + radiusOne * cos(i) );
		y = (midCirY + radiusTwo * sin(i));
	    SetPixel(hdc, x, y, color); 

	}
}


void drawCircle(HDC hdc, int centerX, int centerY, int radiusOne, int radiusTwo, COLORREF color){
	int x, y;
	for (int i = 0; i <= (360*2); i++){
		x = (centerX + radiusOne * cos(i) );
		y = (centerY + radiusTwo * sin(i));
	    SetPixel(hdc, x, y, color); 

	}
}

void endProgram(HWND hwnd, HDC hdc){
	
	ReleaseDC(hwnd, hdc); 
    DeleteDC(hdc); 
    cout << endl << endl;
	system("pause");
	
}

int main()
{
	string line;
	int pointAX = 0, pointAY = 0, pointBX = 0, pointBY = 0;
	int centerX, centerY, radiusOne, radiusTwo; 
	int choice = 0;
	HWND hwnd;
	HDC hdc;
	

    COLORREF color = RGB(255,0,0); // COLORREF to hold the color info

    SetConsoleTitle("main"); // Set text of the console so you can find the window

    hwnd = FindWindow(NULL, "main"); // Get the HWND

    hdc = GetDC(hwnd); // Get the DC from that HWND

	
	endProgram(hwnd,hdc);
	
	
    SetConsoleTitle("main"); // Set text of the console so you can find the window

    hwnd = FindWindow(NULL, "main"); // Get the HWND

    hdc = GetDC(hwnd); // Get the DC from that HWND

	
	system("CLS");
		
	cout << "Enter point A: " << endl << endl << "x: ";
	cin >> pointAX;
	cout << "y: ";
	cin >> pointAY;
	
	system("CLS");
	
	cout << "Enter point B: " << endl << endl << "x: ";
	cin >> pointBX;
	cout << "y: ";
	cin >> pointBY;
	

   	system("CLS");	
	while(1){
		drawLine(hdc, pointAX, pointAY, pointBX, pointBY, color);
		getline( cin, line );
    	if (!line.empty()) break;
	}	

	system("CLS");

	color = RGB(0,0,0); // COLORREF to hold the color info
	drawLine(hdc, pointAX, pointAY, pointBX, pointBY, color);
	
	endProgram(hwnd, hdc);   
	
    color = RGB(255,0,0); // COLORREF to hold the color info

    SetConsoleTitle("main"); // Set text of the console so you can find the window

    hwnd = FindWindow(NULL, "main"); // Get the HWND

    hdc = GetDC(hwnd); // Get the DC from that HWND

	cout << "Press 1 to create a circle and 0 to exit" << endl;
	cin >> choice;
	
	system("CLS");
	
	if (choice){
		cout << "Enter center point"<<endl<<"x: ";
		cin >> centerX;
		cout << "y: ";
		cin >> centerY;
		
		cout << "Enter radius one: ";
		cin >> radiusOne;
		cout << "y: ";
		cin >> radiusTwo;
		
		system("CLS");
		
		while(1){
			
			drawCircle(hdc,centerX, centerY, radiusOne, radiusTwo, color);
			getline( cin, line );
    		if (!line.empty()) break;
	
		}	
		
	}else{
		cout << "goodbye";
		return 0;
	}
	
	endProgram(hwnd, hdc);	

    return(0);
}
