int __cdecl FUN_00271f20(unsigned short* destination, const unsigned short* source, unsigned int capacity) {
    unsigned int count = 0;
    while (source[count] != 0) {
        unsigned short first = source[count];
        unsigned int length = 1;
        if (first >= 0xd800 && first <= 0xdbff) {
            unsigned short second = source[count + 1];
            if (second < 0xdc00 || second > 0xdfff)
                return -1;
            length = 2;
        } else if (first >= 0xdc00 && first <= 0xdfff) {
            return -1;
        }
        if ((count + length) * 2 + 2 > capacity) {
            destination[count] = 0;
            return (int)count;
        }
        for (unsigned int i = 0; i < length; ++i)
            destination[count + i] = source[count + i];
        count += length;
    }
    destination[count] = 0;
    return (int)(count * 2);
}