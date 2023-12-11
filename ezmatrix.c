#include "ezmatrix.h"
#include <math.h>
#include <stdint.h>

Matrix_t *create_matrix(uint16_t u16_numRows, uint16_t u16_numCols)
{
    Matrix_t *newMatrix = (Matrix_t *) malloc(sizeof(Matrix_t));
    
    newMatrix->u16_rows = u16_numRows;
    newMatrix->u16_cols = u16_numCols;
    newMatrix->f_val = (float **) malloc(u16_numRows * (sizeof(float *)));

    for (uint16_t i = 0; i < u16_numRows; i++) {
        newMatrix->f_val[i] = (float *) malloc(u16_numCols * (sizeof(float *)));
    }
    
    return newMatrix;
}

Matrix_t *create_simple_matrix(uint16_t u16_numRows, uint16_t u16_numCols, float f_num)
{
    Matrix_t *newMatrix = create_matrix(u16_numRows, u16_numCols);

    for (uint16_t i = 0; i < u16_numRows; i++) {
        for (uint16_t j = 0; j < u16_numCols; j++) {
            newMatrix->f_val[i][j] = f_num;
        }
    }

    return newMatrix;
}

Matrix_t *create_random_matrix(uint16_t u16_numRows, uint16_t u16_numCols, int16_t s16_lowerBound, int16_t s16_upperBound)
{
    Matrix_t *newMatrix = create_matrix(u16_numRows, u16_numCols);

    for (uint16_t i = 0; i < u16_numRows; i++) {
        for (uint16_t j = 0; j < u16_numCols; j++) {
            newMatrix->f_val[i][j] = (float) (rand() % (s16_upperBound - s16_lowerBound + 1)) + s16_lowerBound;
        }
    }

    return newMatrix;
}

Matrix_t *matrix_multiply(Matrix_t *a, Matrix_t *b)
{
    if (a->u16_cols != b->u16_rows) {
        return NULL;
    }
    
    Matrix_t *c = create_matrix(a->u16_rows, b->u16_cols);

    for (uint16_t i = 0; i < a->u16_rows; i++) {
        for (uint16_t j = 0; j < b->u16_cols; j++) {
            for (uint16_t k = 0; k < a->u16_cols; k++) {
                c->f_val[i][j] += a->f_val[i][k] * b->f_val[k][j];
            }
        }
    }

    return c;
}


Matrix_t *matrix_add(Matrix_t *a, Matrix_t *b)
{
    if ((a->u16_cols != b->u16_cols) || (a->u16_rows != b->u16_rows)) {
        return NULL;
    }

    Matrix_t *c = create_matrix(a->u16_rows, a->u16_cols);

    for (uint16_t i = 0; i < a->u16_rows; i++) {
        for (uint16_t j = 0; j < a->u16_cols; j++) {
            c->f_val[i][j] = a->f_val[i][j] + b->f_val[i][j];
        }
    }

    return c;
}

Matrix_t *matrix_subtract(Matrix_t *a, Matrix_t *b)
{
    if ((a->u16_cols != b->u16_cols) || (a->u16_rows != b->u16_rows)) {
        return NULL;
    }

    Matrix_t *c = create_matrix(a->u16_rows, a->u16_cols);

    for (uint16_t i = 0; i < a->u16_rows; i++) {
        for (uint16_t j = 0; j < a->u16_cols; j++) {
            c->f_val[i][j] = a->f_val[i][j] - b->f_val[i][j];
        }
    }

    return c;
}

Matrix_t *matrix_scalar_multiply(float f_scalar, Matrix_t *m)
{
    Matrix_t *c = create_matrix(m->u16_rows, m->u16_cols);

    for (uint16_t i = 0; i < m->u16_rows; i++) {
        for (uint16_t j = 0; j < m->u16_cols; j++) {
            c->f_val[i][j] = m->f_val[i][j] * f_scalar;
        }
    }

    return c;
}

Matrix_t *matrix_transpose(Matrix_t *m)
{
    Matrix_t *c = create_matrix(m->u16_rows, m->u16_cols);

    for (uint16_t i = 0; i < m->u16_rows; i++) {
        for (uint16_t j = 0; j < m->u16_cols; j++) {
            c->f_val[j][i] = m->f_val[i][j];
        }
    }

    return c;
}


