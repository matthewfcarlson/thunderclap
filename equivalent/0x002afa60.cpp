// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 20/20)
// pure3d::BMPHandler::vfunc_9 @ 0x002afa60
// BMP loader: checks the "BM" magic and the header, then hands 4, 8 and 24 bit images to their readers.
struct Reader {
    char pad00[0xc];
    char open;
    char pad0d;
    char binary;
    char pad0f[0x11];
    char FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Header {
    unsigned magic;
    unsigned char b4, b5, b6, b7;
    unsigned w8, wc, w10, w14;
    unsigned short s18, bitCount;   // 0x1a
    unsigned compression;           // 0x1c
    unsigned w20, w24, w28, w2c, w30;
};

struct Output;

// equiv-conv: FUN_002af8c0 esi edi
void FUN_002af8c0(Header *h, Reader *r);
void __cdecl FUN_002af510(Reader *reader, Header *img, Output *out);
// equiv-conv: FUN_002af670 esi ebx stack
int __cdecl FUN_002af670(Header *info, Reader *stream, Output *out);
// equiv-conv: FUN_002af790 edi stack stack
int __cdecl FUN_002af790(Reader *reader, Header *header, Output *out);

// The stream pointer's argument slot is reused for the two magic bytes.
union StreamArg {
    Reader *reader;
    unsigned short magic;
};

namespace pure3d {
class BMPHandler {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9(StreamArg stream, Output *out);
    virtual void vfunc_10();
};
}

void pure3d::BMPHandler::vfunc_9(StreamArg stream, Output *out)
{
    Header h;
    Reader *reader = stream.reader;
    reader->FUN_002647e0(&stream.magic, 2, 1, 1);
    if ((stream.magic & 0xff) == 'B' && (stream.magic >> 8) == 'M') {
        FUN_002af8c0(&h, reader);
        unsigned short bits = h.bitCount;
        if ((bits == 1 || bits == 4 || bits == 8 || bits == 0x18) && h.compression == 0) {
            if (bits == 4)
                FUN_002af510(reader, &h, out);
            else if (bits == 8)
                FUN_002af670(&h, reader, out);
            else if (bits == 0x18)
                FUN_002af790(reader, &h, out);
        }
    }
}
