#include <stdlib.h>
#include <stdio.h>

void merge(int *vet, int ini, int meio, int fim);
void mergeSort(int *vet, int ini, int fim);

int main()
{
    int vet[10] = {1, 4, 2, 10, 10, 45, 12, 10, 33, 0};
    int vet1[3] = {1, 4, 2};
    int vet2[5] = {1, 4, 2, 3, 5};

    for (int i = 0; i < 10; i++)
    {
        printf("[%d]", vet[i]);
    }
    printf("\n\n");

    mergeSort(vet, 0, 9);

    for (int i = 0; i < 10; i++)
    {
        printf("[%d]", vet[i]);
    }
}

void mergeSort(int *vet, int ini, int fim)
{
    if (ini < fim)
    {
        int meio = ini + (fim - ini) / 2;
        mergeSort(vet, ini, meio);
        mergeSort(vet, (meio + 1), fim);
        merge(vet, ini, meio, fim);
    }
}

void merge(int *vet, int ini, int meio, int fim)
{
    int sizeLeft = meio - ini + 1;
    int sizeRight = fim - meio;

    int *right = malloc(sizeRight * sizeof(int));
    int *left = malloc(sizeLeft * sizeof(int));

    for (int i = 0; i < sizeLeft; i++)
    {
        left[i] = vet[ini + i];
    }
    for (int i = 0; i < sizeRight; i++)
    {
        right[i] = vet[(meio + 1) + i];
    }

    int i = 0, j = 0, k = ini;
    while (i < sizeLeft && j < sizeRight)
    {
        if (right[j] <= left[i])
        {
            vet[k++] = right[j++];
        }
        else
        {
            vet[k++] = left[i++];
        }
    }
    while (i < sizeLeft)
    {
        vet[k++] = left[i++];
    }
    while (j < sizeRight)
    {
        vet[k++] = right[j++];
    }

    free(right);
    free(left);
}