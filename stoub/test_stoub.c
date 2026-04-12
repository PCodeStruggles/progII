#include <stdbool.h>
#include <stdio.h>

#include "stoub.h"

typedef struct {
  char *s;
  int b;
  int expected;
  int r;
} test_case;

int main(void) {
  test_case tests[] = {
      {"101", 2, 5, 0},      {"  11", 2, 3, 0},       {"  21", 3, 7, 0},
      {"a  21", 3, 0, 0},    {"102", 3, 11, 0},       {"112a", 3, 14, 0},
      {"253", 7, 136, 0},    {"1A3", 16, 419, 0},     {"2F5", 16, 757, 0},
      {"2B4", 21, 1117, 0},  {"2B4 a", 21, 1117, 0},  {"1B5 a", 27, 1031, 0},
      {"ABA", 2, 0, 0},      {"", 2, 0, 0},           {"9A", 10, 9, 0},
      {"A9", 10, 0, 0},      {" ", 2, 0, 0},          {"1YO a", 36, 2544, 0},
      {"1YaO", 36, 70, 0},   {"aba", 25, 0, 0},       {"AA", 47, 0, 0},
      {"-1YaO", 36, -70, 0}, {"-1234", 10, -1234, 0}, {"-a1234", 10, 0, 0},
      {"- 10", 10, 0, 0},    {"-", 12, 0, 0}};

  bool all_passed = true;
  size_t num_tests = sizeof(tests) / sizeof(tests[0]);
  for (size_t i = 0; all_passed && i < num_tests; i++) {
    int output = stoub(tests[i].s, tests[i].b, &tests[i].r);
    if (tests[i].r != tests[i].expected) {
      printf("Test %zu failed\n", i);
      printf("s:        %s\n", tests[i].s);
      printf("b:        %d\n", tests[i].b);
      printf("expected: %d\n", tests[i].expected);
      printf("got:      %d\n", tests[i].r);
      all_passed = false;
    }
  }
  if (all_passed) {
    printf("All tests %zu passed ✓\n", num_tests);
  }
  return 0;
}
