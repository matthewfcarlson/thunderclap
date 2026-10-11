// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 12/12)
// FUN_002dd890 @ 0x002dd890
struct Reader {
    void FUN_002647e0(void *dst, int size, int count, int flag);
};

struct Device {
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

struct ImageInfo {
    char pad0[6];
    unsigned short numColors;
    unsigned char bpp;
    char pad9[5];
    unsigned short width;
    unsigned short height;
    char pad12;
    unsigned char flags;
};

void *FUN_00266e00(int a, int b);
void FUN_00267090(void *p);

// equiv-conv: FUN_002dd890 esi ebx stack
void FUN_002dd890(ImageInfo *info, Reader *r, Device *dev)
{
    struct Frame {
        char pad0[9];
        unsigned char c1, c0, c2;
        unsigned int palette[256];
    } f;
    unsigned int *palette = f.palette;
    int n = info->numColors;
    int i;
    if (n < 256) {
        for (i = n; i < 256; i++)
            palette[i] = 0;
    }
    if (info->bpp == 0x18) {
        for (i = 0; i < n; i++) {
            r->FUN_002647e0(&f.c0, 1, 1, 1);
            r->FUN_002647e0(&f.c1, 1, 1, 1);
            r->FUN_002647e0(&f.c2, 1, 1, 1);
            palette[i] = (((0xffffff00u | f.c2) << 8 | f.c1) << 8) | f.c0;
        }
    } else {
        r->FUN_002647e0(palette, n * 4, 1, 1);
    }
    dev->FUN_slot0(info->width, info->height, 8, !((info->flags >> 5) & 1), palette);
    void *row = FUN_00266e00(1, info->width);
    for (i = 0; i < info->height; i++) {
        r->FUN_002647e0(row, info->width, 1, 1);
        dev->FUN_slot2(row);
    }
    FUN_00267090(row);
    dev->FUN_slot10();
}
