#include <Python.h>
#include <iostream>
#include <datetime.h>  // Include the Python datetime API
#include <numpy/arrayobject.h> // and numpy
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/eigen.h>  // If you're using Eigen types

namespace py = pybind11;
using namespace std;

#include "PPM_atm.cpp"

Eigen::VectorXd shadow_function(Eigen::MatrixXd r_sat, Eigen::MatrixXd r_sun) {
  // test time: UTC: 2015 1 11 18 33 34
  // shadow function should give: 0.474838
  if(r_sat.cols() == 1) {
    r_sat = r_sat.transpose();
  }
  if(r_sun.cols() == 1) {
    r_sun = r_sun.transpose();
  }

  Eigen::VectorXd shadow_factor(r_sat.rows());

  for(int i = 0; i < r_sat.rows(); i++) {

    GVector satpos(r_sat(i,0), r_sat(i,1), r_sat(i,2)); // sat position in km
    GVector sunpos(r_sun(i,0), r_sun(i,1), r_sun(i,2)); //sun position in km

    shadow_factor[i] = myshadowFactor(sunpos, satpos);

    }
    return shadow_factor;
}

PYBIND11_MODULE(shado, m) {
    m.def("shadow_function", &shadow_function, R"mydelimiter(
        Generate n evenly spaced DateTime objects between two specified DateTime points

        :param dt1: The first DateTime
        :param dt2: The second DateTime
        :param n: The number of DateTime objects to generate
        :return: A vector of DateTime objects
        )mydelimiter");
}