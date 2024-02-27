#include <stdio.h>
#include <assert.h>

#include "dynarray.c"

int main(int argc, char** argv) {
    struct dynarray* dynarray = dynarray_create();

    int val = 5;
    void* yes = &val;
    dynarray_insert(dynarray, yes);
    
    return 0;
}