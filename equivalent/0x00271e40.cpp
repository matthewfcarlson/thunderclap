// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 15/18, incomplete)
// FUN_00271e40 @ 0x00271e40
int __cdecl FUN_00271e40(unsigned int codepoint, unsigned short *output, unsigned int capacity, unsigned int replacement, unsigned int *written, unsigned int *unused);

int __cdecl encodeUtf16(unsigned int codepoint, unsigned short *output, unsigned int capacity, unsigned int replacement, unsigned int *written, unsigned int *unused)
{
    if (codepoint >= 0x10ffff) {
        int result = FUN_00271e40(replacement, output, capacity, 0, written, unused);
        return result == -2 ? -6 : result;
    }
    unsigned int bytes = codepoint <= 0xffff ? 2 : 4;
    if (capacity < bytes)
        return -1;
    if (codepoint <= 0xffff) {
        if (codepoint >= 0xd800 && codepoint <= 0xdfff)
            return -2;
        output[0] = (unsigned short)codepoint;
    } else {
        unsigned int value = codepoint - 0x10000;
        output[0] = (unsigned short)((value >> 10) + 0xd800);
        output[1] = (unsigned short)((value & 0x3ff) + 0xdc00);
    }
    *written = bytes;
    return 0;
}