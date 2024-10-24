//
// Created by jimmy on 10/24/2024.
//
#include <stdio.h>
#include <cc_vec.h>

int main() {
    cc_vector_t vec;
    cc_vector_init(&vec, sizeof(int), 5);

    for (int i = 0; i < 2500; i++) {
        int x = i;
        cc_vector_push(&vec, &x);
    }

    int *y = cc_vector_pop(&vec);
    return 0;
}