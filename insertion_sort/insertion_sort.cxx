// An implementation of insertion sort on integers in an array.

#include <iostream>             // std::cout, std::endl

void print_array(int* array, const int& size);
void insertion_sort(int* array, const int& size);

int main(void)
{
    const int array_size = 10;

    // Create a randomized integer array of specified size.
    int array[array_size] = { 4, 3, 1, 2, 0, 9, 7, 5, 6, 8 };

    // Show user how the array looks before sorting.
    print_array(array, array_size);

    // Sort array with insertion sort.
    insertion_sort(array, array_size);

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

void insertion_sort(int* array, const int& size)
{
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = i; j > 0; j--) {
            if (array[j] < array[j-1]) {
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            } else {
                break;
            }
        }
    }
}
