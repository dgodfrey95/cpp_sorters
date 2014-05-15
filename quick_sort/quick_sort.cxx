#include <utility>              // std::swap
#include <iostream>             // std::cout, std::endl
#include <algorithm>            // std::shuffle
#include <cstdlib>              // rand, srand
#include <ctime>                // time

void print_array(int* array, const int& size);
void quick_sort(int* array, const int& size);
void sort(int* array, int low, int high);
int partition(int* array, int low, int high);
void knuth_shuffle(int* array, const int& size);

int main(void)
{
    const int array_size = 10;

    // Create a randomized integer array of specified size.
    int array[array_size] = { 4, 3, 1, 2, 0, 9, 7, 5, 6, 8 };

    // Show user how the array looks before sorting.
    print_array(array, array_size);

    // Sort array with quick sort.
    quick_sort(array, array_size);

    // Show user how the array looks after sorting.
    print_array(array, array_size);
}

void print_array(int* array, const int& size)
{
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void quick_sort(int* array, const int& size)
{
    // Randomize the array using the Knuth shuffle.
    knuth_shuffle(array, size);

    sort(array, 0, size - 1);
}

void sort(int* array, int low, int high)
{
    if (high <= low)
        return;

    // Partition the array.
    int j = partition(array, low, high);

    sort(array, low, j - 1);
    sort(array, j + 1, high);
}

int partition(int* array, int low, int high)
{
    int i = low;
    int j = high + 1;

    while (1) {
        // Find leftwards item to swap.
        while (array[++i] < array[low]) {
            if (i == high)
                break;
        }
        //  Find rightwards item to swap.
        while (array[low] < array[--j]) {
            if (j == low)
                break;
        }
    
        if (i >= j)
            break;
        std::swap(array[i], array[j]);
    }
    std::swap(array[low], array[j]);
    return j;
}

void knuth_shuffle(int* array, const int& size)
{
    // Initialize random generator.
    srand(time(NULL));
    
    for (int i = 0; i < size; i++) {
        // Get a random index between 0 and i.
        int rnd = rand() % (i + 1);

        // Swap values at index i and rnd.
        std::swap(array[i], array[rnd]);
    }  
}
