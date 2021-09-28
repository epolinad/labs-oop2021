#include <strstream>
#include <stdio.h>
#include <string.h>
#include "Deltoida.h"
namespace Prog2 {
	
	Deltoida::Deltoida(double rad) :p(0, 0) 
	{
		if (rad < 0)
			throw std::exception("invalid radius");
		r = rad;
	}
	Deltoida::Deltoida(const Point& p0, double rad) :p(p0) 
	{
		if (rad < 0)
			throw std::exception("invalid radius");
		r = rad;
	}
	Deltoida::Deltoida(double x0, double y0, double rad) :p(x0, y0) 
		
	{
		if (rad < 0)
			throw std::exception("invalid radius");
		r = rad;
	}
	
	Deltoida& Deltoida::setR(double r0)
	{
		if (r0 < 0)
			throw std::exception("invalid radius");
		r = r0;
		return *this;
	}
	Point Deltoida::coord(double t) const 
	{
		Point res;
		res.x = 2 * r * cos(t) + r * cos(2 * t) + p.x;
		res.y = 2 * r * sin(t) - r * sin(2 * t) + p.y;
		return res;
	}
	char* Deltoida::frm() const 
	{

		const char* s1 = "{x = cos(t) + cos(2t) + , y = sin(t) - sin(2t) + }\n";
		int l = strlen(s1) + 1; 
		size_t Size = 20;
		// schitajem skok nuzno mesta pod chisla
		char num[20]; 
		sprintf_s(num, 20, "%.2f", p.x);
		l += strlen(num);
		sprintf_s(num, 20, "%.2f", p.y); 
		l += strlen(num);
		sprintf_s(num, 20, "%.2f", r); 
		l += strlen(num) * 2;
		sprintf_s(num, 20, "%.2f", 2*r);
		l += strlen(num) * 2;

		char* s = new char[l];
		
		sprintf_s(s, l, "{x = %.2fcos(t) + %.2fcos(2t) + %.2f, y = %.2fsin(t) - %.2fsin(2t) + %.2f}", 2*r, r, p.x, 2*r, r, p.y);
		return s;
	}
}
