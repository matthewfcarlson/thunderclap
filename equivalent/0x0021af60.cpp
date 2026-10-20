// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0021af60 @ 0x0021af60
#include "compat/ptr.h"
struct Buffer { char *data; unsigned count; unsigned capacity; };
struct Context { char pad[0x20]; void *allocator; char pad2[4]; Buffer *buffer; };
extern "C" void *FUN_0021add0(void *, void *, hulk_uintptr, hulk_uintptr);
extern "C" void *FUN_0021af00(Context *, int);
// equiv-conv: FUN_0021af60 eax edi
void *FUN_0021af60(int code, Context *ctx) {
    if (code != 0x116 && (code <= 0x11c || code > 0x11e))
        return FUN_0021af00(ctx, code);
    Buffer *buf = ctx->buffer;
    if (buf->count + 1 > buf->capacity) {
        unsigned cap = buf->capacity;
        buf->data = (char *)FUN_0021add0(ctx->allocator, buf->data, cap, cap * 2 + 0x20);
        buf->capacity = buf->capacity * 2 + 0x20;
    }
    buf->data[buf->count] = 0;
    ++buf->count;
    return ctx->buffer->data;
}