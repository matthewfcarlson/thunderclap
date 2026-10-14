extern unsigned char gTable_215f70[256];
int target(unsigned int value) {
    int count = -1;
    while (value >= 0x100) {
        value >>= 8;
        count += 8;
    }
    return gTable_215f70[value] + count;
}