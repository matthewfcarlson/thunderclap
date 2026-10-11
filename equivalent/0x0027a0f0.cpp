// STATUS: equivalent (tools/equiv.py level 3: 48 inputs, branch coverage 5/6, incomplete)
// FUN_0027a0f0 @ 0x0027a0f0
// equiv-conv: FUN_0027a0f0 ecx eax esi
unsigned int FUN_0027a0f0(unsigned int length, unsigned int tag, unsigned char *output)
{
    if (length <= 15) {
        output[0] = (unsigned char)(length | tag);
        return 1;
    }
    unsigned int remainder = length - 15;
    output[0] = (unsigned char)tag;
    unsigned int index = 1;
    if (remainder > 255) {
        unsigned int zeros = (remainder - 256) / 255 + 1;
        for (unsigned int i = 0; i < zeros; ++i)
            output[1 + i] = 0;
        index = zeros + 1;
        remainder -= zeros * 255;
    }
    output[index] = (unsigned char)remainder;
    return index + 1;
}
