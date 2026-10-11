// STATUS: equivalent (tools/equiv.py level 3: 23 inputs, branch coverage 16/16)
// FUN_002af510 @ 0x002af510
void *__cdecl FUN_00266e00(unsigned int count, unsigned int size);
void __cdecl FUN_00267090(void *p);

struct Reader {
    void FUN_002647e0(void *dst, int count, int size, int flag);
    int FUN_00263fc0();
    void FUN_00264510(int bytes);
};

class Writer {
public:
    virtual void vfunc_0(int width, int height, int bitsPerPixel, int flag, unsigned int *palette);
    virtual void vfunc_1();
    virtual void vfunc_2(unsigned char *row);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
};

struct ImageHeader {
    char pad00[8];
    int dataEnd;
    char pad0c[4];
    int width;
    int height;
    char pad18[0x2c - 0x18];
    int paletteCount;
};

/* Reads a 4-bit paletted image from the stream and feeds it to the writer one row at a time. */
void __cdecl FUN_002af510(Reader *reader, ImageHeader *img, Writer *writer)
{
    unsigned int palette[16];
    int i;
    int n = img->paletteCount;

    for (i = 0; i < 16; i++)
        palette[i] = 0;
    if (n == 0)
        n = 16;

    reader->FUN_002647e0(palette, n, 4, 1);
    for (i = 0; i < n; i++) {
        palette[i] |= 0xff000000;
        palette[i] = palette[i];
    }

    writer->vfunc_0(img->width, img->height, 4, 1, palette);
    reader->FUN_00264510(img->dataEnd - reader->FUN_00263fc0());

    int width = img->width;
    int packed = width / 2;
    int pad = 0;
    if ((packed & 3) != 0)
        pad = 4 - (packed & 3);

    unsigned char *src = (unsigned char *)FUN_00266e00(1, packed);
    unsigned char *row = (unsigned char *)FUN_00266e00(1, width);

    for (int y = 0; y < img->height; y++) {
        reader->FUN_002647e0(src, packed, 1, 1);
        for (i = 0; i < packed; i++) {
            row[i * 2] = src[i] >> 4;
            row[i * 2 + 1] = src[i] & 0xf;
        }
        writer->vfunc_2(row);
        reader->FUN_00264510(pad);
    }
    FUN_00267090(src);
    FUN_00267090(row);
    writer->vfunc_10();
}
