// FUN_002dd3a0 @ 0x002dd3a0
struct RowInfo_2dd3a0 {
    unsigned int width;
    unsigned int rowbytes;
    unsigned char color_type;
    unsigned char bit_depth;
    unsigned char channels;
    unsigned char pixel_depth;
};

extern "C" void FUN_002dd3a0(void *row_info, unsigned char *row, unsigned int flags)
{
    unsigned char *sp = row;
    unsigned char *dp = row;
    unsigned int row_width = ((RowInfo_2dd3a0 *)row_info)->width;
    unsigned int i;

    if (((RowInfo_2dd3a0 *)row_info)->channels == 4) {
        if (((RowInfo_2dd3a0 *)row_info)->bit_depth == 8) {
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
            ((RowInfo_2dd3a0 *)row_info)->pixel_depth = 24;
            ((RowInfo_2dd3a0 *)row_info)->rowbytes = row_width * 3;
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
            ((RowInfo_2dd3a0 *)row_info)->pixel_depth = 48;
            ((RowInfo_2dd3a0 *)row_info)->rowbytes = row_width * 6;
        }
        ((RowInfo_2dd3a0 *)row_info)->channels = 3;
        ((RowInfo_2dd3a0 *)row_info)->color_type &= 0xfb;
    } else if (((RowInfo_2dd3a0 *)row_info)->channels == 2) {
        if (((RowInfo_2dd3a0 *)row_info)->bit_depth == 8) {
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
            ((RowInfo_2dd3a0 *)row_info)->pixel_depth = 8;
            ((RowInfo_2dd3a0 *)row_info)->rowbytes = row_width;
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
            ((RowInfo_2dd3a0 *)row_info)->pixel_depth = 16;
            ((RowInfo_2dd3a0 *)row_info)->rowbytes = row_width * 2;
        }
        ((RowInfo_2dd3a0 *)row_info)->channels = 1;
        ((RowInfo_2dd3a0 *)row_info)->color_type &= 0xfb;
    }
}
