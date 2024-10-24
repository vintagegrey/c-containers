//
// Created by jimmy on 10/24/2024.
//
#include "../include/cc_sparse.h"
#include "cc_util.h"
#include "cc_err.h"

void cc_sparse_init(cc_sparse_t *s, size_t element_size, size_t capacity) {
    CC_ASSERT(s, CC_NOT_INIT);
    CC_ASSERT(element_size > 0, CC_INVALID_SIZE);

    cc_vector_init(&s->sparse, sizeof(int), capacity);
    cc_vector_init(&s->dense, element_size, capacity);
}

void cc_sparse_add(cc_sparse_t *s, size_t idx, void *e) {
    CC_ASSERT(s, CC_NOT_INIT);

    if (idx > s->sparse.count) {
        cc_vector_reserve_set(&s->sparse, idx + 1, -1);
    }
}