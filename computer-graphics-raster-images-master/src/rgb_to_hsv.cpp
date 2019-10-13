#include "rgb_to_hsv.h"
#include <math.h>
#include <algorithm>

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
	double cmax = std::max(r, std::max(g, b));
	double cmin = std::min(r, std::min(g, b));
	double delta = cmax - cmin;
	double epislon = 0.0001;
	if (fabs(delta) < epislon) {
		h = 0;
	}
	else
	{
		if (fabs(cmax - r) < epislon && g>=b) {
			h = 60 * ((g - b) / delta + 0);
		}
		else if (fabs(cmax - r) < epislon && g<b) {
			h = 60 * ((g - b) / delta + 6);
		}
		else if(fabs(cmax - g)<epislon)
		{
			h = 60 * ((b - r) / delta + 2);
		}
		else if(fabs(cmax - b)<epislon)
		{
			h = 60 * ((r - b) / delta + 4);
		}
	}

	if (fabs(cmax - 0) < epislon) {
		s = 0;
	}
	else
	{
		s = delta / cmax;
	}

	v = cmax;
  ////////////////////////////////////////////////////////////////////////////
}
