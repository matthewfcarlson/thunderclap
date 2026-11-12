// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0024c1c0..0x0024cc00 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_f52e920b {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f52e920b {} using namespace fn_f52e920b;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f52e920b {
struct Entry {
  public:
    union { int a; int value; };
    union { int b; const char *name; };
    int *key;
    int d;
    char _m_pad_10[0x8];
};
typedef unsigned char u8_24c2b0;
typedef unsigned int u32_24c310;
typedef int i32_24c310;
typedef unsigned int uint_24c3e0;
struct FmtEntry {
    unsigned int scaleA;
    unsigned int scaleB;
    unsigned int pad[4];
};
extern "C" unsigned int __cdecl FUN_0024c590(unsigned int* p, unsigned int x);
struct Obj_24c910 {
    char pad[0x3c];
    float value;
    int other;
};
struct Obj_24c950 {
    char pad[0x50];
    float value;
};
typedef unsigned int u32_24ca70;
typedef unsigned int U_24cab0;
typedef unsigned int U32_24cb50;
struct Triple_24cb50 {
    U32_24cb50 a;
    U32_24cb50 b;
    U32_24cb50 c;
};
struct A_24cb70 {
    char pad[12];
    unsigned x, y, z;
};
struct B_24cb70 {
    unsigned x, y, z;
};


// 0x0024c1c0 FUN_0024c1c0 (51 B): equivalent/0x0024c1c0.cpp
// sym: _FUN_0024c1c0 @5f76c8943744 @w8966a7b50904
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0024c1c0 @ 0x0024c1c0
extern "C" int __cdecl FUN_0024c1c0(const int *key) { for (int i = 0; i < 6; ++i) { if (*key == *((Entry*)&DAT_004cc248)[i].key) return ((Entry*)&DAT_004cc248)[i].value; } return 7; }


// 0x0024c200 FUN_0024c200 (97 B): equivalent/0x0024c200.cpp
// sym: ?FUN_0024c200@fn_f52e920b@@YAHPBD@Z @d7cfacbe3c2f @w2760b7f485d1
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 12/12)
// FUN_0024c200 @ 0x0024c200
int __cdecl FUN_0024c200(const char *name)
{
    for (unsigned i = 0; i < 6; ++i) {
        const char *a = name;
        const char *b = ((Entry*)&DAT_004cc248)[i].name;
        while (*a && *a == *b) { ++a; ++b; }
        if (*a == *b) return ((Entry*)&DAT_004cc248)[i].value;
    }
    return 7;
}


// 0x0024c2b0 FUN_0024c2b0 (15 B): matches/0x0024c2b0.cpp
// sym: _FUN_0024c2b0
// data: gTable_24c2b0 = DAT_004cc254 + 8 (the codec table's third field)
extern "C" u8_24c2b0 __cdecl FUN_0024c2b0(int i) {
    return ((u8_24c2b0*)((char*)&DAT_004cc254 + 8))[i * 24];
}


// 0x0024c2c0 FUN_0024c2c0 (13 B): matches/0x0024c2c0.cpp
// sym: _FUN_0024c2c0
extern "C" int __cdecl FUN_0024c2c0(int* format) {
    return (*format << 0x1c) >> 0x1c;
}


// 0x0024c2d0 FUN_0024c2d0 (13 B): matches/0x0024c2d0.cpp
// sym: _FUN_0024c2d0
extern "C" unsigned int FUN_0024c2d0(unsigned int* p) {
    return (*p >> 4) & 0x1f;
}


// 0x0024c2f0 FUN_0024c2f0 (32 B): matches/0x0024c2f0.cpp
// sym: _FUN_0024c2f0
// data: gTable_24c2f0 = DAT_004cc254 + 4 (the codec table's second field)
extern "C" int FUN_0024c2f0(unsigned int* p) {
    unsigned int v = *p;
    int index = (int)(v << 28) >> 28;
    return (int)((v >> 4) & 31) * *(int*)((char*)((int*)((char*)&DAT_004cc254 + 4)) + index * 24);
}


// 0x0024c310 FUN_0024c310 (23 B): matches/0x0024c310.cpp
// sym: _FUN_0024c310
extern "C" u32_24c310 __cdecl FUN_0024c310(i32_24c310* format) {
    return ((u32_24c310*)&DAT_004cc254)[((*format << 28) >> 28) * 6];
}


// 0x0024c330 FUN_0024c330 (57 B): matches/0x0024c330.cpp
// sym: _FUN_0024c330
extern "C" unsigned* FUN_0024c330(unsigned* p, unsigned a, unsigned b, unsigned c) {
    *p = ((((b & 0x1ffff | 0x200000) << 5 | c & 0x1f) << 4) | (*(volatile unsigned*)p & 0xc0000000)) |
         (a & 0xf);
    return p;
}


// 0x0024c3b0 FUN_0024c3b0 (37 B): matches/0x0024c3b0.cpp
// sym: _FUN_0024c3b0
// data: gData_24c3b0 = DAT_004cc254 + 4 (the codec table's second field)
extern "C" int FUN_0024c3b0(unsigned int* format, int count) {
    return ((*format >> 4) & 0x1f) * ((int*)((char*)&DAT_004cc254 + 4))[((int)(*format << 28) >> 28) * 6] * count;
}


// 0x0024c3e0 FUN_0024c3e0 (44 B): matches/0x0024c3e0.cpp
// sym: _FUN_0024c3e0
extern "C" hulk_uintptr __cdecl FUN_0024c3e0(uint_24c3e0* format, uint_24c3e0 bytes) {
    return bytes / (((*format >> 4) & 0x1f) * ((int*)((char*)&DAT_004cc254 + 4))[((int)(*format << 0x1c) >> 0x1c) * 6]);
}


// 0x0024c480 FUN_0024c480 (70 B): matches/0x0024c480.cpp
// sym: _FUN_0024c480
extern "C" int FUN_0024c480(unsigned int* format, unsigned int bytes) {
    unsigned int x = *format;
    int index = (int)(x << 28) >> 28;
    unsigned int m = (x >> 4);
    m &= 31;
    unsigned int d = *(unsigned int*)(((unsigned char*)&DAT_004cc254) + index * 24);
    unsigned int s = m * *(unsigned int*)(((unsigned char*)((char*)&DAT_004cc254 + 4)) + index * 24);
    unsigned int q = bytes / d;
    unsigned int r = bytes % d;
    return (r * s) / d + q * s;
}


// 0x0024c4d0 FUN_0024c4d0 (70 B): matches/0x0024c4d0.cpp
// sym: _FUN_0024c4d0
extern "C" unsigned __cdecl FUN_0024c4d0(unsigned* p, unsigned n) {
    unsigned x = *p;
    int i = (int)(x << 28) >> 28;
    unsigned d = ((x >> 4) & 31) * ((Entry*)&DAT_004cc254)[i].b;
    unsigned q = n / d;
    unsigned r = n % d;
    unsigned v = ((Entry*)&DAT_004cc254)[i].a;
    unsigned z = q * v;
    return z + r * v / d;
}


// 0x0024c520 FUN_0024c520 (109 B): equivalent/0x0024c520.cpp
// sym: ?FUN_0024c520@fn_f52e920b@@YAIPAII@Z @d0daff9ea334 @w213b37c98b1c
// STATUS: equivalent (tools/equiv.py level 3: 965 inputs, branch coverage 0/0)
// FUN_0024c520 @ 0x0024c520
unsigned int FUN_0024c520(unsigned int *packed, unsigned int value)
{
    unsigned int w = *packed;
    const FmtEntry &e = ((FmtEntry*)&DAT_004cc254)[(int)(w << 28) >> 28];
    unsigned int unit = ((w >> 4) & 0x1f) * e.scaleB;
    unsigned int q = value / unit;
    unsigned int r = value % unit;
    unsigned int scaled = (r * e.scaleA) / unit + q * e.scaleA;
    unsigned int divisor = (w >> 9) & 0x1ffff;
    unsigned int whole = scaled / divisor;
    unsigned int rem = scaled % divisor;
    return whole * 1000 + (rem * 1000) / divisor;
}


// 0x0024c590 FUN_0024c590 (110 B): matches/0x0024c590.cpp
// sym: _FUN_0024c590
unsigned int __cdecl FUN_0024c590(unsigned int* p, unsigned int x) {
    unsigned int u = p[0];
    unsigned int v = (u >> 9) & 0x1ffff;
    unsigned int r = ((x % 1000) * v) / 1000 + (x / 1000) * v;
    int i = (int)(u << 28) >> 28;
    unsigned int d = ((unsigned int*)&DAT_004cc254)[i * 6];
    unsigned int n = (u >> 4 & 31) * ((unsigned int*)((char*)&DAT_004cc254 + 4))[i * 6];
    return ((r % d) * n) / d + (r / d) * n;
}


// 0x0024c710 FUN_0024c710 (6 B): matches/0x0024c710.cpp
// sym: _FUN_0024c710
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0024c710() {
    return &(*(int*)&DAT_004e61f0);
}


// 0x0024c740 FUN_0024c740 (6 B): matches/0x0024c740.cpp
// sym: _FUN_0024c740
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0024c740() {
    return &(*(int*)&DAT_004e6208);
}


// 0x0024c760 FUN_0024c760 (11 B): matches/0x0024c760.cpp
// sym: _FUN_0024c760
// data: gValue_24c760 = DAT_004e6200
extern "C" void FUN_0024c760(void) {
    (*(int*)&DAT_004e6200) = 0;
}


// 0x0024c7f0 FUN_0024c7f0 (10 B): matches/0x0024c7f0.cpp
// sym: _FUN_0024c7f0
// data: g_value_24c7f0 = DAT_004e62d4
extern "C" void FUN_0024c7f0(unsigned char x) {
    (*(unsigned char*)&DAT_004e62d4) = x;
}


// 0x0024c810 FUN_0024c810 (106 B): matches/0x0024c810.cpp
// sym: _FUN_0024c810
extern "C" void FUN_0024c810(unsigned int* p) {
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0x3f800000;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0x3f800000;
    p[12] = 0x43b40000;
    p[13] = 0x43b40000;
    p[14] = 0x3f800000;
    p[15] = 0x41a00000;
    p[16] = 0x42f00000;
    p[17] = 0x3c23d70a;
    p[18] = 0;
    p[19] = 0;
    p[20] = 0x3f800000;
    p[21] = 0x3f800000;
    p[22] = 0;
    p[23] = 0;
    p[24] = 0x3f800000;
}


// 0x0024c880 FUN_0024c880 (1 B): matches/0x0024c880.cpp
// sym: _FUN_0024c880
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_0024c880() {}


// 0x0024c910 FUN_0024c910 (19 B): matches/0x0024c910.cpp
// sym: _FUN_0024c910
extern "C" void __cdecl FUN_0024c910(Obj_24c910* a, float b, int c) {
    a->value = b;
    a->other = c;
}


// 0x0024c950 FUN_0024c950 (12 B): matches/0x0024c950.cpp
// sym: _FUN_0024c950
extern "C" void FUN_0024c950(Obj_24c950* self, float value) {
    self->value = value;
}


// 0x0024c9c0 FUN_0024c9c0 (168 B): matches/0x0024c9c0.cpp
// sym: _FUN_0024c9c0
extern "C" void __cdecl FUN_0024c9c0() {
    (*(float**)&DAT_004e6200) = &DAT_004e6298;
    DAT_004e62b0 = 0.0f;
    DAT_004e62b4 = 0.0f;
    DAT_004e62b8 = 1.0f;
    DAT_004e62bc = 0.0f;
    DAT_004e62c0 = 1.0f;
    DAT_004e62c4 = 0.0f;
    DAT_004e6298 = 0.0f;
    DAT_004e629c = 0.0f;
    DAT_004e62a0 = 0.0f;
    DAT_004e62a4 = 0.0f;
    DAT_004e62a8 = 0.0f;
    DAT_004e62ac = 0.0f;
    DAT_004e62c8 = 1.0f;
    DAT_004e62cc = 1.0f;
    DAT_004e62d0 = 1.0f;
    (*(unsigned char*)&DAT_004e62d4) = 0;
}


// 0x0024ca70 FUN_0024ca70 (30 B): matches/0x0024ca70.cpp
// sym: _FUN_0024ca70
extern "C" void FUN_0024ca70(u32_24ca70* p) {
    (*(u32_24ca70*)&DAT_004e6298) = p[0];
    (*(u32_24ca70*)&DAT_004e629c) = p[1];
    (*(u32_24ca70*)&DAT_004e62a0) = p[2];
}


// 0x0024cab0 FUN_0024cab0 (67 B): matches/0x0024cab0.cpp
// sym: _FUN_0024cab0
// data: g0_24cab0 = DAT_004e62b0
extern "C" void FUN_0024cab0(U_24cab0* a, U_24cab0* b) {
    if (a) {
        (*(U_24cab0*)&DAT_004e62b0) = a[0];
        (*(U_24cab0*)&DAT_004e62b4) = a[1];
        (*(U_24cab0*)&DAT_004e62b8) = a[2];
    }
    if (b) {
        (*(U_24cab0*)&DAT_004e62bc) = b[0];
        (*(U_24cab0*)&DAT_004e62c0) = b[1];
        (*(U_24cab0*)&DAT_004e62c4) = b[2];
    }
}


// 0x0024cb50 FUN_0024cb50 (25 B): matches/0x0024cb50.cpp
// sym: _FUN_0024cb50
extern "C" void FUN_0024cb50(Triple_24cb50* dst, const Triple_24cb50* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
}


// 0x0024cb70 FUN_0024cb70 (26 B): matches/0x0024cb70.cpp
// sym: _FUN_0024cb70
extern "C" void __cdecl FUN_0024cb70(A_24cb70* a, B_24cb70* b) {
    unsigned* d = &a->x;
    const unsigned* s = &b->x;
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
}

} // namespace fn_f52e920b
