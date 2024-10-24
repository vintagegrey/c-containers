//
// Created by jimmy on 10/24/2024.
//

#ifndef C_CONTAINERS_CC_VEC_H
#define C_CONTAINERS_CC_VEC_H

/** Vector (dynamic array) */
typedef struct {
    size_t element_size;    /**< Size of each element */
    size_t count;           /**< Number of elements */
    size_t capacity;        /**< Max elements until reallocation */
    void *data;             /**< Raw data */
} cc_vector_t;

void cc_vector_init(cc_vector_t *v, size_t element_size, size_t capacity);
void cc_vector_grow(cc_vector_t *v);
void cc_vector_push(cc_vector_t *v, void *e);
void cc_vector_push_s(cc_vector_t *v, void *e, size_t size);
void *cc_vector_pop(cc_vector_t *v);
void *cc_vector_get(cc_vector_t *v, size_t idx);
void cc_vector_remove(cc_vector_t *v, size_t idx);
void cc_vector_clear(cc_vector_t *v);

#endif //C_CONTAINERS_CC_VEC_H
