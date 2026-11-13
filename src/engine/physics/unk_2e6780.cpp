// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002e6780..0x002ecd50 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/physics_world.h"
#include "decls/data/engine/core.h"
#include "decls/data/engine/physics.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb0f1f83 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fb0f1f83 {} using namespace fn_fb0f1f83;
#include "engine/physics.h"
// (ren2) fprintf's own name (CRT, C linkage)
extern "C" int __cdecl fprintf(void*, const char*, ...);

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#endif
namespace fn_fb0f1f83 {
struct png_struct_2e68a0 {
    char pad[0x114];
    unsigned char chunk_name[4];
};
struct FILE_TYPE { char unused; };
} // namespace fn_fb0f1f83
extern "C" int __cdecl _fwprintf(FILE_TYPE *, const char *);
extern "C" void __cdecl _longjmp(void *, int);
namespace fn_fb0f1f83 {
typedef unsigned int U32_2e6970;
struct S_2e6970 {
    char pad[0x40];
    U32_2e6970 a;
    U32_2e6970 b;
    U32_2e6970 c;
};
typedef void*(__cdecl* Callback)(Object*, void*);
struct Object {
    char pad[0x44];
    Callback callback;
};
void* FUN_002e6950();
extern "C" void __cdecl FUN_002e68a0(char *, void *, const char *);
void __cdecl FUN_002e69a0(void *source, void *result);
struct Data { char bytes[80]; };
void __cdecl FUN_002e69d0(void* object, Data* result);
typedef void* (__cdecl *Allocator)(int, unsigned int);
typedef void(__cdecl* Callback_2e6ab0)(void*, int);
void __cdecl FUN_003479bc(int);
extern "C" void FUN_002e69a0(unsigned int, const char*);
extern "C" void FUN_003479bc(unsigned int);
struct Obj_2e6ba0 {
    char pad[0x20c];
    int a;
    int b;
    int c;
};
typedef unsigned int u32_2e6bf0;
void FUN_002e6ab0(u32_2e6bf0, int);
typedef unsigned int u32_2e6c00;
typedef u32_2e6c00(__cdecl* Callback_2e6c00)(void*, void*);
extern u32_2e6c00 __cdecl fallback_002e6af0(void*, void*);
struct Obj_2e6c00 {
    char pad[0x210];
    Callback_2e6c00 fn;
};
struct Inner_2e6db0 {
    int v0;
    int v1;
    int v2;
    int flag;
    char pad[4];
    int arg;
};
struct Obj_2e6db0 {
    char pad0[8];
    int a;
    char pad1[8];
    int b;
    int c;
    Inner_2e6db0* inner;
};
int __cdecl helper_002ea2a0(int, Obj_2e6db0*, int);
typedef unsigned int u32_2e6e00;
struct Obj_2e6e00 {
    char pad0[0x1c];
    hulk_intptr field1c;
    char pad20[4];
    int(__cdecl* callback)(int, int);
    int field28;
};
extern "C" int __cdecl FUN_002eaf30(void *, void *);
struct State_2e6e50 {
    char pad[12];
    int raw;
    int bits;
    void* table;
};
typedef void*(__cdecl* Alloc_2e6e50)(void*, unsigned, unsigned);
typedef void(__cdecl* Free)(void*, void*);
typedef unsigned(__cdecl* Lookup_2e6e50)(unsigned);
extern void* __cdecl FUN_002eb120(void*, unsigned, unsigned);
extern void __cdecl FUN_002eb140(void*, void*);
extern unsigned __cdecl FUN_002eafc0(unsigned);
struct Stream {
    char pad[24];
    int status;
    State_2e6e50* state;
    Alloc_2e6e50 allocate;
    Free release;
    void* context;
};
extern void* __cdecl FUN_002ea320(Stream*, Lookup_2e6e50, unsigned);
extern "C" int __cdecl FUN_002e6e00(void *);
extern int __cdecl FUN_002e6db0(Stream*);
typedef unsigned int u32_2e6f50;
extern "C" int __cdecl FUN_002e6e50(void *, int, const char *, int);
void FUN_002dd690(int, int, int);
void FUN_002d6cb0(int, int, int);
class Obj_2e75b0 {
  public:
    char pad0[0x64];
    int flags;
    char pad68[0x108 - 0x68];
    int value;
    char pad10c[0x114 - 0x10c];
    unsigned char mode;
};
extern void __cdecl FUN_002dd690(Obj_2e75b0*, int*, int);
extern int __cdecl FUN_002e7500(int*);
struct PngStruct_2e7680 {
    char pad0[0x68];
    unsigned int transformations;
    char pad6c[0xc0 - 0x6c];
    unsigned int width;
    char padc4[0xe4 - 0xc4];
    unsigned char *row_buf;
    char pade8[0x103 - 0xe8];
    unsigned char pixel_depth;
};
struct Image {
  public:
    unsigned int width;
    union { unsigned int p4; unsigned int pitch; };
    char _m_pad_8[0x3];
    unsigned char bitsPerPixel;
    unsigned int rowbytes;
    char _m_pad_10[0x8];
    char channels;
    unsigned char type;
    unsigned char b8;
    unsigned char b9;
    unsigned char b7;
    unsigned char row;
    unsigned char bits;
    char _m_pad_1f[0x41];
    unsigned int flags;
};
struct png_struct_2e7fb0 {
    char pad0[0x64];
    unsigned int flags;                 // 0x64
    unsigned int transformations;       // 0x68
    char pad6c[4];
    unsigned int avail_in;              // 0x70
    char pad74[0xc0 - 0x74];
    unsigned int width;                 // 0xc0
    unsigned int height;                // 0xc4
    unsigned int num_rows;              // 0xc8
    char padcc[4];
    unsigned int rowbytes;              // 0xd0
    unsigned int irowbytes;             // 0xd4
    unsigned int iwidth;                // 0xd8
    char paddc[4];
    unsigned char *row_buf;             // 0xe0
    unsigned char *big_row_buf;         // 0xe4
    char pade8[0x112 - 0xe8];
    unsigned short num_trans;           // 0x112
    char pad114[0x11b - 0x114];
    unsigned char interlaced;           // 0x11b
    unsigned char pass;                 // 0x11c
    char pad11d;
    unsigned char color_type;           // 0x11e
    unsigned char bit_depth;            // 0x11f
    char pad120;
    unsigned char pixel_depth;          // 0x121
};
extern "C" void __cdecl FUN_002dc3e0(png_struct_2e7fb0 *png_ptr);
unsigned char *__cdecl FUN_002e6c00(png_struct_2e7fb0 *png_ptr, unsigned int size);
void __cdecl FUN_002e6b60(png_struct_2e7fb0 *png_ptr, unsigned char *ptr, int value, unsigned int size);
struct png_color_2e84e0 {
    unsigned char red, green, blue;
};
struct png_info_2e84e0 {
    char pad0[8];
    unsigned int valid;
};
struct png_struct_2e84e0 {
    char pad0[0x60];
    unsigned int mode;
    unsigned int flags;
    char pad68[0x10c - 0x68];
    png_color_2e84e0 *palette;
    unsigned short num_palette;
    unsigned short num_trans;
    char pad114[0x11e - 0x114];
    unsigned char color_type;
};
void FUN_002e69a0(png_struct_2e84e0 *png_ptr, const char *msg);
void FUN_002e69d0(png_struct_2e84e0 *png_ptr, const char *msg);
void FUN_002e81e0(png_struct_2e84e0 *png_ptr, unsigned int skip);
void *FUN_002d6c20(png_struct_2e84e0 *png_ptr, unsigned int num, unsigned int size);
void FUN_002e7580(png_struct_2e84e0 *png_ptr, unsigned char *buf, unsigned int length);
void FUN_002eb4c0(png_struct_2e84e0 *png_ptr, png_info_2e84e0 *info_ptr, png_color_2e84e0 *palette, int num);
void Missing_002e69a0(Image*, const char*);
void BadLength_002e69d0(Image*, const char*);
void Finish_002e81e0(Image*, int);
struct png_info_2e87e0 {
    char pad00[8];
    unsigned int valid;
};
struct png_struct_2e87e0 {
    char pad000[0x60];
    unsigned int mode;
    char pad064[0x11e - 0x64];
    unsigned char color_type;
    char pad11f[3];
    unsigned char channels;
    char pad123[0x174 - 0x123];
    unsigned char sig_red;
    unsigned char sig_green;
    unsigned char sig_blue;
    unsigned char sig_gray;
    unsigned char sig_alpha;
};
void __cdecl FUN_002e69a0(png_struct_2e87e0* png_ptr, const char* msg);
void __cdecl FUN_002e69d0(png_struct_2e87e0* png_ptr, const char* msg);
int __cdecl FUN_002e81e0(png_struct_2e87e0* png_ptr, unsigned int skip);
void __cdecl FUN_002e7580(png_struct_2e87e0* png_ptr, unsigned char* buf, unsigned int length);
void __cdecl FUN_002eb4f0(png_struct_2e87e0* png_ptr, png_info_2e87e0* info_ptr, unsigned char* sig_bit);
class Thing_2e9bb0 {
    char pad[0x60];

  public:
    unsigned int flags;
};
extern void FUN_002e69a0(Thing_2e9bb0*, const char*);
extern char* FUN_002e6c00(Thing_2e9bb0*, unsigned int);
extern void FUN_002e7580(Thing_2e9bb0*, char*, unsigned int);
extern int FUN_002e81e0(Thing_2e9bb0*, int);
extern void FUN_002e6c40(Thing_2e9bb0*, char*);
extern void FUN_002eb5e0(Thing_2e9bb0*, void*, void*, int);
struct ZStream_2e9c60 {
    unsigned char *next_in;
    unsigned avail_in;
    unsigned total_in;
    unsigned char *next_out;
    unsigned avail_out;
    unsigned total_out;
    const char *msg;
};
struct PngStruct_2e9c60 {
    char pad0[0x60];
    unsigned mode;
    char pad1[8];
    ZStream_2e9c60 zstream;
    char pad2[0xa4 - 0x6c - sizeof(ZStream_2e9c60)];
    unsigned char *zbuf;
    unsigned zbuf_size;
};
struct PngText {
    int compression;
    char *key;
    char *text;
    unsigned text_length;
};
} // namespace fn_fb0f1f83
extern "C" int __cdecl _sprintf(char *buf, const char *fmt, ...);
namespace fn_fb0f1f83 {
void __cdecl FUN_002e69a0(PngStruct_2e9c60 *png, const char *msg);
void __cdecl FUN_002e69d0(PngStruct_2e9c60 *png, const char *msg);
int __cdecl FUN_002e81e0(PngStruct_2e9c60 *png, unsigned skip);
void *__cdecl FUN_002e6c00(PngStruct_2e9c60 *png, unsigned size);
void __cdecl FUN_002e6c40(PngStruct_2e9c60 *png, void *ptr);
void __cdecl FUN_002e7580(PngStruct_2e9c60 *png, void *buf, unsigned length);
int __cdecl FUN_002e6f70(ZStream_2e9c60 *z, int flush);
void __cdecl FUN_002e6db0(ZStream_2e9c60 *z);
void __cdecl FUN_002eb5e0(PngStruct_2e9c60 *png, void *info, PngText *text, int n);
struct Ctx_2ea2a0 {
    char pad[0x24];
    void(__cdecl* fn)(int, int);
    int x28;
    char p2c[4];
    int m30;
};
extern void __cdecl FUN_002ebed0(int, Ctx_2ea2a0*);
class Obj_2ea2a0 {
  public:
    int type;
    int a4;
    int a8;
    int aC;
    char p10[0x0c];
    int m1c;
    int m20;
    char p24[4];
    int m28;
    int m2c;
    int m30;
    int m34;
    int(__cdecl* m38)(int, int, int);
    int m3c;
};
typedef void*(__cdecl* AllocFn)(void*, int, int);
typedef void(__cdecl* FreeFn)(void*, void*);
struct Manager_2ea320 {
    char pad[0x20];
    AllocFn alloc;
    FreeFn freefn;
    void* heap;
};
extern void* __cdecl FUN_002ea2a0(void*, void*, int);
typedef unsigned int u32_2eaf30;
struct Obj_2eaf30 {
    char pad[0x24];
    void(__cdecl* fn)(u32_2eaf30, u32_2eaf30);
    u32_2eaf30 value;
};
void __cdecl FUN_002ea2a0(Obj_2eaf30*, Obj_2eaf30*, int);
struct Buf {
    char pad[0x28];
    char* data;
    char pad2[4];
    char* a;
    char* b;
};
void FUN_00347aa0(int, int);
struct Obj {
    char pad[8];
    unsigned flags;
    char data[0x56];
};
struct Obj_2eb180 {
    char pad0[8];
    unsigned int flags;
    char pad1[0x74];
    float a[8];
};
struct Obj_2eb1f0 {
    char pad[8];
    uint flags;
    char pad2[0x1c];
    float value;
};
typedef unsigned int uint_2eb220;
struct Thing_2eb220 {
    char pad[8];
    uint_2eb220 flags;
    char pad2[0x70];
    uint_2eb220 value;
};
extern "C" void __cdecl FUN_002e69d0(void *, void *);
struct Obj_2eb2f0 {
    char pad0[8];
    unsigned int flags;
    char pad1[0x64 - 12];
    int a;
    int b;
    unsigned char c;
};
static inline unsigned int Len(const char *p) { const char *q = p; while (*q) q++; return (unsigned int)(q - p); }
static inline void Copy(char *d, const char *p, unsigned int n) {
    // rep movsd for the whole dwords, then rep movsb for the rest (the order matters when the ranges overlap)
    unsigned int w = n >> 2;
    while (w--) { *(unsigned int *)d = *(const unsigned int *)p; d += 4; p += 4; }
    for (unsigned int k = n & 3; k; k--) *d++ = *p++;
}
void *FUN_002e6c00(Pool *pool, hulk_uintptr size);
struct Entry_2eb330 {
    char pad0[8];
    unsigned int flags;
    char padc[0xa0 - 0xc];
    char *name;
    int a4;
    int a8;
    char *text;
    char **list;
    unsigned char flagA;
    unsigned char count;
};
typedef unsigned int u32_2eb480;
typedef unsigned char u8_2eb480;
typedef unsigned short u16_2eb4c0;
typedef unsigned int u32_2eb4c0;
struct Obj_2eb4c0 {
    char pad0[8];
    u32_2eb4c0 flags;
    char padc[4];
    u32_2eb4c0 field10;
    u16_2eb4c0 field14;
};
struct Src {
    int a;
    char b;
};
struct Dst {
    char pad[8];
    int flags;
    char pad2[0x38];
    Src value;
};
struct Entry_2eb5e0 { int id; int value; const char* text; int length; };
struct List_2eb5e0 { char pad[0x30]; int count; int capacity; Entry_2eb5e0* entries; };
extern void* __cdecl FUN_002e6c00(void*, unsigned int);
extern void __cdecl FUN_002e6c40(void*, void*);
typedef unsigned int u32_2eb6f0;
struct Data_2eb6f0 {
    u32_2eb6f0 a;
    u32_2eb6f0 b;
};
struct Obj_2eb6f0 {
    char pad[8];
    u32_2eb6f0 flags;
    char pad2[0x30];
    u32_2eb6f0 x;
    u32_2eb6f0 y;
};
struct Val_2eb720 {
    char bytes[10];
};
struct Obj_2eb720 {
    char p0[8];
    int flags;
    char p1[10];
    short count;
    char p2[0x34];
    int data;
    Val_2eb720 val;
};
struct Manager_2eb780 {
    char pad[0x20];
    AllocFn alloc;
    char pad24[4];
    void* context;
};
typedef unsigned int U32_2ebed0;
struct Obj_2ebed0 {
    char pad[0x24];
    void(__cdecl* fn)(U32_2ebed0, U32_2ebed0);
    U32_2ebed0 arg;
};
typedef unsigned char Byte;
typedef unsigned int uInt;
struct inflate_huft {
    union {
        struct {
            Byte Exop;
            Byte Bits;
        } what;
        uInt pad;
    } word;
    uInt base;
};
struct Huft;
struct ZStream_2ec3e0 {
    char pad0[0x18];
    const char *msg;
    char pad1c[4];
    void *(*zalloc)(void *opaque, unsigned int items, unsigned int size);
    void (*zfree)(void *opaque, void *address);
    void *opaque;
};
int FUN_002ebef0(unsigned int *c, unsigned int *bits, unsigned int n, unsigned int s,
                 unsigned int *base, unsigned int *extra, Huft **t, Huft *hp,
                 unsigned int *hn, unsigned int *v);
struct ZStream_2ec490 {
    char pad0[0x18];
    const char *msg;
    char pad1c[4];
    void *(*zalloc)(void *opaque, unsigned int items, unsigned int size);
    void (*zfree)(void *opaque, void *address);
    void *opaque;
};
struct z_stream_2ec650 {
    unsigned char *next_in;
    unsigned avail_in;
    unsigned total_in;
    unsigned char *next_out;
    unsigned avail_out;
    unsigned total_out;
    char pad[0x30 - 0x18];
    unsigned adler;
};
typedef unsigned (*check_fn)(unsigned, const unsigned char *, unsigned);
struct inflate_blocks_state_2ec650 {
    char pad[0x28];
    unsigned char *window;
    unsigned char *end;
    unsigned char *read;
    unsigned char *write;
    check_fn checkfn;
    unsigned check;
};
struct inflate_huft_2ec780 {
    unsigned char exop;
    unsigned char bits;
    unsigned short pad2;
    unsigned int base;
};
struct inflate_blocks_state_2ec780 {
    char pad00[0x1c];
    unsigned int bitk;
    unsigned int bitb;
    char pad24[4];
    unsigned char *window;
    unsigned char *end;
    unsigned char *read;
    unsigned char *write;
};
struct z_stream_2ec780 {
    unsigned char *next_in;
    unsigned int avail_in;
    unsigned int total_in;
    char pad0c[0x18 - 0x0c];
    const char *msg;
};
extern void* hulk_at_0043117c;
struct Sub2_2eccd0 {
    void Do_002f7a60();
};
struct PA {
    char pad0[0x38];
    float f38;
    char pad1[0x2c];
    Sub2_2eccd0 s;
};
struct PB {
    // (x64t4) the physics world (DAT_00554c14): a word of its collision detector and its solver at the parts'
    // offsets (decls/physics_world.h)
    char pad0[HULK_PW_AT(0x70, 0x80)];
    float f80;
    char pad1[HULK_PW_SOLVER - HULK_PW_AT(0x70, 0x80) - 4];
    Sub2_2eccd0 s;
};


// 0x002e6780 FUN_002e6780 (192 B): equivalent/0x002e6780.cpp
// sym: _FUN_002e6780 @d437700dec06 @wbc46b886721f
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002e6780 @ 0x002e6780
extern "C" unsigned int * __cdecl FUN_002e6780(unsigned int *output, unsigned int color, signed char adjustment)
{
    if (!adjustment) { *output = color; return output; }
    int red = ((color >> 16) & 255) + (int)adjustment;
    int green = ((color >> 8) & 255) + (int)adjustment;
    int blue = (color & 255) + (int)adjustment;
    unsigned int ri = ((red >> 31) & 1) | ((red >> 7) & 2);
    unsigned int gi = ((green >> 31) & 1) | ((green >> 7) & 2);
    unsigned int bi = ((blue >> 31) & 1) | ((blue >> 7) & 2);
    unsigned int r = (((unsigned int*)&DAT_0042fdb4)[ri] & red) | ((unsigned int*)&DAT_0042fdc4)[ri];
    unsigned int g = (((unsigned int*)&DAT_0042fdb4)[gi] & green) | ((unsigned int*)&DAT_0042fdc4)[gi];
    unsigned int b = (((unsigned int*)&DAT_0042fdb4)[bi] & blue) | ((unsigned int*)&DAT_0042fdc4)[bi];
    *output = (((r << 8) | g) << 8) | b | (color & 0xff000000);
    return output;
}


// 0x002e6840 FUN_002e6840 (87 B): equivalent/0x002e6840.cpp
// sym: _FUN_002e6840 @d90e0c1a26af @w6a1dad2bb798
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002e6840 @ 0x002e6840
extern "C" unsigned int * __cdecl FUN_002e6840(unsigned int *result, unsigned int color, char delta)
{
    if (delta != 0) {
        int alpha = (color >> 24) + (int)delta;
        unsigned int slot = ((alpha >> 31) & 1) | ((alpha >> 7) & 2);
        *result = (((((unsigned int*)&DAT_0042fdb4)[slot] & alpha) | ((unsigned int*)&DAT_0042fdc4)[slot]) << 24) | (color & 0xffffff);
    } else {
        *result = color;
    }
    return result;
}


// 0x002e68a0 FUN_002e68a0 (142 B): equivalent/0x002e68a0.cpp
// sym: _FUN_002e68a0 @72cb9e35c2ad @wbcfdc414a2f9
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 12/12)
// FUN_002e68a0 @ 0x002e68a0
// libpng png_format_buffer: "chunk: message" with unprintable chunk-name bytes written as [XX].
// equiv-conv: FUN_002e68a0 eax ecx edx
extern "C" void FUN_002e68a0(char* buffer, void * png_ptr, const char* message) {
    int pos = 0;
    for (int i = 0; i < 4; i++) {
        int c = ((png_struct_2e68a0 *)png_ptr)->chunk_name[i];
        if (c < 0x29 || c > 0x7a || (c > 0x5a && c < 0x61)) {
            buffer[pos] = '[';
            buffer[pos + 1] = DAT_0042fdd4[(c >> 4) & 0xf];
            buffer[pos + 2] = DAT_0042fdd4[c & 0xf];
            buffer[pos + 3] = ']';
            pos += 4;
        } else {
            buffer[pos++] = (char)c;
        }
    }
    if (message == 0) {
        buffer[pos] = 0;
        return;
    }
    buffer[pos] = ':';
    buffer[pos + 1] = ' ';
    // the original copies with an inline rep movs; a plain forward loop keeps clang from emitting a memcpy call
    {
        char *dst = buffer + pos + 2;
        const char *src = message;
        for (int k = 0; k < 16; k++) { *(unsigned int *)dst = *(const unsigned int *)src; dst += 4; src += 4; } // rep movsd x16
    }
    buffer[pos + 2 + 63] = 0;
}


// 0x002e6930 FUN_002e6930 (32 B): equivalent/0x002e6930.cpp
// sym: _FUN_002e6930 @78ed7fa3a22f @wd6d63dd283e4
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002e6930 @ 0x002e6930
extern "C" void __cdecl FUN_002e6930(void *jumpBuffer)
{
    _fwprintf(((FILE_TYPE*)&DAT_004d9a30), "libpng error: %s\n");
    _longjmp(jumpBuffer, 1);
}


// 0x002e6950 FUN_002e6950 (20 B): equivalent/0x002e6950.cpp
// sym: ?FUN_002e6950@fn_fb0f1f83@@YAXPBD@Z @216996c891dd @w397358ecc78a
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002e6950 @ 0x002e6950
// equiv-conv: FUN_002e6950 eax
void FUN_002e6950(const char *message)
{
    fprintf((void*)(((File*)&DAT_004d9a30)), "libpng warning: %s\n");
}


// 0x002e6970 FUN_002e6970 (26 B): matches/0x002e6970.cpp
// sym: _FUN_002e6970
extern "C" void FUN_002e6970(S_2e6970* p, U32_2e6970 x, U32_2e6970 y, U32_2e6970 z) {
    p->c = x;
    p->a = y;
    p->b = z;
}

} // namespace fn_fb0f1f83

// 0x002e69a0 FUN_002e69a0 (38 B): equivalent/0x002e69a0.cpp [wrapped: code differs from its standalone build]
// sym: ?FUN_002e69a0@fn_002e69a0@@YAXPAUItem@1@PAX@Z @36c98b6a27e9 @wd4a4e7394527
namespace fn_002e69a0 {
// STATUS: equivalent (tools/equiv.py level 3: 18799 inputs, branch coverage 2/2)
// FUN_002e69a0 @ 0x002e69a0
// FUN_002e69a0 @ 0x002e69a0
struct Item { char pad[0x40]; void (__cdecl *callback)(Item *, void *); };
extern "C++" __declspec(nothrow) void __cdecl FUN_002e6930(void *);
void __cdecl FUN_002e69a0(Item *item, void *context) {
    if (item->callback) item->callback(item, context);
    FUN_002e6930((Item *)item);
}
} // namespace fn_002e69a0

namespace fn_fb0f1f83 {

// 0x002e69d0 FUN_002e69d0 (26 B): matches/0x002e69d0.cpp
// sym: ?FUN_002e69d0@fn_fb0f1f83@@YAPAXPAUObject@1@PAX@Z
void* __cdecl FUN_002e69d0(Object* object, void* argument) {
    if (object->callback)
        return object->callback(object, argument);
    void* volatile* p = &argument;
    *p;
    return FUN_002e6950();
}


// 0x002e69f0 FUN_002e69f0 (42 B): equivalent/0x002e69f0.cpp
// sym: _FUN_002e69f0 @8a51754cf757 @w0b1ba8924a4e
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002e69f0 @ 0x002e69f0
// equiv-conv: FUN_002e68a0 eax ecx edx
extern "C" void __cdecl FUN_002e69f0(void *source, void *other)
{
    char result[80];
    FUN_002e68a0((char *)(void *)result, source, (const char *)(void *)other);
    FUN_002e69a0(source, result);
}


// 0x002e6a20 FUN_002e6a20 (42 B): equivalent/0x002e6a20.cpp
// sym: _FUN_002e6a20 @61f77e5c46bf @w5e32f86abab2
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002e6a20 @ 0x002e6a20
// equiv-conv: FUN_002e68a0 eax ecx edx
extern "C" void __cdecl FUN_002e6a20(void* object, void* value)
{
    Data result;
    FUN_002e68a0((char *)(Data *)(&result), object, (const char *)(void *)value);
    FUN_002e69d0(object, &result);
}


// 0x002e6a50 FUN_002e6a50 (87 B): equivalent/0x002e6a50.cpp
// sym: ?FUN_002e6a50@fn_fb0f1f83@@YAPAXHP6APAXHI@Z@Z @e18a8ceca698 @wfc2f61d02bea
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_002e6a50 @ 0x002e6a50
void* __cdecl FUN_002e6a50(int type, Allocator allocator)
{
    unsigned int size;
    if (type == 2) size = 0xb8;
    else if (type == 1) size = 0x21c;
    else return 0;
    void* result = allocator ? allocator(0, size) : malloc(size);
    if (result) {
        unsigned char* bytes = (unsigned char*)result;
        for (unsigned int i = 0; i < size; ++i) bytes[i] = 0;
    }
    return result;
}


// 0x002e6ab0 FUN_002e6ab0 (58 B): matches/0x002e6ab0.cpp
// sym: ?FUN_002e6ab0@fn_fb0f1f83@@YAXHP6AXPAXH@Z@Z
void __cdecl FUN_002e6ab0(int ptr, Callback_2e6ab0 callback) {
    char local[0x21c];
    if (ptr != 0) {
        if (callback != 0)
            callback(local, ptr);
        else
            FUN_003479bc(ptr);
    }
}


// 0x002e6af0 FUN_002e6af0 (42 B): matches/0x002e6af0.cpp
// sym: ?FUN_002e6af0@fn_fb0f1f83@@YAPAXII@Z
void* FUN_002e6af0(unsigned int context, unsigned int size) {
    void* p = malloc(size);
    if (!p)
        FUN_002e69a0(context, "Out of Memory");
    return p;
}


// 0x002e6b20 FUN_002e6b20 (12 B): matches/0x002e6b20.cpp
// sym: _FUN_002e6b20
extern "C" void FUN_002e6b20(unsigned int unused, unsigned int ptr) {
    FUN_003479bc(ptr);
}


// 0x002e6b30 FUN_002e6b30 (35 B): matches/0x002e6b30.cpp
// sym: _FUN_002e6b30
extern "C" void* __cdecl FUN_002e6b30(void* unused, void* dst, const void* src, unsigned int n) {
    return memcpy(dst, src, n);
}


// 0x002e6b60 FUN_002e6b60 (49 B): matches/0x002e6b60.cpp
// sym: ?FUN_002e6b60@fn_fb0f1f83@@YAPAXHPAXHI@Z
void* __cdecl FUN_002e6b60(int unused, void* dst, int value, unsigned int n) {
    return memset(dst, value, n);
}


// 0x002e6ba0 FUN_002e6ba0 (35 B): matches/0x002e6ba0.cpp
// sym: _FUN_002e6ba0
extern "C" void FUN_002e6ba0(Obj_2e6ba0* self, int a, int b, int c) {
    self->a = a;
    self->b = b;
    self->c = c;
}


// 0x002e6bf0 FUN_002e6bf0 (16 B): matches/0x002e6bf0.cpp
// sym: _FUN_002e6bf0
extern "C" void FUN_002e6bf0(u32_2e6bf0 a) {
    FUN_002e6ab0(a, 0);
}


// 0x002e6c00 FUN_002e6c00 (52 B): matches/0x002e6c00.cpp
// sym: ?target@fn_fb0f1f83@@YAIPAUObj_2e6c00@1@PAX@Z
hulk_uintptr __cdecl target(Obj_2e6c00* a, void* b) {
    if (!a || !b)
        return 0;
    if (a->fn)
        return a->fn(a, b);
    return fallback_002e6af0(a, b);
}

} // namespace fn_fb0f1f83

// 0x002e6c40 FUN_002e6c40 (42 B): matches/0x002e6c40.cpp [wrapped: conflict: FUN_002e6b20]
// sym: ?target@fn_002e6c40@@YAXPAUObj_2e6c40@1@PAX@Z
namespace fn_002e6c40 {
typedef void(__cdecl* Fn_2e6c40)(void*, void*);
struct Obj_2e6c40 {
    char pad[0x214];
    Fn_2e6c40 fn;
};
void __cdecl FUN_002e6b20(void*, void*);
void __cdecl target(Obj_2e6c40* a, void* b) {
    if (a && b) {
        if (a->fn)
            a->fn(a, b);
        else
            FUN_002e6b20(a, b);
    }
}
} // namespace fn_002e6c40

namespace fn_fb0f1f83 {

// 0x002e6c80 FUN_002e6c80 (298 B): equivalent/0x002e6c80.cpp
// sym: _FUN_002e6c80 @873e139ed68c @w418250fc17ec
// STATUS: equivalent (tools/equiv.py level 3: 132 inputs, branch coverage 10/10)
// FUN_002e6c80 @ 0x002e6c80
extern "C" unsigned int __cdecl FUN_002e6c80(unsigned int crc, const unsigned char* data, unsigned int length)
{
    if (!data) return 0;
    crc = ~crc;
    while (length != 0) {
        crc = (crc >> 8) ^ ((unsigned int*)&DAT_0042fe20)[(crc ^ *data) & 255];
        ++data;
        --length;
    }
    return ~crc;
}


// 0x002e6db0 FUN_002e6db0 (66 B): matches/0x002e6db0.cpp
// sym: ?target@fn_fb0f1f83@@YAHPAUObj_2e6db0@1@@Z
int __cdecl target(Obj_2e6db0* p) {
    if (p && p->inner) {
        p->b = 0;
        p->a = 0;
        p->c = 0;
        Inner_2e6db0* q = p->inner;
        q->v0 = q->flag ? 7 : 0;
        helper_002ea2a0(p->inner->arg, p, 0);
        return 0;
    }
    return -2;
}


// 0x002e6e00 FUN_002e6e00 (72 B): matches/0x002e6e00.cpp
// sym: _FUN_002e6e00
extern "C" int __cdecl FUN_002e6e00(void * p) {
    if (((Obj_2e6e00 *)p) && ((Obj_2e6e00 *)p)->field1c && ((Obj_2e6e00 *)p)->callback) {
        int v = *(int*)(((Obj_2e6e00 *)p)->field1c + 0x14);
        if (v)
            FUN_002eaf30((void *)(hulk_uintptr)(int)v, (Obj_2e6e00 *)((Obj_2e6e00 *)p));
        ((Obj_2e6e00 *)p)->callback(((Obj_2e6e00 *)p)->field28, ((Obj_2e6e00 *)p)->field1c);
        ((Obj_2e6e00 *)p)->field1c = 0;
        return 0;
    }
    return -2;
}


// 0x002e6e50 FUN_002e6e50 (250 B): matches/0x002e6e50.cpp
// sym: _FUN_002e6e50
extern "C" int __cdecl FUN_002e6e50(void * s, int bits, const char* version, int size) {
    if (!version || version[0] != '1' || size != 56)
        return -6;
    if (!((Stream *)s))
        return -2;
    ((Stream *)s)->status = 0;
    if (!((Stream *)s)->allocate) {
        ((Stream *)s)->allocate = FUN_002eb120;
        ((Stream *)s)->context = 0;
    }
    if (!((Stream *)s)->release)
        ((Stream *)s)->release = FUN_002eb140;
    ((Stream *)s)->state = (State_2e6e50*)((Stream *)s)->allocate(((Stream *)s)->context, 1, 24);
    if (!((Stream *)s)->state)
        return -4;
    ((Stream *)s)->state->table = 0;
    ((Stream *)s)->state->raw = 0;
    if (bits < 0) {
        bits = -bits;
        ((Stream *)s)->state->raw = 1;
    }
    if (bits < 8 || bits > 15) {
        FUN_002e6e00((Stream *)((Stream *)s));
        return -2;
    }
    ((Stream *)s)->state->bits = bits;
    ((Stream *)s)->state->table = FUN_002ea320(((Stream *)s), ((Stream *)s)->state->raw ? 0 : FUN_002eafc0, 1u << bits);
    if (!((Stream *)s)->state->table) {
        FUN_002e6e00((Stream *)((Stream *)s));
        return -4;
    }
    FUN_002e6db0(((Stream *)s));
    return 0;
}


// 0x002e6f50 FUN_002e6f50 (26 B): matches/0x002e6f50.cpp
// sym: _FUN_002e6f50
extern "C" int FUN_002e6f50(u32_2e6f50 a, u32_2e6f50 b, u32_2e6f50 c) {
    return FUN_002e6e50((void *)(hulk_uintptr)(unsigned int)a, 0xf, (const char *)(hulk_uintptr)(unsigned int)b, (unsigned int)c);
}

} // namespace fn_fb0f1f83

// 0x002e6f70 FUN_002e6f70 (962 B): equivalent/0x002e6f70.cpp [wrapped: macros]
// sym: ?FUN_002e6f70@fn_002e6f70@@YAHPAUz_stream_2e6f70@1@H@Z @20231421467e @w6015261ff0f4
namespace fn_002e6f70 {
// STATUS: equivalent (tools/equiv.py level 3: 3038 inputs, branch coverage 62/64, incomplete)
// FUN_002e6f70 @ 0x002e6f70
// zlib 1.1.x inflate()
struct inflate_blocks_state;

struct inflate_state {
    int mode;
    union {
        unsigned int method;
        struct {
            unsigned long was;
            unsigned long need;
        } check;
        unsigned int marker;
    } sub;
    int nowrap;
    unsigned int wbits;
    inflate_blocks_state *blocks;
};

struct z_stream_2e6f70 {
    unsigned char *next_in;
    unsigned int avail_in;
    unsigned long total_in;
    unsigned char *next_out;
    unsigned int avail_out;
    unsigned long total_out;
    char *msg;
    inflate_state *state;
    void *zalloc;
    void *zfree;
    void *opaque;
    int data_type;
    unsigned long adler;
    unsigned long reserved;
};

enum {
    METHOD = 0, FLAG, DICT4, DICT3, DICT2, DICT1, DICT0, BLOCKS,
    CHECK4, CHECK3, CHECK2, CHECK1, DONE, BAD
};

int FUN_002ea3c0(inflate_blocks_state *s, z_stream_2e6f70 *z, int r);
void FUN_002ea2a0(inflate_blocks_state *s, z_stream_2e6f70 *z, unsigned long *c);

#define NEEDBYTE { if (z->avail_in == 0) return r; r = f; }
#define NEXTBYTE (z->avail_in--, z->total_in++, *z->next_in++)

int FUN_002e6f70(z_stream_2e6f70 *z, int f)
{
    int r;
    unsigned int b;

    if (z == 0 || z->state == 0 || z->next_in == 0) {
        return -2;
    }
    f = (f == 4) ? -5 : 0;
    r = -5;
    for (;;) {
        switch (z->state->mode) {
        case METHOD:
            NEEDBYTE
            if (((z->state->sub.method = NEXTBYTE) & 0xf) != 8) {
                z->state->mode = BAD;
                z->msg = (char *)"unknown compression method";
                z->state->sub.marker = 5;
                break;
            }
            if ((z->state->sub.method >> 4) + 8 > z->state->wbits) {
                z->state->mode = BAD;
                z->msg = (char *)"invalid window size";
                z->state->sub.marker = 5;
                break;
            }
            z->state->mode = FLAG;
        case FLAG:
            NEEDBYTE
            b = NEXTBYTE;
            if (((z->state->sub.method << 8) + b) % 31) {
                z->state->mode = BAD;
                z->msg = (char *)"incorrect header check";
                z->state->sub.marker = 5;
                break;
            }
            if (!(b & 0x20)) {
                z->state->mode = BLOCKS;
                break;
            }
            z->state->mode = DICT4;
        case DICT4:
            NEEDBYTE
            z->state->sub.check.need = (unsigned long)NEXTBYTE << 24;
            z->state->mode = DICT3;
        case DICT3:
            NEEDBYTE
            z->state->sub.check.need += (unsigned long)NEXTBYTE << 16;
            z->state->mode = DICT2;
        case DICT2:
            NEEDBYTE
            z->state->sub.check.need += (unsigned long)NEXTBYTE << 8;
            z->state->mode = DICT1;
        case DICT1:
            NEEDBYTE
            z->state->sub.check.need += (unsigned long)NEXTBYTE;
            z->adler = z->state->sub.check.need;
            z->state->mode = DICT0;
            return 2;
        case DICT0:
            z->state->mode = BAD;
            z->msg = (char *)"need dictionary";
            z->state->sub.marker = 0;
            return -2;
        case BLOCKS:
            r = FUN_002ea3c0(z->state->blocks, z, r);
            if (r == -3) {
                z->state->mode = BAD;
                z->state->sub.marker = 0;
                break;
            }
            if (r == 0) {
                r = f;
            }
            if (r != 1) {
                return r;
            }
            r = f;
            FUN_002ea2a0(z->state->blocks, z, &z->state->sub.check.was);
            if (z->state->nowrap) {
                z->state->mode = DONE;
                break;
            }
            z->state->mode = CHECK4;
        case CHECK4:
            NEEDBYTE
            z->state->sub.check.need = (unsigned long)NEXTBYTE << 24;
            z->state->mode = CHECK3;
        case CHECK3:
            NEEDBYTE
            z->state->sub.check.need += (unsigned long)NEXTBYTE << 16;
            z->state->mode = CHECK2;
        case CHECK2:
            NEEDBYTE
            z->state->sub.check.need += (unsigned long)NEXTBYTE << 8;
            z->state->mode = CHECK1;
        case CHECK1:
            NEEDBYTE
            z->state->sub.check.need += (unsigned long)NEXTBYTE;
            if (z->state->sub.check.was != z->state->sub.check.need) {
                z->state->mode = BAD;
                z->msg = (char *)"incorrect data check";
                z->state->sub.marker = 5;
                break;
            }
            z->state->mode = DONE;
        case DONE:
            return 1;
        case BAD:
            return -3;
        default:
            return -2;
        }
    }
}
} // namespace fn_002e6f70
#undef NEEDBYTE
#undef NEXTBYTE

namespace fn_fb0f1f83 {

// 0x002e7500 FUN_002e7500 (35 B): matches/0x002e7500.cpp
// sym: ?FUN_002e7500@fn_fb0f1f83@@YAIPAE@Z
unsigned int FUN_002e7500(unsigned char* p) {
    unsigned int v = p[0];
    v = (v << 8) + p[1];
    v = (v << 8) + p[2];
    v = (v << 8) + p[3];
    return v;
}


// 0x002e7530 FUN_002e7530 (35 B): matches/0x002e7530.cpp
// sym: _FUN_002e7530
// Same code shape as 0x002e7500 (propagated; names are from that function)
extern "C" unsigned int FUN_002e7530(unsigned char* p) {
    unsigned int v = p[0];
    v = (v << 8) + p[1];
    v = (v << 8) + p[2];
    v = (v << 8) + p[3];
    return v;
}


// 0x002e7560 FUN_002e7560 (19 B): matches/0x002e7560.cpp
// sym: _FUN_002e7560
extern "C" unsigned short __cdecl FUN_002e7560(const unsigned char * data) {
    register unsigned short a = (unsigned short)data[0];
    register unsigned short b = (unsigned short)data[1];
    a <<= 8;
    a += b;
    return a;
}


// 0x002e7580 FUN_002e7580 (38 B): matches/0x002e7580.cpp
// sym: ?target@fn_fb0f1f83@@YAXHHH@Z
void target(hulk_intptr a, hulk_intptr b, int c) {
    FUN_002dd690(a, b, c);
    FUN_002d6cb0(a, b, c);
}


// 0x002e75b0 FUN_002e75b0 (103 B): matches/0x002e75b0.cpp
// sym: _FUN_002e75b0
extern "C" int __cdecl FUN_002e75b0(void * p) {
    int q;
    int b = 1;
    if (((Obj_2e75b0 *)p)->mode & 0x20) {
        if ((((Obj_2e75b0 *)p)->flags & 0x300) == 0x300)
            b = 0;
    } else if (((Obj_2e75b0 *)p)->flags & 0x800)
        b = 0;
    FUN_002dd690(((Obj_2e75b0 *)p), &q, 4);
    if (b) {
        return FUN_002e7500(&q) != ((Obj_2e75b0 *)p)->value;
    }
    return 0;
}

} // namespace fn_fb0f1f83

// 0x002e7620 FUN_002e7620 (93 B): matches/0x002e7620.cpp [wrapped: lost its match in the tree (call sequence differs)]
// sym: ?Check@fn_002e7620@@YAXIPBD@Z
namespace fn_002e7620 {
extern "C++" __declspec(nothrow) void __cdecl FUN_002e69f0(void *, void *);
void Check(unsigned int unused, const char* s) {
    unsigned char c;
    c = (unsigned char)s[0];
    if (c < 0x29 || c > 0x7a || (c > 0x5a && c < 0x61)) {
        FUN_002e69f0((void *)(hulk_uintptr)(unsigned int)unused, (void *)(const char *)"invalid chunk type");
        return;
    }
    c = (unsigned char)s[1];
    if (c < 0x29 || c > 0x7a || (c > 0x5a && c < 0x61)) {
        FUN_002e69f0((void *)(hulk_uintptr)(unsigned int)unused, (void *)(const char *)"invalid chunk type");
        return;
    }
    c = (unsigned char)s[2];
    if (c < 0x29 || c > 0x7a || (c > 0x5a && c < 0x61)) {
        FUN_002e69f0((void *)(hulk_uintptr)(unsigned int)unused, (void *)(const char *)"invalid chunk type");
        return;
    }
    c = (unsigned char)s[3];
    if (c < 0x29 || c > 0x7a || (c > 0x5a && c < 0x61)) {
        FUN_002e69f0((void *)(hulk_uintptr)(unsigned int)unused, (void *)(const char *)"invalid chunk type");
        return;
    }
}
} // namespace fn_002e7620

namespace fn_fb0f1f83 {

// 0x002e7680 FUN_002e7680 (769 B): matches/0x002e7680.cpp
// sym: _FUN_002e7680
// FUN_002e7680 @ 0x002e7680
extern "C" void __cdecl FUN_002e7680(PngStruct_2e7680 *png_ptr, unsigned char *row, int mask)
{
    if (mask == 0xff) {
        unsigned int rowbytes = (png_ptr->pixel_depth * png_ptr->width + 7) >> 3;
        memcpy(row, png_ptr->row_buf + 1, rowbytes);
        return;
    }

    switch (png_ptr->pixel_depth) {
    case 1: {
        unsigned char *sp = png_ptr->row_buf + 1;
        unsigned char *dp = row;
        int s_inc, s_start, s_end;
        int m = 0x80;
        int shift;
        unsigned int row_width = png_ptr->width;
        if (png_ptr->transformations & 0x10000) {
            s_start = 0;
            s_end = 7;
            s_inc = 1;
        } else {
            s_start = 7;
            s_end = 0;
            s_inc = -1;
        }
        shift = s_start;
        for (unsigned int i = 0; i < row_width; i++) {
            if (m & mask) {
                int value = (*sp >> shift) & 0x01;
                *dp &= (unsigned char)((0x7f7f >> (7 - shift)) & 0xff);
                *dp |= (unsigned char)(value << shift);
            }
            if (shift == s_end) {
                shift = s_start;
                sp++;
                dp++;
            } else {
                shift += s_inc;
            }
            if (m == 1)
                m = 0x80;
            else
                m >>= 1;
        }
        break;
    }
    case 2: {
        unsigned char *sp = png_ptr->row_buf + 1;
        unsigned char *dp = row;
        int s_start, s_end, s_inc;
        int m = 0x80;
        int shift;
        unsigned int row_width = png_ptr->width;
        if (png_ptr->transformations & 0x10000) {
            s_start = 0;
            s_end = 6;
            s_inc = 2;
        } else {
            s_start = 6;
            s_end = 0;
            s_inc = -2;
        }
        shift = s_start;
        for (unsigned int i = 0; i < row_width; i++) {
            if (m & mask) {
                int value = (*sp >> shift) & 0x3;
                *dp &= (unsigned char)((0x3f3f >> (6 - shift)) & 0xff);
                *dp |= (unsigned char)(value << shift);
            }
            if (shift == s_end) {
                shift = s_start;
                sp++;
                dp++;
            } else {
                shift += s_inc;
            }
            if (m == 1)
                m = 0x80;
            else
                m >>= 1;
        }
        break;
    }
    case 4: {
        unsigned char *sp = png_ptr->row_buf + 1;
        unsigned char *dp = row;
        int s_start, s_end, s_inc;
        int m = 0x80;
        int shift;
        unsigned int row_width = png_ptr->width;
        if (png_ptr->transformations & 0x10000) {
            s_start = 0;
            s_end = 4;
            s_inc = 4;
        } else {
            s_start = 4;
            s_end = 0;
            s_inc = -4;
        }
        shift = s_start;
        for (unsigned int i = 0; i < row_width; i++) {
            if (m & mask) {
                int value = (*sp >> shift) & 0xf;
                *dp &= (unsigned char)((0xf0f >> (4 - shift)) & 0xff);
                *dp |= (unsigned char)(value << shift);
            }
            if (shift == s_end) {
                shift = s_start;
                sp++;
                dp++;
            } else {
                shift += s_inc;
            }
            if (m == 1)
                m = 0x80;
            else
                m >>= 1;
        }
        break;
    }
    default: {
        unsigned char *sp = png_ptr->row_buf + 1;
        unsigned char *dp = row;
        unsigned int pixel_bytes = (png_ptr->pixel_depth >> 3);
        unsigned int row_width = png_ptr->width;
        unsigned char m = 0x80;
        for (unsigned int i = 0; i < row_width; i++) {
            if (m & mask)
                memcpy(dp, sp, pixel_bytes);
            sp += pixel_bytes;
            dp += pixel_bytes;
            if (m == 1)
                m = 0x80;
            else
                m >>= 1;
        }
        break;
    }
    }
}


// 0x002e7990 FUN_002e7990 (1058 B): equivalent/0x002e7990.cpp
// sym: _FUN_002e7990 @6afa953877b1 @w692612a53d39
// STATUS: equivalent (tools/equiv.py level 3: 122 inputs, branch coverage 57/60, incomplete)
// FUN_002e7990 @ 0x002e7990
// Stretches a row-major pixel run in place, replicating every pixel DAT_004d10d8[sel] times (from the end, so
// the source is never overwritten before it is read), then updates the image width and pitch.
extern "C" void FUN_002e7990(Image *img, unsigned char *pixels, int sel, unsigned int flags)
{
    if (pixels == 0 || img == 0)
        return;

    int factor = DAT_004d10d8[sel];
    unsigned int w = img->width;
    unsigned int newW = w * factor;
    unsigned int bpp = img->bitsPerPixel;
    unsigned int i;

    if (bpp == 1 || bpp == 2 || bpp == 4) {
        unsigned int perByte = 8 / bpp;
        unsigned int maxShift = 8 - bpp;
        unsigned int valMask = (1 << bpp) - 1;
        unsigned char *src = pixels + (w - 1) / perByte;
        unsigned char *dst = pixels + (newW - 1) / perByte;
        int srcShift, dstShift, reset, limit, step;
        if (flags & 0x10000) {
            srcShift = ((w - 1) % perByte) * bpp;
            dstShift = ((newW - 1) % perByte) * bpp;
            reset = maxShift;
            limit = 0;
            step = -(int)bpp;
        } else {
            srcShift = maxShift - ((w - 1) % perByte) * bpp;
            dstShift = maxShift - ((newW - 1) % perByte) * bpp;
            reset = 0;
            limit = maxShift;
            step = bpp;
        }
        if (w != 0) {
            i = 0;
            do {
                unsigned char v = (unsigned char)((*src >> srcShift) & valMask);
                if (factor > 0) {
                    int n = factor;
                    do {
                        *dst = (unsigned char)((*dst & ~(valMask << dstShift)) | (v << dstShift));
                        if (dstShift == limit) {
                            dstShift = reset;
                            dst--;
                        } else {
                            dstShift += step;
                        }
                    } while (--n != 0);
                }
                if (srcShift == limit) {
                    srcShift = reset;
                    src--;
                } else {
                    srcShift += step;
                }
                i++;
            } while (i < img->width);
        }
    } else {
        unsigned int bytes = bpp >> 3;
        unsigned char *src = pixels + (w - 1) * bytes;
        unsigned char *dst = pixels + (newW - 1) * bytes;
        unsigned char tmp[8];
        if (w != 0) {
            i = 0;
            do {
                memcpy(tmp, src, bytes);
                if (factor > 0) {
                    int n = factor;
                    do {
                        memcpy(dst, tmp, bytes);
                        dst -= bytes;
                    } while (--n != 0);
                }
                src -= bytes;
                i++;
            } while (i < img->width);
        }
    }
    img->width = newW;
    img->pitch = (img->bitsPerPixel * newW + 7) >> 3;
}

} // namespace fn_fb0f1f83

// 0x002e7dc0 FUN_002e7dc0 (464 B): equivalent/0x002e7dc0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: _FUN_002e7dc0 @c98fc32e420d @wb0f77dc24f6b
namespace fn_002e7dc0 {
// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 43/43)
// FUN_002e7dc0 @ 0x002e7dc0
struct png_struct;

struct png_row_info_2e7dc0 {
    unsigned int width;
    unsigned int rowbytes;
    unsigned char color_type;
    unsigned char bit_depth;
    unsigned char channels;
    unsigned char pixel_depth;
};

void FUN_002e69d0(png_struct *png_ptr, const char *message);

static int abs_int(int v)
{
    return v < 0 ? -v : v;
}

extern "C" void FUN_002e7dc0(png_struct *png_ptr, png_row_info_2e7dc0 *row_info, unsigned char *row,
                  unsigned char *prev_row, int filter)
{
    unsigned int i;
    unsigned int bpp;
    unsigned int rowbytes;
    unsigned char *rp;
    unsigned char *lp;
    unsigned char *pp;
    unsigned char *cp;

    switch (filter) {
    case 0:
        break;
    case 1:
        bpp = (row_info->pixel_depth + 7) >> 3;
        rowbytes = row_info->rowbytes;
        rp = row + bpp;
        lp = row;
        for (i = bpp; i < rowbytes; i++) {
            *rp = (unsigned char)(*rp + *lp);
            rp++;
            lp++;
        }
        break;
    case 2:
        rowbytes = row_info->rowbytes;
        rp = row;
        pp = prev_row;
        for (i = 0; i < rowbytes; i++) {
            *rp = (unsigned char)(*rp + *pp);
            rp++;
            pp++;
        }
        break;
    case 3:
        bpp = (row_info->pixel_depth + 7) >> 3;
        rowbytes = row_info->rowbytes;
        pp = prev_row;
        rp = row;
        lp = row;
        for (i = 0; i < bpp; i++) {
            *rp = (unsigned char)(*rp + (*pp / 2));
            pp++;
            rp++;
        }
        for (i = 0; i < rowbytes - bpp; i++) {
            *rp = (unsigned char)(*rp + ((*pp + *lp) / 2));
            pp++;
            lp++;
            rp++;
        }
        break;
    case 4:
        bpp = (row_info->pixel_depth + 7) >> 3;
        rowbytes = row_info->rowbytes;
        pp = prev_row;
        cp = prev_row;
        lp = row;
        rp = row;
        for (i = 0; i < bpp; i++) {
            *rp = (unsigned char)(*rp + *pp);
            rp++;
            pp++;
        }
        for (i = 0; i < rowbytes - bpp; i++) {
            int a = *lp++;
            int c = *cp++;
            int b = *pp++;
            int p = b - c;
            int pc = a - c;
            int pa = abs_int(p);
            int pb = abs_int(pc);
            pc = abs_int(p + pc);
            if (pa <= pb && pa <= pc)
                p = a;
            else if (pb <= pc)
                p = b;
            else
                p = c;
            *rp = (unsigned char)(*rp + p);
            rp++;
        }
        break;
    default:
        FUN_002e69d0(png_ptr, "Ignoring bad adaptive filter type");
        *row = 0;
        break;
    }
}
} // namespace fn_002e7dc0

namespace fn_fb0f1f83 {

// 0x002e7fb0 FUN_002e7fb0 (553 B): equivalent/0x002e7fb0.cpp
// sym: _FUN_002e7fb0 @991daca4fec6 @w784a02d0f6ae
// STATUS: equivalent (tools/equiv.py level 3: 124 inputs, branch coverage 49/50, incomplete)
// FUN_002e7fb0 @ 0x002e7fb0
  // png_pass_start
  // png_pass_inc
  // png_pass_ystart
  // png_pass_yinc
// libpng png_read_start_row
extern "C" void __cdecl FUN_002e7fb0(png_struct_2e7fb0 *png_ptr)
{
    int max_pixel_depth;
    unsigned int row_bytes;

    png_ptr->avail_in = 0;
    FUN_002dc3e0(png_ptr);

    if (png_ptr->interlaced) {
        if (!(png_ptr->transformations & 2))
            png_ptr->num_rows = (png_ptr->height - ((const unsigned int*)&DAT_004d10f4)[0] + ((const unsigned int*)&DAT_004d1110)[0] - 1) / ((const unsigned int*)&DAT_004d1110)[0];
        else
            png_ptr->num_rows = png_ptr->height;
        png_ptr->iwidth = (png_ptr->width - ((const unsigned int*)&DAT_004d10bc)[png_ptr->pass] + ((const unsigned int*)&DAT_004d10d8)[png_ptr->pass] - 1)
                          / ((const unsigned int*)&DAT_004d10d8)[png_ptr->pass];
        row_bytes = (png_ptr->pixel_depth * png_ptr->iwidth + 7) >> 3;
    } else {
        png_ptr->num_rows = png_ptr->height;
        png_ptr->iwidth = png_ptr->width;
        row_bytes = png_ptr->rowbytes;
    }
    png_ptr->irowbytes = row_bytes + 1;

    max_pixel_depth = png_ptr->pixel_depth;
    unsigned int transformations = png_ptr->transformations;

    if ((transformations & 4) && png_ptr->bit_depth < 8)
        max_pixel_depth = 8;

    unsigned int expand = transformations & 0x1000;
    if (expand) {
        if (png_ptr->color_type == 3) {
            max_pixel_depth = (png_ptr->num_trans != 0) ? 32 : 24;
        } else if (png_ptr->color_type == 0) {
            if (max_pixel_depth < 8)
                max_pixel_depth = 8;
            if (png_ptr->num_trans != 0)
                max_pixel_depth *= 2;
        } else if (png_ptr->color_type == 2) {
            if (png_ptr->num_trans != 0)
                max_pixel_depth = (max_pixel_depth * 4) / 3;
        }
    }

    unsigned int filler = transformations & 0x8000;
    if (filler) {
        if (png_ptr->color_type == 3)
            max_pixel_depth = 32;
        else if (png_ptr->color_type == 0)
            max_pixel_depth = (max_pixel_depth > 8) ? 32 : 16;
        else if (png_ptr->color_type == 2)
            max_pixel_depth = (max_pixel_depth > 32) ? 64 : 32;
    }

    if (transformations & 0x4000) {
        if ((png_ptr->num_trans != 0 && expand) || filler || png_ptr->color_type == 4)
            max_pixel_depth = (max_pixel_depth > 16) ? 64 : 32;
        else
            max_pixel_depth = (max_pixel_depth > 8) ? 48 : 24;
    }

    unsigned int w = (png_ptr->width + 7) & ~7u;
    unsigned int bytes = (w * max_pixel_depth + 7) >> 3;
    bytes = bytes + (((max_pixel_depth + 7) >> 3) + 1);

    png_ptr->big_row_buf = FUN_002e6c00(png_ptr, bytes);
    png_ptr->row_buf = FUN_002e6c00(png_ptr, png_ptr->rowbytes + 1);
    FUN_002e6b60(png_ptr, png_ptr->row_buf, 0, png_ptr->rowbytes + 1);
    png_ptr->flags |= 0x40;
}

} // namespace fn_fb0f1f83

// 0x002e81e0 FUN_002e81e0 (177 B): equivalent/0x002e81e0.cpp [wrapped: code differs from its standalone build]
// sym: ?FUN_002e81e0@fn_002e81e0@@YAHPAUContext@1@I@Z @6c67b4a36930 @w56bfc8840dbf
namespace fn_002e81e0 {
// STATUS: equivalent (tools/equiv.py level 3: 134 inputs, branch coverage 16/16)
// FUN_002e81e0 @ 0x002e81e0
struct Context {
 char pad0[0x64];
 unsigned int flags;
 char pad1[0x3c];
 void* buffer;
 unsigned int chunkSize;
 char pad2[0x68];
 unsigned char mode;
};
extern void __cdecl FUN_002e7580(Context*, void*, unsigned int);
extern "C++" __declspec(nothrow) int __cdecl FUN_002e75b0(void *);
extern "C++" __declspec(nothrow) void __cdecl FUN_002e6a20(void *, void *);
extern "C++" __declspec(nothrow) void __cdecl FUN_002e69f0(void *, void *);
int __cdecl FUN_002e81e0(Context* context, unsigned int count) {
 unsigned int chunk = context->chunkSize;
 while (count > chunk) {
  FUN_002e7580(context, context->buffer, context->chunkSize);
  count -= chunk;
 }
 if (count) FUN_002e7580(context, context->buffer, count);
 if (!FUN_002e75b0((Context *)context)) return 0;
 if ((context->mode & 0x20) ? !(context->flags & 0x200) : (context->flags & 0x400) != 0)
  FUN_002e6a20((Context *)context, (void *)(const char *)"CRC error");
 else
  FUN_002e69f0((Context *)context, (void *)(const char *)"CRC error");
 return 1;
}
} // namespace fn_002e81e0


// 0x002e82a0 FUN_002e82a0 (545 B): equivalent/0x002e82a0.cpp [wrapped: code differs from its standalone build]
// sym: _FUN_002e82a0 @4f7c984d92cd @w41f5a0961b7a
namespace fn_002e82a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3071 inputs, branch coverage 50/55, incomplete)
// FUN_002e82a0 @ 0x002e82a0
struct png_info;

struct png_struct_2e82a0 {
    char pad0[0x60];
    unsigned int mode;
    char pad64[0xc0 - 0x64];
    unsigned int width;                 // 0xc0
    unsigned int height;                // 0xc4
    char padc8[0xd0 - 0xc8];
    unsigned int rowbytes;              // 0xd0
    char padd4[0x11b - 0xd4];
    unsigned char interlaced;           // 0x11b
    char pad11c[0x11e - 0x11c];
    unsigned char color_type;           // 0x11e
    unsigned char bit_depth;            // 0x11f
    char pad120;
    unsigned char pixel_depth;          // 0x121
    unsigned char channels;             // 0x122
};

void FUN_002e69a0(png_struct_2e82a0 *png_ptr, const char *msg);
void FUN_002e7580(png_struct_2e82a0 *png_ptr, unsigned char *buf, unsigned int length);
void FUN_002e81e0(png_struct_2e82a0 *png_ptr, unsigned int skip);
unsigned int FUN_002e7500(unsigned char *buf);
void FUN_002eb240(png_struct_2e82a0 *png_ptr, png_info *info_ptr, unsigned int width, unsigned int height,
                  int bit_depth, int color_type, int interlace, int compression, int filter);

// libpng png_handle_IHDR
extern "C" void FUN_002e82a0(png_struct_2e82a0 *png_ptr, png_info *info_ptr, unsigned int length)
{
    unsigned char buf[13];

    if (png_ptr->mode != 0)
        FUN_002e69a0(png_ptr, "Out of place IHDR");
    if (length != 13)
        FUN_002e69a0(png_ptr, "Invalid IHDR chunk");

    png_ptr->mode |= 1;
    FUN_002e7580(png_ptr, buf, 13);
    FUN_002e81e0(png_ptr, 0);

    unsigned int width = FUN_002e7500(buf);
    unsigned int height = FUN_002e7500(buf + 4);
    int bit_depth = buf[8];
    int color_type = buf[9];
    int compression = buf[10];
    int filter = buf[11];
    int interlace = buf[12];

    if (width == 0 || width > 0x7fffffff || height == 0 || height > 0x7fffffff)
        FUN_002e69a0(png_ptr, "Invalid image size in IHDR");

    if (bit_depth != 1 && bit_depth != 2 && bit_depth != 4 && bit_depth != 8 && bit_depth != 16)
        FUN_002e69a0(png_ptr, "Invalid bit depth in IHDR");

    if (color_type == 1 || color_type == 5 || color_type > 6)
        FUN_002e69a0(png_ptr, "Invalid color type in IHDR");

    if (color_type != 3 && (color_type == 2 || color_type == 4 || color_type == 6) && bit_depth < 8)
        FUN_002e69a0(png_ptr, "Invalid color type/bit depth combination in IHDR");

    if (interlace >= 2)
        FUN_002e69a0(png_ptr, "Unknown interlace method in IHDR");
    if (compression != 0)
        FUN_002e69a0(png_ptr, "Unknown compression method in IHDR");
    if (filter != 0)
        FUN_002e69a0(png_ptr, "Unknown filter method in IHDR");

    png_ptr->width = width;
    png_ptr->height = height;
    png_ptr->bit_depth = (unsigned char)bit_depth;
    png_ptr->interlaced = (unsigned char)interlace;
    png_ptr->color_type = (unsigned char)color_type;

    switch (color_type) {
    case 0: png_ptr->channels = 1; break;
    case 2: png_ptr->channels = 3; break;
    case 3: png_ptr->channels = 1; break;
    case 4: png_ptr->channels = 2; break;
    case 6: png_ptr->channels = 4; break;
    default: break;
    }
    png_ptr->pixel_depth = (unsigned char)(png_ptr->channels * bit_depth);
    png_ptr->rowbytes = (png_ptr->pixel_depth * width + 7) >> 3;

    FUN_002eb240(png_ptr, info_ptr, width, height, bit_depth, color_type, interlace, compression, filter);
}
} // namespace fn_002e82a0

namespace fn_fb0f1f83 {

// 0x002e84e0 FUN_002e84e0 (351 B): equivalent/0x002e84e0.cpp
// sym: ?FUN_002e84e0@fn_fb0f1f83@@YAXPAUpng_struct_2e84e0@1@PAUpng_info_2e84e0@1@I@Z @6cf509bc611f @w21043057eac9
// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 21/22, incomplete)
// FUN_002e84e0 @ 0x002e84e0
// libpng png_handle_PLTE
void FUN_002e84e0(png_struct_2e84e0 *png_ptr, png_info_2e84e0 *info_ptr, unsigned int length)
{
    png_color_2e84e0 *palette;
    int num, i;
    unsigned char buf[3];

    if (!(png_ptr->mode & 1)) {
        FUN_002e69a0(png_ptr, "Missing IHDR before PLTE");
    } else if (png_ptr->mode & 4) {
        FUN_002e69d0(png_ptr, "Invalid PLTE after IDAT");
        FUN_002e81e0(png_ptr, length);
        return;
    } else if (png_ptr->mode & 2) {
        FUN_002e69a0(png_ptr, "Duplicate PLTE chunk");
    }

    png_ptr->mode |= 2;

    if (length % 3) {
        if (png_ptr->color_type != 3) {
            FUN_002e69d0(png_ptr, "Invalid palette chunk");
            FUN_002e81e0(png_ptr, length);
            return;
        }
        FUN_002e69a0(png_ptr, "Invalid palette chunk");
    }

    num = (int)length / 3;
    palette = (png_color_2e84e0 *)FUN_002d6c20(png_ptr, num, 3);
    png_ptr->flags |= 0x1000;

    for (i = 0; i < num; i++) {
        FUN_002e7580(png_ptr, buf, 3);
        palette[i].red = buf[0];
        palette[i].green = buf[1];
        palette[i].blue = buf[2];
    }

    FUN_002e81e0(png_ptr, 0);
    png_ptr->num_palette = (unsigned short)num;
    png_ptr->palette = palette;
    FUN_002eb4c0(png_ptr, info_ptr, palette, num);

    if (png_ptr->color_type == 3 && info_ptr && (info_ptr->valid & 0x10)
        && png_ptr->num_trans > png_ptr->num_palette) {
        FUN_002e69d0(png_ptr, "Truncating incorrect tRNS chunk length");
        png_ptr->num_trans = png_ptr->num_palette;
    }
}


// 0x002e8640 FUN_002e8640 (83 B): matches/0x002e8640.cpp
// sym: _FUN_002e8640
extern "C" void FUN_002e8640(Image* self, hulk_intptr p2, int p3) {
    if (((self->flags & 1) == 0 || (self->flags & 4) == 0) && (Missing_002e69a0(self, "No image in file"), p2 == 0))
        return;
    self->flags |= 0x18;
    if (p3 != 0)
        BadLength_002e69d0(self, "Incorrect IEND chunk length");
    Finish_002e81e0(self, p3);
}

} // namespace fn_fb0f1f83

// 0x002e86a0 FUN_002e86a0 (312 B): matches/0x002e86a0.cpp [wrapped: lost its match in the tree (a call became inline code (callee now defined in the same TU))]
// sym: _FUN_002e86a0
namespace fn_002e86a0 {
// FUN_002e86a0 @ 0x002e86a0

struct png_struct_2e86a0 {
    char pad[0x60];
    unsigned int mode;
    char pad2[0x154 - 0x64];
    float gamma;
};

struct png_info_2e86a0 {
    char pad[8];
    unsigned int valid;
};


void FUN_002e69a0(png_struct_2e86a0* png, const char* msg);
void FUN_002e69d0(png_struct_2e86a0* png, const char* msg);
int FUN_002e81e0(png_struct_2e86a0* png, unsigned int length);
void FUN_002e7580(png_struct_2e86a0* png, unsigned char* buf, unsigned int length);
unsigned int FUN_002e7500(unsigned char* buf);
void FUN_002eb1f0(png_struct_2e86a0* png, png_info_2e86a0* info, double gamma);
int FUN_00347792(void* stream, const char* fmt, ...);

extern "C" void FUN_002e86a0(png_struct_2e86a0* png, png_info_2e86a0* info, unsigned int length)
{
    unsigned char buf[4];

    if (!(png->mode & 1)) {
        FUN_002e69a0(png, "Missing IHDR before gAMA");
    } else if (png->mode & 4) {
        FUN_002e69d0(png, "Invalid gAMA after IDAT");
        FUN_002e81e0(png, length);
        return;
    } else if (png->mode & 2) {
        FUN_002e69d0(png, "Out of place gAMA chunk");
    } else if (info != 0 && (info->valid & 1) && !(info->valid & 0x800)) {
        FUN_002e69d0(png, "Duplicate gAMA chunk");
        FUN_002e81e0(png, length);
        return;
    }

    if (length != 4) {
        FUN_002e69d0(png, "Incorrect gAMA chunk length");
        FUN_002e81e0(png, length);
        return;
    }

    FUN_002e7580(png, buf, 4);
    if (FUN_002e81e0(png, 0) != 0)
        return;

    unsigned int igamma = FUN_002e7500(buf);
    if (igamma == 0)
        return;

    if ((info->valid & 0x800) && igamma != 45000) {
        FUN_002e69d0(png, "Ignoring incorrect gAMA value when sRGB is also present");
        FUN_00347792(((int*)&DAT_004d9a30), "igamma = %lu\n", igamma);
        return;
    }

    hulk_freg gamma = (hulk_freg)igamma * 1e-5f;
    png->gamma = gamma;
    FUN_002eb1f0(png, info, gamma);
}
} // namespace fn_002e86a0

namespace fn_fb0f1f83 {

// 0x002e87e0 FUN_002e87e0 (340 B): equivalent/0x002e87e0.cpp
// sym: _FUN_002e87e0 @c1af77318318 @w0af9a661354f
// STATUS: equivalent (tools/equiv.py level 3: 96 inputs, branch coverage 18/18)
// FUN_002e87e0 @ 0x002e87e0
extern "C" void __cdecl FUN_002e87e0(png_struct_2e87e0* png_ptr, png_info_2e87e0* info_ptr, unsigned int length)
{
    unsigned char buf[4];
    unsigned int truelen;

    buf[0] = 0;
    buf[1] = 0;
    buf[2] = 0;
    buf[3] = 0;

    if (!(png_ptr->mode & 1)) {
        FUN_002e69a0(png_ptr, "Missing IHDR before sBIT");
    } else if (png_ptr->mode & 4) {
        FUN_002e69d0(png_ptr, "Invalid sBIT after IDAT");
        FUN_002e81e0(png_ptr, length);
        return;
    } else if (png_ptr->mode & 2) {
        FUN_002e69d0(png_ptr, "Out of place sBIT chunk");
    } else if (info_ptr != 0 && (info_ptr->valid & 2)) {
        FUN_002e69d0(png_ptr, "Duplicate sBIT chunk");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    if (png_ptr->color_type == 3)
        truelen = 3;
    else
        truelen = png_ptr->channels;

    if (length != truelen) {
        FUN_002e69d0(png_ptr, "Incorrect sBIT chunk length");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    FUN_002e7580(png_ptr, buf, truelen);
    if (FUN_002e81e0(png_ptr, 0))
        return;

    if (png_ptr->color_type & 2) {
        png_ptr->sig_red = buf[0];
        png_ptr->sig_green = buf[1];
        png_ptr->sig_blue = buf[2];
        png_ptr->sig_alpha = buf[3];
    } else {
        png_ptr->sig_gray = buf[0];
        png_ptr->sig_red = buf[0];
        png_ptr->sig_green = buf[0];
        png_ptr->sig_blue = buf[0];
        png_ptr->sig_alpha = buf[1];
    }
    FUN_002eb4f0(png_ptr, info_ptr, &png_ptr->sig_red);
}

} // namespace fn_fb0f1f83

// 0x002e8940 FUN_002e8940 (1594 B): matches/0x002e8940.cpp [wrapped: lost its match in the tree (a call became inline code (callee now defined in the same TU))]
// sym: _FUN_002e8940
namespace fn_002e8940 {


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl fabs(double);
#endif


struct PngStruct_2e8940 {
    char pad00[0x60];
    unsigned int mode;
};

struct PngInfo_2e8940 {
    char pad00[8];
    unsigned int valid;
};

void __cdecl FUN_002e69a0(PngStruct_2e8940* p, const char* msg);
void __cdecl FUN_002e69d0(PngStruct_2e8940* p, const char* msg);
int __cdecl FUN_002e81e0(PngStruct_2e8940* p, unsigned int length);
void __cdecl FUN_002e7580(PngStruct_2e8940* p, unsigned char* buf, unsigned int n);
unsigned int __cdecl FUN_002e7500(const unsigned char* buf);
void __cdecl FUN_002eb180(PngStruct_2e8940* p, PngInfo_2e8940* info, double wx, double wy, double rx, double ry, double gx,
                          double gy, double bx, double by);

extern "C" void FUN_002e8940(PngStruct_2e8940* png_ptr, PngInfo_2e8940* info_ptr, unsigned int length) {
    unsigned char buf[4];
    float white_x, white_y, red_x, red_y, green_x, green_y, blue_x, blue_y;

    if (!(png_ptr->mode & 1)) {
        FUN_002e69a0(png_ptr, "Missing IHDR before sBIT");
    } else if (png_ptr->mode & 4) {
        FUN_002e69d0(png_ptr, "Invalid cHRM after IDAT");
        FUN_002e81e0(png_ptr, length);
        return;
    } else if (png_ptr->mode & 2) {
        FUN_002e69d0(png_ptr, "Missing PLTE before cHRM");
    } else if (info_ptr != 0 && (info_ptr->valid & 4) && !(info_ptr->valid & 0x800)) {
        FUN_002e69d0(png_ptr, "Duplicate cHRM chunk");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    if (length != 0x20) {
        FUN_002e69d0(png_ptr, "Incorrect cHRM chunk length");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    FUN_002e7580(png_ptr, buf, 4);
    white_x = (float)FUN_002e7500(buf) * 1e-5f;
    FUN_002e7580(png_ptr, buf, 4);
    white_y = (float)FUN_002e7500(buf) * 1e-5f;
    if (white_x < 0 || white_x > 0.8 || white_y < 0 || white_y > 0.8 || white_y + white_x > 1.0) {
        FUN_002e69d0(png_ptr, "Invalid cHRM white point");
        FUN_002e81e0(png_ptr, 0x18);
        return;
    }

    FUN_002e7580(png_ptr, buf, 4);
    red_x = (float)FUN_002e7500(buf) * 1e-5f;
    FUN_002e7580(png_ptr, buf, 4);
    red_y = (float)FUN_002e7500(buf) * 1e-5f;
    if (red_x < 0 || red_x > 0.8 || red_y < 0 || red_y > 0.8 || red_y + red_x > 1.0) {
        FUN_002e69d0(png_ptr, "Invalid cHRM red point");
        FUN_002e81e0(png_ptr, 0x10);
        return;
    }

    FUN_002e7580(png_ptr, buf, 4);
    green_x = (float)FUN_002e7500(buf) * 1e-5f;
    FUN_002e7580(png_ptr, buf, 4);
    green_y = (float)FUN_002e7500(buf) * 1e-5f;
    if (green_x < 0 || green_x > 0.8 || green_y < 0 || green_y > 0.8 || green_y + green_x > 1.0) {
        FUN_002e69d0(png_ptr, "Invalid cHRM green point");
        FUN_002e81e0(png_ptr, 8);
        return;
    }

    FUN_002e7580(png_ptr, buf, 4);
    blue_x = (float)FUN_002e7500(buf) * 1e-5f;
    FUN_002e7580(png_ptr, buf, 4);
    blue_y = (float)FUN_002e7500(buf) * 1e-5f;
    if (blue_x < 0 || blue_x > 0.8f || blue_y < 0 || blue_y > 0.8f || blue_y + blue_x > 1.0f) {
        FUN_002e69d0(png_ptr, "Invalid cHRM blue point");
        FUN_002e81e0(png_ptr, 0);
        return;
    }

    if (FUN_002e81e0(png_ptr, 0))
        return;

    if (info_ptr->valid & 0x800) {
        if (fabs(white_x - 0.3127f) > 0.001 || fabs(white_y - 0.329f) > 0.001 ||
            fabs(red_x - 0.64f) > 0.001 || fabs(red_y - 0.33f) > 0.001 || fabs(green_x - 0.3f) > 0.001 ||
            fabs(green_y - 0.6f) > 0.001 || fabs(blue_x - 0.15f) > 0.001 || fabs(blue_y - 0.06f) > 0.001) {
            FUN_002e69d0(png_ptr, "Ignoring incorrect cHRM value when sRGB is also present");
            fprintf(((char*)&DAT_004d9a30), "wx=%f, wy=%f, rx=%f, ry=%f\n", white_x, white_y, red_x, red_y);
            fprintf(((char*)&DAT_004d9a30), "gx=%f, gy=%f, bx=%f, by=%f\n", green_x, green_y, blue_x, blue_y);
        }
        return;
    }
    FUN_002eb180(png_ptr, info_ptr, white_x, white_y, red_x, red_y, green_x, green_y, blue_x, blue_y);
}
} // namespace fn_002e8940


// 0x002e8f80 FUN_002e8f80 (556 B): equivalent/0x002e8f80.cpp [wrapped: conflict: _fwprintf]
// sym: ?png_handle_sRGB@fn_002e8f80@@YAXPAUpng_struct@1@PAUpng_info@1@I@Z @60318132d671 @wd113aaab3db4
namespace fn_002e8f80 {
// STATUS: equivalent (tools/equiv.py level 3: 3059 inputs, branch coverage 38/38)
// FUN_002e8f80 @ 0x002e8f80


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double fabs(double);
#endif


struct png_struct {
    char pad0[0x60];
    unsigned int mode;
    char pad64[0x154 - 0x64];
    float gamma;
};

struct png_info {
    char pad0[8];
    unsigned int valid;
    char pad0c[0x80 - 0x0c];
    float whiteX, whiteY;
    float redX, redY;
    float greenX, greenY;
    float blueX, blueY;
};


void __cdecl FUN_002e69a0(png_struct *png_ptr, const char *msg);
void __cdecl FUN_002e69d0(png_struct *png_ptr, const char *msg);
int __cdecl FUN_002e81e0(png_struct *png_ptr, unsigned int skip);
void __cdecl FUN_002e7580(png_struct *png_ptr, unsigned char *buf, unsigned int length);
void __cdecl FUN_002eb540(png_struct *png_ptr, png_info *info_ptr, int intent);

// libpng png_handle_sRGB. The first argument's stack slot doubles as the one-byte intent buffer.
void png_handle_sRGB(png_struct *png_ptr_arg, png_info *info_ptr, unsigned int length)
{
    png_struct *png_ptr = png_ptr_arg;
    unsigned char *intentBuf = (unsigned char *)&png_ptr_arg;
    int intent;
    unsigned int mode = png_ptr->mode;

    if (!(mode & 1)) {
        FUN_002e69a0(png_ptr, "Missing IHDR before sRGB");
    } else if (mode & 4) {
        FUN_002e69d0(png_ptr, "Invalid sRGB after IDAT");
        FUN_002e81e0(png_ptr, length);
        return;
    } else if (mode & 2) {
        FUN_002e69d0(png_ptr, "Out of place sRGB chunk");
    } else if (info_ptr != 0 && (info_ptr->valid & 0x800)) {
        FUN_002e69d0(png_ptr, "Duplicate sRGB chunk");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    if (length != 1) {
        FUN_002e69d0(png_ptr, "Incorrect sRGB chunk length");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    FUN_002e7580(png_ptr, intentBuf, 1);
    if (FUN_002e81e0(png_ptr, 0)) {
        return;
    }
    intent = *intentBuf;
    if (intent >= 4) {
        FUN_002e69d0(png_ptr, "Unknown sRGB intent");
        return;
    }

    if (info_ptr->valid & 1) {
        int igamma = (int)(png_ptr->gamma * 100000.0f + 0.5);
        if (igamma != 45000) {
            FUN_002e69d0(png_ptr, "Ignoring incorrect gAMA value when sRGB is also present");
            fprintf(DAT_004d9a30, "gamma=%f\n", (double)png_ptr->gamma);
        }
    }

    if (info_ptr->valid & 4) {
        if (fabs(info_ptr->whiteX - 0.3127f) > 0.001 ||
            fabs(info_ptr->whiteY - 0.329f) > 0.001 ||
            fabs(info_ptr->redX - 0.64f) > 0.001 ||
            fabs(info_ptr->redY - 0.33f) > 0.001 ||
            fabs(info_ptr->greenX - 0.3f) > 0.001 ||
            fabs(info_ptr->greenY - 0.6f) > 0.001 ||
            fabs(info_ptr->blueX - 0.15f) > 0.001 ||
            fabs(info_ptr->blueY - 0.06f) > 0.001) {
            FUN_002e69d0(png_ptr, "Ignoring incorrect cHRM value when sRGB is also present");
        }
    }

    FUN_002eb540(png_ptr, info_ptr, intent);
}
} // namespace fn_002e8f80


// 0x002e91b0 FUN_002e91b0 (509 B): matches/0x002e91b0.cpp [wrapped: lost its match in the tree (a call became inline code (callee now defined in the same TU))]
// sym: ?png_handle_tRNS@fn_002e91b0@@YAXPAUpng_struct_2e91b0@1@PAUpng_info_2e91b0@1@I@Z
namespace fn_002e91b0 {
// FUN_002e91b0 @ 0x002e91b0
struct png_color_16_2e91b0 {
    unsigned char index;
    unsigned char pad1;
    unsigned short red;
    unsigned short green;
    unsigned short blue;
    unsigned short gray;
};

struct png_info_2e91b0 {
    char pad0[8];
    unsigned int valid;
};

struct png_struct_2e91b0 {
    char pad0[0x60];
    unsigned int mode;
    unsigned int flags;
    char pad68[0x110 - 0x68];
    unsigned short num_palette;
    unsigned short num_trans;
    char pad114[0x11e - 0x114];
    unsigned char color_type;
    char pad11f[0x180 - 0x11f];
    unsigned char *trans;
    png_color_16_2e91b0 trans_values;
};

void __cdecl FUN_002e69a0(png_struct_2e91b0 *png_ptr, const char *msg);
void __cdecl FUN_002e69d0(png_struct_2e91b0 *png_ptr, const char *msg);
int __cdecl FUN_002e81e0(png_struct_2e91b0 *png_ptr, unsigned int skip);
unsigned char *__cdecl FUN_002e6c00(png_struct_2e91b0 *png_ptr, unsigned int size);
void __cdecl FUN_002e7580(png_struct_2e91b0 *png_ptr, unsigned char *buf, unsigned int length);
extern "C++" __declspec(nothrow) unsigned short __cdecl FUN_002e7560(const unsigned char *);
void __cdecl FUN_002eb720(png_struct_2e91b0 *png_ptr, png_info_2e91b0 *info_ptr, unsigned char *trans, int num_trans,
                          png_color_16_2e91b0 *trans_values);

// libpng png_handle_tRNS
void png_handle_tRNS(png_struct_2e91b0 *png_ptr, png_info_2e91b0 *info_ptr, unsigned int length)
{
    unsigned char buf[6];

    if (!(png_ptr->mode & 1)) {
        FUN_002e69a0(png_ptr, "Missing IHDR before tRNS");
    } else if (png_ptr->mode & 4) {
        FUN_002e69d0(png_ptr, "Invalid tRNS after IDAT");
        FUN_002e81e0(png_ptr, length);
        return;
    } else if (info_ptr != 0 && (info_ptr->valid & 0x10)) {
        FUN_002e69d0(png_ptr, "Duplicate tRNS chunk");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    if (png_ptr->color_type == 3) {
        if (!(png_ptr->mode & 2)) {
            FUN_002e69d0(png_ptr, "Missing PLTE before tRNS");
        } else if (length > png_ptr->num_palette) {
            FUN_002e69d0(png_ptr, "Incorrect tRNS chunk length");
            FUN_002e81e0(png_ptr, length);
            return;
        }
        if (length == 0) {
            FUN_002e69d0(png_ptr, "Zero length tRNS chunk");
            FUN_002e81e0(png_ptr, length);
            return;
        }
        png_ptr->trans = FUN_002e6c00(png_ptr, length);
        png_ptr->flags |= 0x2000;
        FUN_002e7580(png_ptr, png_ptr->trans, length);
        png_ptr->num_trans = (unsigned short)length;
    } else if (png_ptr->color_type == 2) {
        if (length != 6) {
            FUN_002e69d0(png_ptr, "Incorrect tRNS chunk length");
            FUN_002e81e0(png_ptr, length);
            return;
        }
        FUN_002e7580(png_ptr, buf, length);
        png_ptr->num_trans = 1;
        png_ptr->trans_values.red = FUN_002e7560(buf);
        png_ptr->trans_values.green = FUN_002e7560(buf + 2);
        png_ptr->trans_values.blue = FUN_002e7560(buf + 4);
    } else if (png_ptr->color_type == 0) {
        if (length != 2) {
            FUN_002e69d0(png_ptr, "Incorrect tRNS chunk length");
            FUN_002e81e0(png_ptr, length);
            return;
        }
        FUN_002e7580(png_ptr, buf, 2);
        png_ptr->num_trans = 1;
        png_ptr->trans_values.gray = FUN_002e7560(buf);
    } else {
        FUN_002e69d0(png_ptr, "tRNS chunk not allowed with alpha channel");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    if (FUN_002e81e0(png_ptr, 0))
        return;
    FUN_002eb720(png_ptr, info_ptr, png_ptr->trans, png_ptr->num_trans, &png_ptr->trans_values);
}
} // namespace fn_002e91b0


// 0x002e93b0 FUN_002e93b0 (440 B): matches/0x002e93b0.cpp [wrapped: lost its match in the tree (a call became inline code (callee now defined in the same TU))]
// sym: ?png_handle_bKGD@fn_002e93b0@@YAXPAUpng_struct_2e93b0@1@PAUpng_info_2e93b0@1@I@Z
namespace fn_002e93b0 {
// FUN_002e93b0 @ 0x002e93b0
struct png_color_16_2e93b0 {
    unsigned char index;
    unsigned char pad1;
    unsigned short red;
    unsigned short green;
    unsigned short blue;
    unsigned short gray;
};

struct png_color_2e93b0 {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

struct png_info_2e93b0 {
    char pad0[8];
    unsigned int valid;
};

struct png_struct_2e93b0 {
    char pad0[0x60];
    unsigned int mode;
    char pad64[0x10c - 0x64];
    png_color_2e93b0 *palette;
    char pad110[0x11e - 0x110];
    unsigned char color_type;
    char pad11f[0x130 - 0x11f];
    png_color_16_2e93b0 background;
};

void __cdecl FUN_002e69a0(png_struct_2e93b0 *png_ptr, const char *msg);
void __cdecl FUN_002e69d0(png_struct_2e93b0 *png_ptr, const char *msg);
int __cdecl FUN_002e81e0(png_struct_2e93b0 *png_ptr, unsigned int skip);
void __cdecl FUN_002e7580(png_struct_2e93b0 *png_ptr, unsigned char *buf, unsigned int length);
extern "C++" __declspec(nothrow) unsigned short __cdecl FUN_002e7560(const unsigned char *);
void __cdecl FUN_002eb150(png_struct_2e93b0 *png_ptr, png_info_2e93b0 *info_ptr, png_color_16_2e93b0 *background);

void png_handle_bKGD(png_struct_2e93b0 *png_ptr, png_info_2e93b0 *info_ptr, unsigned int length)
{
    unsigned int truelen;
    unsigned char buf[6];

    if (!(png_ptr->mode & 1)) {
        FUN_002e69a0(png_ptr, "Missing IHDR before bKGD");
    } else if (png_ptr->mode & 4) {
        FUN_002e69d0(png_ptr, "Invalid bKGD after IDAT");
        FUN_002e81e0(png_ptr, length);
        return;
    } else if (png_ptr->color_type == 3 && !(png_ptr->mode & 2)) {
        FUN_002e69d0(png_ptr, "Missing PLTE before bKGD");
        FUN_002e81e0(png_ptr, length);
        return;
    } else if (info_ptr != 0 && (info_ptr->valid & 0x20)) {
        FUN_002e69d0(png_ptr, "Duplicate bKGD chunk");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    if (png_ptr->color_type == 3)
        truelen = 1;
    else if (png_ptr->color_type & 2)
        truelen = 6;
    else
        truelen = 2;

    if (length != truelen) {
        FUN_002e69d0(png_ptr, "Incorrect bKGD chunk length");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    FUN_002e7580(png_ptr, buf, truelen);
    if (FUN_002e81e0(png_ptr, 0))
        return;

    if (png_ptr->color_type == 3) {
        png_ptr->background.index = buf[0];
        png_ptr->background.red = png_ptr->palette[buf[0]].red;
        png_ptr->background.green = png_ptr->palette[buf[0]].green;
        png_ptr->background.blue = png_ptr->palette[buf[0]].blue;
    } else if (!(png_ptr->color_type & 2)) {
        png_ptr->background.red = png_ptr->background.green = png_ptr->background.blue = png_ptr->background.gray = FUN_002e7560(buf);
    } else {
        png_ptr->background.red = FUN_002e7560(buf);
        png_ptr->background.green = FUN_002e7560(buf + 2);
        png_ptr->background.blue = FUN_002e7560(buf + 4);
    }
    FUN_002eb150(png_ptr, info_ptr, &png_ptr->background);
}
} // namespace fn_002e93b0


// 0x002e9570 FUN_002e9570 (302 B): matches/0x002e9570.cpp [wrapped: lost its match in the tree (call sequence differs)]
// sym: _FUN_002e9570
namespace fn_002e9570 {
// FUN_002e9570 @ 0x002e9570
struct png_info_2e9570 {
    char pad0[8];
    unsigned int valid;
};

struct png_struct_2e9570 {
    char pad0[0x60];
    unsigned int mode;
    unsigned int flags;
    char pad1[0x110 - 0x68];
    unsigned short num_palette;
    char pad2[0x1ec - 0x112];
    unsigned short *hist;
};

void FUN_002e69a0(png_struct_2e9570 *png, const char *msg);
void FUN_002e69d0(png_struct_2e9570 *png, const char *msg);
int FUN_002e81e0(png_struct_2e9570 *png, unsigned int skip);
unsigned short *FUN_002e6c00(png_struct_2e9570 *png, unsigned int size);
void FUN_002e7580(png_struct_2e9570 *png, unsigned char *buf, unsigned int length);
extern "C++" __declspec(nothrow) unsigned short __cdecl FUN_002e7560(const unsigned char *);
void FUN_002eb220(png_struct_2e9570 *png, png_info_2e9570 *info, unsigned short *hist);

extern "C" void FUN_002e9570(png_struct_2e9570 *png, png_info_2e9570 *info, int length)
{
    unsigned char buf[2];
    int num;
    int i;

    if (!(png->mode & 1)) {
        FUN_002e69a0(png, "Missing IHDR before hIST");
    } else if (png->mode & 4) {
        FUN_002e69d0(png, "Invalid hIST after IDAT");
        FUN_002e81e0(png, length);
        return;
    } else if (!(png->mode & 2)) {
        FUN_002e69d0(png, "Missing PLTE before hIST");
        FUN_002e81e0(png, length);
        return;
    } else if (info != 0 && (info->valid & 0x40)) {
        FUN_002e69d0(png, "Duplicate hIST chunk");
        FUN_002e81e0(png, length);
        return;
    }

    if (length != png->num_palette * 2) {
        FUN_002e69d0(png, "Incorrect hIST chunk length");
        FUN_002e81e0(png, length);
        return;
    }

    num = length / 2;
    unsigned short *hist = FUN_002e6c00(png, num * 2);
    png->hist = hist;
    png->flags |= 0x4000;
    for (i = 0; i < num; i++) {
        FUN_002e7580(png, buf, 2);
        png->hist[i] = FUN_002e7560(buf);
    }
    if (FUN_002e81e0(png, 0) == 0)
        FUN_002eb220(png, info, png->hist);
}
} // namespace fn_002e9570


// 0x002e96a0 FUN_002e96a0 (228 B): equivalent/0x002e96a0.cpp [wrapped: code differs from its standalone build]
// sym: _FUN_002e96a0 @98ba42890514 @w39c0b11e476d
namespace fn_002e96a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 12/12)
// FUN_002e96a0 @ 0x002e96a0
struct Png_2e96a0 { char pad[0x60]; unsigned flags; };
struct Info_2e96a0 { char pad[8]; signed char flags; };
struct PhysData { unsigned char x[4]; unsigned char y[4]; unsigned char unit; };
extern "C++" __declspec(nothrow) void __cdecl FUN_002e69a0(Png_2e96a0*, const char*);
extern "C++" __declspec(nothrow) void __cdecl FUN_002e69d0(Png_2e96a0*, const char*);
extern "C++" __declspec(nothrow) int __cdecl FUN_002e81e0(Png_2e96a0*, unsigned);
extern "C++" __declspec(nothrow) void __cdecl FUN_002e7580(Png_2e96a0*, void*, unsigned);
extern "C++" __declspec(nothrow) unsigned __cdecl FUN_002e7500(unsigned char*);
extern "C" int __cdecl FUN_002eb480(Png_2e96a0*, Info_2e96a0*, unsigned, unsigned, unsigned);
extern "C" int __cdecl FUN_002e96a0(Png_2e96a0* png, Info_2e96a0* info, unsigned length) {
    unsigned flags = png->flags;
    if (!(flags & 1)) {
        FUN_002e69a0(png, "Missing IHDR before pHYS");
    } else if (flags & 4) {
        FUN_002e69d0(png, "Invalid pHYS after IDAT");
        return FUN_002e81e0(png, length);
    } else if (info && info->flags < 0) {
        FUN_002e69d0(png, "Duplicate pHYS chunk");
        return FUN_002e81e0(png, length);
    }
    if (length != 9) {
        FUN_002e69d0(png, "Incorrect pHYs chunk length");
        return FUN_002e81e0(png, length);
    }
    PhysData data;
    FUN_002e7580(png, &data, 9);
    int result = FUN_002e81e0(png, 0);
    if (result) return result;
    unsigned unit = data.unit;
    unsigned y = FUN_002e7500(data.y);
    unsigned x = FUN_002e7500(data.x);
    return FUN_002eb480(png, info, x, y, unit);
}
} // namespace fn_002e96a0


// 0x002e9790 FUN_002e9790 (229 B): equivalent/0x002e9790.cpp [wrapped: code differs from its standalone build]
// sym: _FUN_002e9790 @88302960d1cf @w8e168324ac43
namespace fn_002e9790 {
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 12/12)
// FUN_002e9790 @ 0x002e9790
struct State_2e9790 { char pad[0x60]; unsigned flags; };
struct Info_2e9790 { char pad[8]; unsigned flags; };
extern "C++" __declspec(nothrow) void __cdecl FUN_002e69a0(State_2e9790*, const char*);
extern "C++" __declspec(nothrow) void __cdecl FUN_002e69d0(State_2e9790*, const char*);
extern "C++" __declspec(nothrow) int __cdecl FUN_002e81e0(State_2e9790*, unsigned);
extern "C++" __declspec(nothrow) void __cdecl FUN_002e7580(State_2e9790*, void*, unsigned);
extern "C++" __declspec(nothrow) unsigned __cdecl FUN_002e7500(const void*);
extern "C" int __cdecl FUN_002eb2f0(State_2e9790*, Info_2e9790*, unsigned, unsigned, unsigned);
extern "C" int __cdecl FUN_002e9790(State_2e9790* s, Info_2e9790* info, unsigned length) {
 if (!(s->flags & 1)) FUN_002e69a0(s, "Missing IHDR before oFFs");
 else if (s->flags & 4) { FUN_002e69d0(s, "Invalid oFFs after IDAT"); return FUN_002e81e0(s,length); }
 else if (info && (info->flags & 0x100)) { FUN_002e69d0(s, "Duplicate oFFs chunk"); return FUN_002e81e0(s,length); }
 if (length != 9) { FUN_002e69d0(s, "Incorrect oFFs chunk length"); return FUN_002e81e0(s,length); }
 unsigned char data[12];
 FUN_002e7580(s,data,9);
 int result = FUN_002e81e0(s,0);
 if (!result) {
 unsigned unit=data[8];
 unsigned y=FUN_002e7500(data+4);
 unsigned x=FUN_002e7500(data);
 return FUN_002eb2f0(s,info,x,y,unit);
 }
 return result;
}
} // namespace fn_002e9790


// 0x002e9880 FUN_002e9880 (561 B): equivalent/0x002e9880.cpp [wrapped: code differs from its standalone build]
// sym: ?png_handle_pCAL@fn_002e9880@@YAXPAUpng_struct_2e9880@1@PAUpng_info_2e9880@1@I@Z @d5275c8bfc6d @w15b8b49bed7b
namespace fn_002e9880 {
// STATUS: equivalent (tools/equiv.py level 3: 130 inputs, branch coverage 46/50, incomplete)
// FUN_002e9880 @ 0x002e9880
struct png_struct_2e9880 {
    char pad0[0x60];
    unsigned int mode;
};

struct png_info_2e9880 {
    char pad0[8];
    unsigned int valid;
};

void __cdecl FUN_002e69a0(png_struct_2e9880 *png_ptr, const char *msg);
void __cdecl FUN_002e69d0(png_struct_2e9880 *png_ptr, const char *msg);
int __cdecl FUN_002e81e0(png_struct_2e9880 *png_ptr, unsigned int skip);
void *__cdecl FUN_002e6c00(png_struct_2e9880 *png_ptr, unsigned int size);
void __cdecl FUN_002e6c40(png_struct_2e9880 *png_ptr, void *ptr);
void __cdecl FUN_002e7580(png_struct_2e9880 *png_ptr, unsigned char *buf, unsigned int length);
extern "C++" __declspec(nothrow) unsigned int __cdecl FUN_002e7530(unsigned char *);
void __cdecl FUN_002eb330(png_struct_2e9880 *png_ptr, png_info_2e9880 *info_ptr, char *purpose, int X0, int X1,
                          int type, int nparams, char *units, char **params);

// libpng png_handle_pCAL
void png_handle_pCAL(png_struct_2e9880 *png_ptr, png_info_2e9880 *info_ptr, unsigned int length)
{
    char *buf;
    char *endptr;
    char *units;
    char **params;
    int X0;
    int X1;
    unsigned char type;
    unsigned char nparams;
    int i;

    if (!(png_ptr->mode & 1)) {
        FUN_002e69a0(png_ptr, "Missing IHDR before pCAL");
    } else if (png_ptr->mode & 4) {
        FUN_002e69d0(png_ptr, "Invalid pCAL after IDAT");
        FUN_002e81e0(png_ptr, length);
        return;
    } else if (info_ptr != 0 && (info_ptr->valid & 0x400)) {
        FUN_002e69d0(png_ptr, "Duplicate pCAL chunk");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    buf = (char *)FUN_002e6c00(png_ptr, length + 1);
    FUN_002e7580(png_ptr, (unsigned char *)buf, length);
    if (FUN_002e81e0(png_ptr, 0)) {
        FUN_002e6c40(png_ptr, buf);
        return;
    }

    endptr = buf + length;
    *endptr = 0;
    units = buf;
    while (*units) {
        units++;
    }
    if (endptr <= units + 12) {
        FUN_002e69d0(png_ptr, "Invalid pCAL data");
        FUN_002e6c40(png_ptr, buf);
        return;
    }

    X0 = ((int)FUN_002e7530((unsigned char *)(const unsigned char *)((unsigned char *)units + 1)));
    X1 = ((int)FUN_002e7530((unsigned char *)(const unsigned char *)((unsigned char *)units + 5)));
    nparams = (unsigned char)units[10];
    type = (unsigned char)units[9];
    units += 11;

    if ((type == 0 && nparams != 2) || (type == 1 && nparams != 3) || (type == 2 && nparams != 3) ||
        (type == 3 && nparams != 4)) {
        FUN_002e69d0(png_ptr, "Invalid pCAL parameters for equation type");
        FUN_002e6c40(png_ptr, buf);
        return;
    } else if (type >= 4) {
        FUN_002e69d0(png_ptr, "Unrecognized equation type for pCAL chunk");
    }

    {
        char *p = units;
        while (*p) {
            p++;
        }
        params = (char **)FUN_002e6c00(png_ptr, nparams * sizeof(char *));
        for (i = 0; i < nparams; i++) {
            p++;
            params[i] = p;
            for (; *p != 0 && p <= endptr; p++) {
            }
            if (p > endptr) {
                FUN_002e69d0(png_ptr, "Invalid pCAL data");
                FUN_002e6c40(png_ptr, buf);
                FUN_002e6c40(png_ptr, params);
                return;
            }
        }
    }

    FUN_002eb330(png_ptr, info_ptr, buf, X0, X1, type, nparams, units, params);
    FUN_002e6c40(png_ptr, buf);
    FUN_002e6c40(png_ptr, params);
}
} // namespace fn_002e9880


// 0x002e9ac0 FUN_002e9ac0 (232 B): equivalent/0x002e9ac0.cpp [wrapped: code differs from its standalone build]
// sym: _FUN_002e9ac0 @1a1c428dea09 @wa5bedb5274b7
namespace fn_002e9ac0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_002e9ac0 @ 0x002e9ac0
struct Png_2e9ac0 { char pad[0x60]; unsigned flags; };
struct Info_2e9ac0 { char pad[8]; unsigned flags; };
struct Time { unsigned short year; unsigned char month, day, hour, minute, second; };
extern void __cdecl FUN_002e69a0(Png_2e9ac0*, const char*);
extern void __cdecl FUN_002e69d0(Png_2e9ac0*, const char*);
extern int __cdecl FUN_002e81e0(Png_2e9ac0*, unsigned);
extern void __cdecl FUN_002e7580(Png_2e9ac0*, unsigned char*, unsigned);
extern "C++" __declspec(nothrow) unsigned short __cdecl FUN_002e7560(const unsigned char *);
extern int __cdecl FUN_002eb6f0(Png_2e9ac0*, Info_2e9ac0*, Time*);
extern "C" int __cdecl FUN_002e9ac0(Png_2e9ac0* png, Info_2e9ac0* info, unsigned length) {
 if (!(png->flags & 1)) FUN_002e69a0(png, "Out of place tIME chunk");
 else if (info && (info->flags & 0x200)) {
  FUN_002e69d0(png, "Duplicate tIME chunk");
  return FUN_002e81e0(png,length);
 }
 if (png->flags & 4) png->flags |= 8;
 if (length != 7) {
  FUN_002e69d0(png,"Incorrect tIME chunk length");
  return FUN_002e81e0(png,length);
 }
 unsigned char data[8];
 Time t;
 FUN_002e7580(png,data,7);
 int result=FUN_002e81e0(png,0);
 if (result) return result;
 t.hour=data[4]; t.minute=data[5]; t.second=data[6];
 t.day=data[3]; t.month=data[2];
 t.year=FUN_002e7560(data);
 return FUN_002eb6f0(png,info,&t);
}
} // namespace fn_002e9ac0

namespace fn_fb0f1f83 {

// 0x002e9bb0 FUN_002e9bb0 (176 B): matches/0x002e9bb0.cpp
// sym: _FUN_002e9bb0
extern "C" void FUN_002e9bb0(Thing_2e9bb0* a, void* x, unsigned int n) {
    if (!(a->flags & 1))
        FUN_002e69a0(a, "Missing IHDR before tEXt");
    if (a->flags & 4)
        a->flags |= 8;
    char* b = FUN_002e6c00(a, n + 1);
    FUN_002e7580(a, b, n);
    if (FUN_002e81e0(a, 0)) {
        FUN_002e6c40(a, b);
        return;
    }
    b[n] = 0;
    char* e = b;
    while (*e)
        ++e;
    if (e != b + n)
        ++e;
    void* q = FUN_002e6c00(a, 16);
    ((int*)q)[0] = -1;
    ((char**)q)[1] = b;
    ((char**)q)[2] = e;
    FUN_002eb5e0(a, x, q, 1);
    FUN_002e6c40(a, (char*)q);
}


// 0x002e9c60 FUN_002e9c60 (861 B): equivalent/0x002e9c60.cpp
// sym: ?png_handle_zTXt@fn_fb0f1f83@@YAXPAUPngStruct_2e9c60@1@PAXI@Z @0ecaf1575fff @w07c38831191b
// STATUS: equivalent (tools/equiv.py level 3: 1068 inputs, branch coverage 36/38, incomplete)
// FUN_002e9c60 @ 0x002e9c60
// libpng png_handle_zTXt (with png_decompress_chunk inlined)
void png_handle_zTXt(PngStruct_2e9c60 *png, void *info, unsigned length)
{
    char *chunkdata;
    char *text;
    int comp_type = -1;
    unsigned prefix;
    unsigned text_size;
    char umsg[52];

    if (!(png->mode & 1))
        FUN_002e69a0(png, "Missing IHDR before zTXt");
    if (png->mode & 4)
        png->mode |= 8;

    chunkdata = (char *)FUN_002e6c00(png, length + 1);
    FUN_002e7580(png, chunkdata, length);
    if (FUN_002e81e0(png, 0)) {
        FUN_002e6c40(png, chunkdata);
        return;
    }
    chunkdata[length] = 0;
    text = chunkdata;
    while (*text)
        text++;

    if (text == chunkdata + length) {
        FUN_002e69d0(png, "Zero length zTXt chunk");
    } else {
        comp_type = (signed char)*++text;
        text++;
        if (comp_type != 0) {
            unsigned n;
            _sprintf(umsg, "Unknown zTXt compression type %d", comp_type);
            FUN_002e69d0(png, umsg);
            text--;
            n = (unsigned)(chunkdata - text) + length - 1;
            if (n >= 0x1a)
                n = 0x1a;
            memcpy(text, "Error decoding zTXt chunk", n + 1);
        } else {
            unsigned char *zbuf0 = png->zbuf;
            unsigned zbuf_size0 = png->zbuf_size;
            prefix = (unsigned)(text - chunkdata);
            png->zstream.next_in = (unsigned char *)text;
            png->zstream.avail_in = (unsigned)(chunkdata - text) + length;
            png->zstream.next_out = zbuf0;
            png->zstream.avail_out = zbuf_size0;
            text = 0;
            text_size = 0;
            while (png->zstream.avail_in) {
                int ret = FUN_002e6f70(&png->zstream, 1);
                if (ret != 0 && ret != 1) {
                    const char *m = png->zstream.msg;
                    FUN_002e69d0(png, m ? m : "Error decoding zTXt chunk");
                    FUN_002e6db0(&png->zstream);
                    png->zstream.avail_in = 0;
                    if (text == 0) {
                        text_size = prefix + 0x1b;
                        text = (char *)FUN_002e6c00(png, text_size);
                        memcpy(text, chunkdata, prefix);
                    }
                    text[text_size - 1] = 0;
                    {
                        unsigned n = (unsigned)(chunkdata - text) + length - 1;
                        if (n >= 0x1a)
                            n = 0x1a;
                        memcpy(text + prefix, "Error decoding zTXt chunk", n + 1);
                    }
                    break;
                }
                {
                    unsigned avail_out = png->zstream.avail_out;
                    if (avail_out == 0 || ret == 1) {
                        unsigned produced = png->zbuf_size - avail_out;
                        if (text == 0) {
                            char *nt = (char *)FUN_002e6c00(png, produced + prefix + 1);
                            unsigned n = png->zbuf_size - png->zstream.avail_out;
                            text = nt;
                            memcpy(text + prefix, png->zbuf, n);
                            memcpy(text, chunkdata, prefix);
                            text_size = png->zbuf_size - png->zstream.avail_out + prefix;
                        } else {
                            char *old = text;
                            unsigned oldsize = text_size;
                            unsigned n;
                            text = (char *)FUN_002e6c00(png, produced + oldsize + 1);
                            memcpy(text, old, oldsize);
                            FUN_002e6c40(png, old);
                            n = png->zbuf_size - png->zstream.avail_out;
                            memcpy(text + oldsize, png->zbuf, n);
                            text_size = oldsize + (png->zbuf_size - png->zstream.avail_out);
                        }
                        text[text_size] = 0;
                        if (ret == 1)
                            break;
                        png->zstream.next_out = png->zbuf;
                        png->zstream.avail_out = png->zbuf_size;
                    }
                }
            }
            FUN_002e6db0(&png->zstream);
            png->zstream.avail_in = 0;
            FUN_002e6c40(png, chunkdata);
            chunkdata = text;
            text = text + prefix;
        }
    }

    {
        PngText *tp = (PngText *)FUN_002e6c00(png, 0x10);
        tp->compression = comp_type;
        tp->key = chunkdata;
        tp->text = text;
        FUN_002eb5e0(png, info, tp, 1);
        FUN_002e6c40(png, tp);
    }
}

} // namespace fn_fb0f1f83

// 0x002e9fc0 FUN_002e9fc0 (80 B): matches/0x002e9fc0.cpp [wrapped: lost its match in the tree (call sequence differs)]
// sym: _FUN_002e9fc0
namespace fn_002e9fc0 {
typedef unsigned int u32_2e9fc0;
typedef unsigned char u8;
extern void Parse_002e7620(void*, u8*);
extern "C++" __declspec(nothrow) void __cdecl FUN_002e69f0(void *, void *);
extern void Continue_002e81e0(void*, u32_2e9fc0);
extern "C" void FUN_002e9fc0(void* self, hulk_uintptr param2, u32_2e9fc0 param3) {
    u8* flag = (u8*)self + 0x114;
    Parse_002e7620(self, flag);
    if ((*flag & 0x20) == 0 && (FUN_002e69f0(self, (void *)(const char *)"unknown critical chunk"), param2 == 0))
        return;
    u32_2e9fc0* state = (u32_2e9fc0*)((char*)self + 0x60);
    if ((*state & 4) != 0)
        *state |= 8;
    Continue_002e81e0(self, param3);
}
} // namespace fn_002e9fc0


// 0x002ea010 FUN_002ea010 (653 B): equivalent/0x002ea010.cpp [wrapped: code differs from its standalone build]
// sym: ?FUN_002ea010@fn_002ea010@@YAXPAUPngStruct_2ea010@1@@Z @0663fdae1386 @wca218f1c0d14
namespace fn_002ea010 {
// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 40/42, incomplete)
// FUN_002ea010 @ 0x002ea010

struct ZStream_2ea010 {
    unsigned char *next_in;
    unsigned avail_in;
    unsigned total_in;
    unsigned char *next_out;
    unsigned avail_out;
    unsigned total_out;
    const char *msg;
};

struct PngStruct_2ea010 {
    char pad0[0x60];
    unsigned mode;
    unsigned flags;
    unsigned transformations;
    ZStream_2ea010 zstream;
    char pad1[0xa4 - 0x6c - sizeof(ZStream_2ea010)];
    unsigned char *zbuf;
    unsigned zbuf_size;
    char pad2[0xc0 - 0xac];
    unsigned width;
    unsigned height;
    unsigned num_rows;
    char pad3[0xd0 - 0xcc];
    unsigned rowbytes;
    unsigned irowbytes;
    unsigned iwidth;
    unsigned row_number;
    unsigned char *prev_row;
    char pad4[0x104 - 0xe4];
    unsigned idat_size;
    char pad5[0x114 - 0x108];
    unsigned char chunk_name[4];
    char pad6[0x11b - 0x118];
    unsigned char interlaced;
    unsigned char pass;
    char pad7[0x121 - 0x11d];
    unsigned char pixel_depth;
};


void __cdecl FUN_002e6b60(PngStruct_2ea010 *png, void *s, int c, unsigned n);
void __cdecl FUN_002e81e0(PngStruct_2ea010 *png, unsigned n);
void __cdecl FUN_002dd690(PngStruct_2ea010 *png, void *buf, unsigned n);
unsigned __cdecl FUN_002e7500(unsigned char *buf);
void __cdecl FUN_002d6c90(PngStruct_2ea010 *png);
void __cdecl FUN_002e7580(PngStruct_2ea010 *png, void *buf, unsigned n);
void __cdecl FUN_002e69a0(PngStruct_2ea010 *png, const char *msg);
int __cdecl FUN_002e6f70(ZStream_2ea010 *z, int flush);
void __cdecl FUN_002e6db0(ZStream_2ea010 *z);

void FUN_002ea010(PngStruct_2ea010 *png)
{
    png->row_number = png->row_number + 1;
    if (png->row_number < png->num_rows)
        return;

    if (png->interlaced) {
        png->row_number = 0;
        FUN_002e6b60(png, png->prev_row, 0, png->rowbytes + 1);
        do {
            png->pass = png->pass + 1;
            if (png->pass >= 7)
                break;
            png->iwidth = (png->width + ((unsigned*)&DAT_004d10d8)[png->pass] - 1 - DAT_004d10bc[png->pass]) / ((unsigned*)&DAT_004d10d8)[png->pass];
            png->irowbytes = ((png->pixel_depth * png->iwidth + 7) >> 3) + 1;
            if (!(png->transformations & 2))
                png->num_rows = (png->height + ((unsigned*)&DAT_004d1110)[png->pass] - 1 - ((unsigned*)&DAT_004d10f4)[png->pass]) / ((unsigned*)&DAT_004d1110)[png->pass];
            else
                break;
        } while (png->iwidth == 0);
        if (png->pass < 7)
            return;
    }

    if (!(png->flags & 0x20)) {
        char extra;
        unsigned char chunk_length[4];
        png->zstream.next_out = (unsigned char *)&extra;
        png->zstream.avail_out = 1;
        for (;;) {
            if (!png->zstream.avail_in) {
                while (!png->idat_size) {
                    FUN_002e81e0(png, 0);
                    FUN_002dd690(png, chunk_length, 4);
                    png->idat_size = FUN_002e7500(chunk_length);
                    FUN_002d6c90(png);
                    FUN_002e7580(png, png->chunk_name, 4);
                    if (*(unsigned *)png->chunk_name != *(unsigned *)((unsigned char*)&DAT_004d103c))
                        FUN_002e69a0(png, "Not enough image data");
                }
                png->zstream.avail_in = png->zbuf_size;
                png->zstream.next_in = png->zbuf;
                if (png->zbuf_size > png->idat_size)
                    png->zstream.avail_in = png->idat_size;
                FUN_002e7580(png, png->zbuf, png->zstream.avail_in);
                png->idat_size -= png->zstream.avail_in;
            }
            int ret = FUN_002e6f70(&png->zstream, 1);
            if (ret == 1) {
                if (!png->zstream.avail_out || png->zstream.avail_in || png->idat_size)
                    FUN_002e69a0(png, "Extra compressed data");
                png->mode |= 8;
                png->flags |= 0x20;
                break;
            }
            if (ret != 0)
                FUN_002e69a0(png, png->zstream.msg ? png->zstream.msg : "Decompression Error");
            if (!png->zstream.avail_out)
                FUN_002e69a0(png, "Extra compressed data");
        }
        png->zstream.avail_out = 0;
    }
    if (png->idat_size || png->zstream.avail_in)
        FUN_002e69a0(png, "Extra compression data");
    FUN_002e6db0(&png->zstream);
    png->mode |= 8;
}
} // namespace fn_002ea010

namespace fn_fb0f1f83 {

// 0x002ea2a0 FUN_002ea2a0 (123 B): matches/0x002ea2a0.cpp
// sym: ?FUN_002ea2a0@fn_fb0f1f83@@YAXPAVObj_2ea2a0@1@PAUCtx_2ea2a0@1@PAH@Z
void __cdecl FUN_002ea2a0(Obj_2ea2a0* self, Ctx_2ea2a0* ctx, int* out) {
    if (out)
        *out = self->m3c;
    if (self->type == 4 || self->type == 5) {
        int v = ctx->x28;
        int a = self->aC;
        ctx->fn(v, a);
    }
    if (self->type == 6)
        FUN_002ebed0(self->a4, ctx);
    self->m34 = self->m28;
    self->m30 = self->m28;
    int(__cdecl * f)(int, int, int) = self->m38;
    self->type = 0;
    self->m1c = 0;
    self->m20 = 0;
    if (f) {
        int r = f(0, 0, 0);
        self->m3c = r;
        ctx->m30 = r;
    }
}


// 0x002ea320 FUN_002ea320 (155 B): matches/0x002ea320.cpp
// sym: ?FUN_002ea320@fn_fb0f1f83@@YAPAXPAUManager_2ea320@1@HH@Z
void* __cdecl FUN_002ea320(Manager_2ea320* m, hulk_intptr param2, int param3) {
    void* a = m->alloc(m->heap, 1, 0x40);
    if (!a)
        return 0;
    *(void**)((char*)a + 0x24) = m->alloc(m->heap, 8, 0x5a0);
    if (!*(void**)((char*)a + 0x24)) {
        m->freefn(m->heap, a);
        return 0;
    }
    *(void**)((char*)a + 0x28) = m->alloc(m->heap, 1, param3);
    if (!*(void**)((char*)a + 0x28)) {
        m->freefn(m->heap, *(void**)((char*)a + 0x24));
        m->freefn(m->heap, a);
        return 0;
    }
    *(void**)((char*)a + 0x2c) = (char*)*(void**)((char*)a + 0x28) + param3;
    *(int*)((char*)a + 0x38) = param2;
    *(int*)a = 0;
    FUN_002ea2a0(a, m, 0);
    return a;
}

} // namespace fn_fb0f1f83

// 0x002ea3c0 FUN_002ea3c0 (2870 B): equivalent/0x002ea3c0.cpp [wrapped: macros]
// sym: ?FUN_002ea3c0@fn_002ea3c0@@YAHPAUinflate_blocks_state@1@PAUz_stream@1@H@Z @a290fa3b15be @w99b685128fb5
namespace fn_002ea3c0 {
// STATUS: equivalent (tools/equiv.py level 3: 19923 inputs, branch coverage 133/142, incomplete)
// FUN_002ea3c0 @ 0x002ea3c0
// FUN_002ea3c0 @ 0x002ea3c0

typedef unsigned char Byte;
typedef unsigned int uInt;
typedef unsigned long uLong;

struct z_stream;
typedef void *(__cdecl *alloc_func)(void *opaque, uInt items, uInt size);
typedef void (__cdecl *free_func)(void *opaque, void *address);

struct inflate_huft {
    Byte exop;
    Byte bits;
    unsigned short pad;
    uInt base;
};

struct z_stream {
    Byte *next_in;
    uInt avail_in;
    uLong total_in;
    Byte *next_out;
    uInt avail_out;
    uLong total_out;
    char *msg;
    void *state;
    alloc_func zalloc;
    free_func zfree;
    void *opaque;
};

struct inflate_codes_state;

struct inflate_blocks_state {
    uInt mode;
    union {
        uInt left;
        struct {
            uInt table;
            uInt index;
            uInt *blens;
            uInt bb;
            inflate_huft *tb;
        } trees;
        struct {
            inflate_codes_state *codes;
        } decode;
    } sub;
    uInt last;
    uInt bitk;
    uLong bitb;
    inflate_huft *hufts;
    Byte *window;
    Byte *end;
    Byte *read;
    Byte *write;
};


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *memcpy(void *, const void *, unsigned int);
#endif


extern int __cdecl FUN_002ec650(inflate_blocks_state *s, z_stream *z, int r);
extern int __cdecl FUN_002ec620(uInt *bl, uInt *bd, inflate_huft **tl, inflate_huft **td, z_stream *z);
extern inflate_codes_state *__cdecl FUN_002eb780(uInt bl, uInt bd, inflate_huft *tl, inflate_huft *td, z_stream *z);
extern int __cdecl FUN_002ec3e0(uInt *c, uInt *bb, inflate_huft **tb, inflate_huft *hp, z_stream *z);
extern int __cdecl FUN_002ec490(uInt nl, uInt nd, uInt *c, uInt *bl, uInt *bd, inflate_huft **tl, inflate_huft **td, inflate_huft *hp, z_stream *z);
extern int __cdecl FUN_002eb7c0(inflate_blocks_state *s, z_stream *z, int r);
extern void __cdecl FUN_002ebed0(inflate_codes_state *c, z_stream *z);

#define LOADIN { p = z->next_in; n = z->avail_in; b = s->bitb; k = s->bitk; }
#define WAVAIL ((uInt)(q < s->read ? s->read - q - 1 : s->end - q))
#define LOADOUT { q = s->write; m = WAVAIL; }
#define LOAD { LOADIN LOADOUT }
// zlib's order: s and z may alias, so the stores must come in this order.
#define UPDATEIN { s->bitb = b; s->bitk = k; z->avail_in = n; z->total_in += p - z->next_in; z->next_in = p; }
#define UPDATEOUT { s->write = q; }
#define UPDATE { UPDATEIN UPDATEOUT }
#define LEAVE { UPDATE return FUN_002ec650(s, z, r); }
#define NEEDBYTE { if (n) r = 0; else LEAVE }
#define NEXTBYTE (n--, *p++)
#define NEEDBITS(j) { while (k < (j)) { NEEDBYTE b |= ((uLong)NEXTBYTE) << k; k += 8; } }
#define DUMPBITS(j) { b >>= (j); k -= (j); }
#define WRAP { if (q == s->end && s->read != s->window) { q = s->window; m = WAVAIL; } }
#define FLUSH { UPDATEOUT r = FUN_002ec650(s, z, r); LOADOUT }
#define NEEDOUT { if (m == 0) { WRAP if (m == 0) { FLUSH WRAP if (m == 0) LEAVE } } r = 0; }

int __cdecl FUN_002ea3c0(inflate_blocks_state *s, z_stream *z, int r)
{
    uInt t;
    uLong b;
    uInt k;
    Byte *p;
    uInt n;
    Byte *q;
    uInt m;

    LOAD

    while (1) switch (s->mode) {
    case 0:
        NEEDBITS(3)
        t = (uInt)b & 7;
        s->last = t & 1;
        switch (t >> 1) {
        case 0:
            DUMPBITS(3)
            t = k & 7;
            DUMPBITS(t)
            s->mode = 1;
            break;
        case 1: {
            uInt bl, bd;
            inflate_huft *tl, *td;
            FUN_002ec620(&bl, &bd, &tl, &td, z);
            s->sub.decode.codes = FUN_002eb780(bl, bd, tl, td, z);
            if (s->sub.decode.codes == 0) {
                r = -4;
                LEAVE
            }
        }
            DUMPBITS(3)
            s->mode = 6;
            break;
        case 2:
            DUMPBITS(3)
            s->mode = 3;
            break;
        case 3:
            DUMPBITS(3)
            s->mode = 9;
            z->msg = "invalid block type";
            r = -3;
            LEAVE
        }
        break;
    case 1:
        NEEDBITS(32)
        if ((((~b) >> 16) & 0xffff) != (b & 0xffff)) {
            s->mode = 9;
            z->msg = "invalid stored block lengths";
            r = -3;
            LEAVE
        }
        s->sub.left = (uInt)b & 0xffff;
        b = k = 0;
        s->mode = s->sub.left ? 2 : (s->last ? 7 : 0);
        break;
    case 2:
        if (n == 0)
            LEAVE
        NEEDOUT
        t = s->sub.left;
        if (t > n)
            t = n;
        if (t > m)
            t = m;
        memcpy(q, p, t);
        p += t;
        n -= t;
        q += t;
        m -= t;
        if ((s->sub.left -= t) != 0)
            break;
        s->mode = s->last ? 7 : 0;
        break;
    case 3:
        NEEDBITS(14)
        s->sub.trees.table = t = (uInt)b & 0x3fff;
        if ((t & 0x1f) > 29 || ((t >> 5) & 0x1f) > 29) {
            s->mode = 9;
            z->msg = "too many length or distance symbols";
            r = -3;
            LEAVE
        }
        t = 258 + (t & 0x1f) + ((t >> 5) & 0x1f);
        if ((s->sub.trees.blens = (uInt *)(*(z->zalloc))(z->opaque, t, sizeof(uInt))) == 0) {
            r = -4;
            LEAVE
        }
        DUMPBITS(14)
        s->sub.trees.index = 0;
        s->mode = 4;
    case 4:
        while (s->sub.trees.index < 4 + (s->sub.trees.table >> 10)) {
            NEEDBITS(3)
            s->sub.trees.blens[((unsigned int*)&DAT_00430c58)[s->sub.trees.index++]] = (uInt)b & 7;
            DUMPBITS(3)
        }
        while (s->sub.trees.index < 19)
            s->sub.trees.blens[((unsigned int*)&DAT_00430c58)[s->sub.trees.index++]] = 0;
        s->sub.trees.bb = 7;
        t = FUN_002ec3e0(s->sub.trees.blens, &s->sub.trees.bb, &s->sub.trees.tb, s->hufts, z);
        if (t != 0) {
            (*(z->zfree))(z->opaque, s->sub.trees.blens);
            r = t;
            if (r == -3)
                s->mode = 9;
            LEAVE
        }
        s->sub.trees.index = 0;
        s->mode = 5;
    case 5:
        while (t = s->sub.trees.table, s->sub.trees.index < 258 + (t & 0x1f) + ((t >> 5) & 0x1f)) {
            inflate_huft *h;
            uInt i, j, c;

            t = s->sub.trees.bb;
            NEEDBITS(t)
            h = s->sub.trees.tb + ((uInt)b & ((unsigned int*)&DAT_004d2838)[t]);
            t = h->bits;
            c = h->base;
            if (c < 16) {
                DUMPBITS(t)
                s->sub.trees.blens[s->sub.trees.index++] = c;
            } else {
                i = c == 18 ? 7 : c - 14;
                j = c == 18 ? 11 : 3;
                NEEDBITS(t + i)
                DUMPBITS(t)
                j += (uInt)b & ((unsigned int*)&DAT_004d2838)[i];
                DUMPBITS(i)
                i = s->sub.trees.index;
                t = s->sub.trees.table;
                if (i + j > 258 + (t & 0x1f) + ((t >> 5) & 0x1f) || (c == 16 && i < 1)) {
                    (*(z->zfree))(z->opaque, s->sub.trees.blens);
                    s->mode = 9;
                    z->msg = "invalid bit length repeat";
                    r = -3;
                    LEAVE
                }
                c = c == 16 ? s->sub.trees.blens[i - 1] : 0;
                do {
                    s->sub.trees.blens[i++] = c;
                } while (--j);
                s->sub.trees.index = i;
            }
        }
        s->sub.trees.tb = 0;
        {
            uInt bl, bd;
            inflate_huft *tl, *td;
            inflate_codes_state *c;

            bl = 9;
            bd = 6;
            t = s->sub.trees.table;
            t = FUN_002ec490(257 + (t & 0x1f), 1 + ((t >> 5) & 0x1f), s->sub.trees.blens, &bl, &bd, &tl, &td, s->hufts, z);
            (*(z->zfree))(z->opaque, s->sub.trees.blens);
            if (t != 0) {
                if (t == (uInt)-3)
                    s->mode = 9;
                r = t;
                LEAVE
            }
            if ((c = FUN_002eb780(bl, bd, tl, td, z)) == 0) {
                r = -4;
                LEAVE
            }
            s->sub.decode.codes = c;
        }
        s->mode = 6;
    case 6:
        UPDATE
        if ((r = FUN_002eb7c0(s, z, r)) != 1)
            return FUN_002ec650(s, z, r);
        r = 0;
        FUN_002ebed0(s->sub.decode.codes, z);
        LOAD
        if (!s->last) {
            s->mode = 0;
            break;
        }
        s->mode = 7;
    case 7:
        FLUSH
        if (s->read != s->write)
            LEAVE
        s->mode = 8;
    case 8:
        r = 1;
        LEAVE
    case 9:
        r = -3;
        LEAVE
    default:
        r = -2;
        LEAVE
    }
}
} // namespace fn_002ea3c0
#undef DUMPBITS
#undef FLUSH
#undef LEAVE
#undef LOAD
#undef LOADIN
#undef LOADOUT
#undef NEEDBITS
#undef NEEDBYTE
#undef NEEDOUT
#undef NEXTBYTE
#undef UPDATE
#undef UPDATEIN
#undef UPDATEOUT
#undef WAVAIL
#undef WRAP

namespace fn_fb0f1f83 {

// 0x002eaf30 FUN_002eaf30 (57 B): matches/0x002eaf30.cpp
// sym: _FUN_002eaf30
extern "C" int __cdecl FUN_002eaf30(void * a, void * b) {
    FUN_002ea2a0(((Obj_2eaf30 *)a), ((Obj_2eaf30 *)b), 0);
    ((Obj_2eaf30 *)b)->fn(((Obj_2eaf30 *)b)->value, ((Obj_2eaf30 *)a)->value);
    ((Obj_2eaf30 *)b)->fn(((Obj_2eaf30 *)b)->value, *((u32_2eaf30*)((char*)((Obj_2eaf30 *)a) + 0x24)));
    ((Obj_2eaf30 *)b)->fn(((Obj_2eaf30 *)b)->value, (hulk_uintptr)((Obj_2eaf30 *)a));
    return 0;
}


// 0x002eaf70 FUN_002eaf70 (49 B): matches/0x002eaf70.cpp
// sym: ?FUN_002eaf70@fn_fb0f1f83@@YAXPAUBuf@1@PBXI@Z
void __cdecl FUN_002eaf70(Buf* p, const void* src, unsigned int n) {
    memcpy(p->data, src, n);
    p->a = p->b = p->data + n;
}


// 0x002eafc0 FUN_002eafc0 (297 B): equivalent/0x002eafc0.cpp
// sym: ?FUN_002eafc0@fn_fb0f1f83@@YAIIPBEI@Z @5e1a7141f371 @w54753c603962
// STATUS: equivalent (tools/equiv.py level 3: 159 inputs, branch coverage 16/16)
// FUN_002eafc0 @ 0x002eafc0
unsigned int __cdecl FUN_002eafc0(unsigned int checksum, const unsigned char* data, unsigned int length)
{
    if (!data) return 1;
    unsigned int low = checksum & 0xffff;
    unsigned int high = checksum >> 16;
    while (length) {
        unsigned int count = length < 5552 ? length : 5552;
        length -= count;
        for (unsigned int i = 0; i < count; ++i) {
            low += *data++;
            high += low;
        }
        low %= 65521;
        high %= 65521;
    }
    return (high << 16) | low;
}


// 0x002eb120 FUN_002eb120 (19 B): matches/0x002eb120.cpp
// sym: ?FUN_002eb120@fn_fb0f1f83@@YAXHHH@Z
void FUN_002eb120(int a, int b, int c) {
    FUN_00347aa0(b, c);
}


// 0x002eb140 FUN_002eb140 (12 B): matches/0x002eb140.cpp
// sym: ?FUN_002eb140@fn_fb0f1f83@@YAXHH@Z
void __cdecl FUN_002eb140(int a, int b) {
    FUN_003479bc(b);
}


// 0x002eb150 FUN_002eb150 (48 B): matches/0x002eb150.cpp
// sym: ?Set@fn_fb0f1f83@@YAXHPAUObj@1@PBX@Z
void Set(int ok, Obj* obj, const void* src) {
    if (ok && obj) {
        memcpy(&obj->data[0x4e], src, 10);
        obj->flags |= 0x20;
    }
}


// 0x002eb180 FUN_002eb180 (106 B): matches/0x002eb180.cpp
// sym: ?target@fn_fb0f1f83@@YAXHPAUObj_2eb180@1@NNNNNNNN@Z
void target(hulk_intptr p1, Obj_2eb180* p2, double a, double b, double c, double d, double e, double f, double g, double h) {
    if (!p1)
        return;
    if (!p2)
        return;
    p2->flags |= 4;
    p2->a[0] = (float)a;
    p2->a[1] = (float)b;
    p2->a[2] = (float)c;
    p2->a[3] = (float)d;
    p2->a[4] = (float)e;
    p2->a[5] = (float)f;
    p2->a[6] = (float)g;
    p2->a[7] = (float)h;
}


// 0x002eb1f0 FUN_002eb1f0 (33 B): matches/0x002eb1f0.cpp
// sym: ?FUN_002eb1f0@fn_fb0f1f83@@YAXHPAUObj_2eb1f0@1@N@Z
void FUN_002eb1f0(hulk_intptr a, Obj_2eb1f0* b, double c) {
    if (a && b) {
        b->value = (float)c;
        b->flags |= 1;
    }
}


// 0x002eb220 FUN_002eb220 (28 B): matches/0x002eb220.cpp
// sym: ?FUN_002eb220@fn_fb0f1f83@@YAXHPAUThing_2eb220@1@I@Z
void FUN_002eb220(hulk_intptr handle, Thing_2eb220* object, hulk_uintptr newValue) {
    if (handle && object) {
        object->value = newValue;
        object->flags |= 0x40;
    }
}


// 0x002eb240 FUN_002eb240 (173 B): matches/0x002eb240.cpp
// sym: ?FUN_002eb240@fn_fb0f1f83@@YAXHPAUImage@1@IIDEEEE@Z
void FUN_002eb240(int a, Image* p, unsigned int width, unsigned int p4, char channels, unsigned char type,
                  unsigned char b7, unsigned char b8, unsigned char b9) {
    if (!a || !p)
        return;
    p->width = width;
    p->channels = channels;
    p->p4 = p4;
    p->b8 = b8;
    p->type = type;
    p->b9 = b9;
    p->b7 = b7;
    if (type == 3 || (type & 2) == 0)
        p->row = 1;
    else
        p->row = 3;
    if (type & 4)
        ++p->row;
    unsigned char bits = p->row * channels;
    p->bits = bits;
    unsigned int divisor = (bits + 7) >> 3;
    if (width > 0x7fffffff / divisor) {
        FUN_002e69d0((void *)(hulk_uintptr)(int)a, (void *)(const char *)"Width too large to process image data; rowbytes will overflow.");
        p->rowbytes = 0;
        return;
    }
    p->rowbytes = (bits * width + 7) >> 3;
}


// 0x002eb2f0 FUN_002eb2f0 (50 B): matches/0x002eb2f0.cpp
// sym: ?target@fn_fb0f1f83@@YAXHPAUObj_2eb2f0@1@HHE@Z
void target(int p1, Obj_2eb2f0* p2, int p3, int p4, unsigned char p5) {
    if (p1 != 0 && p2 != 0) {
        p2->a = p3;
        p2->b = p4;
        p2->c = p5;
        p2->flags |= 0x100;
    }
}


// 0x002eb330 FUN_002eb330 (328 B): equivalent/0x002eb330.cpp
// sym: ?FUN_002eb330@fn_fb0f1f83@@YAXPAUPool@1@PAUEntry_2eb330@1@PBDHHDH2PAPBD@Z @046ed051afd6 @w5e94cbe73676
// STATUS: equivalent (tools/equiv.py level 3: 168 inputs, branch coverage 14/14)
// FUN_002eb330 @ 0x002eb330
// the original scans and copies with inline repne scasb / rep movs; plain forward loops keep clang from emitting calls
void FUN_002eb330(Pool *pool, Entry_2eb330 *e, const char *name, int a4, int a8,
                  char flagA, int count, const char *text, const char **list)
{
    if (pool == 0)
        return;
    if (e == 0)
        return;

    hulk_uintptr n = Len(name) + 1;
    char *copy = (char *)FUN_002e6c00(pool, n);
    e->name = copy;
    Copy(copy, name, n);
    e->flagA = flagA;
    e->a4 = a4;
    e->a8 = a8;
    e->count = (unsigned char)count;

    n = Len(text) + 1;
    copy = (char *)FUN_002e6c00(pool, n);
    e->text = copy;
    Copy(copy, text, n);

    e->list = (char **)FUN_002e6c00(pool, count * 4 + 4);
    e->list[count] = 0;
    for (int i = 0; i < count; i++) {
        n = Len(list[i]) + 1;
        char *s = (char *)FUN_002e6c00(pool, n);
        e->list[i] = s;
        Copy(e->list[i], list[i], n);
    }
    e->flags |= 0x400;
}


// 0x002eb480 FUN_002eb480 (50 B): matches/0x002eb480.cpp
// sym: ?target@fn_fb0f1f83@@YAXHPADIIE@Z
void target(int a, char* b, u32_2eb480 c, u32_2eb480 d, u8_2eb480 e) {
    if (a && b) {
        *(u32_2eb480*)(b + 0x70) = c;
        *(u32_2eb480*)(b + 0x74) = d;
        *(u8_2eb480*)(b + 0x78) = e;
        *(u32_2eb480*)(b + 8) |= 0x80;
    }
}


// 0x002eb4c0 FUN_002eb4c0 (42 B): matches/0x002eb4c0.cpp
// sym: ?FUN_002eb4c0@fn_fb0f1f83@@YAXHPAUObj_2eb4c0@1@IG@Z
void FUN_002eb4c0(int a, Obj_2eb4c0* b, u32_2eb4c0 c, u16_2eb4c0 d) {
    if (a && b) {
        b->field10 = c;
        b->field14 = d;
        b->flags |= 8;
    }
}


// 0x002eb4f0 FUN_002eb4f0 (40 B): matches/0x002eb4f0.cpp
// sym: ?FUN_002eb4f0@fn_fb0f1f83@@YAXPAXPAUDst@1@PAUSrc@1@@Z
void __cdecl FUN_002eb4f0(void* p, Dst* d, Src* s) {
    if (p && d) {
        memcpy(&d->value, s, 5);
        d->flags |= 2;
    }
}


// 0x002eb520 FUN_002eb520 (31 B): matches/0x002eb520.cpp
// sym: ?FUN_002eb520@fn_fb0f1f83@@YAXHPAXE@Z
void FUN_002eb520(int a, void* b, unsigned char c) {
    if (a && b) {
        ((unsigned char*)b)[0x2c] = c;
        *(unsigned*)((char*)b + 8) |= 0x800;
    }
}

} // namespace fn_fb0f1f83

// 0x002eb540 FUN_002eb540 (146 B): equivalent/0x002eb540.cpp [wrapped: compile error C2732: linkage specification contradicts earlier specification for 'fn_fb0f1f83::FUN_002eb540']
// sym: _FUN_002eb540 @4f4ca09b98b0 @wb63ff8f96ea9
namespace fn_002eb540 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002eb540 @ 0x002eb540
// libpng png_set_sRGB_gAMA_and_cHRM
struct png_struct;
struct png_info;

void __cdecl FUN_002eb520(png_struct *png_ptr, png_info *info_ptr, int intent);                  // png_set_sRGB
void __cdecl FUN_002eb1f0(png_struct *png_ptr, png_info *info_ptr, double file_gamma);           // png_set_gAMA
void __cdecl FUN_002eb180(png_struct *png_ptr, png_info *info_ptr,
                          double white_x, double white_y, double red_x, double red_y,
                          double green_x, double green_y, double blue_x, double blue_y);          // png_set_cHRM

extern "C" void __cdecl FUN_002eb540(png_struct *png_ptr, png_info *info_ptr, int intent)
{
    if (png_ptr == 0 || info_ptr == 0)
        return;

    FUN_002eb520(png_ptr, info_ptr, intent);
    FUN_002eb1f0(png_ptr, info_ptr, 0.45f);
    FUN_002eb180(png_ptr, info_ptr, 0.3127f, 0.329f, 0.64f, 0.33f, 0.3f, 0.6f, 0.15f, 0.06f);
}
} // namespace fn_002eb540

namespace fn_fb0f1f83 {

// 0x002eb5e0 FUN_002eb5e0 (257 B): equivalent/0x002eb5e0.cpp
// sym: ?FUN_002eb5e0@fn_fb0f1f83@@YAXPAXPAUList_2eb5e0@1@PAUEntry_2eb5e0@1@H@Z @29d75ab1fe91 @w33b2261a5314
// STATUS: equivalent (tools/equiv.py level 3: 80 inputs, branch coverage 20/20)
// FUN_002eb5e0 @ 0x002eb5e0
void __cdecl FUN_002eb5e0(void* allocator, List_2eb5e0* list, Entry_2eb5e0* source, int count) {
 if (!allocator || !list || !count) return;
 int needed = list->count + count;
 int oldCapacity = list->capacity;
 if (needed > oldCapacity) {
  Entry_2eb5e0* old = list->entries;
  if (old) {
   list->capacity = needed + 8;
   Entry_2eb5e0* fresh = (Entry_2eb5e0*)FUN_002e6c00(allocator, (unsigned int)list->capacity * 16);
   list->entries = fresh;
   unsigned int words = ((unsigned int)oldCapacity * 16) / 4;
   unsigned int* dst = (unsigned int*)fresh;
   unsigned int* src = (unsigned int*)old;
   for (unsigned int j=0; j<words; ++j) dst[j]=src[j];
   FUN_002e6c40(allocator, old);
  } else {
   list->capacity = count + 8;
   list->count = 0;
   list->entries = (Entry_2eb5e0*)FUN_002e6c00(allocator, (unsigned int)list->capacity * 16);
  }
 }
 for (int i=0; i<count; ++i) {
  Entry_2eb5e0* dest = list->entries + list->count;
  if (!source[i].text) source[i].text = ((const char*)&DAT_003f335c);
  const char* text = source[i].text;
  if (!*text) { dest->length=0; dest->id=-1; }
  else { int len=0; while (text[len]) ++len; dest->length=len; dest->id=source[i].id; }
  dest->text=source[i].text;
  dest->value=source[i].value;
  ++list->count;
 }
}


// 0x002eb6f0 FUN_002eb6f0 (39 B): matches/0x002eb6f0.cpp
// sym: ?FUN_002eb6f0@fn_fb0f1f83@@YAXHPAUObj_2eb6f0@1@PAUData_2eb6f0@1@@Z
void FUN_002eb6f0(int p1, Obj_2eb6f0* p2, Data_2eb6f0* p3) {
    if (p1 && p2) {
        p2->x = p3->a;
        p2->y = p3->b;
        p2->flags |= 0x200;
    }
}


// 0x002eb720 FUN_002eb720 (93 B): matches/0x002eb720.cpp
// sym: ?F@fn_fb0f1f83@@YAXPAXPAUObj_2eb720@1@HHPAUVal_2eb720@1@@Z
void F(void* p, Obj_2eb720* o, hulk_intptr data, int count, Val_2eb720* v) {
    if (!p || !o)
        return;
    if (data)
        o->data = data;
    if (v)
        o->val = *v;
    if (v && !count)
        count = 1;
    o->count = count;
    o->flags |= 0x10;
}


// 0x002eb780 FUN_002eb780 (57 B): matches/0x002eb780.cpp
// sym: ?FUN_002eb780@fn_fb0f1f83@@YAPADEEHHPAUManager_2eb780@1@@Z
char* __cdecl FUN_002eb780(unsigned char a, unsigned char b, int c, int d, Manager_2eb780* m) {
    char* p = (char*)m->alloc(m->context, 1, 0x1c);
    if (p) {
        p[0x10] = a;
        p[0x11] = b;
        *(int*)p = 0;
        *(int*)(p + 0x14) = c;
        *(int*)(p + 0x18) = d;
    }
    return p;
}

} // namespace fn_fb0f1f83

// 0x002eb7c0 FUN_002eb7c0 (1761 B): equivalent/0x002eb7c0.cpp [wrapped: macros]
// sym: _FUN_002eb7c0 @033a0dcf2df3 @w32bd0e0d1c66
namespace fn_002eb7c0 {
// STATUS: equivalent (tools/equiv.py level 3: 220 inputs, branch coverage 100/114, incomplete)
// FUN_002eb7c0 @ 0x002eb7c0

typedef unsigned char Byte;
typedef Byte Bytef;
typedef unsigned int uInt;
typedef unsigned long uLong;

struct inflate_huft {
    Byte exop;
    Byte bits;
    unsigned short pad;
    uInt base;
};

struct inflate_codes_state {
    int mode;                        // 0
    uInt len;                        // 4
    union {
        struct {
            inflate_huft *tree;      // 8
            uInt need;               // 0xc
        } code;
        uInt lit;
        struct {
            uInt get;
            uInt dist;
        } copy;
    } sub;
    Byte lbits;                      // 0x10
    Byte dbits;                      // 0x11
    inflate_huft *ltree;             // 0x14
    inflate_huft *dtree;             // 0x18
};

struct z_stream {
    Bytef *next_in;                  // 0
    uInt avail_in;                   // 4
    uLong total_in;                  // 8
    char pad_c[0x18 - 0xc];
    char *msg;                       // 0x18
};

struct inflate_blocks_state {
    int mode;                        // 0
    inflate_codes_state *codes;      // 4
    char pad8[0x1c - 8];
    uInt bitk;                       // 0x1c
    uLong bitb;                      // 0x20
    char pad24[4];
    Bytef *window;                   // 0x28
    Bytef *end;                      // 0x2c
    Bytef *read;                     // 0x30
    Bytef *write;                    // 0x34
};

        // inflate_mask
int __cdecl FUN_002ec780(uInt bl, uInt bd, inflate_huft *tl, inflate_huft *td, inflate_blocks_state *s, z_stream *z);
int __cdecl FUN_002ec650(inflate_blocks_state *s, z_stream *z, int r);

#define LOAD { p = z->next_in; n = z->avail_in; b = s->bitb; k = s->bitk; q = s->write; m = (uInt)(q < s->read ? s->read - q - 1 : s->end - q); }
#define UPDATE { s->bitb = b; s->bitk = k; z->avail_in = n; z->total_in += p - z->next_in; z->next_in = p; s->write = q; }
#define LEAVE { UPDATE return FUN_002ec650(s, z, r); }
#define NEEDBITS(j) { while (k < (j)) { { if (n) r = 0; else LEAVE } n--; b |= ((uLong)(*p++)) << k; k += 8; } }
#define DUMPBITS(j) { b >>= (j); k -= (j); }
#define WRAP { if (q == s->end && s->read != s->window) { q = s->window; m = (uInt)(q < s->read ? s->read - q - 1 : s->end - q); } }
#define FLUSH { s->write = q; r = FUN_002ec650(s, z, r); q = s->write; m = (uInt)(q < s->read ? s->read - q - 1 : s->end - q); }
#define NEEDOUT { if (m == 0) { WRAP if (m == 0) { FLUSH WRAP if (m == 0) LEAVE } } r = 0; }
#define OUTBYTE(a) { *q++ = (Byte)(a); m--; }

extern "C" int __cdecl FUN_002eb7c0(inflate_blocks_state *s, z_stream *z, int r)
{
    uInt j;
    inflate_huft *t;
    uInt e;
    uLong b;
    uInt k;
    Bytef *p;
    uInt n;
    Bytef *q;
    uInt m;
    Bytef *f;
    inflate_codes_state *c = s->codes;

    LOAD

    while (1) switch (c->mode) {
    case 0:
        if (m >= 258 && n >= 10) {
            UPDATE
            r = FUN_002ec780(c->lbits, c->dbits, c->ltree, c->dtree, s, z);
            LOAD
            if (r != 0) {
                c->mode = r == 1 ? 7 : 9;
                break;
            }
        }
        c->sub.code.need = c->lbits;
        c->sub.code.tree = c->ltree;
        c->mode = 1;
    case 1:
        j = c->sub.code.need;
        NEEDBITS(j)
        t = c->sub.code.tree + ((uInt)b & ((uInt*)&DAT_004d2838)[j]);
        DUMPBITS(t->bits)
        e = (uInt)(t->exop);
        if (e == 0) {
            c->sub.lit = t->base;
            c->mode = 6;
            break;
        }
        if (e & 16) {
            c->sub.copy.get = e & 15;
            c->len = t->base;
            c->mode = 2;
            break;
        }
        if ((e & 64) == 0) {
            c->sub.code.need = e;
            c->sub.code.tree = t + t->base;
            break;
        }
        if (e & 32) {
            c->mode = 7;
            break;
        }
        c->mode = 9;
        z->msg = (char *)"invalid literal/length code";
        r = -3;
        LEAVE
    case 2:
        j = c->sub.copy.get;
        NEEDBITS(j)
        c->len += (uInt)b & ((uInt*)&DAT_004d2838)[j];
        DUMPBITS(j)
        c->sub.code.need = c->dbits;
        c->sub.code.tree = c->dtree;
        c->mode = 3;
    case 3:
        j = c->sub.code.need;
        NEEDBITS(j)
        t = c->sub.code.tree + ((uInt)b & ((uInt*)&DAT_004d2838)[j]);
        DUMPBITS(t->bits)
        e = (uInt)(t->exop);
        if (e & 16) {
            c->sub.copy.get = e & 15;
            c->sub.copy.dist = t->base;
            c->mode = 4;
            break;
        }
        if ((e & 64) == 0) {
            c->sub.code.need = e;
            c->sub.code.tree = t + t->base;
            break;
        }
        c->mode = 9;
        z->msg = (char *)"invalid distance code";
        r = -3;
        LEAVE
    case 4:
        j = c->sub.copy.get;
        NEEDBITS(j)
        c->sub.copy.dist += (uInt)b & ((uInt*)&DAT_004d2838)[j];
        DUMPBITS(j)
        c->mode = 5;
    case 5:
        f = (uInt)(q - s->window) < c->sub.copy.dist ? s->end - (c->sub.copy.dist - (q - s->window)) : q - c->sub.copy.dist;
        while (c->len) {
            NEEDOUT
            OUTBYTE(*f++)
            if (f == s->end)
                f = s->window;
            c->len--;
        }
        c->mode = 0;
        break;
    case 6:
        NEEDOUT
        OUTBYTE(c->sub.lit)
        c->mode = 0;
        break;
    case 7:
        if (k > 7) {
            k -= 8;
            n++;
            p--;
        }
        s->write = q;
        r = FUN_002ec650(s, z, r);
        q = s->write;
        if (s->read != q)
            LEAVE
        c->mode = 8;
    case 8:
        r = 1;
        LEAVE
    case 9:
        r = -3;
        LEAVE
    default:
        r = -2;
        LEAVE
    }
}
} // namespace fn_002eb7c0
#undef DUMPBITS
#undef FLUSH
#undef LEAVE
#undef LOAD
#undef NEEDBITS
#undef NEEDOUT
#undef OUTBYTE
#undef UPDATE
#undef WRAP

namespace fn_fb0f1f83 {

// 0x002ebed0 FUN_002ebed0 (20 B): matches/0x002ebed0.cpp
// sym: ?FUN_002ebed0@fn_fb0f1f83@@YAXIPAUObj_2ebed0@1@@Z
void __cdecl FUN_002ebed0(U32_2ebed0 value, Obj_2ebed0* object) {
    object->fn(object->arg, value);
}


// 0x002ebef0 FUN_002ebef0 (1256 B): equivalent/0x002ebef0.cpp
// sym: ?FUN_002ebef0@fn_fb0f1f83@@YAHPAI0IIPBI1PAPAUinflate_huft@1@PAU21@00@Z @b997725a9348 @w5db5e4e46da3
// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 74/90, incomplete)
// FUN_002ebef0 @ 0x002ebef0
// equiv-conv: FUN_002ebef0 ecx eax stack stack stack stack stack stack stack stack
int FUN_002ebef0(uInt *b, uInt *m, uInt n, uInt s, const uInt *d, const uInt *e, inflate_huft **t,
                 inflate_huft *hp, uInt *hn, uInt *v)
{
    uInt a;
    uInt c[16];
    uInt f;
    int g;
    int h;
    uInt i;
    uInt j;
    int k;
    int l;
    uInt mask;
    uInt *p;
    inflate_huft *q;
    inflate_huft r;
    inflate_huft *u[15];
    int w;
    uInt x[16];
    uInt *xp;
    int y;
    uInt z;

    for (i = 0; i < 16; i++)
        c[i] = 0;
    p = b;
    i = n;
    do {
        c[*p++]++;
    } while (--i);
    if (c[0] == n) {
        *t = 0;
        *m = 0;
        return 0;
    }

    l = *m;
    for (j = 1; j <= 15; j++)
        if (c[j])
            break;
    k = j;
    if ((uInt)l < j)
        l = j;
    for (i = 15; i; i--)
        if (c[i])
            break;
    g = i;
    if ((uInt)l > i)
        l = i;
    *m = l;

    for (y = 1 << j; j < i; j++, y <<= 1)
        if ((y -= c[j]) < 0)
            return -3;
    if ((y -= c[i]) < 0)
        return -3;
    c[i] += y;

    x[1] = j = 0;
    p = c + 1;
    xp = x + 2;
    while (--i) {
        *xp++ = (j += *p++);
    }

    p = b;
    i = 0;
    do {
        if ((j = *p++) != 0)
            v[x[j]++] = i;
    } while (++i < n);
    n = x[g];

    x[0] = i = 0;
    p = v;
    h = -1;
    w = -l;
    u[0] = 0;
    q = 0;
    z = 0;

    for (; k <= g; k++) {
        a = c[k];
        while (a--) {
            while (k > w + l) {
                h++;
                w += l;
                z = g - w;
                z = z > (uInt)l ? l : z;
                if ((f = 1 << (j = k - w)) > a + 1) {
                    f -= a + 1;
                    xp = c + k;
                    if (j < z)
                        while (++j < z) {
                            if ((f <<= 1) <= *++xp)
                                break;
                            f -= *xp;
                        }
                }
                z = 1 << j;
                if (*hn + z > 1440)
                    return -4;
                u[h] = q = hp + *hn;
                *hn += z;
                if (h) {
                    x[h] = i;
                    r.word.what.Bits = (Byte)l;
                    r.word.what.Exop = (Byte)j;
                    j = i >> (w - l);
                    r.base = (uInt)(q - u[h - 1] - j);
                    u[h - 1][j] = r;
                } else
                    *t = q;
            }

            r.word.what.Bits = (Byte)(k - w);
            if (p >= v + n)
                r.word.what.Exop = 128 + 64;
            else if (*p < s) {
                r.word.what.Exop = (Byte)(*p < 256 ? 0 : 32 + 64);
                r.base = *p++;
            } else {
                r.word.what.Exop = (Byte)(e[*p - s] + 16 + 64);
                r.base = d[*p++ - s];
            }

            f = 1 << (k - w);
            for (j = i >> w; j < z; j += f)
                q[j] = r;

            for (j = 1 << (k - 1); i & j; j >>= 1)
                i ^= j;
            i ^= j;

            mask = (1 << w) - 1;
            while ((i & mask) != x[h]) {
                h--;
                w -= l;
                mask = (1 << w) - 1;
            }
        }
    }

    return y != 0 && g != 1 ? -5 : 0;
}


// 0x002ec3e0 FUN_002ec3e0 (163 B): equivalent/0x002ec3e0.cpp
// sym: ?FUN_002ec3e0@fn_fb0f1f83@@YAHPAI0PAPAUHuft@1@PAU21@PAUZStream_2ec3e0@1@@Z @811c32bc137d @w87fd475f18a9
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_002ec3e0 @ 0x002ec3e0
// equiv-conv: FUN_002ebef0 ecx eax stack stack stack stack stack stack stack stack
int FUN_002ec3e0(unsigned int *c, unsigned int *bb, Huft **tb, Huft *hp, ZStream_2ec3e0 *z)
{
    int r;
    unsigned int hn = 0;
    unsigned int *v = (unsigned int *)z->zalloc(z->opaque, 19, 4);
    if (v == 0)
        return -4;

    r = FUN_002ebef0(c, bb, 19, 19, 0, 0, tb, hp, &hn, v);
    if (r == -3) {
        z->msg = "oversubscribed dynamic bit lengths tree";
    } else if (r == -5 || *bb == 0) {
        z->msg = "incomplete dynamic bit lengths tree";
        r = -3;
    }
    z->zfree(z->opaque, v);
    return r;
}


// 0x002ec490 FUN_002ec490 (387 B): equivalent/0x002ec490.cpp
// sym: ?FUN_002ec490@fn_fb0f1f83@@YAHIIPAI00PAPAUHuft@1@1PAU21@PAUZStream_2ec490@1@@Z @48e01babd639 @w3e49a5d59f39
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 22/22)
// FUN_002ec490 @ 0x002ec490
// equiv-conv: FUN_002ebef0 ecx eax stack stack stack stack stack stack stack stack
int FUN_002ec490(unsigned int nl, unsigned int nd, unsigned int *c, unsigned int *bl,
                 unsigned int *bd, Huft **tl, Huft **td, Huft *hp, ZStream_2ec490 *z)
{
    int r;
    unsigned int hn = 0;
    unsigned int *v = (unsigned int *)z->zalloc(z->opaque, 288, 4);
    if (v == 0)
        return -4;

    r = FUN_002ebef0(c, bl, nl, 257, ((unsigned int*)&DAT_00430e78), ((unsigned int*)&DAT_00430ef8), tl, hp, &hn, v);
    if (r != 0 || *bl == 0) {
        if (r == -3) {
            z->msg = "oversubscribed literal/length tree";
        } else if (r != -4) {
            z->msg = "incomplete literal/length tree";
            r = -3;
        }
        z->zfree(z->opaque, v);
        return r;
    }

    r = FUN_002ebef0(c + nl, bd, nd, 0, ((unsigned int*)&DAT_00430f78), ((unsigned int*)&DAT_00430ff0), td, hp, &hn, v);
    if (r != 0 || (*bd == 0 && nl > 257)) {
        if (r == -3) {
            z->msg = "oversubscribed distance tree";
        } else if (r == -5) {
            z->msg = "incomplete distance tree";
            r = -3;
        } else if (r != -4) {
            z->msg = "empty distance tree with lengths";
            r = -3;
        }
        z->zfree(z->opaque, v);
        return r;
    }

    z->zfree(z->opaque, v);
    return 0;
}


// 0x002ec620 FUN_002ec620 (46 B): equivalent/0x002ec620.cpp
// sym: ?FUN_002ec620@fn_fb0f1f83@@YAHPAH0PAPAH1@Z @c5d1d207d504 @w8b29200b3707
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002ec620 @ 0x002ec620
int __cdecl FUN_002ec620(int* first, int* second, int** third, int** fourth)
{
    *first = DAT_004d1730;
    *second = DAT_004d1734;
    *third = ((int*)&DAT_004d1738);
    *fourth = ((int*)&DAT_004d2738);
    return 0;
}


// 0x002ec650 FUN_002ec650 (300 B): matches/0x002ec650.cpp
// sym: ?FUN_002ec650@fn_fb0f1f83@@YAHPAUinflate_blocks_state_2ec650@1@PAUz_stream_2ec650@1@H@Z
// FUN_002ec650 @ 0x002ec650
int FUN_002ec650(inflate_blocks_state_2ec650 *s, z_stream_2ec650 *z, int r)
{
    unsigned char *p = z->next_out;
    unsigned char *q = s->read;
    unsigned n;

    n = (unsigned)((q <= s->write ? s->write : s->end) - q);
    if (n > z->avail_out)
        n = z->avail_out;
    if (n != 0 && r == -5)
        r = 0;
    z->avail_out -= n;
    z->total_out += n;
    if (s->checkfn != 0)
        z->adler = s->check = s->checkfn(s->check, q, n);
    memcpy(p, q, n);
    p += n;
    q += n;

    if (q == s->end) {
        q = s->window;
        if (s->write == s->end)
            s->write = s->window;
        n = (unsigned)(s->write - q);
        if (n > z->avail_out)
            n = z->avail_out;
        if (n != 0 && r == -5)
            r = 0;
        z->avail_out -= n;
        z->total_out += n;
        if (s->checkfn != 0)
            z->adler = s->check = s->checkfn(s->check, q, n);
        memcpy(p, q, n);
        p += n;
        q += n;
    }

    z->next_out = p;
    s->read = q;
    return r;
}


// 0x002ec780 FUN_002ec780 (869 B): matches/0x002ec780.cpp
// sym: ?inflate_fast@fn_fb0f1f83@@YAHIIPAUinflate_huft_2ec780@1@0PAUinflate_blocks_state_2ec780@1@PAUz_stream_2ec780@1@@Z
// FUN_002ec780 @ 0x002ec780
// zlib inflate_fast
int __cdecl inflate_fast(unsigned int bl, unsigned int bd, inflate_huft_2ec780 *tl, inflate_huft_2ec780 *td,
                         inflate_blocks_state_2ec780 *s, z_stream_2ec780 *z)
{
    inflate_huft_2ec780 *t;
    unsigned int e;
    unsigned int b;
    unsigned int k;
    unsigned char *p;
    unsigned int n;
    unsigned char *q;
    unsigned int m;
    unsigned int ml;
    unsigned int md;
    unsigned int c;
    unsigned int d;
    unsigned char *r;

    p = z->next_in;
    n = z->avail_in;
    b = s->bitb;
    k = s->bitk;
    q = s->write;
    m = (unsigned int)(q < s->read ? s->read - q - 1 : s->end - q);

    ml = ((unsigned int*)&DAT_004d2838)[bl];
    md = ((unsigned int*)&DAT_004d2838)[bd];

    do {
        while (k < 20) {
            n--;
            b |= (unsigned int)(*p++) << k;
            k += 8;
        }
        if ((e = (t = tl + (b & ml))->exop) == 0) {
            b >>= t->bits;
            k -= t->bits;
            *q++ = (unsigned char)t->base;
            m--;
            continue;
        }
        do {
            b >>= t->bits;
            k -= t->bits;
            if (e & 16) {
                e &= 15;
                c = t->base + (b & ((unsigned int*)&DAT_004d2838)[e]);
                b >>= e;
                k -= e;
                while (k < 15) {
                    n--;
                    b |= (unsigned int)(*p++) << k;
                    k += 8;
                }
                e = (t = td + (b & md))->exop;
                do {
                    b >>= t->bits;
                    k -= t->bits;
                    if (e & 16) {
                        e &= 15;
                        while (k < e) {
                            n--;
                            b |= (unsigned int)(*p++) << k;
                            k += 8;
                        }
                        d = t->base + (b & ((unsigned int*)&DAT_004d2838)[e]);
                        b >>= e;
                        k -= e;
                        m -= c;
                        if ((unsigned int)(q - s->window) >= d) {
                            r = q - d;
                            *q++ = *r++;
                            c--;
                            *q++ = *r++;
                            c--;
                        } else {
                            e = d - (unsigned int)(q - s->window);
                            r = s->end - e;
                            if (c > e) {
                                c -= e;
                                do {
                                    *q++ = *r++;
                                } while (--e);
                                r = s->window;
                            }
                        }
                        do {
                            *q++ = *r++;
                        } while (--c);
                        break;
                    } else if ((e & 64) == 0) {
                        t += t->base;
                        e = (t += (b & ((unsigned int*)&DAT_004d2838)[e]))->exop;
                    } else {
                        z->msg = "invalid distance code";
                        c = z->avail_in - n;
                        c = (k >> 3) < c ? k >> 3 : c;
                        n += c;
                        p -= c;
                        k -= c << 3;
                        s->bitb = b;
                        s->bitk = k;
                        z->avail_in = n;
                        z->total_in += (unsigned int)(p - z->next_in);
                        z->next_in = p;
                        s->write = q;
                        return -3;
                    }
                } while (1);
                break;
            }
            if ((e & 64) == 0) {
                t += t->base;
                if ((e = (t += (b & ((unsigned int*)&DAT_004d2838)[e]))->exop) == 0) {
                    b >>= t->bits;
                    k -= t->bits;
                    *q++ = (unsigned char)t->base;
                    m--;
                    break;
                }
            } else if (e & 32) {
                c = z->avail_in - n;
                c = (k >> 3) < c ? k >> 3 : c;
                n += c;
                p -= c;
                k -= c << 3;
                s->bitb = b;
                s->bitk = k;
                z->avail_in = n;
                z->total_in += (unsigned int)(p - z->next_in);
                z->next_in = p;
                s->write = q;
                return 1;
            } else {
                z->msg = "invalid literal/length code";
                c = z->avail_in - n;
                c = (k >> 3) < c ? k >> 3 : c;
                n += c;
                p -= c;
                k -= c << 3;
                s->bitb = b;
                s->bitk = k;
                z->avail_in = n;
                z->total_in += (unsigned int)(p - z->next_in);
                z->next_in = p;
                s->write = q;
                return -3;
            }
        } while (1);
    } while (m >= 258 && n >= 10);

    c = z->avail_in - n;
    c = (k >> 3) < c ? k >> 3 : c;
    n += c;
    p -= c;
    k -= c << 3;
    s->bitb = b;
    s->bitk = k;
    z->avail_in = n;
    z->total_in += (unsigned int)(p - z->next_in);
    z->next_in = p;
    s->write = q;
    return 0;
}


// 0x002ecb70 FUN_002ecb70 (28 B): matches/0x002ecb70.cpp
// sym: _FUN_002ecb70
extern "C" void FUN_002ecb70() {
    (*(unsigned char*)&DAT_00554c0c) = 0;
    DAT_004d287c = 1.0f;
    DAT_004d2880 = 8;
}


// 0x002ecb90 FUN_002ecb90 (213 B): equivalent/0x002ecb90.cpp
// sym: _FUN_002ecb90 @975908f6bdf9 @w81b629c821cf
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_002ecb90 @ 0x002ecb90
extern "C" void __cdecl FUN_002ecb90(unsigned int mode)
{
    if (mode == 8) return;
    switch (mode) {
    case 0: DAT_004d287c = 10.0f; break;
    case 1: DAT_004d287c = 1.0f; break;
    case 2: DAT_004d287c = 0.01f; break;
    case 3: DAT_004d287c = 0.00001f; break;
    case 4: DAT_004d287c = 0.3937f; break;
    case 5: DAT_004d287c = 0.03281f; break;
    case 6: DAT_004d287c = 0.01094f; break;
    case 7: DAT_004d287c = 0.0006214f; break;
    }
    (*(unsigned char*)&DAT_00554c0c) = 1;
    (*(unsigned int*)&DAT_004d2880) = mode;
}


// 0x002ecca0 FUN_002ecca0 (7 B): matches/0x002ecca0.cpp
// sym: ?FUN_002ecca0@fn_fb0f1f83@@YIXPAX@Z
// Same code shape as 0x001b6820 (propagated; names are from that function)
void __fastcall FUN_002ecca0(void* self) {
    *(void**)self = &hulk_at_0043117c;
}


// 0x002eccb0 FUN_002eccb0 (22 B): matches/0x002eccb0.cpp
// sym: ?FUN_002eccb0@fn_fb0f1f83@@YAXXZ
// data: gObj_2eccb0 = DAT_00554c10
void __cdecl FUN_002eccb0() {
    (*(RefCounted**)&DAT_00554c10)->Release();
    (*(RefCounted**)&DAT_00554c10) = 0;
}

} // namespace fn_fb0f1f83

// 0x002eccd0 FUN_002eccd0 (104 B): matches/0x002eccd0.cpp
// sym: ?FUN_002eccd0@Cls_2eccd0@owners@@QAEXM@Z
// data: gEnabled_2eccd0 = DAT_00554c0c, kScale_2eccd0 = DAT_004d287c
void owners::Cls_2eccd0::FUN_002eccd0(float f) {
    a = f;
    if (!DAT_00554c0c)
        return;
    b = (*(const float*)&DAT_004d287c) * f;
    if ((*(PA**)&DAT_0055547c)) {
        (*(PA**)&DAT_0055547c)->s.Do_002f7a60();
        (*(PA**)&DAT_0055547c)->f38 = b;
    } else if ((*(PB**)&DAT_00554c14)) {
        (*(PB**)&DAT_00554c14)->s.Do_002f7a60();
        (*(PB**)&DAT_00554c14)->f80 = b;
    }
}

