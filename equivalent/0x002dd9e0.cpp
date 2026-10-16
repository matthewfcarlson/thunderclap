// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 12/12)
// FUN_002dd9e0 @ 0x002dd9e0
struct Reader {
    void FUN_002647e0(void *dst, int a, int b, int c);
};

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

void *FUN_00266e00(int a, int b);
void FUN_00267090(void *p);

// equiv-conv: FUN_002dd9e0 ebx edi stack
// The original reuses its stack argument slot as scratch: first as the row counter of
// the 32-bit path, then as the buffer for the first byte of each 24-bit pixel.
void FUN_002dd9e0(Device *dev, Reader *rd, ImageInfo *infoArg)
{
    ImageInfo *info = infoArg;
    Slot &arg = *(Slot *)&infoArg;
    struct Frame {
        char pad8[2];
        unsigned char c1, c2;
        unsigned char *row;
        int x;
        int y;
    } fr;

    dev->FUN_slot0(info->width, info->height, info->bpp, !((info->flags >> 5) & 1), 0);
    fr.row = (unsigned char *)FUN_00266e00(1, info->width * 4);
    if (info->bpp == 0x20) {
        for (arg.count = 0; arg.count < info->height; arg.count++) {
            rd->FUN_002647e0(fr.row, info->width, 4, 1);
            dev->FUN_slot1(fr.row);
        }
    } else {
        for (fr.y = 0; fr.y < info->height; fr.y++) {
            unsigned char *p = fr.row;
            for (fr.x = info->width; fr.x != 0; fr.x--) {
                rd->FUN_002647e0(&arg.byte, 1, 1, 1);
                p[0] = arg.byte;
                rd->FUN_002647e0(&fr.c1, 1, 1, 1);
                p[1] = fr.c1;
                rd->FUN_002647e0(&fr.c2, 1, 1, 1);
                p[2] = fr.c2;
                p[3] = 0xff;
                p += 4;
            }
            dev->FUN_slot1(fr.row);
        }
    }
    FUN_00267090(fr.row);
    dev->FUN_slot10();
}
