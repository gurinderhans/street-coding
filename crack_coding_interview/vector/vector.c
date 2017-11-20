#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "vector.h"

void vectori_init(vector_int *v)
{
  v->data = NULL;
  v->size = 0;
  v->internal_size = 0;
}

void vectori_new(vector_int **v)
{
  *v = malloc(sizeof(vector_int));
  vectori_init(*v);
}

void vectori_add(vector_int *v, int e)
{

  if (v->internal_size == 0)
  {
    v->internal_size = 8;
    v->data = malloc(sizeof(int) * v->internal_size);
    // just to 'zero' out all memory
    memset(v->data, '\0', sizeof(int) * v->internal_size);
  }

  if (v->size == v->internal_size)
  {
    v->internal_size *= 2;
    v->data = realloc(v->data, sizeof(int) * v->internal_size);
  }

  v->data[v->size] = e;
  v->size++;
}

int vectori_get(vector_int *v, int idx)
{
  if (idx >= v->size)
  {
    return -1;
  }

  return v->data[idx];
}

void vectori_set(vector_int *v, int idx, int e)
{
  if (idx >= v->size)
  {
    return;
  }

  v->data[idx] = e;
}

void vectori_delete(vector_int *v, int idx)
{

  if (idx >= v->size)
  {
    return;
  }

  // shift everything to the left after the 'deleting' element
  for (int i = idx+1; i < v->size; ++i)
  {
    v->data[i-1] = v->data[i];
  }

  v->size--;
}

void vectori_free(vector_int *v)
{
  free(v->data);
  free(v);
}

/// general

void vector_init(vector *v)
{
  v->data = NULL;
  v->size = 0;
  v->internal_size = 0;
}

void vector_new(vector **v)
{
  *v = malloc(sizeof(vector));
  vector_init(*v);
}

void vector_add(vector *v, void *e)
{
  if (v->internal_size == 0) {
    v->internal_size = 8;
    v->data = malloc(sizeof(void *) * v->internal_size);
    memset(v->data, '\0', sizeof(void *) * v->internal_size);
  }

  if (v->size == v->internal_size) {
    v->internal_size *= 2;
    v->data = realloc(v->data, sizeof(void *) * v->internal_size);
  }

  v->data[v->size] = e;
  v->size++;
}

void * vector_get (vector *v, int idx)
{
  if (idx >= v->size)
  {
    return NULL;
  }

  return v->data[idx];
}

void vector_set(vector *v, int idx, void *e)
{
  if (idx >= v->size)
  {
    return;
  }

  v->data[idx] = e;
}

void vector_delete(vector *v, int idx)
{
  if (idx >= v->size)
  {
    return;
  }

  // shift to left
  for (int i = idx+1; i < v->size; ++i)
  {
    v->data[i-1] = v->data[i];
  }

  v->size--;
}

void vector_free(vector *v)
{
  free(v->data);
  free(v);
}



/* int main() */
/* { */
/*  */
/*   vector *v1; */
/*   vector_new(&v1); */
/*  */
/*   vector_add(v1, 2); */
/*   vector_add(v1, 4); */
/*  */
/*   printf("v1->size = %d\n", v1->size); */
/*  */
/*   printf("v1[0] = %d\n", vector_get(v1,0)); */
/*   printf("v1[1] = %d\n", vector_get(v1,1)); */
/*  */
/*   vector_delete(v1, 0); */
/*   printf("v1[0] = %d\n", vector_get(v1,0)); */
/*  */
/*   vector_free(v1); */
/*  */
/*   return 0; */
/* } */
