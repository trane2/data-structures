#ifndef __DYNARRAY_H
#define __DYNARRAY_H

struct dynarray;

struct dynarray* dynarray_create();
void dynarray_set(struct dynarray* da, int index, void* object);
void* dynarray_get(struct dynarray* da, int index);
int dynarray_size(struct dynarray* da);
int dynarray_capacity(struct dynarray* da);
void dynarray_resize(struct dynarray* da);
void dynarray_insert(struct dynarray* da, void* object);
void dynarray_remove(struct dynarray* da, int index);
void dynarray_free(struct dynarray* da);

#endif