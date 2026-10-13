// STATUS: equivalent (tools/equiv.py level 3: 159 inputs, branch coverage 16/16)
// FUN_002eafc0 @ 0x002eafc0
unsigned int __cdecl FUN_002eafc0(unsigned int checksum, const unsigned char* data, unsigned int length)
{
    if (!data) return 1;
    unsigned int low = checksum & 0xffff;
    unsigned int high = checksum >> 16;
    while (length) {
        unsigned int count = length < 5552 ? length : 5552;
        length -= count;
        for (unsigned int i = 0; i < count; ++i) {
            low += *data++;
            high += low;
        }
        low %= 65521;
        high %= 65521;
    }
    return (high << 16) | low;
}
