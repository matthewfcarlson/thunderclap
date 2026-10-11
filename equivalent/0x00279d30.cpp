// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 55/56, incomplete)
// FUN_00279d30 @ 0x00279d30
typedef unsigned char Byte;
Byte* __cdecl FUN_00279d30(Byte* input, unsigned int unused, Byte* output, unsigned int limit, unsigned int fullSize)
{
    unsigned int written = 0;
    if (!limit) return (Byte*)fullSize;
    if (limit == fullSize) {
        do {
            unsigned int token = *input++;
            if (token > 15) {
                unsigned int length = token & 15;
                if (!length) {
                    length = 15;
                    while (*input == 0) { length += 255; ++input; }
                    length += *input++;
                }
                unsigned int distance = (token >> 4) | ((unsigned int)*input++ << 4);
                Byte* source = output - distance;
                int groups = (int)length >> 2;
                unsigned int remainder = length - groups * 4;
                do {
                    for (int i=0; i<4; ++i) *output++ = *source++;
                    written += 4;
                } while (--groups);
                written += remainder;
                while (remainder--) *output++ = *source++;
            } else {
                unsigned int length = token;
                if (!length) {
                    while (*input == 0) { length += 255; ++input; }
                    length += *input++;
                    for (int i=0; i<15; ++i) *output++ = *input++;
                    written += 15;
                }
                do { *output++ = *input++; ++written; } while (--length);
            }
        } while (written < limit);
        return output;
    }
    unsigned int bound = limit;
    do {
        unsigned int token = *input++;
        if (token > 15) {
            unsigned int length = token & 15;
            if (!length) {
                length = 15;
                while (*input == 0) { length += 255; ++input; }
                length += *input++;
            }
            unsigned int distance = (token >> 4) | ((unsigned int)*input++ << 4);
            Byte* source = output - distance;
            unsigned int remaining = bound - written;
            if ((int)length > (int)remaining) length = remaining;
            if (length) {
                written += length;
                do { *output++ = *source++; } while (--length);
                bound = limit;
            }
        } else {
            unsigned int length = token;
            if (!length) {
                length = 15;
                while (*input == 0) { length += 255; ++input; }
                length += *input++;
            }
            unsigned int remaining = bound - written;
            if ((int)length > (int)remaining) length = remaining;
            do { *output++ = *input++; ++written; } while (--length);
            bound = limit;
        }
    } while (written < bound);
    return input;
}
