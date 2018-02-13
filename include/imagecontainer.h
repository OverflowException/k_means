#ifndef _IMAGECONTAINER
#define _IMAGECONTAINER
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>

typedef unsigned char uchar;

using std::cout;
using std::endl;
using std::string;
using std::ios;
using std::fstream;


#define PIX(X, Y) (_imageData[Y * _width + X])

class RAWContainer
{

 public:
  RAWContainer(int width = 0, int height = 0);  
  ~RAWContainer(){delete _imageData;}
  
  int getWidth() const {return _width;}
  int getHeight() const {return _height;}
  uchar* getData() const {return _imageData;}
  //Set data directly
  void setPixel(size_t x, size_t y, uchar pixel){PIX(x, y) = pixel;}
  uchar getPixel(size_t x, size_t y) const {return PIX(x, y);}
  void clear(){memset(_imageData, 0xff, _width * _height * sizeof(uchar));};
  void readFromFile(string filename);
  void writeToFile(string filename);
  void resize(int width, int height);
  
 private:
  uchar* _imageData;
  int _width;
  int _height;
  
};

#endif
