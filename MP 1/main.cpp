#include <windows.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void drawLine(HDC hdc, int pointAX, int pointAY, int pointBX, int pointBY, COLORREF color){
	
	for (int i = pointAX; i < pointBX; i++){
	    SetPixel(hdc, i, pointAY, color); // SetPixel(HDC hdc, int x, int y, COLORREF color)
	    SetPixel(hdc, i, pointBY, color); // SetPixel(HDC hdc, int x, int y, COLORREF color)

	}
	for (int i = pointAY; i < pointBY; i++ ){
	    SetPixel(hdc, pointAX, i, color); // SetPixel(HDC hdc, int x, int y, COLORREF color)
	    SetPixel(hdc, pointBX, i, color); // SetPixel(HDC hdc, int x, int y, COLORREF color)

	}

	
	/*
	for( int i = 0 ; i < 100 ; i++ )
    {
    SetPixel(hdc, i, 12, color); // SetPixel(HDC hdc, int x, int y, COLORREF color)
    }
	*/
}

void endProgram(HWND hwnd, HDC hdc){
	
	ReleaseDC(hwnd, hdc); // Release the DC
    DeleteDC(hdc); // Delete the DC
    cout << endl << endl;
	system("pause");
	
}

int main()
{
	string line;
	int pointAX = 0, pointAY = 0, pointBX = 0, pointBY = 0;
	int radiusOne, radiusTwo; 
	
	cout << "Enter point A: " << endl << endl << "x: ";
	cin >> pointAX;
	cout << "y: ";
	cin >> pointAY;
	
	system("CLS");
	
	cout << "Enter point B: " << endl << endl << "x: ";
	cin >> pointBX;
	cout << "y: ";
	cin >> pointBY;
	
    COLORREF color = RGB(255,0,0); // COLORREF to hold the color info

    SetConsoleTitle("Draw"); // Set text of the console so you can find the window

    HWND hwnd = FindWindow(NULL, "Draw"); // Get the HWND

    HDC hdc = GetDC(hwnd); // Get the DC from that HWND

   	system("CLS");	
	while(1){
		drawLine(hdc, pointAX, pointAY, pointBX, pointBY, color);
		getline( cin, line );
    	if (!line.empty()) break;
	}	
	
	endProgram(hwnd, hdc);	
	
    return(0);
}
