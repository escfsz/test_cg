#include "demosaic.h"

#define LEFT(Array,width,i,j)    (Array[(j)*(width) + (i-1)])
#define RIGHT(Array,width,i,j)   (Array[(j)*(width) + (i+1)])
#define UP(Array,width,i,j)   (Array[(j-1)*(width) + (i)])
#define DOWN(Array,width,i,j)   (Array[(j+1)*(width) + (i)])

#define LU(Array,width,i,j)   (Array[(j-1)*(width) + (i-1)])
#define RU(Array,width,i,j)   (Array[(j-1)*(width) + (i+1)])
#define LD(Array,width,i,j)   (Array[(j+1)*(width) + (i-1)])
#define RD(Array,width,i,j)   (Array[(j+1)*(width) + (i+1)])
void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  std::vector<int> tempBayer;
  tempBayer.resize((width + 2)*(height * 2), 0);
  for (int i = 0; i < width; i++) {
	  for (int j = 0; j < height; j++) {

		  tempBayer[(j + 1)*(width + 2) + i + 1] = bayer[j*width + i];
	  }
  }

  for (int i = 0; i < width; i++)
  {
	  for (int j = 0; j < height; j++) {

		  if (i % 2 == 0 && j % 2 == 0) {  //G
			  //bayer[j*width + i] = rgb[(j*width + i) * 3 + 1];

			  rgb[(j*width + i) * 3] = (UP(tempBayer,width+2,i+1,j+1) + DOWN(tempBayer,width+2,i+1,j+1))/2;
			  rgb[(j*width + i) * 3 + 1] = bayer[j*width + i];//G
			  rgb[(j*width + i) * 3 + 2] = (LEFT(tempBayer,width+2,i+1,j+1)+RIGHT(tempBayer,width+2,i+1,j+1)) / 2;
		  }
		  else if (i % 2 == 0 && j % 2 != 0)//R
		  {
			  rgb[(j*width + i) * 3] = bayer[j*width + i] ;
			  rgb[(j*width + i) * 3 + 1] = (LEFT(tempBayer,width+2,i+1,j+1) + RIGHT(tempBayer,width+2,i+1,j+1)+UP(tempBayer,width+2,i+1,j+1)+DOWN(tempBayer,width+2,i+1,j+1)) / 4;
			  rgb[(j*width + i) * 3 + 2] = (LU(tempBayer,width+2,i+1,j+1) + RU(tempBayer, width + 2, i + 1, j + 1) + LD(tempBayer, width + 2, i + 1, j + 1) + RD(tempBayer, width + 2, i + 1, j + 1)) / 4;
		  }
		  else if (i % 2 != 0 && j % 2 == 0)//B
		  {
			  rgb[(j*width + i) * 3] = (LU(tempBayer, width + 2, i + 1, j + 1) + RU(tempBayer, width + 2, i + 1, j + 1) + LD(tempBayer, width + 2, i + 1, j + 1) + RD(tempBayer, width + 2, i + 1, j + 1)) / 4;
			  rgb[(j*width + i) * 3 + 1] = (LEFT(tempBayer, width + 2, i + 1, j + 1) + RIGHT(tempBayer, width + 2, i + 1, j + 1) + UP(tempBayer, width + 2, i + 1, j + 1) + DOWN(tempBayer, width + 2, i + 1, j + 1)) / 4;
			  rgb[(j*width + i) * 3 + 2] = bayer[j*width + i];
		  }
		  else if (i % 2 != 0 && j % 2 != 0)//G
		  {
			  rgb[(j*width + i) * 3] = (LEFT(tempBayer, width + 2, i + 1, j + 1) + RIGHT(tempBayer, width + 2, i + 1, j + 1)) / 2;
			  rgb[(j*width + i) * 3 + 1] = bayer[j*width + i] ;
			  rgb[(j*width + i) * 3 + 2] = (UP(tempBayer, width + 2, i + 1, j + 1) + DOWN(tempBayer, width + 2, i + 1, j + 1)) / 2;
		  }


	  }
  }
}
