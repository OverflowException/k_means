#ifndef _VISUALIZATIONWIDGET
#define _VISUALIZATIONWIDGET

#include <QtWidgets>
#include <queue>
#include <utility>
#include "imagecontainer.h"

#define VW_MARK_RECT    0b0001u
#define VW_MARK_ELLIPSE  0b0010u
#define VW_MARK_CROSS     0b0100u

using std::queue;
using std::pair;

typedef uchar MarkerShape;
struct VisualMarker
{
  QColor color;
  MarkerShape shape;
  pair<size_t, size_t> center;
  pair<size_t, size_t> size;
VisualMarker(QColor c = Qt::blue, MarkerShape m = 0,
	       pair<size_t, size_t> p = {0, 0},
	       pair<size_t, size_t> s = {0, 0}): color(c), shape(m), center(p), size(s){}
};

class VisualizationWidget : public QWidget
{
  Q_OBJECT
 public:
  VisualizationWidget(QWidget *parent = 0);
  ~VisualizationWidget();
  void setMarker(QColor color = Qt::blue,
		 MarkerShape shape = VW_MARK_RECT,
		 pair<size_t, size_t> center = {0, 0},
		 pair<size_t, size_t> size = {5, 5});
  
 public slots:
   void receiveArray(RAWContainer*);
   
 protected:
  //This event will be called by slot: QWidget::repaint()
   void paintEvent(QPaintEvent* );

 private:
  //This pointer will be nullified if the original container is modified.
  //Which means the container can only be flushed FROM parent TO this
  //Flush in a reversed direction prohibited
  const RAWContainer*  _raw_ptr;
  //Markers can be set manually.
  //Once flushed, this queue will be cleared.
  queue<VisualMarker> _list_marker;
};

#endif
