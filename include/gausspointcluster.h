#ifndef _GAUSSPOINTCLUSTER
#define _GAUSSPOINTCLUSTER

#include <utility>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using std::vector;
using std::pair;
using std::make_pair;
using std::min;
using std::find;

class GaussCluster2D
{
 public:
  //Any operation that involves changing parameters (number, mean, var) will take effect on actual cluster data immediately.
  GaussCluster2D(const size_t number = 0,
		 const pair<size_t, size_t>& mean = {0, 0},
		 const size_t var = 0,
		 const pair<size_t, size_t>& spawn_area = {0, 0});
  ~GaussCluster2D(){};
  void setMean(const pair<size_t, size_t>& mean){this->_mean = mean;}
  void setVar(const size_t var){this->_var = var;}
  void setTotalNumber(const size_t number){this->_number = number;}
  void setSpawnArea(const pair<size_t, size_t>& spawnarea){this->_spawn_area = spawnarea;}
  void setParams(const pair<size_t, size_t>& mean,
		 const size_t var,
		 const size_t number,
		 const pair<size_t, size_t>& spawnarea)
  {setMean(mean); setVar(var); setTotalNumber(number); setSpawnArea(spawnarea);}
  size_t getVar()const{return _var;}
  pair<size_t, size_t> getMean()const{return _mean;}
  pair<size_t, size_t> getSpawnArea()const{return _spawn_area;}
  size_t getTotalNumber()const{return _number;}
  void exposeNoiseCluster(bool b){_exposed_cluster = b ? &_noised_gaussianPoints : &_gaussianPoints;}
  pair<size_t, size_t> getPoint(size_t index)const{return (*_exposed_cluster)[index];}
  //pair<size_t, size_t> getNoisedPoint(size_t index)const{return _noised_gaussianPoints[index];}
  
  void generate();
  //Add gaussian white noise to every single point in this cluster.
  //True inidicates noise has been successsfully added, false indicates the original gauss points have not been generated
  bool addNoise(const size_t var);
  
 private:
  size_t _number;
  pair<size_t, size_t> _mean;
  size_t _var;
  pair<size_t, size_t> _spawn_area;
  vector<pair<size_t, size_t>> _gaussianPoints;
  vector<pair<size_t, size_t>> _noised_gaussianPoints;
  //Indicates which cluster (clean or noised) should be presented when someone called getPoint from the outside;
  const decltype(_gaussianPoints)* _exposed_cluster;
  
  pair<size_t, size_t> generateSinglePoint(const pair<size_t, size_t>& mean,
					    const size_t var,
					    const pair<size_t, size_t>& spawn_area);
  inline double probDensity(auto mean, auto point, size_t var)
  {
    //THE PARAMETERS OF POW() MUST ALL BE DOUBLE!!!
    return 1000 * exp(-(pow((double)mean.first - point.first, 2.0) + pow((double)mean.second - point.second, 2.0)) / (2 * var));
  }
};



#endif
