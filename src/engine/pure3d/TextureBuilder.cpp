// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002ae0e0..0x002ae8a0 (kind game, layer engine, confidence high), dominant class pure3d::TextureBuilder
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#include "gen/pure3d.h"
#include "decls/texture_builder.h"
#define TREE_TU_BEGIN namespace fn_f9c5e282 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f9c5e282 {} using namespace fn_f9c5e282;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f9c5e282 {
struct Surface_2ae1a0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void setPalette(int count, void* palette);
};
struct Texture_nv_2ae1a0 {
    pure3d::Texture* FUN_002c1c30();
    void FUN_002c1c70(int width,int height,int depth,int a,int b,int palette,int c);
};
struct Manager_2ae1a0 { virtual void slot0(); virtual void slot1(); virtual int slot2(); };
extern void* __cdecl FUN_00263ea0(int);
// (x64t17) the builder's record (decls/texture_builder.h)
struct Object_2ae1a0 : HulkTextureBuilder {
 int run(int width,int height,int requestedDepth,int unused,void* palette);
};
} // namespace fn_f9c5e282
namespace pure3d {
// (x64t17) the locked level (decls/texture_builder.h HulkPixelLock; channels red, green, blue, alpha)
struct PixelFormat_2ae5a0 : HulkPixelLock {
 unsigned FUN_002addb0(unsigned pixel);
};
}
namespace fn_f9c5e282 {
class Receiver_2ae820 {
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
    virtual void v14(int level);   // (x64t17) the pddi texture's unlock (d3dTexture 0x00326a10)
};
} // namespace fn_f9c5e282
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
#endif
namespace fn_f9c5e282 {
} // namespace fn_f9c5e282

// 0x002ae0e0 pure3d::TextureBuilder::vfunc_9 (10 B): matches/0x002ae0e0.cpp
// sym: ?vfunc_9@TextureBuilder@pure3d@@UAEXH@Z
// Same code shape as 0x00083d70 (propagated; names are from that function)
void pure3d::TextureBuilder::vfunc_9(int x) {
    this->f_28 = x;
}

namespace fn_f9c5e282 {

// 0x002ae1a0 FUN_002ae1a0 (266 B): equivalent/0x002ae1a0.cpp
// sym: ?run@Object_2ae1a0@fn_f9c5e282@@QAEHHHHHPAX@Z @48a113ad4cea @w9cdf5c85e7f0 @v4709bac5ef1e
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_002ae1a0 @ 0x002ae1a0
int Object_2ae1a0::run(int width,int height,int requestedDepth,int unused,void* palette) {
 if(texture) texture->vfunc_1();
 pure3d::Texture* p=(pure3d::Texture*)FUN_00263ea0(sizeof(::pure3d::Texture));   // (x64t16) 0x18 on the 32-bit builds
 if(p) p=((Texture_nv_2ae1a0*)(p))->FUN_002c1c30();
 texture=p;
 if(bits==16) ((Texture_nv_2ae1a0*)(texture))->FUN_002c1c70(width,height,16,alphaDepth,mips,0,usage);
 else if(bits>8 || requestedDepth>8) ((Texture_nv_2ae1a0*)(texture))->FUN_002c1c70(width,height,32,alphaDepth,mips,0,usage);
 else if(requestedDepth==8) { ((Texture_nv_2ae1a0*)(texture))->FUN_002c1c70(width,height,8,alphaDepth,mips,1,usage); ((Surface_2ae1a0*)texture->f_10)->setPalette(256,palette); }
 else if(requestedDepth==4) { ((Texture_nv_2ae1a0*)(texture))->FUN_002c1c70(width,height,4,alphaDepth,mips,1,usage); ((Surface_2ae1a0*)texture->f_10)->setPalette(16,palette); }
 if(texture->f_10) return (*(Manager_2ae1a0**)&DAT_0052c2a0)->slot2();
 return 0;
}

} // namespace fn_f9c5e282

// 0x002ae2b0 pure3d::TextureBuilder::vfunc_0 (529 B): equivalent/0x002ae2b0.cpp [wrapped: conflict: pure3d::TextureBuilder]
// sym: ?vfunc_0@TextureBuilder@pure3d@fn_002ae2b0@@QAE_NHHHHPAI@Z @42553a1ce8a9 @w96d592fc8802 @vb0ca69230046
namespace fn_002ae2b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3106 inputs, branch coverage 62/62)
// pure3d::TextureBuilder::vfunc_0 @ 0x002ae2b0

void *FUN_00263ea0(unsigned int size);

class Resource_2ae2b0 {
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
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11(int count, unsigned int *palette);
    virtual void vfunc_12();
    virtual HulkPixelLock *vfunc_13(int level, int flags);
};

// pure3d::Texture: its vftable and Entity's three words, then the resource (the pddi texture; gen's f_10, natively
// at +0x18)
class Texture {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    char pad04[0xc];
    Resource_2ae2b0 *res;
    Texture *FUN_002c1c30();
    bool FUN_002c1c70(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};

class Device_2ae2b0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual int vfunc_2();
};


// (x64t17) the builder's record (decls/texture_builder.h): slot 0 of the game's vftable 0x0042e154
namespace pure3d {
struct TextureBuilder : HulkTextureBuilder {
    bool vfunc_0(int a1, int a2, int a3, int a4, unsigned int *a5);
};
}

static inline Resource_2ae2b0 *res_2ae2b0(::pure3d::Texture *t) { return ((Texture *)t)->res; }

bool pure3d::TextureBuilder::vfunc_0(int a1, int a2, int a3, int a4, unsigned int *a5)
{
    if (texture == 0) {
        void *mem = FUN_00263ea0(sizeof(::pure3d::Texture));   // (x64t16) 0x18 on the 32-bit builds
        Texture *t = 0;
        if (mem)
            t = ((Texture *)mem)->FUN_002c1c30();
        texture = (::pure3d::Texture *)t;
        int fmt = format;
        switch (fmt) {
        case 0:
        case 1: {
            int g = bits;
            if (g == 0x10) {
                t->FUN_002c1c70(a1, a2, 0x10, alphaDepth, mips, 0, usage);
            } else if (g > 8 || a3 > 8) {
                t->FUN_002c1c70(a1, a2, 0x20, alphaDepth, mips, 0, usage);
            } else if (a3 == 8) {
                t->FUN_002c1c70(a1, a2, 8, alphaDepth, mips, 1, usage);
                res_2ae2b0(texture)->vfunc_11(0x100, a5);
            } else if (a3 == 4) {
                t->FUN_002c1c70(a1, a2, 4, alphaDepth, mips, 1, usage);
                res_2ae2b0(texture)->vfunc_11(0x10, a5);
            }
            break;
        }
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            t->FUN_002c1c70(a1, a2, 2, 0, mips, fmt, usage);
            break;
        case 0xd:
        case 0xe:
        case 0xf:
        case 0x10:
        case 0x1b:
        case 0x11:
        case 0x12:
        case 0x15:
        case 0x13:
        case 0x14:
            t->FUN_002c1c70(a1, a2, a3, 8, mips, fmt, usage);
            break;
        case 0x1c:
            t->FUN_002c1c70(a1, a2, 0x20, 0x1c, mips, fmt, usage);
            break;
        default:
            break;
        }
    }

    if (res_2ae2b0(texture) == 0) {
        if ((*(Device_2ae2b0**)&DAT_0052c2a0)->vfunc_2() != 1) {
            ((Texture *)texture)->vfunc_1();
            texture = 0;
        }
    }
    if (texture == 0)
        return false;

    lock = res_2ae2b0(texture)->vfunc_13(level, 0);
    row = lock->bits;
    rows = 0;
    stride = lock->stride;
    if (a4 == 1) {
        row = row + (a2 - 1) * stride;
        stride = -stride;
    }
    palette = a5;
    return true;
}
} // namespace fn_002ae2b0


// 0x002ae5a0 pure3d::TextureBuilder::vfunc_1 (286 B): equivalent/0x002ae5a0.cpp
// sym: ?vfunc_1@TextureBuilder@pure3d@@UAEXPAX@Z @5f22fb33fdbf @w2a35bac3a86b @v38792ffa0aff
// STATUS: equivalent (tools/equiv.py level 3: 20029 inputs, branch coverage 16/16)
// pure3d::TextureBuilder::vfunc_1 @ 0x002ae5a0
void pure3d::TextureBuilder::vfunc_1(void* __p0) { const unsigned int * source = (const unsigned int *)__p0;

 // (x64t17) the record's fields (decls/texture_builder.h): the texture and the row pointers natively 8 bytes; the
 // stride an int (negative for a bottom-up lock; added as an unsigned it moved the row 4 GB natively)
 if (!this->f_04) return;
 if (((PixelFormat_2ae5a0 *)this->f_0c)->bitsPerPixel == 16) {
  unsigned short* out = (unsigned short*)this->f_14;
  for (int i=0; i<((PixelFormat_2ae5a0 *)this->f_0c)->width; ++i) {
   PixelFormat_2ae5a0* f = (PixelFormat_2ae5a0 *)this->f_0c;
   unsigned p = *source++;
   unsigned b = ((p & 0xffu) >> (f->right[2] & 31)) << (f->left[2] & 31);
   unsigned r = ((p & 0xff0000u) >> (f->right[0] & 31)) << (f->left[0] & 31);
   unsigned a = ((p & 0xff000000u) >> (f->right[3] & 31)) << (f->left[3] & 31);
   unsigned g = ((p & 0xff00u) >> (f->right[1] & 31)) << (f->left[1] & 31);
   *out++ = (unsigned short)(b | r | a | g);
  }
 } else if (((PixelFormat_2ae5a0 *)this->f_0c)->bitsPerPixel == 32) {
  unsigned* out = (unsigned*)this->f_14;
  if (((PixelFormat_2ae5a0 *)this->f_0c)->direct) {
   unsigned count = ((unsigned)((PixelFormat_2ae5a0 *)this->f_0c)->width << 2) >> 2;
   for (unsigned i=0; i<count; ++i) *out++ = *source++;
  } else {
   for (int i=0; i<((PixelFormat_2ae5a0 *)this->f_0c)->width; ++i) {
    unsigned converted = ((PixelFormat_2ae5a0 *)this->f_0c)->FUN_002addb0(*source);
    *out++ = converted;
    ++source;
   }
  }
 }
 this->f_14 += this->f_10;
 ++this->f_18;
}


// 0x002ae6c0 pure3d::TextureBuilder::vfunc_2 (348 B): equivalent/0x002ae6c0.cpp [wrapped: conflict: pure3d::TextureBuilder]
// sym: ?vfunc_2@TextureBuilder@pure3d@fn_002ae6c0@@QAEXPBE@Z @5f0007bfab7d @wa29135a7a2aa @v4890380f5dcf
namespace fn_002ae6c0 {
// STATUS: equivalent (tools/equiv.py level 3: 156 inputs, branch coverage 22/22)
// pure3d::TextureBuilder::vfunc_2 @ 0x002ae6c0
// (x64t17) the locked level (decls/texture_builder.h HulkPixelLock)
struct PixelFormat_2ae6c0 : HulkPixelLock {
    unsigned int FUN_002addb0(unsigned int color);
};

// (x64t17) the builder's record (decls/texture_builder.h): slot 2 of the game's vftable 0x0042e154
namespace pure3d {
struct TextureBuilder : HulkTextureBuilder {
    void vfunc_2(const unsigned char *src);
    PixelFormat_2ae6c0 *format() { return (PixelFormat_2ae6c0 *)lock; }
};
}

void pure3d::TextureBuilder::vfunc_2(const unsigned char *src)
{
    if (texture == 0)
        return;
    int bits = format()->bitsPerPixel;
    if (bits == 16) {
        unsigned short *out = (unsigned short *)row;
        for (int i = 0; i < format()->width; i++) {
            unsigned int px = palette[*src];
            PixelFormat_2ae6c0 *f = format();
            unsigned int v = ((px & 0xff) >> f->right[2]) << f->left[2];
            v |= ((px & 0xff0000) >> f->right[0]) << f->left[0];
            v |= ((px & 0xff000000) >> f->right[3]) << f->left[3];
            v |= ((px & 0xff00) >> f->right[1]) << f->left[1];
            *out++ = (unsigned short)v;
            src++;
        }
    } else if (bits == 32) {
        unsigned int *out = (unsigned int *)row;
        for (int i = 0; i < format()->width; i++) {
            *out = format()->FUN_002addb0(palette[*src]);
            out++;
            src++;
        }
    } else if (bits == 8) {
        unsigned char *out = row;
        for (int i = 0; i < format()->width; i++)
            *out++ = *src++;
    } else if (bits == 4) {
        unsigned char *out = row;
        for (int i = 0; i < format()->width; i += 2) {
            *out++ = (unsigned char)((src[1] << 4) | (src[0] & 0xf));
            src += 2;
        }
    }
    row = row + stride;
    rows = rows + 1;
}
} // namespace fn_002ae6c0

// 0x002ae820 pure3d::TextureBuilder::vfunc_10 (22 B): matches/0x002ae820.cpp
// sym: ?vfunc_10@TextureBuilder@pure3d@@UAEXXZ
// (x64t17) on gen's class (the record's fields): unlocks the level the texture's pddi texture locked
void pure3d::TextureBuilder::vfunc_10() {
    if (f_04) {
        Receiver_2ae820* r = (Receiver_2ae820*)f_04->f_10;
        r->v14(f_1c);
    }
}

// 0x002ae840 pure3d::TextureBuilder::vfunc_3 (41 B): matches/0x002ae840.cpp
// sym: ?vfunc_3@TextureBuilder@pure3d@@UAEXHH@Z
 // namespace pure3d
void pure3d::TextureBuilder::vfunc_3(hulk_intptr __p0, int __p1) { const void * src = (const void *)__p0; unsigned int n = (unsigned int)__p1;

    if (this->f_04) {
        memcpy(this->f_14, src, n);
    }
}


// 0x002ae870 pure3d::TextureBuilder::vfunc_6 (3 B): matches/0x002ae870.cpp
// sym: ?vfunc_6@TextureBuilder@pure3d@@UAEXHHH@Z
// Same code shape as 0x00098430 (propagated; names are from that function)
void pure3d::TextureBuilder::vfunc_6(int , int , int ) {}

namespace fn_f9c5e282 {

// 0x002ae880 pure3d::TextureBuilder::vfunc_4 (4 B): matches/0x002ae880.cpp
// sym: ?target@fn_f9c5e282@@YIPAEPAUHulkTextureBuilder@@@Z
// Same code shape as 0x000862d0 (propagated; names are from that function)
// (x64t17) the next row (the record's +0x14, a pointer natively)
unsigned char* __fastcall target(HulkTextureBuilder* self) {
    return self->row;
}

} // namespace fn_f9c5e282

// 0x002ae890 pure3d::TextureBuilder::vfunc_5 (7 B): matches/0x002ae890.cpp [wrapped: conflict: ImageHandler]
// sym: ?vfunc_5@TextureBuilder_2ae890@fn_002ae890@@QAEIXZ
namespace fn_002ae890 {
// (x64t17) the builder's record (decls/texture_builder.h): the word after the lock (the lock is d3dTexture's at +0x70,
// this its +0xc4)
struct TextureBuilder_2ae890 : HulkTextureBuilder {
    unsigned int vfunc_5();
};
unsigned int TextureBuilder_2ae890::vfunc_5() {
    return *(unsigned int*)(lock + 1);
}
} // namespace fn_002ae890

