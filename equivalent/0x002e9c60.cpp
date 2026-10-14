// STATUS: equivalent (tools/equiv.py level 3: 1068 inputs, branch coverage 36/38, incomplete)
// FUN_002e9c60 @ 0x002e9c60
struct ZStream_2e9c60 {
    unsigned char *next_in;
    unsigned avail_in;
    unsigned total_in;
    unsigned char *next_out;
    unsigned avail_out;
    unsigned total_out;
    const char *msg;
};

struct PngStruct_2e9c60 {
    char pad0[0x60];
    unsigned mode;
    char pad1[8];
    ZStream_2e9c60 zstream;
    char pad2[0xa4 - 0x6c - sizeof(ZStream_2e9c60)];
    unsigned char *zbuf;
    unsigned zbuf_size;
};

struct PngText {
    int compression;
    char *key;
    char *text;
    unsigned text_length;
};

extern "C" void *memcpy(void *dst, const void *src, unsigned int n);
extern "C" int __cdecl _sprintf(char *buf, const char *fmt, ...);

void __cdecl FUN_002e69a0(PngStruct_2e9c60 *png, const char *msg);
void __cdecl FUN_002e69d0(PngStruct_2e9c60 *png, const char *msg);
int __cdecl FUN_002e81e0(PngStruct_2e9c60 *png, unsigned skip);
void *__cdecl FUN_002e6c00(PngStruct_2e9c60 *png, unsigned size);
void __cdecl FUN_002e6c40(PngStruct_2e9c60 *png, void *ptr);
void __cdecl FUN_002e7580(PngStruct_2e9c60 *png, void *buf, unsigned length);
int __cdecl FUN_002e6f70(ZStream_2e9c60 *z, int flush);
void __cdecl FUN_002e6db0(ZStream_2e9c60 *z);
void __cdecl FUN_002eb5e0(PngStruct_2e9c60 *png, void *info, PngText *text, int n);

// libpng png_handle_zTXt (with png_decompress_chunk inlined)
void png_handle_zTXt(PngStruct_2e9c60 *png, void *info, unsigned length)
{
    char *chunkdata;
    char *text;
    int comp_type = -1;
    unsigned prefix;
    unsigned text_size;
    char umsg[52];

    if (!(png->mode & 1))
        FUN_002e69a0(png, "Missing IHDR before zTXt");
    if (png->mode & 4)
        png->mode |= 8;

    chunkdata = (char *)FUN_002e6c00(png, length + 1);
    FUN_002e7580(png, chunkdata, length);
    if (FUN_002e81e0(png, 0)) {
        FUN_002e6c40(png, chunkdata);
        return;
    }
    chunkdata[length] = 0;
    text = chunkdata;
    while (*text)
        text++;

    if (text == chunkdata + length) {
        FUN_002e69d0(png, "Zero length zTXt chunk");
    } else {
        comp_type = (signed char)*++text;
        text++;
        if (comp_type != 0) {
            unsigned n;
            _sprintf(umsg, "Unknown zTXt compression type %d", comp_type);
            FUN_002e69d0(png, umsg);
            text--;
            n = (unsigned)(chunkdata - text) + length - 1;
            if (n >= 0x1a)
                n = 0x1a;
            memcpy(text, "Error decoding zTXt chunk", n + 1);
        } else {
            unsigned char *zbuf0 = png->zbuf;
            unsigned zbuf_size0 = png->zbuf_size;
            prefix = (unsigned)(text - chunkdata);
            png->zstream.next_in = (unsigned char *)text;
            png->zstream.avail_in = (unsigned)(chunkdata - text) + length;
            png->zstream.next_out = zbuf0;
            png->zstream.avail_out = zbuf_size0;
            text = 0;
            text_size = 0;
            while (png->zstream.avail_in) {
                int ret = FUN_002e6f70(&png->zstream, 1);
                if (ret != 0 && ret != 1) {
                    const char *m = png->zstream.msg;
                    FUN_002e69d0(png, m ? m : "Error decoding zTXt chunk");
                    FUN_002e6db0(&png->zstream);
                    png->zstream.avail_in = 0;
                    if (text == 0) {
                        text_size = prefix + 0x1b;
                        text = (char *)FUN_002e6c00(png, text_size);
                        memcpy(text, chunkdata, prefix);
                    }
                    text[text_size - 1] = 0;
                    {
                        unsigned n = (unsigned)(chunkdata - text) + length - 1;
                        if (n >= 0x1a)
                            n = 0x1a;
                        memcpy(text + prefix, "Error decoding zTXt chunk", n + 1);
                    }
                    break;
                }
                {
                    unsigned avail_out = png->zstream.avail_out;
                    if (avail_out == 0 || ret == 1) {
                        unsigned produced = png->zbuf_size - avail_out;
                        if (text == 0) {
                            char *nt = (char *)FUN_002e6c00(png, produced + prefix + 1);
                            unsigned n = png->zbuf_size - png->zstream.avail_out;
                            text = nt;
                            memcpy(text + prefix, png->zbuf, n);
                            memcpy(text, chunkdata, prefix);
                            text_size = png->zbuf_size - png->zstream.avail_out + prefix;
                        } else {
                            char *old = text;
                            unsigned oldsize = text_size;
                            unsigned n;
                            text = (char *)FUN_002e6c00(png, produced + oldsize + 1);
                            memcpy(text, old, oldsize);
                            FUN_002e6c40(png, old);
                            n = png->zbuf_size - png->zstream.avail_out;
                            memcpy(text + oldsize, png->zbuf, n);
                            text_size = oldsize + (png->zbuf_size - png->zstream.avail_out);
                        }
                        text[text_size] = 0;
                        if (ret == 1)
                            break;
                        png->zstream.next_out = png->zbuf;
                        png->zstream.avail_out = png->zbuf_size;
                    }
                }
            }
            FUN_002e6db0(&png->zstream);
            png->zstream.avail_in = 0;
            FUN_002e6c40(png, chunkdata);
            chunkdata = text;
            text = text + prefix;
        }
    }

    {
        PngText *tp = (PngText *)FUN_002e6c00(png, 0x10);
        tp->compression = comp_type;
        tp->key = chunkdata;
        tp->text = text;
        FUN_002eb5e0(png, info, tp, 1);
        FUN_002e6c40(png, tp);
    }
}
