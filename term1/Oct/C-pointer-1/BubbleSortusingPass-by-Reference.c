#include <stdio.h>
#define SIZE 10

void bubbleSort(int *const array, size_t size);

int main(void)
{
    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
    size_t i;
    puts("Data items in original order");
    for (i = 0; i < SIZE; ++i)
    {
        printf("%4d", a[i]);
    }
    bubbleSort(a, SIZE);

    puts("In Data items in ascending order");
    // loop through array a
    for (i = 0; i < SIZE; ++i)
    {
        printf("%4d", a[i]);
    }

    puts("");
}

void bubbleSort(int *const array, size_t size)
{
    void swap(int *element1ptr, int *element2Ptr); // prototype
    unsigned int pass;                             // pass counter
    size_t j;                                      // comparison counter
    // 1oop to control passes
    for (pass = 0; pass < size - 1; + pass)
    {
        // 1oop to contro1 comparisons during each pass
        for (j = 0; j < size - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void swap(int *element1Ptr, int *element2Ptr)
{
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}
