#include"../includes/helpers.h"

void unsort(int *vet, int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        int rd = (rand() % 5);

        swap(&vet[i], &vet[rd]);
    }
}

int isSorted(int *vet, int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        if (vet[i] > vet[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void swap(int *pos1, int *pos2)
{
    int temp = *pos1;
    *pos1 = *pos2;
    *pos2 = temp;
}
