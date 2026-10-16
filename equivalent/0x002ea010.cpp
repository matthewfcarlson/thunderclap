// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 40/42, incomplete)
// FUN_002ea010 @ 0x002ea010
#include "decls/data/engine/physics.h"
#include "decls/data/engine/pure3d.h"

struct ZStream_2ea010 {
    unsigned char *next_in;
    unsigned avail_in;
    unsigned total_in;
    unsigned char *next_out;
    unsigned avail_out;
    unsigned total_out;
    const char *msg;
};

struct PngStruct_2ea010 {
    char pad0[0x60];
    unsigned mode;
    unsigned flags;
    unsigned transformations;
    ZStream_2ea010 zstream;
    char pad1[0xa4 - 0x6c - sizeof(ZStream_2ea010)];
    unsigned char *zbuf;
    unsigned zbuf_size;
    char pad2[0xc0 - 0xac];
    unsigned width;
    unsigned height;
    unsigned num_rows;
    char pad3[0xd0 - 0xcc];
    unsigned rowbytes;
    unsigned irowbytes;
    unsigned iwidth;
    unsigned row_number;
    unsigned char *prev_row;
    char pad4[0x104 - 0xe4];
    unsigned idat_size;
    char pad5[0x114 - 0x108];
    unsigned char chunk_name[4];
    char pad6[0x11b - 0x118];
    unsigned char interlaced;
    unsigned char pass;
    char pad7[0x121 - 0x11d];
    unsigned char pixel_depth;
};


void __cdecl FUN_002e6b60(PngStruct_2ea010 *png, void *s, int c, unsigned n);
void __cdecl FUN_002e81e0(PngStruct_2ea010 *png, unsigned n);
void __cdecl FUN_002dd690(PngStruct_2ea010 *png, void *buf, unsigned n);
unsigned __cdecl FUN_002e7500(unsigned char *buf);
void __cdecl FUN_002d6c90(PngStruct_2ea010 *png);
void __cdecl FUN_002e7580(PngStruct_2ea010 *png, void *buf, unsigned n);
void __cdecl FUN_002e69a0(PngStruct_2ea010 *png, const char *msg);
int __cdecl FUN_002e6f70(ZStream_2ea010 *z, int flush);
void __cdecl FUN_002e6db0(ZStream_2ea010 *z);

void FUN_002ea010(PngStruct_2ea010 *png)
{
    png->row_number = png->row_number + 1;
    if (png->row_number < png->num_rows)
        return;

    if (png->interlaced) {
        png->row_number = 0;
        FUN_002e6b60(png, png->prev_row, 0, png->rowbytes + 1);
        do {
            png->pass = png->pass + 1;
            if (png->pass >= 7)
                break;
            png->iwidth = (png->width + ((unsigned*)&DAT_004d10d8)[png->pass] - 1 - DAT_004d10bc[png->pass]) / ((unsigned*)&DAT_004d10d8)[png->pass];
            png->irowbytes = ((png->pixel_depth * png->iwidth + 7) >> 3) + 1;
            if (!(png->transformations & 2))
                png->num_rows = (png->height + ((unsigned*)&DAT_004d1110)[png->pass] - 1 - ((unsigned*)&DAT_004d10f4)[png->pass]) / ((unsigned*)&DAT_004d1110)[png->pass];
            else
                break;
        } while (png->iwidth == 0);
        if (png->pass < 7)
            return;
    }

    if (!(png->flags & 0x20)) {
        char extra;
        unsigned char chunk_length[4];
        png->zstream.next_out = (unsigned char *)&extra;
        png->zstream.avail_out = 1;
        for (;;) {
            if (!png->zstream.avail_in) {
                while (!png->idat_size) {
                    FUN_002e81e0(png, 0);
                    FUN_002dd690(png, chunk_length, 4);
                    png->idat_size = FUN_002e7500(chunk_length);
                    FUN_002d6c90(png);
                    FUN_002e7580(png, png->chunk_name, 4);
                    if (*(unsigned *)png->chunk_name != *(unsigned *)((unsigned char*)&DAT_004d103c))
                        FUN_002e69a0(png, "Not enough image data");
                }
                png->zstream.avail_in = png->zbuf_size;
                png->zstream.next_in = png->zbuf;
                if (png->zbuf_size > png->idat_size)
                    png->zstream.avail_in = png->idat_size;
                FUN_002e7580(png, png->zbuf, png->zstream.avail_in);
                png->idat_size -= png->zstream.avail_in;
            }
            int ret = FUN_002e6f70(&png->zstream, 1);
            if (ret == 1) {
                if (!png->zstream.avail_out || png->zstream.avail_in || png->idat_size)
                    FUN_002e69a0(png, "Extra compressed data");
                png->mode |= 8;
                png->flags |= 0x20;
                break;
            }
            if (ret != 0)
                FUN_002e69a0(png, png->zstream.msg ? png->zstream.msg : "Decompression Error");
            if (!png->zstream.avail_out)
                FUN_002e69a0(png, "Extra compressed data");
        }
        png->zstream.avail_out = 0;
    }
    if (png->idat_size || png->zstream.avail_in)
        FUN_002e69a0(png, "Extra compression data");
    FUN_002e6db0(&png->zstream);
    png->mode |= 8;
}
