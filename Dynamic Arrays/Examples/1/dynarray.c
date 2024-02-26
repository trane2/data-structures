#include <stdio.h>
#include <stdlib.h>

struct dynarray {
    int size;
    int capacity;
    void** data;
};

struct dynarray* dynarray_create() {
    struct dynarray* da = malloc(sizeof(struct dynarray*));
    da->size = 0;
    da->capacity = 2;
    da->data = malloc(2 * sizeof(void*));
    return da;
}

void dynarray_insert(struct dynarray* da, void* object) {
    int size = da->size;
    int capacity = da->capacity;
    int isFull = (size == capacity);
    if (isFull) {
        void** newData = malloc(capacity * 2 * sizeof(void*));
        for (int i = 0; i < size; i++) {
            newData[i] = da->data[i];
        }
        da->capacity *= 2;
        da->data = newData;
    }

    da->data[size] = object;
    da->size++;
}

void dynarray_remove(struct dynarray* da, int index) {
    int size = da->size;
    void** data = da->data;
    for (int i = index; i < size-1; i++) {
        data[i] = data[i+1];
    }
    da->size--;
    data[size-1] = NULL;
}

void dynarray_destroy(struct dynarray* da) {
    free(da);
}