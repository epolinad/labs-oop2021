#include <iostream>
#include "Deltoida.h"
#include "menu.h"
int _tmain(int argc, char* argv[])
{
	Prog2::Deltoida c(2, 1, 2);
	Prog2::Point p(3);
	int fl1 = 1;
	double r;
	char* s = NULL;
	while (fl1) {
		std::cout << "Your Deltoida is:" << std::endl;
		s = c.frm();
		std::cout << s << std::endl;
		delete[] s;
		std::cout << "area: " << c.area() << std::endl;
		std::cout << "perimeter: " << c.perimeter() << std::endl;
		std::cout << "intersection lenght: " << c.intersection_length() << std::endl;
		int fl2 = 1;
		while (fl2) {
			std::cout << "Enter t for calculate value x(t) and y(t) or precc ctrl+Z to quit:" <<
				std::endl;
			double x;
			Prog2::Point y;
			std::cin >> x;
			fl2 = std::cin.good();
			if (!fl2)
				continue;
			try {
				y = c.coord(x);
				std::cout << "x = " << y.x << ", y = " << y.y << std::endl;
			}

				catch (std::exception& ex)
			{
				std::cout << ex.what() << std::endl;
			}
		}
		std::cin.clear();
		std::cout << "Enter new x, y and r to continue or press ctrl+Z to quit:" << std::endl;
		std::cin >> p.x >> p.y >> r;
		if (std::cin.good()) {
			c.setP(p);
			try {
				c.setR(r);
			}
			catch (std::exception& ex)
			{
				std::cout << ex.what() << std::endl;
			}
		}
		else
			fl1 = 0;
	}
	return 0;
}
