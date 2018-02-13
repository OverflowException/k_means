#include "gausspointcluster.h"

GaussCluster2D::GaussCluster2D(const size_t number,
			       const pair<size_t, size_t>& mean,
			       const size_t var,
			       const pair<size_t, size_t>& spawn_area)
{
  srand((unsigned char)time(NULL));
  this->_number = number;
  this->_mean = mean;
  this->_var = var;
  this->_spawn_area = spawn_area;
  _gaussianPoints.clear();
  _noised_gaussianPoints.clear();
  exposeNoiseCluster(false);
}

void GaussCluster2D::generate()
{
  _gaussianPoints.clear();
  decltype(_gaussianPoints)::value_type _temp_point;
  auto it = back_inserter(_gaussianPoints);
  //Insert new gaussian points to cluster.
  for(size_t count = 0; count < _number; ++count, ++it)
    {
      _temp_point = generateSinglePoint(_mean, _var, _spawn_area);
      //Check if the newly generated already existed.
      while(find(_gaussianPoints.begin(), _gaussianPoints.end(), _temp_point) != _gaussianPoints.end())
	_temp_point = generateSinglePoint(_mean, _var, _spawn_area);
      *it = _temp_point;
    }
}

bool GaussCluster2D::addNoise(const size_t var)
{
  _noised_gaussianPoints.clear();
  if(_gaussianPoints.empty())
    return false;

  decltype(_gaussianPoints)::value_type _temp_point;
  auto it_clean = _gaussianPoints.begin();
  auto it_noised = back_inserter(_noised_gaussianPoints);
  //Add noise to every point in this cluster.
  for(;it_clean != _gaussianPoints.end(); ++it_clean, ++it_noised)
    {
      _temp_point = generateSinglePoint(*it_clean, var, this->_spawn_area);
      //See if the point already existed.
      while(find(_noised_gaussianPoints.begin(),
		 _noised_gaussianPoints.end(), _temp_point) != _noised_gaussianPoints.end())
	_temp_point = generateSinglePoint(*it_clean, var, this->_spawn_area);
      *it_noised = _temp_point;
    }
  return true;
}

pair<size_t, size_t> GaussCluster2D::generateSinglePoint(const pair<size_t, size_t>& mean,
							  const size_t var,
							  const pair<size_t, size_t>& spawn_area)
{
  pair<size_t, size_t> _result;
do
  {
  _result.first = rand() % spawn_area.first;
  _result.second = rand() % spawn_area.second;
  }while(probDensity(mean, _result, var) < (rand() % 1000));
 
  return _result;
}
