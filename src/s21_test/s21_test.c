#include "s21_test.h"

void run_testcase(Suite *testcase) {
  SRunner *sr = srunner_create(testcase);
  // srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

void run_all_tests(void) {
  Suite *list_cases[] = {suite_memchr(),
                         suite_memcmp(),
                         suite_memcpy(),
                         suite_memset(),
                         suite_sprintf(),
                         suite_strncat(),
                         suite_strrchr(),
                         suite_strchr(),
                         suite_strncmp(),
                         suite_strncpy(),
                         suite_strcspn(),
                         suite_strlen(),
                         suite_strpbrk(),
                         suite_strstr(),
                         suite_strtok(),
                         suite_strerror(),
                         suite_to_upper(),
                         suite_to_lower(),
                         suite_insert(),
                         suite_trim(),

                         NULL};

  for (int i = 0; list_cases[i] != NULL; i++) {
    run_testcase(list_cases[i]);
  }
}

int main(void) {
  run_all_tests();
  return 0;
}
