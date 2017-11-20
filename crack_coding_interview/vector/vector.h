#ifndef VECTOR_H
#define VECTOR_H

// raw int data type vector
typedef struct vector_int_ {
  int *data;
  int size;
  int internal_size;
} vector_int;

// pointer vector
typedef struct vector_ {
  void **data;
  int size;
  int internal_size;
} vector;

void vectori_new(vector_int **);
void vectori_init(vector_int *);
void vectori_add(vector_int *, int);
int vectori_get(vector_int *, int);
void vectori_set(vector_int *, int, int);
void vectori_delete(vector_int *, int);
void vectori_free(vector_int *);

void vector_new(vector **);
void vector_init(vector *);
void vector_add(vector *, void *);
void * vector_get(vector *, int);
void vector_set(vector *, int, void *);
void vector_delete(vector *, int);
void vector_free(vector *);

#endif
