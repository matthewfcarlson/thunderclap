// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 9/10, incomplete)
// FUN_0031c680 @ 0x0031c680
unsigned int* __cdecl FUN_0031c680(unsigned int* output, unsigned int first, unsigned int second, int weight)
{
    if (weight <= 0) { *output = first; return output; }
    if (weight >= 255) { *output = second; return output; }
    unsigned int a = 255 - weight;
    unsigned int b = weight;
    unsigned int result = 0;
    for (unsigned int shift = 0; shift < 32; shift += 8) {
        unsigned int channel = (((first >> shift) & 255) * a + ((second >> shift) & 255) * b) >> 8;
        result |= channel << shift;
    }
    *output = result;
    return output;
}
