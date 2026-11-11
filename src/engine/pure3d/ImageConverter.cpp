// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002de230..0x002dee20 (kind game, layer engine, confidence high), dominant class pure3d::ImageConverter
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f9c3d788 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f9c3d788 {} using namespace fn_f9c3d788;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f9c3d788 {
class ImageConverter_2de230 {
  public:
    ImageConverter_2de230();
    virtual ~ImageConverter_2de230();
};
extern void* hulk_at_0042f900;
extern char DAT_004d098c[];
extern char DAT_004d09a8[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern void *__cdecl FUN_00263ea0(unsigned int size);
struct Sub_2de250 {
    char data[8];
    void FUN_0027af70(Sub_2de250 *src);
};
struct Image {
    char pad0[8];
    Sub_2de250 sub;
    int width;
    int height;
    int format;
    char pad1c[4];
    int extra;
};
class Surface_2de250 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual int GetKind();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void SetProperty(int key, int value);
    virtual void s12();
    virtual int s13(int a, int b);
    virtual void s14(int a);
};
class Source_2de250 {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual int GetValue();
};
class Texture {
public:
    virtual void t0();
    virtual void Release();
    char pad4[4];
    Sub_2de250 sub;
    Surface_2de250 *surface;
    Texture *FUN_002c1c30();
    bool FUN_002c1c70(int w, int h, int fmt, int extra, int a, int mode, int b);
};
class Game_2de250 {
public:
    virtual void g0();
    virtual void g1();
    virtual int GetState();
};
class ImageConverter {
  public:
    virtual void _m_vf0();
    virtual Texture *vfunc_1(Image *img, bool flag);
    virtual void _m_vf2();
    virtual int f3(void** items, int count, void* a, void* b);
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void f6(void* item, int n, int i);
    virtual void vfunc_7(Image *img, int value);
    virtual void f8(void*, void*);
    void* vfunc_4(void* p);
};
class Other_2de390 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual int n(void*, int);
    virtual void o(void*);
};
} // namespace fn_f9c3d788
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned int);
#endif
namespace fn_f9c3d788 {
struct Src {
    char pad[0x24];
    char* data;
};
struct Info {
    int size;
    int count;
    char pad[0x40];
    int stride;
    char pad2[4];
    char* dest;
};
struct Format_2de600 {
 unsigned width, height;
 char pad08[16];
 unsigned redLeft, greenLeft, blueLeft, alphaLeft;
 unsigned redRight, greenRight, blueRight, alphaRight;
 char pad38[16];
 int pitch;
};
struct Source_2de6c0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual unsigned int pixel(int x,int y);
};
struct Format_2de6c0 {
 int width,height;
 char pad08[16];
 unsigned int redLeft,greenLeft,blueLeft,alphaLeft;
 unsigned int redRight,greenRight,blueRight,alphaRight;
 char pad38[16];
 int pitch;
};
struct PixelFormat_2de790 {
 unsigned width, height;
 char reserved08[12];
 unsigned char directCopy;
 char reserved15[3];
 unsigned redLeft, greenLeft, blueLeft, alphaLeft;
 unsigned redRight, greenRight, blueRight, alphaRight;
 char reserved38[16];
 unsigned pitch;
};
struct Source_2de8b0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
 virtual unsigned int pixel(int x,int y);
};
struct Format_2de8b0 {
 int width,height; char pad08[16];
 unsigned int redOut,greenOut,blueOut,alphaOut;
 unsigned int redIn,greenIn,blueIn,alphaIn;
 char pad38[16]; int pitch;
};
struct Item {
  public:
    char _m_pad_0[0x18];
    union { int kind; int type; };
    char _m_pad_1c[0x8];
    void *data;
};
struct Context {
  public:
    char _m_pad_0[0x50];
    void *value;
};
struct Context;
extern "C" void __cdecl FUN_002de600(unsigned short *, const unsigned *, const void *);
extern "C" void __cdecl FUN_002de6c0(unsigned short *, void *, void *);
extern "C" void __cdecl FUN_002de790(unsigned char *, void *, const unsigned *);
extern "C" void __cdecl FUN_002de8b0(unsigned int *, void *, void *);
typedef unsigned int u32_2dea00;
void* alloc_00263ea0(hulk_uintptr);
class Image32_2dea00 {
  public:
    void* run_002bffc0();
};
struct PixelFormat_2dea50 {
    char pad0[8];
    int bits;                   // 0x08
    char pad0c[0x18 - 0x0c];
    int rShift;                 // 0x18
    int gShift;                 // 0x1c
    int bShift;                 // 0x20
    char pad24[4];
    int rDst;                   // 0x28
    int gDst;                   // 0x2c
    int bDst;                   // 0x30
    char pad34[4];
    unsigned int rMask;         // 0x38
    unsigned int gMask;         // 0x3c
    unsigned int bMask;         // 0x40
    char pad44[4];
    int pitch;                  // 0x48
    char pad4c[4];
    unsigned char *pixels;      // 0x50
};
struct Image_2dea50 {
    char pad0[0x10];
    int width;                  // 0x10
    int height;                 // 0x14
    char pad18[0x24 - 0x18];
    unsigned int *dst;          // 0x24
};
extern "C" void __cdecl FUN_0028fcc0(const char* format, ...);
struct SourceImage {
    int width;            // 0x00
    int height;           // 0x04
    char pad08[8];
    int format;           // 0x10
};
struct Texture_2deca0 {
    char pad00[0x10];
    int width;            // 0x10
    int height;           // 0x14
    const char* FUN_0027b000();
};
extern "C" void __stdcall FUN_002de5a0(void *, void *);
extern "C" void __stdcall FUN_002de990(void *, void *);
extern "C" void __stdcall FUN_002de9c0(void *, void *);
struct Image_2ded30 {
    char pad[0x10];
    int width;
    int height;
};
struct Surface_2ded30 {
    int width;
    int height;
    char pad08[4];
    int rows;
    int format;
    char pad14[0x4c - 0x14];
    int stride;
    int cursor;
};


// 0x002de230 FUN_002de230 (9 B): matches/0x002de230.cpp
// sym: ??0ImageConverter_2de230@fn_f9c3d788@@QAE@XZ
// Same code shape as 0x000b3de0 (propagated; names are from that function)
ImageConverter_2de230::ImageConverter_2de230() {}


// 0x002de240 FUN_002de240 (7 B): matches/0x002de240.cpp
// sym: ?FUN_002de240@fn_f9c3d788@@YIXPAX@Z
// Same code shape as 0x001b6820 (propagated; names are from that function)
void __fastcall FUN_002de240(void* self) {
    *(void**)self = &hulk_at_0042f900;
}


// 0x002de250 pure3d::ImageConverter::vfunc_1 (309 B): equivalent/0x002de250.cpp
// sym: ?vfunc_1@ImageConverter@fn_f9c3d788@@UAEPAVTexture@2@PAUImage@2@_N@Z @29a8f2592261 @w466f3f130ab0
// STATUS: equivalent (tools/equiv.py level 3: 96 inputs, branch coverage 23/24, incomplete)
// pure3d::ImageConverter::vfunc_1 @ 0x002de250
Texture *ImageConverter::vfunc_1(Image *img, bool flag)
{
    Texture *tex;
    Texture *mem = (Texture *)FUN_00263ea0(0x18);
    if (mem)
        tex = mem->FUN_002c1c30();
    else
        tex = 0;

    if (img)
        tex->sub.FUN_0027af70(&img->sub);

    int mode = 0;
    if (img->format == 8)
        mode = 1;
    if (flag)
        mode = 0xb;

    if (!tex->FUN_002c1c70(img->width, img->height, img->format, img->extra, 0, mode, 0)) {
        if ((*(Game_2de250**)&DAT_0052c2a0)->GetState() != 1) {
            tex->Release();
            return 0;
        }
    }

    if (tex) {
        Surface_2de250 *s = tex->surface;
        vfunc_7(img, s->s13(0, 0));
        s->s14(0);
        Source_2de250 *src = (Source_2de250 *)FUN_00344e74(img, 0, DAT_004d098c, DAT_004d09a8, 0);
        if (src) {
            if (s->GetKind() == 7 || s->GetKind() == 8)
            {
                int v = src->GetValue();
                tex->surface->SetProperty(0x100, v);
            }
        }
    }
    return tex;
}


// 0x002de390 pure3d::ImageConverter::vfunc_3 (88 B): matches/0x002de390.cpp
// sym: ?f3@ImageConverter@fn_f9c3d788@@UAEHPAPAXHPAX1@Z
int ImageConverter::f3(void** items, int count, void* a, void* b) {
    Other_2de390* obj = *(Other_2de390**)((char*)a + 0x10);
    int n = obj->n(b, 0);
    for (int i = 0; i < count; ++i)
        f6(items[i], n, i);
    obj->o(b);
    return (hulk_intptr)a;
}

} // namespace fn_f9c3d788

// 0x002de3f0 pure3d::ImageConverter::vfunc_2 (293 B): equivalent/0x002de3f0.cpp [wrapped: conflict: DAT_004d098c; Image; pure3d::ImageConverter]
// sym: ?vfunc_2@ImageConverter@pure3d@fn_002de3f0@@UAEPAUTexture_2de3f0@3@PAPAUImage@3@HHH@Z @af968681bc51 @w38161c7b12de
namespace fn_002de3f0 {
// STATUS: equivalent (tools/equiv.py level 3: 222 inputs, branch coverage 20/20)
// pure3d::ImageConverter::vfunc_2 @ 0x002de3f0

struct Name_2de3f0 { void FUN_0027af70(Name_2de3f0*); };
struct Texture { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(int,int); virtual void s12(); virtual void* s13(int,int); virtual void s14(int); };
struct Image { virtual void s0(); virtual void s1(); char pad4[4]; Name_2de3f0 name; char pad12[4]; int width,height,depth; char pad28[4]; int format; };
struct Texture_2de3f0 { virtual void s0(); virtual void s1(); char pad4[4]; Name_2de3f0 name; char pad12[4]; Texture* texture; char pad20[4]; Texture_2de3f0* FUN_002c1c30(); bool FUN_002c1cf0(int,int,int,int,int,int,int,int); };
struct Service_2de3f0 { virtual void s0(); virtual void s1(); virtual int s2(); };
struct Extra_2de3f0 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual int s18(); };
extern char DAT_004d098c[],DAT_004d09a8[];
void* __cdecl FUN_00263ea0(int);
Extra_2de3f0* __cdecl FUN_00344e74(Image*,int,void*,void*,int);
namespace pure3d { struct ImageConverter { virtual void vfunc_0(); virtual void vfunc_1(); virtual Texture_2de3f0* vfunc_2(Image**,int,int,int); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(Image*,void*,int); virtual void vfunc_7(); virtual void vfunc_8(); }; }
Texture_2de3f0* pure3d::ImageConverter::vfunc_2(Image** images,int count,int a,int b) {
 void* mem=FUN_00263ea0(24);
 Texture_2de3f0* result=mem?((Texture_2de3f0*)mem)->FUN_002c1c30():0;
 if(images[0]) result->name.FUN_0027af70(&images[0]->name);
 Image* image=images[0];
 int bits=image->depth==8?8:32; int indexed=image->depth==8?1:0;
 if(!result->FUN_002c1cf0(image->width,image->height,count,bits,image->format,a,indexed,b)) {
 int kind=(*(Service_2de3f0**)&DAT_0052c2a0)->s2();
 if(kind!=1){result->s1();result=0;}
 }
 Texture* texture=result->texture;
 void* data=texture->s13(0,0);
 for(int i=0;i<count;++i) vfunc_6(images[i],data,i);
 texture->s14(0);
 Extra_2de3f0* extra=FUN_00344e74(images[0],0,DAT_004d098c,DAT_004d09a8,0);
 if(extra){int value=extra->s18();result->texture->s11(256,value);}
 return result;
}
} // namespace fn_002de3f0


// 0x002de520 pure3d::ImageConverter::vfunc_5 (114 B): matches/0x002de520.cpp [wrapped: conflict: ImageConverter]
// sym: ?vfunc_5@ImageConverter@fn_002de520@@UAEXPAXPAVSource_2de520@2@H@Z
namespace fn_002de520 {
// pure3d::ImageConverter::vfunc_5 @ 0x002de520
extern "C++" __declspec(nothrow) void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);
extern char DAT_004d098c[];
extern char DAT_004d09a8[];

class Target_2de520 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual void SetOption(int option, int value);      // slot 11 (0x2c)
    virtual void v12();
    virtual int GetProperty(int key, int flags);        // slot 13 (0x34)
    virtual void Select(int key);                       // slot 14 (0x38)
};

class Converted {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual int GetValue();                             // slot 18 (0x48)
};

class Source_2de520 {
public:
    char pad0[0x10];
    Target_2de520* target;     // 0x10
};

class ImageConverter {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual void vfunc_5(void* dest, Source_2de520* src, int key);
    virtual void v6();
    virtual void Apply(void* dest, int value);         // slot 7 (0x1c)
};

void ImageConverter::vfunc_5(void* dest, Source_2de520* src, int key)
{
    if (src == 0)
        return;
    Apply(dest, src->target->GetProperty(key, 0));
    src->target->Select(key);
    Converted* c = (Converted*)FUN_00344e74(dest, 0, DAT_004d098c, DAT_004d09a8, 0);
    if (c != 0) {
        int value = c->GetValue();
        src->target->SetOption(0x100, value);
    }
}
} // namespace fn_002de520

namespace fn_f9c3d788 {

// 0x002de5a0 FUN_002de5a0 (85 B): matches/0x002de5a0.cpp
// sym: _FUN_002de5a0@8
extern "C" void __stdcall FUN_002de5a0(void * src, void * info) {
    char* dst = ((Info *)info)->dest;
    char* p = ((Src *)src)->data;
    for (int i = 0; i < ((Info *)info)->count; ++i) {
        memcpy(dst, p, ((Info *)info)->size);
        p += ((Info *)info)->size;
        dst += ((Info *)info)->stride;
    }
}


// 0x002de600 FUN_002de600 (190 B): equivalent/0x002de600.cpp
// sym: _FUN_002de600 @00cf051f4d1e @wd4f77d3b59a9
// STATUS: equivalent (tools/equiv.py level 3: 60 inputs, branch coverage 8/8)
// FUN_002de600 @ 0x002de600
// equiv-conv: FUN_002de600 eax ecx esi
extern "C" void FUN_002de600(unsigned short* destination, const unsigned* source, const void * format)
{
 int padding = (((const Format_2de600 *)format)->pitch - (int)(((const Format_2de600 *)format)->width * 2)) / 2;
 unsigned rows = ((const Format_2de600 *)format)->height;
 if (rows) {
   do {
     unsigned count = ((const Format_2de600 *)format)->width;
     if (count) {
       do {
         unsigned pixel = *source++;
         unsigned result = (((pixel & 0xffu) >> (((const Format_2de600 *)format)->blueRight & 31)) << (((const Format_2de600 *)format)->blueLeft & 31));
         result |= (((pixel & 0xff0000u) >> (((const Format_2de600 *)format)->redRight & 31)) << (((const Format_2de600 *)format)->redLeft & 31));
         result |= (((pixel & 0xff000000u) >> (((const Format_2de600 *)format)->alphaRight & 31)) << (((const Format_2de600 *)format)->alphaLeft & 31));
         result |= (((pixel & 0xff00u) >> (((const Format_2de600 *)format)->greenRight & 31)) << (((const Format_2de600 *)format)->greenLeft & 31));
         *destination++ = (unsigned short)result;
       } while (--count);
     }
     destination = (unsigned short*)((char*)destination + padding * 2);
   } while (--rows);
 }
}


// 0x002de6c0 FUN_002de6c0 (204 B): equivalent/0x002de6c0.cpp
// sym: _FUN_002de6c0 @365ee9503fb9 @wcea8df7219eb
// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 8/8)
// FUN_002de6c0 @ 0x002de6c0
// equiv-conv: FUN_002de6c0 eax esi stack
extern "C" void FUN_002de6c0(unsigned short* destination, void * format, void * source) {
 int remainder = (int)((unsigned int)((Format_2de6c0 *)format)->pitch - (unsigned int)((Format_2de6c0 *)format)->width*2);
 int padding = (remainder / 2)*2;
 if(((Format_2de6c0 *)format)->height <= 0) return;
 for(int y=0; y<((Format_2de6c0 *)format)->height; ++y) {
  for(int x=0; x<((Format_2de6c0 *)format)->width; ++x) {
   unsigned int color = ((Source_2de6c0 *)source)->pixel(x,y);
   unsigned int a = ((color & 0xff000000u) >> (((Format_2de6c0 *)format)->alphaRight & 31)) << (((Format_2de6c0 *)format)->alphaLeft & 31);
   unsigned int g = ((color & 0xff00u) >> (((Format_2de6c0 *)format)->greenRight & 31)) << (((Format_2de6c0 *)format)->greenLeft & 31);
   unsigned int b = ((color & 0xffu) >> (((Format_2de6c0 *)format)->blueRight & 31)) << (((Format_2de6c0 *)format)->blueLeft & 31);
   unsigned int r = ((color & 0xff0000u) >> (((Format_2de6c0 *)format)->redRight & 31)) << (((Format_2de6c0 *)format)->redLeft & 31);
   *destination++ = (unsigned short)(a|g|b|r);
  }
  destination = (unsigned short*)((char*)destination + padding);
 }
}


// 0x002de790 FUN_002de790 (286 B): equivalent/0x002de790.cpp
// sym: _FUN_002de790 @a61152d29b13 @wdf909a7521c7
// STATUS: equivalent (tools/equiv.py level 3: 52 inputs, branch coverage 14/14)
// FUN_002de790 @ 0x002de790
// equiv-conv: FUN_002de790 eax ebx stack
extern "C" void __cdecl FUN_002de790(unsigned char* destination, void * format, const unsigned* source)
{
 unsigned rows = ((volatile PixelFormat_2de790 *)format)->height;
 if (((volatile PixelFormat_2de790 *)format)->directCopy) {
  unsigned bytes = ((volatile PixelFormat_2de790 *)format)->width * 4;
  while (rows--) {
   unsigned words = bytes / 4;
   unsigned* out = (unsigned*)destination;
   const unsigned* in = source;
   while (words--) *out++ = *in++;
   bytes = ((volatile PixelFormat_2de790 *)format)->width * 4;
   source = (const unsigned*)((const unsigned char*)source + bytes);
   destination += ((volatile PixelFormat_2de790 *)format)->pitch;
  }
 } else {
  int gap = (int)(((volatile PixelFormat_2de790 *)format)->pitch - ((volatile PixelFormat_2de790 *)format)->width * 4);
  gap = (gap / 4) * 4;
  while (rows--) {
   unsigned count = ((volatile PixelFormat_2de790 *)format)->width;
   while (count--) {
    unsigned pixel = *source++;
    unsigned blue = ((pixel & 0xff) >> (((volatile PixelFormat_2de790 *)format)->blueRight & 31)) << (((volatile PixelFormat_2de790 *)format)->blueLeft & 31);
    unsigned red = ((pixel & 0xff0000) >> (((volatile PixelFormat_2de790 *)format)->redRight & 31)) << (((volatile PixelFormat_2de790 *)format)->redLeft & 31);
    unsigned alpha = ((pixel & 0xff000000) >> (((volatile PixelFormat_2de790 *)format)->alphaRight & 31)) << (((volatile PixelFormat_2de790 *)format)->alphaLeft & 31);
    unsigned green = ((pixel & 0xff00) >> (((volatile PixelFormat_2de790 *)format)->greenRight & 31)) << (((volatile PixelFormat_2de790 *)format)->greenLeft & 31);
    *(unsigned*)destination = blue | red | alpha | green;
    destination += 4;
   }
   destination += gap;
  }
 }
}


// 0x002de8b0 FUN_002de8b0 (209 B): equivalent/0x002de8b0.cpp
// sym: _FUN_002de8b0 @2b07893b222b @w0e1406468ea2
// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 8/8)
// FUN_002de8b0 @ 0x002de8b0
// equiv-conv: FUN_002de8b0 eax esi stack
extern "C" void FUN_002de8b0(unsigned int* destination, void * format, void * source) {
 int padding = (((Format_2de8b0 *)format)->pitch - ((Format_2de8b0 *)format)->width * 4) / 4 * 4;
 for(int y=0;y<((Format_2de8b0 *)format)->height;++y) {
  for(int x=0;x<((Format_2de8b0 *)format)->width;++x) {
   unsigned int p=((Source_2de8b0 *)source)->pixel(x,y);
   unsigned int a=((p & 0xff000000U) >> (((Format_2de8b0 *)format)->alphaIn & 31)) << (((Format_2de8b0 *)format)->alphaOut & 31);
   unsigned int g=((p & 0xff00U) >> (((Format_2de8b0 *)format)->greenIn & 31)) << (((Format_2de8b0 *)format)->greenOut & 31);
   unsigned int b=((p & 0xffU) >> (((Format_2de8b0 *)format)->blueIn & 31)) << (((Format_2de8b0 *)format)->blueOut & 31);
   unsigned int r=((p & 0xff0000U) >> (((Format_2de8b0 *)format)->redIn & 31)) << (((Format_2de8b0 *)format)->redOut & 31);
   *destination++=a|g|b|r;
  }
  destination=(unsigned int*)((char*)destination+padding);
 }
}


// 0x002de990 FUN_002de990 (43 B): equivalent/0x002de990.cpp
// sym: _FUN_002de990@8 @123afddf0bc4 @w876d0ff2d3eb
// STATUS: equivalent (tools/equiv.py level 3: 18669 inputs, branch coverage 2/2)
// FUN_002de990 @ 0x002de990
// FUN_002de990 @ 0x002de990
// equiv-conv: FUN_002de600 eax ecx esi
// equiv-conv: FUN_002de6c0 eax esi stack
extern "C" void __stdcall FUN_002de990(void *item, void *context) {
    if (((Item *)item)->kind == 0x20) {
        FUN_002de600((unsigned short *)(void *)(((Context *)context)->value), (const unsigned *)(void *)(((Item *)item)->data), (Context *)((Context *)context));
    } else {
        FUN_002de6c0((unsigned short *)(void *)(((Context *)context)->value), (Context *)((Context *)context), (Item *)((Item *)item));
    }
}


// 0x002de9c0 FUN_002de9c0 (51 B): equivalent/0x002de9c0.cpp
// sym: _FUN_002de9c0@8 @c3ba1a49fc05 @w17ececcc6a09
// STATUS: equivalent (tools/equiv.py level 3: 18664 inputs, branch coverage 2/2)
// FUN_002de9c0 @ 0x002de9c0
// FUN_002de9c0 @ 0x002de9c0
// equiv-conv: FUN_002de790 eax ebx stack
// equiv-conv: FUN_002de8b0 eax esi stack
extern "C" void __stdcall FUN_002de9c0(void * item, void * context)
{
    if (((Item *)item)->type == 0x20)
        FUN_002de790((unsigned char *)(void *)(((Context *)context)->value), (Context *)((Context *)context), (const unsigned *)(void *)(((Item *)item)->data));
    else
        FUN_002de8b0((unsigned int *)(void *)(((Context *)context)->value), (Context *)((Context *)context), (Item *)((Item *)item));
}


// 0x002dea00 pure3d::ImageConverter::vfunc_4 (67 B): matches/0x002dea00.cpp
// sym: ?vfunc_4@ImageConverter@fn_f9c3d788@@QAEPAXPAX@Z
void* ImageConverter::vfunc_4(void* p) {
    hulk_intptr t = (hulk_intptr)alloc_00263ea0(0x30);
    void* x;
    if (t) {
        x = ((Image32_2dea00*)t)->run_002bffc0();
    } else
        x = 0;
    struct Pair {
        int a;
        int b;
    }* q = (Pair*)p;
    class Obj {
      public:
        virtual void a();
        virtual void b();
        virtual void c();
        virtual void d();
        virtual void e();
        virtual void g(void*, void*);
    };
    ((Obj*)x)->g((void*)q->a, (void*)q->b);
    f8(p, x);
    return x;
}

} // namespace fn_f9c3d788

// 0x002dea50 pure3d::ImageConverter::vfunc_8 (546 B): equivalent/0x002dea50.cpp
// sym: ?vfunc_8@ImageConverter@pure3d@@UAEXHH@Z @0b4ed66adf3a @w2053fdba4a45
// STATUS: equivalent (tools/equiv.py level 3: 110 inputs, branch coverage 20/20)
// pure3d::ImageConverter::vfunc_8 @ 0x002dea50
void pure3d::ImageConverter::vfunc_8(hulk_intptr __p0, hulk_intptr __p1) { PixelFormat_2dea50 * fmt = (PixelFormat_2dea50 *)__p0; Image_2dea50 * img = (Image_2dea50 *)__p1;

    int sA = fmt->rShift + (4 - fmt->rDst) * 2;
    int sB = fmt->gShift + (4 - fmt->gDst) * 2;
    int sC = fmt->bShift + (4 - fmt->bDst) * 2;
    int width = img->width;
    int height = img->height;

    if (fmt->bits == 16) {
        const unsigned char *src = fmt->pixels;
        unsigned int *dst = img->dst;
        int rowBytes = (fmt->pitch / 2) * 2;
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                unsigned int v = ((const unsigned short *)src)[x];
                unsigned int r = fmt->rMask & v;
                unsigned int b = fmt->bMask & v;
                unsigned int g = fmt->gMask & v;
                unsigned int out = ((b >> fmt->bShift) << fmt->bDst)
                                 | ((g >> fmt->gShift) << fmt->gDst)
                                 | ((r >> fmt->rShift) << fmt->rDst)
                                 | (b >> sC) | (g >> sB) | (r >> sA) | 0xff000000;
                *dst++ = out;
            }
            src += rowBytes;
        }
    } else if (fmt->bits == 32) {
        const unsigned char *src = fmt->pixels;
        unsigned int *dst = img->dst;
        int rowBytes = (fmt->pitch / 4) * 4;
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                unsigned int v = ((const unsigned int *)src)[x];
                unsigned int r = fmt->rMask & v;
                unsigned int b = fmt->bMask & v;
                unsigned int g = fmt->gMask & v;
                unsigned int out = ((b >> fmt->bShift) << fmt->bDst)
                                 | ((g >> fmt->gShift) << fmt->gDst)
                                 | ((r >> fmt->rShift) << fmt->rDst)
                                 | (b >> sC) | (g >> sB) | (r >> sA) | 0xff000000;
                *dst++ = out;
            }
            src += rowBytes;
        }
    }
}


// 0x002dec80 pure3d::ImageConverter::vfunc_0 (31 B): matches/0x002dec80.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002dec80@@UAEPAV123@E@Z
namespace fn_002dec80 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002dec80


// 0x002deca0 pure3d::ImageConverter::vfunc_7 (107 B): equivalent/0x002deca0.cpp
// sym: ?vfunc_7@ImageConverter@pure3d@@UAEXHH@Z @cb32f18a6225 @w6ff1a3e12dbd
// STATUS: equivalent (tools/equiv.py level 3: 3030 inputs, branch coverage 13/13)
// pure3d::ImageConverter::vfunc_7 @ 0x002deca0
void pure3d::ImageConverter::vfunc_7(hulk_intptr __p0, hulk_intptr __p1) { Texture_2deca0 * dest = (Texture_2deca0 *)__p0; SourceImage * src = (SourceImage *)__p1;

    if (dest->width != src->width || dest->height != src->height) {
        FUN_0028fcc0("Pure3D : ImageConverter::UpdateTexture() src size != dest size, image : %s\n",
                     dest->FUN_0027b000());
        return;
    }
    switch (src->format) {
    case 1:
    case 2:
    case 3:
    case 4:
        FUN_002de990((Texture_2deca0 *)dest, (SourceImage *)src);
        return;
    case 6:
        FUN_002de9c0((Texture_2deca0 *)dest, (SourceImage *)src);
        return;
    case 7:
        FUN_002de5a0((Texture_2deca0 *)dest, (SourceImage *)src);
        return;
    }
}


// 0x002ded30 pure3d::ImageConverter::vfunc_6 (111 B): equivalent/0x002ded30.cpp
// sym: ?vfunc_6@ImageConverter@pure3d@@UAEXHHH@Z @59a24a91955e @w4a7d368f5fea
// STATUS: equivalent (tools/equiv.py level 3: 3023 inputs, branch coverage 15/15)
// pure3d::ImageConverter::vfunc_6 @ 0x002ded30
void pure3d::ImageConverter::vfunc_6(hulk_intptr __p0, hulk_intptr __p1, int row) { Image_2ded30 * img = (Image_2ded30 *)__p0; Surface_2ded30 * s = (Surface_2ded30 *)__p1;

    if (img->width != s->width || img->height != s->height || row >= s->rows)
        return;
    int saved = s->cursor;
    s->cursor = s->stride * row + saved;
    switch (s->format) {
    case 1:
    case 2:
    case 3:
    case 4:
        FUN_002de990((Image_2ded30 *)img, (Surface_2ded30 *)s);
        break;
    case 6:
        FUN_002de9c0((Image_2ded30 *)img, (Surface_2ded30 *)s);
        break;
    case 7:
        FUN_002de5a0((Image_2ded30 *)img, (Surface_2ded30 *)s);
        break;
    }
    s->cursor = saved;
}

