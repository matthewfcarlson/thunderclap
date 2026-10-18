// FUN_002e91b0 @ 0x002e91b0
struct png_color_16_2e91b0 {
    unsigned char index;
    unsigned char pad1;
    unsigned short red;
    unsigned short green;
    unsigned short blue;
    unsigned short gray;
};

struct png_info_2e91b0 {
    char pad0[8];
    unsigned int valid;
};

struct png_struct_2e91b0 {
    char pad0[0x60];
    unsigned int mode;
    unsigned int flags;
    char pad68[0x110 - 0x68];
    unsigned short num_palette;
    unsigned short num_trans;
    char pad114[0x11e - 0x114];
    unsigned char color_type;
    char pad11f[0x180 - 0x11f];
    unsigned char *trans;
    png_color_16_2e91b0 trans_values;
};

void __cdecl FUN_002e69a0(png_struct_2e91b0 *png_ptr, const char *msg);
void __cdecl FUN_002e69d0(png_struct_2e91b0 *png_ptr, const char *msg);
int __cdecl FUN_002e81e0(png_struct_2e91b0 *png_ptr, unsigned int skip);
unsigned char *__cdecl FUN_002e6c00(png_struct_2e91b0 *png_ptr, unsigned int size);
void __cdecl FUN_002e7580(png_struct_2e91b0 *png_ptr, unsigned char *buf, unsigned int length);
unsigned short __cdecl FUN_002e7560(const unsigned char *buf);
void __cdecl FUN_002eb720(png_struct_2e91b0 *png_ptr, png_info_2e91b0 *info_ptr, unsigned char *trans, int num_trans,
                          png_color_16_2e91b0 *trans_values);

// libpng png_handle_tRNS
void png_handle_tRNS(png_struct_2e91b0 *png_ptr, png_info_2e91b0 *info_ptr, unsigned int length)
{
    unsigned char buf[6];

    if (!(png_ptr->mode & 1)) {
        FUN_002e69a0(png_ptr, "Missing IHDR before tRNS");
    } else if (png_ptr->mode & 4) {
        FUN_002e69d0(png_ptr, "Invalid tRNS after IDAT");
        FUN_002e81e0(png_ptr, length);
        return;
    } else if (info_ptr != 0 && (info_ptr->valid & 0x10)) {
        FUN_002e69d0(png_ptr, "Duplicate tRNS chunk");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    if (png_ptr->color_type == 3) {
        if (!(png_ptr->mode & 2)) {
            FUN_002e69d0(png_ptr, "Missing PLTE before tRNS");
        } else if (length > png_ptr->num_palette) {
            FUN_002e69d0(png_ptr, "Incorrect tRNS chunk length");
            FUN_002e81e0(png_ptr, length);
            return;
        }
        if (length == 0) {
            FUN_002e69d0(png_ptr, "Zero length tRNS chunk");
            FUN_002e81e0(png_ptr, length);
            return;
        }
        png_ptr->trans = FUN_002e6c00(png_ptr, length);
        png_ptr->flags |= 0x2000;
        FUN_002e7580(png_ptr, png_ptr->trans, length);
        png_ptr->num_trans = (unsigned short)length;
    } else if (png_ptr->color_type == 2) {
        if (length != 6) {
            FUN_002e69d0(png_ptr, "Incorrect tRNS chunk length");
            FUN_002e81e0(png_ptr, length);
            return;
        }
        FUN_002e7580(png_ptr, buf, length);
        png_ptr->num_trans = 1;
        png_ptr->trans_values.red = FUN_002e7560(buf);
        png_ptr->trans_values.green = FUN_002e7560(buf + 2);
        png_ptr->trans_values.blue = FUN_002e7560(buf + 4);
    } else if (png_ptr->color_type == 0) {
        if (length != 2) {
            FUN_002e69d0(png_ptr, "Incorrect tRNS chunk length");
            FUN_002e81e0(png_ptr, length);
            return;
        }
        FUN_002e7580(png_ptr, buf, 2);
        png_ptr->num_trans = 1;
        png_ptr->trans_values.gray = FUN_002e7560(buf);
    } else {
        FUN_002e69d0(png_ptr, "tRNS chunk not allowed with alpha channel");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    if (FUN_002e81e0(png_ptr, 0))
        return;
    FUN_002eb720(png_ptr, info_ptr, png_ptr->trans, png_ptr->num_trans, &png_ptr->trans_values);
}
