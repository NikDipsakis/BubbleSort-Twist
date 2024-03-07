#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>

// Τσεκάρει αν οι αριθμοί είναι μοναδικοί
bool existsInArray(int array[], int size, int number)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == number)
        {
            return true;
        }
    }
    return false;
}
// BubbleSort 2.0
void bubbleSort(int *P, int *S, int size)
{
    int *tempArray = (int *)malloc(size * sizeof(int));

    // Αντιγραφή των στοιχείων στο προσωρινό πίνακα με τη σωστή σειρά
    for (int i = 0; i < size; i++)
    {
        tempArray[i] = P[S[i] - 1];
    }

    // Αντιγραφή των στοιχείων πίσω στον πίνακα P
    for (int i = 0; i < size; i++)
    {
        P[i] = tempArray[i];
    }

    free(tempArray);
}

int main()
{
    int *P, *S, N;
    system("chcp 65001>null");
    // Ζητάει από τον χρήστη πόσους αριθμούς θέλει να ταξινομήσει
    printf("Δώστε τον αριθμό των στοιχείων που θα θέλατε να ταξινομήσετε: ");
    scanf("%d", &N);

    P = (int *)malloc(N * sizeof(int));
    S = (int *)malloc(N * sizeof(int));
    // Ζητάει από τον χρήστη ποιους αριθμούς να ταξινομήσει
    printf("Εισάγετε τα στοιχεία που θελετε να ταξινομηθούν (P):\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &P[i]);
    }
    // Ζητάει άπο τον χρήστη να ορίσει την σειρά που θέλει να κατανεμηθούν οι αριθμοί
    printf("Εισάγετε μοναδικές τιμές από 1 έως %d για να καθορίσετε την σείρα των στοιχείων (S):\n", N);
    for (int i = 0; i < N;)
    {
        int num;
        scanf("%d", &num); // Αμυντικός προγραμματισμός
        if (num < 1 || num > N || existsInArray(S, i, num))
        {
            printf("Εχετε διαλέξει αυτήν την θέση, διαλέξτε έναν αριθμό που δεν έχετε.\n");
        }
        else
        {
            S[i++] = num;
        }
    }

    bubbleSort(P, S, N);
    // Τυπώνει τους αριθμούς που ζητήθηκαν απο τον χρήστη στην σειρά που ζήτησε
    printf("Ταξινομημένος πίνακας P:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", P[i]);
    }

    free(P);
    free(S);

    return 0;
}
