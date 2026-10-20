#include "compat/ptr.h"
extern "C" void __cdecl copybytes(int, void*, hulk_intptr);
struct Buffer_3394b0 {
    char* pos;
    int count;
    int size;
    char data[512];
};
extern "C" void __cdecl flush(Buffer_3394b0*);
void __cdecl FUN_003394b0(Buffer_3394b0* b, const char* src, int n) {
    for (; n != 0; --n) {
        if (b->pos >= b->data + 512) {
            hulk_intptr len = b->pos - b->data;
            if (len != 0) {
                copybytes(b->size, b->data, len);
                b->pos = b->data;
                ++b->count;
                flush(b);
            }
        }
        *b->pos++ = *src++;
    }
}