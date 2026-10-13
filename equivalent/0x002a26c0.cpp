// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 10/10)
// FUN_002a26c0 @ 0x002a26c0
typedef unsigned int uint;
struct Item { uint key; uint value; };
void __cdecl FUN_002a26c0(uint byteIndex, uint count, Item* input, Item* output)
{
    uint frequencies[256] = {0};
    uint positions[256];
    uint shift = (byteIndex * 8) & 31;
    uint i;
    for (i = 0; i < count; ++i)
        ++frequencies[(input[i].key >> shift) & 255];
    positions[0] = 0;
    for (i = 1; i < 256; ++i)
        positions[i] = positions[i-1] + frequencies[i-1];
    for (i = 0; i < count; ++i) {
        uint bucket = (input[i].key >> shift) & 255;
        uint destination = positions[bucket];
        output[destination].key = input[i].key;
        output[destination].value = input[i].value;
        bucket = (input[i].key >> shift) & 255;
        ++positions[bucket];
    }
}
