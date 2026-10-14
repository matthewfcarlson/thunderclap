// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_00271fe0 @ 0x00271fe0
// Counts the UTF-16 code points of a string, returning -1 on an unpaired surrogate.
// Optionally stores the string length in bytes.
int FUN_00271fe0(const unsigned short *str, unsigned int *byteLength)
{
    int codePoints = 0;
    int index = 0;
    const unsigned short *cur = str;
    unsigned short c = str[0];

    while (c != 0) {
        int step = 1;
        if (c >= 0xd800 && c <= 0xdbff) {
            unsigned short low = cur[1];
            if (low < 0xdc00 || low > 0xdfff)
                return -1;
            step = 2;
        } else if (c >= 0xdc00 && c <= 0xdfff) {
            return -1;
        }
        index += step;
        c = str[index];
        cur = str + index;
        codePoints++;
    }

    if (byteLength != 0)
        *byteLength = index * 2;
    return codePoints;
}
