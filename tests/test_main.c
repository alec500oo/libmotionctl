/** Entrypoint file for unit tests.
 *
 * @author Alec Matthews <alec500oo@gmail.com>
 */


#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>

#include <cmocka.h>

#include "motion_ctl.h"

static void null_test_success(void** state) {
  (void)state;
}

static void change_param_kp(void** state) {
  // Check the ability to change the control constants.
  MOTION_PARAMS param;
  param.kp = 1;
  assert_float_equal(param.kp, 1, 0.01);

  param.kp = 0.86;
  assert_float_equal(param.kp, 0.86, 0.01);
}

static void change_param_ki(void** state) {
  // Check the ability to change the control constants.
  MOTION_PARAMS param;
  param.ki = 0.56;
  assert_float_equal(param.ki, 0.56, 0.01);

  param.ki = 0.75;
  assert_float_equal(param.ki, 0.75, 0.01);
}

static void change_param_kd(void** state) {
  // Check the ability to change the control constants.
  MOTION_PARAMS param;
  param.kd = 0.75;
  assert_float_equal(param.kd, 0.75, 0.01);

  param.kd = 0.43;
  assert_float_equal(param.kd, 0.43, 0.01);
}

static void set_max_lim(void** state) {
  MOTION_PARAMS p;
  p.max_lim = 90;
  assert_float_equal(p.max_lim, 90, 0.01);

  p.max_lim = 75;
  assert_float_equal(p.max_lim, 75, 0.01);
}

static void set_min_lim(void** state) {
  MOTION_PARAMS p;

  p.min_lim = -90;
  assert_float_equal(p.min_lim, -90, 0.01);

  p.min_lim = -86;
  assert_float_equal(p.min_lim, -86, 0.01);
}

static void check_limits(void** state) {
  MOTION_PARAMS p;
  p.max_lim = 90;
  p.min_lim = -90;

  assert_true(CheckLimits(180, &p) < 0);
  assert_true(CheckLimits(60, &p) == 0);
}

static void preform_calculation(void** state) {
  MOTION_PARAMS p = {0};
  p.kp = 0.5;
  p.ki = 0.2;
  p.kd = 0;

  float c = CalculateCompensation(100, &p);

  assert_float_equal(c, 70.0, 0.01);

  c = CalculateCompensation(50, &p);

  assert_float_equal(c, 55.0, 0.01);

  c = CalculateCompensation(10, &p);

  assert_float_equal(c, 37.0, 0.01);
}

int main(void) {
  const struct CMUnitTest tests[] = {cmocka_unit_test(null_test_success),
                                     cmocka_unit_test(change_param_kp),
                                     cmocka_unit_test(change_param_ki),
                                     cmocka_unit_test(change_param_kd),
                                     cmocka_unit_test(set_max_lim),
                                     cmocka_unit_test(set_min_lim),
                                     cmocka_unit_test(check_limits),
                                     cmocka_unit_test(preform_calculation)};

  return cmocka_run_group_tests(tests, NULL, NULL);
}
