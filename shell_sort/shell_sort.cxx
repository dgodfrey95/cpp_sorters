// An implementation of shell sort on integers in an array.

#include <iostream>             // std::cout, std::endl

void print_array(int* array, const int& size);
void shell_sort(int* array, const int& size);

int main(void)
{
    const int array_size = 10;

    // Create a randomized integer array of specified size.
    int array[array_size] = { 4, 3, 1, 2, 0, 9, 7, 5, 6, 8 };

    // Show user how the array looks before sorting.
    print_array(array, array_size);

    // Sort array with shell sort.
    shell_sort(array, array_size);

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

void shell_sort(int* array, const int& size)
{
    int h = 1;

    // Following Donald Knuth, h = 3h + 1.
    while (h < size/3) {
        h = 3 * h + 1;
    }

    while (h >= 1) {
        for (int i = h; i < size; i++) {
            for (int j = i; j >= h && array[j] < array[j - h]; j -= h) {
                std::swap(array[j], array[j - h]);
            }
        }
        h = h / 3;
    }
}
