// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0021a550..0x0021a790 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f7d9ae77 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f7d9ae77 {} using namespace fn_f7d9ae77;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_f7d9ae77 {
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);


// 0x0021a550 FUN_0021a550 (58 B): equivalent/0x0021a550.cpp
// sym: _FUN_0021a550
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 4/4)
// luaZ_fill: refill the stream's buffer from its reader; the first byte, or -1 at the end.
extern "C" int __cdecl FUN_0021a550(LuaVMZio* z) {
    // the original keeps size in z's argument slot: a reader that does not write it leaves z's address there
    unsigned int size = (unsigned int)(hulk_uintptr)z;
    const char* buff = z->reader(z->L, z->data, &size);
    if (buff && size) {
        z->p = buff;
        z->n = size - 1;
        unsigned int c = *(const unsigned char*)buff;
        z->p = buff + 1;
        return (int)c;
    }
    return -1;
}


// 0x0021a590 FUN_0021a590 (79 B): equivalent/0x0021a590.cpp
// sym: _FUN_0021a590
// STATUS: equivalent (tools/equiv.py level 3: 3025 inputs, branch coverage 7/8, incomplete)
// luaZ_lookahead: the next byte without consuming it (refilling an empty buffer), or -1 at the end.
extern "C" int __cdecl FUN_0021a590(LuaVMZio* z) {
    if (z->n == 0) {
        // the original keeps size in z's argument slot: a reader that does not write it leaves z's address there
        unsigned int size = (unsigned int)(hulk_uintptr)z;
        const char* buff = z->reader(z->L, z->data, &size);
        if (buff == 0 || size == 0)
            return -1;
        z->p = buff;
        z->n = size - 1;
        z->p = buff + 1;
        z->n = size;
        z->p = buff;
    }
    return *(const unsigned char*)z->p;
}


// 0x0021a5e0 FUN_0021a5e0 (39 B): matches/0x0021a5e0.cpp
// sym: _FUN_0021a5e0
// luaZ_init: a stream over a reader.
extern "C" void __cdecl FUN_0021a5e0(LuaVMState* L, LuaVMZio* z, LuaVMReader reader, void* data) {
    z->L = L;
    z->reader = reader;
    z->data = data;
    z->n = 0;
    z->p = 0;
}


// 0x0021a610 FUN_0021a610 (150 B): equivalent/0x0021a610.cpp
// sym: _FUN_0021a610
// STATUS: equivalent (tools/equiv.py level 3: 541 inputs, branch coverage 13/14, incomplete)
// luaZ_read: copy n bytes out of the stream into b; the number of bytes missing.
extern "C" unsigned int __cdecl FUN_0021a610(LuaVMZio* z, void* b, unsigned int n) {
    while (n != 0) {
        if (z->n == 0) {
            unsigned int size;
            const char* buff = z->reader(z->L, z->data, &size);
            if (buff == 0 || size == 0)
                return n;
            z->n = size - 1;
            z->p = buff;
            int c = *(const unsigned char*)z->p++;
            if (c == -1)
                return n;
            z->n++;
            z->p--;
        }
        unsigned int m = (n <= z->n) ? n : z->n;
        memcpy(b, z->p, m);
        z->n -= m;
        z->p += m;
        b = (char*)b + m;
        n -= m;
    }
    return 0;
}


// 0x0021a6b0 FUN_0021a6b0 (55 B): matches/0x0021a6b0.cpp
// sym: _FUN_0021a6b0
// luaZ_openspace: make the buffer at least n bytes (32 at least); its characters.
extern "C" char* __cdecl FUN_0021a6b0(LuaVMState* L, LuaVMBuffer* buff, unsigned int n) {
    if (n > buff->buffsize) {
        if (n < 32)
            n = 32;
        buff->buffer = (char*)FUN_0021add0(L, buff->buffer, buff->buffsize, n);
        buff->buffsize = n;
    }
    return buff->buffer;
}

} // namespace fn_f7d9ae77
