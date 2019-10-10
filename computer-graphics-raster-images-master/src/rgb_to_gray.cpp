#include "rgb_to_gray.h"

void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.resize(height*width);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i < width; i++)
  {
	  for (int j = 0; j < height; j++) {

			   auto grayVal = 2126 *rgb[(j*width + i)*3] + 7152 * rgb[(j*width + i) * 3 + 1] + 722 * rgb[(j*width + i) * 3 + 2] + 5000;
			   gray[(j*width + i)] = grayVal/10000;
		  }
	  }
 }



