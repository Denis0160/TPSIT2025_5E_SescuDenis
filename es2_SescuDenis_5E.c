#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s1[100], s2[100];
    char pari[100], dispari[100];
    char c;
    int i, len, count = 0, vocali1 = 0, vocali2 = 0, cons1 = 0, cons2 = 0;

    printf("Inserisci la prima stringa: ");
    scanf("%s", s1);

    int solo_lettere = 1;
    for (i = 0; s1[i]; i++) {
        if (!isalpha(s1[i])) {
            solo_lettere = 0;
            break;
        }
    }
    if (solo_lettere)
        printf("Contiene solo lettere\n");
    else
        printf("Contiene anche altri caratteri\n");

    printf("Inserisci una lettera da contare: ");
    scanf(" %c", &c);
    count = 0;
    for (i = 0; s1[i]; i++) {
        if (s1[i] == c)
            count++;
    }
    printf("La lettera '%c' compare %d volte\n", c, count);

    int p = 0, d = 0;
    for (i = 0; s1[i]; i++) {
        if (i % 2 == 0)
            pari[p++] = s1[i];
        else
            dispari[d++] = s1[i];
    }
    pari[p] = '\0';
    dispari[d] = '\0';

    printf("Lettere in posizione pari: %s\n", pari);
    printf("Lettere in posizione dispari: %s\n", dispari);

    int doppie = 0;
    for (i = 0; s1[i + 1]; i++) {
        if (s1[i] == s1[i + 1]) {
            doppie = 1;
            break;
        }
    }
    if (doppie)
        printf("Contiene doppie\n");
    else
        printf("Non contiene doppie\n");

    printf("Inserisci la seconda stringa: ");
    scanf("%s", s2);

    int len1 = strlen(s1), len2 = strlen(s2);
    if (len1 > len2)
        printf("La prima stringa è più lunga\n");
    else if (len2 > len1)
        printf("La seconda stringa è più lunga\n");
    else
        printf("Le due stringhe hanno la stessa lunghezza\n");

    printf("Lettere comuni: ");
    for (i = 0; s1[i]; i++) {
        for (int j = 0; s2[j]; j++) {
            if (s1[i] == s2[j]) {
                printf("%c ", s1[i]);
                break;
            }
        }
    }
    printf("\n");

    for (i = 0; s1[i]; i++) {
        char ch = tolower(s1[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            vocali1++;
        else
            cons1++;
    }

    for (i = 0; s2[i]; i++) {
        char ch = tolower(s2[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            vocali2++;
        else
            cons2++;
    }

    if (vocali1 > vocali2)
        printf("La prima stringa ha più vocali\n");
    else if (vocali2 > vocali1)
        printf("La seconda stringa ha più vocali\n");
    else
        printf("Hanno lo stesso numero di vocali\n");

    if (cons1 > cons2)
        printf("La prima stringa ha più consonanti\n");
    else if (cons2 > cons1)
        printf("La seconda stringa ha più consonanti\n");
    else
        printf("Hanno lo stesso numero di consonanti\n");

    return 0;
}
