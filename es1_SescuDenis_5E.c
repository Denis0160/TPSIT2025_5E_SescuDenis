#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void visualizza(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void inverti(int v[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = v[i];
        v[i] = v[n - 1 - i];
        v[n - 1 - i] = temp;
    }
}

void somma_media(int v[], int n) {
    int somma = 0;
    for (int i = 0; i < n; i++) {
        somma += v[i];
    }
    float media = (float)somma / n;
    printf("Somma: %d\n", somma);
    printf("Media: %.2f\n", media);
}

void numeri_pari(int v[], int n) {
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            printf("%d ", v[i]);
        }
    }
    printf("\n");
}

void numeri_dispari(int v[], int n) {
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 != 0) {
            printf("%d ", v[i]);
        }
    }
    printf("\n");
}

void ricerca(int v[], int n, int num) {
    int trovato = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == num) {
            trovato = 1;
            break;
        }
    }
    if (trovato)
        printf("Numero trovato\n");
    else
        printf("Numero non trovato\n");
}

int elimina(int v[], int *n, int num) {
    for (int i = 0; i < *n; i++) {
        if (v[i] == num) {
            for (int j = i; j < *n - 1; j++) {
                v[j] = v[j + 1];
            }
            (*n)--;
            return 1;
        }
    }
    return 0;
}

void alterna(int v[], int n) {
    for (int i = 0; i < n - 1; i += 2) {
        int temp = v[i];
        v[i] = v[i + 1];
        v[i + 1] = temp;
    }
}

void bubble_sort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int main() {
    int v[MAX], n = 0, scelta, num;
    srand(time(NULL));
    printf("Inserisci la dimensione dell'array (max %d): ", MAX);
    scanf("%d", &n);
    printf("1) Inserisci manualmente\n2) Genera casualmente\nScelta: ");
    scanf("%d", &scelta);
    if (scelta == 1) {
        for (int i = 0; i < n; i++) {
            printf("Elemento %d: ", i + 1);
            scanf("%d", &v[i]);
        }
    } else {
        for (int i = 0; i < n; i++) {
            v[i] = rand() % 100;
        }
    }

    do {
        printf("\nMenu:\n");
        printf("1) Visualizza array\n");
        printf("2) Inverti array\n");
        printf("3) Somma e media\n");
        printf("4) Numeri pari\n");
        printf("5) Numeri dispari\n");
        printf("6) Ricerca numero\n");
        printf("7) Elimina numero\n");
        printf("8) Alterna elementi\n");
        printf("9) Ordina array\n");
        printf("0) Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        switch (scelta) {
            case 1:
                visualizza(v, n);
                break;
            case 2:
                inverti(v, n);
                visualizza(v, n);
                break;
            case 3:
                somma_media(v, n);
                break;
            case 4:
                numeri_pari(v, n);
                break;
            case 5:
                numeri_dispari(v, n);
                break;
            case 6:
                printf("Inserisci numero da cercare: ");
                scanf("%d", &num);
                ricerca(v, n, num);
                break;
            case 7:
                printf("Inserisci numero da eliminare: ");
                scanf("%d", &num);
                if (elimina(v, &n, num))
                    printf("Numero eliminato\n");
                else
                    printf("Numero non trovato\n");
                break;
            case 8:
                alterna(v, n);
                visualizza(v, n);
                break;
            case 9:
                bubble_sort(v, n);
                visualizza(v, n);
                break;
        }
    } while (scelta != 0);

    return 0;
}
