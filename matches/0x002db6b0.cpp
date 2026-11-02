// FUN_002db6b0 @ 0x002db6b0
struct RowInfo_2db6b0 {
    unsigned int width;
    unsigned int rowbytes;
    unsigned char color_type;
    unsigned char bit_depth;
    unsigned char channels;
    unsigned char pixel_depth;
};

struct Color_2db6b0 {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

extern "C" void FUN_002db6b0(void *row_info, unsigned char *row, void *palette, unsigned char *trans, int num_trans)
{
    unsigned int row_width = ((RowInfo_2db6b0 *)row_info)->width;
    unsigned int i;
    int shift;
    unsigned char *sp;
    unsigned char *dp;

    if (((RowInfo_2db6b0 *)row_info)->color_type != 3)
        return;

    if (((RowInfo_2db6b0 *)row_info)->bit_depth < 8) {
        switch (((RowInfo_2db6b0 *)row_info)->bit_depth) {
        case 1:
            sp = row + ((row_width - 1) >> 3);
            dp = row + row_width - 1;
            shift = 7 - (int)((row_width - 1) & 7);
            for (i = 0; i < row_width; i++) {
                *dp = (unsigned char)((*sp >> shift) & 1);
                if (shift == 7) {
                    shift = 0;
                    sp--;
                } else {
                    shift++;
                }
                dp--;
            }
            break;
        case 2:
            sp = row + ((row_width - 1) >> 2);
            dp = row + row_width - 1;
            shift = (3 - (int)((row_width - 1) & 3)) << 1;
            for (i = 0; i < row_width; i++) {
                *dp = (unsigned char)((*sp >> shift) & 3);
                if (shift == 6) {
                    shift = 0;
                    sp--;
                } else {
                    shift += 2;
                }
                dp--;
            }
            break;
        case 4:
            sp = row + ((row_width - 1) >> 1);
            dp = row + row_width - 1;
            shift = (int)((row_width & 1) << 2);
            for (i = 0; i < row_width; i++) {
                *dp = (unsigned char)((*sp >> shift) & 0xf);
                if (shift == 4) {
                    shift = 0;
                    sp--;
                } else {
                    shift += 4;
                }
                dp--;
            }
            break;
        }
        ((RowInfo_2db6b0 *)row_info)->bit_depth = 8;
        ((RowInfo_2db6b0 *)row_info)->pixel_depth = 8;
        ((RowInfo_2db6b0 *)row_info)->rowbytes = row_width;
    }

    if (((RowInfo_2db6b0 *)row_info)->bit_depth == 8) {
        if (trans != 0) {
            sp = row + row_width - 1;
            dp = row + (row_width << 2) - 1;
            for (i = 0; i < row_width; i++) {
                if ((int)*sp >= num_trans)
                    *dp-- = 0xff;
                else
                    *dp-- = trans[*sp];
                *dp-- = ((Color_2db6b0 *)palette)[*sp].blue;
                *dp-- = ((Color_2db6b0 *)palette)[*sp].green;
                *dp-- = ((Color_2db6b0 *)palette)[*sp].red;
                sp--;
            }
            ((RowInfo_2db6b0 *)row_info)->bit_depth = 8;
            ((RowInfo_2db6b0 *)row_info)->pixel_depth = 32;
            ((RowInfo_2db6b0 *)row_info)->rowbytes = row_width * 4;
            ((RowInfo_2db6b0 *)row_info)->color_type = 6;
            ((RowInfo_2db6b0 *)row_info)->channels = 4;
        } else {
            sp = row + row_width - 1;
            dp = row + (row_width * 3) - 1;
            for (i = 0; i < row_width; i++) {
                *dp-- = ((Color_2db6b0 *)palette)[*sp].blue;
                *dp-- = ((Color_2db6b0 *)palette)[*sp].green;
                *dp-- = ((Color_2db6b0 *)palette)[*sp].red;
                sp--;
            }
            ((RowInfo_2db6b0 *)row_info)->bit_depth = 8;
            ((RowInfo_2db6b0 *)row_info)->pixel_depth = 24;
            ((RowInfo_2db6b0 *)row_info)->rowbytes = row_width * 3;
            ((RowInfo_2db6b0 *)row_info)->color_type = 2;
            ((RowInfo_2db6b0 *)row_info)->channels = 3;
        }
    }
}
