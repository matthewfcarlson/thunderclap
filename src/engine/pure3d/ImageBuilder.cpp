// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002adf20..0x002ae0e0 (kind game, layer engine, confidence high), dominant class pure3d::ImageBuilder
#include "tree_prelude.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f8a52572 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f8a52572 {} using namespace fn_f8a52572;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned);
#endif
namespace fn_f8a52572 {
struct Info_2ae060 {
    char p[0x10];
    int count;
    int p14;
    int bpp;
};

} // namespace fn_f8a52572

// 0x002adf20 pure3d::ImageBuilder::vfunc_0 (253 B): equivalent/0x002adf20.cpp [wrapped: conflict: pure3d::ImageBuilder; pure3d::ImageHandler]
// sym: ?vfunc_0@ImageBuilder@pure3d@fn_002adf20@@UAE_NHHHHPAX@Z
namespace fn_002adf20 {
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 12/12)
// pure3d::ImageBuilder::vfunc_0 @ 0x002adf20
void* __cdecl FUN_00263ea0(unsigned);
struct Image {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
 virtual void size(int,int);
 virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12();
 virtual void count(unsigned);
 virtual void s14(); virtual void s15(); virtual void palette(void*,unsigned);
 char pad[0x1c]; int format; char* pixels; unsigned char flag;
 Image* FUN_002bfcb0(); Image* FUN_002bffc0();
};
namespace pure3d { struct ImageHandler { struct Builder {
 virtual bool vfunc_0(int,int,int,int,void*);
 virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10();
 Image* image; void* paletteData; char* cursor; int index; int stride; int depth;
}; }; struct ImageBuilder : ImageHandler::Builder { virtual bool vfunc_0(int,int,int,int,void*); }; }
bool pure3d::ImageBuilder::vfunc_0(int width,int height,int bits,int direction,void* pal) {
 int bytes=1;
 if(depth<=8 && bits<=8) {
  Image* p=(Image*)FUN_00263ea0(0x438);
  image=p ? p->FUN_002bfcb0() : 0;
  unsigned n=1u << (bits & 31);
  image->palette(pal,n);
  image->count(n);
 } else {
  Image* p=(Image*)FUN_00263ea0(0x30);
  image=p ? p->FUN_002bffc0() : 0;
  bytes=4;
 }
 image->size(width,height);
 image->flag=1;
 image->format=bits==32 ? 8 : 1;
 cursor=image->pixels;
 index=0;
 stride=bytes*width;
 if(direction==1) { cursor+=(height-1)*bytes*width; stride=-stride; }
 paletteData=pal;
 return true;
}
} // namespace fn_002adf20


// 0x002ae020 pure3d::ImageBuilder::vfunc_1 (57 B): matches/0x002ae020.cpp [wrapped: conflict: pure3d::ImageBuilder; pure3d::ImageHandler]
// sym: ?vfunc_1@ImageBuilder@pure3d@fn_002ae020@@UAEXPBX@Z
namespace fn_002ae020 {

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned int);
#endif


namespace pure3d {
class ImageHandler {
  public:
    class Builder {
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
    };
};

class ImageBuilder : public ImageHandler::Builder {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(const void* src);
    virtual void vfunc_2();
    virtual void vfunc_10();
    char* mContext;
    char pad8[4];
    char* mData;
    unsigned int mCount;
    unsigned int mStride;
};

void ImageBuilder::vfunc_1(const void* src) {
    unsigned int n = *reinterpret_cast<unsigned int*>(mContext + 0x10);
    memcpy(mData, src, n << 2);
    mData += mStride;
    ++mCount;
}
} // namespace pure3d
} // namespace fn_002ae020


// 0x002ae060 pure3d::ImageBuilder::vfunc_2 (100 B): matches/0x002ae060.cpp
// sym: ?vfunc_2@ImageBuilder@pure3d@@UAEXPAX@Z
void pure3d::ImageBuilder::vfunc_2(void* __p0) { const unsigned char * src = (const unsigned char *)__p0;

    int n;
    if ((*(Info_2ae060 * *)&this->f_04)->bpp == 8) {
        n = (*(Info_2ae060 * *)&this->f_04)->count;
        memcpy((*(unsigned char * *)&this->f_0c), src, n);
    } else {
        n = (*(Info_2ae060 * *)&this->f_04)->count;
        for (int i = 0; i < n; i++)
            ((unsigned*)(*(unsigned char * *)&this->f_0c))[i] = (*(unsigned int * *)&this->f_08)[src[i]];
    }
    (*(unsigned char * *)&this->f_0c) += (*(int *)&this->f_14);
    (*(int *)&this->f_10)++;
}

namespace fn_f8a52572 {

// 0x002ae0d0 pure3d::ImageBuilder::vfunc_10 (1 B): matches/0x002ae0d0.cpp
// sym: ?FUN_002ae0d0@fn_f8a52572@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_002ae0d0() {}

} // namespace fn_f8a52572
