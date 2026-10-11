// STATUS: equivalent (tools/equiv.py level 3: 113 inputs, branch coverage 24/32, incomplete)
// FUN_002719a0 @ 0x002719a0
// equiv-conv: FUN_002719a0 ecx edx
unsigned char __fastcall FUN_002719a0(unsigned int length, const unsigned char* bytes)
{
    if (length < 1 || length > 4)
        return 0;

    // Every byte after the first must be a UTF-8 continuation byte.
    for (unsigned int i = length - 1; i > 1; --i) {
        unsigned char continuation = bytes[i];
        if (continuation < 0x80 || continuation > 0xbf)
            return 0;
    }

    if (length >= 2) {
        unsigned char second = bytes[1];
        if (second > 0xbf)
            return 0;
        if (bytes[0] == 0xe0) {
            if (second < 0xa0)
                return 0;
        } else if (bytes[0] == 0xf0) {
            if (second < 0x90)
                return 0;
        } else if (bytes[0] == 0xf4) {
            if (second > 0x8f)
                return 0;
        } else if (second < 0x80) {
            return 0;
        }
    }

    unsigned char first = bytes[0];
    if (first >= 0x80 && first < 0xc2)
        return 0;
    return first <= 0xf4 ? 1 : 0;
}