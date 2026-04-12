#include "../include/array_ops.h"

#include <limits.h>
#include <stdio.h>

int main(void) {
  double arr1[] = {0.76, 1.11, 2.33, 3.42, 102.45, 5.98, 99.992, 82.883};
  unsigned int arr1Len = sizeof(arr1) / sizeof(arr1[0]);

  double arr2[] = {0.92, 1.23, 2.34, 5.49};
  unsigned int arr2Len = sizeof(arr2) / sizeof(arr2[0]);

  // print array iterative
  printf("Array 1 (iterative):\n");
  print_array_iterative(arr1, arr1Len);

  printf("\n");

  printf("Array 1 (recursive):\n");
  print_array_recursive(arr1, arr1Len);

  printf("\n");

  printf("Array 2 (iterative):\n");
  print_array_iterative(arr2, arr2Len);

  printf("\n");

  printf("Array 2 (recursive):\n");
  print_array_recursive(arr2, arr2Len);

  printf("\n");

  // sum array iterative
  printf("sum_array_iterative(arr1, arr1Len) ");
  printf(DOUBLE_FMT "\n", sum_array_iterative(arr1, arr1Len));

  printf("sum_array_recursive(arr1, arr1Len) ");
  printf(DOUBLE_FMT "\n", sum_array_recursive(arr1, arr1Len));

  printf("sum_array_iterative(arr2, arr2Len) ");
  printf(DOUBLE_FMT "\n", sum_array_iterative(arr2, arr2Len));

  printf("sum_array_recursive(arr2, arr2Len) ");
  printf(DOUBLE_FMT "\n", sum_array_recursive(arr2, arr2Len));

  // average array iterative
  printf("average_array_iterative(arr1, arr1Len) ");
  printf(DOUBLE_FMT "\n", average_array_iterative(arr1, arr1Len));

  printf("average_array_recursive(arr1, arr1Len) ");
  printf(DOUBLE_FMT "\n", average_array_recursive(arr1, arr1Len));

  // min max array iterative
  double min, max = 0;
  printf("min_max_array_iteratve(arr1, arrLen1) ");
  min_max_array_iterative(arr1, arr1Len, &min, &max);
  printf("min: " DOUBLE_FMT " - max: " DOUBLE_FMT "\n", min, max);

  min = 0;
  max = 0;
  printf("min_max_array_recursive(arr1, arrLen1) ");
  min_max_array_recursive(arr1, arr1Len, &min, &max);
  printf("min: " DOUBLE_FMT " - max: " DOUBLE_FMT "\n", min, max);

  min = 0;
  max = 0;
  printf("min_max_array_iterative(arr2, arrLen2) ");
  min_max_array_iterative(arr2, arr2Len, &min, &max);
  printf("min: " DOUBLE_FMT " - max: " DOUBLE_FMT "\n", min, max);

  min = 0;
  max = 0;
  printf("min_max_array_recursive(arr2, arrLen2) ");
  min_max_array_recursive(arr2, arr2Len, &min, &max);
  printf("min: " DOUBLE_FMT " - max: " DOUBLE_FMT "\n", min, max);

  // is sorted array iterative
  printf("is_sorted_array_iterative(arr1, arr1Len) ");
  printf("%s\n", is_sorted_array_iterative(arr1, arr1Len) ? "Yes" : "No");

  printf("is_sorted_array_iterative(arr1, arr1Len) ");
  printf("%s\n", is_sorted_array_iterative(arr1, arr1Len) ? "Yes" : "No");

  printf("is_sorted_array_iterative(arr2, arr2Len) ");
  printf("%s\n", is_sorted_array_iterative(arr2, arr2Len) ? "Yes" : "No");

  printf("is_sorted_array_iterative(arr2, arr2Len) ");
  printf("%s\n", is_sorted_array_iterative(arr2, arr2Len) ? "Yes" : "No");
  return 0;
}
