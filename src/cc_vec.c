//
// Created by jimmy on 10/24/2024.
//
#include "../include/cc_vec.h"
#include "cc_util.h"
#include "cc_err.h"
#include <string.h>

void cc_vector_init(cc_vector_t *v, size_t element_size, size_t capacity) {
    CC_ASSERT(v, CC_NOT_INIT);
    CC_ASSERT(element_size > 0, CC_INVALID_SIZE);

    v->element_size = element_size;
    v->capacity = capacity;
    v->count = 0;
    v->data = malloc(capacity * element_size * capacity);

    CC_ASSERT(v->data, CC_FAILED_ALLOC);
}

void cc_vector_grow(cc_vector_t *v) {
    CC_ASSERT(v, CC_NOT_INIT);

    v->capacity *= 2;
    void *tmp = realloc(v->data, v->capacity * v->element_size);
    CC_ASSERT(tmp, CC_NO_REALLOC);

    v->data = tmp;
}

/** @warning: Not meant to be used on its own: use cc_vector_push or cc_vector_push_s. */
static void cc__vector_insert(cc_vector_t *v, void *e) {
    if (v->count == v->capacity) {
        cc_vector_grow(v);
    }

    void *dst = ((char *) v->data) + (v->count * v->element_size);
    memcpy(dst, e, v->element_size);
    v->count++;
}

void cc_vector_push(cc_vector_t *v, void *e) {
    CC_ASSERT(v, CC_NOT_INIT);
    CC_ASSERT(e, CC_NULL_PARAM);
    cc__vector_insert(v, e);
}

void cc_vector_push_s(cc_vector_t *v, void *e, size_t size) {
    CC_ASSERT(v, CC_NOT_INIT);
    CC_ASSERT(e, CC_NULL_PARAM);
    CC_ASSERT(size == v->element_size, CC_WRONG_SIZE);
    cc__vector_insert(v, e);
}

void *cc_vector_pop(cc_vector_t *v) {
    CC_ASSERT(v, CC_NOT_INIT);

    if (v->count == 0) {
        CC_ERROR(CC_EMPTY);
        return NULL;
    }

    return ((char *) v->data) + (--v->count * v->element_size);
}

void *cc_vector_get(cc_vector_t *v, size_t idx) {
    CC_ASSERT(v, CC_NOT_INIT);

    if (idx > v->count) {
        CC_ERROR(CC_OUT_OF_BOUNDS);
        return NULL;
    }

    return ((char *) v->data) + (idx * v->element_size);
}

void cc_vector_remove(cc_vector_t *v, size_t idx) {
    CC_ASSERT(v, CC_NOT_INIT);

    if (idx >= v->count) {
        CC_ERROR(CC_OUT_OF_BOUNDS);
        return;
    }

    void *src = ((char *) v->data) + ((idx + 1) * v->element_size);
    void *dst = ((char *) v->data) + (idx * v->element_size);
    size_t s = (v->count - (idx + 1)) * v->element_size;

    memcpy(dst, src, s);
    v->count--;
}

void cc_vector_clear(cc_vector_t *v) {
    CC_ASSERT(v, CC_NOT_INIT);
    v->count = 0;
}