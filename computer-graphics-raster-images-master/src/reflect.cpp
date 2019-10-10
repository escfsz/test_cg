#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i < width; i++)
  {
	  for (int j = 0; j < height; j++) {
		  
		  for(int k = 0;k<num_channels;k++){

			reflected[(j*width + width - 1 - i)*num_channels+k] = input[(j*width + i)*num_channels+k];
		  }
	  }
  }
}
