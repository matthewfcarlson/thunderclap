// STATUS: equivalent (tools/equiv.py level 3: 20100 inputs, branch coverage 51/52, incomplete)
// FUN_002d9840 @ 0x002d9840
struct RowInfo {
    unsigned width;
    unsigned rowbytes;
    unsigned char color_type;
    unsigned char bit_depth;
    unsigned char channels;
    unsigned char pixel_depth;
};

extern "C" void FUN_002d9840(void *ri, unsigned char *row, unsigned filler, unsigned flags)
{
    unsigned w = ((RowInfo *)ri)->width;
    unsigned char hi = (unsigned char)(filler >> 8);
    unsigned char lo = (unsigned char)filler;
    bool after = (flags & 0x80) != 0;
    unsigned i;

    if (((RowInfo *)ri)->color_type == 0) {
        if (((RowInfo *)ri)->bit_depth == 8) {
            unsigned char *sp = row + w;
            unsigned char *dp = sp + w;
            if (after) {
                for (i = 1; i < w; i++) {
                    *(--dp) = lo;
                    *(--dp) = *(--sp);
                }
                *(--dp) = lo;
            } else {
                for (i = 0; i < w; i++) {
                    *(--dp) = *(--sp);
                    *(--dp) = lo;
                }
            }
            ((RowInfo *)ri)->channels = 2;
            ((RowInfo *)ri)->pixel_depth = 16;
            ((RowInfo *)ri)->rowbytes = w * 2;
        } else if (((RowInfo *)ri)->bit_depth == 16) {
            unsigned char *sp = row + w;
            unsigned char *dp = sp + w;
            if (after) {
                for (i = 1; i < w; i++) {
                    *(--dp) = hi;
                    *(--dp) = lo;
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                }
                *(--dp) = hi;
                *(--dp) = lo;
                ((RowInfo *)ri)->channels = 2;
                ((RowInfo *)ri)->pixel_depth = 32;
                ((RowInfo *)ri)->rowbytes = w * 2;
            } else {
                for (i = 0; i < w; i++) {
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = hi;
                    *(--dp) = lo;
                }
                ((RowInfo *)ri)->channels = 2;
                ((RowInfo *)ri)->pixel_depth = 16;
                ((RowInfo *)ri)->rowbytes = w * 2;
            }
        }
    } else if (((RowInfo *)ri)->color_type == 2) {
        if (((RowInfo *)ri)->bit_depth == 8) {
            unsigned char *sp = row + w * 3;
            unsigned char *dp = sp + w;
            if (after) {
                for (i = 1; i < w; i++) {
                    *(--dp) = lo;
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                }
                *(--dp) = lo;
            } else {
                for (i = 0; i < w; i++) {
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = lo;
                }
            }
            ((RowInfo *)ri)->channels = 4;
            ((RowInfo *)ri)->pixel_depth = 32;
            ((RowInfo *)ri)->rowbytes = w * 4;
        } else if (((RowInfo *)ri)->bit_depth == 16) {
            unsigned char *sp = row + w * 3;
            unsigned char *dp = sp + w;
            if (after) {
                for (i = 1; i < w; i++) {
                    *(--dp) = hi;
                    *(--dp) = lo;
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                }
                *(--dp) = hi;
                *(--dp) = lo;
            } else {
                for (i = 0; i < w; i++) {
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = hi;
                    *(--dp) = lo;
                }
            }
            ((RowInfo *)ri)->channels = 4;
            ((RowInfo *)ri)->pixel_depth = 64;
            ((RowInfo *)ri)->rowbytes = w * 4;
        }
    }
}
