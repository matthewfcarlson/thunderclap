// STATUS: equivalent (tools/equiv.py level 3: 7536 inputs, branch coverage 33/37, incomplete; run with --inputs 12000)
// FUN_002d93f0 @ 0x002d93f0
struct RowInfo_2d93f0 {
    unsigned width;
    unsigned rowbytes;
    unsigned char color_type;
    unsigned char bit_depth;
    unsigned char channels;
    unsigned char pixel_depth;
};

struct SigBits {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char gray;
    unsigned char alpha;
};

void FUN_002d93f0(RowInfo_2d93f0 *row_info, unsigned char *row, SigBits *sig_bits)
{
    if (row_info->color_type == 3)
        return;

    int shift[4];
    int channels = 0;
    unsigned short value = 0;
    unsigned row_width = row_info->width;

    if (row_info->color_type & 2) {
        shift[channels++] = row_info->bit_depth - sig_bits->red;
        shift[channels++] = row_info->bit_depth - sig_bits->green;
        shift[channels++] = row_info->bit_depth - sig_bits->blue;
    } else {
        shift[channels++] = row_info->bit_depth - sig_bits->gray;
    }
    if (row_info->color_type & 4)
        shift[channels++] = row_info->bit_depth - sig_bits->alpha;

    for (int c = 0; c < channels; c++) {
        if (shift[c] <= 0)
            shift[c] = 0;
        else
            value = 1;
    }
    if (!value)
        return;

    switch (row_info->bit_depth) {
    default:
        break;
    case 2: {
        unsigned char *bp = row;
        unsigned istop = row_info->rowbytes;
        for (unsigned i = 0; i < istop; i++) {
            *bp >>= 1;
            *bp++ &= 0x55;
        }
        break;
    }
    case 4: {
        unsigned char *bp = row;
        unsigned istop = row_info->rowbytes;
        unsigned char mask = (unsigned char)((((int)0xf0 >> shift[0]) & (int)0xf0) |
                                             (unsigned char)((int)0xf >> shift[0]));
        for (unsigned i = 0; i < istop; i++) {
            *bp >>= shift[0];
            *bp++ &= mask;
        }
        break;
    }
    case 8: {
        unsigned char *bp = row;
        unsigned istop = row_width * channels;
        for (unsigned i = 0; i < istop; i++)
            *bp++ >>= shift[i % channels];
        break;
    }
    case 16: {
        unsigned char *bp = row;
        unsigned istop = channels * row_width;
        for (unsigned i = 0; i < istop; i++) {
            value = (unsigned short)((*bp << 8) + *(bp + 1));
            value >>= shift[i % channels];
            *bp++ = (unsigned char)(value >> 8);
            *bp++ = (unsigned char)(value & 0xff);
        }
        break;
    }
    }
}
