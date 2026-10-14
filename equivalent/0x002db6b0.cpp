// STATUS: equivalent (tools/equiv.py level 3: 127 inputs, branch coverage 41/42, incomplete)
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

void FUN_002db6b0(RowInfo_2db6b0 *row_info, unsigned char *row, Color_2db6b0 *palette, unsigned char *trans, int num_trans)
{
    unsigned int row_width = row_info->width;
    unsigned int i;
    int shift;
    unsigned char *sp;
    unsigned char *dp;

    if (row_info->color_type != 3)
        return;

    if (row_info->bit_depth < 8) {
        switch (row_info->bit_depth) {
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
        row_info->bit_depth = 8;
        row_info->pixel_depth = 8;
        row_info->rowbytes = row_width;
    }

    if (row_info->bit_depth == 8) {
        if (trans != 0) {
            sp = row + row_width - 1;
            dp = row + (row_width << 2) - 1;
            for (i = 0; i < row_width; i++) {
                if ((int)*sp >= num_trans)
                    *dp-- = 0xff;
                else
                    *dp-- = trans[*sp];
                *dp-- = palette[*sp].blue;
                *dp-- = palette[*sp].green;
                *dp-- = palette[*sp].red;
                sp--;
            }
            row_info->bit_depth = 8;
            row_info->pixel_depth = 32;
            row_info->rowbytes = row_width * 4;
            row_info->color_type = 6;
            row_info->channels = 4;
        } else {
            sp = row + row_width - 1;
            dp = row + (row_width * 3) - 1;
            for (i = 0; i < row_width; i++) {
                *dp-- = palette[*sp].blue;
                *dp-- = palette[*sp].green;
                *dp-- = palette[*sp].red;
                sp--;
            }
            row_info->bit_depth = 8;
            row_info->pixel_depth = 24;
            row_info->rowbytes = row_width * 3;
            row_info->color_type = 2;
            row_info->channels = 3;
        }
    }
}
