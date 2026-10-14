// STATUS: equivalent (tools/equiv.py level 3: 1792 inputs, branch coverage 12/12)
// FUN_00245b70 @ 0x00245b70
class RingReader {
public:
    unsigned char buf[0x80];
    char pad80[4];
    unsigned int windowStart;
    unsigned int windowLen;
    unsigned int base;
    char pad90[8];
    unsigned int limit;
    void FUN_002459d0();
    unsigned char ByteAt(unsigned int index);
};

unsigned char RingReader::ByteAt(unsigned int index)
{
    if (index >= limit)
        return 0;
    if (index < base)
        return 0;
    if (index >= windowStart && index < windowLen + base)
        return buf[(windowStart - base + index) & 0x7f];
    while (index < windowStart || index >= windowLen + base)
        FUN_002459d0();
    return buf[(index - base + windowStart) & 0x7f];
}
