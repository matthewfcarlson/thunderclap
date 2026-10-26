#include "decls/data/game/global.h"
// data: marker = DAT_00422518

typedef unsigned int size_t;
struct File {
    char pad[12];
    unsigned char flags;
};
struct Buf {
    int pending;
    File* file;
    char data[512];
};
extern "C" size_t __cdecl fread(void*, size_t, size_t, File*);
char* __cdecl FUN_00339770(int unused, Buf* b, size_t* count) {
    if (b->pending) {
        b->pending = 0;
        *count = 1;
        return ((char*)&DAT_00422518);
    }
    File* f = b->file;
    if (f->flags & 16)
        return 0;
    size_t n = fread(b->data, 1, 512, f);
    *count = n;
    return n > 0 ? b->data : 0;
}