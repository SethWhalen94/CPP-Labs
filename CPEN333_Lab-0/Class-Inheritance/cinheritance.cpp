#include <stdio.h>

class Polygon
{
private:
	int m_width, m_height;

public:
	Polygon(int w, int h): m_width(w), m_height(h){}	//Constructor
	int get_width(void) { return m_width; }				//Getters
	int get_height(void) { return m_height; }
	void set_width(int w) { m_width = w; }				//Setters
	void set_height(int h) { m_height = h; }
};

class Rectangle : public Polygon {

public:
	Rectangle(int x, int y) : Polygon(x, y){}					//calls base constructor in Polygon
	int get_area(void) { return get_width() * get_height(); }	//calls member functions inherited from Polygon class

};

class Triangle : Polygon {

public:
	Triangle(int a, int b) : Polygon(a, b){}						//calls base constructor
	int get_area(void) { return get_width() * get_height() / 2; }	//calls inherited functions

};

int main()
{

	return 0;
}