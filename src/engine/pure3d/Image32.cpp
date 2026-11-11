// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002bfad0..0x002c0be0 (kind game, layer engine, confidence high), dominant class pure3d::Image32
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fbf8e46b {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fbf8e46b {} using namespace fn_fbf8e46b;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fbf8e46b {
extern "C" char DAT_0042ea40[];
class Image {
  public:
    virtual void _m_vf0();
    char _m_pad_4[0xc];
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    union { int f24; int m24; };
    char b28;
    char b29;
    char _m_pad_2a[0x2];
    void InitBase_0027b070();
    Image* FUN();
    void Fn();
    void Next_0027afd0();
};
} // namespace fn_fbf8e46b
namespace pure3d {
class Entity_2bfb10 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[0x100];
};
}
namespace fn_fbf8e46b {
extern int hulk_at_0042ea40[];
extern void __cdecl thunk_FUN_00267090(hulk_intptr);
extern "C" void* __cdecl FUN_00266e00(int, hulk_uintptr);
extern "C" void __cdecl FUN_00267090(void*);
struct Image32_2bfbe0 {
 char pad0[16];
 int width;
 int height;
 int bits;
 char pad1[8];
 unsigned char* pixels;
 void FUN_002bfbe0();
};
struct Image32_nv_2bfd30 {
    void Finish_0027afd0();
};
struct Image_2bfd30 {
    hulk_intptr vf;
    char pad[0x20];
    int m24;
};
extern void __cdecl Thunk_0008d340(int);
void Image_Init(Image_2bfd30*);
} // namespace fn_fbf8e46b
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned int);
#endif
namespace fn_fbf8e46b {
void __cdecl free_pixels_0008d340(void*);
void* __cdecl alloc_pixels_0008d6d0(int);
extern "C" void* __cdecl FUN_0008d6d0(unsigned int size);
extern "C" void __cdecl FUN_0008d340(void* data);
} // namespace fn_fbf8e46b
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memset(void*, int, unsigned int);
#endif
namespace fn_fbf8e46b {
struct Image_2bffc0 {
    char pad[0x10];
    void Init_0027b070();
};
extern int hulk_at_0042ead4;
struct Image32 : Image_2bffc0 {
    int field10, field14, field18, field1c, field20, field24;
    unsigned char field28, field29;
    Image32* Init();
};
typedef unsigned int u32_2c0070;
void thunk_FUN_00267090(void*);
void* FUN_0008d6d0(u32_2c0070);
class Surface_2c0240 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    char pad4[0xc];
    int stride;         // 0x10
    char pad14[0x24 - 0x14];
    char *base;         // 0x24
};
class Surface_2c02b0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18();
    char pad04[0x10 - 4];
    int pitch;              // 0x10
    char pad14[0x24 - 0x14];
    char *pixels;           // 0x24
};
class Source_2c03e0 {
  public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8();
    virtual unsigned int Get(int x, int y);
};
class Surface_2c0450 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual unsigned GetPixel(int x, int y);
};
struct Name_2c0590 {
    unsigned int lo, hi;
};
struct Sprite {
    char pad0[8];
    Name_2c0590 name;
    char pad10[0x28 - 0x10];
    char flag;
};
struct Stream {
};
struct Reader {
    char pad0[0x284];
    Stream *stream;
    char FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
    void FUN_00266ca0(int v);
};
struct Factory_2c0590 {
    char pad0[0x8c];
    int f8c;
    Sprite *FUN_002aecb0(char *name);
};
struct Frame_2c0590 {
    short unk10;
    unsigned char len;
    char flag;
    int a;
    int b;
    char buf1[0x80];
    char buf2[0x100];
};
class Loader_2c0590 {
public:
    char pad0[0x14];
    Factory_2c0590 *factory;
    Sprite *FUN_002c0590(Reader *r, int unused);
};


// 0x002bfad0 FUN_002bfad0 (48 B): matches/0x002bfad0.cpp
// sym: ?FUN@Image@fn_fbf8e46b@@QAEPAV12@XZ
Image* Image::FUN() {
    InitBase_0027b070();
    f24 = 0;
    f10 = 0;
    f14 = 0;
    f18 = 0;
    f1c = 0;
    b29 = 0;
    b28 = 0;
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042ea40);
    f20 = 8;
    return this;
}

} // namespace fn_fbf8e46b

// 0x002bfb00 pure3d::Image::vfunc_3 (3 B): matches/0x002bfb00.cpp
// sym: ?vfunc_3@Image@pure3d@@UAE_NXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
bool pure3d::Image::vfunc_3() {
    return (bool)(0);
}


// 0x002bfb10 pure3d::Image::vfunc_4 (3 B): matches/0x002bfb10.cpp
// sym: ?vfunc_4@Image@pure3d@@UAEPAXXZ
// Same code shape as 0x002a1130 (propagated; names are from that function)
 // namespace pure3d
void* pure3d::Image::vfunc_4() {
    return (void*)(this);
}


// 0x002bfb20 FUN_002bfb20 (79 B): matches/0x002bfb20.cpp [wrapped: conflict: Image]
// sym: ??0Image@fn_002bfb20@@QAE@PBU01@@Z
namespace fn_002bfb20 {
extern int ImageVtable;
struct Entity_0027b070 {
    Entity_0027b070();
};
class Sub_2bfb20 {
  public:
    void Copy_0027af70(const Sub_2bfb20*);
};
struct Image : public Entity_0027b070 {
    int* vt;
    char pad4[0x0c];
    int m10;
    int m14;
    char pad18[4];
    int m1c;
    int m20;
    int m24;
    char pad28;
    unsigned char m29;
    Image(const Image*);
};
Image::Image(const Image* src) : Entity_0027b070() {
    vt = &ImageVtable;
    if (src)
        ((Sub_2bfb20*)((char*)this + 8))->Copy_0027af70((const Sub_2bfb20*)((const char*)src + 8));
    m24 = 0;
    m20 = src->m20;
    m1c = src->m1c;
    m29 = src->m29;
    m10 = src->m10;
    m14 = src->m14;
}
} // namespace fn_002bfb20

namespace fn_fbf8e46b {

// 0x002bfb70 FUN_002bfb70 (29 B): matches/0x002bfb70.cpp
// sym: ?Fn@Image@fn_fbf8e46b@@QAEXXZ
void Image::Fn() {
    int x = m24;
    *(hulk_intptr*)this = (hulk_intptr)hulk_at_0042ea40;
    thunk_FUN_00267090(x);
    Next_0027afd0();
}


// 0x002bfbe0 FUN_002bfbe0 (195 B): equivalent/0x002bfbe0.cpp
// sym: ?FUN_002bfbe0@Image32_2bfbe0@fn_fbf8e46b@@QAEXXZ @faeeabddaf2c @w6d23e844a56d
// STATUS: equivalent (tools/equiv.py level 3: 55 inputs, branch coverage 4/4)
// FUN_002bfbe0 @ 0x002bfbe0
void Image32_2bfbe0::FUN_002bfbe0() {
 int bytesPerPixel = bits >> 3;
 unsigned char* temp = (unsigned char*)FUN_00266e00(1, (unsigned int)width * bytesPerPixel);
 unsigned int stride = (unsigned int)width * bytesPerPixel;
 unsigned char* first = pixels;
 unsigned char* last = pixels + (unsigned int)(height - 1) * stride;
 if ((height & ~1) > 0) {
  int row = 0;
  do {
   unsigned int i;
   for (i=0; i < (stride >> 2); ++i) ((unsigned int*)temp)[i] = ((unsigned int*)last)[i];
   for (i=(stride & ~3u); i < stride; ++i) temp[i] = last[i];
   for (i=0; i < (stride >> 2); ++i) ((unsigned int*)last)[i] = ((unsigned int*)first)[i];
   for (i=(stride & ~3u); i < stride; ++i) last[i] = first[i];
   for (i=0; i < (stride >> 2); ++i) ((unsigned int*)first)[i] = ((unsigned int*)temp)[i];
   for (i=(stride & ~3u); i < stride; ++i) first[i] = temp[i];
   first += stride;
   last -= stride;
   ++row;
  } while (row < (height >> 1));
 }
 FUN_00267090(temp);
}

} // namespace fn_fbf8e46b

// 0x002bfcb0 FUN_002bfcb0 (71 B): equivalent/0x002bfcb0.cpp [wrapped: conflict: pure3d::Image8]
// sym: ??0Image8@pure3d@fn_002bfcb0@@QAE@XZ @35a4e1b90e1d @w6c280e89a96a
namespace fn_002bfcb0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002bfcb0 @ 0x002bfcb0
namespace pure3d {
struct FUN_0027b070 {
    virtual void Destroy();
    char pad[12];
    FUN_0027b070();
};
struct Image8 : FUN_0027b070 {
    virtual void Destroy();
    unsigned int width;
    unsigned int height;
    unsigned int depth;
    unsigned int pitch;
    unsigned int format;
    unsigned int flags;
    unsigned char bit28;
    unsigned char bit29;
    char pad2[6];
    unsigned int palette[256];
    unsigned int paletteSize;
    Image8();
};
Image8::Image8() {
    width = 0;
    height = 0;
    depth = 8;
    pitch = 0;
    format = 8;
    flags = 0;
    bit28 = 0;
    bit29 = 0;
    for (int i = 0; i < 256; ++i) palette[i] = 0;
    paletteSize = 256;
}
}
} // namespace fn_002bfcb0


// 0x002bfd00 pure3d::Image8::vfunc_13 (13 B): matches/0x002bfd00.cpp
// sym: ?vfunc_13@Image8@pure3d@@UAEXH@Z
 // namespace pure3d
void pure3d::Image8::vfunc_13(int x) {
    this->f_430 = x;
}


// 0x002bfd10 pure3d::Image8::vfunc_14 (7 B): matches/0x002bfd10.cpp
// sym: ?vfunc_14@Image8@pure3d@@UAEIXZ
 // namespace pure3d
unsigned int pure3d::Image8::vfunc_14() {
    return (*(unsigned int *)&this->f_430);
}

namespace fn_fbf8e46b {

// 0x002bfd20 pure3d::Image8::vfunc_8 (3 B): matches/0x002bfd20.cpp
// sym: ?GetZero@fn_fbf8e46b@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}


// 0x002bfd30 FUN_002bfd30 (29 B): matches/0x002bfd30.cpp
// sym: ?Image_Init@fn_fbf8e46b@@YIXPAUImage_2bfd30@1@PAX@Z
void __fastcall Image_Init(Image_2bfd30* self, void*) {
    int x = self->m24;
    self->vf = ((hulk_intptr)DAT_0042ea40);
    Thunk_0008d340(x);
    ((Image32_nv_2bfd30*)(((pure3d::Image32*)(((pure3d::Image32*)self)))))->Finish_0027afd0();
}

} // namespace fn_fbf8e46b

// 0x002bfd50 pure3d::Image8::vfunc_19 (27 B): matches/0x002bfd50.cpp
// sym: ?vfunc_19@Image8@pure3d@@UAEXHHE@Z
void pure3d::Image8::vfunc_19(int x, int y, unsigned char value) {
    (*(unsigned char * *)&this->f_24)[this->f_10 * y + x] = value;
}


// 0x002bfd70 pure3d::Image8::vfunc_20 (24 B): matches/0x002bfd70.cpp
// sym: ?vfunc_20@Image8@pure3d@@UAEIHH@Z
unsigned int pure3d::Image8::vfunc_20(int p2, int p3) {
    return *((unsigned char*)(this->f_10 * p3 + (*(hulk_intptr *)&this->f_24) + p2));
}


// 0x002bfd90 pure3d::Image8::vfunc_6 (52 B): matches/0x002bfd90.cpp
// sym: ?vfunc_6@Image8@pure3d@@UAEXHHPAX@Z
void pure3d::Image8::vfunc_6(int width, int height, void* __p2) { const void * src = (const void *)__p2;

    vfunc_5(width, height);
    memcpy((*(u8 * *)&this->f_24), src, width * height);
}


// 0x002bfdd0 pure3d::Image8::vfunc_5 (49 B): matches/0x002bfdd0.cpp
// sym: ?vfunc_5@Image8@pure3d@@UAEXHH@Z
void pure3d::Image8::vfunc_5(int w, int h) {
    this->f_10 = w;
    this->f_14 = h;
    free_pixels_0008d340((*(void * *)&this->f_24));
    (*(void * *)&this->f_24) = alloc_pixels_0008d6d0(this->f_14 * this->f_10);
}


// 0x002bfe10 pure3d::Image8::vfunc_7 (199 B): equivalent/0x002bfe10.cpp
// sym: ?vfunc_7@Image8@pure3d@@UAEXHH@Z @c527a559ea3c @w08b69b2d0245
// STATUS: equivalent (tools/equiv.py level 3: 52 inputs, branch coverage 10/10)
// pure3d::Image8::vfunc_7 @ 0x002bfe10
void pure3d::Image8::vfunc_7(int newWidth, int newHeight) {
 int copyWidth = this->f_10 < newWidth ? this->f_10 : newWidth;
 int copyHeight = this->f_14 < newHeight ? this->f_14 : newHeight;
 unsigned int size = (unsigned int)newWidth * (unsigned int)newHeight;
 unsigned char* buffer = (unsigned char*)FUN_0008d6d0(size);
 for (unsigned int i=0;i<size;++i) buffer[i]=0;
 unsigned char* source=(*(unsigned char * *)&this->f_24);
 if (source) {
  unsigned char* dest=buffer;
  for (int y=0;y<copyHeight;++y) {
   for (unsigned int x=0;x<(unsigned int)copyWidth;++x) dest[x]=source[x];
   dest+=newWidth;
   source+=this->f_10;
  }
  unsigned char* old=(*(unsigned char * *)&this->f_24);
  this->f_10=newWidth;
  this->f_14=newHeight;
  FUN_0008d340(old);
 }
 (*(unsigned char * *)&this->f_24)=buffer;
}


// 0x002bfee0 pure3d::Image8::vfunc_9 (26 B): matches/0x002bfee0.cpp
// sym: ?vfunc_9@Image8@pure3d@@UAEIHH@Z
unsigned int pure3d::Image8::vfunc_9(int a, int b) {
    return (*(int (*)[256])&this->f_30)[(*(unsigned char * *)&this->f_24)[this->f_10 * b + a]];
}


// 0x002bff00 pure3d::Image8::vfunc_10 (27 B): matches/0x002bff00.cpp
// sym: ?vfunc_10@Image8@pure3d@@UAEXHHH@Z
// Same code shape as 0x002bfd50 (propagated; names are from that function)
void pure3d::Image8::vfunc_10(int x, int y, int __p2) { unsigned char value = (unsigned char)__p2;

    (*(unsigned char * *)&this->f_24)[this->f_10 * y + x] = value;
}


// 0x002bff20 pure3d::Image8::vfunc_18 (4 B): matches/0x002bff20.cpp
// sym: ?vfunc_18@Image8@pure3d@@UAEPAXXZ
// Same code shape as 0x001c4e20 (propagated; names are from that function)
void* pure3d::Image8::vfunc_18() {
    return (void*)((pure3d::Image8*)((char*)this + 0x30));
}


// 0x002bff30 pure3d::Image8::vfunc_16 (44 B): matches/0x002bff30.cpp
// sym: ?vfunc_16@Image8@pure3d@@UAEXHH@Z
void pure3d::Image8::vfunc_16(hulk_intptr __p0, int __p1) { const unsigned int * src = (const unsigned int *)__p0; unsigned int n = (unsigned int)__p1;

    if (n != 256)
        memset((*(unsigned int (*)[256])&this->f_30), 0, sizeof (*(unsigned int (*)[256])&this->f_30));
    memcpy((*(unsigned int (*)[256])&this->f_30), src, n * 4);
}


// 0x002bff60 pure3d::Image8::vfunc_15 (15 B): matches/0x002bff60.cpp
// sym: ?vfunc_15@Image8@pure3d@@UAEXHH@Z
void pure3d::Image8::vfunc_15(int index, int value) {
    (*(int (*)[1])&this->f_30)[index] = value;
}


// 0x002bff70 pure3d::Image8::vfunc_17 (11 B): matches/0x002bff70.cpp
// sym: ?vfunc_17@Image8@pure3d@@UAEIH@Z
unsigned int pure3d::Image8::vfunc_17(int index) {
    return (*(unsigned int (*)[1])&this->f_30)[index];
}


// 0x002bff80 pure3d::Image8::vfunc_11 (49 B): matches/0x002bff80.cpp
// sym: ?vfunc_11@Image8@pure3d@@UAEXI@Z
void pure3d::Image8::vfunc_11(unsigned int __p0) { int value = (int)__p0;

    memset((*(u8 * *)&this->f_24), value, this->f_10 * this->f_14);
}

namespace fn_fbf8e46b {

// 0x002bffc0 FUN_002bffc0 (52 B): matches/0x002bffc0.cpp
// sym: ?Init@Image32@fn_fbf8e46b@@QAEPAU12@XZ
Image32* Image32::Init() {
    Image_2bffc0::Init_0027b070();
    field24 = 0;
    field10 = 0;
    field14 = 0;
    field1c = 0;
    field29 = 0;
    field28 = 0;
    field20 = 8;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_0042ead4;
    field18 = 0x20;
    return this;
}


// 0x002c0000 pure3d::Image32::vfunc_8 (3 B): matches/0x002c0000.cpp
// sym: _FUN_002c0000
// Same code shape as 0x0026ef40 (propagated; names are from that function)
extern "C" unsigned int FUN_002c0000() {
    return 0;
}

} // namespace fn_fbf8e46b

// 0x002c0010 FUN_002c0010 (29 B): matches/0x002c0010.cpp [wrapped: conflict: Image]
// sym: ??1Image@fn_002c0010@@UAE@XZ
namespace fn_002c0010 {
class Image {
  public:
    virtual void V0_00038290();
    char pad04[0x20];
    int m24;
    virtual ~Image();
    void Finish_0027afd0();
};
extern void __cdecl thunk_FUN_00267090(hulk_intptr);
Image::~Image() {
    thunk_FUN_00267090(m24);
    Finish_0027afd0();
}
} // namespace fn_002c0010


// 0x002c0030 pure3d::Image32::vfunc_6 (55 B): matches/0x002c0030.cpp
// sym: ?vfunc_6@Image32@pure3d@@UAEXHHPAX@Z
 // namespace pure3d
void pure3d::Image32::vfunc_6(int w, int h, void* __p2) { const void * src = (const void *)__p2;

    vfunc_5(w, h);
    memcpy((*(void * *)&this->f_24), src, w * h * 4);
}


// 0x002c0070 pure3d::Image32::vfunc_5 (52 B): matches/0x002c0070.cpp
// sym: ?vfunc_5@Image32@pure3d@@UAEXHH@Z
void pure3d::Image32::vfunc_5(int w, int h) {
    this->f_10 = w;
    this->f_14 = h;
    thunk_FUN_00267090((*(void * *)&this->f_24));
    (*(void * *)&this->f_24) = FUN_0008d6d0(this->f_14 * this->f_10 * 4);
}


// 0x002c00b0 pure3d::Image32::vfunc_7 (216 B): equivalent/0x002c00b0.cpp
// sym: ?vfunc_7@Image32@pure3d@@UAEXHH@Z @360d384ac205 @w14cef8e4fa00
// STATUS: equivalent (tools/equiv.py level 3: 53 inputs, branch coverage 10/10)
// pure3d::Image32::vfunc_7 @ 0x002c00b0
void pure3d::Image32::vfunc_7(int newWidth, int newHeight) {
 int copyWidth = this->f_10 < newWidth ? this->f_10 : newWidth;
 int copyHeight = this->f_14 < newHeight ? this->f_14 : newHeight;
 unsigned int size = (unsigned int)newWidth * (unsigned int)newHeight * 4;
 unsigned int* buffer = (unsigned int*)FUN_0008d6d0(size);
 for(unsigned int i=0;i<(size>>2);++i) buffer[i]=0;
 if((*(unsigned int * *)&this->f_24)) {
  unsigned int* src=(*(unsigned int * *)&this->f_24);
  unsigned int* dst=buffer;
  for(int y=0;y<copyHeight;++y) {
   unsigned int bytes=(unsigned int)copyWidth*4;
   for(unsigned int x=0;x<(bytes>>2);++x) dst[x]=src[x];
   dst+=newWidth;
   src+=this->f_10;
  }
  unsigned int* old=(*(unsigned int * *)&this->f_24);
  this->f_10=newWidth;
  this->f_14=newHeight;
  FUN_0008d340(old);
 }
 (*(unsigned int * *)&this->f_24)=buffer;
}


// 0x002c0190 pure3d::Image32::vfunc_9 (23 B): matches/0x002c0190.cpp
// sym: ?vfunc_9@Image32@pure3d@@UAEIHH@Z
unsigned int pure3d::Image32::vfunc_9(int x, int y) {
    return (*(unsigned int * *)&this->f_24)[this->f_10 * y + x];
}


// 0x002c01b0 pure3d::Image32::vfunc_10 (27 B): matches/0x002c01b0.cpp
// sym: ?vfunc_10@Image32@pure3d@@UAEXHHH@Z
void pure3d::Image32::vfunc_10(int x, int y, int value) {
    (*(int * *)&this->f_24)[this->f_10 * y + x] = value;
}


// 0x002c01d0 pure3d::Image32::vfunc_11 (44 B): matches/0x002c01d0.cpp
// sym: ?vfunc_11@Image32@pure3d@@UAEXI@Z
void pure3d::Image32::vfunc_11(unsigned int value) {
    unsigned int* p = (*(unsigned int * *)&this->f_24);
    int count = this->f_14 * this->f_10;
    int i = 0;
    if (count > 0) {
        do {
            *p++ = value;
            ++i;
            count = this->f_14 * this->f_10;
        } while (i < count);
    }
}

namespace fn_fbf8e46b {

// 0x002c0200 FUN_002c0200 (58 B): equivalent/0x002c0200.cpp
// sym: _FUN_002c0200 @113c74d4d76f @weef6c8c7a63a
// STATUS: equivalent (tools/equiv.py level 3: 159 inputs, branch coverage 4/4)
// FUN_002c0200 @ 0x002c0200
// equiv-conv: FUN_002c0200 eax edx ecx stack stack stack
extern "C" void FUN_002c0200(const unsigned char *source, unsigned char *destination, int count, unsigned int bytes, int sourceStride, int destinationStride)
{
    for (int row = 0; row < count; ++row) {
        const unsigned int *wordsSource = (const unsigned int *)source;
        unsigned int *wordsDestination = (unsigned int *)destination;
        for (unsigned int i = 0; i < (bytes >> 2); ++i)
            wordsDestination[i] = wordsSource[i];
        for (unsigned int j = bytes & 3, offset = bytes & ~3U; j; --j, ++offset)
            destination[offset] = source[offset];
        source += sourceStride;
        destination += destinationStride;
    }
}


// 0x002c0240 FUN_002c0240 (101 B): equivalent/0x002c0240.cpp
// sym: _FUN_002c0240 @765d68e2faf2 @w5e3fd516791e
// STATUS: equivalent (tools/equiv.py level 3: 120 inputs, branch coverage 8/8)
// FUN_002c0240 @ 0x002c0240
// equiv-conv: FUN_002c0240 ecx eax ebx stack stack stack stack
extern "C" void __cdecl FUN_002c0240(void *surf, int y, int x, char *dst, int w, int h, int dstStride)
{
    int stride = ((Surface_2c0240 *)surf)->stride;
    char *src = ((Surface_2c0240 *)surf)->base + stride * y + x;
    ((Surface_2c0240 *)surf)->v18();
    int endY = y + h;
    if (y < endY) {
        int rows = endY - y;
        int endX = w + x;
        do {
            for (int k = x; k < endX; k++)
                dst[k - x] = src[k - x];
            src += stride;
            dst += dstStride;
        } while (--rows != 0);
    }
}


// 0x002c02b0 FUN_002c02b0 (166 B): equivalent/0x002c02b0.cpp
// sym: ?FUN_002c02b0@fn_fbf8e46b@@YAXPAVSurface_2c02b0@1@HPADHHHHD@Z @374d65799de0 @w99126d3ff2c2
// STATUS: equivalent (tools/equiv.py level 3: 118 inputs, branch coverage 10/10)
// FUN_002c02b0 @ 0x002c02b0
// equiv-conv: FUN_002c02b0 ecx eax stack stack stack stack stack stack
void FUN_002c02b0(Surface_2c02b0 *surf, int y0, char *dst, int x0, int width, int height, int dstPitch, char key)
{
    int stride = surf->pitch;
    char *src = surf->pixels + stride * y0 + x0;
    surf->v18();
    int xEnd = x0 + width;
    int rows = (y0 + height) - y0;
    if (y0 < y0 + height) {
        do {
            char *s = src;
            char *d = dst;
            for (int x = x0; x < xEnd; x++) {
                if (*s != key)
                    *d = *s;
                s++;
                d++;
            }
            src += stride;
            dst += dstPitch;
            rows--;
        } while (rows != 0);
    }
}


// 0x002c0360 FUN_002c0360 (124 B): equivalent/0x002c0360.cpp
// sym: _FUN_002c0360 @64a94ba3dfb3 @w77efa7a48376
// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 10/10)
// FUN_002c0360 @ 0x002c0360
// Copies a rectangle of 32-bit pixels, skipping those whose colour (low 24 bits) equals `key`.
// equiv-conv: FUN_002c0360 eax ecx edx stack stack stack stack
extern "C" void __cdecl FUN_002c0360(int rows, int srcStride, unsigned int *dst, unsigned int *src, int width,
                          int dstStride, unsigned int key) {
    for (; rows > 0; rows--) {
        for (int x = 0; x < width; x++) {
            unsigned int pixel = src[x];
            if ((pixel & 0xffffff) != key) {
                dst[x] = pixel;
            }
        }
        src += srcStride;
        dst += dstStride;
    }
}


// 0x002c03e0 FUN_002c03e0 (102 B): equivalent/0x002c03e0.cpp
// sym: _FUN_002c03e0 @4e82ad82b5a9 @w14f4bed9fd3e
// STATUS: equivalent (tools/equiv.py level 3: 104 inputs, branch coverage 8/8)
// FUN_002c03e0 @ 0x002c03e0
// equiv-conv: FUN_002c03e0 eax ecx edx stack stack stack stack
extern "C" void FUN_002c03e0(int width, int height, int stride, void * src, unsigned int* dst, int x0, int y0) {
    for (int y = y0; y < y0 + height; y++) {
        unsigned int* p = dst;
        for (int x = x0; x < x0 + width; x++) {
            *p = ((Source_2c03e0 *)src)->Get(x, y);
            p++;
        }
        dst += stride;
    }
}


// 0x002c0450 FUN_002c0450 (316 B): equivalent/0x002c0450.cpp
// sym: _FUN_002c0450 @4d470e4d75ad @w8b41a6ede9e7
// STATUS: equivalent (tools/equiv.py level 3: 39 inputs, branch coverage 16/16)
// FUN_002c0450 @ 0x002c0450
// Blits a source surface into a 32-bit ARGB buffer, alpha-blending each pixel.
// equiv-conv: FUN_002c0450 eax ecx edx stack stack stack stack stack
extern "C" void FUN_002c0450(int y0, int width, int height, void *src, unsigned *dst, int x0, int stride, unsigned key)
{
    int yEnd = y0 + height;
    int xEnd = x0 + width;
    for (int y = y0; y < yEnd; y++) {
        unsigned *row = dst;
        for (int x = x0; x < xEnd; x++) {
            unsigned c = ((Surface_2c0450 *)src)->GetPixel(x, y);
            if ((c & 0xffffff) != key) {
                int a = (int)(c >> 24);
                if (a == 0xff) {
                    *row = c;
                } else if (a > 0) {
                    unsigned d = *row;
                    int dr = (d >> 16) & 0xff;
                    int dg = (d >> 8) & 0xff;
                    int db = d & 0xff;
                    int r = (((int)((c >> 16) & 0xff) - dr) * a >> 8) + dr;
                    int g = (((int)((c >> 8) & 0xff) - dg) * a >> 8) + dg;
                    int b = (((int)(c & 0xff) - db) * a >> 8) + db;
                    int na = (int)(d >> 24) + a;
                    if (na > 0xff)
                        na = 0xff;
                    *row = (na << 24) | (r << 16) | (g << 8) | b;
                }
            }
            row++;
        }
        dst += stride;
    }
}


// 0x002c0590 FUN_002c0590 (488 B): equivalent/0x002c0590.cpp
// sym: ?FUN_002c0590@Loader_2c0590@fn_fbf8e46b@@QAEPAUSprite@2@PAUReader@2@H@Z @434fdcd6048b @w246ef94b9661
// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 10/12, incomplete)
// FUN_002c0590 @ 0x002c0590
Sprite *Loader_2c0590::FUN_002c0590(Reader *r, int unused)
{
    Frame_2c0590 f;
    Sprite *result = 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1);
    int len = f.len;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(f.buf1), (hulk_intptr)len, 1, (hulk_intptr)1);
    f.buf1[len] = 0;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.a), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.a), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.a), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.a), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.b), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.b), (hulk_intptr)1, 4, (hulk_intptr)1);
    int kind = f.b;
    f.flag = (kind == 1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.b), (hulk_intptr)1, 4, (hulk_intptr)1);
    factory->f8c = f.a;
    while (r->FUN_002669f0()) {
        int id = r->FUN_00266a30();
        if (id == 0x19002) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.a), (hulk_intptr)1, 4, (hulk_intptr)1);
            int v = ((int)((owners::Target_266c90 *)r)->FUN_00266c90());
            result = ((Sprite *)((owners::SomeClass_2aed60 *)factory)->FUN_002aed60((void *)(hulk_uintptr)(int)v, (void *)(hulk_uintptr)(int)(f.b)));
            r->FUN_00266ca0(v);
        } else if (id == 0x19003) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1);
            int n = f.len;
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(f.buf2), (hulk_intptr)n, 1, (hulk_intptr)1);
            f.buf2[n] = 0;
            result = factory->FUN_002aecb0(f.buf2);
        }
        r->FUN_00266be0();
    }
    if (result) {
        result->flag = f.flag;
        ((owners::Target_27b040 *)&(result->name))->FUN_0027b040((hulk_uintptr)(f.buf1));
    }
    return result;
}

} // namespace fn_fbf8e46b

// 0x002c0790 pure3d::Image::vfunc_2 (50 B): matches/0x002c0790.cpp [wrapped: conflict: pure3d::LightsChooserCache]
// sym: ??_GLightsChooserCache@pure3d@fn_002c0790@@UAEPAXI@Z
namespace fn_002c0790 {
// Same code shape as 0x0029e7b0 (propagated; names are from that function)
extern "C++" __declspec(nothrow) void destroyChooser_0008d340(void*);
namespace pure3d {
class LightsChooserCache {
  public:
    virtual ~LightsChooserCache();
    void baseDtor_0027afd0();
    char pad[0x20];
    void* mPtr;
};

LightsChooserCache::~LightsChooserCache() {
    destroyChooser_0008d340(mPtr);
    baseDtor_0027afd0();
}
} // namespace pure3d
} // namespace fn_002c0790


// 0x002c07d0 pure3d::Image8::vfunc_2 (50 B): matches/0x002c07d0.cpp [wrapped: conflict: pure3d::LightsChooserCache]
// sym: ??_GLightsChooserCache@pure3d@fn_002c07d0@@UAEPAXI@Z
namespace fn_002c07d0 {
// Same code shape as 0x0029e7b0 (propagated; names are from that function)
extern "C++" __declspec(nothrow) void destroyChooser(void*);
namespace pure3d {
class LightsChooserCache {
  public:
    virtual ~LightsChooserCache();
    void baseDtor_0027afd0();
    char pad[0x20];
    void* mPtr;
};

LightsChooserCache::~LightsChooserCache() {
    destroyChooser(mPtr);
    baseDtor_0027afd0();
}
} // namespace pure3d
} // namespace fn_002c07d0


// 0x002c08d0 pure3d::Image8::vfunc_12 (206 B): equivalent/0x002c08d0.cpp [wrapped: conflict: pure3d::Image8]
// sym: ?vfunc_12@Image8@pure3d@fn_002c08d0@@UAEXPAU123@HHHHHH@Z @a9a743033960 @w16688ea0447e
namespace fn_002c08d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// pure3d::Image8::vfunc_12 @ 0x002c08d0
namespace pure3d {
struct Image8 {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(Image8* source, int x, int y, int width, int height, int destX, int destY);
    char pad04[12]; int width; int height; char pad18[4]; unsigned char key; char pad1d[7]; unsigned char* pixels; unsigned char pad28; unsigned char transparent;
};
}
// equiv-conv: FUN_002c02b0 ecx eax stack stack stack stack stack stack
void __cdecl FUN_002c02b0(pure3d::Image8* source, int y, unsigned char* dest, int x, int width, int height, int stride, unsigned int key);
// equiv-conv: FUN_002c0240 ecx eax ebx stack stack stack stack
extern "C++" __declspec(nothrow) void __cdecl FUN_002c0240(void *, int, int, char *, int, int, int);
void pure3d::Image8::vfunc_12(Image8* source, int x, int y, int w, int h, int dx, int dy) {
    if (dx < 0) { x += dx; w -= dx; dx = 0; }
    if (dy < 0) { y += dy; h -= dy; dy = 0; }
    int stride = width;
    if (dx + w > stride) w = stride - dx;
    if (dy + h > height) h = height - dy;
    if (w < 1 || h < 1 || !source->pixels || !pixels) return;
    unsigned char* dest = pixels + stride * dy + dx;
    if (source->transparent) FUN_002c02b0(source, y, dest, x, w, h, stride, source->key);
    else FUN_002c0240((pure3d :: Image8 *)source, y, x, (char *)(unsigned char *)dest, w, h, stride);
}
} // namespace fn_002c08d0


// 0x002c09a0 pure3d::Image32::vfunc_2 (50 B): matches/0x002c09a0.cpp [wrapped: conflict: pure3d::LightsChooserCache]
// sym: ??_GLightsChooserCache@pure3d@fn_002c09a0@@UAEPAXI@Z
namespace fn_002c09a0 {
// Same code shape as 0x0029e7b0 (propagated; names are from that function)
extern "C++" __declspec(nothrow) void destroyChooser(void*);
namespace pure3d {
class LightsChooserCache {
  public:
    virtual ~LightsChooserCache();
    void baseDtor_0027afd0();
    char pad[0x20];
    void* mPtr;
};

LightsChooserCache::~LightsChooserCache() {
    destroyChooser(mPtr);
    baseDtor_0027afd0();
}
} // namespace pure3d
} // namespace fn_002c09a0


// 0x002c09e0 FUN_002c09e0 (113 B): matches/0x002c09e0.cpp [wrapped: conflict: Image32]
// sym: ??0Image32@fn_002c09e0@@QAE@ABV01@@Z
namespace fn_002c09e0 {
void Free_0008d340(void*);
void* Alloc_0008d6d0(int);
class Image32;
class Image_2c09e0 {
  public:
    Image_2c09e0(const Image32& o);
    virtual void v0();
    virtual void v1_000382a0();
    virtual void v2();
    virtual void v3_002bfb00();
    virtual void v4_002bfb10();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void Copy_002c0a60(const Image32* s, int a, int b, int w, int h, int c, int d);
    char pad[0xc];
    int mW, mH, mBpp;
    char pad2[8];
    int* mData;
    char pad3[1];
    char mFlag;
};
class Image32 : public Image_2c09e0 {
  public:
    Image32(const Image32& o);
    virtual void v0();
};
Image32::Image32(const Image32& o) : Image_2c09e0(o) {
    mBpp = 0x20;
    int h = o.mH;
    int w = o.mW;
    mW = w;
    mH = h;
    Free_0008d340(mData);
    mData = (int*)Alloc_0008d6d0(mH * mW * 4);
    char f = mFlag;
    mFlag = 0;
    Image_2c09e0* b = this;
    b->Copy_002c0a60(&o, 0, 0, o.mW, o.mH, 0, 0);
    mFlag = f;
}
} // namespace fn_002c09e0


// 0x002c0a60 pure3d::Image32::vfunc_12 (376 B): equivalent/0x002c0a60.cpp [wrapped: conflict: Image32]
// sym: ?vfunc_12@Image32@fn_002c0a60@@UAEXPAV12@HHHHHH@Z @4979d54ffe18 @w8b6646e7b11b
namespace fn_002c0a60 {
// STATUS: equivalent (tools/equiv.py level 3: 20008 inputs, branch coverage 22/22)
// pure3d::Image32::vfunc_12 @ 0x002c0a60
// pure3d::Image32::vfunc_12 @ 0x002c0a60
class Image32;

// equiv-conv: FUN_002c0360 eax ecx edx stack stack stack stack
extern "C++" __declspec(nothrow) void FUN_002c0360(int rows, int srcStride, unsigned int* dst, unsigned int* src, int width, int dstStride, unsigned int key);
// equiv-conv: FUN_002c0200 eax edx ecx stack stack stack
extern "C++" __declspec(nothrow) void __cdecl FUN_002c0200(const unsigned char *, unsigned char *, int, unsigned int, int, int);
// equiv-conv: FUN_002c0450 eax ecx edx stack stack stack stack stack
extern "C++" __declspec(nothrow) void __cdecl FUN_002c0450(int, int, int, void *, unsigned *, int, int, unsigned);
// equiv-conv: FUN_002c03e0 eax ecx edx stack stack stack stack
extern "C++" __declspec(nothrow) void __cdecl FUN_002c03e0(int, int, int, void *, unsigned int *, int, int);

class Image32 {
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
    virtual unsigned int vfunc_9(int x, int y);
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(Image32* src, int srcX, int srcY, int width, int height, int dstX, int dstY);
    char pad04[0x10 - 4];
    int width;
    int height;
    int bpp;
    unsigned int colorKey;
    char pad20[4];
    unsigned int* pixels;
    char hasAlpha;
    char useColorKey;
};

void Image32::vfunc_12(Image32* src, int srcX, int srcY, int w, int h, int dstX, int dstY)
{
    hasAlpha = src->hasAlpha;
    if (dstX < 0) {
        srcX += dstX;
        w -= dstX;
        dstX = 0;
    }
    if (dstY < 0) {
        srcY += dstY;
        h -= dstY;
        dstY = 0;
    }
    if (w + dstX > width)
        w = width - dstX;
    if (h + dstY > height)
        h = height - dstY;
    if (w < 1 || h < 1)
        return;
    if (src->pixels == 0)
        return;
    unsigned int* dstPixels = pixels;
    if (dstPixels == 0)
        return;
    if (src->bpp == 32) {
        unsigned int* srcPtr = src->pixels + (src->width * srcY + srcX);
        unsigned int* dstPtr = dstPixels + (width * dstY + dstX);
        if (src->useColorKey) {
            FUN_002c0360(h, src->width, dstPtr, srcPtr, w, width, src->colorKey);
        } else {
            FUN_002c0200((const unsigned char *)(char *)((char*)srcPtr), (unsigned char *)(char *)((char*)dstPtr), h, (int)(w * 4), src->width * 4, width * 4);
        }
    } else {
        unsigned int* dstPtr = dstPixels + (width * dstY + dstX);
        if (src->useColorKey) {
            FUN_002c0450(srcY, w, h, (Image32 *)src, (unsigned *)(unsigned int *)dstPtr, srcX, width, (unsigned int)(src->colorKey));
        } else {
            FUN_002c03e0(w, h, width, (Image32 *)src, dstPtr, srcX, srcY);
        }
    }
}
} // namespace fn_002c0a60

