// FUN_002e93b0 @ 0x002e93b0
struct png_color_16_2e93b0 {
    unsigned char index;
    unsigned char pad1;
    unsigned short red;
    unsigned short green;
    unsigned short blue;
    unsigned short gray;
};

struct png_color_2e93b0 {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

struct png_info_2e93b0 {
    char pad0[8];
    unsigned int valid;
};

struct png_struct_2e93b0 {
    char pad0[0x60];
    unsigned int mode;
    char pad64[0x10c - 0x64];
    png_color_2e93b0 *palette;
    char pad110[0x11e - 0x110];
    unsigned char color_type;
    char pad11f[0x130 - 0x11f];
    png_color_16_2e93b0 background;
};

void __cdecl FUN_002e69a0(png_struct_2e93b0 *png_ptr, const char *msg);
void __cdecl FUN_002e69d0(png_struct_2e93b0 *png_ptr, const char *msg);
int __cdecl FUN_002e81e0(png_struct_2e93b0 *png_ptr, unsigned int skip);
void __cdecl FUN_002e7580(png_struct_2e93b0 *png_ptr, unsigned char *buf, unsigned int length);
unsigned short __cdecl FUN_002e7560(const unsigned char *buf);
void __cdecl FUN_002eb150(png_struct_2e93b0 *png_ptr, png_info_2e93b0 *info_ptr, png_color_16_2e93b0 *background);

void png_handle_bKGD(png_struct_2e93b0 *png_ptr, png_info_2e93b0 *info_ptr, unsigned int length)
{
    unsigned int truelen;
    unsigned char buf[6];

    if (!(png_ptr->mode & 1)) {
        FUN_002e69a0(png_ptr, "Missing IHDR before bKGD");
    } else if (png_ptr->mode & 4) {
        FUN_002e69d0(png_ptr, "Invalid bKGD after IDAT");
        FUN_002e81e0(png_ptr, length);
        return;
    } else if (png_ptr->color_type == 3 && !(png_ptr->mode & 2)) {
        FUN_002e69d0(png_ptr, "Missing PLTE before bKGD");
        FUN_002e81e0(png_ptr, length);
        return;
    } else if (info_ptr != 0 && (info_ptr->valid & 0x20)) {
        FUN_002e69d0(png_ptr, "Duplicate bKGD chunk");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    if (png_ptr->color_type == 3)
        truelen = 1;
    else if (png_ptr->color_type & 2)
        truelen = 6;
    else
        truelen = 2;

    if (length != truelen) {
        FUN_002e69d0(png_ptr, "Incorrect bKGD chunk length");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    FUN_002e7580(png_ptr, buf, truelen);
    if (FUN_002e81e0(png_ptr, 0))
        return;

    if (png_ptr->color_type == 3) {
        png_ptr->background.index = buf[0];
        png_ptr->background.red = png_ptr->palette[buf[0]].red;
        png_ptr->background.green = png_ptr->palette[buf[0]].green;
        png_ptr->background.blue = png_ptr->palette[buf[0]].blue;
    } else if (!(png_ptr->color_type & 2)) {
        png_ptr->background.red = png_ptr->background.green = png_ptr->background.blue = png_ptr->background.gray = FUN_002e7560(buf);
    } else {
        png_ptr->background.red = FUN_002e7560(buf);
        png_ptr->background.green = FUN_002e7560(buf + 2);
        png_ptr->background.blue = FUN_002e7560(buf + 4);
    }
    FUN_002eb150(png_ptr, info_ptr, &png_ptr->background);
}
