// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 7/8, incomplete)
// FUN_0021a590 @ 0x0021a590
#include "compat/ptr.h"
struct Stream { hulk_uintptr remaining; unsigned char *cursor; unsigned char *(__cdecl *refill)(void *, void *, unsigned int *); void *arg1; void *arg2; };
unsigned int __cdecl FUN_0021a590(Stream *stream)
{
    if (stream->remaining == 0) {
        unsigned int count = (unsigned int)stream;
        unsigned char *data = stream->refill(stream->arg2, stream->arg1, &count);
        if (data == 0 || count == 0)
            return 0xffffffff;
        stream->cursor = data;
        stream->remaining = count - 1;
        stream->cursor = data + 1;
        stream->remaining = count;
        stream->cursor = data;
    }
    return *stream->cursor;
}