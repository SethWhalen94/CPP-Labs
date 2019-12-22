//Example using reference to a class object
#include<iostream>
#include <stdio.h>

class Rectangle {
	int m_width, m_height;

public:
	Rectangle(int width, int height) : m_width(width), m_height(height){}		//Constructor

	int get_area(void) {

		return m_width * m_height;
	}

};

int main()
{
	Rectangle r1(3, 4);

	Rectangle &rp1 = r1;

	std::cout << "r1's area = " << r1.get_area() << std::endl;
	std::cout << "r1's reference area = " << rp1.get_area();


}