unsigned char __cdecl FUN_00271dd0(const unsigned short* text, unsigned int* bytesConsumed,
                                   unsigned int* codePoint) {
    unsigned int point = text[0];
    unsigned int units = 1;
    if (point >= 0xd800 && point <= 0xdbff) {
        unsigned int low = text[1];
        if (low < 0xdc00 || low > 0xdfff)
            return 0;
        point = ((point - 0xd7f7) << 10) + low;
        units = 2;
    } else if (point >= 0xdc00 && point <= 0xdfff) {
        return 0;
    }
    if (bytesConsumed)
        *bytesConsumed = units * 2;
    if (codePoint)
        *codePoint = point;
    return 1;
}