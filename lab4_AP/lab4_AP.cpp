#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

bool check_min_non_recursive(double[], int);
void deleterow_non_recursion(double*, int*, int);
void inp_matrix(double*, int*, int*);
void print_matrix(double* arr, int Rn, int Cn, const char[]);

int main() {
    system("chcp 1251"); system("cls");
    double matrix[N][N];
    int Rn, Cn;

    inp_matrix(*matrix, &Rn, &Cn);
    print_matrix(*matrix, Rn, Cn, "Введена");

    deleterow_non_recursion(*matrix, &Rn, Cn);
    print_matrix(*matrix, Rn, Cn, "Відредагована");

    return 0;
}

void inp_matrix(double* arr, int* Rn, int* Cn) {
    int i, j;
    printf("Введіть розмірність матриці(а,b < %d): ", N);
    scanf_s("%d%d", Rn, Cn);
    printf("Вводьте елементи матриці:\n");
    for (i = 0; i < *Rn; i++) {
        for (j = 0; j < *Cn; j++) {
            scanf_s("%lf", arr+i*N+j);
        }
    }
}

void print_matrix(double* arr, int Rn, int Cn, const char s[]) {
    printf("\n%s матриця:\n", s);
    for (int i = 0; i < Rn; i++) {
        for (int j = 0; j < Cn; j++) {
            printf("%6.2lf ", *(arr+i*N+j));
        }
        printf("\n");
    }
}

bool check_min_non_recursive(double arr[], int n) {
    for (double* ptr = arr; ptr < arr + n; ptr++) {
        if (*ptr < *(arr + n - 1)) return 0;
    }
    return 1;
}

void deleterow_non_recursion(double* arr, int* Rn, int Cn) {
    for (int i = 0; i < *Rn; i++) {
        if (!check_min_non_recursive(arr + i * N, Cn)) {
            for (int o = i + 1; o < *Rn; o++)
                for (int j = 0; j < Cn; ++j)
                    *((arr + (o - 1) * N) + j) = *((arr + o * N) + j);
            (*Rn)--;
            i--;
        }
    }
}


/*4 3
2 3 1
5 6 9
1 2 3
9 8 4

3 4
1.26 65 4.7 2.99
2.54 47 5.1 1.7
15.56 4 7.6 9.3

5 5
4 5 6 8 7
9 5 6 4 1
1 5 6 7 2
3 5 7 9 1
1 5 9 5 3
*/