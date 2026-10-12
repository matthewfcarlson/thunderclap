// STATUS: equivalent (tools/equiv.py level 3: 1951 inputs, branch coverage 43/48, incomplete)
// FUN_002dd3a0 @ 0x002dd3a0
struct RowInfo {
    unsigned int width;
    unsigned int rowbytes;
    unsigned char color_type;
    unsigned char bit_depth;
    unsigned char channels;
    unsigned char pixel_depth;
};

void FUN_002dd3a0(RowInfo *row_info, unsigned char *row, unsigned int flags)
{
    unsigned char *sp = row;
    unsigned char *dp = row;
    unsigned int row_width = row_info->width;
    unsigned int i;

    if (row_info->channels == 4) {
        if (row_info->bit_depth == 8) {
            if (flags & 0x80) {
                dp += 3;
                sp += 4;
                for (i = 1; i < row_width; i++) {
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    sp++;
                }
            } else {
                for (i = 0; i < row_width; i++) {
                    sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                }
            }
            row_info->pixel_depth = 24;
            row_info->rowbytes = row_width * 3;
        } else {
            if (flags & 0x80) {
                sp += 8;
                dp += 6;
                for (i = 1; i < row_width; i++) {
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    sp += 2;
                }
            } else {
                for (i = 0; i < row_width; i++) {
                    sp += 2;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                }
            }
            row_info->pixel_depth = 48;
            row_info->rowbytes = row_width * 6;
        }
        row_info->channels = 3;
        row_info->color_type &= 0xfb;
    } else if (row_info->channels == 2) {
        if (row_info->bit_depth == 8) {
            if (flags & 0x80) {
                for (i = 0; i < row_width; i++) {
                    *dp++ = *sp++;
                    sp++;
                }
            } else {
                for (i = 0; i < row_width; i++) {
                    sp++;
                    *dp++ = *sp++;
                }
            }
            row_info->pixel_depth = 8;
            row_info->rowbytes = row_width;
        } else {
            if (flags & 0x80) {
                sp += 4;
                dp += 2;
                for (i = 1; i < row_width; i++) {
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                    sp += 2;
                }
            } else {
                for (i = 0; i < row_width; i++) {
                    sp += 2;
                    *dp++ = *sp++;
                    *dp++ = *sp++;
                }
            }
            row_info->pixel_depth = 16;
            row_info->rowbytes = row_width * 2;
        }
        row_info->channels = 1;
        row_info->color_type &= 0xfb;
    }
}
