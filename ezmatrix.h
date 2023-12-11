#ifndef EZMATRIX_H
#define EZMATRIX_H

#include <stdint.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    uint16_t u16_rows;
    uint16_t u16_cols;
    float ** f_val;
} Matrix_t;

Matrix_t *create_matrix(uint16_t u16_numRows, uint16_t u16_numCols);
Matrix_t *create_simple_matrix(uint16_t u16_numRows, uint16_t u16_numCols, float f_num);
Matrix_t *create_random_matrix(uint16_t u16_numRows, uint16_t u16_numCols, int16_t s16_lowerBound, int16_t s16_upperBound);

Matrix_t *matrix_multiply(Matrix_t *a, Matrix_t *b);
Matrix_t *matrix_add(Matrix_t *a, Matrix_t *b);
Matrix_t *matrix_subtract(Matrix_t *a, Matrix_t *b);
Matrix_t *matrix_scalar_multiply(float f_scalar, Matrix_t *m);
Matrix_t *matrix_transpose(Matrix_t *m);

#endif
