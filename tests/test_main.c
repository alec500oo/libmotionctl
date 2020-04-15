/** Entrypoint file for unit tests. 
 * 
 * @author Alec Matthews <alec500oo@gmail.com>
 */

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "motion_ctl.h"

static void null_test_success(void** state) {
  (void) state;
}

static void change_param(void** state) {
  // Check the ability to change the control constants.
  MOTION_PARAMS param;
  param.kp = 1;
  param.ki = 0.56;
  param.kd = 0.75;

  assert_float_equal(param.kp, 1, 0.01);
  assert_float_equal(param.ki, 0.56, 0.01);
  assert_float_equal(param.kd, 0.76, 0.01);
}

static void check_limits(void** state) {
  MOTION_PARAMS p;
  p.max_lim = 90;
  p.min_lim = -90;

  assert_float_equal(p.max_lim, 90, 0.01);
  assert_float_equal(p.min_lim, -90, 0.01);

  assert_true(CheckLimits(180, &p) < 0);
  assert_true(CheckLimits(60, &p) == 0);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(null_test_success),
    cmocka_unit_test(change_param),
    cmocka_unit_test(check_limits)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
