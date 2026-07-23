#include <stdio.h>
#include <stdlib.h>

#define TAM(v) ((int)(sizeof(v) / sizeof((v)[0])))

void quickSort(int *vet, int ini, int fim);
int partition(int *vet, int ini, int fim);
void swap(int *pos1, int *pos2);
int medianaDeTres(int *vet, int ini, int fim);

void printVet(int *vet, int ini, int fim);

int main()
{

    int vetTe[20] = {1, 4, 2, 10, 10, 45, 12, 10, 33, 0, 1, 4, 2, 10, 10, 45, 12, 10, 33, 0};
    int vet1[3] = {1, 4, 2};
    int vet2[5] = {1, 4, 2, 3, 5};
    int vetC[7] = {5, 3, 8, 1, 9, 2, 7};
    int vet3[2] = {1, 2};

    int *vetvets[5] = {vetTe, vet1, vet2, vetC, vet3};
    int tams[5] = {TAM(vetTe), TAM(vet1), TAM(vet2), TAM(vetC), TAM(vet3)};

    for (int i = 0; i < 5; i++)
    {
        int tam = tams[i];

        printf("teste #%d\n\n\n", i + 1);

        printf("caso teste:\n");
        printVet(vetvets[i], 0, tam - 1);

        quickSort(vetvets[i], 0, tam - 1);
        printf("apos quickSort:\n");
        printVet(vetvets[i], 0, tam - 1);
        printf("\n\n");
    }
}

void quickSort(int *vet, int ini, int fim)
{
    if (ini < fim)
    {
        int ordened = partition(vet, ini, fim);
        quickSort(vet, ini, ordened - 1);
        quickSort(vet, ordened + 1, fim);
    }
}

int partition(int *vet, int ini, int fim)
{
    int pivo = medianaDeTres(vet, ini, fim);
    int i = ini, j = fim;

    while (i < j)
    {
        while (i < j && vet[i] <= pivo)
            i++;

        while (i < j && vet[j] > pivo)
            j--;

        if (i < j)
            swap(&vet[i], &vet[j]);
    }

    if (vet[i] > pivo)
        i--;

    swap(&vet[ini], &vet[i]);
    return i;
}

void swap(int *pos1, int *pos2)
{
    int temp = *pos1;
    *pos1 = *pos2;
    *pos2 = temp;
}

int medianaDeTres(int *vet, int ini, int fim)
{
    int meio = ini + (fim - ini) / 2;

    if (vet[meio] < vet[ini])
        swap(&vet[meio], &vet[ini]);
    if (vet[fim] < vet[ini])
        swap(&vet[fim], &vet[ini]);
    if (vet[fim] < vet[meio])
        swap(&vet[fim], &vet[meio]);

    swap(&vet[meio], &vet[ini]);
    return vet[ini];
}

void printVet(int *vet, int ini, int fim)
{
    printf("vet = [");
    for (int i = ini; i <= fim; i++)
    {
        printf("%d, ", vet[i]);
    }
    printf("]\n");
}