//
// Created by yhwach on 5/15/26.
//


#include "alloc.h"

#include <sys/mman.h>

struct pool_type
{
    void* raw_memory;
    void* next;

    size_t size;
};

static struct pool_type pool__ = {
    .raw_memory = NULL,
    .next = NULL,
    .size = 0
};

void __alloc_for_pool(struct pool_type* pool, const size_t size)
{
    pool->raw_memory = mmap(NULL,
                            size(size, 2),
                            PROT_READ | PROT_WRITE,
                            MAP_PRIVATE | MAP_ANONYMOUS,
                            -1,
                            0);

    pool->size = size(size, 2);
    pool->next = pool->raw_memory;
}

void* __get_and_move(struct pool_type* pool, const size_t size)
{
    void* mem = pool->next;

    pool->next += size;
    pool->size -= size;

    return mem;
}

void* alloc(size_t size)
{
    if (pool__.size < size)
    {
        __alloc_for_pool(&pool__, size);
    }

    if (pool__.raw_memory == NULL)
    {
        //SHiT: memory exhausted? cosmic rays? hardware disconnect? hardware fail?
    }

    return __get_and_move(&pool__, size);
}

void free(void* ptr)
{
    munmap(ptr, pool__.size);
}
