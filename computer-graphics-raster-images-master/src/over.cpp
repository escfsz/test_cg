#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  for (int i = 0; i < width; i++)
  {
	  for (int j = 0; j < height; j++) {

		  auto alphaA = A[(j * width + i) * 4 + 3];
		  auto alphaB = B[(j * width + i) * 4 + 3];
		 // auto alphaC = alphaB + alphaA*(1 - alphaB);
		  C[(j * width + i) * 4] = (int)(A[(j * width + i) * 4]* alphaA*1.0/255 + B[(j * width + i) * 4]*(255 - alphaA)*1.0/255);
		  C[(j * width + i) * 4+1] = (int)(A[(j * width + i) * 4+1] * alphaA * 1.0 / 255 + B[(j * width + i) * 4+1] * (255 - alphaA) * 1.0 / 255);
		  C[(j * width + i) * 4+2] = (int)(A[(j * width + i) * 4+2] * alphaA * 1.0 / 255 + B[(j * width + i) * 4+2] * (255 - alphaA) * 1.0 / 255);
		  C[(j * width + i) * 4+3] = (int)(A[(j * width + i) * 4 + 3] * alphaA * 1.0 / 255 + B[(j * width + i) * 4 + 3] * (255 - alphaA) * 1.0 / 255);

	  }
  }
}
