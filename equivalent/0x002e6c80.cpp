// STATUS: equivalent (tools/equiv.py level 3: 132 inputs, branch coverage 10/10)
// FUN_002e6c80 @ 0x002e6c80
extern unsigned int DAT_0042fe20[256];
unsigned int __cdecl FUN_002e6c80(unsigned int crc, const unsigned char* data, unsigned int length)
{
    if (!data) return 0;
    crc = ~crc;
    while (length != 0) {
        crc = (crc >> 8) ^ DAT_0042fe20[(crc ^ *data) & 255];
        ++data;
        --length;
    }
    return ~crc;
}
