// An implementation of the Knuth shuffle (aka. Fisher-Yates).
//
// See http://en.wikipedia.org/wiki/Fisher–Yates_shuffle 
// or Donald Knuth's "The Art of Computer Programming", Vol. 2, 3rd ed., 1998,
// p. 145-146.

#include <utility>              // std::swap
#include <iostream>             // cout, endl
#include <cstdlib>              // rand, srand
#include <ctime>                // time

void print_array(int* array, const int& size);
void knuth_shuffle(int* array, const int& size);

int main(void)
{
    const int array_size = 10;

    // Create an empty integer array of specified size.
    int *array = new int[array_size];

    // Fill the array with integers in consecutive order starting at 0.
    for (int i = 0; i < array_size; i++) {
        array[i] = i;
    }

    // Show user how the array looks before shuffling.
    print_array(array, array_size);

    // Shuffle the array with the Knuth shuffle.
    knuth_shuffle(array, array_size);

    // Show user how the array looks after shuffling.
    print_array(array, array_size);
}

void print_array(int* array, const int& size)
{
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }  
    std::cout << std::endl;
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
