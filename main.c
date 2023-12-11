#include "ezmatrix.h"
#include <stdio.h>
#include <time.h>

void print(Matrix_t *m)
{
    for (int i = 0; i < m->u16_rows; i++) {
        for (int j = 0; j < m->u16_cols; j++) {
            printf("%f ", m->f_val[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}


int main (void) 
{
    srand(time(0)); 
    Matrix_t *a = create_random_matrix(3, 3, 0, 10);
    Matrix_t *b = create_random_matrix(3, 3, 0, 10);

    Matrix_t *c = matrix_transpose(a);

    print(a);
    //print(b);
    print(c);

    return 0;
}
