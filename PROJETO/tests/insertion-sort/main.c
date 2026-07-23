#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *vet, int size);
void FIRSTVERSIONinsertionSort(int *vet, int size);
void SECONDVERSIONinsertionSort(int *vet, int size);
void swap(int *pos1, int *pos2);

int main()
{
    int vet[10] = {1, 4, 2, 10, 8, 45, 12, 5, 33, 0};
    int vet1[3] = {1, 4, 2};

    for (int i = 0; i < 10; i++)
    {
        printf("[%d]", vet[i]);
    }
    printf("\n\n");

    insertionSort(vet, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("[%d]", vet[i]);
    }
}

void swap(int *pos1, int *pos2)
{
    int temp = *pos1;
    *pos1 = *pos2;
    *pos2 = temp;
}

void SECONDVERSIONinsertionSort(int *vet, int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0 && vet[j] < vet[j - 1]; j--)
        {
            swap(&vet[j], &vet[j - 1]);
        }
    }
}

void FIRSTVERSIONinsertionSort(int *vet, int size)
{
    int sizeSec;
    for (int i = 1; i < size; i++)
    {
        if (vet[i] < vet[i - 1])
        {
            sizeSec = i;
            for (int j = sizeSec; j > 0; j--)
            {
                if (vet[j] < vet[j - 1])
                {
                    swap(&vet[j], &vet[j - 1]);
                }
                else
                {
                    break;
                }
            }
        }
    }
}

//final version
void insertionSort(int *vet, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = vet[i];
        int j = i - 1;
        while (j >= 0 && vet[j] > key)
        {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = key;
    }
}

