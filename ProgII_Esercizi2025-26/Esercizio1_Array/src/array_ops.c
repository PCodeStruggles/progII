#include "../include/array_ops.h"

#include <float.h>
#include <stdio.h>

/* Versioni ricorsive */
void print_array_recursive(const double *data, unsigned int length) {
  if (length == 0) {
  } else {
    printf(DOUBLE_FMT " ", *data);
    print_array_recursive(data + 1, length - 1);
  }
}

double sum_array_recursive(const double *data, unsigned int length) {
  double ret = 0;
  if (length == 0) {
  } else {
    ret += sum_array_recursive(data + 1, length - 1);
    ret += *data;
  }
  return ret;
}

double average_array_recursive(const double *data, unsigned int length) {
  if (data == NULL || length == 0)
    return 0;
  double sum = sum_array_recursive(data, length);
  return sum / length;
}

void min_max_array_recursive(const double *data, unsigned int length,
                             double *min, double *max) {
  if (data == NULL || length == 0) {
    *min = DBL_MIN;
    *max = DBL_MAX;
    return;
  }
  if (length == 1) {
    *min = *data;
    *max = *data;
  } else {
    min_max_array_recursive(data + 1, length - 1, min, max);
    if (*data > *max) {
      *max = *data;
    }
    if (*data < *min) {
      *min = *data;
    }
  }
}

int is_sorted_array_recursive(const double *data, unsigned int length) {
  int ret = 0;
  if (length == 0) {
  } else {
    ret = *data > *(data + 1);
    ret = ret && is_sorted_array_recursive(data + 1, length - 1);
  }
  return ret;
}

/* Versioni iterative */
void print_array_iterative(const double *data, unsigned int length) {
  if (data == NULL || length == 0)
    return;
  for (size_t i = 0; i < length; i++)
    printf(DOUBLE_FMT " ", data[i]);
}

double sum_array_iterative(const double *data, unsigned int length) {
  double ret = 0;
  if (data == NULL || length == 0)
    return ret;
  for (size_t i = 0; i < length; i++)
    ret += data[i];
  return ret;
}

double average_array_iterative(const double *data, unsigned int length) {
  double acc = 0;
  if (data == NULL || length == 0)
    return acc;
  for (size_t i = 0; i < length; i++)
    acc += data[i];
  return acc / length;
}

void min_max_array_iterative(const double *data, unsigned int length,
                             double *min, double *max) {
  if (data == NULL || length == 0) {
    *min = DBL_MIN;
    *max = DBL_MAX;
    return;
  }
  *min = data[0];
  *max = data[0];
  for (size_t i = 1; i < length; i++) {
    if (data[i] > *max)
      *max = data[i];
    if (data[i] < *min)
      *min = data[i];
  }
  return;
}

int is_sorted_array_iterative(const double *data, unsigned int length) {
  if (data == NULL || length == 0)
    return 0;
  int ret = 1;
  for (size_t i = 1; ret && i < length; i++) {
    if (data[i] < data[i - 1])
      ret = 0;
  }
  return ret;
}
