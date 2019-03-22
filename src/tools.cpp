#include <iostream>
#include "tools.h"


using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
	VectorXd rms_error(4);
  	rms_error << 0,0,0,0;
  	if(estimations.size() == 0)
	{
      		cout << "ERROR - CalculateRMSE () - The estimations vector is empty" << endl;
      		return rms_error;
    	}

   	if(ground_truth.size() == 0)
	{
     		cout << "ERROR - CalculateRMSE () - The ground-truth vector is empty" << endl;
     		return rms_error;
    	}

    	unsigned int n = estimations.size();
    	if(n != ground_truth.size())
	{
      	cout << "ERROR - CalculateRMSE () - The ground-truth and estimations vectors must have the same size." << endl;
      	return rms_error;
    	}

  
  	 for(unsigned int i=0; i < estimations.size(); ++i)
     	{
        VectorXd diff = estimations[i] - ground_truth[i];
        diff = diff.array()*diff.array();
        rms_error += diff;

    	}
      unsigned int n = estimations.size();

      rms_error = rms_error / n;
      rms_error = rms_error.array().sqrt();
      return rms_error;
    }

MatrixXd Tools::CalculateJacobian(const VectorXd& x_state) 
{
    MatrixXd Jacobian(3,4);

  if ( x_state.size() != 4 ) {
    cout << "ERROR - CalculateJacobian () - The state vector must have size 4." << endl;
    return Jacobian;
  }
	//recover state parameters
	double px = x_state(0);
	double py = x_state(1);
	double vx = x_state(2);
	double vy = x_state(3);

	//pre-compute a set of terms to avoid repeated calculation
	double c1 = px*px+py*py;
	double c2 = sqrt(c1);
	double c3 = (c1*c2);

	//check division by zero
	if(fabs(c1) < 0.0000001 )
    {
		cout << "ERROR - Division by Zero during Jacobian Calculation" << endl;
		return Jacobian;
	}

	//compute the Jacobian matrix
	Jacobian << (px/c2), (py/c2), 0, 0,
		  	-(py/c1), (px/c1), 0, 0,
		  	 py*(vx*py - vy*px)/c3, px*(px*vy - py*vx)/c3, px/c2, py/c2;

	return Jacobian;
}
