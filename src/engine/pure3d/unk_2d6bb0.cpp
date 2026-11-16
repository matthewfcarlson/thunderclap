// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002d6bb0..0x002dd760 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"
#include "decls/libpng.h"
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
} // namespace fn_fcd359fc
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memset(void*, int, unsigned int);
#endif
namespace fn_fcd359fc {
typedef PngStruct Obj_2d6c90;   // (x64t16) decls/libpng.h
extern "C" unsigned int __cdecl FUN_002e6c80(unsigned int, const unsigned char*, unsigned int);   // (x64t16) crc32
typedef PngStruct Obj_2d6cb0;
typedef unsigned int u32_2d6d00;
typedef PngText Item_2d6d10;   // (x64t16) decls/libpng.h
typedef PngInfo Obj_2d6d10;
extern void __cdecl Process_002e6c40(void* ctx, void* p);
extern void __cdecl Finish_002d6d00(Obj_2d6d10*);
typedef PngStruct Obj_2d6dd0;
void* __cdecl FUN_002e6a50(int, PngMallocFn);
void __cdecl FUN_002d6d00(PngInfo*);
typedef PngStruct Obj_2d6ed0;
void FUN_002d6d10(PngStruct*, PngInfo*);
void FUN_002e6ab0(void*, PngFreeFn);
extern "C" void __cdecl FUN_002e7fb0(void *);
extern "C" void __cdecl FUN_002d9170(void *, void *);
typedef PngStruct Obj_2d73f0;   // (x64t16) decls/libpng.h
struct Head_2d7b60 {
    int w[16];
};
struct PngInfo_2d7b60;   // (x64t16) only the thunk's symbol spells it (the png is decls/libpng.h's PngStruct)
void FUN_002d6d10(PngStruct* png, PngInfo* extra);
void FUN_002e6c40(PngStruct* png, void* ptr);
void thunk_FUN_002e6c40(PngInfo_2d7b60* png, void* ptr);
extern "C" void FUN_002e6e00(void* zstream);
typedef PngStruct Obj_2d7df0;   // (x64t16) decls/libpng.h
void F1_002d7b60(PngStruct*, PngInfo*, PngInfo*);
void F2_002e6c40(PngStruct*, void*);
void F3_002e6ab0(void*, PngFreeFn);
typedef unsigned int uint_2d7e90;
typedef PngInfo Obj_2d7e90;   // (x64t16) decls/libpng.h
typedef unsigned int u32_2d7eb0;
typedef unsigned char u8_2d7f10;
typedef unsigned char u8_2d7f30;
typedef int i32_2d7f30;
typedef unsigned char u8_2d7f70;
typedef unsigned int u32_2d7f70;
typedef unsigned int uint_2d8550;
typedef PngInfo Data_2d8550;   // (x64t16) decls/libpng.h
typedef PngInfo S_2d8630;   // (x64t16) decls/libpng.h
typedef unsigned int u32_2d8820;
typedef PngStruct Thing_2d8820;   // (x64t16) decls/libpng.h
typedef PngStruct Source_2d9170;   // (x64t16) decls/libpng.h
typedef PngInfo Format_2d9170;   // (x64t16) decls/libpng.h
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
typedef PngStruct png_struct_2d9c30;   // (x64t16) decls/libpng.h
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
typedef PngStruct Gamma;   // (x64t16) decls/libpng.h
unsigned char *__cdecl FUN_002e6c00(Gamma *g, unsigned int size);
typedef PngColor16 Col;   // (x64t16) decls/libpng.h
typedef PngStruct Pal_2dc3e0;   // (x64t16) decls/libpng.h
void __cdecl FUN_002dbd90(void *p);   // (x64t16) a call (not the definition below: MSVC would inline it)
typedef unsigned char png_byte;
typedef PngRowInfo png_row_info_2dcd90;   // (x64t16) decls/libpng.h
typedef PngColor16 png_color_16_2dcd90;   // (x64t16) decls/libpng.h
typedef PngStruct png_struct_2dcd90;   // (x64t16) decls/libpng.h
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
typedef PngStruct Obj_2dd1a0;   // (x64t16) decls/libpng.h
typedef PngStruct Obj_2dd250;   // (x64t16) decls/libpng.h
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
typedef PngRwFn ReadFn_2dd690;
extern "C" void __cdecl Fail_002e69a0(void*, const char*);
typedef PngStruct Obj_2dd690;   // (x64t16) decls/libpng.h
typedef PngStruct File_2dd6b0;   // (x64t16) decls/libpng.h
extern "C" size_t __cdecl fread(void*, size_t, size_t, void*);
extern "C" void __cdecl report(File_2dd6b0*, const char*);
extern "C" void __cdecl FUN_002dd6b0();
typedef unsigned int u32_2dd6f0;
typedef PngStruct Obj_2dd6f0;   // (x64t16) decls/libpng.h


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
// sym: ?FUN_002d6c20@fn_fcd359fc@@YAPAIPAXII@Z
// (x64t16) png_zalloc (the png as zlib's opaque, items, size)
unsigned int* __cdecl FUN_002d6c20(void* a, unsigned int b, unsigned int c) {
    unsigned int n = b * c;
    unsigned int* p = (unsigned int*)FUN_002e6c00((PngStruct*)a, n);
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
    ((Obj_2d6c90 *)self)->crc = FUN_002e6c80(0, 0, 0);
}


// 0x002d6cb0 FUN_002d6cb0 (72 B): matches/0x002d6cb0.cpp
// sym: _FUN_002d6cb0
extern "C" void __cdecl FUN_002d6cb0(Obj_2d6cb0* self, unsigned char* a, unsigned int b) {
    if (self->chunk_name[0] & 32) {
        if ((self->flags & 0x300) != 0x300)
            goto work;
        return;
    }
    if (self->flags & 0x800)
        return;
work:
    self->crc = FUN_002e6c80(self->crc, a, b);
}


// 0x002d6d00 FUN_002d6d00 (16 B): matches/0x002d6d00.cpp
// sym: ?FUN_002d6d00@fn_fcd359fc@@YAXPAI@Z
void __cdecl FUN_002d6d00(u32_2d6d00* p) {
    for (int i = sizeof(PngInfo) / 4; i != 0; --i)   // (x64t16) 0x2e words on the 32-bit builds
        *p++ = 0;
}


// 0x002d6d10 FUN_002d6d10 (188 B): matches/0x002d6d10.cpp
// sym: ?Target@fn_fcd359fc@@YAXPAXPAUPngInfo@@@Z
void __cdecl Target(void* ctx, Obj_2d6d10* s) {
    if (s->text) {
        int i = 0;
        if (s->num_text > 0) {
            do {
                Process_002e6c40(ctx, s->text[i].key);
                ++i;
            } while (i < s->num_text);
        }
        Process_002e6c40(ctx, s->text);
    }
    Process_002e6c40(ctx, s->pcal_purpose);
    Process_002e6c40(ctx, s->pcal_units);
    if (s->pcal_params) {
        int i = 0;
        if (s->pcal_nparams > 0) {
            do {
                Process_002e6c40(ctx, s->pcal_params[i]);
                ++i;
            } while (i < (int)s->pcal_nparams);
        }
        Process_002e6c40(ctx, s->pcal_params);
    }
    Finish_002d6d00(s);
}


// 0x002d6dd0 FUN_002d6dd0 (8 B): matches/0x002d6dd0.cpp
// sym: _FUN_002d6dd0
extern "C" void* __cdecl FUN_002d6dd0(Obj_2d6dd0* p) {   // (x64t16) png_get_io_ptr
    return p->io_ptr;
}


// 0x002d6ea0 FUN_002d6ea0 (44 B): equivalent/0x002d6ea0.cpp
// sym: _FUN_002d6ea0 @93e65479bd77 @we6d73391690e
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002d6ea0 @ 0x002d6ea0
extern "C" PngInfo* __cdecl FUN_002d6ea0(PngStruct* object)   // (x64t16) png_create_info_struct
{
    if (!object) return 0;
    PngInfo* result = (PngInfo*)FUN_002e6a50(2, object->malloc_fn);
    if (result) FUN_002d6d00(result);
    return result;
}


// 0x002d6ed0 FUN_002d6ed0 (54 B): matches/0x002d6ed0.cpp
// sym: _FUN_002d6ed0
extern "C" void FUN_002d6ed0(Obj_2d6ed0* self, PngInfo** out) {
    if (out && *out) {
        PngInfo* p = *out;
        FUN_002d6d10(self, p);
        FUN_002e6ab0(p, self->free_fn);
        *out = 0;
    }
}

} // namespace fn_fcd359fc

// 0x002d6f10 FUN_002d6f10 (307 B): equivalent/0x002d6f10.cpp [wrapped: code differs from its standalone build]
// sym: _FUN_002d6f10 @a1616325fc21 @w9563aae9ed67
namespace fn_002d6f10 {
// STATUS: equivalent (tools/equiv.py level 3: 3107 inputs, branch coverage 21/21)
// FUN_002d6f10 @ 0x002d6f10

typedef ZStream ZStream_2d6f10;   // (x64t16) decls/libpng.h

typedef PngStruct PngStruct_2d6f10;   // (x64t16) decls/libpng.h


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
extern "C++" void __cdecl FUN_002dd6f0(void *, void *, void *);
void* FUN_002d6c20(void*, unsigned int, unsigned int);   // (x64t16) png_zalloc, as zlib calls it
void FUN_002d6c80(void*, void*); /* (unb4) as defined; address taken only */

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

    png->zbuf_size = 0x2000;
    png->zbuf = (unsigned char *)FUN_002e6c00(png, 0x2000);
    png->zstream.zalloc = &FUN_002d6c20;
    png->zstream.zfree = &FUN_002d6c80;
    png->zstream.opaque = png;

    switch (FUN_002e6f50(&png->zstream, "1.1.3", sizeof(ZStream))) {
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
    png->zstream.avail_out = png->zbuf_size;
    FUN_002dd6f0((PngStruct_2d6f10 *)png, 0, (void *)(hulk_uintptr)(int)0);
    return png;
}
} // namespace fn_002d6f10


// 0x002d7150 FUN_002d7150 (665 B): equivalent/0x002d7150.cpp [wrapped: code differs from its standalone build]
// sym: ?FUN_002d7150@fn_002d7150@@YAXTPngArg@1@PAUPngInfo@@@Z @cf7c9e852bfc @wacfc2f0bba56
namespace fn_002d7150 {
// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 48/48)
// FUN_002d7150 @ 0x002d7150
// libpng png_read_info

typedef PngStruct PngStruct_2d7150;   // (x64t16) decls/libpng.h

typedef PngInfo PngInfo_2d7150;   // (x64t16) decls/libpng.h

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

extern "C++" void __cdecl FUN_002dd690(void *, void *, unsigned int);
extern "C" unsigned int __cdecl FUN_002e7500(unsigned char *);
extern "C++" void __cdecl FUN_002d6c90(void *);
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

extern "C++" int __cdecl FUN_002d6bb0(const char *, unsigned int, unsigned int);

void FUN_002d7150(PngArg arg, PngInfo_2d7150* info)
{
    PngStruct_2d7150* png = arg.png;
    unsigned int length;

    if (png->sig_bytes < 8) {
        unsigned int numChecked = png->sig_bytes;
        unsigned int numToCheck = 8 - numChecked;
        FUN_002dd690((PngStruct_2d7150 *)png, info->signature + numChecked, numToCheck);
        png->sig_bytes = 8;
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
        FUN_002e7580(png, png->chunk_name, 4);

        if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d1034)) {
            FUN_002e82a0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d104c)) {
            FUN_002e84e0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d1044)) {
            FUN_002e8640(png, info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d103c)) {
            if ((png->mode & 1) == 0) {
                FUN_002e69a0((PngStruct_2d7150 *)png, (void *)(const char *)"Missing IHDR before IDAT");
            } else if (png->color_type == 3 && (png->mode & 2) == 0) {
                FUN_002e69a0((PngStruct_2d7150 *)png, (void *)(const char *)"Missing PLTE before IDAT");
            }
            png->idat_size = length;
            png->mode |= 4;
            return;
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d1054)) {
            FUN_002e93b0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d105c)) {
            FUN_002e8940((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d1064)) {
            FUN_002e86a0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d106c)) {
            FUN_002e9570((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, (unsigned int)length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d1074)) {
            FUN_002e9790((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, (unsigned int)length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d107c)) {
            FUN_002e9880((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d1084)) {
            FUN_002e96a0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, (unsigned int)length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d108c)) {
            FUN_002e87e0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d1094)) {
            FUN_002e8f80((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d109c)) {
            FUN_002e9bb0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d10a4)) {
            FUN_002e9ac0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, (unsigned int)length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d10ac)) {
            FUN_002e91b0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d10b4)) {
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
extern "C" void __cdecl FUN_002d73f0(Obj_2d73f0* p, PngInfo* a) {   // (x64t16) png_read_update_info
    if ((p->flags & 0x40) == 0)
        FUN_002e7fb0(p);
    FUN_002d9170(p, a);
}

} // namespace fn_fcd359fc

// 0x002d7440 FUN_002d7440 (1084 B): equivalent/0x002d7440.cpp [wrapped: code differs from its standalone build]
// sym: _FUN_002d7440 @6e851aafeeed @w8e82a2cc4bee
namespace fn_002d7440 {
// STATUS: equivalent (tools/equiv.py level 3: 1832 inputs, branch coverage 92/95, incomplete)
// FUN_002d7440 @ 0x002d7440
// libpng 1.2.x png_read_row, as compiled into the game (zlib 1.2 inflate, Adam7 interlace handling).

typedef ZStream ZStream_2d7440;   // (x64t16) decls/libpng.h

typedef PngRowInfo RowInfo_2d7440;   // (x64t16) decls/libpng.h

typedef void (*ReadRowFn)(PngStruct *png, unsigned int row, int pass);

typedef PngStruct PngStruct_2d7440;   // (x64t16) decls/libpng.h

           // png_pass_mask
           // png_pass_dsp_mask
   // "IDAT"

extern "C" void __cdecl FUN_002e7fb0(void *);                                   // png_read_start_row
extern "C" void __cdecl FUN_002e7680(PngStruct_2d7440 *png, unsigned char *row, int mask);     // png_combine_row
extern "C" void __cdecl FUN_002ea010(PngStruct_2d7440 *png);                                   // png_read_finish_row
extern "C" void __cdecl FUN_002e69a0(void *, void *);                  // png_error
extern "C" int __cdecl FUN_002e81e0(void *, unsigned int);                // png_crc_finish
extern "C++" void __cdecl FUN_002dd690(void *, void *, unsigned int);   // png_read_data
extern "C" unsigned int __cdecl FUN_002e7500(unsigned char *);                       // png_get_uint_31
extern "C++" void __cdecl FUN_002d6c90(void *);                                   // png_reset_crc
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
// sym: ?FUN_002d7980@fn_002d7980@@YAXPAUPngStruct@@PAUPngInfo@@@Z @43561fe2da22 @wde15f237f3e7
namespace fn_002d7980 {
// STATUS: equivalent (tools/equiv.py level 3: 100 inputs, branch coverage 40/40)
// FUN_002d7980 @ 0x002d7980
// libpng png_read_info

typedef PngStruct PngStruct_2d7980;   // (x64t16) decls/libpng.h


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
extern "C++" void __cdecl FUN_002dd690(void *, void *, unsigned int);
extern "C" unsigned int __cdecl FUN_002e7500(unsigned char *);
extern "C++" void __cdecl FUN_002d6c90(void *);
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
        FUN_002e7580(png, png->chunk_name, 4);

        if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d1034)) {
            FUN_002e82a0((PngStruct_2d7980 *)png, (PngInfo *)info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d103c)) {
            if (length > 0 || (png->mode & 8) != 0) {
                FUN_002e69a0((PngStruct_2d7980 *)png, (void *)(const char *)"Too many IDAT's found");
            } else {
                FUN_002e81e0((PngStruct_2d7980 *)png, 0);
            }
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d104c)) {
            FUN_002e84e0((PngStruct_2d7980 *)png, (PngInfo *)info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d1044)) {
            FUN_002e8640(png, info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d1054)) {
            FUN_002e93b0((PngStruct_2d7980 *)png, (PngInfo *)info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d105c)) {
            FUN_002e8940((PngStruct_2d7980 *)png, (PngInfo *)info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d1064)) {
            FUN_002e86a0((PngStruct_2d7980 *)png, (PngInfo *)info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d106c)) {
            FUN_002e9570((PngStruct_2d7980 *)png, (PngInfo *)info, (unsigned int)length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d1074)) {
            FUN_002e9790((PngStruct_2d7980 *)png, (PngInfo *)info, (unsigned int)length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d107c)) {
            FUN_002e9880((PngStruct_2d7980 *)png, (PngInfo *)info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d1084)) {
            FUN_002e96a0((PngStruct_2d7980 *)png, (PngInfo *)info, (unsigned int)length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d108c)) {
            FUN_002e87e0((PngStruct_2d7980 *)png, (PngInfo *)info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d1094)) {
            FUN_002e8f80((PngStruct_2d7980 *)png, (PngInfo *)info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d109c)) {
            FUN_002e9bb0((PngStruct_2d7980 *)png, (PngInfo *)info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d10a4)) {
            FUN_002e9ac0((PngStruct_2d7980 *)png, (PngInfo *)info, (unsigned int)length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d10ac)) {
            FUN_002e91b0((PngStruct_2d7980 *)png, (PngInfo *)info, length);
        } else if (*(unsigned int *)png->chunk_name == (*(const unsigned int*)&DAT_004d10b4)) {
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
extern "C" void FUN_002d7b60(PngStruct* png, PngInfo* a, PngInfo* b)
{
    if (a)
        FUN_002d6d10(png, a);
    if (b)
        FUN_002d6d10(png, b);

    FUN_002e6c40(png, png->zbuf);
    FUN_002e6c40(png, png->row_buf);
    FUN_002e6c40(png, png->prev_row);
    FUN_002e6c40(png, png->palette_lookup);
    FUN_002e6c40(png, png->dither_index);
    FUN_002e6c40(png, png->gamma_table);
    FUN_002e6c40(png, png->gamma_from_1);
    FUN_002e6c40(png, png->gamma_to_1);

    if (png->flags & 0x1000)
        thunk_FUN_002e6c40((PngInfo_2d7b60*)png, png->palette);
    if (png->flags & 0x2000)
        FUN_002e6c40(png, png->trans);
    if (png->flags & 0x4000)
        FUN_002e6c40(png, png->hist);

    if (png->gamma_16_table) {
        int n = 1 << (8 - png->gamma_shift);
        for (int i = 0; i < n; i++)
            FUN_002e6c40(png, png->gamma_16_table[i]);
        FUN_002e6c40(png, png->gamma_16_table);
    }
    if (png->gamma_16_from_1) {
        int n = 1 << (8 - png->gamma_shift);
        for (int i = 0; i < n; i++)
            FUN_002e6c40(png, png->gamma_16_from_1[i]);
        FUN_002e6c40(png, png->gamma_16_from_1);
    }
    if (png->gamma_16_to_1) {
        int n = 1 << (8 - png->gamma_shift);
        for (int i = 0; i < n; i++)
            FUN_002e6c40(png, png->gamma_16_to_1[i]);
        FUN_002e6c40(png, png->gamma_16_to_1);
    }

    FUN_002e6c40(png, png->time_buffer);
    FUN_002e6e00(&png->zstream);
    FUN_002e6c40(png, png->save_buffer);

    PngFreeFn k214 = png->free_fn;
    void* k48 = png->error_ptr;
    PngErrorFn k40 = png->error_fn;
    Head_2d7b60 head = *(Head_2d7b60*)png->jmpbuf;
    PngErrorFn k44 = png->warning_fn;
    unsigned int* p = (unsigned int*)png;
    for (int i = 0; i < (int)(sizeof(PngStruct) / 4); i++)   // (x64t16) 0x87 words on the 32-bit builds
        p[i] = 0;
    png->warning_fn = k44;
    png->free_fn = k214;
    *(Head_2d7b60*)png->jmpbuf = head;
    png->error_ptr = k48;
    png->error_fn = k40;
}


// 0x002d7df0 FUN_002d7df0 (150 B): matches/0x002d7df0.cpp
// sym: ?FUN_002d7df0@fn_fcd359fc@@YAXPAPAUPngStruct@@PAPAUPngInfo@@1@Z
void FUN_002d7df0(PngStruct** a, PngInfo** b, PngInfo** c) {   // (x64t16) png_destroy_read_struct
    PngStruct* x = 0;
    PngInfo* y = 0;
    PngInfo* z = 0;
    if (a)
        x = *a;
    if (b)
        y = *b;
    if (c)
        z = *c;
    PngFreeFn q = x->free_fn;
    F1_002d7b60(x, y, z);
    if (y) {
        F2_002e6c40(x, y->text);
        F3_002e6ab0(y, q);
        *b = 0;
    }
    if (z) {
        F2_002e6c40(x, z->text);
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
        return object->valid & mask;
    return 0;
}


// 0x002d7eb0 FUN_002d7eb0 (23 B): matches/0x002d7eb0.cpp
// sym: _FUN_002d7eb0
extern "C" u32_2d7eb0 FUN_002d7eb0(void* a, void* b) {
    if (a && b)
        return ((PngInfo*)b)->rowbytes;
    return 0;
}


// 0x002d7ed0 FUN_002d7ed0 (22 B): matches/0x002d7ed0.cpp
// sym: _FUN_002d7ed0
extern "C" int FUN_002d7ed0(hulk_intptr a, PngInfo* b) {
    if (a && b)
        return b->width;
    return 0;
}


// 0x002d7ef0 FUN_002d7ef0 (23 B): matches/0x002d7ef0.cpp
// sym: _FUN_002d7ef0
extern "C" int FUN_002d7ef0(hulk_intptr a, hulk_intptr b) {
    if (a && b)
        return ((PngInfo*)b)->height;
    return 0;
}


// 0x002d7f10 FUN_002d7f10 (23 B): matches/0x002d7f10.cpp
// sym: _FUN_002d7f10
extern "C" u8_2d7f10 __cdecl FUN_002d7f10(void* handle, void* object) {
    if (handle != 0 && object != 0)
        return ((PngInfo*)object)->bit_depth;
    return 0;
}


// 0x002d7f30 FUN_002d7f30 (23 B): matches/0x002d7f30.cpp
// sym: _FUN_002d7f30
extern "C" u8_2d7f30 __cdecl FUN_002d7f30(hulk_intptr a, hulk_intptr b) {
    if (a && b)
        return ((PngInfo*)b)->color_type;
    return 0;
}


// 0x002d7f70 FUN_002d7f70 (23 B): matches/0x002d7f70.cpp
// sym: _FUN_002d7f70
extern "C" u8_2d7f70 FUN_002d7f70(hulk_uintptr handle, PngInfo* object) {
    if (handle != 0 && object != 0)
        return object->interlace_type;
    return 0;
}


// 0x002d8550 FUN_002d8550 (54 B): matches/0x002d8550.cpp
// sym: _FUN_002d8550
extern "C" int __cdecl FUN_002d8550(hulk_intptr a, Data_2d8550* b, PngColor** out, uint_2d8550* out2) {
    if (a && b && (b->valid & 8) && out) {
        *out = b->palette;
        *out2 = (uint_2d8550)b->num_palette;
        return 8;
    }
    return 0;
}


// 0x002d8630 FUN_002d8630 (115 B): matches/0x002d8630.cpp
// sym: _FUN_002d8630
extern "C" int FUN_002d8630(hulk_intptr a, S_2d8630* s, unsigned char** o1, unsigned* o2, PngColor16** o3) {
    int r = 0;
    if (a != 0 && s != 0 && (s->valid & 0x10) != 0) {
        if (s->color_type == 3) {
            if (o1 != 0) {
                *o1 = s->trans;
                r = 0x10;
            }
            if (o3 != 0) {
                *o3 = &s->trans_values;
            }
        } else {
            if (o3 != 0) {
                *o3 = &s->trans_values;
                r = 0x10;
            }
            if (o1 != 0) {
                *o1 = 0;
            }
        }
        if (o2 != 0) {
            *o2 = s->num_trans;
            r |= 0x10;
        }
    }
    return r;
}


// 0x002d8820 FUN_002d8820 (12 B): matches/0x002d8820.cpp
// sym: _FUN_002d8820
extern "C" void __cdecl FUN_002d8820(Thing_2d8820* p) {
    p->transformations |= 0x400;
}


// 0x002d8830 FUN_002d8830 (12 B): matches/0x002d8830.cpp
// sym: _FUN_002d8830
extern "C" void FUN_002d8830(void* object) {
    ((PngStruct*)object)->transformations |= 0x40000;
}


// 0x002d9060 FUN_002d9060 (12 B): matches/0x002d9060.cpp
// sym: _FUN_002d9060
extern "C" void FUN_002d9060(void* p) {
    ((PngStruct*)p)->transformations |= 0x1000;
}


// 0x002d9170 FUN_002d9170 (326 B): equivalent/0x002d9170.cpp
// sym: _FUN_002d9170 @474ab52d0bba @w6e250edf9681
// STATUS: equivalent (tools/equiv.py level 3: 116 inputs, branch coverage 50/50)
// FUN_002d9170 @ 0x002d9170
extern "C" void FUN_002d9170(void *src, void * fmt_)
{
    Format_2d9170 * fmt = (Format_2d9170 *)fmt_;
    unsigned char bl = 8;

    if (((Source_2d9170 *)src)->transformations & 0x1000) {
        if (fmt->color_type == 3) {
            fmt->color_type = (((Source_2d9170 *)src)->num_trans != 0) * 4 + 2;
            fmt->bit_depth = bl;
        } else {
            if (((Source_2d9170 *)src)->num_trans != 0)
                fmt->color_type = fmt->color_type | 4;
            if (fmt->bit_depth < bl)
                fmt->bit_depth = bl;
        }
        fmt->num_trans = 0;
    }
    if (((Source_2d9170 *)src)->transformations & 0x80) {
        fmt->color_type &= 0xfb;
        fmt->num_trans = 0;
        for (int i = 0; i < 10; i++)
            ((unsigned char *)&fmt->background)[i] = ((unsigned char *)&((Source_2d9170 *)src)->background)[i];
    }
    if (((Source_2d9170 *)src)->transformations & 0x2000)
        *(unsigned int *)&fmt->gamma = *(unsigned int *)&((Source_2d9170 *)src)->gamma;
    if (((Source_2d9170 *)src)->transformations & 0x400) {
        if (fmt->bit_depth == 0x10)
            fmt->bit_depth = bl;
    }
    if (((Source_2d9170 *)src)->transformations & 0x40) {
        unsigned char m = fmt->color_type;
        if ((m == 2 || m == 6) && ((Source_2d9170 *)src)->palette_lookup != 0 && fmt->bit_depth == bl)
            fmt->color_type = 3;
    }
    if (((Source_2d9170 *)src)->transformations & 4) {
        if (fmt->bit_depth < bl)
            fmt->bit_depth = bl;
    }
    if (((Source_2d9170 *)src)->transformations & 0x4000)
        fmt->color_type |= 2;
    if (((Source_2d9170 *)src)->transformations & 0x600000)
        fmt->color_type &= 0xfd;
    unsigned char m = fmt->color_type;
    if (m != 3 && (m & 2))
        fmt->channels = 3;
    else
        fmt->channels = 1;
    if (((Source_2d9170 *)src)->transformations & 0x40000) {
        m &= 0xfb;
        fmt->color_type = m;
    }
    m = fmt->color_type;
    if (m & 4)
        fmt->channels++;
    if (((Source_2d9170 *)src)->transformations & 0x8000) {
        if (m == 2 || m == 0)
            fmt->channels++;
    }
    unsigned char bits = (unsigned char)(fmt->bit_depth * fmt->channels);
    fmt->pixel_depth = bits;
    fmt->rowbytes = (bits * fmt->width + 7) >> 3;
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
                            png_uint_16 red_1 = ((png_struct_2d9c30 *)png_ptr)->gamma_16_to_1[(red & 0xff) >> (*(png_uint_16 *)&((png_struct_2d9c30 *)png_ptr)->gamma_shift)][red >> 8];
                            png_uint_16 green_1 = ((png_struct_2d9c30 *)png_ptr)->gamma_16_to_1[(green & 0xff) >> (*(png_uint_16 *)&((png_struct_2d9c30 *)png_ptr)->gamma_shift)][green >> 8];
                            png_uint_16 blue_1 = ((png_struct_2d9c30 *)png_ptr)->gamma_16_to_1[(blue & 0xff) >> (*(png_uint_16 *)&((png_struct_2d9c30 *)png_ptr)->gamma_shift)][blue >> 8];
                            png_uint_16 gray16 = (png_uint_16)((rc * red_1 + gc * green_1 + bc * blue_1) >> 8);
                            w = ((png_struct_2d9c30 *)png_ptr)->gamma_16_from_1[(gray16 & 0xff) >> (*(png_uint_16 *)&((png_struct_2d9c30 *)png_ptr)->gamma_shift)][gray16 >> 8];
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
                            png_uint_16 red_1 = ((png_struct_2d9c30 *)png_ptr)->gamma_16_to_1[(red & 0xff) >> (*(png_uint_16 *)&((png_struct_2d9c30 *)png_ptr)->gamma_shift)][red >> 8];
                            png_uint_16 green_1 = ((png_struct_2d9c30 *)png_ptr)->gamma_16_to_1[(green & 0xff) >> (*(png_uint_16 *)&((png_struct_2d9c30 *)png_ptr)->gamma_shift)][green >> 8];
                            png_uint_16 blue_1 = ((png_struct_2d9c30 *)png_ptr)->gamma_16_to_1[(blue & 0xff) >> (*(png_uint_16 *)&((png_struct_2d9c30 *)png_ptr)->gamma_shift)][blue >> 8];
                            png_uint_16 gray16 = (png_uint_16)((rc * red_1 + gc * green_1 + bc * blue_1) >> 8);
                            w = ((png_struct_2d9c30 *)png_ptr)->gamma_16_from_1[(gray16 & 0xff) >> (*(png_uint_16 *)&((png_struct_2d9c30 *)png_ptr)->gamma_shift)][gray16 >> 8];
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
// sym: ?FUN_002dbd90@fn_fcd359fc@@YAXPAUPngStruct@@@Z @fc728c88a8a1 @w5cbbc353a908
// STATUS: equivalent (tools/equiv.py level 3: 106 inputs, branch coverage 62/80, incomplete)
// FUN_002dbd90 @ 0x002dbd90
void FUN_002dbd90(Gamma *g)
{
    if (g->gamma == 0.0)
        return;
    if (g->bit_depth <= 8) {
        double e;
        if (g->screen_gamma > 1e-6)
            e = 1.0 / (g->screen_gamma * g->gamma);
        else
            e = 1.0;
        g->gamma_table = FUN_002e6c00(g, 0x100);
        for (int i = 0; i < 0x100; i++)
            g->gamma_table[i] = (unsigned char)(int)(pow(i * 0.00392156862745098, e) * 255.0 + 0.5);
        if (!(g->transformations & 0x600080))
            return;
        double e2 = 1.0 / g->gamma;
        g->gamma_to_1 = FUN_002e6c00(g, 0x100);
        for (int i = 0; i < 0x100; i++)
            g->gamma_to_1[i] = (unsigned char)(int)(pow(i * 0.00392156862745098, e2) * 255.0 + 0.5);
        g->gamma_from_1 = FUN_002e6c00(g, 0x100);
        double e3;
        if (g->screen_gamma > 1e-6)
            e3 = 1.0 / g->screen_gamma;
        else
            e3 = g->gamma;
        for (int i = 0; i < 0x100; i++)
            g->gamma_from_1[i] = (unsigned char)(int)(pow(i * 0.00392156862745098, e3) * 255.0 + 0.5);
        return;
    }

    int c;
    if (g->color_type & 2) {
        c = g->sig_bit.red;
        if (g->sig_bit.green > c)
            c = g->sig_bit.green;
        if (g->sig_bit.blue > c)
            c = g->sig_bit.blue;
    } else {
        c = g->sig_bit.gray;
    }
    int bits;
    if (c > 0)
        bits = 0x10 - c;
    else
        bits = 0;
    if ((g->transformations & 0x400) && bits < 5)
        bits = 5;
    else if (bits > 8)
        bits = 8;
    else if (bits < 0)
        bits = 0;
    g->gamma_shift = (unsigned char)bits;
    int shift = 8 - bits;
    int count = 1 << shift;
    double d;
    if (g->screen_gamma > 1e-6)
        d = 1.0 / (g->screen_gamma * g->gamma);
    else
        d = 1.0;
    g->gamma_16_table = (unsigned short **)FUN_002e6c00(g, count * sizeof(unsigned short *));
    unsigned int edi = 0;
    if (g->transformations & 0x480) {
        for (int i = 0; i < count; i++)
            g->gamma_16_table[i] = (unsigned short *)FUN_002e6c00(g, 0x200);
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
                    g->gamma_16_table[mask & edi][edi >> shift] = v;
                    edi++;
                } while (edi <= end);
            }
        }
        if (edi < n) {
            int mask = 0xff >> bits;
            do {
                g->gamma_16_table[mask & edi][edi >> shift] = 0xffff;
                edi++;
            } while (edi < n);
        }
    } else {
        if (count > 0) {
            int i = 0;
            do {
                g->gamma_16_table[i] = (unsigned short *)FUN_002e6c00(g, 0x200);
                unsigned int base = (((unsigned int*)&DAT_004d1164)[bits] * i) >> 4;
                unsigned int k = 0;
                do {
                    g->gamma_16_table[i][k / 2] = (unsigned short)(int)(pow((double)base * 1.5259021896696422e-05, d) * 65535.0 + 0.5);
                    k += 2;
                    base += 0x100;
                } while (k < 0x200);
                i++;
            } while (i < count);
        }
    }
    if (!(g->transformations & 0x600080))
        return;
    double e4 = 1.0 / g->gamma;
    g->gamma_16_to_1 = (unsigned short **)FUN_002e6c00(g, count * sizeof(unsigned short *));
    if (count > 0) {
        int i = 0;
        do {
            g->gamma_16_to_1[i] = (unsigned short *)FUN_002e6c00(g, 0x200);
            unsigned int base = (((unsigned int*)&DAT_004d1164)[bits] * i) >> 4;
            unsigned int k = 0;
            do {
                g->gamma_16_to_1[i][k / 2] = (unsigned short)(int)(pow((double)base * 1.5259021896696422e-05, e4) * 65535.0 + 0.5);
                k += 2;
                base += 0x100;
            } while (k < 0x200);
            i++;
        } while (i < count);
    }
    double e5;
    if (g->screen_gamma > 1e-6)
        e5 = 1.0 / g->screen_gamma;
    else
        e5 = g->gamma;
    g->gamma_16_from_1 = (unsigned short **)FUN_002e6c00(g, count * sizeof(unsigned short *));
    if (count > 0) {
        int i = 0;
        do {
            g->gamma_16_from_1[i] = (unsigned short *)FUN_002e6c00(g, 0x200);
            unsigned int base = (((unsigned int*)&DAT_004d1164)[bits] * i) >> 4;
            unsigned int k = 0;
            do {
                g->gamma_16_from_1[i][k / 2] = (unsigned short)(int)(pow((double)base * 1.5259021896696422e-05, e5) * 65535.0 + 0.5);
                k += 2;
                base += 0x100;
            } while (k < 0x200);
            i++;
        } while (i < count);
    }
}


// 0x002dc3e0 FUN_002dc3e0 (2429 B): equivalent/0x002dc3e0.cpp
// sym: ?FUN_002dc3e0@fn_fcd359fc@@YAXPAUPngStruct@@@Z @b026280774ab @w5578472f3a18 @ved186d695045
// STATUS: equivalent (tools/equiv.py level 3: 3046 inputs, branch coverage 90/95, incomplete)
// FUN_002dc3e0 @ 0x002dc3e0
void FUN_002dc3e0(Pal_2dc3e0 *p)
{
    unsigned int mode = p->color_type;
    unsigned int flags = p->transformations;
    int i;

    if (flags & 0x100) {
        if (!(mode & 2)) {
            switch (p->bit_depth) {
            case 1: {
                unsigned short g = (unsigned short)(p->background.gray * 0xff);
                p->background.gray = g;
                p->background.blue = g;
                p->background.green = g;
                p->background.red = g;
                break;
            }
            case 2: {
                unsigned short g = (unsigned short)(p->background.gray * 0x55);
                p->background.gray = g;
                p->background.blue = g;
                p->background.green = g;
                p->background.red = g;
                break;
            }
            case 4: {
                unsigned short g = (unsigned short)(p->background.gray * 0x11);
                p->background.gray = g;
                p->background.blue = g;
                p->background.green = g;
                p->background.red = g;
                break;
            }
            case 8:
            case 16: {
                unsigned short g = p->background.gray;
                p->background.blue = g;
                p->background.green = g;
                p->background.red = g;
                break;
            }
            }
        } else if (mode == 3) {
            unsigned char *e = ((unsigned char *)p->palette) + p->background.index * 3;
            p->background.red = e[0];
            p->background.green = e[1];
            p->background.blue = e[2];
            if ((flags & 0x80000) && !(flags & 0x1000)) {
                int n = p->num_trans;
                for (i = 0; i < n; i++)
                    p->trans[i] = 0xff - p->trans[i];
            }
        }
    }

    p->background_1 = p->background;

    flags = p->transformations;
    if (flags & 0x602000) {
        FUN_002dbd90((void *)p);
        if (p->transformations & 0x80) {
            if (mode == 3) {
                int count = p->num_palette;
                double A, B;
                unsigned char c0, c1, c2, d0, d1, d2;
                if (p->background_gamma_type == 2) {
                    unsigned char *t = p->gamma_table;
                    c0 = t[p->background.red];
                    c1 = t[p->background.green];
                    c2 = t[p->background.blue];
                    unsigned char *u = p->gamma_to_1;
                    d0 = u[p->background.red];
                    d1 = u[p->background.green];
                    d2 = u[p->background.blue];
                } else {
                    switch (p->background_gamma_type) {
                    case 1:
                        A = p->screen_gamma;
                        B = 1.0;
                        break;
                    case 2:
                        A = 1.0 / p->gamma;
                        B = 1.0 / ((double)p->screen_gamma * p->gamma);
                        break;
                    case 3:
                        A = 1.0 / p->background_gamma;
                        B = 1.0 / ((double)p->screen_gamma * p->background_gamma);
                        break;
                    default:
                        A = 1.0;
                        B = 1.0;
                        break;
                    }
                    if (fabs(B - 1.0) < 0.05) {
                        c0 = (unsigned char)p->background.red;
                        c1 = (unsigned char)p->background.green;
                        c2 = (unsigned char)p->background.blue;
                    } else {
                        c0 = (unsigned char)(int)(pow(p->background.red * 0.00392156862745098, B) * 255.0 + 0.5);
                        c1 = (unsigned char)(int)(pow(p->background.green * 0.00392156862745098, B) * 255.0 + 0.5);
                        c2 = (unsigned char)(int)(pow(p->background.blue * 0.00392156862745098, B) * 255.0 + 0.5);
                    }
                    d0 = (unsigned char)(int)(pow(p->background.red * 0.00392156862745098, A) * 255.0 + 0.5);
                    d1 = (unsigned char)(int)(pow(p->background.green * 0.00392156862745098, A) * 255.0 + 0.5);
                    d2 = (unsigned char)(int)(pow(p->background.blue * 0.00392156862745098, A) * 255.0 + 0.5);
                }
                unsigned char *pal = ((unsigned char *)p->palette);
                for (i = 0; i < count; i++) {
                    unsigned char *e = pal + i * 3;
                    if (i >= p->num_trans || p->trans[i] == 0xff) {
                        e[0] = p->gamma_table[e[0]];
                        e[1] = p->gamma_table[e[1]];
                        e[2] = p->gamma_table[e[2]];
                    } else if (p->trans[i] == 0) {
                        e[0] = c0;
                        e[1] = c1;
                        e[2] = c2;
                    } else {
                        unsigned int a = p->trans[i];
                        unsigned int s = (unsigned short)(p->gamma_to_1[e[0]] * a + (0xff - a) * d0 + 0x80);
                        e[0] = p->gamma_from_1[(unsigned char)(((s >> 8) + s) >> 8)];
                        a = p->trans[i];
                        s = (unsigned short)(p->gamma_to_1[e[1]] * a + (0xff - a) * d1 + 0x80);
                        e[1] = p->gamma_from_1[(unsigned char)(((s >> 8) + s) >> 8)];
                        a = p->trans[i];
                        s = (unsigned short)(p->gamma_to_1[e[2]] * a + (0xff - a) * d2 + 0x80);
                        e[2] = p->gamma_from_1[(unsigned char)(((s >> 8) + s) >> 8)];
                    }
                }
            } else {
                unsigned int m = (1u << p->bit_depth) - 1;
                double M = (double)m;
                double C0 = 1.0;
                double C1 = 1.0;
                switch (p->background_gamma_type) {
                case 1:
                    C0 = p->screen_gamma;
                    C1 = 1.0;
                    break;
                case 2:
                    C0 = 1.0 / p->gamma;
                    C1 = 1.0 / ((double)p->screen_gamma * p->gamma);
                    break;
                case 3:
                    C0 = 1.0 / p->background_gamma;
                    C1 = 1.0 / ((double)p->screen_gamma * p->background_gamma);
                    break;
                }
                if (mode & 2) {
                    double inv = 1.0 / M;
                    double v1 = p->background.red * inv;
                    p->background_1.red = (unsigned short)(int)(__int64)(pow(v1, C0) * M + 0.5);
                    double v2 = p->background.green * inv;
                    p->background_1.green = (unsigned short)(int)(__int64)(pow(v2, C0) * M + 0.5);
                    double v3 = p->background.blue * inv;
                    p->background_1.blue = (unsigned short)(int)(__int64)(pow(v3, C0) * M + 0.5);
                    p->background.red = (unsigned short)(int)(__int64)(pow(v1, C1) * M + 0.5);
                    p->background.green = (unsigned short)(int)(__int64)(pow(v2, C1) * M + 0.5);
                    p->background.blue = (unsigned short)(int)(__int64)(pow(v3, C1) * M + 0.5);
                } else {
                    double v = p->background.gray / M;
                    p->background_1.gray = (unsigned short)(int)(__int64)(pow(v, C0) * M + 0.5);
                    p->background.gray = (unsigned short)(int)(__int64)(pow(v, C1) * M + 0.5);
                }
            }
        } else if (mode == 3) {
            int n = p->num_palette;
            if (n > 0) {
                unsigned char *e = ((unsigned char *)p->palette);
                for (i = 0; i < n; i++) {
                    e[0] = p->gamma_table[e[0]];
                    e[1] = p->gamma_table[e[1]];
                    e[2] = p->gamma_table[e[2]];
                    e += 3;
                }
            }
        }
    } else if ((flags & 0x80) && mode == 3) {
        int n = p->num_trans;
        unsigned char r = (unsigned char)p->background.red;
        unsigned char g = (unsigned char)p->background.green;
        unsigned char b = (unsigned char)p->background.blue;
        if (n > 0) {
            unsigned char *e = ((unsigned char *)p->palette);
            for (i = 0; i < n; i++) {
                unsigned int a = p->trans[i];
                if (a == 0) {
                    e[0] = r;
                    e[1] = g;
                    e[2] = b;
                } else if (a != 0xff) {
                    unsigned int s = (unsigned short)((0xff - a) * r + e[0] * a + 0x80);
                    e[0] = (unsigned char)(((s >> 8) + s) >> 8);
                    a = p->trans[i];
                    s = (unsigned short)((0xff - a) * g + e[1] * a + 0x80);
                    e[1] = (unsigned char)(((s >> 8) + s) >> 8);
                    a = p->trans[i];
                    s = (unsigned short)((0xff - a) * b + e[2] * a + 0x80);
                    e[2] = (unsigned char)(((s >> 8) + s) >> 8);
                }
                e += 3;
            }
        }
    }

    if ((p->transformations & 8) && mode == 3) {
        int s0 = 8 - p->sig_bit.red;
        int s1 = 8 - p->sig_bit.green;
        int s2 = 8 - p->sig_bit.blue;
        unsigned short n = p->num_palette;
        if (s0 < 0 || s0 > 8) s0 = 0;
        if (s1 < 0 || s1 > 8) s1 = 0;
        if (s2 < 0 || s2 > 8) s2 = 0;
        for (i = 0; i < n; i++) {
            ((unsigned char *)p->palette)[i * 3] >>= s0;
            ((unsigned char *)p->palette)[i * 3 + 1] >>= s1;
            ((unsigned char *)p->palette)[i * 3 + 2] >>= s2;
        }
    }
}


// 0x002dcd90 FUN_002dcd90 (1025 B): matches/0x002dcd90.cpp
// sym: ?FUN_002dcd90@fn_fcd359fc@@YAXPAUPngStruct@@@Z
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
            FUN_002db6b0((png_row_info_2dcd90 *)(&png_ptr->row_info), png_ptr->row_buf + 1, (void *)png_ptr->palette, (unsigned char *)(void *)(png_ptr->trans), png_ptr->num_trans);
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
        FUN_002d93f0((png_row_info_2dcd90 *)(&png_ptr->row_info), png_ptr->row_buf + 1, (unsigned char *)(&png_ptr->shift));
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
    object->transformations |= 1;
}


// 0x002dd230 FUN_002dd230 (30 B): matches/0x002dd230.cpp
// sym: ?FUN_002dd230@fn_fcd359fc@@YAHPAX@Z
int __cdecl FUN_002dd230(void* p) {
    if (((PngStruct*)p)->interlaced) {
        ((PngStruct*)p)->transformations |= 2;
        return 7;
    }
    return 1;
}


// 0x002dd250 FUN_002dd250 (90 B): matches/0x002dd250.cpp
// sym: _FUN_002dd250
extern "C" void FUN_002dd250(Obj_2dd250* p, unsigned char b, int mode) {
    unsigned int* q = &p->transformations;
    *q |= 0x8000;
    p->filler = b;
    if (mode == 1)
        p->flags |= 0x80;
    else
        p->flags &= 0xffffff7f;
    if (p->color_type == 2)
        p->usr_channels = 4;
    if (p->color_type == 0 && p->bit_depth >= 8)
        p->usr_channels = 2;
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
    ReadFn_2dd690 fn = ((Obj_2dd690 *)p)->read_data_fn;
    if (fn)
        fn(((Obj_2dd690 *)p), (unsigned char *)data, length);
    else
        Fail_002e69a0(((Obj_2dd690 *)p), "Call to NULL read function");
}


// 0x002dd6b0 FUN_002dd6b0 (51 B): matches/0x002dd6b0.cpp
// sym: ?readFile@fn_fcd359fc@@YAXPAUPngStruct@@PAXI@Z
void __cdecl readFile(File_2dd6b0* file, void* dest, unsigned int count) {
    if (fread(dest, 1, count, file->io_ptr) != count)
        report(file, "Read Error");
}


// 0x002dd6f0 FUN_002dd6f0 (83 B): matches/0x002dd6f0.cpp
// sym: _FUN_002dd6f0
extern "C" void FUN_002dd6f0(void * p, void* value, void* fn) {   // (x64t16) png_set_read_fn (png, io_ptr, read_data_fn)
    ((Obj_2dd6f0 *)p)->io_ptr = value;
    if (fn)
        ((Obj_2dd6f0 *)p)->read_data_fn = (PngRwFn)fn;
    else
        ((Obj_2dd6f0 *)p)->read_data_fn = (PngRwFn)&readFile;   // (x64t16) png_default_read_data (0x002dd6b0) itself
    if (((Obj_2dd6f0 *)p)->write_data_fn) {
        ((Obj_2dd6f0 *)p)->write_data_fn = 0;
        FUN_002e69d0((Obj_2dd6f0 *)((Obj_2dd6f0 *)p), (void *)(const char *)"It's an error to set both read_data_fn and write_data_fn in the ");
        FUN_002e69d0((Obj_2dd6f0 *)((Obj_2dd6f0 *)p), (void *)(const char *)"same structure.  Resetting write_data_fn to NULL.");
    }
    ((Obj_2dd6f0 *)p)->output_flush_fn = 0;
}

} // namespace fn_fcd359fc
