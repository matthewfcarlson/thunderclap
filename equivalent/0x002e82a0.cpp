// STATUS: equivalent (tools/equiv.py level 3: 199 inputs, branch coverage 47/53, incomplete)
// FUN_002e82a0 @ 0x002e82a0
struct png_info;

struct png_struct {
    char pad0[0x60];
    unsigned int mode;
    char pad64[0xc0 - 0x64];
    unsigned int width;                 // 0xc0
    unsigned int height;                // 0xc4
    char padc8[0xd0 - 0xc8];
    unsigned int rowbytes;              // 0xd0
    char padd4[0x11b - 0xd4];
    unsigned char interlaced;           // 0x11b
    char pad11c[0x11e - 0x11c];
    unsigned char color_type;           // 0x11e
    unsigned char bit_depth;            // 0x11f
    char pad120;
    unsigned char pixel_depth;          // 0x121
    unsigned char channels;             // 0x122
};

void FUN_002e69a0(png_struct *png_ptr, const char *msg);
void FUN_002e7580(png_struct *png_ptr, unsigned char *buf, unsigned int length);
void FUN_002e81e0(png_struct *png_ptr, unsigned int skip);
unsigned int FUN_002e7500(unsigned char *buf);
void FUN_002eb240(png_struct *png_ptr, png_info *info_ptr, unsigned int width, unsigned int height,
                  int bit_depth, int color_type, int interlace, int compression, int filter);

// libpng png_handle_IHDR
void FUN_002e82a0(png_struct *png_ptr, png_info *info_ptr, unsigned int length)
{
    unsigned char buf[13];

    if (png_ptr->mode != 0)
        FUN_002e69a0(png_ptr, "Out of place IHDR");
    if (length != 13)
        FUN_002e69a0(png_ptr, "Invalid IHDR chunk");

    png_ptr->mode |= 1;
    FUN_002e7580(png_ptr, buf, 13);
    FUN_002e81e0(png_ptr, 0);

    unsigned int width = FUN_002e7500(buf);
    unsigned int height = FUN_002e7500(buf + 4);
    int bit_depth = buf[8];
    int color_type = buf[9];
    int compression = buf[10];
    int filter = buf[11];
    int interlace = buf[12];

    if (width == 0 || width > 0x7fffffff || height == 0 || height > 0x7fffffff)
        FUN_002e69a0(png_ptr, "Invalid image size in IHDR");

    if (bit_depth != 1 && bit_depth != 2 && bit_depth != 4 && bit_depth != 8 && bit_depth != 16)
        FUN_002e69a0(png_ptr, "Invalid bit depth in IHDR");

    if (color_type == 1 || color_type == 5 || color_type > 6)
        FUN_002e69a0(png_ptr, "Invalid color type in IHDR");

    if (color_type != 3 && (color_type == 2 || color_type == 4 || color_type == 6) && bit_depth < 8)
        FUN_002e69a0(png_ptr, "Invalid color type/bit depth combination in IHDR");

    if (interlace >= 2)
        FUN_002e69a0(png_ptr, "Unknown interlace method in IHDR");
    if (compression != 0)
        FUN_002e69a0(png_ptr, "Unknown compression method in IHDR");
    if (filter != 0)
        FUN_002e69a0(png_ptr, "Unknown filter method in IHDR");

    png_ptr->width = width;
    png_ptr->height = height;
    png_ptr->bit_depth = (unsigned char)bit_depth;
    png_ptr->interlaced = (unsigned char)interlace;
    png_ptr->color_type = (unsigned char)color_type;

    switch (color_type) {
    case 0: png_ptr->channels = 1; break;
    case 2: png_ptr->channels = 3; break;
    case 3: png_ptr->channels = 1; break;
    case 4: png_ptr->channels = 2; break;
    case 6: png_ptr->channels = 4; break;
    default: break;
    }
    png_ptr->pixel_depth = (unsigned char)(png_ptr->channels * bit_depth);
    png_ptr->rowbytes = (png_ptr->pixel_depth * width + 7) >> 3;

    FUN_002eb240(png_ptr, info_ptr, width, height, bit_depth, color_type, interlace, compression, filter);
}
