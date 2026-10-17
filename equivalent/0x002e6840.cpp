// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002e6840 @ 0x002e6840
extern unsigned int DAT_0042fdb4[4];
extern unsigned int DAT_0042fdc4[4];
unsigned int * __cdecl FUN_002e6840(unsigned int *result, unsigned int color, char delta)
{
    if (delta != 0) {
        int alpha = (color >> 24) + (int)delta;
        unsigned int slot = ((alpha >> 31) & 1) | ((alpha >> 7) & 2);
        *result = (((DAT_0042fdb4[slot] & alpha) | DAT_0042fdc4[slot]) << 24) | (color & 0xffffff);
    } else {
        *result = color;
    }
    return result;
}