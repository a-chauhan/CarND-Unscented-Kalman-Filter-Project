#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using std::vector;
using namespace std;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
   * TODO: Calculate the RMSE here.
   */
  VectorXd rmse(4);
  rmse << 0,0,0,0;
  
  if(estimations.size() == 0){
    return rmse;
  }

  if(estimations.size() != ground_truth.size()){
    return rmse;
  }

  for(unsigned int i=0; i < estimations.size(); ++i){
    VectorXd residual = estimations[i] - ground_truth[i];
    residual = residual.array() * residual.array();
    rmse += residual;
  }
  
  rmse = rmse / estimations.size();
  rmse = rmse.array().sqrt();
  return rmse;
}