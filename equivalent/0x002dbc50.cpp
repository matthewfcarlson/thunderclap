// STATUS: equivalent (tools/equiv.py level 3: 12061 inputs, branch coverage 30/30; run with --inputs 12000)
// FUN_002dbc50 @ 0x002dbc50
struct ImageInfo_2dbc50 {
    unsigned int count;
    unsigned int byteSize;
    unsigned char format;
    unsigned char bits;
    unsigned char flag;
    unsigned char bitsCopy;
};

extern "C" void FUN_002dbc50(void *info, unsigned char *data, unsigned char *rgbToIndex, unsigned char *remap)
{
    unsigned int count = ((ImageInfo_2dbc50 *)info)->count;

    if ((((ImageInfo_2dbc50 *)info)->format == 2 || ((ImageInfo_2dbc50 *)info)->format == 6) && rgbToIndex != 0 && ((ImageInfo_2dbc50 *)info)->bits == 8) {
        unsigned int stride = (((ImageInfo_2dbc50 *)info)->format == 2) ? 3 : 4;
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
        ((ImageInfo_2dbc50 *)info)->bitsCopy = ((ImageInfo_2dbc50 *)info)->bits;
        ((ImageInfo_2dbc50 *)info)->format = 3;
        ((ImageInfo_2dbc50 *)info)->flag = 1;
        ((ImageInfo_2dbc50 *)info)->byteSize = (((ImageInfo_2dbc50 *)info)->bitsCopy * count + 7) >> 3;
        return;
    }
    if (((ImageInfo_2dbc50 *)info)->format == 3 && remap != 0 && ((ImageInfo_2dbc50 *)info)->bits == 8) {
        unsigned int n;
        unsigned char *p = data;
        for (n = count; n != 0; n--) {
            *p = remap[*p];
            p++;
        }
    }
}
