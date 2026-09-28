#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" 
{
    #endif

    #define RING_BUFFER_CAPACITY 512

    #if (RING_BUFFER_CAPACITY & (RING_BUFFER_CAPACITY - 1)) != 0
    #error "RING_BUFFER_CAPACITY must be a power of two."
    #endif


    typedef struct
    {
        /* data */
        uint8_t storage[RING_BUFFER_CAPACITY];
        volatile size_t head;
        volatile size_t tail;
    } spsc_ring_buffer_t;

    void ring_buffer_init(spsc_ring_buffer_t *rb);
    void ring_buffer_push(spsc_ring_buffer_t *rb, uint8_t byte);
    bool ring_buffer_pop(spsc_ring_buffer_t *rb, uint8_t *byte);
    size_t ring_buffer_available(const spsc_ring_buffer_t *rb);

    #ifdef __cplusplus
}

#endif
#endif /* RINGBUFFER_H */