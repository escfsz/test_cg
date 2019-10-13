#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  for (int i = 0; i < width; i++)
  {
	  for (int j = 0; j < height; j++) {
		  double r = rgb[(j * width + i) * 3] * 1.0 / 255;
		  double g = rgb[(j * width + i) * 3 + 1] * 1.0 / 255;
		  double b = rgb[(j * width + i) * 3 + 2] * 1.0 / 255;
		  double h, s, v;
		  rgb_to_hsv(r, g, b, h, s, v);
		  //not right
		  s = factor * s;

		  hsv_to_rgb(h, s, v, r, g, b);
		  desaturated[(j * width + i) * 3] = (int)(r * 255);
		  desaturated[(j * width + i) * 3 + 1] = (int)(g * 255);
		  desaturated[(j * width + i) * 3 + 2] = (int)(b * 255);
	  }
  }
}
