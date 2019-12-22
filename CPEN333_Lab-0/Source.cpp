#include <iostream>
#include <stdio.h>

class Foo
{
private:
	int m_x, m_y;

public:
	/*Declaration of Class Foo functions*/
	Foo(Foo& copy);
	void set_value_x(int x);
	void set_value_y(int y);
	int get_value_x();
	int get_value_y();
	/*End of declarations*/

	Foo(int x = 1, int y = 2) : m_x(x), m_y(y){}	//Default Constructor
	
};

/*Definition of class Foo functions*/
Foo::Foo(Foo& copy) : m_x(copy.m_x), m_y(copy.m_y)	//Copy Constructor
{
}
void Foo::set_value_x(int x) {					//Set the value of m_x
	this->m_x = x;
};

void Foo::set_value_y(int y) {					//Set the value of m_y
	this->m_y = y;
}

int Foo::get_value_x() {
	return this->m_x;
}

int Foo::get_value_y() {
	return this->m_y;
}
/*End of Class Foo function definitions*/
int main()
{
	Foo bar1, bar2;

	bar1.set_value_x(0);
	bar1.set_value_y(1);
	bar2.set_value_x(2);
	bar2.set_value_y(3);
	

	std::cout <<
		bar1.get_value_x() <<
		bar1.get_value_y() <<
		bar2.get_value_x() <<
		bar2.get_value_y() <<
		'\n';

	Foo bar3(bar1);

	std::cout <<
		bar1.get_value_x() <<
		bar1.get_value_y() <<
		bar3.get_value_x() <<
		bar3.get_value_y() <<
		'\n';

	return 0;
}
