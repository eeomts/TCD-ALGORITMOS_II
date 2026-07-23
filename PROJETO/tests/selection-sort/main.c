#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *vet, int size);
void swap(int *pos1, int *pos2);

int main()
{
    int vet[10] = {12, 45, 67, 23, 2, 5, 9, 87, 11, 1};

    for (int i = 0; i < sizeof(vet) / sizeof(vet[0]); i++)
    {
        printf("[%d]", vet[i]);
    }
    printf("\n");

    selectionSort(vet, 10);

    for (int i = 0; i < sizeof(vet) / sizeof(vet[0]); i++)
    {
        printf("[%d]", vet[i]);
    }
}

void selectionSort(int *vet, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (vet[j] < vet[min])
            {
                min = j;
            }
        }
        if (min != i)
            swap(&vet[i], &vet[min]);
    }
}

void swap(int *pos1, int *pos2)
{
    int temp = *pos1;
    *pos1 = *pos2;
    *pos2 = temp;
}






