struct Stream {
    char pad00[0xf];
    unsigned char flag;       // 0x0f
    char FUN_002647e0(void *dst, int count, int size, int flags);
};

class Texture {
public:
    virtual char v0(int width, int height, int levels, int a, int b);
    virtual void v1();
    virtual void v2();
    virtual void v3(void *data, int size);
    virtual void *v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(int format);
    virtual void v10();
};

struct DdsHeader {
    unsigned int size;           // 0x00
    unsigned int flags;          // 0x04
    unsigned int height;         // 0x08
    unsigned int width;          // 0x0c
    unsigned int pitchOrLinear;  // 0x10
    unsigned int depth;          // 0x14
    unsigned int mipCount;       // 0x18
    unsigned int reserved[11];   // 0x1c
    unsigned int pfSize;         // 0x48
    unsigned int pfFlags;        // 0x4c
    unsigned int fourCC;         // 0x50
    unsigned int bitCount;       // 0x54
    unsigned int masks[4];       // 0x58
    unsigned int caps[5];        // 0x68
};

struct DdsFile {
    unsigned int magic;
    DdsHeader header;
};

void *FUN_00266e00(int count, unsigned int size);
void FUN_00267090(void *p);

void FUN_002de030(Stream *s, Texture *tex)
{
    DdsFile f;
    s->FUN_002647e0(&f.magic, 1, 4, 1);
    if (f.magic == 0x44445320)
        s->flag = (s->flag == 0);
    s->FUN_002647e0(&f.header, 0x1f, 4, 1);

    int format;
    switch (f.header.fourCC) {
    case 0x31545844: format = 4; break;   // DXT1
    case 0x32545844: format = 5; break;   // DXT2
    case 0x33545844: format = 6; break;   // DXT3
    case 0x34545844: format = 7; break;   // DXT4
    case 0x35545844: format = 8; break;   // DXT5
    default:
        return;
    }

    tex->v9(format);
    if (!tex->v0(f.header.width, f.header.height, 2, 0, 0))
        return;

    if (f.header.flags & 0x80000) {
        void *dst = tex->v4();
        if (dst == 0)
            return;
        s->FUN_002647e0(dst, f.header.pitchOrLinear, 1, 1);
        tex->v10();
        return;
    }

    unsigned int rowBytes = (f.header.bitCount * f.header.width) >> 3;
    char *buf = (char *)FUN_00266e00(1, f.header.pitchOrLinear * f.header.height);
    if (buf == 0)
        return;
    char *row = buf;
    for (unsigned int y = 0; y < f.header.height; y++) {
        s->FUN_002647e0(row, rowBytes, 1, 1);
        row += f.header.pitchOrLinear;
    }
    tex->v3(buf, f.header.pitchOrLinear * f.header.height);
    FUN_00267090(buf);
    tex->v10();
}
