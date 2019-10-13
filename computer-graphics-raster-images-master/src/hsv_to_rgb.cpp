#include "hsv_to_rgb.h"
#include <math.h>
#include <iostream>
void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:

	int h1 = (int)(h / 60)%6;
	double f = h / 60 - h1;
	double p = v * (1 - s);
	double q = v * (1 - f * s);
	double t = v * (1 - (1 - f)*s);

	switch (h1)
	{
	case 0:
		r = v;		g = t;		b = p;
		break;
	case 1:
		r = q;		g = v;		b = p;
		break;
	case 2:
		r = p;		g = v;		b = t;
		break;
	case 3:
		r = p;		g = q;		b = v;
		break;
	case 4:
		r = t;		g = p;		b = v;
		break;
	case 5:
		r = v;		g = p;		b = q;
		break;

	default:
		std::cout << h1 << std::endl;
		std::cout << "wrong" << std::endl;
		break;
	}
  ////////////////////////////////////////////////////////////////////////////
}
