#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i < width; i++)
  {
	  for (int j = 0; j < height; j++) {

		  if (i % 2 == 0 && j % 2 == 0) {  //G
			  bayer[j*width + i] = rgb[(j*width + i) * 3 + 1];
		  }
		  else if(i%2 == 0 && j%2 != 0)//R
		  {
			  bayer[j*width + i] = rgb[(j*width + i) * 3 ];
		  }
		  else if(i%2 != 0 && j%2 == 0)//B
		  {
			  bayer[j*width + i] = rgb[(j*width + i) * 3 + 2];
		  }
		  else if(i%2 != 0 && j%2 != 0)//G
		  {
			  bayer[j*width + i] = rgb[(j*width + i) * 3 + 1];
		  }


	  }
  }
}
