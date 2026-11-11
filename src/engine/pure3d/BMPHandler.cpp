// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002af2d0..0x002afb30 (kind game, layer engine, confidence high), dominant class pure3d::BMPHandler
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f24f7502 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f24f7502 {} using namespace fn_f24f7502;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f24f7502 {
void *__cdecl FUN_00266e00(unsigned int count, unsigned int size);
void __cdecl FUN_00267090(void *p);
struct Reader {
  public:
    int FUN_00263fc0();
};
class Writer_2af510 {
public:
    virtual void vfunc_0(int width, int height, int bitsPerPixel, int flag, unsigned int *palette);
    virtual void vfunc_1();
    virtual void vfunc_2(unsigned char *row);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
};
struct ImageHeader {
    char pad00[8];
    int dataEnd;
    char pad0c[4];
    int width;
    int height;
    char pad18[0x2c - 0x18];
    int paletteCount;
};
struct Stream {
 int FUN_00263fc0();
};
struct Info_2af670 { char pad0[8]; int position; char pad1[4]; int width; int height; char pad2[20]; int paletteCount; };
struct Image {
 virtual void init(int,int,int,int,void*);
 virtual void slot1();
 virtual void row(void*);
 virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual int finish();
};
extern void* __cdecl FUN_00266e00(int,int);
struct Header_2af8c0 {
    unsigned magic;
    unsigned char b4, b5, b6, b7;
    unsigned w8, wc, w10, w14;
    unsigned short s18, s1a;
    unsigned w1c, w20, w24, w28, w2c, w30;
};

} // namespace fn_f24f7502

// 0x002af2d0 FUN_002af2d0 (529 B): equivalent/0x002af2d0.cpp [wrapped: conflict: pure3d::BMPHandler; pure3d::DXTNHandler; pure3d::ImageHandler; pure3d::PNGHandler (+2)]
// sym: ?FUN_002af2d0@ImageRegistry_2af2d0@fn_002af2d0@@QAEPAV12@XZ @36aed03f4066 @w0b397d9dd580
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_002af2d0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_002af2d0 @ 0x002af2d0


extern "C" void *FUN_0008d690(unsigned int size);
void *FUN_00263ea0(unsigned int size);

class Manager_2af2d0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int getA();
    virtual int getB();
};

struct ImageConverter {
    ImageConverter *FUN_002de230();
};

namespace pure3d {

class ImageHandler {
public:
    __forceinline ImageHandler() : f04(0), f08(0), f0c(0) {
        f10 = (*(Manager_2af2d0**)&DAT_0052c2a4)->getB();
        f14 = (*(Manager_2af2d0**)&DAT_0052c2a4)->getA();
    }
    virtual void slot0();
    virtual void slot1_000382a0();
    virtual void slot2();
    virtual void slot3_002aea70(void*, void*);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual char slot7_002ae8a0(void*);
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11_00291bf0(int);
    virtual void slot12_00291c00();
    virtual void slot13_00291c10(char);
    virtual void slot14_00291c20();
    virtual void slot15();
    int f04;
    int f08;
    char f0c;
    int f10;
    int f14;
};

class PNGHandler : public ImageHandler {
public:
    __forceinline PNGHandler() {}
    virtual void slot0();
};
class BMPHandler : public ImageHandler {
public:
    __forceinline BMPHandler() {}
    virtual void slot0();
};
class TargaHandler : public ImageHandler {
public:
    __forceinline TargaHandler() {}
    virtual void slot0();
};
class RawImageHandler : public ImageHandler {
public:
    __forceinline RawImageHandler() {}
    virtual void slot0();
};
class DXTNHandler : public ImageHandler {
public:
    __forceinline DXTNHandler() {}
    virtual void slot0();
};

}

class ImageRegistry_2af2d0 {
public:
    int count;
    pure3d::ImageHandler *handlers[0x20];
    ImageConverter *converter;
    char flag88;
    char flag89;
    char flag8a;
    char pad8b;
    int f8c;
    int pad90;
    int f94;
    int f98;
    int f9c;
    int fa0;

    ImageRegistry_2af2d0 *FUN_002af2d0();
};

ImageRegistry_2af2d0 *ImageRegistry_2af2d0::FUN_002af2d0()
{
    count = 0;
    flag88 = 0;
    flag89 = 0;
    flag8a = 0;
    f8c = 0x20;
    f94 = 8;
    f98 = 0;
    f9c = 0;
    fa0 = 0;
    void *mem = FUN_0008d690(4);
    ImageConverter *conv = 0;
    if (mem)
        conv = ((ImageConverter *)mem)->FUN_002de230();
    converter = conv;

    pure3d::ImageHandler *h = 0;
    mem = FUN_00263ea0(0x18);
    if (mem)
        h = new (mem) pure3d::PNGHandler;
    h->slot0();
    handlers[count] = h;
    count = count + 1;

    h = 0;
    mem = FUN_00263ea0(0x18);
    if (mem)
        h = new (mem) pure3d::BMPHandler;
    h->slot0();
    handlers[count] = h;
    count = count + 1;

    h = 0;
    mem = FUN_00263ea0(0x18);
    if (mem)
        h = new (mem) pure3d::TargaHandler;
    h->slot0();
    handlers[count] = h;
    count = count + 1;

    h = 0;
    mem = FUN_00263ea0(0x18);
    if (mem)
        h = new (mem) pure3d::RawImageHandler;
    h->slot0();
    handlers[count] = h;
    count = count + 1;

    h = 0;
    mem = FUN_00263ea0(0x18);
    if (mem)
        h = new (mem) pure3d::DXTNHandler;
    h->slot0();
    handlers[count] = h;
    count = count + 1;
    return this;
}
} // namespace fn_002af2d0


// 0x002af4f0 pure3d::BMPHandler::vfunc_8 (15 B): matches/0x002af4f0.cpp
// sym: ?vfunc_8@BMPHandler@pure3d@@UAE_NH@Z
bool pure3d::BMPHandler::vfunc_8(int value) {
    return value == 3;
}


// 0x002af500 pure3d::BMPHandler::vfunc_10 (5 B): matches/0x002af500.cpp
// sym: ?vfunc_10@BMPHandler@pure3d@@UAE_NHH@Z
// Same code shape as 0x000d7a40 (propagated; names are from that function)
bool pure3d::BMPHandler::vfunc_10(int , int ) {
    return false;
}

namespace fn_f24f7502 {

// 0x002af510 FUN_002af510 (341 B): equivalent/0x002af510.cpp
// sym: _FUN_002af510 @d9bb23ac1e24 @w135ea3e98c8d
// STATUS: equivalent (tools/equiv.py level 3: 144 inputs, branch coverage 16/16)
// FUN_002af510 @ 0x002af510
extern "C" void __cdecl FUN_002af510(void *reader, void *img, void *writer)
{
    unsigned int palette[16];
    int i;
    int n = ((ImageHeader *)img)->paletteCount;

    for (i = 0; i < 16; i++)
        palette[i] = 0;
    if (n == 0)
        n = 16;

    ((owners::X_2647e0 *)(((Reader *)reader)))->FUN_002647e0((hulk_intptr)palette, (hulk_intptr)n, 4, (hulk_intptr)1);
    for (i = 0; i < n; i++) {
        palette[i] |= 0xff000000;
        palette[i] = palette[i];
    }

    ((Writer_2af510 *)writer)->vfunc_0(((ImageHeader *)img)->width, ((ImageHeader *)img)->height, 4, 1, palette);
    int position = ((Reader *)reader)->FUN_00263fc0(); // MSVC evaluates the call before reading dataEnd
    ((owners::S_264510 *)(((Reader *)reader)))->FUN_00264510((unsigned)(((ImageHeader *)img)->dataEnd - position));

    int width = ((ImageHeader *)img)->width;
    int packed = width / 2;
    int pad = 0;
    if ((packed & 3) != 0)
        pad = 4 - (packed & 3);

    unsigned char *src = (unsigned char *)FUN_00266e00(1, packed);
    unsigned char *row = (unsigned char *)FUN_00266e00(1, width);

    for (int y = 0; y < ((ImageHeader *)img)->height; y++) {
        ((owners::X_2647e0 *)(((Reader *)reader)))->FUN_002647e0((hulk_intptr)src, (hulk_intptr)packed, 1, (hulk_intptr)1);
        for (i = 0; i < packed; i++) {
            row[i * 2] = src[i] >> 4;
            row[i * 2 + 1] = src[i] & 0xf;
        }
        ((Writer_2af510 *)writer)->vfunc_2(row);
        ((owners::S_264510 *)(((Reader *)reader)))->FUN_00264510((unsigned)pad);
    }
    FUN_00267090(src);
    FUN_00267090(row);
    ((Writer_2af510 *)writer)->vfunc_10();
}


// 0x002af670 FUN_002af670 (284 B): equivalent/0x002af670.cpp
// sym: _FUN_002af670 @46fde2cde988 @w9d6d4be76372
// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 12/12)
// FUN_002af670 @ 0x002af670
// equiv-conv: FUN_002af670 esi ebx stack
extern "C" int __cdecl FUN_002af670(void * info, void * stream, void * image) {
 unsigned int palette[256] = {0};
 int count = ((Info_2af670 *)info)->paletteCount;
 if (!count) count = 256;
 ((owners::X_2647e0 *)(((Stream *)stream)))->FUN_002647e0((hulk_intptr)palette, (hulk_intptr)count, 4, (hulk_intptr)1);
 for(int i=0;i<count;++i) palette[i] |= 0xff000000;
 ((Image *)image)->init(((Info_2af670 *)info)->width,((Info_2af670 *)info)->height,8,1,palette);
 int position=((Stream *)stream)->FUN_00263fc0();
 ((owners::S_264510 *)(((Stream *)stream)))->FUN_00264510((unsigned)(((Info_2af670 *)info)->position-position));
 int width=((Info_2af670 *)info)->width;
 int padding=(width & 3) ? 4-(width & 3):0;
 void* buffer=FUN_00266e00(1,width);
 for(int y=0;y<((Info_2af670 *)info)->height;++y) {
 ((owners::X_2647e0 *)(((Stream *)stream)))->FUN_002647e0((hulk_intptr)buffer, (hulk_intptr)width, 1, (hulk_intptr)1);
 ((Image *)image)->row(buffer);
 ((owners::S_264510 *)(((Stream *)stream)))->FUN_00264510((unsigned)padding);
 }
 FUN_00267090(buffer);
 return ((Image *)image)->finish();
}

} // namespace fn_f24f7502

// 0x002af790 FUN_002af790 (291 B): equivalent/0x002af790.cpp [wrapped: conflict: FUN_00266e00]
// sym: _FUN_002af790 @4877b3ce62b1 @w13fc6d1baaa7
namespace fn_002af790 {
// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 10/10)
// FUN_002af790 @ 0x002af790
struct Header_2af790 { char pad[16]; int width; int height; };
struct Reader {   };
struct Output_2af790 { virtual void init(int,int,int,int,int); virtual void row(unsigned char*); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual int finish(); };
extern unsigned char* __cdecl FUN_00266e00(int,int);
extern void __cdecl FUN_00267090(unsigned char*);
// equiv-conv: FUN_002af790 edi stack stack
extern "C" int __cdecl FUN_002af790(void * reader, void * header, void * output) {
 ((Output_2af790 *)output)->init(((Header_2af790 *)header)->width,((Header_2af790 *)header)->height,24,1,0);
 struct Locals { unsigned short unused; unsigned char b,c; unsigned char* buffer; int padding; int row; int width; int unused2; unsigned char a; } s;
 s.width=((Header_2af790 *)header)->width;
 s.padding=s.width & 3;
 s.buffer=FUN_00266e00(1,s.width*4);
 s.row=0;
 while(s.row<((Header_2af790 *)header)->height) {
  for(int x=0;x<s.width;++x) {
   ((owners::X_2647e0 *)(((Reader *)reader)))->FUN_002647e0((hulk_intptr)(&s.a), (hulk_intptr)1, 1, (hulk_intptr)1);
   s.buffer[x*4]=s.a;
   ((owners::X_2647e0 *)(((Reader *)reader)))->FUN_002647e0((hulk_intptr)(&s.b), (hulk_intptr)1, 1, (hulk_intptr)1);
   s.buffer[x*4+1]=s.b;
   ((owners::X_2647e0 *)(((Reader *)reader)))->FUN_002647e0((hulk_intptr)(&s.c), (hulk_intptr)1, 1, (hulk_intptr)1);
   s.buffer[x*4+2]=s.c;
   s.buffer[x*4+3]=255;
  }
  ((owners::S_264510 *)(((Reader *)reader)))->FUN_00264510((unsigned)(s.padding));
  ((Output_2af790 *)output)->row(s.buffer);
  ++s.row;
 }
 FUN_00267090(s.buffer);
 return ((Output_2af790 *)output)->finish();
}
} // namespace fn_002af790

namespace fn_f24f7502 {

// 0x002af8c0 FUN_002af8c0 (414 B): equivalent/0x002af8c0.cpp
// sym: _FUN_002af8c0 @af8ebae87531 @w2c370d48e3da
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_002af8c0 @ 0x002af8c0
// equiv-conv: FUN_002af8c0 esi edi
extern "C" void FUN_002af8c0(void *h, void *r)
{
    unsigned tmp;

    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->magic = tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 1, (hulk_intptr)1)); ((Header_2af8c0 *)h)->b4 = (unsigned char)tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 1, (hulk_intptr)1)); ((Header_2af8c0 *)h)->b5 = (unsigned char)tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 1, (hulk_intptr)1)); ((Header_2af8c0 *)h)->b6 = (unsigned char)tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 1, (hulk_intptr)1)); ((Header_2af8c0 *)h)->b7 = (unsigned char)tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->w8 = tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->wc = tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->w10 = tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->w14 = tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 2, (hulk_intptr)1)); ((Header_2af8c0 *)h)->s18 = (unsigned short)tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 2, (hulk_intptr)1)); ((Header_2af8c0 *)h)->s1a = (unsigned short)tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->w1c = tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->w20 = tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->w24 = tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->w28 = tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->w2c = tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->w30 = tmp;
}

} // namespace fn_f24f7502

// 0x002afa60 pure3d::BMPHandler::vfunc_9 (195 B): equivalent/0x002afa60.cpp [wrapped: conflict: pure3d::BMPHandler]
// sym: ?vfunc_9@BMPHandler@pure3d@fn_002afa60@@UAEXTStreamArg@3@PAUOutput@3@@Z @ce4128d26481 @wa66696a928b3
namespace fn_002afa60 {
// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 20/20)
// pure3d::BMPHandler::vfunc_9 @ 0x002afa60
// BMP loader: checks the "BM" magic and the header, then hands 4, 8 and 24 bit images to their readers.
struct Reader {
    char pad00[0xc];
    char open;
    char pad0d;
    char binary;
    char pad0f[0x11];
    char FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Header_2afa60 {
    unsigned magic;
    unsigned char b4, b5, b6, b7;
    unsigned w8, wc, w10, w14;
    unsigned short s18, bitCount;   // 0x1a
    unsigned compression;           // 0x1c
    unsigned w20, w24, w28, w2c, w30;
};

struct Output;

// equiv-conv: FUN_002af8c0 esi edi
extern "C++" __declspec(nothrow) void __cdecl FUN_002af8c0(void *, void *);
extern "C++" __declspec(nothrow) void __cdecl FUN_002af510(void *, void *, void *);
// equiv-conv: FUN_002af670 esi ebx stack
extern "C++" __declspec(nothrow) int __cdecl FUN_002af670(void *, void *, void *);
// equiv-conv: FUN_002af790 edi stack stack
extern "C++" __declspec(nothrow) int __cdecl FUN_002af790(void *, void *, void *);

// The stream pointer's argument slot is reused for the two magic bytes.
union StreamArg {
    Reader *reader;
    unsigned short magic;
};

namespace pure3d {
class BMPHandler {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9(StreamArg stream, Output *out);
    virtual void vfunc_10();
};
}

void pure3d::BMPHandler::vfunc_9(StreamArg stream, Output *out)
{
    Header_2afa60 h;
    Reader *reader = stream.reader;
    reader->FUN_002647e0(&stream.magic, 2, 1, 1);
    if ((stream.magic & 0xff) == 'B' && (stream.magic >> 8) == 'M') {
        FUN_002af8c0((Header_2afa60 *)(&h), (Reader *)reader);
        unsigned short bits = h.bitCount;
        if ((bits == 1 || bits == 4 || bits == 8 || bits == 0x18) && h.compression == 0) {
            if (bits == 4)
                FUN_002af510((Reader *)reader, (Header_2afa60 *)(&h), (Output *)out);
            else if (bits == 8)
                FUN_002af670((Header_2afa60 *)(&h), (Reader *)reader, (Output *)out);
            else if (bits == 0x18)
                FUN_002af790((Reader *)reader, (Header_2afa60 *)(&h), (Output *)out);
        }
    }
}
} // namespace fn_002afa60

