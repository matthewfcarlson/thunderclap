// STATUS: equivalent (tools/equiv.py level 3: 28 inputs, branch coverage 25/28, incomplete)
// FUN_002d7b60 @ 0x002d7b60
// libpng png_read_destroy-style teardown: free every owned buffer, then wipe the struct
// while preserving the jmpbuf header and a few fields.
struct Head {
    int w[16];
};

struct PngInfo {
    Head head;                 // 0x00 .. 0x40 (jmp_buf), preserved
    int keep40;                // 0x40
    int keep44;                // 0x44
    int keep48;                // 0x48
    char pad4c[0x64 - 0x4c];
    unsigned int flags;        // 0x64
    char pad68[4];
    char zstream[0xa4 - 0x6c]; // 0x6c
    void* f0a4;
    char pada8[0xe0 - 0xa8];
    void* f0e0;
    void* f0e4;
    char pad0e8[0x10c - 0xe8];
    void* f10c;
    char pad110[0x150 - 0x110];
    int bitDepthShift;         // 0x150
    char pad154[0x15c - 0x154];
    void* f15c;
    void* f160;
    void* f164;
    void** table168;
    void** table16c;
    void** table170;
    char pad174[0x180 - 0x174];
    void* f180;
    char pad184[0x1a8 - 0x184];
    void* f1a8;
    char pad1ac[0x1e4 - 0x1ac];
    void* f1e4;
    void* f1e8;
    void* f1ec;
    char pad1f0[0x208 - 0x1f0];
    void* f208;
    char pad20c[0x214 - 0x20c];
    int keep214;               // 0x214
    char pad218[4];
};

void FUN_002d6d10(PngInfo* png, int extra);
void FUN_002e6c40(PngInfo* png, void* ptr);
void thunk_FUN_002e6c40(PngInfo* png, void* ptr);
void FUN_002e6e00(void* zstream);

void FUN_002d7b60(PngInfo* png, int a, int b)
{
    if (a)
        FUN_002d6d10(png, a);
    if (b)
        FUN_002d6d10(png, b);

    FUN_002e6c40(png, png->f0a4);
    FUN_002e6c40(png, png->f0e4);
    FUN_002e6c40(png, png->f0e0);
    FUN_002e6c40(png, png->f1e4);
    FUN_002e6c40(png, png->f1e8);
    FUN_002e6c40(png, png->f15c);
    FUN_002e6c40(png, png->f160);
    FUN_002e6c40(png, png->f164);

    if (png->flags & 0x1000)
        thunk_FUN_002e6c40(png, png->f10c);
    if (png->flags & 0x2000)
        FUN_002e6c40(png, png->f180);
    if (png->flags & 0x4000)
        FUN_002e6c40(png, png->f1ec);

    if (png->table168) {
        int n = 1 << (8 - png->bitDepthShift);
        for (int i = 0; i < n; i++)
            FUN_002e6c40(png, png->table168[i]);
        FUN_002e6c40(png, png->table168);
    }
    if (png->table16c) {
        int n = 1 << (8 - png->bitDepthShift);
        for (int i = 0; i < n; i++)
            FUN_002e6c40(png, png->table16c[i]);
        FUN_002e6c40(png, png->table16c);
    }
    if (png->table170) {
        int n = 1 << (8 - png->bitDepthShift);
        for (int i = 0; i < n; i++)
            FUN_002e6c40(png, png->table170[i]);
        FUN_002e6c40(png, png->table170);
    }

    FUN_002e6c40(png, png->f208);
    FUN_002e6e00(png->zstream);
    FUN_002e6c40(png, png->f1a8);

    int k214 = png->keep214;
    int k48 = png->keep48;
    int k40 = png->keep40;
    Head head = png->head;
    int k44 = png->keep44;
    unsigned int* p = (unsigned int*)png;
    for (int i = 0; i < 0x87; i++)
        p[i] = 0;
    png->keep44 = k44;
    png->keep214 = k214;
    png->head = head;
    png->keep48 = k48;
    png->keep40 = k40;
}
