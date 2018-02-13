#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
  //Initialize actions
  actOpenFile = new QAction(tr("Open"));
  actSaveFile = new QAction(tr("Save"));
  actGenerateClusters = new QAction(tr("GaussClusters"));
  actAddNoise = new QAction(tr("AddNoise"));
  actDropCenters = new QAction(tr("DropCenters"));
  
  actOpenFile->setShortcut(tr("ctrl+O"));
  actSaveFile->setShortcut(tr("ctrl+S"));
  actGenerateClusters->setShortcut(tr("ctrl+G"));
  actAddNoise->setShortcut(tr("ctrl+N"));
  //Initialize menubar
  
  //Initialize toolbar
  tbProcess = addToolBar(tr("Options"));
  tbProcess->addAction(actOpenFile);
  tbProcess->addAction(actSaveFile);
  tbProcess->addAction(actGenerateClusters);
  tbProcess->addAction(actAddNoise);
  tbProcess->addAction(actDropCenters);
  
  //Initialize widgets
  QLabel* lblCMeanX = new QLabel(tr("Cluster Mean X"));
  QLabel* lblCMeanY = new QLabel(tr("Cluster Mean Y"));
  QLabel* lblCVar = new QLabel(tr("Cluster Variance"));
  QLabel* lblNoiseVar = new QLabel(tr("Noise Variance"));
  QLabel* lblPointsPerCluster = new QLabel(tr("Points Per Cluster"));
  QLabel* lblCenter1 = new QLabel(tr("Center 1"));
  QLabel* lblCenter2 = new QLabel(tr("Center 2"));
  QLabel* lblCenter3 = new QLabel(tr("Center 3"));
  QLabel* lblX = new QLabel(tr("X:"));
  QLabel* lblY = new QLabel(tr("Y:"));
  QLabel* lblProgress = new QLabel(tr("Progress:"));
  QLabel* lblError = new QLabel(tr("Error Rate:"));
  lblCenter1X = new QLabel("[center 1 x]");
  lblCenter1Y = new QLabel("[center 1 y]");
  lblCenter2X = new QLabel("[center 2 x]");
  lblCenter2Y = new QLabel("[center 2 y]");
  lblCenter3X = new QLabel("[center 3 x]");
  lblCenter3Y = new QLabel("[center 3 y]");
  lblCenter1Prog = new QLabel("0");
  lblCenter2Prog = new QLabel("0");
  lblCenter3Prog = new QLabel("0");
  lblErrorRate = new QLabel("0");
  
  editPointPerCluster =  new QLineEdit("200");
  QValidator* vPerCluster = new QIntValidator(100, 5000, this);
  editPointPerCluster->setValidator(vPerCluster);
  
  editClusterMean1X = new QLineEdit("100");
  QValidator* vMean1X = new QIntValidator(0, 400, this);
  editClusterMean1X->setValidator(vMean1X);
  
  editClusterMean1Y = new QLineEdit("100");
  QValidator* vMean1Y = new QIntValidator(0, 400, this);
  editClusterMean1Y->setValidator(vMean1Y);
  
  editClusterMean2X = new QLineEdit("300");
  QValidator* vMean2X = new QIntValidator(0, 400, this);
  editClusterMean2X->setValidator(vMean2X);
  
  editClusterMean2Y = new QLineEdit("100");
  QValidator* vMean2Y = new QIntValidator(0, 400, this);
  editClusterMean2Y->setValidator(vMean2Y);
  
  editClusterMean3X = new QLineEdit("200");
  QValidator* vMean3X = new QIntValidator(0, 400, this);
  editClusterMean3X->setValidator(vMean3X);
  
  editClusterMean3Y = new QLineEdit("300");
  QValidator* vMean3Y = new QIntValidator(0, 400, this);
  editClusterMean3Y->setValidator(vMean3Y);

  editCluster1Var = new QLineEdit("200");
  QValidator* vVar1 = new QIntValidator(50, 1000, this);
  editCluster1Var->setValidator(vVar1);

  editCluster2Var = new QLineEdit("200");
  QValidator* vVar2 = new QIntValidator(50, 1000, this);
  editCluster2Var->setValidator(vVar2);
  
  editCluster3Var = new QLineEdit("200");
  QValidator* vVar3 = new QIntValidator(50, 1000, this);
  editCluster3Var->setValidator(vVar3);
  
  editNoiseVar = new QLineEdit("100");
  QValidator* vNoiseVar = new QIntValidator(50, 10000, this);
  editNoiseVar->setValidator(vNoiseVar);

  QGridLayout* layoutParams = new QGridLayout;
  layoutParams->addWidget(lblCMeanX, 0, 0);
  layoutParams->addWidget(editClusterMean1X, 0, 1);
  layoutParams->addWidget(editClusterMean2X, 0, 2);
  layoutParams->addWidget(editClusterMean3X, 0, 3);
  layoutParams->addWidget(lblCMeanY, 1, 0);
  layoutParams->addWidget(editClusterMean1Y, 1, 1);
  layoutParams->addWidget(editClusterMean2Y, 1, 2);
  layoutParams->addWidget(editClusterMean3Y, 1, 3);
  layoutParams->addWidget(lblCVar, 2, 0);
  layoutParams->addWidget(editCluster1Var, 2, 1);
  layoutParams->addWidget(editCluster2Var, 2, 2);
  layoutParams->addWidget(editCluster3Var, 2, 3);
  
  layoutParams->addWidget(lblNoiseVar, 3, 0);
  layoutParams->addWidget(editNoiseVar, 3, 1, 1, 3);

  layoutParams->addWidget(lblPointsPerCluster, 4, 0);
  layoutParams->addWidget(editPointPerCluster, 4, 1, 1, 3);

  btnNext = new QPushButton(tr("Next"));
  btnNext->setEnabled(false);
  
  QGridLayout* layoutStats = new QGridLayout;
  layoutStats->addWidget(lblCenter1, 0, 1);
  layoutStats->addWidget(lblCenter2, 0, 2);
  layoutStats->addWidget(lblCenter3, 0, 3);
  layoutStats->addWidget(lblX, 1, 0);
  layoutStats->addWidget(lblCenter1X, 1, 1);
  layoutStats->addWidget(lblCenter2X, 1, 2);
  layoutStats->addWidget(lblCenter3X, 1, 3);
  layoutStats->addWidget(lblY, 2, 0);
  layoutStats->addWidget(lblCenter1Y, 2, 1);
  layoutStats->addWidget(lblCenter2Y, 2, 2);
  layoutStats->addWidget(lblCenter3Y, 2, 3);
  layoutStats->addWidget(lblProgress, 3, 0);
  layoutStats->addWidget(lblCenter1Prog, 3, 1);
  layoutStats->addWidget(lblCenter2Prog, 3, 2);
  layoutStats->addWidget(lblCenter3Prog, 3, 3);
  layoutStats->addWidget(lblError, 4, 0);
  layoutStats->addWidget(lblErrorRate, 4, 1);
  layoutStats->addWidget(btnNext, 5, 0);
  
  visualArray = new VisualizationWidget(this);
  visualArray->setFixedSize(600, 600);
  QGridLayout* layoutMain = new QGridLayout;
  ///////////////
  layoutMain->addWidget(visualArray, 0, 0, 2, 1);
  layoutMain->addLayout(layoutParams, 0, 1);
  layoutMain->addLayout(layoutStats, 1, 1);

  QFrame* frameMain = new QFrame(this);
  frameMain->setLayout(layoutMain);    
  this->setCentralWidget(frameMain);
  
  //Initialize Attributes
  //these are currently fixed parameters
  _raw_buffer = new RAWContainer(400, 400);
  _cluster_number = 3;
  _points_per_cluster = 200;
  _cluster_means = {{100, 100}, {300, 100}, {200, 300}};
  _cluster_vars = {400, 300, 500};
  _noise_var = editNoiseVar->text().toInt();
  _error_rate = 0;
  
  //Connect signals and slots
  connect(actOpenFile, SIGNAL(triggered()), this, SLOT(actOpenFileHandler()));
  connect(actSaveFile, SIGNAL(triggered()), this, SLOT(actSaveFileHandler()));
  connect(actAddNoise, SIGNAL(triggered()), this, SLOT(actAddNoiseHandler()));
  connect(actGenerateClusters, SIGNAL(triggered()), this, SLOT(actGenerateClustersHandler()));
  connect(actDropCenters, SIGNAL(triggered()), this, SLOT(actDropCentersHandler()));
  connect(btnNext, SIGNAL(clicked()), this, SLOT(nextCenterPositionHandler()));
  connect(this, SIGNAL(flushToVisual(RAWContainer*)), visualArray, SLOT(receiveArray(RAWContainer*)));
}

MainWindow::~MainWindow()
{
  delete _raw_buffer;
  for(const auto c : _clusters)
    delete c;
}


void MainWindow::drawClustersToRAW()
{
  _raw_buffer->clear();
  pair<size_t, size_t> _temp_point;
  size_t _total_number;
  size_t _point_index;
  //cluster_1
  for(auto c : _clusters)
    {
      _total_number = c->getTotalNumber();
      for(_point_index = 0; _point_index < _total_number; ++_point_index)
	{
	  _temp_point = c->getPoint(_point_index);
	  _raw_buffer->setPixel(_temp_point.first, _temp_point.second, 0);
	}
    }
}

void MainWindow::actOpenFileHandler()
{
  QString _strSrcImageName;
  if((_strSrcImageName = QFileDialog::getOpenFileName(this, "Open Image", "./",
						      tr("Images (*.raw *.jpg *.png)"))) != NULL)
    _raw_buffer->readFromFile(_strSrcImageName.toStdString());
  emit flushToVisual(_raw_buffer);
}


void MainWindow::actSaveFileHandler()
{
  QString _strDestFileName;
  if((_strDestFileName = QFileDialog::getSaveFileName(this, "Save Image", "./",
						      tr("Images (*.raw *.jpg *.png)"))) != NULL)
    _raw_buffer->writeToFile(_strDestFileName.toStdString());
}

void MainWindow::actAddNoiseHandler()
{
  _noise_var = editNoiseVar->text().toInt();
  _centers.clear();
  _centers_progress.clear();
  _points_assigned.clear();
  btnNext->setEnabled(false);
  
  for(const auto c : _clusters)
    {
      if(!c->addNoise(_noise_var))
	return;
      c->exposeNoiseCluster(true);
    }  
  
  drawClustersToRAW();
  emit flushToVisual(_raw_buffer);
}

void MainWindow::actGenerateClustersHandler()
{
  _cluster_means[0] = {editClusterMean1X->text().toInt(), editClusterMean1Y->text().toInt()};
  _cluster_means[1] = {editClusterMean2X->text().toInt(), editClusterMean2Y->text().toInt()};
  _cluster_means[2] = {editClusterMean3X->text().toInt(), editClusterMean3Y->text().toInt()};
  
  _cluster_vars[0] = {editCluster1Var->text().toInt()};
  _cluster_vars[1] = {editCluster2Var->text().toInt()};
  _cluster_vars[2] = {editCluster3Var->text().toInt()};

  _points_per_cluster = editPointPerCluster->text().toInt();
  
  _centers.clear();
  _centers_progress.clear();
  _points_assigned.clear();
  btnNext->setEnabled(false);
  
  if(!_clusters.empty())
    for(const auto c : _clusters)
      delete c;
  
  _clusters.resize(_cluster_number);

  pair<size_t, size_t> _spawn_area = make_pair(_raw_buffer->getWidth(), _raw_buffer->getHeight());
  for(size_t _index = 0; _index < this->_cluster_number; ++_index)
    {
      _clusters[_index] = new GaussCluster2D;
      _clusters[_index]->setParams(_cluster_means[_index], _cluster_vars[_index],
		   _points_per_cluster, _spawn_area);
      _clusters[_index]->generate();
      _clusters[_index]->exposeNoiseCluster(false);
    }
      
  drawClustersToRAW();
  emit flushToVisual(_raw_buffer); 
}

void MainWindow::actDropCentersHandler()
{
  _centers.resize(_cluster_number);
  _points_assigned.resize(_cluster_number);
  _centers_progress.resize(_cluster_number);

  btnNext->setEnabled(true);
  //Good to have a dialog to set it up

  //Temporarily drop here
  _centers[0] = {rand() % 400, rand() % 400};
  _centers[1] = {rand() % 400, rand() % 400};
  _centers[2] = {rand() % 400, rand() % 400};

  //Draw center markers and draw coordinates
  updateInfo();
  updateCenterMarkers();
  emit flushToVisual(_raw_buffer);
}

void MainWindow::nextCenterPositionHandler()
{
  clusterDivision();
  calculateNewCenters();
  calculateErrorRate();
  updateInfo();
  updateCenterMarkers();
  emit flushToVisual(_raw_buffer);
}

void MainWindow::updateCenterMarkers()
{

    
  visualArray->setMarker(Qt::blue, VW_MARK_CROSS,
			 make_pair((size_t)_centers[0].first, (size_t)_centers[0].second),
			 make_pair(8, 8));
  visualArray->setMarker(Qt::blue, VW_MARK_RECT,
			 make_pair((size_t)_centers[1].first, (size_t)_centers[1].second),
			 make_pair(8, 8));
  visualArray->setMarker(Qt::blue, VW_MARK_ELLIPSE,
			 make_pair((size_t)_centers[2].first, (size_t)_centers[2].second),
			 make_pair(8, 8));
}

void MainWindow::updateInfo()
{
  lblCenter1X->setText(QString::number(_centers[0].first));
  lblCenter1Y->setText(QString::number(_centers[0].second));
  lblCenter2X->setText(QString::number(_centers[1].first));
  lblCenter2Y->setText(QString::number(_centers[1].second));
  lblCenter3X->setText(QString::number(_centers[2].first));
  lblCenter3Y->setText(QString::number(_centers[2].second));
  
  lblCenter1Prog->setText(QString::number(_centers_progress[0]));
  lblCenter2Prog->setText(QString::number(_centers_progress[1]));
  lblCenter3Prog->setText(QString::number(_centers_progress[2]));

  lblErrorRate->setText(QString::number(_error_rate));
}

inline double MainWindow::distance(pair<double, double> p1, pair<double, double> p2)
{
  return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

void MainWindow::clusterDivision()
{
  for(auto & c : _points_assigned)
    c.clear();
  
  //Current cluster index
  size_t _cl_index;
  //Current point index of the points inside certain cluster
  size_t _p_index;
  //Current center index
  size_t _ce_index, _ce_index_temp;
  //This value is larger than distance between any two points in _raw_buffer
  double _largest_distance = (double)_raw_buffer->getWidth() + _raw_buffer->getHeight();
  double _distance_buffer;
  double _distance_temp;
  //Traverse clusters
  for(_cl_index = 0; _cl_index < _cluster_number; ++_cl_index)
    {
      //Traverse points in this cluster
      for(_p_index = 0; _p_index < _points_per_cluster; ++_p_index)
	{
	  _distance_buffer = _largest_distance;
	  //Traverse centers
	  for(_ce_index = 0; _ce_index < _cluster_number; ++_ce_index)
	    {
	      _distance_temp = distance(_centers[_ce_index],
					_clusters[_cl_index]->getPoint(_p_index));
	      //See if current center is nearer
	      if(_distance_temp < _distance_buffer)
		{
		  _distance_buffer = _distance_temp;
		  _ce_index_temp = _ce_index;
		}
	    }
	  //Assign this current point to the nearest center
	  _points_assigned[_ce_index_temp].push_back(make_pair(_cl_index, _p_index));
	}
    }
}

void MainWindow::calculateNewCenters()
{
  decltype(_centers) _prev_centers = _centers;  
  size_t _ce_index;
  size_t _assigned_number;
  size_t _x_accu;
  size_t _y_accu;
  //Traverse every center
  for(_ce_index = 0; _ce_index < _cluster_number; ++_ce_index)
    {
      _x_accu = _y_accu = 0;
      _assigned_number = _points_assigned[_ce_index].size();
      //Traverse every point that was assigned to this center
      for(const auto& ass : _points_assigned[_ce_index]) //hahahaha, ass!
	{
	  _x_accu += _clusters[ass.first]->getPoint(ass.second).first;
	  _y_accu += _clusters[ass.first]->getPoint(ass.second).second;
	}
      //New position of centers
      _centers[_ce_index] = {(double)_x_accu / _assigned_number, (double)_y_accu / _assigned_number};
      //Calculate progress
      _centers_progress[_ce_index] = distance(_centers[_ce_index], _prev_centers[_ce_index]);
    }  
}

void MainWindow::calculateErrorRate()
{
  size_t _error_point_number = 0;
  //The total number of points that was assigned to a certain center
  size_t _total_assigned;
  size_t _count_temp;
  //e.g.
  //_actual_cluster_count[1] indicates how many points actually belongs to cluster 1,
  //and was assigned to current center when traversing every center.
  //vector<size_t> _actual_cluster_count(_cluster_number, 0);
  vector<size_t> _actual_cluster_count;
  //Traverse every center
  for(const auto& ce : _points_assigned)
    {
      _actual_cluster_count.clear();
      _actual_cluster_count.resize(_cluster_number, 0);
      _total_assigned = ce.size();
      cout << "Total number of points assigned to one center:" << _total_assigned << endl;
      //Count the number of points of each actual cluster that was assigned to this center
      for(const auto& ass : ce)
	++_actual_cluster_count[ass.first];
      //See which actual cluster is the most assigned for this center,
      //and how many points in this actual cluster was assigned to this center
      _count_temp = 0;
      for(const auto& cl : _actual_cluster_count)
	{
	  cout << "One cluster: " << cl << endl;
	  _count_temp = _count_temp < cl ? cl : _count_temp;
	}
      _error_point_number += _total_assigned - _count_temp;
    }

  _error_rate = (double)_error_point_number / (_cluster_number * _points_per_cluster);
}
