//
// Created by yhwach on 5/15/26.
//

#ifndef ALLOC_ALLOC_H
#define ALLOC_ALLOC_H
#include <stddef.h>

#define page_size \
    (4096)

/**
 *
 * @param size requested size
 * @param n number of extra pages that will be allocated
 */
#define size(size, n) \
    ((((size_t) (size) + page_size - 1) / page_size + (size_t)(n)) * page_size)

struct pool_type;

void* alloc(size_t size);
void free(void* ptr);

#endif //ALLOC_ALLOC_H
