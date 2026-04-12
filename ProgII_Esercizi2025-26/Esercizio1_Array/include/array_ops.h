#ifndef ARRAY_OPS_H
#define ARRAY_OPS_H

#define DOUBLE_FMT "%.2f"

/* Versioni ricorsive */
void print_array_recursive(const double *data, unsigned int length);
double sum_array_recursive(const double *data, unsigned int length);
double average_array_recursive(const double *data, unsigned int length);
void min_max_array_recursive(const double *data, unsigned int length,
                             double *min, double *max);
int is_sorted_array_recursive(const double *data, unsigned int length);

/* Versioni iterative */
void print_array_iterative(const double *data, unsigned int length);
double sum_array_iterative(const double *data, unsigned int length);
double average_array_iterative(const double *data, unsigned int length);
void min_max_array_iterative(const double *data, unsigned int length,
                             double *min, double *max);
int is_sorted_array_iterative(const double *data, unsigned int length);

#endif /* ARRAY_OPS_H */
