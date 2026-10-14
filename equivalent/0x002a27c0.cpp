// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 10/10)
// FUN_002a27c0 @ 0x002a27c0
typedef unsigned int uint_2a27c0;
void __cdecl FUN_002a27c0(uint_2a27c0 byteIndex, uint_2a27c0 count, const uint_2a27c0* source, uint_2a27c0* destination)
{
    uint_2a27c0 frequencies[256] = {0};
    uint_2a27c0 offsets[261];
    uint_2a27c0 shift = (byteIndex * 8) & 31;
    uint_2a27c0 i;
    for (i = 0; i < count; ++i)
        ++frequencies[(source[i] >> shift) & 255];
    offsets[0] = 0;
    for (i = 1; i < 256; ++i)
        offsets[i] = offsets[i-1] + frequencies[i-1];
    for (i = 0; i < count; ++i) {
        uint_2a27c0 value = source[i];
        uint_2a27c0 bucket = (value >> shift) & 255;
        destination[offsets[bucket]] = value;
        bucket = (source[i] >> shift) & 255;
        ++offsets[bucket];
    }
}
