#ifndef _DELTOIDA_H_
#define _DELTOIDA_H_
#include <math.h>
namespace Prog2 {

	struct Point {
		double x, y; 
		Point(double x0 = 0, double y0 = 0) :x(x0), y(y0) {}
	};
	
	class Deltoida {
	private:
		Point p; 
		double r; 
	public:
		Deltoida(double rad = 1); 
		Deltoida(const Point& p0, double rad = 1); 
		Deltoida(double x0, double y0, double rad = 1); 
		
		Deltoida& setP(const Point& p0) { p = p0; return *this; }
		Deltoida& setR(double r0);
	
		Point getP() const { return p; }
		double getR() const { return r; }
		
		double area() const { return 3.14159 * r * r * 2.0; } // vernutj ploshtj ogranich kriv
		double perimeter() const { return 16.0 * r; } //dlina krivoj (16/3*3r)

		Point coord (double t) const; // vernutj znach coord x i y d zavis ot t
		double intersection_length() const { return 4 * r; } 
			char* frm() const; 
	};
}
#endif
