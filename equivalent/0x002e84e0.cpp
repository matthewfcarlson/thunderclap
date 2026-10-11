// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 21/22, incomplete)
// FUN_002e84e0 @ 0x002e84e0
struct png_color {
    unsigned char red, green, blue;
};

struct png_info {
    char pad0[8];
    unsigned int valid;
};

struct png_struct {
    char pad0[0x60];
    unsigned int mode;
    unsigned int flags;
    char pad68[0x10c - 0x68];
    png_color *palette;
    unsigned short num_palette;
    unsigned short num_trans;
    char pad114[0x11e - 0x114];
    unsigned char color_type;
};

void FUN_002e69a0(png_struct *png_ptr, const char *msg);
void FUN_002e69d0(png_struct *png_ptr, const char *msg);
void FUN_002e81e0(png_struct *png_ptr, unsigned int skip);
void *FUN_002d6c20(png_struct *png_ptr, unsigned int num, unsigned int size);
void FUN_002e7580(png_struct *png_ptr, unsigned char *buf, unsigned int length);
void FUN_002eb4c0(png_struct *png_ptr, png_info *info_ptr, png_color *palette, int num);

// libpng png_handle_PLTE
void FUN_002e84e0(png_struct *png_ptr, png_info *info_ptr, unsigned int length)
{
    png_color *palette;
    int num, i;
    unsigned char buf[3];

    if (!(png_ptr->mode & 1)) {
        FUN_002e69a0(png_ptr, "Missing IHDR before PLTE");
    } else if (png_ptr->mode & 4) {
        FUN_002e69d0(png_ptr, "Invalid PLTE after IDAT");
        FUN_002e81e0(png_ptr, length);
        return;
    } else if (png_ptr->mode & 2) {
        FUN_002e69a0(png_ptr, "Duplicate PLTE chunk");
    }

    png_ptr->mode |= 2;

    if (length % 3) {
        if (png_ptr->color_type != 3) {
            FUN_002e69d0(png_ptr, "Invalid palette chunk");
            FUN_002e81e0(png_ptr, length);
            return;
        }
        FUN_002e69a0(png_ptr, "Invalid palette chunk");
    }

    num = (int)length / 3;
    palette = (png_color *)FUN_002d6c20(png_ptr, num, 3);
    png_ptr->flags |= 0x1000;

    for (i = 0; i < num; i++) {
        FUN_002e7580(png_ptr, buf, 3);
        palette[i].red = buf[0];
        palette[i].green = buf[1];
        palette[i].blue = buf[2];
    }

    FUN_002e81e0(png_ptr, 0);
    png_ptr->num_palette = (unsigned short)num;
    png_ptr->palette = palette;
    FUN_002eb4c0(png_ptr, info_ptr, palette, num);

    if (png_ptr->color_type == 3 && info_ptr && (info_ptr->valid & 0x10)
        && png_ptr->num_trans > png_ptr->num_palette) {
        FUN_002e69d0(png_ptr, "Truncating incorrect tRNS chunk length");
        png_ptr->num_trans = png_ptr->num_palette;
    }
}
