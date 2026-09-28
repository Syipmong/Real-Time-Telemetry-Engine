#include "ringbuffer.h"

void ring_buffer_init(spsc_ring_buffer_t *rb)
{
    if (!rb) return;
    rb -> head = 0;
    rb -> tail = 0;
}

bool ring_buffer_push(spsc_ring_buffer_t *rb, uint8_t byte)
{
    size_t current_head = rb -> head;
    size_t next_head = (current_head + 1) & (RING_BUFFER_CAPACITY - 1);

    if (next_head == rb -> tail)
    {
        return false; /* buffer overflow */
    }
}