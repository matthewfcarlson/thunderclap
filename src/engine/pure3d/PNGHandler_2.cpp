// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002ad790..0x002adda0 (kind game, layer engine, confidence medium), dominant class pure3d::PNGHandler
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f4f469f6 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f4f469f6 {} using namespace fn_f4f469f6;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f4f469f6 {
class Obj {
  public:
};
extern "C" Obj* __cdecl FUN_002d6dd0(int);
int __cdecl FUN_00266f00(int allocator, void* pointer);
class ImageHandler_2ad800 {
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
};
struct PngInfo;
struct PngRead;
struct PngColor {
    unsigned char red, green, blue;
};
extern int __cdecl FUN_002d7ed0(PngRead *png, PngInfo *info);
extern int __cdecl FUN_002d7ef0(PngRead *png, PngInfo *info);
extern int __cdecl FUN_002d8550(PngRead *png, PngInfo *info, PngColor **palette, int *count);
extern unsigned __cdecl FUN_002d7e90(PngRead *png, PngInfo *info, unsigned flag);
extern int __cdecl FUN_002d8630(PngRead *png, PngInfo *info, unsigned char **trans, int *count, void *values);
extern int __cdecl FUN_002d7eb0(PngRead *png, PngInfo *info);
extern void *__cdecl FUN_00266e00(int count, int size);
extern void __cdecl FUN_002d7440(PngRead *png, unsigned char *row, unsigned char *display);
extern "C" void __cdecl FUN_00267090(void *p);
class TextureSink {
public:
    virtual void vfunc_0(int width, int height, int format, int flags, unsigned *palette);
    virtual void vfunc_1();
    virtual void vfunc_2(unsigned char *scanline);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
};
struct Frame_2ad820 {
    int pad0c;
    int width;
    int height;
    int paletteCount;
    PngColor *paletteIn;
    unsigned char *trans;
    int transCount;
    unsigned palette[256];
};
struct png_struct;
struct png_info;
unsigned int FUN_002d7ed0(png_struct *png, png_info *info);
unsigned int FUN_002d7ef0(png_struct *png, png_info *info);
unsigned int FUN_002d8550(png_struct *png, png_info *info, unsigned char **palette, int *numPalette);
unsigned int FUN_002d7e90(png_struct *png, png_info *info, unsigned int mask);
unsigned int FUN_002d8630(png_struct *png, png_info *info, unsigned char **trans, int *numTrans, void *transValues);
unsigned int FUN_002d7eb0(png_struct *png, png_info *info);
void *FUN_00266e00(int tag, unsigned int size);
void FUN_002d7440(png_struct *png, void *row, int zero);
class ImageSink_2ad9d0 {
public:
    virtual void begin(unsigned int width, unsigned int height, int bitDepth, int flags, unsigned int *palette);
    virtual void v1();
    virtual void writeRow(void *row);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void finish();
};
struct Frame_2ad9d0 {
    union {
        unsigned int height;
        int numTrans;
    };
    int numPalette;
    unsigned char *plte;
    unsigned int width;
    unsigned char *trans;
    unsigned int palette[256];
};
class ImageSink_2adba0 {
public:
    virtual void begin(unsigned int width, unsigned int height, int bitDepth, int flags, unsigned int *palette);
    virtual void v1();
    virtual void writeRow(void *row);
};
struct PngInfoView {
    char pad0[0x1e];
    unsigned char pixelDepth;
};
void FUN_002ad790();
void FUN_002ad7c0();
void FUN_002ad7d0();
void FUN_002ad7e0();
void FUN_002ad7f0();
png_struct *__cdecl FUN_002d6f10(const char *version, void *errPtr, void (*errFn)(), void (*warnFn)(), void *memPtr,
                                 void (*mallocFn)(), void (*freeFn)());
png_info *__cdecl FUN_002d6ea0(png_struct *png);
void __cdecl FUN_002d7df0(png_struct **png, png_info **info, png_info **endInfo);
void __cdecl FUN_002dd6f0(png_struct *png, void *io, void (*readFn)());
void __cdecl FUN_002d7150(png_struct *png, png_info *info);
unsigned char __cdecl FUN_002d7f10(png_struct *png, png_info *info);
unsigned char __cdecl FUN_002d7f30(png_struct *png, png_info *info);
char __cdecl FUN_002d7f70(png_struct *png, png_info *info);
void __cdecl FUN_002d8830(png_struct *png);
void __cdecl FUN_002d8820(png_struct *png);
void __cdecl FUN_002dd1a0(png_struct *png);
void __cdecl FUN_002dd250(png_struct *png, int filler, int where);
void __cdecl FUN_002d9060(png_struct *png);
void __cdecl FUN_002d73f0(png_struct *png, png_info *info);
void __cdecl FUN_002d6ed0(png_struct *png, png_info **info);
extern "C" void __cdecl FUN_002ad820(void *, void *, void *);
extern "C" void __cdecl FUN_002ad9d0(void *, void *, void *);
void FUN_002adb10(png_info *info, png_struct *png, ImageSink_2adba0 *sink);


// 0x002ad790 FUN_002ad790 (35 B): matches/0x002ad790.cpp
// sym: ?Target@fn_f4f469f6@@YAXHHH@Z
void __cdecl Target(int a, int b, int c) {
    Obj* p = FUN_002d6dd0(a);
    ((owners::X_2647e0 *)p)->FUN_002647e0((hulk_intptr)b, (hulk_intptr)c, 1, (hulk_intptr)1);
}

} // namespace fn_f4f469f6

// 0x002ad7c0 FUN_002ad7c0 (1 B): matches/0x002ad7c0.cpp [wrapped: compile error C2732: linkage specification contradicts earlier specification for 'fn_f4f469f6::FUN_002ad7c0']
// sym: _FUN_002ad7c0
namespace fn_002ad7c0 {
extern "C" void FUN_002ad7c0() {}
} // namespace fn_002ad7c0


// 0x002ad7d0 FUN_002ad7d0 (1 B): matches/0x002ad7d0.cpp [wrapped: compile error C2732: linkage specification contradicts earlier specification for 'fn_f4f469f6::FUN_002ad7d0']
// sym: _FUN_002ad7d0
namespace fn_002ad7d0 {
extern "C" void __cdecl FUN_002ad7d0() {}
} // namespace fn_002ad7d0


// 0x002ad7e0 FUN_002ad7e0 (13 B): matches/0x002ad7e0.cpp [wrapped: conflict: FUN_00266e00]
// sym: ?FUN_002ad7e0@fn_002ad7e0@@YAXHH@Z
namespace fn_002ad7e0 {
extern void __cdecl FUN_00266e00(int, int);
void __cdecl FUN_002ad7e0(int arg, int b) {
    arg = 1;
    FUN_00266e00(arg, b);
}
} // namespace fn_002ad7e0

namespace fn_f4f469f6 {

// 0x002ad7f0 FUN_002ad7f0 (13 B): matches/0x002ad7f0.cpp
// sym: ?FUN_002ad7f0@fn_f4f469f6@@YAXPAX0@Z
// The PNG reader's free callback (0x002adba0 passes it to the png_create_read_struct_2-shaped 0x002d6f10 after the
// malloc one): `__cdecl (png, pointer)`, forwarding to the cdecl 0x00266f00 (the allocator table 0x00527c60's
// fifth virtual) with allocator 1: the original stores 1 over its first word and jumps. native15: was spelled as a
// thiscall member calling a thiscall member, which pops 4 bytes natively where both functions pop none (check 7).
void __cdecl FUN_002ad7f0(void* png, void* pointer) {
    FUN_00266f00(1, pointer);
}

} // namespace fn_f4f469f6

// 0x002ad800 pure3d::PNGHandler::vfunc_8 (15 B): matches/0x002ad800.cpp
// sym: ?vfunc_8@PNGHandler@pure3d@@UAE_NH@Z
bool pure3d::PNGHandler::vfunc_8(int x) {
    return x == 1;
}

namespace fn_f4f469f6 {

// 0x002ad820 FUN_002ad820 (421 B): equivalent/0x002ad820.cpp
// sym: _FUN_002ad820
// STATUS: equivalent (tools/equiv.py level 3: 20 inputs, branch coverage 18/18)
// FUN_002ad820 @ 0x002ad820
// equiv-conv: FUN_002ad820 eax stack stack
extern "C" void FUN_002ad820(void *info, void *png, void *sink)
{
    Frame_2ad820 f;
    f.width = FUN_002d7ed0(((PngRead *)png), ((PngInfo *)info));
    f.height = FUN_002d7ef0(((PngRead *)png), ((PngInfo *)info));
    f.paletteCount = 0;
    FUN_002d8550(((PngRead *)png), ((PngInfo *)info), &f.paletteIn, &f.paletteCount);
    for (int i = 0; i < 256; i++)
        f.palette[i] = 0;
    for (int i = 0; i < f.paletteCount; i++) {
        PngColor *c = &f.paletteIn[i];
        f.palette[i] = 0xff000000 | (c->red << 16) | (c->green << 8) | c->blue;
    }
    if (FUN_002d7e90(((PngRead *)png), ((PngInfo *)info), 0x10)) {
        FUN_002d8630(((PngRead *)png), ((PngInfo *)info), &f.trans, &f.transCount, 0);
        for (int i = 0; i < f.transCount; i++)
            f.palette[i] = (f.trans[i] << 24) | (f.palette[i] & 0xffffff);
    }
    int width = f.width;
    int height = f.height;
    ((TextureSink *)sink)->vfunc_0(width, height, 4, 0, f.palette);
    unsigned char *row = (unsigned char *)FUN_00266e00(1, FUN_002d7eb0(((PngRead *)png), ((PngInfo *)info)));
    unsigned char *line = (unsigned char *)FUN_00266e00(1, width);
    if (height > 0) {
        int half = width / 2;
        for (int y = height; y != 0; y--) {
            FUN_002d7440(((PngRead *)png), row, 0);
            for (int x = 0; x < half; x++) {
                line[x * 2] = row[x] >> 4;
                line[x * 2 + 1] = row[x] & 0xf;
            }
            ((TextureSink *)sink)->vfunc_2(line);
        }
    }
    FUN_00267090(row);
    FUN_00267090(line);
    ((TextureSink *)sink)->vfunc_10();
}


// 0x002ad9d0 FUN_002ad9d0 (305 B): equivalent/0x002ad9d0.cpp
// sym: _FUN_002ad9d0
// STATUS: equivalent (tools/equiv.py level 3: 20 inputs, branch coverage 14/14)
// FUN_002ad9d0 @ 0x002ad9d0
// FUN_002ad9d0 @ 0x002ad9d0
// equiv-conv: FUN_002ad9d0 esi eax ebx
extern "C" void FUN_002ad9d0(void *png, void *info, void *sink)
{
    Frame_2ad9d0 f;
    int i;

    f.width = FUN_002d7ed0(((png_struct *)png), ((png_info *)info));
    unsigned int rows = FUN_002d7ef0(((png_struct *)png), ((png_info *)info));
    f.height = rows;

    f.numPalette = 0;
    FUN_002d8550(((png_struct *)png), ((png_info *)info), &f.plte, &f.numPalette);
    for (i = 0; i < f.numPalette; i++) {
        f.palette[i] = ((0xffffff00u | f.plte[i * 3]) << 8 | f.plte[i * 3 + 1]) << 8 | f.plte[i * 3 + 2];
    }

    if (FUN_002d7e90(((png_struct *)png), ((png_info *)info), 0x10) != 0) {
        FUN_002d8630(((png_struct *)png), ((png_info *)info), &f.trans, &f.numTrans, 0);
        for (i = 0; i < f.numTrans; i++)
            f.palette[i] = ((unsigned int)f.trans[i] << 24) | (f.palette[i] & 0xffffff);
    }

    ((ImageSink_2ad9d0 *)sink)->begin(f.width, rows, 8, 0, f.palette);

    void *row = FUN_00266e00(1, FUN_002d7eb0(((png_struct *)png), ((png_info *)info)));
    int remaining = rows;
    if (remaining > 0) {
        do {
            FUN_002d7440(((png_struct *)png), row, 0);
            ((ImageSink_2ad9d0 *)sink)->writeRow(row);
            remaining--;
        } while (remaining != 0);
    }
    FUN_00267090(row);
    ((ImageSink_2ad9d0 *)sink)->finish();
}

} // namespace fn_f4f469f6

// 0x002adb10 FUN_002adb10 (144 B): equivalent/0x002adb10.cpp [wrapped: conflict: FUN_00266f00]
// sym: ?FUN_002adb10@fn_002adb10@@YAHHPAXPAUOutput_2adb10@1@@Z
namespace fn_002adb10 {
// STATUS: equivalent (tools/equiv.py level 3: 151 inputs, branch coverage 4/4)
// FUN_002adb10 @ 0x002adb10
struct Output_2adb10 {
 virtual void init(int a, int count, int format, int zero1, int zero2);
 virtual void append(void* data);
 virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual int finish();
};
extern unsigned char __cdecl FUN_002d7f30(void*, int);
extern int __cdecl FUN_002d7ed0(void*, int);
extern int __cdecl FUN_002d7ef0(void*, int);
extern int __cdecl FUN_002d7eb0(void*, int);
extern void* __cdecl FUN_00266e00(int, int);
extern void __cdecl FUN_002d7440(void*, void*, int);
extern void __cdecl FUN_00266f00(int, void*);
// equiv-conv: FUN_002adb10 eax esi edi
int FUN_002adb10(hulk_intptr index, void* source, Output_2adb10* output) {
 unsigned char type = FUN_002d7f30(source,index);
 int format = type == 6 ? 32 : 24;
 int a = FUN_002d7ed0(source,index);
 int count = FUN_002d7ef0(source,index);
 output->init(a,count,format,0,0);
 int size = FUN_002d7eb0(source,index);
 void* buffer = FUN_00266e00(1,size);
 for(int i=count; i>0; --i) {
  FUN_002d7440(source,buffer,0);
  output->append(buffer);
 }
 FUN_00266f00(1,buffer);
 volatile int result = output->finish();
 return result;
}
} // namespace fn_002adb10


// 0x002adba0 pure3d::PNGHandler::vfunc_9 (497 B): equivalent/0x002adba0.cpp
// sym: ?vfunc_9@PNGHandler@pure3d@@UAEXHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20085 inputs, branch coverage 32/32)
// pure3d::PNGHandler::vfunc_9 @ 0x002adba0
// pure3d::PNGHandler::vfunc_9 @ 0x002adba0
// equiv-conv: FUN_002ad820 eax stack stack
// equiv-conv: FUN_002ad9d0 esi eax ebx
// equiv-conv: FUN_002adb10 eax esi edi
void pure3d::PNGHandler::vfunc_9(hulk_intptr __p0, hulk_intptr __p1) { void * io = (void *)__p0; ImageSink_2adba0 * sink = (ImageSink_2adba0 *)__p1;

    struct Frame {
        png_struct *png;
        png_info *info;
    } f;

    f.png = FUN_002d6f10("1.0.3", 0, FUN_002ad7c0, FUN_002ad7d0, 0, FUN_002ad7e0, FUN_002ad7f0);
    if (f.png == 0)
        return;
    f.info = FUN_002d6ea0(f.png);
    if (f.info == 0) {
        FUN_002d7df0(&f.png, 0, 0);
        return;
    }
    FUN_002dd6f0(f.png, io, FUN_002ad790);
    FUN_002d7150(f.png, f.info);
    unsigned int bitDepth = FUN_002d7f10(f.png, f.info);
    unsigned int colorType = FUN_002d7f30(f.png, f.info);
    if (colorType != 3 && colorType != 2 && colorType != 6) {
        FUN_002d7df0(&f.png, 0, 0);
        return;
    }
    if (!FUN_002d7f70(f.png, f.info)) {
        if (FUN_002d7e90(f.png, f.info, 8))
            FUN_002d8830(f.png);
        if (bitDepth == 16)
            FUN_002d8820(f.png);
        FUN_002dd1a0(f.png);
        if (((PngInfoView *)f.info)->pixelDepth != 0x20)
            FUN_002dd250(f.png, 0xff, 1);
        if (colorType == 3 && bitDepth != 4 && bitDepth != 8)
            FUN_002d9060(f.png);
        FUN_002d73f0(f.png, f.info);
        if (bitDepth == 4 && colorType == 3)
            FUN_002ad820((png_info *)(f.info), (png_struct *)(f.png), (ImageSink_2adba0 *)sink);
        else if (bitDepth == 8 && colorType == 3)
            FUN_002ad9d0((png_struct *)(f.png), (png_info *)(f.info), (ImageSink_2adba0 *)sink);
        else
            FUN_002adb10(f.info, f.png, sink);
    }
    FUN_002d6ed0(f.png, &f.info);
    FUN_002d7df0(&f.png, 0, 0);
}

