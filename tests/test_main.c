/** Entrypoint file for unit tests. 
 * 
 * @author Alec Matthews <alec500oo@gmail.com>
 */

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "pid/pid.h"

static void null_test_success(void** state) {
  TestFunc();
  (void) state;
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(null_test_success)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
