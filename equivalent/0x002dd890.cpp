// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 12/12)
// FUN_002dd890 @ 0x002dd890
#include "gen/owners.h"
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
