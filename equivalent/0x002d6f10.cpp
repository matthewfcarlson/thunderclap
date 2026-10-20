// STATUS: equivalent (tools/equiv.py level 3: 3107 inputs, branch coverage 21/21)
// FUN_002d6f10 @ 0x002d6f10
#include "decls/data/engine/pure3d.h"

struct ZStream_2d6f10 {
    void *next_in;
    unsigned int avail_in;
    unsigned int total_in;
    void *next_out;
    unsigned int avail_out;
    unsigned int total_out;
    char *msg;
    void *state;
    void (*zalloc)();
    void (*zfree)();
    void *opaque;
    char pad2c[0x38 - 0x2c];
};

struct PngStruct_2d6f10 {
    char jmpbuf[0x6c];
    ZStream_2d6f10 zstream;
    void *zbuf;
    unsigned int zbufSize;
};


// the CRT setjmp helper (_setjmp3), named by address
int FUN_00347250(void *jmpbuf, int count);
PngStruct_2d6f10 *FUN_002e6a50(int type, void *mallocFn);
void FUN_002e6c40(PngStruct_2d6f10 *png, void *ptr);
void FUN_002e6bf0(PngStruct_2d6f10 *png);
void FUN_002e6ba0(PngStruct_2d6f10 *png, void *memPtr, void *mallocFn, void *freeFn);
void FUN_002e6970(PngStruct_2d6f10 *png, void *errorPtr, void *errorFn, void *warnFn);
void FUN_002e69a0(PngStruct_2d6f10 *png, const char *message);
void *FUN_002e6c00(PngStruct_2d6f10 *png, unsigned int size);
int FUN_002e6f50(ZStream_2d6f10 *strm, const char *version, int streamSize);
void FUN_002dd6f0(PngStruct_2d6f10 *png, int a, int b);
void FUN_002d6c20();
void FUN_002d6c80();

PngStruct_2d6f10 *FUN_002d6f10(const char *userVersion, void *errorPtr, void *errorFn, void *warnFn,
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
        FUN_002e69a0(png, "Incompatible libpng version in application and library");

    png->zbufSize = 0x2000;
    png->zbuf = FUN_002e6c00(png, 0x2000);
    png->zstream.zalloc = &FUN_002d6c20;
    png->zstream.zfree = &FUN_002d6c80;
    png->zstream.opaque = png;

    switch (FUN_002e6f50(&png->zstream, "1.1.3", 0x38)) {
    case 0:
        break;
    case -4:
    case -2:
        FUN_002e69a0(png, "zlib memory error");
        break;
    case -6:
        FUN_002e69a0(png, "zlib version error");
        break;
    default:
        FUN_002e69a0(png, "Unknown zlib error");
        break;
    }

    png->zstream.next_out = png->zbuf;
    png->zstream.avail_out = png->zbufSize;
    FUN_002dd6f0(png, 0, 0);
    return png;
}
