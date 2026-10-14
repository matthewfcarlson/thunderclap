// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002e6780 @ 0x002e6780
extern unsigned int DAT_0042fdb4[4];
extern unsigned int DAT_0042fdc4[4];
unsigned int * __cdecl FUN_002e6780(unsigned int *output, unsigned int color, signed char adjustment)
{
    if (!adjustment) { *output = color; return output; }
    int red = ((color >> 16) & 255) + (int)adjustment;
    int green = ((color >> 8) & 255) + (int)adjustment;
    int blue = (color & 255) + (int)adjustment;
    unsigned int ri = ((red >> 31) & 1) | ((red >> 7) & 2);
    unsigned int gi = ((green >> 31) & 1) | ((green >> 7) & 2);
    unsigned int bi = ((blue >> 31) & 1) | ((blue >> 7) & 2);
    unsigned int r = (DAT_0042fdb4[ri] & red) | DAT_0042fdc4[ri];
    unsigned int g = (DAT_0042fdb4[gi] & green) | DAT_0042fdc4[gi];
    unsigned int b = (DAT_0042fdb4[bi] & blue) | DAT_0042fdc4[bi];
    *output = (((r << 8) | g) << 8) | b | (color & 0xff000000);
    return output;
}
