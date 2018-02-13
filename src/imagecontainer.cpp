#include "imagecontainer.h"

RAWContainer::RAWContainer(int width, int height)
{
  this->_width = width;
  this->_height = height;
      
  if(width == 0 ||  height == 0)
    _imageData = NULL;
  else
    {
      _imageData = new uchar[_width * _height];
      clear();
    }
}

void RAWContainer::readFromFile(string filename)
{
  fstream _instream_image;
  _instream_image.open(filename, ios::in | ios::binary);
  int _temp_height, _temp_width;
  _instream_image.read((char*)&_temp_width, sizeof(int));
  _instream_image.read((char*)&_temp_height, sizeof(int));
  resize(_temp_width, _temp_height);
  _instream_image.read((char*)_imageData, this->_width * this->_height);
  _instream_image.close();
}
 
void RAWContainer::writeToFile(string filename)
{
  fstream _outstream_image;
  _outstream_image.open(filename, ios::out | ios::binary);
  _outstream_image.write((char*)&(this->_width), sizeof(int));
  _outstream_image.close();
  _outstream_image.open(filename, ios::out | ios::binary | ios::app);
  _outstream_image.write((char*)&(this->_height), sizeof(int));
  _outstream_image.write((char*)_imageData, this->_width * this->_height);
  _outstream_image.close();
}

void RAWContainer::resize(int width, int height)
{
  if(width != _width || height != _height)
    {
      this->_width = width;
      this->_height = height;
      if(_imageData)
	delete _imageData;
      _imageData = new uchar[width * height];
      clear();
    }
}
