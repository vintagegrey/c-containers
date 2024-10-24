//
// Created by jimmy on 10/24/2024.
//

#ifndef C_CONTAINERS_CC_UTIL_H
#define C_CONTAINERS_CC_UTIL_H

#include <stdio.h>
#include <stdlib.h>

#define CC_ERROR(_msg) fprintf(stderr, "%s(): %s.\n", __func__, _msg)
#define CC_ASSERT(_e, ...) do { if (!(_e)) { CC_ERROR(__VA_ARGS__); exit(1); } } while(0)

#endif //C_CONTAINERS_CC_UTIL_H
