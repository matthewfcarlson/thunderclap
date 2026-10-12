// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 45/52, incomplete)
// FUN_002e7680 @ 0x002e7680
extern "C" void *memcpy(void *dst, const void *src, unsigned int n);

struct PngStruct {
    char pad0[0x68];
    unsigned int transformations;
    char pad6c[0xc0 - 0x6c];
    unsigned int width;
    char padc4[0xe4 - 0xc4];
    unsigned char *row_buf;
    char pade8[0x103 - 0xe8];
    unsigned char pixel_depth;
};

void __cdecl FUN_002e7680(PngStruct *png_ptr, unsigned char *row, int mask)
{
    if (mask == 0xff) {
        unsigned int rowbytes = (png_ptr->pixel_depth * png_ptr->width + 7) >> 3;
        memcpy(row, png_ptr->row_buf + 1, rowbytes);
        return;
    }

    switch (png_ptr->pixel_depth) {
    case 1: {
        unsigned char *sp = png_ptr->row_buf + 1;
        unsigned char *dp = row;
        int s_inc, s_start, s_end;
        int m = 0x80;
        int shift;
        unsigned int row_width = png_ptr->width;
        if (png_ptr->transformations & 0x10000) {
            s_start = 0;
            s_end = 7;
            s_inc = 1;
        } else {
            s_start = 7;
            s_end = 0;
            s_inc = -1;
        }
        shift = s_start;
        for (unsigned int i = 0; i < row_width; i++) {
            if (m & mask) {
                int value = (*sp >> shift) & 0x01;
                *dp &= (unsigned char)((0x7f7f >> (7 - shift)) & 0xff);
                *dp |= (unsigned char)(value << shift);
            }
            if (shift == s_end) {
                shift = s_start;
                sp++;
                dp++;
            } else {
                shift += s_inc;
            }
            if (m == 1)
                m = 0x80;
            else
                m >>= 1;
        }
        break;
    }
    case 2: {
        unsigned char *sp = png_ptr->row_buf + 1;
        unsigned char *dp = row;
        int s_start, s_end, s_inc;
        int m = 0x80;
        int shift;
        unsigned int row_width = png_ptr->width;
        if (png_ptr->transformations & 0x10000) {
            s_start = 0;
            s_end = 6;
            s_inc = 2;
        } else {
            s_start = 6;
            s_end = 0;
            s_inc = -2;
        }
        shift = s_start;
        for (unsigned int i = 0; i < row_width; i++) {
            if (m & mask) {
                int value = (*sp >> shift) & 0x3;
                *dp &= (unsigned char)((0x3f3f >> (6 - shift)) & 0xff);
                *dp |= (unsigned char)(value << shift);
            }
            if (shift == s_end) {
                shift = s_start;
                sp++;
                dp++;
            } else {
                shift += s_inc;
            }
            if (m == 1)
                m = 0x80;
            else
                m >>= 1;
        }
        break;
    }
    case 4: {
        unsigned char *sp = png_ptr->row_buf + 1;
        unsigned char *dp = row;
        int s_start, s_end, s_inc;
        int m = 0x80;
        int shift;
        unsigned int row_width = png_ptr->width;
        if (png_ptr->transformations & 0x10000) {
            s_start = 0;
            s_end = 4;
            s_inc = 4;
        } else {
            s_start = 4;
            s_end = 0;
            s_inc = -4;
        }
        shift = s_start;
        for (unsigned int i = 0; i < row_width; i++) {
            if (m & mask) {
                int value = (*sp >> shift) & 0xf;
                *dp &= (unsigned char)((0xf0f >> (4 - shift)) & 0xff);
                *dp |= (unsigned char)(value << shift);
            }
            if (shift == s_end) {
                shift = s_start;
                sp++;
                dp++;
            } else {
                shift += s_inc;
            }
            if (m == 1)
                m = 0x80;
            else
                m >>= 1;
        }
        break;
    }
    default: {
        unsigned char *sp = png_ptr->row_buf + 1;
        unsigned char *dp = row;
        unsigned int pixel_bytes = (png_ptr->pixel_depth >> 3);
        unsigned int row_width = png_ptr->width;
        unsigned char m = 0x80;
        for (unsigned int i = 0; i < row_width; i++) {
            if (m & mask)
                memcpy(dp, sp, pixel_bytes);
            sp += pixel_bytes;
            dp += pixel_bytes;
            if (m == 1)
                m = 0x80;
            else
                m >>= 1;
        }
        break;
    }
    }
}
