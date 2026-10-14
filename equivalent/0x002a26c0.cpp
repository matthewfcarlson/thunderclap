// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 10/10)
// FUN_002a26c0 @ 0x002a26c0
typedef unsigned int uint_2a26c0;
struct Item_2a26c0 { uint_2a26c0 key; uint_2a26c0 value; };
void __cdecl FUN_002a26c0(uint_2a26c0 byteIndex, uint_2a26c0 count, Item_2a26c0* input, Item_2a26c0* output)
{
    uint_2a26c0 frequencies[256] = {0};
    uint_2a26c0 positions[256];
    uint_2a26c0 shift = (byteIndex * 8) & 31;
    uint_2a26c0 i;
    for (i = 0; i < count; ++i)
        ++frequencies[(input[i].key >> shift) & 255];
    positions[0] = 0;
    for (i = 1; i < 256; ++i)
        positions[i] = positions[i-1] + frequencies[i-1];
    for (i = 0; i < count; ++i) {
        uint_2a26c0 bucket = (input[i].key >> shift) & 255;
        uint_2a26c0 destination = positions[bucket];
        output[destination].key = input[i].key;
        output[destination].value = input[i].value;
        bucket = (input[i].key >> shift) & 255;
        ++positions[bucket];
    }
}
