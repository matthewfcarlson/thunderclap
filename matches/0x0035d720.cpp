extern "C" unsigned __int64 GetHash(unsigned int key);

unsigned int gHashLo;
unsigned int gHashHi;

void FUN_0035d720() {
    unsigned __int64 r = GetHash(0x400488u);
    gHashLo = (unsigned int)r;
    gHashHi = (unsigned int)(r >> 32);
}
