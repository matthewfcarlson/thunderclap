// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 10/10)
// FUN_0008ef00 @ 0x0008ef00
struct Stream {
    virtual void reset(int);
    virtual void flush();
    unsigned stride;
    unsigned char* current;
    unsigned char* auxiliary1;
    unsigned char* auxiliary2;
    unsigned char* auxiliary3;
    unsigned limit;
    unsigned index;
    int retained;
    unsigned char buffer[1];
    void FUN_0008ef00();
};
void Stream::FUN_0008ef00() {
    ++index;
    if (index != limit) {
        unsigned step = stride;
        current += step;
        if (auxiliary1) auxiliary1 += step;
        if (auxiliary2) auxiliary2 += step;
        if (auxiliary3) auxiliary3 += step;
        return;
    }
    if (retained > 0) {
        unsigned bytes = stride * (unsigned)retained;
        unsigned char* source = current - stride * ((unsigned)retained - 1);
        unsigned char* dest = buffer;
        for (unsigned words = bytes >> 2; words; --words) {
            *(unsigned*)dest = *(unsigned*)source;
            dest += 4;
            source += 4;
        }
        for (unsigned tail = bytes & 3; tail; --tail) {
            *dest++ = *source++;
        }
    }
    flush();
    reset(1);
}
