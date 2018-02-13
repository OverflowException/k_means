#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include <QtWidgets>
#include <Qt>
#include <utility>
#include "visualizationwidget.h"
#include "imagecontainer.h"
#include "gausspointcluster.h"

using std::pair;
using std::make_pair;

 class MainWindow : public QMainWindow
 {
   Q_OBJECT
   
 public:
   MainWindow(QWidget *parent = 0);
   ~MainWindow();

 private:
   //Foudamental widgets
   QToolBar* tbProcess;
   QAction* actOpenFile;
   QAction* actAddNoise;
   QAction* actSaveFile;
   QAction* actGenerateClusters;
   QAction* actDropCenters;
   QFrame* frameStats;
   QGridLayout* layoutStats;
   
   QLabel* lblCenter1X;
   QLabel* lblCenter1Y;
   QLabel* lblCenter2X;
   QLabel* lblCenter2Y;
   QLabel* lblCenter3X;
   QLabel* lblCenter3Y;
   QLabel* lblCenter1Prog;
   QLabel* lblCenter2Prog;
   QLabel* lblCenter3Prog;
   QLabel* lblErrorRate;

   QLineEdit* editPointPerCluster;
   QLineEdit* editClusterMean1X;
   QLineEdit* editClusterMean1Y;
   QLineEdit* editClusterMean2X;
   QLineEdit* editClusterMean2Y;
   QLineEdit* editClusterMean3X;
   QLineEdit* editClusterMean3Y;
   QLineEdit* editCluster1Var;
   QLineEdit* editCluster2Var;
   QLineEdit* editCluster3Var;
   QLineEdit* editNoiseVar;
   
   QPushButton* btnNext;
     
   //Functional widgets
   VisualizationWidget* visualArray;

   //Attributes
   RAWContainer* _raw_buffer;
   size_t _cluster_number;
   size_t _points_per_cluster;
   vector<pair<size_t, size_t>> _cluster_means;
   vector<size_t> _cluster_vars;
   size_t _noise_var;
   
   vector<GaussCluster2D*> _clusters;
   vector<pair<double, double>> _centers;
   vector<double> _centers_progress;
   double _error_rate;
   //pair<clusterNumber, pointIndex>
   vector<vector<pair<size_t, size_t>>> _points_assigned;
   
   //Member Functions
   inline double distance(pair<double, double> p1, pair<double, double> p2);
   //Draw the clusters to raw buffer
   void drawClustersToRAW();
   //Set center markers on the visualization widget and update center info
   void updateCenterMarkers();
   void updateInfo();
   //Assign all the points to its nearest center, respectively
   void clusterDivision();
   //Calculate new center positions
   void calculateNewCenters();
   //Calculate Error Rate
   void calculateErrorRate();
   
 signals:
   //emit this signal every time the raw buffer changes
   void flushToVisual(RAWContainer*);
   
 public slots:
   
 private slots:
   void actOpenFileHandler();
   void actSaveFileHandler();
   void actAddNoiseHandler();
   void actGenerateClustersHandler();
   void actDropCentersHandler();
   void nextCenterPositionHandler();
 };

#endif
