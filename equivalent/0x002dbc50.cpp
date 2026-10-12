// STATUS: equivalent (tools/equiv.py level 3: 12061 inputs, branch coverage 30/30; run with --inputs 12000)
// FUN_002dbc50 @ 0x002dbc50
struct ImageInfo {
    unsigned int count;
    unsigned int byteSize;
    unsigned char format;
    unsigned char bits;
    unsigned char flag;
    unsigned char bitsCopy;
};

void FUN_002dbc50(ImageInfo *info, unsigned char *data, unsigned char *rgbToIndex, unsigned char *remap)
{
    unsigned int count = info->count;

    if ((info->format == 2 || info->format == 6) && rgbToIndex != 0 && info->bits == 8) {
        unsigned int stride = (info->format == 2) ? 3 : 4;
        unsigned char *src = data;
        unsigned char *dst = data;
        unsigned int n;
        for (n = count; n != 0; n--) {
            unsigned int idx = (((src[0] & 0xf8) << 5) | (src[1] & 0xf8)) << 2;
            idx |= (src[2] >> 3) & 0x1f;
            *dst = rgbToIndex[idx];
            dst++;
            src += stride;
        }
        info->bitsCopy = info->bits;
        info->format = 3;
        info->flag = 1;
        info->byteSize = (info->bitsCopy * count + 7) >> 3;
        return;
    }
    if (info->format == 3 && remap != 0 && info->bits == 8) {
        unsigned int n;
        unsigned char *p = data;
        for (n = count; n != 0; n--) {
            *p = remap[*p];
            p++;
        }
    }
}
