// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002adf20..0x002ae0e0 (kind game, layer engine, confidence high), dominant class pure3d::ImageBuilder
#include "tree_prelude.h"
#include "gen/pure3d.h"
#include "decls/image_builder.h"
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

} // namespace fn_f8a52572

// 0x002adf20 pure3d::ImageBuilder::vfunc_0 (253 B): equivalent/0x002adf20.cpp [wrapped: conflict: pure3d::ImageBuilder; pure3d::ImageHandler]
// sym: ?vfunc_0@ImageBuilder_2adf20@fn_002adf20@@QAE_NHHHHPAX@Z @a3f1697fca2b @w6d567fbd4d4b @v7c40e9fda8ee
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
 Image* FUN_002bfcb0(); Image* FUN_002bffc0();   // (x64t18) the words: gen's Image8 (below)
};
// (x64t18, D90) the builder's record (decls/image_builder.h HulkImageBuilder): slot 0 is reached only through the game's
// vftable 0x0042e184, so it is a plain member; the image is an Image8 (0x438 bytes) or an Image32 (0x30), whose
// words (gen's f_20 format, f_24 pixels, f_28 flag, at the same offsets in both) are read through gen's Image8
struct ImageBuilder_2adf20 : HulkImageBuilder {
 Image*& img() { return *(Image**)&image; }
 bool vfunc_0(int,int,int,int,void*);
};
bool ImageBuilder_2adf20::vfunc_0(int width,int height,int bits,int direction,void* pal) {
 int bytes=1;
 if(depth<=8 && bits<=8) {
  Image* p=(Image*)FUN_00263ea0(0x438);
  img()=p ? p->FUN_002bfcb0() : 0;
  unsigned n=1u << (bits & 31);
  img()->palette(pal,n);
  img()->count(n);
 } else {
  Image* p=(Image*)FUN_00263ea0(0x30);
  img()=p ? p->FUN_002bffc0() : 0;
  bytes=4;
 }
 img()->size(width,height);
 ((::pure3d::Image8*)image)->f_28=1;
 ((::pure3d::Image8*)image)->f_20=bits==32 ? 8 : 1;
 row=(unsigned char*)((::pure3d::Image8*)image)->f_24;
 rows=0;
 stride=bytes*width;
 if(direction==1) { row+=(height-1)*bytes*width; stride=-stride; }
 palette=(unsigned int*)pal;
 return true;
}
} // namespace fn_002adf20


// 0x002ae020 pure3d::ImageBuilder::vfunc_1 (57 B): matches/0x002ae020.cpp [wrapped: conflict: pure3d::ImageBuilder; pure3d::ImageHandler]
// sym: ?vfunc_1@ImageBuilder_2ae020@fn_002ae020@@QAEXPBX@Z
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

} // namespace pure3d

// (x64t18, D90) the builder's record (decls/image_builder.h): slot 1, a 32-bit row into the Image32 (its width, gen's
// f_10; the view read it 4 bytes short natively, and added the stride as an unsigned word: 4 GB past the row for a
// bottom-up image)
struct ImageBuilder_2ae020 : HulkImageBuilder {
    void vfunc_1(const void* src);
};

void ImageBuilder_2ae020::vfunc_1(const void* src) {
    unsigned int n = (unsigned int)((::pure3d::Image32*)image)->f_10;
    memcpy(row, src, n << 2);
    row += stride;
    ++rows;
}
} // namespace fn_002ae020


// 0x002ae060 pure3d::ImageBuilder::vfunc_2 (100 B): matches/0x002ae060.cpp
// sym: ?vfunc_2@ImageBuilder@pure3d@@UAEXPAX@Z
// (x64t18, D90) the builder's record (decls/image_builder.h; gen's words natively the same): a paletted row, copied
// into an Image8 or expanded through the palette into an Image32 (the image's width and bits, gen's f_10 / f_18 at the
// same offsets in both; the view read them 4 bytes short natively)
void pure3d::ImageBuilder::vfunc_2(void* __p0) { const unsigned char * src = (const unsigned char *)__p0;
    HulkImageBuilder* self = (HulkImageBuilder*)this;

    int n;
    if (((::pure3d::Image8*)self->image)->f_18 == 8) {
        n = ((::pure3d::Image8*)self->image)->f_10;
        memcpy(self->row, src, n);
    } else {
        n = ((::pure3d::Image8*)self->image)->f_10;
        for (int i = 0; i < n; i++)
            ((unsigned*)self->row)[i] = self->palette[src[i]];
    }
    self->row += self->stride;
    self->rows++;
}

namespace fn_f8a52572 {

// 0x002ae0d0 pure3d::ImageBuilder::vfunc_10 (1 B): matches/0x002ae0d0.cpp
// sym: ?FUN_002ae0d0@fn_f8a52572@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_002ae0d0() {}

} // namespace fn_f8a52572
