// An implementation of selection sort on integers in an array.

#include <iostream>             // std::cout, std::endl

void print_array(int* array, const int& size);
void selection_sort(int* array, const int& size);

int main(void)
{
    const int array_size = 10;

    // Create a randomized integer array of specified size.
    int array[array_size] = { 4, 3, 1, 2, 0, 9, 7, 5, 6, 8 };

    // Show user how the array looks before sorting.
    print_array(array, array_size);

    // Sort array with selection sort.
    selection_sort(array, array_size);

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

void selection_sort(int* array, const int& size)
{
    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        if (array[min] < array[i]) {
            std::swap(array[i], array[min]);
        }
    }
}
