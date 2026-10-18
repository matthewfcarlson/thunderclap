// FUN_002dd5c0 @ 0x002dd5c0
// libpng png_do_bgr: swap the red and blue samples of RGB / RGBA rows in place.
struct png_row_info_2dd5c0 {
    unsigned int width;
    unsigned int rowbytes;
    unsigned char color_type;
    unsigned char bit_depth;
    unsigned char channels;
    unsigned char pixel_depth;
};

void __cdecl FUN_002dd5c0(png_row_info_2dd5c0 *row_info, unsigned char *row)
{
    if (row_info->color_type & 2) {
        unsigned int row_width = row_info->width;
        unsigned int i;
        unsigned char *rp;
        unsigned char save;

        if (row_info->bit_depth == 8) {
            if (row_info->color_type == 2) {
                for (i = 0, rp = row; i < row_width; i++, rp += 3) {
                    save = *rp;
                    *rp = *(rp + 2);
                    *(rp + 2) = save;
                }
            } else if (row_info->color_type == 6) {
                for (i = 0, rp = row; i < row_width; i++, rp += 4) {
                    save = *rp;
                    *rp = *(rp + 2);
                    *(rp + 2) = save;
                }
            }
        } else if (row_info->bit_depth == 16) {
            if (row_info->color_type == 2) {
                for (i = 0, rp = row; i < row_width; i++, rp += 6) {
                    save = *rp;
                    *rp = *(rp + 4);
                    *(rp + 4) = save;
                    save = *(rp + 1);
                    *(rp + 1) = *(rp + 5);
                    *(rp + 5) = save;
                }
            } else if (row_info->color_type == 6) {
                for (i = 0, rp = row; i < row_width; i++, rp += 8) {
                    save = *rp;
                    *rp = *(rp + 4);
                    *(rp + 4) = save;
                    save = *(rp + 1);
                    *(rp + 1) = *(rp + 5);
                    *(rp + 5) = save;
                }
            }
        }
    }
}
