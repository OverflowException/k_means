#include "visualizationwidget.h"

VisualizationWidget::VisualizationWidget(QWidget *parent)
{
  _raw_ptr = NULL;
}
VisualizationWidget::~VisualizationWidget()
{
  _raw_ptr = NULL;
}


void VisualizationWidget::setMarker(QColor color, MarkerShape shape,
				    pair<size_t, size_t> center,
				    pair<size_t, size_t> size)
{
  this->_list_marker.emplace(color, shape, center, size);
}

void VisualizationWidget::paintEvent(QPaintEvent* pe)
{
  QPainter _arrayPainter(this);
  if(_raw_ptr)
    {
      size_t _image_width = _raw_ptr->getWidth();
      size_t _image_height = _raw_ptr->getHeight();
      size_t _image_start_x = (this->width() - _image_width) / 2;
      size_t _image_start_y = (this->height() - _image_height) / 2;
      const uchar* _image_data = _raw_ptr->getData();
      QImage _image(_image_width, _image_height, QImage::Format_RGB32);
      size_t row, column, acc_index = 0;
      for(row = 0; row < _image_height; row++)
	{
	  for(column = 0; column < _image_width; ++column, ++acc_index)
	    _image.setPixel(column, row,
			    qRgb(_image_data[acc_index],
				 _image_data[acc_index],
				 _image_data[acc_index]));
	}
      _arrayPainter.drawImage(QRectF(_image_start_x, _image_start_y, 
				     _image_width, _image_height), _image);
      //Draw markers
      while(!_list_marker.empty())
	{
	  VisualMarker _temp;
	  _temp = _list_marker.front();
	  _arrayPainter.setPen(QPen(_temp.color, 2, Qt::SolidLine, Qt::FlatCap));
	  switch(_temp.shape)
	    {
	    case VW_MARK_ELLIPSE:
	      _arrayPainter.drawEllipse(QPoint(_temp.center.first + _image_start_x,
					       _temp.center.second + _image_start_y),
					_temp.size.first / 2, _temp.size.second / 2);
	      break;
	    case VW_MARK_CROSS:
	      _arrayPainter.drawLine(QLine(_temp.center.first - _temp.size.first / 2 + _image_start_x,
					   _temp.center.second + _image_start_y,
					   _temp.center.first + _temp.size.first / 2 + _image_start_x,
					   _temp.center.second + _image_start_y));
	      
	      _arrayPainter.drawLine(QLine(_temp.center.first + _image_start_x,
					   _temp.center.second - _temp.size.second / 2 + _image_start_y,
					   _temp.center.first + _image_start_x,
					   _temp.center.second + _temp.size.second / 2 + _image_start_y));
	      break;
	    case VW_MARK_RECT:
	      _arrayPainter.drawRect(_temp.center.first - _temp.size.first / 2 + _image_start_x,
				     _temp.center.second - _temp.size.second / 2 + _image_start_y,
				     _temp.size.first, _temp.size.second);
	      break;
	    }
	  _list_marker.pop();
	}
    }

  //Initialization
  else
    {
      _arrayPainter.setPen(Qt::blue);
      _arrayPainter.setFont(QFont("Arial", 30));
      _arrayPainter.drawText(rect(), Qt::AlignCenter, "<Viewer>");
    }
}

void VisualizationWidget::receiveArray(RAWContainer* rc)
{
  _raw_ptr = rc;
  this->repaint();
}
