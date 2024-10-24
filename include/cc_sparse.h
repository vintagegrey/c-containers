//
// Created by jimmy on 10/24/2024.
//

#ifndef C_CONTAINERS_CC_SPARSE_H
#define C_CONTAINERS_CC_SPARSE_H

#include <cc_vec.h>

/** Sparse set */
typedef struct {
    cc_vector_t sparse; /**< Vector of int */
    cc_vector_t dense;  /**< Vector of elements */
} cc_sparse_t;

void cc_sparse_init(cc_sparse_t *s, size_t element_size, size_t capacity);
void cc_sparse_add(cc_sparse_t *s, size_t idx, void *e);

#endif //C_CONTAINERS_CC_SPARSE_H
