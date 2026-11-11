// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002d6bb0..0x002dd760 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fcd359fc {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fcd359fc {} using namespace fn_fcd359fc;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int memcmp(const void*, const void*, unsigned int);
#endif
namespace fn_fcd359fc {
extern "C" void* __cdecl FUN_002e6c00(unsigned int, unsigned int);
} // namespace fn_fcd359fc
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memset(void*, int, unsigned int);
#endif
namespace fn_fcd359fc {
struct Obj_2d6c90 {
    char pad[0x108];
    int value;
};
extern "C" int __cdecl FUN_002e6c80(int, int, int);
class Obj_2d6cb0 {
  public:
    char pad[0x64];
    unsigned int flags;
    char p68[0xA0];
    char p108[12];
    unsigned char flag114;
};
extern "C" unsigned int __cdecl helper(hulk_uintptr, unsigned int, unsigned int);
typedef unsigned int u32_2d6d00;
struct Item_2d6d10 {
    int a;
    void* p;
    int c, d;
};
struct Obj_2d6d10 {
    char pad[0x30];
    int count;
    char pad34[4];
    Item_2d6d10* items;
    char pad3c[0x64];
    void* a0;
    char pada4[8];
    void* ac;
    void** b0;
    char padb4;
    unsigned char b5;
};
extern void __cdecl Process_002e6c40(void* ctx, void* p);
extern void __cdecl Finish_002d6d00(Obj_2d6d10*);
typedef unsigned int U32_2d6dd0;
struct Obj_2d6dd0 {
    char pad[0x5c];
    U32_2d6dd0 value;
};
struct Object { char pad[0x210]; int value; };
int __cdecl FUN_002e6a50(int, int);
void __cdecl FUN_002d6d00(int);
typedef unsigned int u32_2d6ed0;
struct Obj_2d6ed0 {
    char pad[0x214];
    u32_2d6ed0 value;
};
void FUN_002d6d10(Obj_2d6ed0*, int*);
void FUN_002e6ab0(int*, u32_2d6ed0);
extern "C" void __cdecl FUN_002e7fb0(void *);
extern "C" void __cdecl FUN_002d9170(void *, void *);
struct Obj_2d73f0 {
    char pad[0x64];
    u8 flags;
};
struct Head_2d7b60 {
    int w[16];
};
struct PngInfo_2d7b60 {
    Head_2d7b60 head;                 // 0x00 .. 0x40 (jmp_buf), preserved
    int keep40;                // 0x40
    int keep44;                // 0x44
    int keep48;                // 0x48
    char pad4c[0x64 - 0x4c];
    unsigned int flags;        // 0x64
    char pad68[4];
    char zstream[0xa4 - 0x6c]; // 0x6c
    void* f0a4;
    char pada8[0xe0 - 0xa8];
    void* f0e0;
    void* f0e4;
    char pad0e8[0x10c - 0xe8];
    void* f10c;
    char pad110[0x150 - 0x110];
    int bitDepthShift;         // 0x150
    char pad154[0x15c - 0x154];
    void* f15c;
    void* f160;
    void* f164;
    void** table168;
    void** table16c;
    void** table170;
    char pad174[0x180 - 0x174];
    void* f180;
    char pad184[0x1a8 - 0x184];
    void* f1a8;
    char pad1ac[0x1e4 - 0x1ac];
    void* f1e4;
    void* f1e8;
    void* f1ec;
    char pad1f0[0x208 - 0x1f0];
    void* f208;
    char pad20c[0x214 - 0x20c];
    int keep214;               // 0x214
    char pad218[4];
};
void FUN_002d6d10(PngInfo_2d7b60* png, int extra);
void FUN_002e6c40(PngInfo_2d7b60* png, void* ptr);
void thunk_FUN_002e6c40(PngInfo_2d7b60* png, void* ptr);
extern "C" void FUN_002e6e00(void* zstream);
struct Obj_2d7df0 {
    char pad[0x38];
    int field38;
    char rest[0x214 - 0x3c];
    int field214;
};
void F1_002d7b60(Obj_2d7df0*, Obj_2d7df0*, Obj_2d7df0*);
void F2_002e6c40(Obj_2d7df0*, int);
void F3_002e6ab0(Obj_2d7df0*, int);
typedef unsigned int uint_2d7e90;
struct Obj_2d7e90 {
    char pad[8];
    uint_2d7e90 value;
};
typedef unsigned int u32_2d7eb0;
typedef unsigned char u8_2d7f10;
typedef unsigned char u8_2d7f30;
typedef int i32_2d7f30;
typedef unsigned char u8_2d7f70;
typedef unsigned int u32_2d7f70;
typedef unsigned int uint_2d8550;
struct Data_2d8550 {
    char pad0[8];
    unsigned char flags;
    char pad9[7];
    unsigned int value;
    unsigned short size;
};
struct S_2d8630 {
    char p0[8];
    unsigned char f8;
    char p1[0xd];
    unsigned short f16;
    char p2[1];
    unsigned char f19;
    char p3[0x32];
    int f4c;
    int f50;
};
typedef unsigned int u32_2d8820;
struct Thing_2d8820 {
    char pad[0x68];
    u32_2d8820 flags;
};
struct Source_2d9170 {
    char pad0[0x68];
    unsigned int flags;
    char pad6c[0x112 - 0x6c];
    unsigned short count;
    char pad114[0x130 - 0x114];
    unsigned char tag[10];
    char pad13a[0x154 - 0x13a];
    unsigned int value154;
    char pad158[0x1e4 - 0x158];
    void *link;
};
struct Format_2d9170 {
    unsigned int width;
    char pad4[0xc - 4];
    unsigned int rowBytes;
    char pad10[0x16 - 0x10];
    unsigned short w16;
    unsigned char depth;
    unsigned char mode;
    char pad1a[0x1d - 0x1a];
    unsigned char channels;
    unsigned char bits;
    char pad1f[0x28 - 0x1f];
    unsigned int value28;
    char pad2c[0x5a - 0x2c];
    unsigned char tag[10];
};
struct RowInfo_2d92c0 {
 unsigned int width;
 unsigned int rowBytes;
 unsigned char type;
 unsigned char bitDepth;
 unsigned char channels;
 unsigned char pixelDepth;
};
struct RowInfo_2d93f0 {
    unsigned width;
    unsigned rowbytes;
    unsigned char color_type;
    unsigned char bit_depth;
    unsigned char channels;
    unsigned char pixel_depth;
};
struct SigBits {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char gray;
    unsigned char alpha;
};
typedef unsigned char u8_2d95c0;
struct X_2d95c0 {
    int n;
    int count;
    char a;
    unsigned char mode;
    unsigned char width;
    unsigned char bits;
};
struct ImageInfo_2d9610 { unsigned count; unsigned endOffset; unsigned char kind; unsigned char depth; };
struct ImageSpan {
    unsigned int count;
    unsigned int endOffset;
    unsigned char format;
    unsigned char depth;
};
struct RowInfo {
    unsigned width;
    unsigned rowbytes;
    unsigned char color_type;
    unsigned char bit_depth;
    unsigned char channels;
    unsigned char pixel_depth;
};
struct ImageInfo_2d9ae0 {
    unsigned int width;
    unsigned int pitch;
    unsigned char flags;
    unsigned char depth;
    unsigned char channels;
    unsigned char bitsPerPixel;
};
typedef unsigned char png_byte_2d9c30;
typedef unsigned short png_uint_16;
typedef unsigned int png_uint_32;
struct png_row_info_2d9c30 {
    png_uint_32 width;
    png_uint_32 rowbytes;
    png_byte_2d9c30 color_type;
    png_byte_2d9c30 bit_depth;
    png_byte_2d9c30 channels;
    png_byte_2d9c30 pixel_depth;
};
struct png_struct_2d9c30 {
    char pad0[0x150];
    png_uint_16 gamma_shift;           // 0x150
    char pad152[0x160 - 0x152];
    png_byte_2d9c30 *gamma_from_1;            // 0x160
    png_byte_2d9c30 *gamma_to_1;              // 0x164
    char pad168[4];
    png_uint_16 **gamma_16_from_1;     // 0x16c
    png_uint_16 **gamma_16_to_1;       // 0x170
    char pad174[0x219 - 0x174];
    png_byte_2d9c30 rgb_to_gray_red_coeff;    // 0x219
    png_byte_2d9c30 rgb_to_gray_green_coeff;
    png_byte_2d9c30 rgb_to_gray_blue_coeff;
};
struct RowInfo_2db320 {
    unsigned int width;
    unsigned int rowbytes;
    unsigned char color_type;
    unsigned char bit_depth;
    unsigned char channels;
    unsigned char pixel_depth;
};
struct RowInfo_2db6b0 {
    unsigned int width;
    unsigned int rowbytes;
    unsigned char color_type;
    unsigned char bit_depth;
    unsigned char channels;
    unsigned char pixel_depth;
};
struct Color_2db6b0 {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};
struct ImageInfo {
    unsigned int count;         // 0x00 pixels
    unsigned int size;          // 0x04 bytes
    unsigned char mode;         // 0x08
    unsigned char depth;        // 0x09 bits per channel
    unsigned char channels;     // 0x0a
    unsigned char bpp;          // 0x0b bits per pixel
};
struct ColorKey {
    unsigned short w[5];
};
struct ImageInfo_2dbc50 {
    unsigned int count;
    unsigned int byteSize;
    unsigned char format;
    unsigned char bits;
    unsigned char flag;
    unsigned char bitsCopy;
};
struct Gamma {
    char pad00[0x68];
    unsigned int flags;
    char pad6c[0x11e - 0x6c];
    unsigned char b11e;
    unsigned char mode;
    char pad120[0x150 - 0x120];
    unsigned int bits;
    float gamma;
    float scale;
    unsigned char *tab0;
    unsigned char *tab1;
    unsigned char *tab2;
    unsigned short **ptabA;
    unsigned short **ptabB;
    unsigned short **ptabC;
    unsigned char c0;
    unsigned char c1;
    unsigned char c2;
    unsigned char c3;
};
unsigned char *__cdecl FUN_002e6c00(Gamma *g, unsigned int size);
struct Col {
    unsigned char idx;
    unsigned char pad;
    unsigned short r;
    unsigned short g;
    unsigned short b;
    unsigned short gray;
};
struct Pal_2dc3e0 {
    char pad00[0x68];
    unsigned int flags;             // 0x68
    char pad6c[0x10c - 0x6c];
    unsigned char *entries;         // 0x10c, 3 bytes per entry
    unsigned short count;           // 0x110
    unsigned short alphaCount;      // 0x112
    char pad114[0x11e - 0x114];
    unsigned char mode;             // 0x11e
    unsigned char bits;             // 0x11f
    char pad120[0x128 - 0x120];
    unsigned char kind;             // 0x128
    char pad129[3];
    float f12c;
    Col cur;                        // 0x130
    Col out;                        // 0x13a
    char pad144[0x154 - 0x144];
    float f154;
    float f158;
    unsigned char *tab15c;
    unsigned char *tab160;
    unsigned char *tab164;
    char pad168[0x174 - 0x168];
    unsigned char sh0;              // 0x174
    unsigned char sh1;
    unsigned char sh2;
    char pad177[0x180 - 0x177];
    unsigned char *alpha;           // 0x180
};
void __cdecl FUN_002dbd90(Pal_2dc3e0 *p);
struct png_struct_2dcd90;
typedef unsigned char png_byte;
struct png_row_info_2dcd90 {
    unsigned int width;
    unsigned int rowbytes;
    png_byte color_type;
    png_byte bit_depth;
    png_byte channels;
    png_byte pixel_depth;
};
struct png_color_16_2dcd90 {
    unsigned short v[5];
};
struct png_struct_2dcd90 {
    char pad000[0x54];
    void (__cdecl *read_user_transform_fn)(png_struct_2dcd90 *, png_row_info_2dcd90 *, png_byte *);
    char pad058[0x64 - 0x58];
    unsigned int flags;
    unsigned int transformations;
    char pad06c[0xdc - 0x6c];
    unsigned long row_number;
    char pade0[4];
    png_byte *row_buf;
    char pade8[0xf8 - 0xe8];
    png_row_info_2dcd90 row_info;
    char pad104[0x10c - 0x104];
    void *palette;
    char pad110[2];
    unsigned short num_trans;
    char pad114[0x11c - 0x114];
    png_byte pass;
    png_byte pad11d;
    png_byte color_type;
    char pad11f[0x126 - 0x11f];
    unsigned short filler;
    char pad128[0x130 - 0x128];
    png_color_16_2dcd90 background;
    png_color_16_2dcd90 background_1;
    char pad144[0x150 - 0x144];
    int gamma_shift;
    char pad154[0x15c - 0x154];
    void *gamma_table;
    void *gamma_from_1;
    void *gamma_to_1;
    void *gamma_16_table;
    void *gamma_16_from_1;
    void *gamma_16_to_1;
    char pad174[0x179 - 0x174];
    png_byte shift[5];
    char pad17e[0x180 - 0x17e];
    void *trans;
    png_color_16_2dcd90 trans_values;
    char pad18e[0x1e4 - 0x18e];
    void *palette_lookup;
    void *dither_index;
    char pad1ec[0x218 - 0x1ec];
    png_byte rgb_to_gray_status;
};
extern "C" void __cdecl FUN_002e69a0(void *, void *);
extern "C" void * __cdecl FUN_002e69d0(void *, void *);
extern "C" void __cdecl FUN_002db6b0(void *, unsigned char *, void *, unsigned char *, int);
extern "C" void __cdecl FUN_002db8d0(void *, unsigned char *, void *);
extern "C" void __cdecl FUN_002dd3a0(void *, unsigned char *, unsigned int);
extern "C" int __cdecl FUN_002d9c30(void *, void *, unsigned char *);
extern "C" void __cdecl FUN_002d9ae0(void *, unsigned char *);
void __cdecl FUN_002da380(png_row_info_2dcd90 *ri, png_byte *row, png_color_16_2dcd90 *trans_values, png_color_16_2dcd90 *background, png_color_16_2dcd90 *background_1, void *gamma_table, void *gamma_from_1, void *gamma_to_1, void *gamma_16_table, void *gamma_16_from_1, void *gamma_16_to_1, int gamma_shift);
extern "C" void __cdecl FUN_002db320(void *, unsigned char *, unsigned char *, unsigned short **, int);
void __cdecl FUN_002d95c0(png_row_info_2dcd90 *ri, png_byte *row);
extern "C" void __cdecl FUN_002dbc50(void *, unsigned char *, unsigned char *, unsigned char *);
extern "C" void __cdecl FUN_002dd2e0(void *, unsigned char *);
extern "C" void __cdecl FUN_002d93f0(void *, unsigned char *, void *);
extern "C" void __cdecl FUN_002d92c0(void *, unsigned char *);
extern "C" void __cdecl FUN_002dd5c0(void *, unsigned char *);
extern "C" void __cdecl FUN_002dd350(void *, unsigned char *);
extern "C" void __cdecl FUN_002d9840(void *, unsigned char *, unsigned, unsigned);
extern "C" void __cdecl FUN_002d9720(const void *, unsigned char *);
extern "C" void __cdecl FUN_002d9610(const void *, unsigned char *);
void __cdecl FUN_002dd310(png_row_info_2dcd90 *ri, png_byte *row);
struct Obj_2dd1a0 {
    char pad[0x68];
    unsigned int flags;
};
struct Obj_2dd250 {
    char pad0[0x64];
    unsigned int flags64;
    char pad68[0x11e - 0x68];
    unsigned char state;
    unsigned char level;
    char pad120[3];
    unsigned char result;
    char pad124[2];
    unsigned short value;
};
struct Data { char pad[4]; unsigned int length; unsigned char flag; unsigned char mode; };
struct Info {
    int n;
    char pad[5];
    unsigned char type;
    unsigned char count;
};
typedef unsigned char u8_2dd350;
struct Obj_2dd350 {
    char pad[4];
    int count;
    char pad2[1];
    u8_2dd350 mode;
};
struct RowInfo_2dd3a0 {
    unsigned int width;
    unsigned int rowbytes;
    unsigned char color_type;
    unsigned char bit_depth;
    unsigned char channels;
    unsigned char pixel_depth;
};
struct png_row_info_2dd5c0 {
    unsigned int width;
    unsigned int rowbytes;
    unsigned char color_type;
    unsigned char bit_depth;
    unsigned char channels;
    unsigned char pixel_depth;
};
typedef void(__cdecl* ReadFn_2dd690)(void*, void*, unsigned int);
extern "C" void __cdecl Fail_002e69a0(void*, const char*);
struct Obj_2dd690 {
    char pad[0x50];
    ReadFn_2dd690 fn;
};
struct File {
    char pad[0x5c];
    void* handle;
};
extern "C" size_t __cdecl fread(void*, size_t, size_t, void*);
extern "C" void __cdecl report(File*, const char*);
extern "C" void __cdecl FUN_002dd6b0();
typedef unsigned int u32_2dd6f0;
struct Obj_2dd6f0 {
    char pad0[0x4c];
    u32_2dd6f0 field4c;
    hulk_uintptr field50;
    char pad54[8];
    u32_2dd6f0 field5c;
    char pad60[0xe4];
    u32_2dd6f0 field144;
};


// 0x002d6bb0 FUN_002d6bb0 (77 B): matches/0x002d6bb0.cpp
// sym: _FUN_002d6bb0
extern "C" int FUN_002d6bb0(const char* p, unsigned int offset, unsigned int count) {
    if (count > 8)
        count = 8;
    if (count < 1)
        return 0;
    if (offset > 7)
        return 0;
    if (offset + count > 8)
        count = 8 - offset;
    return memcmp(p + offset, ((unsigned char*)&DAT_004d102c) + offset, count);
}


// 0x002d6c20 FUN_002d6c20 (96 B): matches/0x002d6c20.cpp
// sym: ?FUN_002d6c20@fn_fcd359fc@@YAPAIIII@Z
unsigned int* __cdecl FUN_002d6c20(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int n = b * c;
    unsigned int* p = (unsigned int*)FUN_002e6c00(a, n);
    if (n > 0x8000) {
        memset(p, 0, 0x8000);
        memset((char*)p + 0x8000, 0, n - 0x8000);
    } else
        memset(p, 0, n);
    return p;
}

// 0x002d6c80 thunk_FUN_002e6c40 (5 B): not yet verified

// 0x002d6c90 FUN_002d6c90 (25 B): matches/0x002d6c90.cpp
// sym: _FUN_002d6c90
extern "C" void __cdecl FUN_002d6c90(void * self) {
    ((Obj_2d6c90 *)self)->value = FUN_002e6c80(0, 0, 0);
}


// 0x002d6cb0 FUN_002d6cb0 (72 B): matches/0x002d6cb0.cpp
// sym: _FUN_002d6cb0
extern "C" void __cdecl FUN_002d6cb0(Obj_2d6cb0* self, unsigned int a, unsigned int b) {
    if (self->flag114 & 32) {
        if ((self->flags & 0x300) != 0x300)
            goto work;
        return;
    }
    if (self->flags & 0x800)
        return;
work:
    *(unsigned int*)((char*)self + 0x108) = helper(*(unsigned int*)((char*)self + 0x108), a, b);
}


// 0x002d6d00 FUN_002d6d00 (16 B): matches/0x002d6d00.cpp
// sym: ?FUN_002d6d00@fn_fcd359fc@@YAXPAI@Z
void __cdecl FUN_002d6d00(u32_2d6d00* p) {
    for (int i = 0x2e; i != 0; --i)
        *p++ = 0;
}


// 0x002d6d10 FUN_002d6d10 (188 B): matches/0x002d6d10.cpp
// sym: ?Target@fn_fcd359fc@@YAXPAXPAUObj_2d6d10@1@@Z
void __cdecl Target(void* ctx, Obj_2d6d10* s) {
    if (s->items) {
        int i = 0;
        if (s->count > 0) {
            do {
                Process_002e6c40(ctx, s->items[i].p);
                ++i;
            } while (i < s->count);
        }
        Process_002e6c40(ctx, s->items);
    }
    Process_002e6c40(ctx, s->a0);
    Process_002e6c40(ctx, s->ac);
    if (s->b0) {
        int i = 0;
        if (s->b5 > 0) {
            do {
                Process_002e6c40(ctx, s->b0[i]);
                ++i;
            } while (i < (int)s->b5);
        }
        Process_002e6c40(ctx, s->b0);
    }
    Finish_002d6d00(s);
}


// 0x002d6dd0 FUN_002d6dd0 (8 B): matches/0x002d6dd0.cpp
// sym: _FUN_002d6dd0
extern "C" U32_2d6dd0 __cdecl FUN_002d6dd0(Obj_2d6dd0* p) {
    return p->value;
}


// 0x002d6ea0 FUN_002d6ea0 (44 B): equivalent/0x002d6ea0.cpp
// sym: _FUN_002d6ea0 @93e65479bd77 @we6d73391690e
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002d6ea0 @ 0x002d6ea0
extern "C" hulk_intptr __cdecl FUN_002d6ea0(Object* object)
{
    if (!object) return 0;
    int result = FUN_002e6a50(2, object->value);
    if (result) FUN_002d6d00(result);
    return result;
}


// 0x002d6ed0 FUN_002d6ed0 (54 B): matches/0x002d6ed0.cpp
// sym: _FUN_002d6ed0
extern "C" void FUN_002d6ed0(Obj_2d6ed0* self, int** out) {
    if (out && *out) {
        int* p = *out;
        FUN_002d6d10(self, p);
        FUN_002e6ab0(p, self->value);
        *out = 0;
    }
}

} // namespace fn_fcd359fc

// 0x002d6f10 FUN_002d6f10 (307 B): equivalent/0x002d6f10.cpp [wrapped: code differs from its standalone build]
// sym: _FUN_002d6f10 @a1616325fc21 @w9563aae9ed67
namespace fn_002d6f10 {
// STATUS: equivalent (tools/equiv.py level 3: 3107 inputs, branch coverage 21/21)
// FUN_002d6f10 @ 0x002d6f10

struct ZStream_2d6f10 {
    void *next_in;
    unsigned int avail_in;
    unsigned int total_in;
    void *next_out;
    unsigned int avail_out;
    unsigned int total_out;
    char *msg;
    void *state;
    void (*zalloc)();
    void (*zfree)();
    void *opaque;
    char pad2c[0x38 - 0x2c];
};

struct PngStruct_2d6f10 {
    char jmpbuf[0x6c];
    ZStream_2d6f10 zstream;
    void *zbuf;
    unsigned int zbufSize;
};


// the CRT setjmp helper (_setjmp3), named by address
int FUN_00347250(void *jmpbuf, int count);
PngStruct_2d6f10 *FUN_002e6a50(int type, void *mallocFn);
void FUN_002e6c40(PngStruct_2d6f10 *png, void *ptr);
extern "C" void FUN_002e6bf0(PngStruct_2d6f10 *png);
extern "C" void FUN_002e6ba0(PngStruct_2d6f10 *png, void *memPtr, void *mallocFn, void *freeFn);
extern "C" void FUN_002e6970(PngStruct_2d6f10 *png, void *errorPtr, void *errorFn, void *warnFn);
extern "C" void __cdecl FUN_002e69a0(void *, void *);
void *FUN_002e6c00(PngStruct_2d6f10 *png, unsigned int size);
extern "C" int FUN_002e6f50(ZStream_2d6f10 *strm, const char *version, int streamSize);
extern "C++" __declspec(nothrow) void __cdecl FUN_002dd6f0(void *, unsigned int, void *);
void FUN_002d6c20();
void FUN_002d6c80();

extern "C" PngStruct_2d6f10 *FUN_002d6f10(const char *userVersion, void *errorPtr, void *errorFn, void *warnFn,
                        void *memPtr, void *mallocFn, void *freeFn)
{
    PngStruct_2d6f10 *png = FUN_002e6a50(1, mallocFn);
    if (!png)
        return 0;

    if (FUN_00347250(png->jmpbuf, 0)) {
        FUN_002e6c40(png, png->zbuf);
        FUN_002e6bf0(png);
        return 0;
    }

    FUN_002e6ba0(png, memPtr, mallocFn, freeFn);
    FUN_002e6970(png, errorPtr, errorFn, warnFn);

    if (!userVersion || userVersion[0] != DAT_004d1020[0] ||
        (userVersion[0] == '0' && userVersion[2] < '9'))
        FUN_002e69a0((PngStruct_2d6f10 *)png, (void *)(const char *)"Incompatible libpng version in application and library");

    png->zbufSize = 0x2000;
    png->zbuf = FUN_002e6c00(png, 0x2000);
    png->zstream.zalloc = &FUN_002d6c20;
    png->zstream.zfree = &FUN_002d6c80;
    png->zstream.opaque = png;

    switch (FUN_002e6f50(&png->zstream, "1.1.3", 0x38)) {
    case 0:
        break;
    case -4:
    case -2:
        FUN_002e69a0((PngStruct_2d6f10 *)png, (void *)(const char *)"zlib memory error");
        break;
    case -6:
        FUN_002e69a0((PngStruct_2d6f10 *)png, (void *)(const char *)"zlib version error");
        break;
    default:
        FUN_002e69a0((PngStruct_2d6f10 *)png, (void *)(const char *)"Unknown zlib error");
        break;
    }

    png->zstream.next_out = png->zbuf;
    png->zstream.avail_out = png->zbufSize;
    FUN_002dd6f0((PngStruct_2d6f10 *)png, 0, (void *)(hulk_uintptr)(int)0);
    return png;
}
} // namespace fn_002d6f10


// 0x002d7150 FUN_002d7150 (665 B): equivalent/0x002d7150.cpp [wrapped: code differs from its standalone build]
// sym: ?FUN_002d7150@fn_002d7150@@YAXTPngArg@1@PAUPngInfo_2d7150@1@@Z @cf7c9e852bfc @wacfc2f0bba56
namespace fn_002d7150 {
// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 48/48)
// FUN_002d7150 @ 0x002d7150
// libpng png_read_info

struct PngStruct_2d7150 {
    char pad0[0x60];
    unsigned int mode;
    char pad64[0x104 - 0x64];
    unsigned int idatSize;
    char pad108[0x114 - 0x108];
    unsigned int chunk_name;
    char pad118[0x11e - 0x118];
    unsigned char colorType;
    char pad11f[0x124 - 0x11f];
    unsigned char sigBytes;
};

struct PngInfo_2d7150 {
    char pad0[0x20];
    unsigned char signature[8];
};

union PngArg {
    PngStruct_2d7150* png;
    unsigned char buf[4];
};

 // "IHDR"
 // "IDAT"
 // "IEND"
 // "PLTE"
 // "bKGD"
 // "cHRM"
 // "gAMA"
 // "hIST"
 // "oFFs"
 // "pCAL"
 // "pHYs"
 // "sBIT"
 // "sRGB"
 // "tEXt"
 // "tIME"
 // "tRNS"
 // "zTXt"

extern "C++" __declspec(nothrow) void __cdecl FUN_002dd690(void *, void *, unsigned int);
extern "C" unsigned int __cdecl FUN_002e7500(unsigned char *);
extern "C++" __declspec(nothrow) void __cdecl FUN_002d6c90(void *);
void FUN_002e7580(PngStruct_2d7150* png, void* buf, unsigned int n);
extern "C" void __cdecl FUN_002e82a0(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002e69a0(void *, void *);
extern "C" void __cdecl FUN_002e84e0(void *, void *, unsigned int);
void FUN_002e8640(PngStruct_2d7150* png, PngInfo_2d7150* info, unsigned int len);
extern "C" void __cdecl FUN_002e93b0(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002e8940(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002e86a0(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002e9570(void *, void *, int);
extern "C" int __cdecl FUN_002e9790(void *, void *, unsigned);
extern "C" void __cdecl FUN_002e9880(void *, void *, unsigned int);
extern "C" int __cdecl FUN_002e96a0(void *, void *, unsigned);
extern "C" void __cdecl FUN_002e87e0(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002e8f80(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002e9bb0(void *, void *, unsigned int);
extern "C" int __cdecl FUN_002e9ac0(void *, void *, unsigned);
extern "C" void __cdecl FUN_002e91b0(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002e9c60(void *, void *, unsigned);
void FUN_002e9fc0(PngStruct_2d7150* png, PngInfo_2d7150* info, unsigned int len);

extern "C++" __declspec(nothrow) int __cdecl FUN_002d6bb0(const char *, unsigned int, unsigned int);

void FUN_002d7150(PngArg arg, PngInfo_2d7150* info)
{
    PngStruct_2d7150* png = arg.png;
    unsigned int length;

    if (png->sigBytes < 8) {
        unsigned int numChecked = png->sigBytes;
        unsigned int numToCheck = 8 - numChecked;
        FUN_002dd690((PngStruct_2d7150 *)png, info->signature + numChecked, numToCheck);
        png->sigBytes = 8;
        if (FUN_002d6bb0((const char *)(const unsigned char *)(info->signature), numChecked, numToCheck)) {
            if (numChecked < 4 && FUN_002d6bb0((const char *)(const unsigned char *)(info->signature), numChecked, numToCheck - 4))
                FUN_002e69a0((PngStruct_2d7150 *)png, (void *)(const char *)"Not a PNG file");
            else
                FUN_002e69a0((PngStruct_2d7150 *)png, (void *)(const char *)"PNG file corrupted by ASCII conversion");
        }
    }
    for (;;) {
        FUN_002dd690((PngStruct_2d7150 *)png, arg.buf, 4);
        length = FUN_002e7500((unsigned char *)(const void *)(arg.buf));
        FUN_002d6c90((PngStruct_2d7150 *)png);
        FUN_002e7580(png, &png->chunk_name, 4);

        if (png->chunk_name == (*(const unsigned int*)&DAT_004d1034)) {
            FUN_002e82a0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d104c)) {
            FUN_002e84e0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1044)) {
            FUN_002e8640(png, info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d103c)) {
            if ((png->mode & 1) == 0) {
                FUN_002e69a0((PngStruct_2d7150 *)png, (void *)(const char *)"Missing IHDR before IDAT");
            } else if (png->colorType == 3 && (png->mode & 2) == 0) {
                FUN_002e69a0((PngStruct_2d7150 *)png, (void *)(const char *)"Missing PLTE before IDAT");
            }
            png->idatSize = length;
            png->mode |= 4;
            return;
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1054)) {
            FUN_002e93b0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d105c)) {
            FUN_002e8940((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1064)) {
            FUN_002e86a0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d106c)) {
            FUN_002e9570((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, (unsigned int)length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1074)) {
            FUN_002e9790((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, (unsigned int)length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d107c)) {
            FUN_002e9880((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1084)) {
            FUN_002e96a0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, (unsigned int)length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d108c)) {
            FUN_002e87e0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1094)) {
            FUN_002e8f80((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d109c)) {
            FUN_002e9bb0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d10a4)) {
            FUN_002e9ac0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, (unsigned int)length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d10ac)) {
            FUN_002e91b0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d10b4)) {
            FUN_002e9c60((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, (unsigned int)length);
        } else {
            FUN_002e9fc0(png, info, length);
        }
    }
}
} // namespace fn_002d7150

namespace fn_fcd359fc {

// 0x002d73f0 FUN_002d73f0 (36 B): matches/0x002d73f0.cpp
// sym: _FUN_002d73f0
extern "C" void __cdecl FUN_002d73f0(Obj_2d73f0* p, hulk_intptr a) {
    if ((p->flags & 0x40) == 0)
        FUN_002e7fb0(p);
    FUN_002d9170(p, (void *)(hulk_uintptr)(int)a);
}

} // namespace fn_fcd359fc

// 0x002d7440 FUN_002d7440 (1084 B): equivalent/0x002d7440.cpp [wrapped: code differs from its standalone build]
// sym: _FUN_002d7440 @6e851aafeeed @w8e82a2cc4bee
namespace fn_002d7440 {
// STATUS: equivalent (tools/equiv.py level 3: 1832 inputs, branch coverage 92/95, incomplete)
// FUN_002d7440 @ 0x002d7440
// libpng 1.2.x png_read_row, as compiled into the game (zlib 1.2 inflate, Adam7 interlace handling).

struct ZStream_2d7440 {
    unsigned char *next_in;          // 0x00
    unsigned int avail_in;           // 0x04
    unsigned int total_in;
    unsigned char *next_out;         // 0x0c
    unsigned int avail_out;          // 0x10
    unsigned int total_out;
    const char *msg;                 // 0x18
    void *state;
    void *zalloc;
    void *zfree;
    void *opaque;
    int data_type;
    unsigned int adler;
    unsigned int reserved;
};

struct RowInfo_2d7440 {
    unsigned int width;              // 0x00
    unsigned int rowbytes;           // 0x04
    unsigned char color_type;        // 0x08
    unsigned char bit_depth;         // 0x09
    unsigned char channels;          // 0x0a
    unsigned char pixel_depth;       // 0x0b
};

struct PngStruct_2d7440;
typedef void (*ReadRowFn)(PngStruct_2d7440 *png, unsigned int row, int pass);

struct PngStruct_2d7440 {
    char pad00[0x60];
    unsigned int mode;               // 0x60
    unsigned int flags;              // 0x64
    unsigned int transformations;    // 0x68
    ZStream_2d7440 zstream;                 // 0x6c
    unsigned char *zbuf;             // 0xa4
    unsigned int zbuf_size;          // 0xa8
    char padac[0xc0 - 0xac];
    unsigned int width;              // 0xc0
    char padc4[0xd0 - 0xc4];
    unsigned int rowbytes;           // 0xd0
    unsigned int irowbytes;          // 0xd4
    unsigned int iwidth;             // 0xd8
    unsigned int row_number;         // 0xdc
    unsigned char *prev_row;         // 0xe0
    unsigned char *row_buf;          // 0xe4
    char pade8[0xf8 - 0xe8];
    RowInfo_2d7440 row_info;                // 0xf8
    unsigned int idat_size;          // 0x104
    char pad108[0x114 - 0x108];
    unsigned char chunk_name[4];     // 0x114
    char pad118[0x11b - 0x118];
    unsigned char interlaced;        // 0x11b
    unsigned char pass;              // 0x11c
    char pad11d[1];
    unsigned char color_type;        // 0x11e
    unsigned char bit_depth;         // 0x11f
    char pad120[1];
    unsigned char pixel_depth;       // 0x121
    unsigned char channels;          // 0x122
    char pad123[0x190 - 0x123];
    ReadRowFn read_row_fn;           // 0x190
};

           // png_pass_mask
           // png_pass_dsp_mask
   // "IDAT"

extern "C" void __cdecl FUN_002e7fb0(void *);                                   // png_read_start_row
extern "C" void __cdecl FUN_002e7680(PngStruct_2d7440 *png, unsigned char *row, int mask);     // png_combine_row
extern "C" void __cdecl FUN_002ea010(PngStruct_2d7440 *png);                                   // png_read_finish_row
extern "C" void __cdecl FUN_002e69a0(void *, void *);                  // png_error
extern "C" int __cdecl FUN_002e81e0(void *, unsigned int);                // png_crc_finish
extern "C++" __declspec(nothrow) void __cdecl FUN_002dd690(void *, void *, unsigned int);   // png_read_data
extern "C" unsigned int __cdecl FUN_002e7500(unsigned char *);                       // png_get_uint_31
extern "C++" __declspec(nothrow) void __cdecl FUN_002d6c90(void *);                                   // png_reset_crc
void __cdecl FUN_002e7580(PngStruct_2d7440 *png, unsigned char *buf, unsigned int size);   // png_crc_read
extern "C" int __cdecl FUN_002e6f70(ZStream_2d7440 *z, int flush);                             // inflate
extern "C" void __cdecl FUN_002e7dc0(PngStruct_2d7440 *png, RowInfo_2d7440 *info, unsigned char *row, unsigned char *prev, int filter);
extern "C" void __cdecl FUN_002e6b30(PngStruct_2d7440 *png, unsigned char *dst, unsigned char *src, unsigned int size);
void __cdecl FUN_002dcd90(PngStruct_2d7440 *png);                                   // png_do_read_transformations
extern "C" void __cdecl FUN_002e7990(RowInfo_2d7440 *info, unsigned char *row, int pass, unsigned int transformations);

extern "C" void __cdecl FUN_002d7440(PngStruct_2d7440 *png, unsigned char *row, unsigned char *dsp_row)
{
    if (!(png->flags & 0x40))
        FUN_002e7fb0((PngStruct_2d7440 *)png);

    if (png->interlaced && (png->transformations & 2)) {
        switch (png->pass) {
        case 0:
            if (png->row_number & 7) {
                if (dsp_row != 0)
                    FUN_002e7680(png, dsp_row, DAT_004d1148[0]);
                FUN_002ea010(png);
                return;
            }
            break;
        case 1:
            if ((png->row_number & 7) || png->width < 5) {
                if (dsp_row != 0)
                    FUN_002e7680(png, dsp_row, DAT_004d1148[1]);
                FUN_002ea010(png);
                return;
            }
            break;
        case 2:
            if ((png->row_number & 7) != 4) {
                if (dsp_row != 0 && (png->row_number & 4))
                    FUN_002e7680(png, dsp_row, DAT_004d1148[2]);
                FUN_002ea010(png);
                return;
            }
            break;
        case 3:
            if ((png->row_number & 3) || png->width < 3) {
                if (dsp_row != 0)
                    FUN_002e7680(png, dsp_row, DAT_004d1148[3]);
                FUN_002ea010(png);
                return;
            }
            break;
        case 4:
            if ((png->row_number & 3) != 2) {
                if (dsp_row != 0 && (png->row_number & 2))
                    FUN_002e7680(png, dsp_row, DAT_004d1148[4]);
                FUN_002ea010(png);
                return;
            }
            break;
        case 5:
            if ((png->row_number & 1) || png->width < 2) {
                if (dsp_row != 0)
                    FUN_002e7680(png, dsp_row, DAT_004d1148[5]);
                FUN_002ea010(png);
                return;
            }
            break;
        case 6:
            if (!(png->row_number & 1)) {
                FUN_002ea010(png);
                return;
            }
            break;
        }
    }

    if (!(png->mode & 4))
        FUN_002e69a0((PngStruct_2d7440 *)png, (void *)(const char *)"Invalid attempt to read row data");

    png->zstream.next_out = png->row_buf;
    png->zstream.avail_out = png->irowbytes;
    do {
        if (png->zstream.avail_in == 0) {
            while (png->idat_size == 0) {
                unsigned char chunk_length[4];
                FUN_002e81e0((PngStruct_2d7440 *)png, 0);
                FUN_002dd690((PngStruct_2d7440 *)png, (unsigned char *)chunk_length, 4);
                png->idat_size = FUN_002e7500(chunk_length);
                FUN_002d6c90((PngStruct_2d7440 *)png);
                FUN_002e7580(png, png->chunk_name, 4);
                if (*(unsigned int *)png->chunk_name != *(const unsigned int *)((const char*)&DAT_004d103c))
                    FUN_002e69a0((PngStruct_2d7440 *)png, (void *)(const char *)"Not enough image data");
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
            if (png->zstream.avail_out || png->zstream.avail_in || png->idat_size)
                FUN_002e69a0((PngStruct_2d7440 *)png, (void *)(const char *)"Extra compressed data");
            png->mode |= 8;
            png->flags |= 0x20;
            break;
        }
        if (ret != 0)
            FUN_002e69a0((PngStruct_2d7440 *)png, (void *)(const char *)(png->zstream.msg ? png->zstream.msg : "Decompression error"));
    } while (png->zstream.avail_out);

    png->row_info.channels = png->channels;
    png->row_info.pixel_depth = png->pixel_depth;
    png->row_info.rowbytes = (png->pixel_depth * png->iwidth + 7) >> 3;
    png->row_info.color_type = png->color_type;
    png->row_info.width = png->iwidth;
    png->row_info.bit_depth = png->bit_depth;

    FUN_002e7dc0(png, &png->row_info, png->row_buf + 1, png->prev_row + 1, png->row_buf[0]);
    FUN_002e6b30(png, png->prev_row, png->row_buf, png->rowbytes + 1);

    if (png->transformations)
        FUN_002dcd90(png);

    if (png->interlaced && (png->transformations & 2)) {
        if (png->pass < 6)
            FUN_002e7990(&png->row_info, png->row_buf + 1, png->pass, png->transformations);
        if (dsp_row != 0)
            FUN_002e7680(png, dsp_row, DAT_004d1148[png->pass]);
        if (row != 0)
            FUN_002e7680(png, row, DAT_004d112c[png->pass]);
    } else {
        if (row != 0)
            FUN_002e7680(png, row, 0xff);
        if (dsp_row != 0)
            FUN_002e7680(png, dsp_row, 0xff);
    }
    FUN_002ea010(png);

    if (png->read_row_fn != 0)
        png->read_row_fn(png, png->row_number, png->pass);
}
} // namespace fn_002d7440


// 0x002d7980 FUN_002d7980 (477 B): equivalent/0x002d7980.cpp [wrapped: code differs from its standalone build]
// sym: ?FUN_002d7980@fn_002d7980@@YAXPAUPngStruct_2d7980@1@PAUPngInfo@1@@Z @43561fe2da22 @wde15f237f3e7
namespace fn_002d7980 {
// STATUS: equivalent (tools/equiv.py level 3: 100 inputs, branch coverage 40/40)
// FUN_002d7980 @ 0x002d7980
// libpng png_read_info

struct PngStruct_2d7980 {
    char pad0[0x60];
    unsigned int mode;
    char pad64[0x114 - 0x64];
    unsigned int chunk_name;
};

struct PngInfo;

 // "IHDR"
 // "IDAT"
 // "IEND"
 // "PLTE"
 // "bKGD"
 // "cHRM"
 // "gAMA"
 // "hIST"
 // "oFFs"
 // "pCAL"
 // "pHYs"
 // "sBIT"
 // "sRGB"
 // "tEXt"
 // "tIME"
 // "tRNS"
 // "zTXt"

extern "C" int __cdecl FUN_002e81e0(void *, unsigned int);
extern "C++" __declspec(nothrow) void __cdecl FUN_002dd690(void *, void *, unsigned int);
extern "C" unsigned int __cdecl FUN_002e7500(unsigned char *);
extern "C++" __declspec(nothrow) void __cdecl FUN_002d6c90(void *);
void FUN_002e7580(PngStruct_2d7980* png, void* buf, unsigned int n);
extern "C" void __cdecl FUN_002e82a0(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002e69a0(void *, void *);
extern "C" void __cdecl FUN_002e84e0(void *, void *, unsigned int);
void FUN_002e8640(PngStruct_2d7980* png, PngInfo* info, unsigned int len);
extern "C" void __cdecl FUN_002e93b0(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002e8940(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002e86a0(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002e9570(void *, void *, int);
extern "C" int __cdecl FUN_002e9790(void *, void *, unsigned);
extern "C" void __cdecl FUN_002e9880(void *, void *, unsigned int);
extern "C" int __cdecl FUN_002e96a0(void *, void *, unsigned);
extern "C" void __cdecl FUN_002e87e0(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002e8f80(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002e9bb0(void *, void *, unsigned int);
extern "C" int __cdecl FUN_002e9ac0(void *, void *, unsigned);
extern "C" void __cdecl FUN_002e91b0(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002e9c60(void *, void *, unsigned);
void FUN_002e9fc0(PngStruct_2d7980* png, PngInfo* info, unsigned int len);

void FUN_002d7980(PngStruct_2d7980* png, PngInfo* info)
{
    unsigned char buf[4];
    unsigned int length;

    FUN_002e81e0((PngStruct_2d7980 *)png, 0);
    do {
        FUN_002dd690((PngStruct_2d7980 *)png, buf, 4);
        length = FUN_002e7500((unsigned char *)(const void *)buf);
        FUN_002d6c90((PngStruct_2d7980 *)png);
        FUN_002e7580(png, &png->chunk_name, 4);

        if (png->chunk_name == (*(const unsigned int*)&DAT_004d1034)) {
            FUN_002e82a0((PngStruct_2d7980 *)png, (PngInfo *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d103c)) {
            if (length > 0 || (png->mode & 8) != 0) {
                FUN_002e69a0((PngStruct_2d7980 *)png, (void *)(const char *)"Too many IDAT's found");
            } else {
                FUN_002e81e0((PngStruct_2d7980 *)png, 0);
            }
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d104c)) {
            FUN_002e84e0((PngStruct_2d7980 *)png, (PngInfo *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1044)) {
            FUN_002e8640(png, info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1054)) {
            FUN_002e93b0((PngStruct_2d7980 *)png, (PngInfo *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d105c)) {
            FUN_002e8940((PngStruct_2d7980 *)png, (PngInfo *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1064)) {
            FUN_002e86a0((PngStruct_2d7980 *)png, (PngInfo *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d106c)) {
            FUN_002e9570((PngStruct_2d7980 *)png, (PngInfo *)info, (unsigned int)length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1074)) {
            FUN_002e9790((PngStruct_2d7980 *)png, (PngInfo *)info, (unsigned int)length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d107c)) {
            FUN_002e9880((PngStruct_2d7980 *)png, (PngInfo *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1084)) {
            FUN_002e96a0((PngStruct_2d7980 *)png, (PngInfo *)info, (unsigned int)length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d108c)) {
            FUN_002e87e0((PngStruct_2d7980 *)png, (PngInfo *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1094)) {
            FUN_002e8f80((PngStruct_2d7980 *)png, (PngInfo *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d109c)) {
            FUN_002e9bb0((PngStruct_2d7980 *)png, (PngInfo *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d10a4)) {
            FUN_002e9ac0((PngStruct_2d7980 *)png, (PngInfo *)info, (unsigned int)length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d10ac)) {
            FUN_002e91b0((PngStruct_2d7980 *)png, (PngInfo *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d10b4)) {
            FUN_002e9c60((PngStruct_2d7980 *)png, (PngInfo *)info, (unsigned int)length);
        } else {
            FUN_002e9fc0(png, info, length);
        }
    } while ((png->mode & 0x10) == 0);
}
} // namespace fn_002d7980

namespace fn_fcd359fc {

// 0x002d7b60 FUN_002d7b60 (577 B): equivalent/0x002d7b60.cpp
// sym: _FUN_002d7b60 @bf1f3012fd4b @wb6536110d50e
// STATUS: equivalent (tools/equiv.py level 3: 28 inputs, branch coverage 25/28, incomplete)
// FUN_002d7b60 @ 0x002d7b60
// libpng png_read_destroy-style teardown: free every owned buffer, then wipe the struct
// while preserving the jmpbuf header and a few fields.
extern "C" void FUN_002d7b60(PngInfo_2d7b60* png, int a, int b)
{
    if (a)
        FUN_002d6d10(png, a);
    if (b)
        FUN_002d6d10(png, b);

    FUN_002e6c40(png, png->f0a4);
    FUN_002e6c40(png, png->f0e4);
    FUN_002e6c40(png, png->f0e0);
    FUN_002e6c40(png, png->f1e4);
    FUN_002e6c40(png, png->f1e8);
    FUN_002e6c40(png, png->f15c);
    FUN_002e6c40(png, png->f160);
    FUN_002e6c40(png, png->f164);

    if (png->flags & 0x1000)
        thunk_FUN_002e6c40(png, png->f10c);
    if (png->flags & 0x2000)
        FUN_002e6c40(png, png->f180);
    if (png->flags & 0x4000)
        FUN_002e6c40(png, png->f1ec);

    if (png->table168) {
        int n = 1 << (8 - png->bitDepthShift);
        for (int i = 0; i < n; i++)
            FUN_002e6c40(png, png->table168[i]);
        FUN_002e6c40(png, png->table168);
    }
    if (png->table16c) {
        int n = 1 << (8 - png->bitDepthShift);
        for (int i = 0; i < n; i++)
            FUN_002e6c40(png, png->table16c[i]);
        FUN_002e6c40(png, png->table16c);
    }
    if (png->table170) {
        int n = 1 << (8 - png->bitDepthShift);
        for (int i = 0; i < n; i++)
            FUN_002e6c40(png, png->table170[i]);
        FUN_002e6c40(png, png->table170);
    }

    FUN_002e6c40(png, png->f208);
    FUN_002e6e00(png->zstream);
    FUN_002e6c40(png, png->f1a8);

    int k214 = png->keep214;
    int k48 = png->keep48;
    int k40 = png->keep40;
    Head_2d7b60 head = png->head;
    int k44 = png->keep44;
    unsigned int* p = (unsigned int*)png;
    for (int i = 0; i < 0x87; i++)
        p[i] = 0;
    png->keep44 = k44;
    png->keep214 = k214;
    png->head = head;
    png->keep48 = k48;
    png->keep40 = k40;
}


// 0x002d7df0 FUN_002d7df0 (150 B): matches/0x002d7df0.cpp
// sym: ?FUN_002d7df0@fn_fcd359fc@@YAXPAPAUObj_2d7df0@1@00@Z
void FUN_002d7df0(Obj_2d7df0** a, Obj_2d7df0** b, Obj_2d7df0** c) {
    Obj_2d7df0* x = 0;
    Obj_2d7df0* y = 0;
    Obj_2d7df0* z = 0;
    if (a)
        x = *a;
    if (b)
        y = *b;
    if (c)
        z = *c;
    int q = x->field214;
    F1_002d7b60(x, y, z);
    if (y) {
        F2_002e6c40(x, y->field38);
        F3_002e6ab0(y, q);
        *b = 0;
    }
    if (z) {
        F2_002e6c40(x, z->field38);
        F3_002e6ab0(z, q);
        *c = 0;
    }
    F3_002e6ab0(x, q);
    *a = 0;
}


// 0x002d7e90 FUN_002d7e90 (27 B): matches/0x002d7e90.cpp
// sym: _FUN_002d7e90
extern "C" uint_2d7e90 FUN_002d7e90(hulk_intptr handle, Obj_2d7e90* object, uint_2d7e90 mask) {
    if (handle != 0 && object != 0)
        return object->value & mask;
    return 0;
}


// 0x002d7eb0 FUN_002d7eb0 (23 B): matches/0x002d7eb0.cpp
// sym: _FUN_002d7eb0
extern "C" u32_2d7eb0 FUN_002d7eb0(void* a, void* b) {
    if (a && b)
        return *(u32_2d7eb0*)((char*)b + 0xc);
    return 0;
}


// 0x002d7ed0 FUN_002d7ed0 (22 B): matches/0x002d7ed0.cpp
// sym: _FUN_002d7ed0
extern "C" int FUN_002d7ed0(hulk_intptr a, int* b) {
    if (a && b)
        return *b;
    return 0;
}


// 0x002d7ef0 FUN_002d7ef0 (23 B): matches/0x002d7ef0.cpp
// sym: _FUN_002d7ef0
extern "C" int FUN_002d7ef0(hulk_intptr a, hulk_intptr b) {
    if (a && b)
        return *(int*)(b + 4);
    return 0;
}


// 0x002d7f10 FUN_002d7f10 (23 B): matches/0x002d7f10.cpp
// sym: _FUN_002d7f10
extern "C" u8_2d7f10 __cdecl FUN_002d7f10(void* handle, void* object) {
    if (handle != 0 && object != 0)
        return *((u8_2d7f10*)object + 0x18);
    return 0;
}


// 0x002d7f30 FUN_002d7f30 (23 B): matches/0x002d7f30.cpp
// sym: _FUN_002d7f30
extern "C" u8_2d7f30 __cdecl FUN_002d7f30(hulk_intptr a, hulk_intptr b) {
    if (a && b)
        return *(u8_2d7f30*)(b + 0x19);
    return 0;
}


// 0x002d7f70 FUN_002d7f70 (23 B): matches/0x002d7f70.cpp
// sym: _FUN_002d7f70
extern "C" u8_2d7f70 FUN_002d7f70(hulk_uintptr handle, u8_2d7f70* object) {
    if (handle != 0 && object != 0)
        return object[0x1c];
    return 0;
}


// 0x002d8550 FUN_002d8550 (54 B): matches/0x002d8550.cpp
// sym: _FUN_002d8550
extern "C" int __cdecl FUN_002d8550(hulk_intptr a, Data_2d8550* b, unsigned int* out, uint_2d8550* out2) {
    if (a && b && (b->flags & 8) && out) {
        *out = b->value;
        *out2 = (uint_2d8550)b->size;
        return 8;
    }
    return 0;
}


// 0x002d8630 FUN_002d8630 (115 B): matches/0x002d8630.cpp
// sym: _FUN_002d8630
extern "C" int FUN_002d8630(hulk_intptr a, S_2d8630* s, int* o1, unsigned* o2, int* o3) {
    int r = 0;
    if (a != 0 && s != 0 && (s->f8 & 0x10) != 0) {
        if (s->f19 == 3) {
            if (o1 != 0) {
                *o1 = s->f4c;
                r = 0x10;
            }
            if (o3 != 0) {
                *(hulk_intptr*)o3 = (hulk_intptr)&s->f50;
            }
        } else {
            if (o3 != 0) {
                *(hulk_intptr*)o3 = (hulk_intptr)&s->f50;
                r = 0x10;
            }
            if (o1 != 0) {
                *o1 = 0;
            }
        }
        if (o2 != 0) {
            *o2 = s->f16;
            r |= 0x10;
        }
    }
    return r;
}


// 0x002d8820 FUN_002d8820 (12 B): matches/0x002d8820.cpp
// sym: _FUN_002d8820
extern "C" void __cdecl FUN_002d8820(Thing_2d8820* p) {
    p->flags |= 0x400;
}


// 0x002d8830 FUN_002d8830 (12 B): matches/0x002d8830.cpp
// sym: _FUN_002d8830
extern "C" void FUN_002d8830(void* object) {
    *(uint*)((char*)object + 0x68) |= 0x40000;
}


// 0x002d9060 FUN_002d9060 (12 B): matches/0x002d9060.cpp
// sym: _FUN_002d9060
extern "C" void FUN_002d9060(void* p) {
    *(unsigned int*)((char*)p + 0x68) |= 0x1000;
}


// 0x002d9170 FUN_002d9170 (326 B): equivalent/0x002d9170.cpp
// sym: _FUN_002d9170 @474ab52d0bba @w6e250edf9681
// STATUS: equivalent (tools/equiv.py level 3: 116 inputs, branch coverage 50/50)
// FUN_002d9170 @ 0x002d9170
extern "C" void FUN_002d9170(void *src, void * fmt_)
{
    Format_2d9170 * fmt = (Format_2d9170 *)fmt_;
    unsigned char bl = 8;

    if (((Source_2d9170 *)src)->flags & 0x1000) {
        if (fmt->mode == 3) {
            fmt->mode = (((Source_2d9170 *)src)->count != 0) * 4 + 2;
            fmt->depth = bl;
        } else {
            if (((Source_2d9170 *)src)->count != 0)
                fmt->mode = fmt->mode | 4;
            if (fmt->depth < bl)
                fmt->depth = bl;
        }
        fmt->w16 = 0;
    }
    if (((Source_2d9170 *)src)->flags & 0x80) {
        fmt->mode &= 0xfb;
        fmt->w16 = 0;
        for (int i = 0; i < 10; i++)
            fmt->tag[i] = ((Source_2d9170 *)src)->tag[i];
    }
    if (((Source_2d9170 *)src)->flags & 0x2000)
        fmt->value28 = ((Source_2d9170 *)src)->value154;
    if (((Source_2d9170 *)src)->flags & 0x400) {
        if (fmt->depth == 0x10)
            fmt->depth = bl;
    }
    if (((Source_2d9170 *)src)->flags & 0x40) {
        unsigned char m = fmt->mode;
        if ((m == 2 || m == 6) && ((Source_2d9170 *)src)->link != 0 && fmt->depth == bl)
            fmt->mode = 3;
    }
    if (((Source_2d9170 *)src)->flags & 4) {
        if (fmt->depth < bl)
            fmt->depth = bl;
    }
    if (((Source_2d9170 *)src)->flags & 0x4000)
        fmt->mode |= 2;
    if (((Source_2d9170 *)src)->flags & 0x600000)
        fmt->mode &= 0xfd;
    unsigned char m = fmt->mode;
    if (m != 3 && (m & 2))
        fmt->channels = 3;
    else
        fmt->channels = 1;
    if (((Source_2d9170 *)src)->flags & 0x40000) {
        m &= 0xfb;
        fmt->mode = m;
    }
    m = fmt->mode;
    if (m & 4)
        fmt->channels++;
    if (((Source_2d9170 *)src)->flags & 0x8000) {
        if (m == 2 || m == 0)
            fmt->channels++;
    }
    unsigned char bits = (unsigned char)(fmt->depth * fmt->channels);
    fmt->bits = bits;
    fmt->rowBytes = (bits * fmt->width + 7) >> 3;
}


// 0x002d92c0 FUN_002d92c0 (290 B): equivalent/0x002d92c0.cpp
// sym: _FUN_002d92c0 @a9bbe2b9b2d2 @wac30466003d3
// STATUS: equivalent (tools/equiv.py level 3: 2800 inputs, branch coverage 26/26)
// FUN_002d92c0 @ 0x002d92c0
extern "C" void __cdecl FUN_002d92c0(void * info, unsigned char* row) {
 unsigned int depth = ((RowInfo_2d92c0 *)info)->bitDepth;
 if (depth >= 8) return;
 unsigned int width = ((RowInfo_2d92c0 *)info)->width;
 if (width && (depth == 1 || depth == 2 || depth == 4)) {
  unsigned int perByte = 8 / depth;
  unsigned int last = width - 1;
  unsigned char* src = row + last / perByte;
  unsigned char* dst = row + last;
  unsigned int shift = (perByte - 1 - last % perByte) * depth;
  unsigned int mask = (1U << depth) - 1;
  unsigned int remaining = width;
  do {
   *dst = (unsigned char)((*src >> shift) & mask);
   if (shift == 8 - depth) { shift = 0; --src; }
   else shift += depth;
   --dst;
  } while (--remaining);
 }
 unsigned int channels = ((RowInfo_2d92c0 *)info)->channels;
 ((RowInfo_2d92c0 *)info)->bitDepth = 8;
 ((RowInfo_2d92c0 *)info)->pixelDepth = (unsigned char)(channels * 8);
 ((RowInfo_2d92c0 *)info)->rowBytes = channels * width;
}


// 0x002d93f0 FUN_002d93f0 (420 B): equivalent/0x002d93f0.cpp
// sym: _FUN_002d93f0 @0b220912690c @w9472154343f1
// STATUS: equivalent (tools/equiv.py level 3: 7536 inputs, branch coverage 33/37, incomplete; run with --inputs 12000)
// FUN_002d93f0 @ 0x002d93f0
extern "C" void FUN_002d93f0(void *row_info, unsigned char *row, void *sig_bits)
{
    if (((RowInfo_2d93f0 *)row_info)->color_type == 3)
        return;

    int shift[4];
    int channels = 0;
    unsigned short value = 0;
    unsigned row_width = ((RowInfo_2d93f0 *)row_info)->width;

    if (((RowInfo_2d93f0 *)row_info)->color_type & 2) {
        shift[channels++] = ((RowInfo_2d93f0 *)row_info)->bit_depth - ((SigBits *)sig_bits)->red;
        shift[channels++] = ((RowInfo_2d93f0 *)row_info)->bit_depth - ((SigBits *)sig_bits)->green;
        shift[channels++] = ((RowInfo_2d93f0 *)row_info)->bit_depth - ((SigBits *)sig_bits)->blue;
    } else {
        shift[channels++] = ((RowInfo_2d93f0 *)row_info)->bit_depth - ((SigBits *)sig_bits)->gray;
    }
    if (((RowInfo_2d93f0 *)row_info)->color_type & 4)
        shift[channels++] = ((RowInfo_2d93f0 *)row_info)->bit_depth - ((SigBits *)sig_bits)->alpha;

    for (int c = 0; c < channels; c++) {
        if (shift[c] <= 0)
            shift[c] = 0;
        else
            value = 1;
    }
    if (!value)
        return;

    switch (((RowInfo_2d93f0 *)row_info)->bit_depth) {
    default:
        break;
    case 2: {
        unsigned char *bp = row;
        unsigned istop = ((RowInfo_2d93f0 *)row_info)->rowbytes;
        for (unsigned i = 0; i < istop; i++) {
            *bp >>= 1;
            *bp++ &= 0x55;
        }
        break;
    }
    case 4: {
        unsigned char *bp = row;
        unsigned istop = ((RowInfo_2d93f0 *)row_info)->rowbytes;
        unsigned char mask = (unsigned char)((((int)0xf0 >> shift[0]) & (int)0xf0) |
                                             (unsigned char)((int)0xf >> shift[0]));
        for (unsigned i = 0; i < istop; i++) {
            *bp >>= shift[0];
            *bp++ &= mask;
        }
        break;
    }
    case 8: {
        unsigned char *bp = row;
        unsigned istop = row_width * channels;
        for (unsigned i = 0; i < istop; i++)
            *bp++ >>= shift[i % channels];
        break;
    }
    case 16: {
        unsigned char *bp = row;
        unsigned istop = channels * row_width;
        for (unsigned i = 0; i < istop; i++) {
            value = (unsigned short)((*bp << 8) + *(bp + 1));
            value >>= shift[i % channels];
            *bp++ = (unsigned char)(value >> 8);
            *bp++ = (unsigned char)(value & 0xff);
        }
        break;
    }
    }
}


// 0x002d95c0 FUN_002d95c0 (70 B): matches/0x002d95c0.cpp
// sym: ?FUN_002d95c0@fn_fcd359fc@@YAXPAUX_2d95c0@1@PAE@Z
void FUN_002d95c0(X_2d95c0* p, u8_2d95c0* src) {
    if (p->mode == 0x10) {
        unsigned int i = (unsigned int)p->width * (unsigned int)p->n;
        u8_2d95c0* in = src;
        u8_2d95c0* out = src;
        while (i > 0) {
            *out = *in;
            in += 2;
            ++out;
            --i;
        }
        p->mode = 8;
        p->bits = p->width << 3;
        p->count = (int)p->width * p->n;
    }
}


// 0x002d9610 FUN_002d9610 (265 B): equivalent/0x002d9610.cpp
// sym: _FUN_002d9610 @048041024225 @w285332657e6b
// STATUS: equivalent (tools/equiv.py level 3: 1854 inputs, branch coverage 24/24)
// FUN_002d9610 @ 0x002d9610
extern "C" void __cdecl FUN_002d9610(const void * info, unsigned char* buffer) {
    unsigned n = ((const ImageInfo_2d9610 *)info)->count;
    if (((const ImageInfo_2d9610 *)info)->kind != 6 && ((const ImageInfo_2d9610 *)info)->kind != 4) return;
    unsigned char* p = buffer + ((const ImageInfo_2d9610 *)info)->endOffset;
    if (((const ImageInfo_2d9610 *)info)->kind == 6) {
        if (((const ImageInfo_2d9610 *)info)->depth == 8) {
            while (n--) {
                unsigned char a = p[-1];
                unsigned char b = p[-2];
                p[-1] = b;
                p[-2] = p[-3];
                p[-3] = p[-4];
                p[-4] = a;
                p -= 4;
            }
        } else {
            while (n--) {
                unsigned char a = p[-1];
                unsigned char b = p[-2];
                p[-1] = p[-3];
                p[-2] = p[-4];
                p[-3] = p[-5];
                p[-4] = p[-6];
                p[-5] = p[-7];
                p[-6] = p[-8];
                p[-7] = a;
                p[-8] = b;
                p -= 8;
            }
        }
    } else {
        if (((const ImageInfo_2d9610 *)info)->depth == 8) {
            while (n--) {
                unsigned char a = p[-1];
                unsigned char b = p[-2];
                p[-1] = b;
                p[-2] = a;
                p -= 2;
            }
        } else {
            while (n--) {
                unsigned char a = p[-1];
                unsigned char b = p[-2];
                p[-1] = p[-3];
                p[-2] = p[-4];
                p[-3] = a;
                p[-4] = b;
                p -= 4;
            }
        }
    }
}


// 0x002d9720 FUN_002d9720 (284 B): equivalent/0x002d9720.cpp
// sym: _FUN_002d9720 @2444e66e1296 @w970a852b3c7e
// STATUS: equivalent (tools/equiv.py level 3: 1854 inputs, branch coverage 24/24)
// FUN_002d9720 @ 0x002d9720
extern "C" void __cdecl FUN_002d9720(const void * span, unsigned char* buffer)
{
    unsigned int count = ((const ImageSpan *)span)->count;
    unsigned char format = ((const ImageSpan *)span)->format;
    if (format != 6 && format != 4) return;
    unsigned int stride;
    unsigned int alphaBytes;
    if (((const ImageSpan *)span)->depth == 8) {
        stride = format == 6 ? 4 : 2;
        alphaBytes = 1;
    } else {
        stride = format == 6 ? 8 : 4;
        alphaBytes = 2;
    }
    unsigned char* end = buffer + ((const ImageSpan *)span)->endOffset;
    for (unsigned int i = 0; i < count; ++i) {
        for (unsigned int j = 0; j < alphaBytes; ++j) {
            --end;
            *end = (unsigned char)(255 - *end);
        }
        for (unsigned int j = alphaBytes; j < stride; ++j) {
            --end;
            *end = *end;
        }
    }
}


// 0x002d9840 FUN_002d9840 (658 B): equivalent/0x002d9840.cpp
// sym: _FUN_002d9840 @0a37037534d2 @w9ae4b91e7acb
// STATUS: equivalent (tools/equiv.py level 3: 20100 inputs, branch coverage 51/52, incomplete)
// FUN_002d9840 @ 0x002d9840
extern "C" void FUN_002d9840(void *ri, unsigned char *row, unsigned filler, unsigned flags)
{
    unsigned w = ((RowInfo *)ri)->width;
    unsigned char hi = (unsigned char)(filler >> 8);
    unsigned char lo = (unsigned char)filler;
    bool after = (flags & 0x80) != 0;
    unsigned i;

    if (((RowInfo *)ri)->color_type == 0) {
        if (((RowInfo *)ri)->bit_depth == 8) {
            unsigned char *sp = row + w;
            unsigned char *dp = sp + w;
            if (after) {
                for (i = 1; i < w; i++) {
                    *(--dp) = lo;
                    *(--dp) = *(--sp);
                }
                *(--dp) = lo;
            } else {
                for (i = 0; i < w; i++) {
                    *(--dp) = *(--sp);
                    *(--dp) = lo;
                }
            }
            ((RowInfo *)ri)->channels = 2;
            ((RowInfo *)ri)->pixel_depth = 16;
            ((RowInfo *)ri)->rowbytes = w * 2;
        } else if (((RowInfo *)ri)->bit_depth == 16) {
            unsigned char *sp = row + w;
            unsigned char *dp = sp + w;
            if (after) {
                for (i = 1; i < w; i++) {
                    *(--dp) = hi;
                    *(--dp) = lo;
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                }
                *(--dp) = hi;
                *(--dp) = lo;
                ((RowInfo *)ri)->channels = 2;
                ((RowInfo *)ri)->pixel_depth = 32;
                ((RowInfo *)ri)->rowbytes = w * 2;
            } else {
                for (i = 0; i < w; i++) {
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = hi;
                    *(--dp) = lo;
                }
                ((RowInfo *)ri)->channels = 2;
                ((RowInfo *)ri)->pixel_depth = 16;
                ((RowInfo *)ri)->rowbytes = w * 2;
            }
        }
    } else if (((RowInfo *)ri)->color_type == 2) {
        if (((RowInfo *)ri)->bit_depth == 8) {
            unsigned char *sp = row + w * 3;
            unsigned char *dp = sp + w;
            if (after) {
                for (i = 1; i < w; i++) {
                    *(--dp) = lo;
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                }
                *(--dp) = lo;
            } else {
                for (i = 0; i < w; i++) {
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = lo;
                }
            }
            ((RowInfo *)ri)->channels = 4;
            ((RowInfo *)ri)->pixel_depth = 32;
            ((RowInfo *)ri)->rowbytes = w * 4;
        } else if (((RowInfo *)ri)->bit_depth == 16) {
            unsigned char *sp = row + w * 3;
            unsigned char *dp = sp + w;
            if (after) {
                for (i = 1; i < w; i++) {
                    *(--dp) = hi;
                    *(--dp) = lo;
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                }
                *(--dp) = hi;
                *(--dp) = lo;
            } else {
                for (i = 0; i < w; i++) {
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = hi;
                    *(--dp) = lo;
                }
            }
            ((RowInfo *)ri)->channels = 4;
            ((RowInfo *)ri)->pixel_depth = 64;
            ((RowInfo *)ri)->rowbytes = w * 4;
        }
    }
}


// 0x002d9ae0 FUN_002d9ae0 (331 B): equivalent/0x002d9ae0.cpp
// sym: _FUN_002d9ae0 @5a34fb98e7b7 @wd89702a6b367
// STATUS: equivalent (tools/equiv.py level 3: 137 inputs, branch coverage 24/28, incomplete)
// FUN_002d9ae0 @ 0x002d9ae0
// Expands a grayscale (flags 0) or gray+alpha (flags 4) image to RGB(A) in place, walking backwards.
extern "C" void __cdecl FUN_002d9ae0(void *info, unsigned char *data)
{
    unsigned char depth = ((ImageInfo_2d9ae0 *)info)->depth;
    unsigned int width = ((ImageInfo_2d9ae0 *)info)->width;
    if (depth < 8 || (((ImageInfo_2d9ae0 *)info)->flags & 2) != 0)
        return;

    unsigned char flags = ((ImageInfo_2d9ae0 *)info)->flags;
    if (flags == 0) {
        if (depth == 8) {
            unsigned char *s = data + width - 1;
            unsigned char *d = s + width * 2;
            for (unsigned int n = width; n != 0; n--) {
                d[0] = s[0];
                d[-1] = s[0];
                d[-2] = s[0];
                d -= 3;
                s -= 1;
            }
        } else {
            unsigned char *s = data + width * 2 - 1;
            unsigned char *d = s + width * 4;
            for (unsigned int n = width; n != 0; n--) {
                d[0] = s[0];
                d[-1] = s[-1];
                d[-2] = s[0];
                d[-3] = s[-1];
                d[-4] = s[0];
                d[-5] = s[-1];
                d -= 6;
                s -= 2;
            }
        }
    } else if (flags == 4) {
        if (depth == 8) {
            unsigned char *s = data + width * 2 - 1;
            unsigned char *d = s + width * 2;
            for (unsigned int n = width; n != 0; n--) {
                d[0] = s[0];
                d[-1] = s[-1];
                d[-2] = s[-1];
                d[-3] = s[-1];
                d -= 4;
                s -= 2;
            }
        } else {
            unsigned char *s = data + width * 4 - 1;
            unsigned char *d = s + width * 4;
            for (unsigned int n = width; n != 0; n--) {
                d[0] = s[0];
                d[-1] = s[-1];
                d[-2] = s[-2];
                d[-3] = s[-3];
                d[-4] = s[-2];
                d[-5] = s[-3];
                d[-6] = s[-2];
                d[-7] = s[-3];
                d -= 8;
                s -= 4;
            }
        }
    }

    unsigned char channels = ((ImageInfo_2d9ae0 *)info)->channels + 2;
    unsigned char newFlags = ((ImageInfo_2d9ae0 *)info)->flags;
    ((ImageInfo_2d9ae0 *)info)->channels = channels;
    unsigned char bits = (unsigned char)((signed char)((ImageInfo_2d9ae0 *)info)->depth * (signed char)channels);
    ((ImageInfo_2d9ae0 *)info)->flags = newFlags | 2;
    ((ImageInfo_2d9ae0 *)info)->bitsPerPixel = bits;
    ((ImageInfo_2d9ae0 *)info)->pitch = ((unsigned int)bits * width + 7) >> 3;
}


// 0x002d9c30 FUN_002d9c30 (1727 B): equivalent/0x002d9c30.cpp
// sym: _FUN_002d9c30 @7633269e91d2 @w42ce49d63f07
// STATUS: equivalent (tools/equiv.py level 3: 2571 inputs, branch coverage 89/90, incomplete)
// FUN_002d9c30 @ 0x002d9c30
extern "C" int __cdecl FUN_002d9c30(void *png_ptr, void * row_info_, unsigned char *row)
{
    png_row_info_2d9c30 * row_info = (png_row_info_2d9c30 *)row_info_;
    png_uint_32 i;
    png_uint_32 row_width = row_info->width;
    int rgb_error = 0;

    if (row_info->color_type & 2) {
        png_byte_2d9c30 rc = ((png_struct_2d9c30 *)png_ptr)->rgb_to_gray_red_coeff;
        png_byte_2d9c30 gc = ((png_struct_2d9c30 *)png_ptr)->rgb_to_gray_green_coeff;
        png_byte_2d9c30 bc = ((png_struct_2d9c30 *)png_ptr)->rgb_to_gray_blue_coeff;

        if (row_info->color_type == 2) {
            if (row_info->bit_depth == 8) {
                if (((png_struct_2d9c30 *)png_ptr)->gamma_from_1 != 0 && ((png_struct_2d9c30 *)png_ptr)->gamma_to_1 != 0) {
                    png_byte_2d9c30 *sp = row;
                    png_byte_2d9c30 *dp = row;
                    for (i = 0; i < row_width; i++) {
                        png_byte_2d9c30 red = ((png_struct_2d9c30 *)png_ptr)->gamma_to_1[*(sp++)];
                        png_byte_2d9c30 green = ((png_struct_2d9c30 *)png_ptr)->gamma_to_1[*(sp++)];
                        png_byte_2d9c30 blue = ((png_struct_2d9c30 *)png_ptr)->gamma_to_1[*(sp++)];
                        if (red != green || red != blue) {
                            rgb_error |= 1;
                            *(dp++) = ((png_struct_2d9c30 *)png_ptr)->gamma_from_1[(rc * red + gc * green + bc * blue) >> 8];
                        } else {
                            *(dp++) = *(sp - 1);
                        }
                    }
                } else {
                    png_byte_2d9c30 *sp = row;
                    png_byte_2d9c30 *dp = row;
                    for (i = 0; i < row_width; i++) {
                        png_byte_2d9c30 red = *(sp++);
                        png_byte_2d9c30 green = *(sp++);
                        png_byte_2d9c30 blue = *(sp++);
                        if (red != green || red != blue) {
                            rgb_error |= 1;
                            *(dp++) = (png_byte_2d9c30)((rc * red + gc * green + bc * blue) >> 8);
                        } else {
                            *(dp++) = *(sp - 1);
                        }
                    }
                }
            } else {
                if (((png_struct_2d9c30 *)png_ptr)->gamma_16_to_1 != 0 && ((png_struct_2d9c30 *)png_ptr)->gamma_16_from_1 != 0) {
                    png_byte_2d9c30 *sp = row;
                    png_byte_2d9c30 *dp = row;
                    for (i = 0; i < row_width; i++) {
                        png_uint_16 red, green, blue, w;
                        red = (png_uint_16)(((*(sp)) << 8) | *(sp + 1)); sp += 2;
                        green = (png_uint_16)(((*(sp)) << 8) | *(sp + 1)); sp += 2;
                        blue = (png_uint_16)(((*(sp)) << 8) | *(sp + 1)); sp += 2;
                        if (red == green && red == blue) {
                            w = red;
                        } else {
                            png_uint_16 red_1 = ((png_struct_2d9c30 *)png_ptr)->gamma_16_to_1[(red & 0xff) >> ((png_struct_2d9c30 *)png_ptr)->gamma_shift][red >> 8];
                            png_uint_16 green_1 = ((png_struct_2d9c30 *)png_ptr)->gamma_16_to_1[(green & 0xff) >> ((png_struct_2d9c30 *)png_ptr)->gamma_shift][green >> 8];
                            png_uint_16 blue_1 = ((png_struct_2d9c30 *)png_ptr)->gamma_16_to_1[(blue & 0xff) >> ((png_struct_2d9c30 *)png_ptr)->gamma_shift][blue >> 8];
                            png_uint_16 gray16 = (png_uint_16)((rc * red_1 + gc * green_1 + bc * blue_1) >> 8);
                            w = ((png_struct_2d9c30 *)png_ptr)->gamma_16_from_1[(gray16 & 0xff) >> ((png_struct_2d9c30 *)png_ptr)->gamma_shift][gray16 >> 8];
                            rgb_error |= 1;
                        }
                        *(dp++) = (png_byte_2d9c30)((w >> 8) & 0xff);
                        *(dp++) = (png_byte_2d9c30)(w & 0xff);
                    }
                } else {
                    png_byte_2d9c30 *sp = row;
                    png_byte_2d9c30 *dp = row;
                    for (i = 0; i < row_width; i++) {
                        png_uint_16 red, green, blue, gray16;
                        red = (png_uint_16)(((*(sp)) << 8) | *(sp + 1)); sp += 2;
                        green = (png_uint_16)(((*(sp)) << 8) | *(sp + 1)); sp += 2;
                        blue = (png_uint_16)(((*(sp)) << 8) | *(sp + 1)); sp += 2;
                        if (red != green || red != blue)
                            rgb_error |= 1;
                        gray16 = (png_uint_16)((rc * red + gc * green + bc * blue) >> 8);
                        *(dp++) = (png_byte_2d9c30)((gray16 >> 8) & 0xff);
                        *(dp++) = (png_byte_2d9c30)(gray16 & 0xff);
                    }
                }
            }
        }
        if (row_info->color_type == 6) {
            if (row_info->bit_depth == 8) {
                if (((png_struct_2d9c30 *)png_ptr)->gamma_from_1 != 0 && ((png_struct_2d9c30 *)png_ptr)->gamma_to_1 != 0) {
                    png_byte_2d9c30 *sp = row;
                    png_byte_2d9c30 *dp = row;
                    for (i = 0; i < row_width; i++) {
                        png_byte_2d9c30 red = ((png_struct_2d9c30 *)png_ptr)->gamma_to_1[*(sp++)];
                        png_byte_2d9c30 green = ((png_struct_2d9c30 *)png_ptr)->gamma_to_1[*(sp++)];
                        png_byte_2d9c30 blue = ((png_struct_2d9c30 *)png_ptr)->gamma_to_1[*(sp++)];
                        if (red != green || red != blue)
                            rgb_error |= 1;
                        *(dp++) = ((png_struct_2d9c30 *)png_ptr)->gamma_from_1[(rc * red + gc * green + bc * blue) >> 8];
                        *(dp++) = *(sp++);
                    }
                } else {
                    png_byte_2d9c30 *sp = row;
                    png_byte_2d9c30 *dp = row;
                    for (i = 0; i < row_width; i++) {
                        png_byte_2d9c30 red = *(sp++);
                        png_byte_2d9c30 green = *(sp++);
                        png_byte_2d9c30 blue = *(sp++);
                        if (red != green || red != blue)
                            rgb_error |= 1;
                        *(dp++) = (png_byte_2d9c30)((rc * red + gc * green + bc * blue) >> 8);
                        *(dp++) = *(sp++);
                    }
                }
            } else {
                if (((png_struct_2d9c30 *)png_ptr)->gamma_16_to_1 != 0 && ((png_struct_2d9c30 *)png_ptr)->gamma_16_from_1 != 0) {
                    png_byte_2d9c30 *sp = row;
                    png_byte_2d9c30 *dp = row;
                    for (i = 0; i < row_width; i++) {
                        png_uint_16 red, green, blue, w;
                        red = (png_uint_16)(((*(sp)) << 8) | *(sp + 1)); sp += 2;
                        green = (png_uint_16)(((*(sp)) << 8) | *(sp + 1)); sp += 2;
                        blue = (png_uint_16)(((*(sp)) << 8) | *(sp + 1)); sp += 2;
                        if (red == green && red == blue) {
                            w = red;
                        } else {
                            png_uint_16 red_1 = ((png_struct_2d9c30 *)png_ptr)->gamma_16_to_1[(red & 0xff) >> ((png_struct_2d9c30 *)png_ptr)->gamma_shift][red >> 8];
                            png_uint_16 green_1 = ((png_struct_2d9c30 *)png_ptr)->gamma_16_to_1[(green & 0xff) >> ((png_struct_2d9c30 *)png_ptr)->gamma_shift][green >> 8];
                            png_uint_16 blue_1 = ((png_struct_2d9c30 *)png_ptr)->gamma_16_to_1[(blue & 0xff) >> ((png_struct_2d9c30 *)png_ptr)->gamma_shift][blue >> 8];
                            png_uint_16 gray16 = (png_uint_16)((rc * red_1 + gc * green_1 + bc * blue_1) >> 8);
                            w = ((png_struct_2d9c30 *)png_ptr)->gamma_16_from_1[(gray16 & 0xff) >> ((png_struct_2d9c30 *)png_ptr)->gamma_shift][gray16 >> 8];
                            rgb_error |= 1;
                        }
                        *(dp++) = (png_byte_2d9c30)((w >> 8) & 0xff);
                        *(dp++) = (png_byte_2d9c30)(w & 0xff);
                        *(dp++) = *(sp++);
                        *(dp++) = *(sp++);
                    }
                } else {
                    png_byte_2d9c30 *sp = row;
                    png_byte_2d9c30 *dp = row;
                    for (i = 0; i < row_width; i++) {
                        png_uint_16 red, green, blue, gray16;
                        red = (png_uint_16)((*(sp) << 8) | *(sp + 1)); sp += 2;
                        green = (png_uint_16)((*(sp) << 8) | *(sp + 1)); sp += 2;
                        blue = (png_uint_16)((*(sp) << 8) | *(sp + 1)); sp += 2;
                        if (red != green || red != blue)
                            rgb_error |= 1;
                        gray16 = (png_uint_16)((rc * red + gc * green + bc * blue) >> 8);
                        *(dp++) = (png_byte_2d9c30)((gray16 >> 8) & 0xff);
                        *(dp++) = (png_byte_2d9c30)(gray16 & 0xff);
                        *(dp++) = *(sp++);
                        *(dp++) = *(sp++);
                    }
                }
            }
        }
        row_info->channels -= (png_byte_2d9c30)2;
        row_info->color_type &= ~2;
        row_info->pixel_depth = (png_byte_2d9c30)(row_info->channels * row_info->bit_depth);
        row_info->rowbytes = ((row_width * (png_uint_32)row_info->pixel_depth) + 7) >> 3;
    }
    return rgb_error;
}

} // namespace fn_fcd359fc

// 0x002da380 FUN_002da380 (3923 B): equivalent/0x002da380.cpp [wrapped: macros]
// sym: ?FUN_002da380@fn_002da380@@YAXPAUpng_row_info@1@PAEPAUpng_color_16@1@22111PAPAG33H@Z @4974fc0ff557 @w4380dd0d0363
namespace fn_002da380 {
// STATUS: equivalent (tools/equiv.py level 3: 3337 inputs, branch coverage 230/237, incomplete)
// FUN_002da380 @ 0x002da380
typedef unsigned char png_byte;
typedef unsigned short png_uint_16;
typedef unsigned int png_uint_32;
typedef png_byte *png_bytep;
typedef png_uint_16 **png_uint_16pp;


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);
#endif


struct png_color_16 {
    png_byte index;
    png_uint_16 red;
    png_uint_16 green;
    png_uint_16 blue;
    png_uint_16 gray;
};

struct png_row_info {
    png_uint_32 width;
    png_uint_32 rowbytes;
    png_byte color_type;
    png_byte bit_depth;
    png_byte channels;
    png_byte pixel_depth;
};

#define PNG_COLOR_MASK_ALPHA 4
#define PNG_COLOR_TYPE_GRAY 0
#define PNG_COLOR_TYPE_PALETTE 3
#define PNG_COLOR_TYPE_RGB 2
#define PNG_COLOR_TYPE_GRAY_ALPHA 4
#define PNG_COLOR_TYPE_RGB_ALPHA 6

#define png_composite(composite, fg, alpha, bg) \
    { \
        png_uint_16 temp = (png_uint_16)((png_uint_16)(fg) * (png_uint_16)(alpha) + \
                                         (png_uint_16)(bg) * (png_uint_16)(255 - (png_uint_16)(alpha)) + \
                                         (png_uint_16)128); \
        (composite) = (png_byte)((temp + (temp >> 8)) >> 8); \
    }

#define png_composite_16(composite, fg, alpha, bg) \
    { \
        png_uint_32 temp = (png_uint_32)((png_uint_32)(fg) * (png_uint_32)(alpha) + \
                                         (png_uint_32)(bg) * (png_uint_32)(65535L - (png_uint_32)(alpha)) + \
                                         (png_uint_32)32768L); \
        (composite) = (png_uint_16)((temp + (temp >> 16)) >> 16); \
    }

void __cdecl FUN_002da380(png_row_info *row_info, png_bytep row, png_color_16 *trans_values,
                          png_color_16 *background, png_color_16 *background_1, png_bytep gamma_table,
                          png_bytep gamma_from_1, png_bytep gamma_to_1, png_uint_16pp gamma_16,
                          png_uint_16pp gamma_16_from_1, png_uint_16pp gamma_16_to_1, int gamma_shift)
{
    png_bytep sp, dp;
    png_uint_32 i;
    png_uint_32 row_width = row_info->width;
    int shift;

    if (background != 0 &&
        (!(row_info->color_type & PNG_COLOR_MASK_ALPHA) ||
         (row_info->color_type != PNG_COLOR_TYPE_PALETTE && trans_values))) {
        switch (row_info->color_type) {
        case PNG_COLOR_TYPE_GRAY: {
            switch (row_info->bit_depth) {
            case 1: {
                sp = row;
                shift = 7;
                for (i = 0; i < row_width; i++) {
                    if ((png_uint_16)((*sp >> shift) & 0x01) == trans_values->gray) {
                        *sp &= (png_byte)((0x7f7f >> (7 - shift)) & 0xff);
                        *sp |= (png_byte)(background->gray << shift);
                    }
                    if (!shift) {
                        shift = 7;
                        sp++;
                    } else
                        shift--;
                }
                break;
            }
            case 2: {
                if (gamma_table != 0) {
                    sp = row;
                    shift = 6;
                    for (i = 0; i < row_width; i++) {
                        if ((png_uint_16)((*sp >> shift) & 0x03) == trans_values->gray) {
                            *sp &= (png_byte)((0x3f3f >> (6 - shift)) & 0xff);
                            *sp |= (png_byte)(background->gray << shift);
                        } else {
                            png_byte p = (png_byte)((*sp >> shift) & 0x03);
                            png_byte g = (png_byte)((gamma_table[p | (p << 2) | (p << 4) | (p << 6)] >> 6) & 0x03);
                            *sp &= (png_byte)((0x3f3f >> (6 - shift)) & 0xff);
                            *sp |= (png_byte)(g << shift);
                        }
                        if (!shift) {
                            shift = 6;
                            sp++;
                        } else
                            shift -= 2;
                    }
                } else {
                    sp = row;
                    shift = 6;
                    for (i = 0; i < row_width; i++) {
                        if ((png_uint_16)((*sp >> shift) & 0x03) == trans_values->gray) {
                            *sp &= (png_byte)((0x3f3f >> (6 - shift)) & 0xff);
                            *sp |= (png_byte)(background->gray << shift);
                        }
                        if (!shift) {
                            shift = 6;
                            sp++;
                        } else
                            shift -= 2;
                    }
                }
                break;
            }
            case 4: {
                if (gamma_table != 0) {
                    sp = row;
                    shift = 4;
                    for (i = 0; i < row_width; i++) {
                        if ((png_uint_16)((*sp >> shift) & 0x0f) == trans_values->gray) {
                            *sp &= (png_byte)((0xf0f >> (4 - shift)) & 0xff);
                            *sp |= (png_byte)(background->gray << shift);
                        } else {
                            png_byte p = (png_byte)((*sp >> shift) & 0x0f);
                            png_byte g = (png_byte)((gamma_table[p | (p << 4)] >> 4) & 0x0f);
                            *sp &= (png_byte)((0xf0f >> (4 - shift)) & 0xff);
                            *sp |= (png_byte)(g << shift);
                        }
                        if (!shift) {
                            shift = 4;
                            sp++;
                        } else
                            shift -= 4;
                    }
                } else {
                    sp = row;
                    shift = 4;
                    for (i = 0; i < row_width; i++) {
                        if ((png_uint_16)((*sp >> shift) & 0x0f) == trans_values->gray) {
                            *sp &= (png_byte)((0xf0f >> (4 - shift)) & 0xff);
                            *sp |= (png_byte)(background->gray << shift);
                        }
                        if (!shift) {
                            shift = 4;
                            sp++;
                        } else
                            shift -= 4;
                    }
                }
                break;
            }
            case 8: {
                if (gamma_table != 0) {
                    sp = row;
                    for (i = 0; i < row_width; i++, sp++) {
                        if (*sp == trans_values->gray) {
                            *sp = (png_byte)background->gray;
                        } else {
                            *sp = gamma_table[*sp];
                        }
                    }
                } else {
                    sp = row;
                    for (i = 0; i < row_width; i++, sp++) {
                        if (*sp == trans_values->gray) {
                            *sp = (png_byte)background->gray;
                        }
                    }
                }
                break;
            }
            case 16: {
                if (gamma_16 != 0) {
                    sp = row;
                    for (i = 0; i < row_width; i++, sp += 2) {
                        png_uint_16 v;
                        v = (png_uint_16)(((*sp) << 8) + *(sp + 1));
                        if (v == trans_values->gray) {
                            *sp = (png_byte)((background->gray >> 8) & 0xff);
                            *(sp + 1) = (png_byte)(background->gray & 0xff);
                        } else {
                            v = gamma_16[*(sp + 1) >> gamma_shift][*sp];
                            *sp = (png_byte)((v >> 8) & 0xff);
                            *(sp + 1) = (png_byte)(v & 0xff);
                        }
                    }
                } else {
                    sp = row;
                    for (i = 0; i < row_width; i++, sp += 2) {
                        png_uint_16 v;
                        v = (png_uint_16)(((*sp) << 8) + *(sp + 1));
                        if (v == trans_values->gray) {
                            *sp = (png_byte)((background->gray >> 8) & 0xff);
                            *(sp + 1) = (png_byte)(background->gray & 0xff);
                        }
                    }
                }
                break;
            }
            }
            break;
        }
        case PNG_COLOR_TYPE_RGB: {
            if (row_info->bit_depth == 8) {
                if (gamma_table != 0) {
                    sp = row;
                    for (i = 0; i < row_width; i++, sp += 3) {
                        if (*sp == trans_values->red && *(sp + 1) == trans_values->green &&
                            *(sp + 2) == trans_values->blue) {
                            *sp = (png_byte)background->red;
                            *(sp + 1) = (png_byte)background->green;
                            *(sp + 2) = (png_byte)background->blue;
                        } else {
                            *sp = gamma_table[*sp];
                            *(sp + 1) = gamma_table[*(sp + 1)];
                            *(sp + 2) = gamma_table[*(sp + 2)];
                        }
                    }
                } else {
                    sp = row;
                    for (i = 0; i < row_width; i++, sp += 3) {
                        if (*sp == trans_values->red && *(sp + 1) == trans_values->green &&
                            *(sp + 2) == trans_values->blue) {
                            *sp = (png_byte)background->red;
                            *(sp + 1) = (png_byte)background->green;
                            *(sp + 2) = (png_byte)background->blue;
                        }
                    }
                }
            } else {
                if (gamma_16 != 0) {
                    sp = row;
                    for (i = 0; i < row_width; i++, sp += 6) {
                        png_uint_16 r = (png_uint_16)(((*sp) << 8) + *(sp + 1));
                        png_uint_16 g = (png_uint_16)(((*(sp + 2)) << 8) + *(sp + 3));
                        png_uint_16 b = (png_uint_16)(((*(sp + 4)) << 8) + *(sp + 5));
                        if (r == trans_values->red && g == trans_values->green && b == trans_values->blue) {
                            *sp = (png_byte)((background->red >> 8) & 0xff);
                            *(sp + 1) = (png_byte)(background->red & 0xff);
                            *(sp + 2) = (png_byte)((background->green >> 8) & 0xff);
                            *(sp + 3) = (png_byte)(background->green & 0xff);
                            *(sp + 4) = (png_byte)((background->blue >> 8) & 0xff);
                            *(sp + 5) = (png_byte)(background->blue & 0xff);
                        } else {
                            png_uint_16 v = gamma_16[*(sp + 1) >> gamma_shift][*sp];
                            *sp = (png_byte)((v >> 8) & 0xff);
                            *(sp + 1) = (png_byte)(v & 0xff);
                            v = gamma_16[*(sp + 3) >> gamma_shift][*(sp + 2)];
                            *(sp + 2) = (png_byte)((v >> 8) & 0xff);
                            *(sp + 3) = (png_byte)(v & 0xff);
                            v = gamma_16[*(sp + 5) >> gamma_shift][*(sp + 4)];
                            *(sp + 4) = (png_byte)((v >> 8) & 0xff);
                            *(sp + 5) = (png_byte)(v & 0xff);
                        }
                    }
                } else {
                    sp = row;
                    for (i = 0; i < row_width; i++, sp += 6) {
                        png_uint_16 r = (png_uint_16)(((*sp) << 8) + *(sp + 1));
                        png_uint_16 g = (png_uint_16)(((*(sp + 2)) << 8) + *(sp + 3));
                        png_uint_16 b = (png_uint_16)(((*(sp + 4)) << 8) + *(sp + 5));
                        if (r == trans_values->red && g == trans_values->green && b == trans_values->blue) {
                            *sp = (png_byte)((background->red >> 8) & 0xff);
                            *(sp + 1) = (png_byte)(background->red & 0xff);
                            *(sp + 2) = (png_byte)((background->green >> 8) & 0xff);
                            *(sp + 3) = (png_byte)(background->green & 0xff);
                            *(sp + 4) = (png_byte)((background->blue >> 8) & 0xff);
                            *(sp + 5) = (png_byte)(background->blue & 0xff);
                        }
                    }
                }
            }
            break;
        }
        case PNG_COLOR_TYPE_GRAY_ALPHA: {
            if (row_info->bit_depth == 8) {
                if (gamma_to_1 != 0 && gamma_from_1 != 0 && gamma_table != 0) {
                    sp = row;
                    dp = row;
                    for (i = 0; i < row_width; i++, sp += 2, dp++) {
                        png_uint_16 a = *(sp + 1);
                        if (a == 0xff)
                            *dp = gamma_table[*sp];
                        else if (a == 0)
                            *dp = (png_byte)background->gray;
                        else {
                            png_byte v, w;
                            v = gamma_to_1[*sp];
                            png_composite(w, v, a, background_1->gray);
                            *dp = gamma_from_1[w];
                        }
                    }
                } else {
                    sp = row;
                    dp = row;
                    for (i = 0; i < row_width; i++, sp += 2, dp++) {
                        png_byte a = *(sp + 1);
                        if (a == 0xff)
                            *dp = *sp;
                        else if (a == 0)
                            *dp = (png_byte)background->gray;
                        else {
                            png_composite(*dp, *sp, a, background_1->gray);
                        }
                    }
                }
            } else {
                if (gamma_16 != 0 && gamma_16_from_1 != 0 && gamma_16_to_1 != 0) {
                    sp = row;
                    dp = row;
                    for (i = 0; i < row_width; i++, sp += 4, dp += 2) {
                        png_uint_16 a = (png_uint_16)(((*(sp + 2)) << 8) + *(sp + 3));
                        if (a == (png_uint_16)0xffff) {
                            png_uint_16 v;
                            v = gamma_16[*(sp + 1) >> gamma_shift][*sp];
                            *dp = (png_byte)((v >> 8) & 0xff);
                            *(dp + 1) = (png_byte)(v & 0xff);
                        } else if (a == 0) {
                            *dp = (png_byte)((background->gray >> 8) & 0xff);
                            *(dp + 1) = (png_byte)(background->gray & 0xff);
                        } else {
                            png_uint_16 g, v, w;
                            g = gamma_16_to_1[*(sp + 1) >> gamma_shift][*sp];
                            png_composite_16(v, g, a, background_1->gray);
                            w = gamma_16_from_1[(v & 0xff) >> gamma_shift][v >> 8];
                            *dp = (png_byte)((w >> 8) & 0xff);
                            *(dp + 1) = (png_byte)(w & 0xff);
                        }
                    }
                } else {
                    sp = row;
                    dp = row;
                    for (i = 0; i < row_width; i++, sp += 4, dp += 2) {
                        png_uint_16 a = (png_uint_16)(((*(sp + 2)) << 8) + *(sp + 3));
                        if (a == (png_uint_16)0xffff) {
                            memcpy(dp, sp, 2);
                        } else if (a == 0) {
                            *dp = (png_byte)((background->gray >> 8) & 0xff);
                            *(dp + 1) = (png_byte)(background->gray & 0xff);
                        } else {
                            png_uint_16 g, v;
                            g = (png_uint_16)(((*sp) << 8) + *(sp + 1));
                            png_composite_16(v, g, a, background_1->gray);
                            *dp = (png_byte)((v >> 8) & 0xff);
                            *(dp + 1) = (png_byte)(v & 0xff);
                        }
                    }
                }
            }
            break;
        }
        case PNG_COLOR_TYPE_RGB_ALPHA: {
            if (row_info->bit_depth == 8) {
                if (gamma_to_1 != 0 && gamma_from_1 != 0 && gamma_table != 0) {
                    sp = row;
                    dp = row;
                    for (i = 0; i < row_width; i++, sp += 4, dp += 3) {
                        png_byte a = *(sp + 3);
                        if (a == 0xff) {
                            *dp = gamma_table[*sp];
                            *(dp + 1) = gamma_table[*(sp + 1)];
                            *(dp + 2) = gamma_table[*(sp + 2)];
                        } else if (a == 0) {
                            *dp = (png_byte)background->red;
                            *(dp + 1) = (png_byte)background->green;
                            *(dp + 2) = (png_byte)background->blue;
                        } else {
                            png_byte v, w;
                            v = gamma_to_1[*sp];
                            png_composite(w, v, a, background_1->red);
                            *dp = gamma_from_1[w];
                            v = gamma_to_1[*(sp + 1)];
                            png_composite(w, v, a, background_1->green);
                            *(dp + 1) = gamma_from_1[w];
                            v = gamma_to_1[*(sp + 2)];
                            png_composite(w, v, a, background_1->blue);
                            *(dp + 2) = gamma_from_1[w];
                        }
                    }
                } else {
                    sp = row;
                    dp = row;
                    for (i = 0; i < row_width; i++, sp += 4, dp += 3) {
                        png_byte a = *(sp + 3);
                        if (a == 0xff) {
                            *dp = *sp;
                            *(dp + 1) = *(sp + 1);
                            *(dp + 2) = *(sp + 2);
                        } else if (a == 0) {
                            *dp = (png_byte)background->red;
                            *(dp + 1) = (png_byte)background->green;
                            *(dp + 2) = (png_byte)background->blue;
                        } else {
                            png_composite(*dp, *sp, a, background->red);
                            png_composite(*(dp + 1), *(sp + 1), a, background->green);
                            png_composite(*(dp + 2), *(sp + 2), a, background->blue);
                        }
                    }
                }
            } else {
                if (gamma_16 != 0 && gamma_16_from_1 != 0 && gamma_16_to_1 != 0) {
                    sp = row;
                    dp = row;
                    for (i = 0; i < row_width; i++, sp += 8, dp += 6) {
                        png_uint_16 a = (png_uint_16)(((png_uint_16)(*(sp + 6)) << 8) + (png_uint_16)(*(sp + 7)));
                        if (a == (png_uint_16)0xffff) {
                            png_uint_16 v;
                            v = gamma_16[*(sp + 1) >> gamma_shift][*sp];
                            *dp = (png_byte)((v >> 8) & 0xff);
                            *(dp + 1) = (png_byte)(v & 0xff);
                            v = gamma_16[*(sp + 3) >> gamma_shift][*(sp + 2)];
                            *(dp + 2) = (png_byte)((v >> 8) & 0xff);
                            *(dp + 3) = (png_byte)(v & 0xff);
                            v = gamma_16[*(sp + 5) >> gamma_shift][*(sp + 4)];
                            *(dp + 4) = (png_byte)((v >> 8) & 0xff);
                            *(dp + 5) = (png_byte)(v & 0xff);
                        } else if (a == 0) {
                            *dp = (png_byte)((background->red >> 8) & 0xff);
                            *(dp + 1) = (png_byte)(background->red & 0xff);
                            *(dp + 2) = (png_byte)((background->green >> 8) & 0xff);
                            *(dp + 3) = (png_byte)(background->green & 0xff);
                            *(dp + 4) = (png_byte)((background->blue >> 8) & 0xff);
                            *(dp + 5) = (png_byte)(background->blue & 0xff);
                        } else {
                            png_uint_16 v, w, x;
                            v = gamma_16_to_1[*(sp + 1) >> gamma_shift][*sp];
                            png_composite_16(w, v, a, background->red);
                            x = gamma_16_from_1[((w & 0xff) >> gamma_shift)][w >> 8];
                            *dp = (png_byte)((x >> 8) & 0xff);
                            *(dp + 1) = (png_byte)(x & 0xff);
                            v = gamma_16_to_1[*(sp + 3) >> gamma_shift][*(sp + 2)];
                            png_composite_16(w, v, a, background->green);
                            x = gamma_16_from_1[((w & 0xff) >> gamma_shift)][w >> 8];
                            *(dp + 2) = (png_byte)((x >> 8) & 0xff);
                            *(dp + 3) = (png_byte)(x & 0xff);
                            v = gamma_16_to_1[*(sp + 5) >> gamma_shift][*(sp + 4)];
                            png_composite_16(w, v, a, background->blue);
                            x = gamma_16_from_1[((w & 0xff) >> gamma_shift)][w >> 8];
                            *(dp + 4) = (png_byte)((x >> 8) & 0xff);
                            *(dp + 5) = (png_byte)(x & 0xff);
                        }
                    }
                } else {
                    sp = row;
                    dp = row;
                    for (i = 0; i < row_width; i++, sp += 8, dp += 6) {
                        png_uint_16 a = (png_uint_16)(((png_uint_16)(*(sp + 6)) << 8) + (png_uint_16)(*(sp + 7)));
                        if (a == (png_uint_16)0xffff) {
                            memcpy(dp, sp, 6);
                        } else if (a == 0) {
                            *dp = (png_byte)((background->red >> 8) & 0xff);
                            *(dp + 1) = (png_byte)(background->red & 0xff);
                            *(dp + 2) = (png_byte)((background->green >> 8) & 0xff);
                            *(dp + 3) = (png_byte)(background->green & 0xff);
                            *(dp + 4) = (png_byte)((background->blue >> 8) & 0xff);
                            *(dp + 5) = (png_byte)(background->blue & 0xff);
                        } else {
                            png_uint_16 v;
                            png_uint_16 r = (png_uint_16)(((*sp) << 8) + *(sp + 1));
                            png_uint_16 g = (png_uint_16)(((*(sp + 2)) << 8) + *(sp + 3));
                            png_uint_16 b = (png_uint_16)(((*(sp + 4)) << 8) + *(sp + 5));
                            png_composite_16(v, r, a, background->red);
                            *dp = (png_byte)((v >> 8) & 0xff);
                            *(dp + 1) = (png_byte)(v & 0xff);
                            png_composite_16(v, g, a, background->green);
                            *(dp + 2) = (png_byte)((v >> 8) & 0xff);
                            *(dp + 3) = (png_byte)(v & 0xff);
                            png_composite_16(v, b, a, background->blue);
                            *(dp + 4) = (png_byte)((v >> 8) & 0xff);
                            *(dp + 5) = (png_byte)(v & 0xff);
                        }
                    }
                }
            }
            break;
        }
        }

        if (row_info->color_type & PNG_COLOR_MASK_ALPHA) {
            row_info->color_type &= ~PNG_COLOR_MASK_ALPHA;
            row_info->channels--;
            row_info->pixel_depth = (png_byte)(row_info->channels * row_info->bit_depth);
            row_info->rowbytes = ((row_width * row_info->pixel_depth + 7) >> 3);
        }
    }
}
} // namespace fn_002da380
#undef PNG_COLOR_MASK_ALPHA
#undef PNG_COLOR_TYPE_GRAY
#undef PNG_COLOR_TYPE_GRAY_ALPHA
#undef PNG_COLOR_TYPE_PALETTE
#undef PNG_COLOR_TYPE_RGB
#undef PNG_COLOR_TYPE_RGB_ALPHA
#undef png_composite
#undef png_composite_16

namespace fn_fcd359fc {

// 0x002db320 FUN_002db320 (872 B): equivalent/0x002db320.cpp
// sym: _FUN_002db320 @555316f0b912 @w584562675e55
// STATUS: equivalent (tools/equiv.py level 3: 3141 inputs, branch coverage 71/71)
// FUN_002db320 @ 0x002db320
// libpng png_do_gamma
extern "C" void __cdecl FUN_002db320(void *row_info, unsigned char *row, unsigned char *gamma_table,
                          unsigned short **gamma_16_table, int gamma_shift)
{
    unsigned char *sp;
    unsigned int i;
    unsigned int row_width = ((RowInfo_2db320 *)row_info)->width;

    if ((((RowInfo_2db320 *)row_info)->bit_depth <= 8 && gamma_table != 0) || (((RowInfo_2db320 *)row_info)->bit_depth == 16 && gamma_16_table != 0)) {
        switch (((RowInfo_2db320 *)row_info)->color_type) {
        case 2:
            if (((RowInfo_2db320 *)row_info)->bit_depth == 8) {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    *sp = gamma_table[*sp];
                    sp++;
                    *sp = gamma_table[*sp];
                    sp++;
                    *sp = gamma_table[*sp];
                    sp++;
                }
            } else {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    unsigned short v;
                    v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 2;
                    v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 2;
                    v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 2;
                }
            }
            break;
        case 6:
            if (((RowInfo_2db320 *)row_info)->bit_depth == 8) {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    *sp = gamma_table[*sp];
                    sp++;
                    *sp = gamma_table[*sp];
                    sp++;
                    *sp = gamma_table[*sp];
                    sp++;
                    sp++;
                }
            } else {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    unsigned short v;
                    v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 2;
                    v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 2;
                    v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 4;
                }
            }
            break;
        case 4:
            if (((RowInfo_2db320 *)row_info)->bit_depth == 8) {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    *sp = gamma_table[*sp];
                    sp += 2;
                }
            } else {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    unsigned short v;
                    v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 4;
                }
            }
            break;
        case 0:
            if (((RowInfo_2db320 *)row_info)->bit_depth == 2) {
                sp = row;
                for (i = 0; i < row_width; i += 4) {
                    int a = *sp & 0xc0;
                    int b = *sp & 0x30;
                    int c = *sp & 0x0c;
                    int d = *sp & 0x03;
                    *sp = (unsigned char)(((int)gamma_table[a | (a >> 2) | (a >> 4) | (a >> 6)] & 0xc0) |
                                          (((int)gamma_table[(b << 2) | b | (b >> 2) | (b >> 4)] >> 2) & 0x30) |
                                          (((int)gamma_table[(c << 4) | (c << 2) | c | (c >> 2)] >> 4) & 0x0c) |
                                          ((int)gamma_table[(d << 6) | (d << 4) | (d << 2) | d] >> 6));
                    sp++;
                }
            }
            if (((RowInfo_2db320 *)row_info)->bit_depth == 4) {
                sp = row;
                for (i = 0; i < row_width; i += 2) {
                    int msb = *sp & 0xf0;
                    int lsb = *sp & 0x0f;
                    *sp = (unsigned char)((((int)gamma_table[msb | (msb >> 4)]) & 0xf0) |
                                          (((int)gamma_table[(lsb << 4) | lsb]) >> 4));
                    sp++;
                }
            } else if (((RowInfo_2db320 *)row_info)->bit_depth == 8) {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    *sp = gamma_table[*sp];
                    sp++;
                }
            } else if (((RowInfo_2db320 *)row_info)->bit_depth == 16) {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    unsigned short v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 2;
                }
            }
            break;
        }
    }
}


// 0x002db6b0 FUN_002db6b0 (539 B): matches/0x002db6b0.cpp
// sym: _FUN_002db6b0
// FUN_002db6b0 @ 0x002db6b0
extern "C" void FUN_002db6b0(void *row_info, unsigned char *row, void *palette, unsigned char *trans, int num_trans)
{
    unsigned int row_width = ((RowInfo_2db6b0 *)row_info)->width;
    unsigned int i;
    int shift;
    unsigned char *sp;
    unsigned char *dp;

    if (((RowInfo_2db6b0 *)row_info)->color_type != 3)
        return;

    if (((RowInfo_2db6b0 *)row_info)->bit_depth < 8) {
        switch (((RowInfo_2db6b0 *)row_info)->bit_depth) {
        case 1:
            sp = row + ((row_width - 1) >> 3);
            dp = row + row_width - 1;
            shift = 7 - (int)((row_width - 1) & 7);
            for (i = 0; i < row_width; i++) {
                *dp = (unsigned char)((*sp >> shift) & 1);
                if (shift == 7) {
                    shift = 0;
                    sp--;
                } else {
                    shift++;
                }
                dp--;
            }
            break;
        case 2:
            sp = row + ((row_width - 1) >> 2);
            dp = row + row_width - 1;
            shift = (3 - (int)((row_width - 1) & 3)) << 1;
            for (i = 0; i < row_width; i++) {
                *dp = (unsigned char)((*sp >> shift) & 3);
                if (shift == 6) {
                    shift = 0;
                    sp--;
                } else {
                    shift += 2;
                }
                dp--;
            }
            break;
        case 4:
            sp = row + ((row_width - 1) >> 1);
            dp = row + row_width - 1;
            shift = (int)((row_width & 1) << 2);
            for (i = 0; i < row_width; i++) {
                *dp = (unsigned char)((*sp >> shift) & 0xf);
                if (shift == 4) {
                    shift = 0;
                    sp--;
                } else {
                    shift += 4;
                }
                dp--;
            }
            break;
        }
        ((RowInfo_2db6b0 *)row_info)->bit_depth = 8;
        ((RowInfo_2db6b0 *)row_info)->pixel_depth = 8;
        ((RowInfo_2db6b0 *)row_info)->rowbytes = row_width;
    }

    if (((RowInfo_2db6b0 *)row_info)->bit_depth == 8) {
        if (trans != 0) {
            sp = row + row_width - 1;
            dp = row + (row_width << 2) - 1;
            for (i = 0; i < row_width; i++) {
                if ((int)*sp >= num_trans)
                    *dp-- = 0xff;
                else
                    *dp-- = trans[*sp];
                *dp-- = ((Color_2db6b0 *)palette)[*sp].blue;
                *dp-- = ((Color_2db6b0 *)palette)[*sp].green;
                *dp-- = ((Color_2db6b0 *)palette)[*sp].red;
                sp--;
            }
            ((RowInfo_2db6b0 *)row_info)->bit_depth = 8;
            ((RowInfo_2db6b0 *)row_info)->pixel_depth = 32;
            ((RowInfo_2db6b0 *)row_info)->rowbytes = row_width * 4;
            ((RowInfo_2db6b0 *)row_info)->color_type = 6;
            ((RowInfo_2db6b0 *)row_info)->channels = 4;
        } else {
            sp = row + row_width - 1;
            dp = row + (row_width * 3) - 1;
            for (i = 0; i < row_width; i++) {
                *dp-- = ((Color_2db6b0 *)palette)[*sp].blue;
                *dp-- = ((Color_2db6b0 *)palette)[*sp].green;
                *dp-- = ((Color_2db6b0 *)palette)[*sp].red;
                sp--;
            }
            ((RowInfo_2db6b0 *)row_info)->bit_depth = 8;
            ((RowInfo_2db6b0 *)row_info)->pixel_depth = 24;
            ((RowInfo_2db6b0 *)row_info)->rowbytes = row_width * 3;
            ((RowInfo_2db6b0 *)row_info)->color_type = 2;
            ((RowInfo_2db6b0 *)row_info)->channels = 3;
        }
    }
}


// 0x002db8d0 FUN_002db8d0 (894 B): equivalent/0x002db8d0.cpp
// sym: _FUN_002db8d0 @8015fb8930cb @w9cd75d9e0474
// STATUS: equivalent (tools/equiv.py level 3: 2789 inputs, branch coverage 65/76, incomplete)
// FUN_002db8d0 @ 0x002db8d0
extern "C" void FUN_002db8d0(void * im_, unsigned char *buf, void *key)
{
    ImageInfo * im = (ImageInfo *)im_;
    unsigned int count = im->count;
    unsigned int k;
    unsigned int n;
    unsigned char *src;
    unsigned char *dst;

    if (im->mode == 0) {
        if (((ColorKey *)key) != 0)
            k = ((ColorKey *)key)->w[4];
        else
            k = 0;
        unsigned char depth = im->depth;
        if (depth < 8) {
            if (depth == 4) {
                k = k + (k << 4);
                src = buf + ((count - 1) >> 1);
                dst = buf + count - 1;
                unsigned int shift = 4 - (((count - 1) & 1) << 2);
                for (n = count; n != 0; n--) {
                    unsigned int v = (*src >> shift) & 0xf;
                    *dst = (unsigned char)((v << 4) | v);
                    if (shift == 4) {
                        shift = 0;
                        src--;
                    } else {
                        shift = 4;
                    }
                    dst--;
                }
                im = im;
            } else if (depth == 2) {
                k = k * 0x55;
                src = buf + ((count - 1) >> 2);
                dst = buf + count - 1;
                unsigned int shift = (3 - ((count - 1) & 3)) << 1;
                for (n = count; n != 0; n--) {
                    unsigned int v = (*src >> shift) & 3;
                    unsigned char b = (unsigned char)v;
                    b = (unsigned char)((b << 2) | v);
                    b = (unsigned char)((b << 2) | v);
                    b = (unsigned char)((b << 2) | v);
                    *dst = b;
                    if (shift == 6) {
                        shift = 0;
                        src--;
                    } else {
                        shift += 2;
                    }
                    dst--;
                }
            } else if (depth == 1) {
                k = k * 0xff;
                src = buf + ((count - 1) >> 3);
                unsigned int shift = 7 - ((count - 1) & 7);
                dst = buf + count - 1;
                unsigned int saved = k;
                for (n = count; n != 0; n--) {
                    unsigned char bit = (unsigned char)((*src >> shift) & 1);
                    unsigned int m = bit ? 0xff : 0;
                    *dst = (unsigned char)m;
                    if (shift == 7) {
                        shift = 0;
                        src--;
                    } else {
                        shift++;
                    }
                    dst--;
                }
                k = saved;
            }
            im->depth = 8;
            im->bpp = 8;
            im->size = count;
        }
        if (((ColorKey *)key) == 0)
            return;
        unsigned char d = im->depth;
        if (d == 8) {
            src = buf + count - 1;
            dst = buf + count * 2 - 1;
            for (n = count; n != 0; n--) {
                unsigned short c = *src;
                if (c == (unsigned short)k)
                    *dst = 0;
                else
                    *dst = 0xff;
                dst--;
                *dst = *src;
                dst--;
                src--;
            }
        } else if (d == 16) {
            unsigned int size = im->size;
            src = buf + size - 1;
            dst = buf + size * 2 - 1;
            for (n = count; n != 0; n--) {
                unsigned int v = (src[-1] << 8) | src[0];
                unsigned char a;
                if (v == (unsigned short)k)
                    a = 0;
                else
                    a = 0xff;
                dst[0] = a;
                dst[-1] = a;
                dst[-2] = src[0];
                dst[-3] = src[-1];
                dst -= 4;
                src -= 2;
            }
        }
        unsigned char b = (unsigned char)(im->depth << 1);
        im->mode = 4;
        im->channels = 2;
        im->bpp = b;
        im->size = (b * count) >> 3;
        return;
    }
    if (im->mode != 2)
        return;
    if (((ColorKey *)key) == 0)
        return;
    unsigned char d = im->depth;
    if (d == 8) {
        src = buf + im->size - 1;
        dst = buf + count * 4 - 1;
        for (n = count; n != 0; n--) {
            unsigned short r = src[-2];
            unsigned short g = src[-1];
            unsigned short bl = src[0];
            unsigned char a;
            if (r == ((ColorKey *)key)->w[1] && g == ((ColorKey *)key)->w[2] && bl == ((ColorKey *)key)->w[3])
                a = 0;
            else
                a = 0xff;
            dst[0] = a;
            dst[-1] = src[0];
            dst[-2] = src[-1];
            dst[-3] = src[-2];
            dst -= 4;
            src -= 3;
        }
    } else if (d == 16) {
        src = buf + im->size - 1;
        dst = buf + count * 8 - 1;
        for (n = count; n != 0; n--) {
            unsigned char a;
            if (((src[-5] << 8) | src[-4]) == ((ColorKey *)key)->w[1] && ((src[-3] << 8) | src[-2]) == ((ColorKey *)key)->w[2] &&
                ((src[-1] << 8) | src[0]) == ((ColorKey *)key)->w[3])
                a = 0;
            else
                a = 0xff;
            dst[0] = a;
            dst[-1] = a;
            dst[-2] = src[0];
            dst[-3] = src[-1];
            dst[-4] = src[-2];
            dst[-5] = src[-3];
            dst[-6] = src[-4];
            dst[-7] = src[-5];
            dst -= 8;
            src -= 6;
        }
    }
    unsigned char b = (unsigned char)(im->depth << 2);
    im->mode = 6;
    im->channels = 4;
    im->bpp = b;
    im->size = (b * count) >> 3;
}


// 0x002dbc50 FUN_002dbc50 (306 B): equivalent/0x002dbc50.cpp
// sym: _FUN_002dbc50 @127b7d6f612a @w83c5641cbd0b
// STATUS: equivalent (tools/equiv.py level 3: 12061 inputs, branch coverage 30/30; run with --inputs 12000)
// FUN_002dbc50 @ 0x002dbc50
extern "C" void FUN_002dbc50(void *info, unsigned char *data, unsigned char *rgbToIndex, unsigned char *remap)
{
    unsigned int count = ((ImageInfo_2dbc50 *)info)->count;

    if ((((ImageInfo_2dbc50 *)info)->format == 2 || ((ImageInfo_2dbc50 *)info)->format == 6) && rgbToIndex != 0 && ((ImageInfo_2dbc50 *)info)->bits == 8) {
        unsigned int stride = (((ImageInfo_2dbc50 *)info)->format == 2) ? 3 : 4;
        unsigned char *src = data;
        unsigned char *dst = data;
        unsigned int n;
        for (n = count; n != 0; n--) {
            unsigned int idx = (((src[0] & 0xf8) << 5) | (src[1] & 0xf8)) << 2;
            idx |= (src[2] >> 3) & 0x1f;
            *dst = rgbToIndex[idx];
            dst++;
            src += stride;
        }
        ((ImageInfo_2dbc50 *)info)->bitsCopy = ((ImageInfo_2dbc50 *)info)->bits;
        ((ImageInfo_2dbc50 *)info)->format = 3;
        ((ImageInfo_2dbc50 *)info)->flag = 1;
        ((ImageInfo_2dbc50 *)info)->byteSize = (((ImageInfo_2dbc50 *)info)->bitsCopy * count + 7) >> 3;
        return;
    }
    if (((ImageInfo_2dbc50 *)info)->format == 3 && remap != 0 && ((ImageInfo_2dbc50 *)info)->bits == 8) {
        unsigned int n;
        unsigned char *p = data;
        for (n = count; n != 0; n--) {
            *p = remap[*p];
            p++;
        }
    }
}


// 0x002dbd90 FUN_002dbd90 (1615 B): equivalent/0x002dbd90.cpp
// sym: ?FUN_002dbd90@fn_fcd359fc@@YAXPAUGamma@1@@Z @fc728c88a8a1 @w5cbbc353a908
// STATUS: equivalent (tools/equiv.py level 3: 106 inputs, branch coverage 62/80, incomplete)
// FUN_002dbd90 @ 0x002dbd90
void FUN_002dbd90(Gamma *g)
{
    if (g->gamma == 0.0)
        return;
    if (g->mode <= 8) {
        double e;
        if (g->scale > 1e-6)
            e = 1.0 / (g->scale * g->gamma);
        else
            e = 1.0;
        g->tab0 = FUN_002e6c00(g, 0x100);
        for (int i = 0; i < 0x100; i++)
            g->tab0[i] = (unsigned char)(int)(pow(i * 0.00392156862745098, e) * 255.0 + 0.5);
        if (!(g->flags & 0x600080))
            return;
        double e2 = 1.0 / g->gamma;
        g->tab2 = FUN_002e6c00(g, 0x100);
        for (int i = 0; i < 0x100; i++)
            g->tab2[i] = (unsigned char)(int)(pow(i * 0.00392156862745098, e2) * 255.0 + 0.5);
        g->tab1 = FUN_002e6c00(g, 0x100);
        double e3;
        if (g->scale > 1e-6)
            e3 = 1.0 / g->scale;
        else
            e3 = g->gamma;
        for (int i = 0; i < 0x100; i++)
            g->tab1[i] = (unsigned char)(int)(pow(i * 0.00392156862745098, e3) * 255.0 + 0.5);
        return;
    }

    int c;
    if (g->b11e & 2) {
        c = g->c0;
        if (g->c1 > c)
            c = g->c1;
        if (g->c2 > c)
            c = g->c2;
    } else {
        c = g->c3;
    }
    int bits;
    if (c > 0)
        bits = 0x10 - c;
    else
        bits = 0;
    if ((g->flags & 0x400) && bits < 5)
        bits = 5;
    else if (bits > 8)
        bits = 8;
    else if (bits < 0)
        bits = 0;
    g->bits = (unsigned char)bits;
    int shift = 8 - bits;
    int count = 1 << shift;
    double d;
    if (g->scale > 1e-6)
        d = 1.0 / (g->scale * g->gamma);
    else
        d = 1.0;
    g->ptabA = (unsigned short **)FUN_002e6c00(g, count * 4);
    unsigned int edi = 0;
    if (g->flags & 0x480) {
        for (int i = 0; i < count; i++)
            g->ptabA[i] = (unsigned short *)FUN_002e6c00(g, 0x200);
        double invd = 1.0 / d;
        unsigned int n = count << 8;
        double dn = (double)n;
        edi = 0;
        for (int j = 0; j < 0x100; j++) {
            unsigned int end = (unsigned int)(int)(pow((j + 0.5) * 0.00390625, invd) * dn);
            if (!(edi > end)) {
                unsigned short v = (unsigned short)((j << 8) | j);
                int mask = 0xff >> bits;
                do {
                    g->ptabA[mask & edi][edi >> shift] = v;
                    edi++;
                } while (edi <= end);
            }
        }
        if (edi < n) {
            int mask = 0xff >> bits;
            do {
                g->ptabA[mask & edi][edi >> shift] = 0xffff;
                edi++;
            } while (edi < n);
        }
    } else {
        if (count > 0) {
            int i = 0;
            do {
                g->ptabA[i] = (unsigned short *)FUN_002e6c00(g, 0x200);
                unsigned int base = (((unsigned int*)&DAT_004d1164)[bits] * i) >> 4;
                unsigned int k = 0;
                do {
                    g->ptabA[i][k / 2] = (unsigned short)(int)(pow((double)base * 1.5259021896696422e-05, d) * 65535.0 + 0.5);
                    k += 2;
                    base += 0x100;
                } while (k < 0x200);
                i++;
            } while (i < count);
        }
    }
    if (!(g->flags & 0x600080))
        return;
    double e4 = 1.0 / g->gamma;
    g->ptabC = (unsigned short **)FUN_002e6c00(g, count * 4);
    if (count > 0) {
        int i = 0;
        do {
            g->ptabC[i] = (unsigned short *)FUN_002e6c00(g, 0x200);
            unsigned int base = (((unsigned int*)&DAT_004d1164)[bits] * i) >> 4;
            unsigned int k = 0;
            do {
                g->ptabC[i][k / 2] = (unsigned short)(int)(pow((double)base * 1.5259021896696422e-05, e4) * 65535.0 + 0.5);
                k += 2;
                base += 0x100;
            } while (k < 0x200);
            i++;
        } while (i < count);
    }
    double e5;
    if (g->scale > 1e-6)
        e5 = 1.0 / g->scale;
    else
        e5 = g->gamma;
    g->ptabB = (unsigned short **)FUN_002e6c00(g, count * 4);
    if (count > 0) {
        int i = 0;
        do {
            g->ptabB[i] = (unsigned short *)FUN_002e6c00(g, 0x200);
            unsigned int base = (((unsigned int*)&DAT_004d1164)[bits] * i) >> 4;
            unsigned int k = 0;
            do {
                g->ptabB[i][k / 2] = (unsigned short)(int)(pow((double)base * 1.5259021896696422e-05, e5) * 65535.0 + 0.5);
                k += 2;
                base += 0x100;
            } while (k < 0x200);
            i++;
        } while (i < count);
    }
}


// 0x002dc3e0 FUN_002dc3e0 (2429 B): equivalent/0x002dc3e0.cpp
// sym: ?FUN_002dc3e0@fn_fcd359fc@@YAXPAUPal_2dc3e0@1@@Z @b026280774ab @wb7e20331dee0
// STATUS: equivalent (tools/equiv.py level 3: 3046 inputs, branch coverage 90/95, incomplete)
// FUN_002dc3e0 @ 0x002dc3e0
void FUN_002dc3e0(Pal_2dc3e0 *p)
{
    unsigned int mode = p->mode;
    unsigned int flags = p->flags;
    int i;

    if (flags & 0x100) {
        if (!(mode & 2)) {
            switch (p->bits) {
            case 1: {
                unsigned short g = (unsigned short)(p->cur.gray * 0xff);
                p->cur.gray = g;
                p->cur.b = g;
                p->cur.g = g;
                p->cur.r = g;
                break;
            }
            case 2: {
                unsigned short g = (unsigned short)(p->cur.gray * 0x55);
                p->cur.gray = g;
                p->cur.b = g;
                p->cur.g = g;
                p->cur.r = g;
                break;
            }
            case 4: {
                unsigned short g = (unsigned short)(p->cur.gray * 0x11);
                p->cur.gray = g;
                p->cur.b = g;
                p->cur.g = g;
                p->cur.r = g;
                break;
            }
            case 8:
            case 16: {
                unsigned short g = p->cur.gray;
                p->cur.b = g;
                p->cur.g = g;
                p->cur.r = g;
                break;
            }
            }
        } else if (mode == 3) {
            unsigned char *e = p->entries + p->cur.idx * 3;
            p->cur.r = e[0];
            p->cur.g = e[1];
            p->cur.b = e[2];
            if ((flags & 0x80000) && !(flags & 0x1000)) {
                int n = p->alphaCount;
                for (i = 0; i < n; i++)
                    p->alpha[i] = 0xff - p->alpha[i];
            }
        }
    }

    p->out = p->cur;

    flags = p->flags;
    if (flags & 0x602000) {
        FUN_002dbd90(p);
        if (p->flags & 0x80) {
            if (mode == 3) {
                int count = p->count;
                double A, B;
                unsigned char c0, c1, c2, d0, d1, d2;
                if (p->kind == 2) {
                    unsigned char *t = p->tab15c;
                    c0 = t[p->cur.r];
                    c1 = t[p->cur.g];
                    c2 = t[p->cur.b];
                    unsigned char *u = p->tab164;
                    d0 = u[p->cur.r];
                    d1 = u[p->cur.g];
                    d2 = u[p->cur.b];
                } else {
                    switch (p->kind) {
                    case 1:
                        A = p->f158;
                        B = 1.0;
                        break;
                    case 2:
                        A = 1.0 / p->f154;
                        B = 1.0 / ((double)p->f158 * p->f154);
                        break;
                    case 3:
                        A = 1.0 / p->f12c;
                        B = 1.0 / ((double)p->f158 * p->f12c);
                        break;
                    default:
                        A = 1.0;
                        B = 1.0;
                        break;
                    }
                    if (fabs(B - 1.0) < 0.05) {
                        c0 = (unsigned char)p->cur.r;
                        c1 = (unsigned char)p->cur.g;
                        c2 = (unsigned char)p->cur.b;
                    } else {
                        c0 = (unsigned char)(int)(pow(p->cur.r * 0.00392156862745098, B) * 255.0 + 0.5);
                        c1 = (unsigned char)(int)(pow(p->cur.g * 0.00392156862745098, B) * 255.0 + 0.5);
                        c2 = (unsigned char)(int)(pow(p->cur.b * 0.00392156862745098, B) * 255.0 + 0.5);
                    }
                    d0 = (unsigned char)(int)(pow(p->cur.r * 0.00392156862745098, A) * 255.0 + 0.5);
                    d1 = (unsigned char)(int)(pow(p->cur.g * 0.00392156862745098, A) * 255.0 + 0.5);
                    d2 = (unsigned char)(int)(pow(p->cur.b * 0.00392156862745098, A) * 255.0 + 0.5);
                }
                unsigned char *pal = p->entries;
                for (i = 0; i < count; i++) {
                    unsigned char *e = pal + i * 3;
                    if (i >= p->alphaCount || p->alpha[i] == 0xff) {
                        e[0] = p->tab15c[e[0]];
                        e[1] = p->tab15c[e[1]];
                        e[2] = p->tab15c[e[2]];
                    } else if (p->alpha[i] == 0) {
                        e[0] = c0;
                        e[1] = c1;
                        e[2] = c2;
                    } else {
                        unsigned int a = p->alpha[i];
                        unsigned int s = (unsigned short)(p->tab164[e[0]] * a + (0xff - a) * d0 + 0x80);
                        e[0] = p->tab160[(unsigned char)(((s >> 8) + s) >> 8)];
                        a = p->alpha[i];
                        s = (unsigned short)(p->tab164[e[1]] * a + (0xff - a) * d1 + 0x80);
                        e[1] = p->tab160[(unsigned char)(((s >> 8) + s) >> 8)];
                        a = p->alpha[i];
                        s = (unsigned short)(p->tab164[e[2]] * a + (0xff - a) * d2 + 0x80);
                        e[2] = p->tab160[(unsigned char)(((s >> 8) + s) >> 8)];
                    }
                }
            } else {
                unsigned int m = (1u << p->bits) - 1;
                double M = (double)m;
                double C0 = 1.0;
                double C1 = 1.0;
                switch (p->kind) {
                case 1:
                    C0 = p->f158;
                    C1 = 1.0;
                    break;
                case 2:
                    C0 = 1.0 / p->f154;
                    C1 = 1.0 / ((double)p->f158 * p->f154);
                    break;
                case 3:
                    C0 = 1.0 / p->f12c;
                    C1 = 1.0 / ((double)p->f158 * p->f12c);
                    break;
                }
                if (mode & 2) {
                    double inv = 1.0 / M;
                    double v1 = p->cur.r * inv;
                    p->out.r = (unsigned short)(int)(pow(v1, C0) * M + 0.5);
                    double v2 = p->cur.g * inv;
                    p->out.g = (unsigned short)(int)(pow(v2, C0) * M + 0.5);
                    double v3 = p->cur.b * inv;
                    p->out.b = (unsigned short)(int)(pow(v3, C0) * M + 0.5);
                    p->cur.r = (unsigned short)(int)(pow(v1, C1) * M + 0.5);
                    p->cur.g = (unsigned short)(int)(pow(v2, C1) * M + 0.5);
                    p->cur.b = (unsigned short)(int)(pow(v3, C1) * M + 0.5);
                } else {
                    double v = p->cur.gray / M;
                    p->out.gray = (unsigned short)(int)(pow(v, C0) * M + 0.5);
                    p->cur.gray = (unsigned short)(int)(pow(v, C1) * M + 0.5);
                }
            }
        } else if (mode == 3) {
            int n = p->count;
            if (n > 0) {
                unsigned char *e = p->entries;
                for (i = 0; i < n; i++) {
                    e[0] = p->tab15c[e[0]];
                    e[1] = p->tab15c[e[1]];
                    e[2] = p->tab15c[e[2]];
                    e += 3;
                }
            }
        }
    } else if ((flags & 0x80) && mode == 3) {
        int n = p->alphaCount;
        unsigned char r = (unsigned char)p->cur.r;
        unsigned char g = (unsigned char)p->cur.g;
        unsigned char b = (unsigned char)p->cur.b;
        if (n > 0) {
            unsigned char *e = p->entries;
            for (i = 0; i < n; i++) {
                unsigned int a = p->alpha[i];
                if (a == 0) {
                    e[0] = r;
                    e[1] = g;
                    e[2] = b;
                } else if (a != 0xff) {
                    unsigned int s = (unsigned short)((0xff - a) * r + e[0] * a + 0x80);
                    e[0] = (unsigned char)(((s >> 8) + s) >> 8);
                    a = p->alpha[i];
                    s = (unsigned short)((0xff - a) * g + e[1] * a + 0x80);
                    e[1] = (unsigned char)(((s >> 8) + s) >> 8);
                    a = p->alpha[i];
                    s = (unsigned short)((0xff - a) * b + e[2] * a + 0x80);
                    e[2] = (unsigned char)(((s >> 8) + s) >> 8);
                }
                e += 3;
            }
        }
    }

    if ((p->flags & 8) && mode == 3) {
        int s0 = 8 - p->sh0;
        int s1 = 8 - p->sh1;
        int s2 = 8 - p->sh2;
        unsigned short n = p->count;
        if (s0 < 0 || s0 > 8) s0 = 0;
        if (s1 < 0 || s1 > 8) s1 = 0;
        if (s2 < 0 || s2 > 8) s2 = 0;
        for (i = 0; i < n; i++) {
            p->entries[i * 3] >>= s0;
            p->entries[i * 3 + 1] >>= s1;
            p->entries[i * 3 + 2] >>= s2;
        }
    }
}


// 0x002dcd90 FUN_002dcd90 (1025 B): matches/0x002dcd90.cpp
// sym: ?FUN_002dcd90@fn_fcd359fc@@YAXPAUpng_struct_2dcd90@1@@Z
// FUN_002dcd90 @ 0x002dcd90
void __cdecl FUN_002dcd90(png_struct_2dcd90 *png_ptr)
{
    if (png_ptr->row_buf == 0) {
        char msg[50];
        sprintf(msg, "NULL row buffer for row %ld, pass %d", png_ptr->row_number, png_ptr->pass);
        FUN_002e69a0((png_struct_2dcd90 *)png_ptr, (void *)(const char *)msg);
    }
    if (png_ptr->transformations & 0x1000) {
        if (png_ptr->row_info.color_type == 3) {
            FUN_002db6b0((png_row_info_2dcd90 *)(&png_ptr->row_info), png_ptr->row_buf + 1, png_ptr->palette, (unsigned char *)(void *)(png_ptr->trans), png_ptr->num_trans);
        } else if (png_ptr->num_trans != 0) {
            FUN_002db8d0((png_row_info_2dcd90 *)(&png_ptr->row_info), png_ptr->row_buf + 1, (png_color_16_2dcd90 *)(&png_ptr->trans_values));
        } else {
            FUN_002db8d0((png_row_info_2dcd90 *)(&png_ptr->row_info), png_ptr->row_buf + 1, (png_color_16_2dcd90 *)0);
        }
    }
    if (png_ptr->transformations & 0x40000)
        FUN_002dd3a0((png_row_info_2dcd90 *)(&png_ptr->row_info), png_ptr->row_buf + 1, 0x80);
    if (png_ptr->transformations & 0x600000) {
        if (FUN_002d9c30((png_struct_2dcd90 *)png_ptr, (png_row_info_2dcd90 *)(&png_ptr->row_info), png_ptr->row_buf + 1)) {
            png_ptr->rgb_to_gray_status = 1;
            if (png_ptr->transformations == 0x400000)
                FUN_002e69d0((png_struct_2dcd90 *)png_ptr, (void *)(const char *)"png_do_rgb_to_gray found nongray pixel");
            if (png_ptr->transformations == 0x200000)
                FUN_002e69a0((png_struct_2dcd90 *)png_ptr, (void *)(const char *)"png_do_rgb_to_gray found nongray pixel");
        }
    }
    if ((png_ptr->transformations & 0x4000) && !(png_ptr->flags & 0x20000))
        FUN_002d9ae0((png_row_info_2dcd90 *)(&png_ptr->row_info), png_ptr->row_buf + 1);
    if ((png_ptr->transformations & 0x80) && (png_ptr->num_trans != 0 || (png_ptr->color_type & 4)))
        FUN_002da380(&png_ptr->row_info, png_ptr->row_buf + 1, &png_ptr->trans_values, &png_ptr->background, &png_ptr->background_1, png_ptr->gamma_table, png_ptr->gamma_from_1, png_ptr->gamma_to_1, png_ptr->gamma_16_table, png_ptr->gamma_16_from_1, png_ptr->gamma_16_to_1, png_ptr->gamma_shift);
    if ((png_ptr->transformations & 0x2000)
        && !((png_ptr->transformations & 0x80) && (png_ptr->num_trans != 0 || (png_ptr->color_type & 4)))
        && png_ptr->color_type != 3)
        FUN_002db320((png_row_info_2dcd90 *)(&png_ptr->row_info), png_ptr->row_buf + 1, (unsigned char *)(void *)(png_ptr->gamma_table), (unsigned short **)(void *)(png_ptr->gamma_16_table), png_ptr->gamma_shift);
    if (png_ptr->transformations & 0x400)
        FUN_002d95c0(&png_ptr->row_info, png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x40) {
        FUN_002dbc50((png_row_info_2dcd90 *)(&png_ptr->row_info), png_ptr->row_buf + 1, (unsigned char *)(void *)(png_ptr->palette_lookup), (unsigned char *)(void *)(png_ptr->dither_index));
        if (png_ptr->row_info.rowbytes == 0)
            FUN_002e69a0((png_struct_2dcd90 *)png_ptr, (void *)(const char *)"png_do_dither returned rowbytes=0");
    }
    if (png_ptr->transformations & 0x20)
        FUN_002dd2e0((png_row_info_2dcd90 *)(&png_ptr->row_info), png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x8)
        FUN_002d93f0((png_row_info_2dcd90 *)(&png_ptr->row_info), png_ptr->row_buf + 1, (unsigned char *)(png_ptr->shift));
    if (png_ptr->transformations & 0x4)
        FUN_002d92c0((png_row_info_2dcd90 *)(&png_ptr->row_info), png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x1)
        FUN_002dd5c0((png_row_info_2dcd90 *)(&png_ptr->row_info), png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x10000)
        FUN_002dd350((png_row_info_2dcd90 *)(&png_ptr->row_info), png_ptr->row_buf + 1);
    if ((png_ptr->transformations & 0x4000) && (png_ptr->flags & 0x20000))
        FUN_002d9ae0((png_row_info_2dcd90 *)(&png_ptr->row_info), png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x8000)
        FUN_002d9840((png_row_info_2dcd90 *)(&png_ptr->row_info), png_ptr->row_buf + 1, (unsigned int)(png_ptr->filler), (unsigned int)(png_ptr->flags));
    if (png_ptr->transformations & 0x80000)
        FUN_002d9720((png_row_info_2dcd90 *)(&png_ptr->row_info), png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x20000)
        FUN_002d9610((png_row_info_2dcd90 *)(&png_ptr->row_info), png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x10)
        FUN_002dd310(&png_ptr->row_info, png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x100000) {
        if (png_ptr->read_user_transform_fn != 0)
            png_ptr->read_user_transform_fn(png_ptr, &png_ptr->row_info, png_ptr->row_buf + 1);
    }
}


// 0x002dd1a0 FUN_002dd1a0 (9 B): matches/0x002dd1a0.cpp
// sym: _FUN_002dd1a0
extern "C" void FUN_002dd1a0(Obj_2dd1a0* object) {
    object->flags |= 1;
}


// 0x002dd230 FUN_002dd230 (30 B): matches/0x002dd230.cpp
// sym: ?FUN_002dd230@fn_fcd359fc@@YAHPAX@Z
int __cdecl FUN_002dd230(void* p) {
    if (((char*)p)[0x11b]) {
        *(int*)((char*)p + 0x68) |= 2;
        return 7;
    }
    return 1;
}


// 0x002dd250 FUN_002dd250 (90 B): matches/0x002dd250.cpp
// sym: _FUN_002dd250
extern "C" void FUN_002dd250(Obj_2dd250* p, unsigned char b, int mode) {
    unsigned int* q = (unsigned int*)((char*)p + 0x68);
    *q |= 0x8000;
    p->value = b;
    if (mode == 1)
        p->flags64 |= 0x80;
    else
        p->flags64 &= 0xffffff7f;
    if (p->state == 2)
        p->result = 4;
    if (p->state == 0 && p->level >= 8)
        p->result = 2;
}


// 0x002dd2e0 FUN_002dd2e0 (43 B): equivalent/0x002dd2e0.cpp
// sym: _FUN_002dd2e0 @84349957db29 @w40d875dbd93f
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 8/8)
// FUN_002dd2e0 @ 0x002dd2e0
extern "C" void __cdecl FUN_002dd2e0(void * data, unsigned char* bytes) { if (((Data *)data)->mode == 1 && ((Data *)data)->flag == 0) { for (unsigned int i = 0; i < ((Data *)data)->length; ++i) bytes[i] = ~bytes[i]; } }


// 0x002dd310 FUN_002dd310 (50 B): matches/0x002dd310.cpp
// sym: ?FUN_002dd310@fn_fcd359fc@@YAXPAUInfo@1@PAE@Z
void __cdecl FUN_002dd310(Info* p, unsigned char* data) {
    if (p->type == 0x10) {
        unsigned char* q = data;
        unsigned int n = p->count * p->n;
        for (; n > 0; --n) {
            unsigned char t = q[0];
            q[0] = q[1];
            q[1] = t;
            q += 2;
        }
    }
}


// 0x002dd350 FUN_002dd350 (79 B): matches/0x002dd350.cpp
// sym: _FUN_002dd350
extern "C" void FUN_002dd350(void * obj, unsigned char * p) {
    u8_2dd350 mode = ((Obj_2dd350 *)obj)->mode;
    if (mode < 8) {
        u8_2dd350* end = p + ((Obj_2dd350 *)obj)->count;
        u8_2dd350* table;
        if (mode == 1)
            table = ((u8_2dd350*)&DAT_004d1188);
        else if (mode == 2)
            table = ((u8_2dd350*)&DAT_004d1288);
        else if (mode == 4)
            table = ((u8_2dd350*)&DAT_004d1388);
        else
            return;
        while (p < end) {
            *p = table[*p];
            ++p;
        }
    }
}


// 0x002dd3a0 FUN_002dd3a0 (543 B): matches/0x002dd3a0.cpp
// sym: _FUN_002dd3a0
// FUN_002dd3a0 @ 0x002dd3a0
extern "C" void FUN_002dd3a0(void *row_info, unsigned char *row, unsigned int flags)
{
    unsigned char *sp = row;
    unsigned char *dp = row;
    unsigned int row_width = ((RowInfo_2dd3a0 *)row_info)->width;
    unsigned int i;

    if (((RowInfo_2dd3a0 *)row_info)->channels == 4) {
        if (((RowInfo_2dd3a0 *)row_info)->bit_depth == 8) {
            if (flags & 0x80) {
                dp += 3;
                sp += 4;
                for (i = 1; i < row_width; i++) {
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    sp++;
                }
            } else {
                for (i = 0; i < row_width; i++) {
                    sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                }
            }
            ((RowInfo_2dd3a0 *)row_info)->pixel_depth = 24;
            ((RowInfo_2dd3a0 *)row_info)->rowbytes = row_width * 3;
        } else {
            if (flags & 0x80) {
                sp += 8;
                dp += 6;
                for (i = 1; i < row_width; i++) {
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    sp += 2;
                }
            } else {
                for (i = 0; i < row_width; i++) {
                    sp += 2;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                }
            }
            ((RowInfo_2dd3a0 *)row_info)->pixel_depth = 48;
            ((RowInfo_2dd3a0 *)row_info)->rowbytes = row_width * 6;
        }
        ((RowInfo_2dd3a0 *)row_info)->channels = 3;
        ((RowInfo_2dd3a0 *)row_info)->color_type &= 0xfb;
    } else if (((RowInfo_2dd3a0 *)row_info)->channels == 2) {
        if (((RowInfo_2dd3a0 *)row_info)->bit_depth == 8) {
            if (flags & 0x80) {
                for (i = 0; i < row_width; i++) {
                    *dp++ = *sp++;
                    sp++;
                }
            } else {
                for (i = 0; i < row_width; i++) {
                    sp++;
                    *dp++ = *sp++;
                }
            }
            ((RowInfo_2dd3a0 *)row_info)->pixel_depth = 8;
            ((RowInfo_2dd3a0 *)row_info)->rowbytes = row_width;
        } else {
            if (flags & 0x80) {
                sp += 4;
                dp += 2;
                for (i = 1; i < row_width; i++) {
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    sp += 2;
                }
            } else {
                for (i = 0; i < row_width; i++) {
                    sp += 2;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                }
            }
            ((RowInfo_2dd3a0 *)row_info)->pixel_depth = 16;
            ((RowInfo_2dd3a0 *)row_info)->rowbytes = row_width * 2;
        }
        ((RowInfo_2dd3a0 *)row_info)->channels = 1;
        ((RowInfo_2dd3a0 *)row_info)->color_type &= 0xfb;
    }
}


// 0x002dd5c0 FUN_002dd5c0 (195 B): matches/0x002dd5c0.cpp
// sym: _FUN_002dd5c0
// FUN_002dd5c0 @ 0x002dd5c0
// libpng png_do_bgr: swap the red and blue samples of RGB / RGBA rows in place.
extern "C" void __cdecl FUN_002dd5c0(void *row_info, unsigned char *row)
{
    if (((png_row_info_2dd5c0 *)row_info)->color_type & 2) {
        unsigned int row_width = ((png_row_info_2dd5c0 *)row_info)->width;
        unsigned int i;
        unsigned char *rp;
        unsigned char save;

        if (((png_row_info_2dd5c0 *)row_info)->bit_depth == 8) {
            if (((png_row_info_2dd5c0 *)row_info)->color_type == 2) {
                for (i = 0, rp = row; i < row_width; i++, rp += 3) {
                    save = *rp;
                    *rp = *(rp + 2);
                    *(rp + 2) = save;
                }
            } else if (((png_row_info_2dd5c0 *)row_info)->color_type == 6) {
                for (i = 0, rp = row; i < row_width; i++, rp += 4) {
                    save = *rp;
                    *rp = *(rp + 2);
                    *(rp + 2) = save;
                }
            }
        } else if (((png_row_info_2dd5c0 *)row_info)->bit_depth == 16) {
            if (((png_row_info_2dd5c0 *)row_info)->color_type == 2) {
                for (i = 0, rp = row; i < row_width; i++, rp += 6) {
                    save = *rp;
                    *rp = *(rp + 4);
                    *(rp + 4) = save;
                    save = *(rp + 1);
                    *(rp + 1) = *(rp + 5);
                    *(rp + 5) = save;
                }
            } else if (((png_row_info_2dd5c0 *)row_info)->color_type == 6) {
                for (i = 0, rp = row; i < row_width; i++, rp += 8) {
                    save = *rp;
                    *rp = *(rp + 4);
                    *(rp + 4) = save;
                    save = *(rp + 1);
                    *(rp + 1) = *(rp + 5);
                    *(rp + 5) = save;
                }
            }
        }
    }
}


// 0x002dd690 FUN_002dd690 (32 B): matches/0x002dd690.cpp
// sym: _FUN_002dd690
extern "C" void __cdecl FUN_002dd690(void * p, void* data, unsigned int length) {
    ReadFn_2dd690 fn = ((Obj_2dd690 *)p)->fn;
    if (fn)
        fn(((Obj_2dd690 *)p), data, length);
    else
        Fail_002e69a0(((Obj_2dd690 *)p), "Call to NULL read function");
}


// 0x002dd6b0 FUN_002dd6b0 (51 B): matches/0x002dd6b0.cpp
// sym: ?readFile@fn_fcd359fc@@YAXPAUFile@1@PAXI@Z
void __cdecl readFile(File* file, void* dest, unsigned int count) {
    if (fread(dest, 1, count, file->handle) != count)
        report(file, "Read Error");
}


// 0x002dd6f0 FUN_002dd6f0 (83 B): matches/0x002dd6f0.cpp
// sym: _FUN_002dd6f0
extern "C" void FUN_002dd6f0(void * p, unsigned int value, void* fn) {
    ((Obj_2dd6f0 *)p)->field5c = value;
    if (fn)
        ((Obj_2dd6f0 *)p)->field50 = (hulk_uintptr)fn;
    else
        ((Obj_2dd6f0 *)p)->field50 = ((hulk_intptr)(void (__cdecl*)())&FUN_002dd6b0);
    if (((Obj_2dd6f0 *)p)->field4c) {
        ((Obj_2dd6f0 *)p)->field4c = 0;
        FUN_002e69d0((Obj_2dd6f0 *)((Obj_2dd6f0 *)p), (void *)(const char *)"It's an error to set both read_data_fn and write_data_fn in the ");
        FUN_002e69d0((Obj_2dd6f0 *)((Obj_2dd6f0 *)p), (void *)(const char *)"same structure.  Resetting write_data_fn to NULL.");
    }
    ((Obj_2dd6f0 *)p)->field144 = 0;
}

} // namespace fn_fcd359fc
