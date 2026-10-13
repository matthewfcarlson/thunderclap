// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 10/10)
// FUN_002a27c0 @ 0x002a27c0
typedef unsigned int uint;
void __cdecl FUN_002a27c0(uint byteIndex, uint count, const uint* source, uint* destination)
{
    uint frequencies[256] = {0};
    uint offsets[261];
    uint shift = (byteIndex * 8) & 31;
    uint i;
    for (i = 0; i < count; ++i)
        ++frequencies[(source[i] >> shift) & 255];
    offsets[0] = 0;
    for (i = 1; i < 256; ++i)
        offsets[i] = offsets[i-1] + frequencies[i-1];
    for (i = 0; i < count; ++i) {
        uint value = source[i];
        uint bucket = (value >> shift) & 255;
        destination[offsets[bucket]] = value;
        bucket = (source[i] >> shift) & 255;
        ++offsets[bucket];
    }
}
