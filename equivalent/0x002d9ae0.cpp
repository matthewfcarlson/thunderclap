// STATUS: equivalent (tools/equiv.py level 3: 137 inputs, branch coverage 24/28, incomplete)
// FUN_002d9ae0 @ 0x002d9ae0
struct ImageInfo_2d9ae0 {
    unsigned int width;
    unsigned int pitch;
    unsigned char flags;
    unsigned char depth;
    unsigned char channels;
    unsigned char bitsPerPixel;
};

// Expands a grayscale (flags 0) or gray+alpha (flags 4) image to RGB(A) in place, walking backwards.
void __cdecl FUN_002d9ae0(ImageInfo_2d9ae0 *info, unsigned char *data)
{
    unsigned char depth = info->depth;
    unsigned int width = info->width;
    if (depth < 8 || (info->flags & 2) != 0)
        return;

    unsigned char flags = info->flags;
    if (flags == 0) {
        if (depth == 8) {
            unsigned char *s = data + width - 1;
            unsigned char *d = s + width * 2;
            for (unsigned int n = width; n != 0; n--) {
                d[0] = s[0];
                d[-1] = s[0];
                d[-2] = s[0];
                d -= 3;
                s -= 1;
            }
        } else {
            unsigned char *s = data + width * 2 - 1;
            unsigned char *d = s + width * 4;
            for (unsigned int n = width; n != 0; n--) {
                d[0] = s[0];
                d[-1] = s[-1];
                d[-2] = s[0];
                d[-3] = s[-1];
                d[-4] = s[0];
                d[-5] = s[-1];
                d -= 6;
                s -= 2;
            }
        }
    } else if (flags == 4) {
        if (depth == 8) {
            unsigned char *s = data + width * 2 - 1;
            unsigned char *d = s + width * 2;
            for (unsigned int n = width; n != 0; n--) {
                d[0] = s[0];
                d[-1] = s[-1];
                d[-2] = s[-1];
                d[-3] = s[-1];
                d -= 4;
                s -= 2;
            }
        } else {
            unsigned char *s = data + width * 4 - 1;
            unsigned char *d = s + width * 4;
            for (unsigned int n = width; n != 0; n--) {
                d[0] = s[0];
                d[-1] = s[-1];
                d[-2] = s[-2];
                d[-3] = s[-3];
                d[-4] = s[-2];
                d[-5] = s[-3];
                d[-6] = s[-2];
                d[-7] = s[-3];
                d -= 8;
                s -= 4;
            }
        }
    }

    unsigned char channels = info->channels + 2;
    unsigned char newFlags = info->flags;
    info->channels = channels;
    unsigned char bits = (unsigned char)((signed char)info->depth * (signed char)channels);
    info->flags = newFlags | 2;
    info->bitsPerPixel = bits;
    info->pitch = ((unsigned int)bits * width + 7) >> 3;
}
