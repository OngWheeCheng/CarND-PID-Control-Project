#include "PID.h"
#include <limits>

#define TWIDDLE_TOLERANCE   0.0002

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  PID::Kp = Kp;
  PID::Ki = Ki;
  PID::Kd = Kd;

  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
}

void PID::UpdateError(double cte) {
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
}

double PID::TotalError() {
  // -tau_p * cte - tau_d * diff_cte - tau_i * int_cte
  return -(Kp * p_error + Ki * i_error + Kd * d_error);
}