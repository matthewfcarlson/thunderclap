// STATUS: equivalent (tools/equiv.py level 3: 20085 inputs, branch coverage 32/32)
// pure3d::PNGHandler::vfunc_9 @ 0x002adba0
// pure3d::PNGHandler::vfunc_9 @ 0x002adba0
#include "gen/pure3d.h"

struct png_struct;
struct png_info;

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
unsigned int __cdecl FUN_002d7e90(png_struct *png, png_info *info, unsigned int mask);
void __cdecl FUN_002d8830(png_struct *png);
void __cdecl FUN_002d8820(png_struct *png);
void __cdecl FUN_002dd1a0(png_struct *png);
void __cdecl FUN_002dd250(png_struct *png, int filler, int where);
void __cdecl FUN_002d9060(png_struct *png);
void __cdecl FUN_002d73f0(png_struct *png, png_info *info);
void __cdecl FUN_002d6ed0(png_struct *png, png_info **info);

// equiv-conv: FUN_002ad820 eax stack stack
void FUN_002ad820(png_info *info, png_struct *png, ImageSink_2adba0 *sink);
// equiv-conv: FUN_002ad9d0 esi eax ebx
void FUN_002ad9d0(png_struct *png, png_info *info, ImageSink_2adba0 *sink);
// equiv-conv: FUN_002adb10 eax esi edi
void FUN_002adb10(png_info *info, png_struct *png, ImageSink_2adba0 *sink);

void pure3d::PNGHandler::vfunc_9(int __p0, int __p1) { void * io = (void *)__p0; ImageSink_2adba0 * sink = (ImageSink_2adba0 *)__p1;

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
            FUN_002ad820(f.info, f.png, sink);
        else if (bitDepth == 8 && colorType == 3)
            FUN_002ad9d0(f.png, f.info, sink);
        else
            FUN_002adb10(f.info, f.png, sink);
    }
    FUN_002d6ed0(f.png, &f.info);
    FUN_002d7df0(&f.png, 0, 0);
}
