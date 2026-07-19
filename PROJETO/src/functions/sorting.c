#include"../../includes/helpers.h"
#include"../../includes/sorting.h"
#include <stdlib.h>

void bubbleSortOtimized(int *vet, int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        int trocas = 0;

        for (int j = 0; j < (size - 1 - i); j++)
        {
            if (vet[j] > vet[j + 1])
            {
                swap(&vet[j], &vet[j + 1]);
                trocas = 1;
            }
        }
        if (!trocas)
            break;
    }
}

void bubbleSortClassic(int *vet, int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        for (int j = 0; j < (size - 1); j++)
        {
            if (vet[j] > vet[j + 1])
            {
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
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

void doubleSelectionSort(int *vet, int size)
{
    int left = 0, right = size - 1;

    while (left < right)
    {
        int min = left, max = left;

        for (int j = left; j <= right; j++)
        {
            if (vet[j] < vet[min])
                min = j;

            if (vet[j] > vet[max])
                max = j;
        }
        swap(&vet[left], &vet[min]);

        if (max == left)
            max = min;

        swap(&vet[right], &vet[max]);

        left++;
        right--;
    }
}