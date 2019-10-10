#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  assert(
    (num_channels == 3 || num_channels ==1 ) &&
    ".ppm only supports RGB or grayscale images");
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  std::ofstream ppm;
  std::string newFilename = "./output/";
  newFilename.append(filename);
  ppm.open(newFilename, std::ios::out | std::ios::trunc);
  //
  ppm << "P3"<<std::endl; //magic number
  ppm << std::to_string(width) << " " << std::to_string(height)<<" "<< std::endl;
  ppm << "255" << std::endl;

  if (num_channels == 1) {
	  for (int j = 0; j < height; j++)
	  {
		  for (int i = 0; i < width; i++)
		  {
			  ppm << std::to_string(data[(width*j + i)]) << " " << std::to_string(data[(width*j + i)]) << " " << std::to_string(data[(width*j + i)]) << " ";
		  }
		  ppm << std::endl;
	  }
  }
  else
  {
	  for (int j = 0; j < height; j++)
	  {
		for (int i = 0;i<width;i++)
		{
			ppm << std::to_string(data[(width*j + i) * 3]) << " " << std::to_string(data[(width*j + i) * 3 + 1]) << " " << std::to_string(data[(width*j + i) * 3 + 2]) << " ";
		}
		ppm << std::endl;
	  }
  }



  return false;
  ////////////////////////////////////////////////////////////////////////////
}
