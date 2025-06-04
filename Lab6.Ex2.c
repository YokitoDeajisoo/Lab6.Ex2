#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Ukrainian");

    int n, choice;
    int a[100][100];

    do {
        printf("\n=== МЕНЮ ===\n");
        printf("1 — Ввести матрицю вручну\n");
        printf("2 — Згенерувати випадкову матрицю з чисел {-1, 0, 1}\n");
        printf("3 — Вийти\n");
        printf("Ваш вибiр: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            printf("Введiть розмiр квадратної матрицi (n): ");
            scanf("%d", &n);

            if (n <= 0 || n > 100) {
                printf("Неприпустимий розмiр.\n");
                continue;
            }

            if (choice == 1) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("a[%d][%d] = ", i, j);
                        scanf("%d", &a[i][j]);
                    }
                }
            }
            else {
                srand((unsigned int)time(NULL));
                printf("Згенерована матриця:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        a[i][j] = (rand() % 3) - 1; // -1, 0 або 1
                        printf("%4d", a[i][j]);
                    }
                    printf("\n");
                }
            }

            int isOrthonormal = 1;

            // Перевірка скалярного добутку кожного рядка на себе
            for (int i = 0; i < n; i++) {
                int dot = 0;
                for (int j = 0; j < n; j++) {
                    dot += a[i][j] * a[i][j];
                }
                if (dot != 1) {
                    isOrthonormal = 0;
                    break;
                }
            }

            // Перевірка скалярного добутку різних рядків
            for (int i = 0; i < n && isOrthonormal; i++) {
                for (int j = i + 1; j < n; j++) {
                    int dot = 0;
                    for (int k = 0; k < n; k++) {
                        dot += a[i][k] * a[j][k];
                    }
                    if (dot != 0) {
                        isOrthonormal = 0;
                        break;
                    }
                }
            }

            if (isOrthonormal) {
                printf("Матриця є ортонормованою.\n");
            }
            else {
                printf("Матриця НЕ є ортонормованою.\n");
            }

        }
        else if (choice == 3) {
            printf("Завершення програми.\n");
        }
        else {
            printf("Невiрний вибiр. Спробуйте ще раз.\n");
        }

    } while (choice != 3);

    return 0;
}
