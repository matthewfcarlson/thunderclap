// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002699f0..0x0026b910 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_fcad8d96 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fcad8d96 {} using namespace fn_fcad8d96;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_fcad8d96 {
typedef unsigned int uint_2699f0;
} // namespace fn_fcad8d96
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#endif
namespace fn_fcad8d96 {
extern "C" bool __cdecl FUN_002716c0(const char* source, uint_2699f0* length, uint_2699f0* other, int zero);
extern "C++" __declspec(nothrow) char __cdecl FUN_002716c0(const char*, int*, const char**, void*);
extern "C" int __cdecl FUN_002716f0(const char*, char*, int, void*, int*, void*);
extern "C" char __cdecl FUN_00271b70(const char*, int*, const char**, void*);
typedef unsigned short wchar16_269ba0;
extern "C" char __cdecl FUN_00271dd0(const wchar16_269ba0 *, unsigned *, unsigned *, void *);
extern "C++" __declspec(nothrow) int __cdecl FUN_002716f0(unsigned, char *, int, int, unsigned *, void *);
extern "C" char __cdecl FUN_00272070(const unsigned *, unsigned *, unsigned *, void *);
extern "C" char __cdecl FUN_00272240(const char*, int*, const char**, void*);
extern "C" char __cdecl FUN_00271820(const char*, int*, const char**, void*);
typedef unsigned int uint_269e00;
extern "C++" __declspec(nothrow) unsigned char __cdecl FUN_00271b70(const char* text, uint_269e00* bytes, uint_269e00* other, int mode);
extern "C++" __declspec(nothrow) unsigned char __cdecl FUN_002716c0(const char* input, int* consumed, int* parsed, int flags);
extern "C" int __cdecl FUN_00271c00(int parsed, char* output, int available, int mode, int* produced, int flags);
extern "C++" __declspec(nothrow) int __cdecl FUN_00271c00(const char*, char*, int, void*, int*, void*);
extern "C++" __declspec(nothrow) int __cdecl FUN_00271c00(unsigned, char *, int, int, unsigned *, void *);
extern "C++" __declspec(nothrow) char __cdecl FUN_00271dd0(const unsigned short *source, unsigned int *length, unsigned int *end, int flags);
extern "C++" __declspec(nothrow) unsigned char __cdecl FUN_00271b70(const char* input, int* consumed, int* parsed, int flags);
extern "C" int __cdecl FUN_00271e40(unsigned int, unsigned short *, unsigned int, unsigned int, unsigned int *, unsigned int *);
extern "C++" __declspec(nothrow) bool __cdecl FUN_00272070(const unsigned *source, int *srcBytes, int *units, int options);
extern "C++" __declspec(nothrow) unsigned char __cdecl FUN_00272240(const char* input, int* consumed, int* parsed, int flags);
typedef unsigned short wchar16_26a600;
extern "C++" __declspec(nothrow) char __cdecl FUN_00271820(const char *, unsigned *, unsigned *, void *);
typedef unsigned int uint_26a6b0;
extern "C++" __declspec(nothrow) unsigned char __cdecl FUN_00272070(const char* text, uint_26a6b0* bytes, uint_26a6b0* other, int mode);
extern "C" int __cdecl FUN_002720b0(int parsed, char* output, int available, int mode, int* produced, int flags);
extern "C++" __declspec(nothrow) char __cdecl FUN_00271b70(const char *, unsigned *, unsigned *, void *);
extern "C++" __declspec(nothrow) int __cdecl FUN_002720b0(unsigned, unsigned *, int, int, unsigned *, void *);
extern "C++" __declspec(nothrow) bool __cdecl FUN_00271dd0(const unsigned short *source, int *srcBytes, int *units, int options);
extern "C++" __declspec(nothrow) unsigned char __cdecl FUN_00272070(const int* input, int* consumed, int* parsed, int flags);
extern "C++" __declspec(nothrow) char __cdecl FUN_00272240(const char *, unsigned *, unsigned *, void *);
extern "C++" __declspec(nothrow) bool __cdecl FUN_00271820(const char *source, int *srcBytes, int *units, int options);
typedef unsigned int uint_26ab60;
extern "C++" __declspec(nothrow) bool __cdecl FUN_00272240(const char* source, uint_26ab60* length, uint_26ab60* other, int zero);
extern "C++" __declspec(nothrow) char __cdecl FUN_002716c0(const char *, unsigned *, unsigned *, void *);
extern "C" int __cdecl FUN_002722b0(unsigned, char *, int, int, unsigned *, void *);
extern "C++" __declspec(nothrow) int __cdecl FUN_002722b0(const char*, char*, int, void*, int*, void*);
typedef unsigned int uint_26af70;
extern "C++" __declspec(nothrow) unsigned char __cdecl FUN_00271820(const char* text, uint_26af70* bytes, uint_26af70* other, int mode);
extern "C" int __cdecl FUN_00271870(int parsed, char* output, int available, int mode, int* produced, int flags);
extern "C++" __declspec(nothrow) int __cdecl FUN_00271870(const char*, char*, int, void*, int*, void*);
extern "C++" __declspec(nothrow) int __cdecl FUN_00271870(unsigned, char *, int, int, unsigned *, void *);
extern "C" int __cdecl FUN_002699f0(int c, int a, int limit);
extern "C" int __cdecl FUN_00269a80(const char *, char *, void *, int, void *);
extern "C" int __cdecl FUN_00269b10(const char *, char *, void *, int, void *);
extern "C" int __cdecl FUN_00269ba0(const unsigned short *, char *, int, int, void *);
extern "C" int __cdecl FUN_00269c40(const unsigned *, char *, int, int, void *);
extern "C" int __cdecl FUN_00269ce0(const char *, char *, void *, int, void *);
extern "C" int __cdecl FUN_00269d70(const char *, char *, void *, int, void *);
extern "C" int __cdecl FUN_00269e00(int c, int a, int limit);
extern "C" int __cdecl FUN_00269e90(const char *, char *, int, int, int);
extern "C" int __cdecl FUN_00269f20(const char *, char *, void *, int, void *);
extern "C++" __declspec(nothrow) int __cdecl FUN_00269fb0(const unsigned short *, char *, int, int, void *);
extern "C" int __cdecl FUN_0026a050(const unsigned *, char *, int, int, void *);
extern "C" int __cdecl FUN_0026a0f0(const char *, char *, void *, int, void *);
extern "C" int __cdecl FUN_0026a180(const char *, char *, void *, int, void *);
extern "C" int __cdecl FUN_0026a210(const unsigned short *, char *, unsigned int);
extern "C++" __declspec(nothrow) int __cdecl FUN_0026a2a0(const char *, char *, int, int, int);
extern "C" int __cdecl FUN_0026a350(const char *, char *, int, int, int);
extern "C++" __declspec(nothrow) int __cdecl FUN_0026a400(const unsigned short *, unsigned short *, int, int, void *);
extern "C" int __cdecl FUN_0026a4a0(const unsigned *, char *, int, int, int);
extern "C" int __cdecl FUN_0026a550(const char *, char *, int, int, int);
extern "C" int __cdecl FUN_0026a600(const char *, unsigned short *, int, int, void *);
extern "C" int __cdecl FUN_0026a6b0(const char *, char *, unsigned int);
extern "C" int __cdecl FUN_0026a750(const char *, char *, int, int, int);
extern "C" int __cdecl FUN_0026a800(const char *, unsigned *, int, int, void *);
extern "C" int __cdecl FUN_0026a8b0(const unsigned short *, char *, int, int, int);
extern "C" int __cdecl FUN_0026a960(const int *, char *, int, int, int);
extern "C" int __cdecl FUN_0026aa00(const char *, unsigned *, int, int, void *);
extern "C" int __cdecl FUN_0026aab0(const char *, char *, int, int, int);
extern "C" int __cdecl FUN_0026ab60(int c, int a, int limit);
extern "C" int __cdecl FUN_0026abf0(const char *, char *, int, int, void *);
extern "C" int __cdecl FUN_0026ac80(const char *, char *, void *, int, void *);
extern "C++" __declspec(nothrow) int __cdecl FUN_0026ad10(const unsigned short *, char *, int, int, void *);
extern "C" int __cdecl FUN_0026adb0(const unsigned *, char *, int, int, void *);
extern "C" int __cdecl FUN_0026ae50(const char *, char *, void *, int, void *);
extern "C" int __cdecl FUN_0026aee0(const char *, char *, void *, int, void *);
extern "C" int __cdecl FUN_0026af70(int c, int a, int limit);
extern "C" int __cdecl FUN_0026b000(const char *, char *, int, int, int);
extern "C" int __cdecl FUN_0026b090(const char *, char *, void *, int, void *);
extern "C++" __declspec(nothrow) int __cdecl FUN_0026b120(const unsigned short *, char *, int, int, void *);
extern "C" int __cdecl FUN_0026b1c0(const unsigned *, char *, int, int, void *);
extern "C" int __cdecl FUN_0026b260(const char *, char *, void *, int, void *);
extern "C" int __cdecl FUN_0026b2f0(const char *, char *, void *, int, void *);
extern int FUN_0026b380(void* a, int mode, void* c, int toMode, int g, int f, int e);
extern int FUN_0026b440(void* a, int mode, void* c, int toMode, int g, int f, int e);
extern int FUN_0026b500(void* a, int mode, void* c, int toMode, int g, int f, int e);
extern int FUN_0026b5c0(void* a, int mode, void* c, int toMode, int g, int f, int e);
extern int FUN_0026b680(void* a, int mode, void* c, int toMode, int g, int f, int e);
extern int FUN_0026b740(void* a, int mode, void* c, int toMode, int g, int f, int e);


// 0x002699f0 FUN_002699f0 (141 B): equivalent/0x002699f0.cpp
// sym: ?FUN_002699f0@fn_fcad8d96@@YAHPBDPADI@Z
// STATUS: equivalent (tools/equiv.py level 3: 228 inputs, branch coverage 8/8)
// FUN_002699f0 @ 0x002699f0
// Copies whole UTF-8-like characters from source into dest while they fit in capacity-1 bytes,
// then terminates dest. Returns the number of bytes copied, or -1 on a bad character.
// equiv-conv: FUN_002699f0 eax stack stack
int __cdecl FUN_002699f0(const char* source, char* dest, uint_2699f0 capacity) {
    uint_2699f0 written = 0;
    while (*source != 0) {
        uint_2699f0 length;
        uint_2699f0 other;
        if (!FUN_002716c0(source, &length, &other, 0))
            return -1;
        if (written + length > capacity - 1)
            break;
        memcpy(dest, source, length);
        written += length;
        source += length;
        dest += length;
    }
    *dest = 0;
    return (int)written;
}


// 0x00269a80 FUN_00269a80 (144 B): equivalent/0x00269a80.cpp
// sym: _FUN_00269a80
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// FUN_00269a80 @ 0x00269a80
// equiv-conv: FUN_00269a80 eax ecx stack stack stack
extern "C" int __cdecl FUN_00269a80(const char* input, char* output, void* value, int capacity, void* context)
{
    int used = 0;
    for (;;) {
        if (!*input) {
            *output = 0;
            return 0;
        }
        int consumed;
        const char* token;
        if (!FUN_002716c0(input, &consumed, &token, context))
            return -2;
        int produced;
        int result = FUN_002716f0(token, output, capacity - used - 1,
                                  value, &produced, context);
        if (result != 0) {
            if (result == -1)
                *output = 0;
            return result;
        }
        input += consumed;
        output += produced;
        used += produced;
    }
}


// 0x00269b10 FUN_00269b10 (144 B): equivalent/0x00269b10.cpp
// sym: _FUN_00269b10
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// FUN_00269b10 @ 0x00269b10
// equiv-conv: FUN_00269b10 eax ecx stack stack stack
extern "C" int __cdecl FUN_00269b10(const char* input, char* output, void* value, int capacity, void* context)
{
    int used = 0;
    for (;;) {
        if (!*input) {
            *output = 0;
            return 0;
        }
        int consumed;
        const char* token;
        if (!FUN_00271b70(input, &consumed, &token, context))
            return -2;
        int produced;
        int result = FUN_002716f0(token, output, capacity - used - 1,
                                  value, &produced, context);
        if (result != 0) {
            if (result == -1)
                *output = 0;
            return result;
        }
        input += consumed;
        output += produced;
        used += produced;
    }
}


// 0x00269ba0 FUN_00269ba0 (160 B): equivalent/0x00269ba0.cpp
// sym: _FUN_00269ba0
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00269ba0 @ 0x00269ba0
// FUN_00269ba0 converts a string of 16-bit code units to bytes, one decoded unit at a time
// equiv-conv: FUN_00269ba0 eax ecx stack stack stack
extern "C" int __cdecl FUN_00269ba0(const unsigned short *source, char *destination, int input, int capacity, void *options) {
    if ((const void *)source == (void *)destination) return -5;
    int used = 0;
    while (*source) {
        struct { unsigned auxiliary, consumed, written; } t;
        if (!FUN_00271dd0(source, &t.consumed, &t.auxiliary, options)) return -2;
        int result = FUN_002716f0(t.auxiliary, destination, capacity - used - 1, input, &t.written, options);
        if (result != 0) {
            if (result == -1) *destination = 0;
            return result;
        }
        source = (const wchar16_269ba0 *)((const char *)source + t.consumed);
        destination += t.written;
        used += t.written;
    }
    *destination = 0;
    return 0;
}


// 0x00269c40 FUN_00269c40 (160 B): equivalent/0x00269c40.cpp
// sym: _FUN_00269c40
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00269c40 @ 0x00269c40
// FUN_00269c40 converts a string of 32-bit code units to bytes, one decoded unit at a time
// equiv-conv: FUN_00269c40 eax ecx stack stack stack
extern "C" int __cdecl FUN_00269c40(const unsigned *source, char *destination, int input, int capacity, void *options) {
    if ((const void *)source == (void *)destination) return -5;
    int used = 0;
    while (*source) {
        struct { unsigned auxiliary, consumed, written; } t;
        if (!FUN_00272070(source, &t.consumed, &t.auxiliary, options)) return -2;
        int result = FUN_002716f0(t.auxiliary, destination, capacity - used - 1, input, &t.written, options);
        if (result != 0) {
            if (result == -1) *destination = 0;
            return result;
        }
        source = (const unsigned *)((const char *)source + t.consumed);
        destination += t.written;
        used += t.written;
    }
    *destination = 0;
    return 0;
}


// 0x00269ce0 FUN_00269ce0 (144 B): equivalent/0x00269ce0.cpp
// sym: _FUN_00269ce0
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// FUN_00269ce0 @ 0x00269ce0
// equiv-conv: FUN_00269ce0 eax ecx stack stack stack
extern "C" int __cdecl FUN_00269ce0(const char* input, char* output, void* value, int capacity, void* context)
{
    int used = 0;
    for (;;) {
        if (!*input) {
            *output = 0;
            return 0;
        }
        int consumed;
        const char* token;
        if (!FUN_00272240(input, &consumed, &token, context))
            return -2;
        int produced;
        int result = FUN_002716f0(token, output, capacity - used - 1,
                                  value, &produced, context);
        if (result != 0) {
            if (result == -1)
                *output = 0;
            return result;
        }
        input += consumed;
        output += produced;
        used += produced;
    }
}


// 0x00269d70 FUN_00269d70 (144 B): equivalent/0x00269d70.cpp
// sym: _FUN_00269d70
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// FUN_00269d70 @ 0x00269d70
// equiv-conv: FUN_00269d70 eax ecx stack stack stack
extern "C" int __cdecl FUN_00269d70(const char* input, char* output, void* value, int capacity, void* context)
{
    int used = 0;
    for (;;) {
        if (!*input) {
            *output = 0;
            return 0;
        }
        int consumed;
        const char* token;
        if (!FUN_00271820(input, &consumed, &token, context))
            return -2;
        int produced;
        int result = FUN_002716f0(token, output, capacity - used - 1,
                                  value, &produced, context);
        if (result != 0) {
            if (result == -1)
                *output = 0;
            return result;
        }
        input += consumed;
        output += produced;
        used += produced;
    }
}


// 0x00269e00 FUN_00269e00 (141 B): equivalent/0x00269e00.cpp
// sym: ?FUN_00269e00@fn_fcad8d96@@YAHPBDPADI@Z
// STATUS: equivalent (tools/equiv.py level 3: 228 inputs, branch coverage 8/8)
// FUN_00269e00 @ 0x00269e00
// equiv-conv: FUN_00269e00 eax stack stack
int __cdecl FUN_00269e00(const char* source, char* destination, uint_269e00 capacity)
{
    uint_269e00 copied = 0;
    uint_269e00 bytes;
    uint_269e00 other;
    while (*source) {
        if (!FUN_00271b70(source, &bytes, &other, 0))
            return -1;
        if (copied + bytes > capacity - 1)
            break;
        memcpy(destination, source, bytes);
        copied += bytes;
        destination += bytes;
        source += bytes;
    }
    *destination = 0;
    return copied;
}


// 0x00269e90 FUN_00269e90 (144 B): equivalent/0x00269e90.cpp
// sym: _FUN_00269e90
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// FUN_00269e90 @ 0x00269e90
// equiv-conv: FUN_00269e90 eax ecx stack stack stack
extern "C" int __cdecl FUN_00269e90(const char* source, char* dest, int mode, int capacity, int flags) {
    int written = 0;
    while (*source) {
        struct { int parsed; int consumed; int produced; } v;
        if (!FUN_002716c0(source, &v.consumed, &v.parsed, flags))
            return -2;
        int result = FUN_00271c00(v.parsed, dest, capacity - written - 1, mode, &v.produced, flags);
        if (result != 0) {
            if (result == -1)
                *(char*)dest = 0;
            return result;
        }
        source += v.consumed;
        dest += v.produced;
        written += v.produced;
    }
    *(char*)dest = 0;
    return 0;
}


// 0x00269f20 FUN_00269f20 (144 B): equivalent/0x00269f20.cpp
// sym: _FUN_00269f20
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// FUN_00269f20 @ 0x00269f20
// equiv-conv: FUN_00269f20 eax ecx stack stack stack
extern "C" int __cdecl FUN_00269f20(const char* input, char* output, void* value, int capacity, void* context)
{
    int used = 0;
    for (;;) {
        if (!*input) {
            *output = 0;
            return 0;
        }
        int consumed;
        const char* token;
        if (!FUN_00271b70(input, &consumed, &token, context))
            return -2;
        int produced;
        int result = FUN_00271c00(token, output, capacity - used - 1,
                                  value, &produced, context);
        if (result != 0) {
            if (result == -1)
                *output = 0;
            return result;
        }
        input += consumed;
        output += produced;
        used += produced;
    }
}

} // namespace fn_fcad8d96

// 0x00269fb0 FUN_00269fb0 (160 B): equivalent/0x00269fb0.cpp [wrapped: compile error in a shared declaration (C2732)]
// sym: _FUN_00269fb0
namespace fn_00269fb0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00269fb0 @ 0x00269fb0
// FUN_00269fb0 converts a string of 16-bit code units to bytes, one decoded unit at a time
typedef unsigned short wchar16_269fb0;
extern "C++" __declspec(nothrow) char __cdecl FUN_00271dd0(const wchar16_269fb0 *, unsigned *, unsigned *, void *);
extern "C++" __declspec(nothrow) int __cdecl FUN_00271c00(unsigned, char *, int, int, unsigned *, void *);

// equiv-conv: FUN_00269fb0 eax ecx stack stack stack
extern "C" int __cdecl FUN_00269fb0(const unsigned short *source, char *destination, int input, int capacity, void *options) {
    if ((const void *)source == (void *)destination) return -5;
    int used = 0;
    while (*source) {
        struct { unsigned auxiliary, consumed, written; } t;
        if (!FUN_00271dd0(source, &t.consumed, &t.auxiliary, options)) return -2;
        int result = FUN_00271c00(t.auxiliary, destination, capacity - used - 1, input, &t.written, options);
        if (result != 0) {
            if (result == -1) *destination = 0;
            return result;
        }
        source = (const wchar16_269fb0 *)((const char *)source + t.consumed);
        destination += t.written;
        used += t.written;
    }
    *destination = 0;
    return 0;
}
} // namespace fn_00269fb0

namespace fn_fcad8d96 {

// 0x0026a050 FUN_0026a050 (160 B): equivalent/0x0026a050.cpp
// sym: _FUN_0026a050
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_0026a050 @ 0x0026a050
// FUN_0026a050 converts a string of 32-bit code units to bytes, one decoded unit at a time
// equiv-conv: FUN_0026a050 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a050(const unsigned *source, char *destination, int input, int capacity, void *options) {
    if ((const void *)source == (void *)destination) return -5;
    int used = 0;
    while (*source) {
        struct { unsigned auxiliary, consumed, written; } t;
        if (!FUN_00272070(source, &t.consumed, &t.auxiliary, options)) return -2;
        int result = FUN_00271c00(t.auxiliary, destination, capacity - used - 1, input, &t.written, options);
        if (result != 0) {
            if (result == -1) *destination = 0;
            return result;
        }
        source = (const unsigned *)((const char *)source + t.consumed);
        destination += t.written;
        used += t.written;
    }
    *destination = 0;
    return 0;
}


// 0x0026a0f0 FUN_0026a0f0 (144 B): equivalent/0x0026a0f0.cpp
// sym: _FUN_0026a0f0
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// FUN_0026a0f0 @ 0x0026a0f0
// equiv-conv: FUN_0026a0f0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a0f0(const char* input, char* output, void* value, int capacity, void* context)
{
    int used = 0;
    for (;;) {
        if (!*input) {
            *output = 0;
            return 0;
        }
        int consumed;
        const char* token;
        if (!FUN_00272240(input, &consumed, &token, context))
            return -2;
        int produced;
        int result = FUN_00271c00(token, output, capacity - used - 1,
                                  value, &produced, context);
        if (result != 0) {
            if (result == -1)
                *output = 0;
            return result;
        }
        input += consumed;
        output += produced;
        used += produced;
    }
}


// 0x0026a180 FUN_0026a180 (144 B): equivalent/0x0026a180.cpp
// sym: _FUN_0026a180
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// FUN_0026a180 @ 0x0026a180
// equiv-conv: FUN_0026a180 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a180(const char* input, char* output, void* value, int capacity, void* context)
{
    int used = 0;
    for (;;) {
        if (!*input) {
            *output = 0;
            return 0;
        }
        int consumed;
        const char* token;
        if (!FUN_00271820(input, &consumed, &token, context))
            return -2;
        int produced;
        int result = FUN_00271c00(token, output, capacity - used - 1,
                                  value, &produced, context);
        if (result != 0) {
            if (result == -1)
                *output = 0;
            return result;
        }
        input += consumed;
        output += produced;
        used += produced;
    }
}


// 0x0026a210 FUN_0026a210 (138 B): equivalent/0x0026a210.cpp
// sym: _FUN_0026a210
// STATUS: equivalent (tools/equiv.py level 3: 137 inputs, branch coverage 8/8)
// FUN_0026a210 @ 0x0026a210
// equiv-conv: FUN_0026a210 eax stack stack
extern "C" int __cdecl FUN_0026a210(const unsigned short *source, char *destination, unsigned int capacity)
{
    unsigned int written = 0;
    while (*source != 0) {
        unsigned int length;
        unsigned int end;
        if (!FUN_00271dd0(source, &length, &end, 0))
            return -1;
        if (length + written > capacity - 2)
            break;
        const char *bytes = (const char *)source;
        memcpy(destination, bytes, length);
        destination += length;
        source = (const unsigned short *)(bytes + length);
        written += length;
    }
    *(unsigned short *)destination = 0;
    return written;
}

} // namespace fn_fcad8d96

// 0x0026a2a0 FUN_0026a2a0 (165 B): equivalent/0x0026a2a0.cpp [wrapped: conflict: FUN_002716c0]
// sym: _FUN_0026a2a0
namespace fn_0026a2a0 {
// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 12/12)
// FUN_0026a2a0 @ 0x0026a2a0
// equiv-conv: FUN_0026a2a0 eax ecx stack stack stack
extern "C++" __declspec(nothrow) bool __cdecl FUN_002716c0(const char *source, int *srcBytes, int *units, int options);
extern "C" int __cdecl FUN_00271e40(unsigned int, unsigned short *, unsigned int, unsigned int, unsigned int *, unsigned int *);

extern "C" int __cdecl FUN_0026a2a0(const char *source, char *destination, int mode, int capacity, int options)
{
    if (source == destination)
        return -5;
    struct { int units; int srcBytes; int written; } r;
    int used = 0;
    while (*source) {
        if (!FUN_002716c0(source, &r.srcBytes, &r.units, options))
            return -2;
        int result = FUN_00271e40((int)(r.units), (unsigned short *)(char *)destination, (int)(capacity - used - 2), (int)mode, (unsigned int *)(int *)(&r.written), (unsigned int *)(hulk_uintptr)(int)options);
        if (result) {
            if (result == -1)
                *(short *)destination = 0;
            return result;
        }
        source += r.srcBytes;
        destination += r.written;
        used += r.written;
    }
    *(short *)destination = 0;
    return 0;
}
} // namespace fn_0026a2a0

namespace fn_fcad8d96 {

// 0x0026a350 FUN_0026a350 (165 B): equivalent/0x0026a350.cpp
// sym: _FUN_0026a350
// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 12/12)
// FUN_0026a350 @ 0x0026a350
// equiv-conv: FUN_0026a350 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a350(const char* source, char* dest, int mode, int capacity, int flags) {
    if (source == dest)
        return -5;
    int written = 0;
    while (*source) {
        struct { int parsed; int consumed; int produced; } v;
        if (!FUN_00271b70(source, &v.consumed, &v.parsed, flags))
            return -2;
        int result = FUN_00271e40((int)(v.parsed), (unsigned short *)(char *)dest, (int)(capacity - written - 2), (int)mode, (unsigned int *)(int *)(&v.produced), (unsigned int *)(hulk_uintptr)(int)flags);
        if (result != 0) {
            if (result == -1)
                *(short*)dest = 0;
            return result;
        }
        source += v.consumed;
        dest += v.produced;
        written += v.produced;
    }
    *(short*)dest = 0;
    return 0;
}

} // namespace fn_fcad8d96

// 0x0026a400 FUN_0026a400 (149 B): equivalent/0x0026a400.cpp [wrapped: compile error in a shared declaration (C2732)]
// sym: _FUN_0026a400
namespace fn_0026a400 {
// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 10/10)
// FUN_0026a400 @ 0x0026a400
typedef unsigned short wchar16_26a400;
extern "C++" __declspec(nothrow) char __cdecl FUN_00271dd0(const wchar16_26a400 *, unsigned *, unsigned *, void *);
extern "C" int __cdecl FUN_00271e40(unsigned int, unsigned short *, unsigned int, unsigned int, unsigned int *, unsigned int *);

// equiv-conv: FUN_0026a400 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a400(const unsigned short *source, unsigned short *destination, int input, int capacity, void *options) {
    int used = 0;
    while (*source) {
        unsigned consumed;
        unsigned auxiliary;
        unsigned written;
        if (!FUN_00271dd0(source, &consumed, &auxiliary, options)) return -2;
        int result = FUN_00271e40((unsigned)auxiliary, destination, (int)(capacity - used - 2), (int)input, (unsigned int *)(unsigned *)(&written), (unsigned int *)(void *)options);
        if (result != 0) {
            if (result == -1) *destination = 0;
            return result;
        }
        source = (const wchar16_26a400 *)((const char *)source + consumed);
        destination = (wchar16_26a400 *)((char *)destination + written);
        used += written;
    }
    *destination = 0;
    return 0;
}
} // namespace fn_0026a400

namespace fn_fcad8d96 {

// 0x0026a4a0 FUN_0026a4a0 (165 B): equivalent/0x0026a4a0.cpp
// sym: _FUN_0026a4a0
// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 12/12)
// FUN_0026a4a0 @ 0x0026a4a0
// equiv-conv: FUN_0026a4a0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a4a0(const unsigned *source, char *destination, int mode, int capacity, int options)
{
    if ((const void *)source == (const void *)destination)
        return -5;
    struct { int units; int srcBytes; int written; } r;
    int used = 0;
    while (*source) {
        if (!FUN_00272070(source, &r.srcBytes, &r.units, options))
            return -2;
        int result = FUN_00271e40((int)(r.units), (unsigned short *)(char *)destination, (int)(capacity - used - 2), (int)mode, (unsigned int *)(int *)(&r.written), (unsigned int *)(hulk_uintptr)(int)options);
        if (result) {
            if (result == -1)
                *(short *)destination = 0;
            return result;
        }
        source = (const unsigned *)((const char *)source + r.srcBytes);
        destination += r.written;
        used += r.written;
    }
    *(short *)destination = 0;
    return 0;
}


// 0x0026a550 FUN_0026a550 (165 B): equivalent/0x0026a550.cpp
// sym: _FUN_0026a550
// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 12/12)
// FUN_0026a550 @ 0x0026a550
// equiv-conv: FUN_0026a550 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a550(const char* source, char* dest, int mode, int capacity, int flags) {
    if (source == dest)
        return -5;
    int written = 0;
    while (*source) {
        struct { int parsed; int consumed; int produced; } v;
        if (!FUN_00272240(source, &v.consumed, &v.parsed, flags))
            return -2;
        int result = FUN_00271e40((int)(v.parsed), (unsigned short *)(char *)dest, (int)(capacity - written - 2), (int)mode, (unsigned int *)(int *)(&v.produced), (unsigned int *)(hulk_uintptr)(int)flags);
        if (result != 0) {
            if (result == -1)
                *(short*)dest = 0;
            return result;
        }
        source += v.consumed;
        dest += v.produced;
        written += v.produced;
    }
    *(short*)dest = 0;
    return 0;
}


// 0x0026a600 FUN_0026a600 (165 B): equivalent/0x0026a600.cpp
// sym: _FUN_0026a600
// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 12/12)
// FUN_0026a600 @ 0x0026a600
// equiv-conv: FUN_0026a600 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a600(const char *source, unsigned short *destination, int input, int capacity, void *options) {
    if (source == (const char *)destination) return -5;
    int used = 0;
    while (*source) {
        struct { unsigned auxiliary, consumed, written; } l;
        if (!FUN_00271820(source, &l.consumed, &l.auxiliary, options)) return -2;
        int result = FUN_00271e40((unsigned)(l.auxiliary), destination, (int)(capacity - used - 2), (int)input, (unsigned int *)(unsigned *)(&l.written), (unsigned int *)(void *)options);
        if (result != 0) {
            if (result == -1) *destination = 0;
            return result;
        }
        source += l.consumed;
        destination = (wchar16_26a600 *)((char *)destination + l.written);
        used += l.written;
    }
    *destination = 0;
    return 0;
}


// 0x0026a6b0 FUN_0026a6b0 (146 B): equivalent/0x0026a6b0.cpp
// sym: _FUN_0026a6b0
// STATUS: equivalent (tools/equiv.py level 3: 113 inputs, branch coverage 8/8)
// FUN_0026a6b0 @ 0x0026a6b0
// equiv-conv: FUN_0026a6b0 eax stack stack
extern "C" int __cdecl FUN_0026a6b0(const char* source, char* destination, unsigned int capacity)
{
    uint_26a6b0 copied = 0;
    struct { uint_26a6b0 bytes; uint_26a6b0 other; } r;
    while (*(const uint_26a6b0*)source) {
        if (!FUN_00272070(source, &r.bytes, &r.other, 0))
            return -1;
        if (copied + r.bytes > capacity - 4)
            break;
        memcpy(destination, source, r.bytes);
        copied += r.bytes;
        destination += r.bytes;
        source += r.bytes;
    }
    *(uint_26a6b0*)destination = 0;
    return copied;
}


// 0x0026a750 FUN_0026a750 (165 B): equivalent/0x0026a750.cpp
// sym: _FUN_0026a750
// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 12/12)
// FUN_0026a750 @ 0x0026a750
// equiv-conv: FUN_0026a750 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a750(const char* source, char* dest, int mode, int capacity, int flags) {
    if (source == dest)
        return -5;
    int written = 0;
    while (*source) {
        struct { int parsed; int consumed; int produced; } v;
        if (!FUN_002716c0(source, &v.consumed, &v.parsed, flags))
            return -2;
        int result = FUN_002720b0(v.parsed, dest, capacity - written - 4, mode, &v.produced, flags);
        if (result != 0) {
            if (result == -1)
                *(int*)dest = 0;
            return result;
        }
        source += v.consumed;
        dest += v.produced;
        written += v.produced;
    }
    *(int*)dest = 0;
    return 0;
}


// 0x0026a800 FUN_0026a800 (165 B): equivalent/0x0026a800.cpp
// sym: _FUN_0026a800
// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 12/12)
// FUN_0026a800 @ 0x0026a800
// equiv-conv: FUN_0026a800 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a800(const char *source, unsigned *destination, int input, int capacity, void *options) {
    if (source == (const char *)destination) return -5;
    int used = 0;
    while (*source) {
        struct { unsigned auxiliary, consumed, written; } l;
        if (!FUN_00271b70(source, &l.consumed, &l.auxiliary, options)) return -2;
        int result = FUN_002720b0(l.auxiliary, destination, capacity - used - 4, input, &l.written, options);
        if (result != 0) {
            if (result == -1) *destination = 0;
            return result;
        }
        source += l.consumed;
        destination = (unsigned *)((char *)destination + l.written);
        used += l.written;
    }
    *destination = 0;
    return 0;
}


// 0x0026a8b0 FUN_0026a8b0 (165 B): equivalent/0x0026a8b0.cpp
// sym: _FUN_0026a8b0
// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 12/12)
// FUN_0026a8b0 @ 0x0026a8b0
// equiv-conv: FUN_0026a8b0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a8b0(const unsigned short *source, char *destination, int mode, int capacity, int options)
{
    if ((const void *)source == (const void *)destination)
        return -5;
    struct { int units; int srcBytes; int written; } r;
    int used = 0;
    while (*source) {
        if (!FUN_00271dd0(source, &r.srcBytes, &r.units, options))
            return -2;
        int result = FUN_002720b0(r.units, destination, capacity - used - 4, mode, &r.written, options);
        if (result) {
            if (result == -1)
                *(int *)destination = 0;
            return result;
        }
        source = (const unsigned short *)((const char *)source + r.srcBytes);
        destination += r.written;
        used += r.written;
    }
    *(int *)destination = 0;
    return 0;
}


// 0x0026a960 FUN_0026a960 (149 B): equivalent/0x0026a960.cpp
// sym: _FUN_0026a960
// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 10/10)
// FUN_0026a960 @ 0x0026a960
// equiv-conv: FUN_0026a960 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a960(const int* source, char* dest, int mode, int capacity, int flags) {
    int written = 0;
    while (*source) {
        struct { int parsed; int consumed; int produced; } v;
        if (!FUN_00272070(source, &v.consumed, &v.parsed, flags))
            return -2;
        int result = FUN_002720b0(v.parsed, dest, capacity - written - 4, mode, &v.produced, flags);
        if (result != 0) {
            if (result == -1)
                *(int*)dest = 0;
            return result;
        }
        source = (const int*)((const char*)source + v.consumed);
        dest += v.produced;
        written += v.produced;
    }
    *(int*)dest = 0;
    return 0;
}


// 0x0026aa00 FUN_0026aa00 (165 B): equivalent/0x0026aa00.cpp
// sym: _FUN_0026aa00
// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 12/12)
// FUN_0026aa00 @ 0x0026aa00
// equiv-conv: FUN_0026aa00 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026aa00(const char *source, unsigned *destination, int input, int capacity, void *options) {
    if (source == (const char *)destination) return -5;
    int used = 0;
    while (*source) {
        struct { unsigned auxiliary, consumed, written; } l;
        if (!FUN_00272240(source, &l.consumed, &l.auxiliary, options)) return -2;
        int result = FUN_002720b0(l.auxiliary, destination, capacity - used - 4, input, &l.written, options);
        if (result != 0) {
            if (result == -1) *destination = 0;
            return result;
        }
        source += l.consumed;
        destination = (unsigned *)((char *)destination + l.written);
        used += l.written;
    }
    *destination = 0;
    return 0;
}


// 0x0026aab0 FUN_0026aab0 (165 B): equivalent/0x0026aab0.cpp
// sym: _FUN_0026aab0
// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 12/12)
// FUN_0026aab0 @ 0x0026aab0
// equiv-conv: FUN_0026aab0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026aab0(const char *source, char *destination, int mode, int capacity, int options)
{
    if ((const void *)source == (const void *)destination)
        return -5;
    struct { int units; int srcBytes; int written; } r;
    int used = 0;
    while (*source) {
        if (!FUN_00271820(source, &r.srcBytes, &r.units, options))
            return -2;
        int result = FUN_002720b0(r.units, destination, capacity - used - 4, mode, &r.written, options);
        if (result) {
            if (result == -1)
                *(int *)destination = 0;
            return result;
        }
        source = (const char *)((const char *)source + r.srcBytes);
        destination += r.written;
        used += r.written;
    }
    *(int *)destination = 0;
    return 0;
}


// 0x0026ab60 FUN_0026ab60 (141 B): equivalent/0x0026ab60.cpp
// sym: ?FUN_0026ab60@fn_fcad8d96@@YAHPBDPADI@Z
// STATUS: equivalent (tools/equiv.py level 3: 228 inputs, branch coverage 8/8)
// FUN_0026ab60 @ 0x0026ab60
// Copies whole UTF-8-like characters from source into dest while they fit in capacity-1 bytes,
// then terminates dest. Returns the number of bytes copied, or -1 on a bad character.
// equiv-conv: FUN_0026ab60 eax stack stack
int __cdecl FUN_0026ab60(const char* source, char* dest, uint_26ab60 capacity) {
    uint_26ab60 written = 0;
    while (*source != 0) {
        uint_26ab60 length;
        uint_26ab60 other;
        if (!FUN_00272240(source, &length, &other, 0))
            return -1;
        if (written + length > capacity - 1)
            break;
        memcpy(dest, source, length);
        written += length;
        source += length;
        dest += length;
    }
    *dest = 0;
    return (int)written;
}


// 0x0026abf0 FUN_0026abf0 (144 B): equivalent/0x0026abf0.cpp
// sym: _FUN_0026abf0
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// FUN_0026abf0 @ 0x0026abf0
// equiv-conv: FUN_0026abf0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026abf0(const char *text, char *output, int options, int capacity, void *state)
{
    int total = 0;
    while (*text != 0) {
        struct { unsigned value, consumed, produced; } l;
        if (!FUN_002716c0(text, &l.consumed, &l.value, state))
            return -2;
        int result = FUN_002722b0(l.value, output, capacity - total - 1,
                                  options, &l.produced, state);
        if (result != 0) {
            if (result == -1)
                *output = 0;
            return result;
        }
        text += l.consumed;
        output += l.produced;
        total += l.produced;
    }
    *output = 0;
    return 0;
}


// 0x0026ac80 FUN_0026ac80 (144 B): equivalent/0x0026ac80.cpp
// sym: _FUN_0026ac80
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// FUN_0026ac80 @ 0x0026ac80
// equiv-conv: FUN_0026ac80 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026ac80(const char* input, char* output, void* value, int capacity, void* context)
{
    int used = 0;
    for (;;) {
        if (!*input) {
            *output = 0;
            return 0;
        }
        int consumed;
        const char* token;
        if (!FUN_00271b70(input, &consumed, &token, context))
            return -2;
        int produced;
        int result = FUN_002722b0(token, output, capacity - used - 1,
                                  value, &produced, context);
        if (result != 0) {
            if (result == -1)
                *output = 0;
            return result;
        }
        input += consumed;
        output += produced;
        used += produced;
    }
}

} // namespace fn_fcad8d96

// 0x0026ad10 FUN_0026ad10 (160 B): equivalent/0x0026ad10.cpp [wrapped: compile error in a shared declaration (C2732)]
// sym: _FUN_0026ad10
namespace fn_0026ad10 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_0026ad10 @ 0x0026ad10
// FUN_0026ad10 converts a string of 16-bit code units to bytes, one decoded unit at a time
typedef unsigned short wchar16_26ad10;
extern "C++" __declspec(nothrow) char __cdecl FUN_00271dd0(const wchar16_26ad10 *, unsigned *, unsigned *, void *);
extern "C" int __cdecl FUN_002722b0(unsigned, char *, int, int, unsigned *, void *);

// equiv-conv: FUN_0026ad10 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026ad10(const unsigned short *source, char *destination, int input, int capacity, void *options) {
    if ((const void *)source == (void *)destination) return -5;
    int used = 0;
    while (*source) {
        struct { unsigned auxiliary, consumed, written; } t;
        if (!FUN_00271dd0(source, &t.consumed, &t.auxiliary, options)) return -2;
        int result = FUN_002722b0(t.auxiliary, destination, capacity - used - 1, input, &t.written, options);
        if (result != 0) {
            if (result == -1) *destination = 0;
            return result;
        }
        source = (const wchar16_26ad10 *)((const char *)source + t.consumed);
        destination += t.written;
        used += t.written;
    }
    *destination = 0;
    return 0;
}
} // namespace fn_0026ad10

namespace fn_fcad8d96 {

// 0x0026adb0 FUN_0026adb0 (160 B): equivalent/0x0026adb0.cpp
// sym: _FUN_0026adb0
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_0026adb0 @ 0x0026adb0
// FUN_0026adb0 converts a string of 32-bit code units to bytes, one decoded unit at a time
// equiv-conv: FUN_0026adb0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026adb0(const unsigned *source, char *destination, int input, int capacity, void *options) {
    if ((const void *)source == (void *)destination) return -5;
    int used = 0;
    while (*source) {
        struct { unsigned auxiliary, consumed, written; } t;
        if (!FUN_00272070(source, &t.consumed, &t.auxiliary, options)) return -2;
        int result = FUN_002722b0(t.auxiliary, destination, capacity - used - 1, input, &t.written, options);
        if (result != 0) {
            if (result == -1) *destination = 0;
            return result;
        }
        source = (const unsigned *)((const char *)source + t.consumed);
        destination += t.written;
        used += t.written;
    }
    *destination = 0;
    return 0;
}


// 0x0026ae50 FUN_0026ae50 (144 B): equivalent/0x0026ae50.cpp
// sym: _FUN_0026ae50
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// FUN_0026ae50 @ 0x0026ae50
// equiv-conv: FUN_0026ae50 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026ae50(const char* input, char* output, void* value, int capacity, void* context)
{
    int used = 0;
    for (;;) {
        if (!*input) {
            *output = 0;
            return 0;
        }
        int consumed;
        const char* token;
        if (!FUN_00272240(input, &consumed, &token, context))
            return -2;
        int produced;
        int result = FUN_002722b0(token, output, capacity - used - 1,
                                  value, &produced, context);
        if (result != 0) {
            if (result == -1)
                *output = 0;
            return result;
        }
        input += consumed;
        output += produced;
        used += produced;
    }
}


// 0x0026aee0 FUN_0026aee0 (144 B): equivalent/0x0026aee0.cpp
// sym: _FUN_0026aee0
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// FUN_0026aee0 @ 0x0026aee0
// equiv-conv: FUN_0026aee0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026aee0(const char* input, char* output, void* value, int capacity, void* context)
{
    int used = 0;
    for (;;) {
        if (!*input) {
            *output = 0;
            return 0;
        }
        int consumed;
        const char* token;
        if (!FUN_00271820(input, &consumed, &token, context))
            return -2;
        int produced;
        int result = FUN_002722b0(token, output, capacity - used - 1,
                                  value, &produced, context);
        if (result != 0) {
            if (result == -1)
                *output = 0;
            return result;
        }
        input += consumed;
        output += produced;
        used += produced;
    }
}


// 0x0026af70 FUN_0026af70 (141 B): equivalent/0x0026af70.cpp
// sym: ?FUN_0026af70@fn_fcad8d96@@YAHPBDPADI@Z
// STATUS: equivalent (tools/equiv.py level 3: 228 inputs, branch coverage 8/8)
// FUN_0026af70 @ 0x0026af70
// equiv-conv: FUN_0026af70 eax stack stack
int __cdecl FUN_0026af70(const char* source, char* destination, uint_26af70 capacity)
{
    uint_26af70 copied = 0;
    uint_26af70 bytes;
    uint_26af70 other;
    while (*source) {
        if (!FUN_00271820(source, &bytes, &other, 0))
            return -1;
        if (copied + bytes > capacity - 1)
            break;
        memcpy(destination, source, bytes);
        copied += bytes;
        destination += bytes;
        source += bytes;
    }
    *destination = 0;
    return copied;
}


// 0x0026b000 FUN_0026b000 (144 B): equivalent/0x0026b000.cpp
// sym: _FUN_0026b000
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// FUN_0026b000 @ 0x0026b000
// equiv-conv: FUN_0026b000 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026b000(const char* source, char* dest, int mode, int capacity, int flags) {
    int written = 0;
    while (*source) {
        struct { int parsed; int consumed; int produced; } v;
        if (!FUN_002716c0(source, &v.consumed, &v.parsed, flags))
            return -2;
        int result = FUN_00271870(v.parsed, dest, capacity - written - 1, mode, &v.produced, flags);
        if (result != 0) {
            if (result == -1)
                *(char*)dest = 0;
            return result;
        }
        source += v.consumed;
        dest += v.produced;
        written += v.produced;
    }
    *(char*)dest = 0;
    return 0;
}


// 0x0026b090 FUN_0026b090 (144 B): equivalent/0x0026b090.cpp
// sym: _FUN_0026b090
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// FUN_0026b090 @ 0x0026b090
// equiv-conv: FUN_0026b090 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026b090(const char* input, char* output, void* value, int capacity, void* context)
{
    int used = 0;
    for (;;) {
        if (!*input) {
            *output = 0;
            return 0;
        }
        int consumed;
        const char* token;
        if (!FUN_00271b70(input, &consumed, &token, context))
            return -2;
        int produced;
        int result = FUN_00271870(token, output, capacity - used - 1,
                                  value, &produced, context);
        if (result != 0) {
            if (result == -1)
                *output = 0;
            return result;
        }
        input += consumed;
        output += produced;
        used += produced;
    }
}

} // namespace fn_fcad8d96

// 0x0026b120 FUN_0026b120 (160 B): equivalent/0x0026b120.cpp [wrapped: compile error in a shared declaration (C2732)]
// sym: _FUN_0026b120
namespace fn_0026b120 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_0026b120 @ 0x0026b120
// FUN_0026b120 converts a string of 16-bit code units to bytes, one decoded unit at a time
typedef unsigned short wchar16_26b120;
extern "C++" __declspec(nothrow) char __cdecl FUN_00271dd0(const wchar16_26b120 *, unsigned *, unsigned *, void *);
extern "C++" __declspec(nothrow) int __cdecl FUN_00271870(unsigned, char *, int, int, unsigned *, void *);

// equiv-conv: FUN_0026b120 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026b120(const unsigned short *source, char *destination, int input, int capacity, void *options) {
    if ((const void *)source == (void *)destination) return -5;
    int used = 0;
    while (*source) {
        struct { unsigned auxiliary, consumed, written; } t;
        if (!FUN_00271dd0(source, &t.consumed, &t.auxiliary, options)) return -2;
        int result = FUN_00271870(t.auxiliary, destination, capacity - used - 1, input, &t.written, options);
        if (result != 0) {
            if (result == -1) *destination = 0;
            return result;
        }
        source = (const wchar16_26b120 *)((const char *)source + t.consumed);
        destination += t.written;
        used += t.written;
    }
    *destination = 0;
    return 0;
}
} // namespace fn_0026b120

namespace fn_fcad8d96 {

// 0x0026b1c0 FUN_0026b1c0 (160 B): equivalent/0x0026b1c0.cpp
// sym: _FUN_0026b1c0
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_0026b1c0 @ 0x0026b1c0
// FUN_0026b1c0 converts a string of 32-bit code units to bytes, one decoded unit at a time
// equiv-conv: FUN_0026b1c0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026b1c0(const unsigned *source, char *destination, int input, int capacity, void *options) {
    if ((const void *)source == (void *)destination) return -5;
    int used = 0;
    while (*source) {
        struct { unsigned auxiliary, consumed, written; } t;
        if (!FUN_00272070(source, &t.consumed, &t.auxiliary, options)) return -2;
        int result = FUN_00271870(t.auxiliary, destination, capacity - used - 1, input, &t.written, options);
        if (result != 0) {
            if (result == -1) *destination = 0;
            return result;
        }
        source = (const unsigned *)((const char *)source + t.consumed);
        destination += t.written;
        used += t.written;
    }
    *destination = 0;
    return 0;
}


// 0x0026b260 FUN_0026b260 (144 B): equivalent/0x0026b260.cpp
// sym: _FUN_0026b260
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// FUN_0026b260 @ 0x0026b260
// equiv-conv: FUN_0026b260 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026b260(const char* input, char* output, void* value, int capacity, void* context)
{
    int used = 0;
    for (;;) {
        if (!*input) {
            *output = 0;
            return 0;
        }
        int consumed;
        const char* token;
        if (!FUN_00272240(input, &consumed, &token, context))
            return -2;
        int produced;
        int result = FUN_00271870(token, output, capacity - used - 1,
                                  value, &produced, context);
        if (result != 0) {
            if (result == -1)
                *output = 0;
            return result;
        }
        input += consumed;
        output += produced;
        used += produced;
    }
}


// 0x0026b2f0 FUN_0026b2f0 (144 B): equivalent/0x0026b2f0.cpp
// sym: _FUN_0026b2f0
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// FUN_0026b2f0 @ 0x0026b2f0
// equiv-conv: FUN_0026b2f0 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026b2f0(const char* input, char* output, void* value, int capacity, void* context)
{
    int used = 0;
    for (;;) {
        if (!*input) {
            *output = 0;
            return 0;
        }
        int consumed;
        const char* token;
        if (!FUN_00271820(input, &consumed, &token, context))
            return -2;
        int produced;
        int result = FUN_00271870(token, output, capacity - used - 1,
                                  value, &produced, context);
        if (result != 0) {
            if (result == -1)
                *output = 0;
            return result;
        }
        input += consumed;
        output += produced;
        used += produced;
    }
}


// 0x0026b380 FUN_0026b380 (163 B): equivalent/0x0026b380.cpp
// sym: ?FUN_0026b380@fn_fcad8d96@@YAHHHHHHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 16/16)
// FUN_0026b380 @ 0x0026b380
// FUN_0026b380 @ 0x0026b380
// equiv-conv: FUN_002699f0 eax stack stack
// equiv-conv: FUN_00269a80 eax ecx stack stack stack
// equiv-conv: FUN_00269b10 eax ecx stack stack stack
// equiv-conv: FUN_00269ba0 eax ecx stack stack stack
// equiv-conv: FUN_00269c40 eax ecx stack stack stack
// equiv-conv: FUN_00269ce0 eax ecx stack stack stack
// equiv-conv: FUN_00269d70 eax ecx stack stack stack
// equiv-conv: FUN_0026b380 stack stack stack ebx edx esi edi
int __cdecl FUN_0026b380(hulk_intptr a, int fromMode, hulk_intptr c, int toMode, int edxArg, int esiArg, int ediArg) {
    if (fromMode == toMode && edxArg == 0) {
        int r = FUN_002699f0(c, a, esiArg);
        if (r < 0) return -2;
        return (r >= esiArg) ? 0 : -1;
    }
    switch (toMode) {
    case 0: return FUN_00269a80((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, (void *)(hulk_uintptr)(int)ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 1: return FUN_00269b10((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, (void *)(hulk_uintptr)(int)ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 2: return FUN_00269ba0((const unsigned short *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 3: return FUN_00269c40((const unsigned *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 4: return FUN_00269ce0((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, (void *)(hulk_uintptr)(int)ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 5: return FUN_00269d70((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, (void *)(hulk_uintptr)(int)ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    }
    return -2;
}


// 0x0026b440 FUN_0026b440 (163 B): equivalent/0x0026b440.cpp
// sym: ?FUN_0026b440@fn_fcad8d96@@YAHHHHHHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 16/16)
// FUN_0026b440 @ 0x0026b440
// FUN_0026b440 @ 0x0026b440
// equiv-conv: FUN_00269e00 eax stack stack
// equiv-conv: FUN_00269e90 eax ecx stack stack stack
// equiv-conv: FUN_00269f20 eax ecx stack stack stack
// equiv-conv: FUN_00269fb0 eax ecx stack stack stack
// equiv-conv: FUN_0026a050 eax ecx stack stack stack
// equiv-conv: FUN_0026a0f0 eax ecx stack stack stack
// equiv-conv: FUN_0026a180 eax ecx stack stack stack
// equiv-conv: FUN_0026b440 stack stack stack ebx edx esi edi
int __cdecl FUN_0026b440(hulk_intptr a, int fromMode, hulk_intptr c, int toMode, int edxArg, int esiArg, int ediArg) {
    if (fromMode == toMode && edxArg == 0) {
        int r = FUN_00269e00(c, a, esiArg);
        if (r < 0) return -2;
        return (r >= esiArg) ? 0 : -1;
    }
    switch (toMode) {
    case 0: return FUN_00269e90((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, edxArg);
    case 1: return FUN_00269f20((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, (void *)(hulk_uintptr)(int)ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 2: return FUN_00269fb0((const unsigned short *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 3: return FUN_0026a050((const unsigned *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 4: return FUN_0026a0f0((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, (void *)(hulk_uintptr)(int)ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 5: return FUN_0026a180((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, (void *)(hulk_uintptr)(int)ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    }
    return -2;
}


// 0x0026b500 FUN_0026b500 (163 B): equivalent/0x0026b500.cpp
// sym: ?FUN_0026b500@fn_fcad8d96@@YAHHHHHHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 16/16)
// FUN_0026b500 @ 0x0026b500
// FUN_0026b500 @ 0x0026b500
// equiv-conv: FUN_0026a210 eax stack stack
// equiv-conv: FUN_0026a2a0 eax ecx stack stack stack
// equiv-conv: FUN_0026a350 eax ecx stack stack stack
// equiv-conv: FUN_0026a400 eax ecx stack stack stack
// equiv-conv: FUN_0026a4a0 eax ecx stack stack stack
// equiv-conv: FUN_0026a550 eax ecx stack stack stack
// equiv-conv: FUN_0026a600 eax ecx stack stack stack
// equiv-conv: FUN_0026b500 stack stack stack ebx edx esi edi
int __cdecl FUN_0026b500(hulk_intptr a, int fromMode, hulk_intptr c, int toMode, int edxArg, int esiArg, int ediArg) {
    if (fromMode == toMode && edxArg == 0) {
        int r = FUN_0026a210((const unsigned short *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, (int)esiArg);
        if (r < 0) return -2;
        return (r >= esiArg) ? 0 : -1;
    }
    switch (toMode) {
    case 0: return FUN_0026a2a0((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, edxArg);
    case 1: return FUN_0026a350((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, edxArg);
    case 2: return FUN_0026a400((const unsigned short *)(hulk_uintptr)(int)c, (unsigned short *)(hulk_uintptr)(int)a, ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 3: return FUN_0026a4a0((const unsigned *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, edxArg);
    case 4: return FUN_0026a550((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, edxArg);
    case 5: return FUN_0026a600((const char *)(hulk_uintptr)(int)c, (unsigned short *)(hulk_uintptr)(int)a, ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    }
    return -2;
}


// 0x0026b5c0 FUN_0026b5c0 (163 B): equivalent/0x0026b5c0.cpp
// sym: ?FUN_0026b5c0@fn_fcad8d96@@YAHHHHHHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 16/16)
// FUN_0026b5c0 @ 0x0026b5c0
// FUN_0026b5c0 @ 0x0026b5c0
// equiv-conv: FUN_0026a6b0 eax stack stack
// equiv-conv: FUN_0026a750 eax ecx stack stack stack
// equiv-conv: FUN_0026a800 eax ecx stack stack stack
// equiv-conv: FUN_0026a8b0 eax ecx stack stack stack
// equiv-conv: FUN_0026a960 eax ecx stack stack stack
// equiv-conv: FUN_0026aa00 eax ecx stack stack stack
// equiv-conv: FUN_0026aab0 eax ecx stack stack stack
// equiv-conv: FUN_0026b5c0 stack stack stack ebx edx esi edi
int __cdecl FUN_0026b5c0(hulk_intptr a, int fromMode, hulk_intptr c, int toMode, int edxArg, int esiArg, int ediArg) {
    if (fromMode == toMode && edxArg == 0) {
        int r = FUN_0026a6b0((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, (int)esiArg);
        if (r < 0) return -2;
        return (r >= esiArg) ? 0 : -1;
    }
    switch (toMode) {
    case 0: return FUN_0026a750((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, edxArg);
    case 1: return FUN_0026a800((const char *)(hulk_uintptr)(int)c, (unsigned *)(hulk_uintptr)(int)a, ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 2: return FUN_0026a8b0((const unsigned short *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, edxArg);
    case 3: return FUN_0026a960((const int *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, edxArg);
    case 4: return FUN_0026aa00((const char *)(hulk_uintptr)(int)c, (unsigned *)(hulk_uintptr)(int)a, ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 5: return FUN_0026aab0((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, edxArg);
    }
    return -2;
}


// 0x0026b680 FUN_0026b680 (163 B): equivalent/0x0026b680.cpp
// sym: ?FUN_0026b680@fn_fcad8d96@@YAHHHHHHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 16/16)
// FUN_0026b680 @ 0x0026b680
// FUN_0026b680 @ 0x0026b680
// equiv-conv: FUN_0026ab60 eax stack stack
// equiv-conv: FUN_0026abf0 eax ecx stack stack stack
// equiv-conv: FUN_0026ac80 eax ecx stack stack stack
// equiv-conv: FUN_0026ad10 eax ecx stack stack stack
// equiv-conv: FUN_0026adb0 eax ecx stack stack stack
// equiv-conv: FUN_0026ae50 eax ecx stack stack stack
// equiv-conv: FUN_0026aee0 eax ecx stack stack stack
// equiv-conv: FUN_0026b680 stack stack stack ebx edx esi edi
int __cdecl FUN_0026b680(hulk_intptr a, int fromMode, hulk_intptr c, int toMode, int edxArg, int esiArg, int ediArg) {
    if (fromMode == toMode && edxArg == 0) {
        int r = FUN_0026ab60(c, a, esiArg);
        if (r < 0) return -2;
        return (r >= esiArg) ? 0 : -1;
    }
    switch (toMode) {
    case 0: return FUN_0026abf0((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 1: return FUN_0026ac80((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, (void *)(hulk_uintptr)(int)ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 2: return FUN_0026ad10((const unsigned short *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 3: return FUN_0026adb0((const unsigned *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 4: return FUN_0026ae50((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, (void *)(hulk_uintptr)(int)ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 5: return FUN_0026aee0((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, (void *)(hulk_uintptr)(int)ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    }
    return -2;
}


// 0x0026b740 FUN_0026b740 (163 B): equivalent/0x0026b740.cpp
// sym: ?FUN_0026b740@fn_fcad8d96@@YAHHHHHHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 16/16)
// FUN_0026b740 @ 0x0026b740
// FUN_0026b740 @ 0x0026b740
// equiv-conv: FUN_0026af70 eax stack stack
// equiv-conv: FUN_0026b000 eax ecx stack stack stack
// equiv-conv: FUN_0026b090 eax ecx stack stack stack
// equiv-conv: FUN_0026b120 eax ecx stack stack stack
// equiv-conv: FUN_0026b1c0 eax ecx stack stack stack
// equiv-conv: FUN_0026b260 eax ecx stack stack stack
// equiv-conv: FUN_0026b2f0 eax ecx stack stack stack
// equiv-conv: FUN_0026b740 stack stack stack ebx edx esi edi
int __cdecl FUN_0026b740(hulk_intptr a, int fromMode, hulk_intptr c, int toMode, int edxArg, int esiArg, int ediArg) {
    if (fromMode == toMode && edxArg == 0) {
        int r = FUN_0026af70(c, a, esiArg);
        if (r < 0) return -2;
        return (r >= esiArg) ? 0 : -1;
    }
    switch (toMode) {
    case 0: return FUN_0026b000((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, edxArg);
    case 1: return FUN_0026b090((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, (void *)(hulk_uintptr)(int)ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 2: return FUN_0026b120((const unsigned short *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 3: return FUN_0026b1c0((const unsigned *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 4: return FUN_0026b260((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, (void *)(hulk_uintptr)(int)ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    case 5: return FUN_0026b2f0((const char *)(hulk_uintptr)(int)c, (char *)(hulk_uintptr)(int)a, (void *)(hulk_uintptr)(int)ediArg, esiArg, (void *)(hulk_uintptr)(int)edxArg);
    }
    return -2;
}


// 0x0026b800 FUN_0026b800 (229 B): equivalent/0x0026b800.cpp
// sym: _FUN_0026b800
// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 18/18)
// FUN_0026b800 @ 0x0026b800
// equiv-conv: FUN_0026b380 stack stack stack ebx edx esi edi
// equiv-conv: FUN_0026b440 stack stack stack ebx edx esi edi
// equiv-conv: FUN_0026b500 stack stack stack ebx edx esi edi
// equiv-conv: FUN_0026b5c0 stack stack stack ebx edx esi edi
// equiv-conv: FUN_0026b680 stack stack stack ebx edx esi edi
// equiv-conv: FUN_0026b740 stack stack stack ebx edx esi edi
extern "C" int FUN_0026b800(void* a, int fromMode, void* c, int toMode, int e, int f, int g) {
    if (a == 0)
        return -3;
    if (c == 0)
        return -2;
    if (fromMode == toMode && a == c && g == 0)
        return 0;
    switch (fromMode) {
    case 0:
        return FUN_0026b380(a, 0, c, toMode, g, f, e);
    case 1:
        return FUN_0026b440(a, 1, c, toMode, g, f, e);
    case 2:
        return FUN_0026b500(a, 2, c, toMode, g, f, e);
    case 3:
        return FUN_0026b5c0(a, 3, c, toMode, g, f, e);
    case 4:
        return FUN_0026b680(a, 4, c, toMode, g, f, e);
    case 5:
        return FUN_0026b740(a, 5, c, toMode, g, f, e);
    }
    return -3;
}

} // namespace fn_fcad8d96
