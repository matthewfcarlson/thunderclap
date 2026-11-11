// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002dd760..0x002ddbe0 (kind game, layer engine, confidence medium), dominant class pure3d::TargaHandler
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f7629933 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f7629933 {} using namespace fn_f7629933;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f7629933 {
struct Stream {
};
struct Header_2dd760 {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char pad3;
    unsigned short w4;
    unsigned short w6;
    unsigned char b8;
    unsigned char pad9;
    unsigned short wA;
    unsigned short wC;
    unsigned short wE;
    unsigned short w10;
    unsigned char b12;
    unsigned char b13;
};
struct Reader {
};
struct Device_2dd890 {
    virtual void FUN_slot0(int w, int h, int bpp, int flag, unsigned int *palette);
    virtual void FUN_slot1();
    virtual void FUN_slot2(void *p);
    virtual void FUN_slot3();
    virtual void FUN_slot4();
    virtual void FUN_slot5();
    virtual void FUN_slot6();
    virtual void FUN_slot7();
    virtual void FUN_slot8();
    virtual void FUN_slot9();
    virtual void FUN_slot10();
};
struct ImageInfo_2dd890 {
    char pad0[6];
    unsigned short numColors;
    unsigned char bpp;
    char pad9[5];
    unsigned short width;
    unsigned short height;
    char pad12;
    unsigned char flags;
};
extern "C" void *FUN_00266e00(int a, int b);
extern "C" void FUN_00267090(void *p);
struct Device {
    virtual void FUN_slot0(int w, int h, int bpp, int flag, int zero);
    virtual void FUN_slot1(void *row);
    virtual void FUN_slot2();
    virtual void FUN_slot3();
    virtual void FUN_slot4();
    virtual void FUN_slot5();
    virtual void FUN_slot6();
    virtual void FUN_slot7();
    virtual void FUN_slot8();
    virtual void FUN_slot9();
    virtual void FUN_slot10();
};
struct ImageInfo {
    char pad0[0xe];
    unsigned short width;
    unsigned short height;
    unsigned char bpp;
    unsigned char flags;
};
union Slot {
    ImageInfo *info;
    unsigned char byte;
    int count;
};
struct Stream_2ddb40 {
};
struct TgaHeader {
    unsigned char idLength;
    unsigned char colorMapType;
    unsigned char imageType;
    char pad03[0xb];
    unsigned short width;
    unsigned short height;
    unsigned char bpp;
    unsigned char descriptor;
};
extern "C" void __cdecl FUN_002dd760(void *, void *);
extern "C" void __cdecl FUN_002dd890(void *, void *, void *);
extern "C" void __cdecl FUN_002dd9e0(void *, void *, void *);


// 0x002dd760 FUN_002dd760 (302 B): equivalent/0x002dd760.cpp
// sym: _FUN_002dd760 @54ca8787c8a1 @wded08d7fe2ae
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_002dd760 @ 0x002dd760
// equiv-conv: FUN_002dd760 esi edi
extern "C" void FUN_002dd760(void *out, void *s)
{
    unsigned int tmp;

    ((owners::X_2647e0 *)(((Stream *)s)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 1, (hulk_intptr)1);
    ((Header_2dd760 *)out)->b0 = *(unsigned char *)&tmp;
    ((owners::X_2647e0 *)(((Stream *)s)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 1, (hulk_intptr)1);
    ((Header_2dd760 *)out)->b1 = *(unsigned char *)&tmp;
    ((owners::X_2647e0 *)(((Stream *)s)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 1, (hulk_intptr)1);
    ((Header_2dd760 *)out)->b2 = *(unsigned char *)&tmp;
    ((owners::X_2647e0 *)(((Stream *)s)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 2, (hulk_intptr)1);
    ((Header_2dd760 *)out)->w4 = *(unsigned short *)&tmp;
    ((owners::X_2647e0 *)(((Stream *)s)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 2, (hulk_intptr)1);
    ((Header_2dd760 *)out)->w6 = *(unsigned short *)&tmp;
    ((owners::X_2647e0 *)(((Stream *)s)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 1, (hulk_intptr)1);
    ((Header_2dd760 *)out)->b8 = *(unsigned char *)&tmp;
    ((owners::X_2647e0 *)(((Stream *)s)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 2, (hulk_intptr)1);
    ((Header_2dd760 *)out)->wA = *(unsigned short *)&tmp;
    ((owners::X_2647e0 *)(((Stream *)s)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 2, (hulk_intptr)1);
    ((Header_2dd760 *)out)->wC = *(unsigned short *)&tmp;
    ((owners::X_2647e0 *)(((Stream *)s)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 2, (hulk_intptr)1);
    ((Header_2dd760 *)out)->wE = *(unsigned short *)&tmp;
    ((owners::X_2647e0 *)(((Stream *)s)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 2, (hulk_intptr)1);
    ((Header_2dd760 *)out)->w10 = *(unsigned short *)&tmp;
    ((owners::X_2647e0 *)(((Stream *)s)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 1, (hulk_intptr)1);
    ((Header_2dd760 *)out)->b12 = *(unsigned char *)&tmp;
    ((owners::X_2647e0 *)(((Stream *)s)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 1, (hulk_intptr)1);
    ((Header_2dd760 *)out)->b13 = *(unsigned char *)&tmp;
}


// 0x002dd890 FUN_002dd890 (325 B): equivalent/0x002dd890.cpp
// sym: _FUN_002dd890 @13ea46651b23 @wf53db958a4b6
// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 12/12)
// FUN_002dd890 @ 0x002dd890
// equiv-conv: FUN_002dd890 esi ebx stack
extern "C" void FUN_002dd890(void *info, void *r, void *dev)
{
    struct Frame {
        char pad0[9];
        unsigned char c1, c0, c2;
        unsigned int palette[256];
    } f;
    unsigned int *palette = f.palette;
    int n = ((ImageInfo_2dd890 *)info)->numColors;
    int i;
    if (n < 256) {
        for (i = n; i < 256; i++)
            palette[i] = 0;
    }
    if (((ImageInfo_2dd890 *)info)->bpp == 0x18) {
        for (i = 0; i < n; i++) {
            ((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&f.c0), (hulk_intptr)1, 1, (hulk_intptr)1);
            ((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&f.c1), (hulk_intptr)1, 1, (hulk_intptr)1);
            ((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&f.c2), (hulk_intptr)1, 1, (hulk_intptr)1);
            palette[i] = (((0xffffff00u | f.c2) << 8 | f.c1) << 8) | f.c0;
        }
    } else {
        ((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)palette, (hulk_intptr)(n * 4), 1, (hulk_intptr)1);
    }
    ((Device_2dd890 *)dev)->FUN_slot0(((ImageInfo_2dd890 *)info)->width, ((ImageInfo_2dd890 *)info)->height, 8, !((((ImageInfo_2dd890 *)info)->flags >> 5) & 1), palette);
    void *row = FUN_00266e00(1, ((ImageInfo_2dd890 *)info)->width);
    for (i = 0; i < ((ImageInfo_2dd890 *)info)->height; i++) {
        ((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)row, (hulk_intptr)(((ImageInfo_2dd890 *)info)->width), 1, (hulk_intptr)1);
        ((Device_2dd890 *)dev)->FUN_slot2(row);
    }
    FUN_00267090(row);
    ((Device_2dd890 *)dev)->FUN_slot10();
}


// 0x002dd9e0 FUN_002dd9e0 (327 B): equivalent/0x002dd9e0.cpp
// sym: _FUN_002dd9e0 @3bd51b7ba4a6 @w3f433f0e9311
// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 12/12)
// FUN_002dd9e0 @ 0x002dd9e0
// equiv-conv: FUN_002dd9e0 ebx edi stack
// The original reuses its stack argument slot as scratch: first as the row counter of
// the 32-bit path, then as the buffer for the first byte of each 24-bit pixel.
extern "C" void FUN_002dd9e0(void *dev, void *rd, void * infoArg_)
{
    ImageInfo * infoArg = (ImageInfo *)infoArg_;
    ImageInfo *info = infoArg;
    Slot &arg = *(Slot *)&infoArg;
    struct Frame {
        char pad8[2];
        unsigned char c1, c2;
        unsigned char *row;
        int x;
        int y;
    } fr;

    ((Device *)dev)->FUN_slot0(info->width, info->height, info->bpp, !((info->flags >> 5) & 1), 0);
    fr.row = (unsigned char *)FUN_00266e00(1, info->width * 4);
    if (info->bpp == 0x20) {
        for (arg.count = 0; arg.count < info->height; arg.count++) {
            ((owners::X_2647e0 *)(((Reader *)rd)))->FUN_002647e0((hulk_intptr)(fr.row), (hulk_intptr)(info->width), 4, (hulk_intptr)1);
            ((Device *)dev)->FUN_slot1(fr.row);
        }
    } else {
        for (fr.y = 0; fr.y < info->height; fr.y++) {
            unsigned char *p = fr.row;
            for (fr.x = info->width; fr.x != 0; fr.x--) {
                ((owners::X_2647e0 *)(((Reader *)rd)))->FUN_002647e0((hulk_intptr)(&arg.byte), (hulk_intptr)1, 1, (hulk_intptr)1);
                p[0] = arg.byte;
                ((owners::X_2647e0 *)(((Reader *)rd)))->FUN_002647e0((hulk_intptr)(&fr.c1), (hulk_intptr)1, 1, (hulk_intptr)1);
                p[1] = fr.c1;
                ((owners::X_2647e0 *)(((Reader *)rd)))->FUN_002647e0((hulk_intptr)(&fr.c2), (hulk_intptr)1, 1, (hulk_intptr)1);
                p[2] = fr.c2;
                p[3] = 0xff;
                p += 4;
            }
            ((Device *)dev)->FUN_slot1(fr.row);
        }
    }
    FUN_00267090(fr.row);
    ((Device *)dev)->FUN_slot10();
}

} // namespace fn_f7629933

// 0x002ddb30 pure3d::TargaHandler::vfunc_8 (15 B): matches/0x002ddb30.cpp
// sym: ?vfunc_8@TargaHandler@pure3d@@UAE_NH@Z
bool pure3d::TargaHandler::vfunc_8(int x) {
    return x == 2;
}


// 0x002ddb40 pure3d::TargaHandler::vfunc_9 (157 B): equivalent/0x002ddb40.cpp
// sym: ?vfunc_9@TargaHandler@pure3d@@UAEXHH@Z @318c26657199 @wb4b88570f7e2
// STATUS: equivalent (tools/equiv.py level 3: 19366 inputs, branch coverage 21/22, incomplete)
// pure3d::TargaHandler::vfunc_9 @ 0x002ddb40
// pure3d::TargaHandler::vfunc_9 @ 0x002ddb40
// pure3d::TargaHandler::vfunc_9 @ 0x002ddb40
// pure3d::TargaHandler::vfunc_9: validate a TGA header and dispatch to the colour-mapped or true-colour reader
// equiv-conv: FUN_002dd760 esi edi
// equiv-conv: FUN_002dd890 esi ebx stack
// equiv-conv: FUN_002dd9e0 ebx edi stack
void pure3d::TargaHandler::vfunc_9(hulk_intptr __p0, hulk_intptr __p1) { Stream_2ddb40 * stream = (Stream_2ddb40 *)__p0; void * out = (void *)__p1;

    TgaHeader hdr;
    FUN_002dd760((TgaHeader *)(&hdr), (Stream_2ddb40 *)stream);
    unsigned char type = hdr.imageType;
    if (type != 1 && type != 2)
        return;
    if (hdr.colorMapType != 0 && hdr.colorMapType != 1)
        return;
    if (hdr.bpp != 0x20 && hdr.bpp != 0x18 && hdr.bpp != 8)
        return;
    if (hdr.width > 0x1000 || hdr.height > 0x1000)
        return;
    ((owners::S_264510 *)stream)->FUN_00264510((unsigned)(hdr.idLength));
    if (type == 1)
        FUN_002dd890((TgaHeader *)(&hdr), (Stream_2ddb40 *)stream, out);
    else if (type == 2)
        FUN_002dd9e0(out, (Stream_2ddb40 *)stream, (TgaHeader *)(&hdr));
}

