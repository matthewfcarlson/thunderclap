// STATUS: equivalent (tools/equiv.py level 3: 1832 inputs, branch coverage 92/95, incomplete)
// FUN_002d7440 @ 0x002d7440
// libpng 1.2.x png_read_row, as compiled into the game (zlib 1.2 inflate, Adam7 interlace handling).
struct ZStream_2d7440 {
    unsigned char *next_in;          // 0x00
    unsigned int avail_in;           // 0x04
    unsigned int total_in;
    unsigned char *next_out;         // 0x0c
    unsigned int avail_out;          // 0x10
    unsigned int total_out;
    const char *msg;                 // 0x18
    void *state;
    void *zalloc;
    void *zfree;
    void *opaque;
    int data_type;
    unsigned int adler;
    unsigned int reserved;
};

struct RowInfo_2d7440 {
    unsigned int width;              // 0x00
    unsigned int rowbytes;           // 0x04
    unsigned char color_type;        // 0x08
    unsigned char bit_depth;         // 0x09
    unsigned char channels;          // 0x0a
    unsigned char pixel_depth;       // 0x0b
};

struct PngStruct_2d7440;
typedef void (*ReadRowFn)(PngStruct_2d7440 *png, unsigned int row, int pass);

struct PngStruct_2d7440 {
    char pad00[0x60];
    unsigned int mode;               // 0x60
    unsigned int flags;              // 0x64
    unsigned int transformations;    // 0x68
    ZStream_2d7440 zstream;                 // 0x6c
    unsigned char *zbuf;             // 0xa4
    unsigned int zbuf_size;          // 0xa8
    char padac[0xc0 - 0xac];
    unsigned int width;              // 0xc0
    char padc4[0xd0 - 0xc4];
    unsigned int rowbytes;           // 0xd0
    unsigned int irowbytes;          // 0xd4
    unsigned int iwidth;             // 0xd8
    unsigned int row_number;         // 0xdc
    unsigned char *prev_row;         // 0xe0
    unsigned char *row_buf;          // 0xe4
    char pade8[0xf8 - 0xe8];
    RowInfo_2d7440 row_info;                // 0xf8
    unsigned int idat_size;          // 0x104
    char pad108[0x114 - 0x108];
    unsigned char chunk_name[4];     // 0x114
    char pad118[0x11b - 0x118];
    unsigned char interlaced;        // 0x11b
    unsigned char pass;              // 0x11c
    char pad11d[1];
    unsigned char color_type;        // 0x11e
    unsigned char bit_depth;         // 0x11f
    char pad120[1];
    unsigned char pixel_depth;       // 0x121
    unsigned char channels;          // 0x122
    char pad123[0x190 - 0x123];
    ReadRowFn read_row_fn;           // 0x190
};

extern int DAT_004d112c[];           // png_pass_mask
extern int DAT_004d1148[];           // png_pass_dsp_mask
extern const char DAT_004d103c[4];   // "IDAT"

void __cdecl FUN_002e7fb0(PngStruct_2d7440 *png);                                   // png_read_start_row
void __cdecl FUN_002e7680(PngStruct_2d7440 *png, unsigned char *row, int mask);     // png_combine_row
void __cdecl FUN_002ea010(PngStruct_2d7440 *png);                                   // png_read_finish_row
void __cdecl FUN_002e69a0(PngStruct_2d7440 *png, const char *msg);                  // png_error
void __cdecl FUN_002e81e0(PngStruct_2d7440 *png, unsigned int skip);                // png_crc_finish
void __cdecl FUN_002dd690(PngStruct_2d7440 *png, unsigned char *buf, unsigned int size);   // png_read_data
unsigned int __cdecl FUN_002e7500(unsigned char *buf);                       // png_get_uint_31
void __cdecl FUN_002d6c90(PngStruct_2d7440 *png);                                   // png_reset_crc
void __cdecl FUN_002e7580(PngStruct_2d7440 *png, unsigned char *buf, unsigned int size);   // png_crc_read
int __cdecl FUN_002e6f70(ZStream_2d7440 *z, int flush);                             // inflate
void __cdecl FUN_002e7dc0(PngStruct_2d7440 *png, RowInfo_2d7440 *info, unsigned char *row, unsigned char *prev, int filter);
void __cdecl FUN_002e6b30(PngStruct_2d7440 *png, unsigned char *dst, unsigned char *src, unsigned int size);
void __cdecl FUN_002dcd90(PngStruct_2d7440 *png);                                   // png_do_read_transformations
void __cdecl FUN_002e7990(RowInfo_2d7440 *info, unsigned char *row, int pass, unsigned int transformations);

void __cdecl FUN_002d7440(PngStruct_2d7440 *png, unsigned char *row, unsigned char *dsp_row)
{
    if (!(png->flags & 0x40))
        FUN_002e7fb0(png);

    if (png->interlaced && (png->transformations & 2)) {
        switch (png->pass) {
        case 0:
            if (png->row_number & 7) {
                if (dsp_row != 0)
                    FUN_002e7680(png, dsp_row, DAT_004d1148[0]);
                FUN_002ea010(png);
                return;
            }
            break;
        case 1:
            if ((png->row_number & 7) || png->width < 5) {
                if (dsp_row != 0)
                    FUN_002e7680(png, dsp_row, DAT_004d1148[1]);
                FUN_002ea010(png);
                return;
            }
            break;
        case 2:
            if ((png->row_number & 7) != 4) {
                if (dsp_row != 0 && (png->row_number & 4))
                    FUN_002e7680(png, dsp_row, DAT_004d1148[2]);
                FUN_002ea010(png);
                return;
            }
            break;
        case 3:
            if ((png->row_number & 3) || png->width < 3) {
                if (dsp_row != 0)
                    FUN_002e7680(png, dsp_row, DAT_004d1148[3]);
                FUN_002ea010(png);
                return;
            }
            break;
        case 4:
            if ((png->row_number & 3) != 2) {
                if (dsp_row != 0 && (png->row_number & 2))
                    FUN_002e7680(png, dsp_row, DAT_004d1148[4]);
                FUN_002ea010(png);
                return;
            }
            break;
        case 5:
            if ((png->row_number & 1) || png->width < 2) {
                if (dsp_row != 0)
                    FUN_002e7680(png, dsp_row, DAT_004d1148[5]);
                FUN_002ea010(png);
                return;
            }
            break;
        case 6:
            if (!(png->row_number & 1)) {
                FUN_002ea010(png);
                return;
            }
            break;
        }
    }

    if (!(png->mode & 4))
        FUN_002e69a0(png, "Invalid attempt to read row data");

    png->zstream.next_out = png->row_buf;
    png->zstream.avail_out = png->irowbytes;
    do {
        if (png->zstream.avail_in == 0) {
            while (png->idat_size == 0) {
                unsigned char chunk_length[4];
                FUN_002e81e0(png, 0);
                FUN_002dd690(png, chunk_length, 4);
                png->idat_size = FUN_002e7500(chunk_length);
                FUN_002d6c90(png);
                FUN_002e7580(png, png->chunk_name, 4);
                if (*(unsigned int *)png->chunk_name != *(const unsigned int *)DAT_004d103c)
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
            if (png->zstream.avail_out || png->zstream.avail_in || png->idat_size)
                FUN_002e69a0(png, "Extra compressed data");
            png->mode |= 8;
            png->flags |= 0x20;
            break;
        }
        if (ret != 0)
            FUN_002e69a0(png, png->zstream.msg ? png->zstream.msg : "Decompression error");
    } while (png->zstream.avail_out);

    png->row_info.channels = png->channels;
    png->row_info.pixel_depth = png->pixel_depth;
    png->row_info.rowbytes = (png->pixel_depth * png->iwidth + 7) >> 3;
    png->row_info.color_type = png->color_type;
    png->row_info.width = png->iwidth;
    png->row_info.bit_depth = png->bit_depth;

    FUN_002e7dc0(png, &png->row_info, png->row_buf + 1, png->prev_row + 1, png->row_buf[0]);
    FUN_002e6b30(png, png->prev_row, png->row_buf, png->rowbytes + 1);

    if (png->transformations)
        FUN_002dcd90(png);

    if (png->interlaced && (png->transformations & 2)) {
        if (png->pass < 6)
            FUN_002e7990(&png->row_info, png->row_buf + 1, png->pass, png->transformations);
        if (dsp_row != 0)
            FUN_002e7680(png, dsp_row, DAT_004d1148[png->pass]);
        if (row != 0)
            FUN_002e7680(png, row, DAT_004d112c[png->pass]);
    } else {
        if (row != 0)
            FUN_002e7680(png, row, 0xff);
        if (dsp_row != 0)
            FUN_002e7680(png, dsp_row, 0xff);
    }
    FUN_002ea010(png);

    if (png->read_row_fn != 0)
        png->read_row_fn(png, png->row_number, png->pass);
}
