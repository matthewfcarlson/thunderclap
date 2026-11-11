// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002ae0e0..0x002ae8a0 (kind game, layer engine, confidence high), dominant class pure3d::TextureBuilder
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#include "gen/pure3d.h"
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
struct Object_2ae1a0 {
 int field0; pure3d::Texture* resource; char pad[24]; int field20; int field24; int field28; int field2c; int depth;
 int run(int width,int height,int requestedDepth,int unused,void* palette);
};
} // namespace fn_f9c5e282
namespace pure3d {
struct PixelFormat_2ae5a0 {
 int width; int unknown4; int bits; char reserved[8]; unsigned char directCopy; char pad[3];
 unsigned redLeft, greenLeft, blueLeft, alphaLeft;
 unsigned redRight, greenRight, blueRight, alphaRight;
 unsigned FUN_002addb0(unsigned pixel);
};
}
namespace fn_f9c5e282 {
class ImageHandler {
  public:
    class Builder {
      public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void vfunc_7();
        virtual void vfunc_8();
    };
};
class TextureBuilder : public ImageHandler::Builder {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void vfunc_9();
    virtual void vfunc_10();
    void* mThing;
    char pad[0x14];
    void* mArg;
};
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
    virtual void v14(void*);
};
} // namespace fn_f9c5e282
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
#endif
namespace fn_f9c5e282 {
struct X_2ae880 {
    char pad[0x14];
    unsigned value;
};

} // namespace fn_f9c5e282

// 0x002ae0e0 pure3d::TextureBuilder::vfunc_9 (10 B): matches/0x002ae0e0.cpp
// sym: ?vfunc_9@TextureBuilder@pure3d@@UAEXH@Z
// Same code shape as 0x00083d70 (propagated; names are from that function)
void pure3d::TextureBuilder::vfunc_9(int x) {
    this->f_28 = x;
}

namespace fn_f9c5e282 {

// 0x002ae1a0 FUN_002ae1a0 (266 B): equivalent/0x002ae1a0.cpp
// sym: ?run@Object_2ae1a0@fn_f9c5e282@@QAEHHHHHPAX@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_002ae1a0 @ 0x002ae1a0
int Object_2ae1a0::run(int width,int height,int requestedDepth,int unused,void* palette) {
 if(resource) resource->vfunc_1();
 pure3d::Texture* p=(pure3d::Texture*)FUN_00263ea0(24);
 if(p) p=((Texture_nv_2ae1a0*)(p))->FUN_002c1c30();
 resource=p;
 if(depth==16) ((Texture_nv_2ae1a0*)(resource))->FUN_002c1c70(width,height,16,field20,field24,0,field2c);
 else if(depth>8 || requestedDepth>8) ((Texture_nv_2ae1a0*)(resource))->FUN_002c1c70(width,height,32,field20,field24,0,field2c);
 else if(requestedDepth==8) { ((Texture_nv_2ae1a0*)(resource))->FUN_002c1c70(width,height,8,field20,field24,1,field2c); (*(Surface_2ae1a0 * *)&resource->f_10)->setPalette(256,palette); }
 else if(requestedDepth==4) { ((Texture_nv_2ae1a0*)(resource))->FUN_002c1c70(width,height,4,field20,field24,1,field2c); (*(Surface_2ae1a0 * *)&resource->f_10)->setPalette(16,palette); }
 if((*(Surface_2ae1a0 * *)&resource->f_10)) return (*(Manager_2ae1a0**)&DAT_0052c2a0)->slot2();
 return 0;
}

} // namespace fn_f9c5e282

// 0x002ae2b0 pure3d::TextureBuilder::vfunc_0 (529 B): equivalent/0x002ae2b0.cpp [wrapped: conflict: pure3d::TextureBuilder]
// sym: ?vfunc_0@TextureBuilder@pure3d@fn_002ae2b0@@UAE_NHHHHH@Z
namespace fn_002ae2b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3106 inputs, branch coverage 62/62)
// pure3d::TextureBuilder::vfunc_0 @ 0x002ae2b0

void *FUN_00263ea0(unsigned int size);

struct Surface_2ae2b0 {
    char pad00[0x48];
    int pitch;
    char pad4c[4];
    unsigned char *data;
};

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
    virtual void vfunc_11(int size, int arg);
    virtual void vfunc_12();
    virtual Surface_2ae2b0 *vfunc_13(int a, int b);
};

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


namespace pure3d {
class TextureBuilder {
public:
    virtual bool vfunc_0(int a1, int a2, int a3, int a4, int a5);
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

    Texture *tex;           // 0x04
    int flags;              // 0x08
    Surface_2ae2b0 *surface;       // 0x0c
    int stride;             // 0x10
    unsigned char *dest;    // 0x14
    int rows;               // 0x18
    int level;              // 0x1c
    int width;              // 0x20
    int height;             // 0x24
    int format;             // 0x28
    int depth;              // 0x2c
    int bpp;                // 0x30
};
}

bool pure3d::TextureBuilder::vfunc_0(int a1, int a2, int a3, int a4, int a5)
{
    if (tex == 0) {
        void *mem = FUN_00263ea0(0x18);
        Texture *t = 0;
        if (mem)
            t = ((Texture *)mem)->FUN_002c1c30();
        tex = t;
        int fmt = format;
        switch (fmt) {
        case 0:
        case 1: {
            int g = bpp;
            if (g == 0x10) {
                t->FUN_002c1c70(a1, a2, 0x10, width, height, 0, depth);
            } else if (g > 8 || a3 > 8) {
                t->FUN_002c1c70(a1, a2, 0x20, width, height, 0, depth);
            } else if (a3 == 8) {
                t->FUN_002c1c70(a1, a2, 8, width, height, 1, depth);
                tex->res->vfunc_11(0x100, a5);
            } else if (a3 == 4) {
                t->FUN_002c1c70(a1, a2, 4, width, height, 1, depth);
                tex->res->vfunc_11(0x10, a5);
            }
            break;
        }
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            t->FUN_002c1c70(a1, a2, 2, 0, height, fmt, depth);
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
            t->FUN_002c1c70(a1, a2, a3, 8, height, fmt, depth);
            break;
        case 0x1c:
            t->FUN_002c1c70(a1, a2, 0x20, 0x1c, height, fmt, depth);
            break;
        default:
            break;
        }
    }

    if (tex->res == 0) {
        if ((*(Device_2ae2b0**)&DAT_0052c2a0)->vfunc_2() != 1) {
            tex->vfunc_1();
            tex = 0;
        }
    }
    if (tex == 0)
        return false;

    surface = tex->res->vfunc_13(level, 0);
    dest = surface->data;
    rows = 0;
    stride = surface->pitch;
    if (a4 == 1) {
        dest = dest + (a2 - 1) * stride;
        stride = -stride;
    }
    flags = a5;
    return true;
}
} // namespace fn_002ae2b0


// 0x002ae5a0 pure3d::TextureBuilder::vfunc_1 (286 B): equivalent/0x002ae5a0.cpp
// sym: ?vfunc_1@TextureBuilder@pure3d@@UAEXPAX@Z
// STATUS: equivalent (tools/equiv.py level 3: 20029 inputs, branch coverage 16/16)
// pure3d::TextureBuilder::vfunc_1 @ 0x002ae5a0
void pure3d::TextureBuilder::vfunc_1(void* __p0) { const unsigned int * source = (const unsigned int *)__p0;

 if (!(*(unsigned int *)&this->f_04)) return;
 if ((*(PixelFormat_2ae5a0 * *)&this->f_0c)->bits == 16) {
  unsigned short* out = (unsigned short*)(*(unsigned char * *)&this->f_14);
  for (int i=0; i<(*(PixelFormat_2ae5a0 * *)&this->f_0c)->width; ++i) {
   PixelFormat_2ae5a0* f = (*(PixelFormat_2ae5a0 * *)&this->f_0c);
   unsigned p = *source++;
   unsigned b = ((p & 0xffu) >> (f->blueRight & 31)) << (f->blueLeft & 31);
   unsigned r = ((p & 0xff0000u) >> (f->redRight & 31)) << (f->redLeft & 31);
   unsigned a = ((p & 0xff000000u) >> (f->alphaRight & 31)) << (f->alphaLeft & 31);
   unsigned g = ((p & 0xff00u) >> (f->greenRight & 31)) << (f->greenLeft & 31);
   *out++ = (unsigned short)(b | r | a | g);
  }
 } else if ((*(PixelFormat_2ae5a0 * *)&this->f_0c)->bits == 32) {
  unsigned* out = (unsigned*)(*(unsigned char * *)&this->f_14);
  if ((*(PixelFormat_2ae5a0 * *)&this->f_0c)->directCopy) {
   unsigned count = ((unsigned)(*(PixelFormat_2ae5a0 * *)&this->f_0c)->width << 2) >> 2;
   for (unsigned i=0; i<count; ++i) *out++ = *source++;
  } else {
   for (int i=0; i<(*(PixelFormat_2ae5a0 * *)&this->f_0c)->width; ++i) {
    unsigned converted = (*(PixelFormat_2ae5a0 * *)&this->f_0c)->FUN_002addb0(*source);
    *out++ = converted;
    ++source;
   }
  }
 }
 (*(unsigned char * *)&this->f_14) += (*(unsigned int *)&this->f_10);
 ++(*(unsigned int *)&this->f_18);
}


// 0x002ae6c0 pure3d::TextureBuilder::vfunc_2 (348 B): equivalent/0x002ae6c0.cpp [wrapped: conflict: pure3d::TextureBuilder]
// sym: ?vfunc_2@TextureBuilder@pure3d@fn_002ae6c0@@UAEXPBE@Z
namespace fn_002ae6c0 {
// STATUS: equivalent (tools/equiv.py level 3: 156 inputs, branch coverage 22/22)
// pure3d::TextureBuilder::vfunc_2 @ 0x002ae6c0
struct PixelFormat_2ae6c0 {
    int count;
    char pad04[4];
    int bits;
    char pad0c[0x18 - 0xc];
    int shlR;
    int shlG;
    int shlB;
    int shlA;
    int shrR;
    int shrG;
    int shrB;
    int shrA;
    unsigned int FUN_002addb0(unsigned int color);
};

namespace pure3d {
class TextureBuilder {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(const unsigned char *src);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();

    int active;
    unsigned int *palette;
    PixelFormat_2ae6c0 *format;
    int stride;
    unsigned char *dest;
    int rows;
};
}

void pure3d::TextureBuilder::vfunc_2(const unsigned char *src)
{
    if (active == 0)
        return;
    int bits = format->bits;
    if (bits == 16) {
        unsigned short *out = (unsigned short *)dest;
        for (int i = 0; i < format->count; i++) {
            unsigned int px = palette[*src];
            PixelFormat_2ae6c0 *f = format;
            unsigned int v = ((px & 0xff) >> f->shrB) << f->shlB;
            v |= ((px & 0xff0000) >> f->shrR) << f->shlR;
            v |= ((px & 0xff000000) >> f->shrA) << f->shlA;
            v |= ((px & 0xff00) >> f->shrG) << f->shlG;
            *out++ = (unsigned short)v;
            src++;
        }
    } else if (bits == 32) {
        unsigned int *out = (unsigned int *)dest;
        for (int i = 0; i < format->count; i++) {
            *out = format->FUN_002addb0(palette[*src]);
            out++;
            src++;
        }
    } else if (bits == 8) {
        unsigned char *out = dest;
        for (int i = 0; i < format->count; i++)
            *out++ = *src++;
    } else if (bits == 4) {
        unsigned char *out = dest;
        for (int i = 0; i < format->count; i += 2) {
            *out++ = (unsigned char)((src[1] << 4) | (src[0] & 0xf));
            src += 2;
        }
    }
    dest = dest + stride;
    rows = rows + 1;
}
} // namespace fn_002ae6c0

namespace fn_f9c5e282 {

// 0x002ae820 pure3d::TextureBuilder::vfunc_10 (22 B): matches/0x002ae820.cpp
// sym: ?vfunc_10@TextureBuilder@fn_f9c5e282@@UAEXXZ
void TextureBuilder::vfunc_10() {
    if (mThing) {
        Receiver_2ae820* r = *(Receiver_2ae820**)((char*)mThing + 0x10);
        r->v14(mArg);
    }
}

} // namespace fn_f9c5e282

// 0x002ae840 pure3d::TextureBuilder::vfunc_3 (41 B): matches/0x002ae840.cpp
// sym: ?vfunc_3@TextureBuilder@pure3d@@UAEXHH@Z
 // namespace pure3d
void pure3d::TextureBuilder::vfunc_3(hulk_intptr __p0, int __p1) { const void * src = (const void *)__p0; unsigned int n = (unsigned int)__p1;

    if ((*(int *)&this->f_04)) {
        memcpy((*(void * *)&this->f_14), src, n);
    }
}


// 0x002ae870 pure3d::TextureBuilder::vfunc_6 (3 B): matches/0x002ae870.cpp
// sym: ?vfunc_6@TextureBuilder@pure3d@@UAEXHHH@Z
// Same code shape as 0x00098430 (propagated; names are from that function)
void pure3d::TextureBuilder::vfunc_6(int , int , int ) {}

namespace fn_f9c5e282 {

// 0x002ae880 pure3d::TextureBuilder::vfunc_4 (4 B): matches/0x002ae880.cpp
// sym: ?target@fn_f9c5e282@@YIIPAUX_2ae880@1@@Z
// Same code shape as 0x000862d0 (propagated; names are from that function)
unsigned __fastcall target(X_2ae880* self) {
    return self->value;
}

} // namespace fn_f9c5e282

// 0x002ae890 pure3d::TextureBuilder::vfunc_5 (7 B): matches/0x002ae890.cpp [wrapped: conflict: ImageHandler]
// sym: ?vfunc_5@TextureBuilder_2ae890@fn_002ae890@@QAEIXZ
namespace fn_002ae890 {
class ImageHandler {
  public:
    class Builder {
      public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
    };
};
class TextureBuilder_2ae890 : public ImageHandler::Builder {
  public:
    char pad[8];
    void* mPtr;
    unsigned int vfunc_5();
};
unsigned int TextureBuilder_2ae890::vfunc_5() {
    return *(unsigned int*)((char*)mPtr + 0x54);
}
} // namespace fn_002ae890

