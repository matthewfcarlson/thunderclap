struct png_struct;
struct png_info;

unsigned int FUN_002d7ed0(png_struct *png, png_info *info);
unsigned int FUN_002d7ef0(png_struct *png, png_info *info);
unsigned int FUN_002d8550(png_struct *png, png_info *info, unsigned char **palette, int *numPalette);
unsigned int FUN_002d7e90(png_struct *png, png_info *info, unsigned int mask);
unsigned int FUN_002d8630(png_struct *png, png_info *info, unsigned char **trans, int *numTrans, void *transValues);
unsigned int FUN_002d7eb0(png_struct *png, png_info *info);
void *FUN_00266e00(int tag, unsigned int size);
void FUN_002d7440(png_struct *png, void *row);
void FUN_00267090(void *p);

class ImageSink {
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

struct Frame {
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

// equiv-conv: FUN_002ad9d0 esi eax ebx
void FUN_002ad9d0(png_struct *png, png_info *info, ImageSink *sink)
{
    Frame f;
    int i;

    f.width = FUN_002d7ed0(png, info);
    unsigned int rows = FUN_002d7ef0(png, info);
    f.height = rows;

    f.numPalette = 0;
    FUN_002d8550(png, info, &f.plte, &f.numPalette);
    for (i = 0; i < f.numPalette; i++) {
        f.palette[i] = ((0xffffff00u | f.plte[i * 3]) << 8 | f.plte[i * 3 + 1]) << 8 | f.plte[i * 3 + 2];
    }

    if (FUN_002d7e90(png, info, 0x10) != 0) {
        FUN_002d8630(png, info, &f.trans, &f.numTrans, 0);
        for (i = 0; i < f.numTrans; i++)
            f.palette[i] = ((unsigned int)f.trans[i] << 24) | (f.palette[i] & 0xffffff);
    }

    sink->begin(f.width, rows, 8, 0, f.palette);

    void *row = FUN_00266e00(1, FUN_002d7eb0(png, info));
    int remaining = rows;
    if (remaining > 0) {
        do {
            FUN_002d7440(png, row);
            sink->writeRow(row);
            remaining--;
        } while (remaining != 0);
    }
    FUN_00267090(row);
    sink->finish();
}
