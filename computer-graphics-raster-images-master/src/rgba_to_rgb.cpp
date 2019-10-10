#include "rgba_to_rgb.h"

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i < width; i++) {
	  for (int j = 0; j < height; j++) {
		  rgb[(j*width + i)*3] = rgba[(j*width + i) * 4];//r
		  rgb[(j*width + i) * 3 + 1] = rgba[(j*width + i) * 4 + 1];
		  rgb[(j*width + i) * 3 + 2] = rgba[(j*width + i) * 4 + 2];
	  }
  }
}
