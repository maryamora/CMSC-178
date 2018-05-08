class Point {
    int x, y;
  public:
    Point ();
    Point (int,int);
    
    void print(void){
    	cout << "x: "<<x<<", y: "<<y<<"."<<endl;
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

