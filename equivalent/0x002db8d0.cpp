// STATUS: equivalent (tools/equiv.py level 3: 2789 inputs, branch coverage 65/76, incomplete)
// FUN_002db8d0 @ 0x002db8d0
struct ImageInfo {
    unsigned int count;         // 0x00 pixels
    unsigned int size;          // 0x04 bytes
    unsigned char mode;         // 0x08
    unsigned char depth;        // 0x09 bits per channel
    unsigned char channels;     // 0x0a
    unsigned char bpp;          // 0x0b bits per pixel
};

struct ColorKey {
    unsigned short w[5];
};

void FUN_002db8d0(ImageInfo *im, unsigned char *buf, ColorKey *key)
{
    unsigned int count = im->count;
    unsigned int k;
    unsigned int n;
    unsigned char *src;
    unsigned char *dst;

    if (im->mode == 0) {
        if (key != 0)
            k = key->w[4];
        else
            k = 0;
        unsigned char depth = im->depth;
        if (depth < 8) {
            if (depth == 4) {
                k = k + (k << 4);
                src = buf + ((count - 1) >> 1);
                dst = buf + count - 1;
                unsigned int shift = 4 - (((count - 1) & 1) << 2);
                for (n = count; n != 0; n--) {
                    unsigned int v = (*src >> shift) & 0xf;
                    *dst = (unsigned char)((v << 4) | v);
                    if (shift == 4) {
                        shift = 0;
                        src--;
                    } else {
                        shift = 4;
                    }
                    dst--;
                }
                im = im;
            } else if (depth == 2) {
                k = k * 0x55;
                src = buf + ((count - 1) >> 2);
                dst = buf + count - 1;
                unsigned int shift = (3 - ((count - 1) & 3)) << 1;
                for (n = count; n != 0; n--) {
                    unsigned int v = (*src >> shift) & 3;
                    unsigned char b = (unsigned char)v;
                    b = (unsigned char)((b << 2) | v);
                    b = (unsigned char)((b << 2) | v);
                    b = (unsigned char)((b << 2) | v);
                    *dst = b;
                    if (shift == 6) {
                        shift = 0;
                        src--;
                    } else {
                        shift += 2;
                    }
                    dst--;
                }
            } else if (depth == 1) {
                k = k * 0xff;
                src = buf + ((count - 1) >> 3);
                unsigned int shift = 7 - ((count - 1) & 7);
                dst = buf + count - 1;
                unsigned int saved = k;
                for (n = count; n != 0; n--) {
                    unsigned char bit = (unsigned char)((*src >> shift) & 1);
                    unsigned int m = bit ? 0xff : 0;
                    *dst = (unsigned char)m;
                    if (shift == 7) {
                        shift = 0;
                        src--;
                    } else {
                        shift++;
                    }
                    dst--;
                }
                k = saved;
            }
            im->depth = 8;
            im->bpp = 8;
            im->size = count;
        }
        if (key == 0)
            return;
        unsigned char d = im->depth;
        if (d == 8) {
            src = buf + count - 1;
            dst = buf + count * 2 - 1;
            for (n = count; n != 0; n--) {
                unsigned short c = *src;
                if (c == (unsigned short)k)
                    *dst = 0;
                else
                    *dst = 0xff;
                dst--;
                *dst = *src;
                dst--;
                src--;
            }
        } else if (d == 16) {
            unsigned int size = im->size;
            src = buf + size - 1;
            dst = buf + size * 2 - 1;
            for (n = count; n != 0; n--) {
                unsigned int v = (src[-1] << 8) | src[0];
                unsigned char a;
                if (v == (unsigned short)k)
                    a = 0;
                else
                    a = 0xff;
                dst[0] = a;
                dst[-1] = a;
                dst[-2] = src[0];
                dst[-3] = src[-1];
                dst -= 4;
                src -= 2;
            }
        }
        unsigned char b = (unsigned char)(im->depth << 1);
        im->mode = 4;
        im->channels = 2;
        im->bpp = b;
        im->size = (b * count) >> 3;
        return;
    }
    if (im->mode != 2)
        return;
    if (key == 0)
        return;
    unsigned char d = im->depth;
    if (d == 8) {
        src = buf + im->size - 1;
        dst = buf + count * 4 - 1;
        for (n = count; n != 0; n--) {
            unsigned short r = src[-2];
            unsigned short g = src[-1];
            unsigned short bl = src[0];
            unsigned char a;
            if (r == key->w[1] && g == key->w[2] && bl == key->w[3])
                a = 0;
            else
                a = 0xff;
            dst[0] = a;
            dst[-1] = src[0];
            dst[-2] = src[-1];
            dst[-3] = src[-2];
            dst -= 4;
            src -= 3;
        }
    } else if (d == 16) {
        src = buf + im->size - 1;
        dst = buf + count * 8 - 1;
        for (n = count; n != 0; n--) {
            unsigned char a;
            if (((src[-5] << 8) | src[-4]) == key->w[1] && ((src[-3] << 8) | src[-2]) == key->w[2] &&
                ((src[-1] << 8) | src[0]) == key->w[3])
                a = 0;
            else
                a = 0xff;
            dst[0] = a;
            dst[-1] = a;
            dst[-2] = src[0];
            dst[-3] = src[-1];
            dst[-4] = src[-2];
            dst[-5] = src[-3];
            dst[-6] = src[-4];
            dst[-7] = src[-5];
            dst -= 8;
            src -= 6;
        }
    }
    unsigned char b = (unsigned char)(im->depth << 2);
    im->mode = 6;
    im->channels = 4;
    im->bpp = b;
    im->size = (b * count) >> 3;
}
