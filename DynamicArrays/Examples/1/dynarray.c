/*
 * Name: Eric Tran
 * Email: trane2@oregonstate.edu
 * Last Edited: 2/26/2024 - 6:07 AM
 * File: dynarray.c
 * 
 * This is an implementation of a dynamic array
 * Dynamic arrays support random access and growable sizes / capacities
 * This particular implementation supports any data type by using void pointers
 */



// Libraries
#include <stdio.h>
#include <stdlib.h>

// Constants
const INITIAL_SIZE = 0;     // All arrays will be empty on creation
const INITIAL_CAPACITY = 2; // Maximum number of elements that can be stored in the array
const RESIZE_FACTOR = 2;    // How many times capacity will increase by when array is filled

/*
 * Dynamic array struct that consists of size, capacity, and data attributes
 * size represents the current number of elements currently stored in the array
 * capacity represents the maximum amount of elements that can be stored in the array
 * data points to an array of void pointers, which supports any data type
 */
struct dynarray {
    int size;
    int capacity;
    void** data;
};

/*
 * This function allocates and initializes a new, empty dynamic array
 * and returns a pointer to it. It has a starting capacity of INITIAL_CAPACITY.
 * 
 * @return da - pointer to new dynamic array
 */
struct dynarray* dynarray_create() {
    struct dynarray* da = malloc(sizeof(struct dynarray));
    da->size = INITIAL_SIZE;
    da->capacity = INITIAL_CAPACITY;
    da->data = malloc(INITIAL_CAPACITY * sizeof(void*));
    return da;
}

/*
 * This function sets the index of the dynamic array to a given value
 * 
 * @param da - pointer to a dynamic array (NOT NULL)
 * @param index - index - integer from [0, n), where n is size of dynamic array (NOT NULL)
 * @param object - void pointer to some data (NOT NULL)
 */
void dynarray_set(struct dynarray* da, int index, void* object) {
    da->data[index] = object;
}

/*
 * This function returns the value of the element at a specific index
 * 
 * @param da - pointer to a dynamic array (NOT NULL)
 * @param index - index - integer from [0, n), where n is size of dynamic array (NOT NULL)
 */
void* dynarray_get(struct dynarray* da, int index) {
    return da->data[index];
}

/*
 * This function returns the size of the dynamic array
 * 
 * @param da - pointer to a dynamic array (NOT NULL)
 */
int dynarray_size(struct dynarray* da) {
    return da->size;
}

/*
 * This function returns the capacity of the dynamic array
 * 
 * @param da - pointer to a dynamic array (NOT NULL)
 */
int dynarray_capacity(struct dynarray* da) {
    return da->capacity;
}

/*
 * This function inserts a new object into the dynamic array
 * This function checks whether or not the array is full before insertion
 * If full, the function allocates new space and copies elements from old data into new data
 * Old data's allocated space is freed
 * 
 * @param da - pointer to a dynamic array (NOT NULL)
 * @param object - void pointer to some data (NOT NULL)
 */
void dynarray_insert(struct dynarray* da, void* object) {
    // Get array's size and capacity
    int size = da->size;
    int capacity = da->capacity;

    // Check if array is full
    int isFull = (size == capacity);
    if (isFull) {
        // Allocate space to store more data
        // Copy old elements into new array
        void** newData = malloc(capacity * 2 * sizeof(void*));
        for (int i = 0; i < size; i++) {
            newData[i] = da->data[i];
        }

        // Update dynamic array object
        free(da->data);
        da->capacity *= 2;
        da->data = newData;
    }

    // Insert object and increase size
    da->data[size] = object;
    da->size++;
}

/*
 * This function removes an element from an array at a specific index
 * This function shifts all proceeding elements back by one space
 * 
 * @param da - pointer to a dynamic array (NOT NULL)
 * @param index - integer from [0, n), where n is size of dynamic array (NOT NULL)
 */
void dynarray_remove(struct dynarray* da, int index) {
    int size = da->size;
    void** data = da->data;
    for (int i = index; i < size-1; i++) {
        data[i] = data[i+1];
    }
    da->size--;
    data[size] = NULL;
}

/*
 * This function frees the allocated space used for the dynamic array
 * It is the responsibility of the caller to free the values stored by the void* if any
 * 
 * @param da - pointer to a dynamic array (NOT NULL)
 */
void dynarray_free(struct dynarray* da) {
    free(da);
}