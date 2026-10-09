struct Obj {
    char pad[4];
    unsigned int* mEnd;
    void Copy(unsigned int* dst, unsigned int* src);
};
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
void Obj::Copy(unsigned int* dst, unsigned int* src) {
    unsigned int* end = mEnd;
    unsigned int* out = dst;
    while (src != end) {
        memcpy(out, src, 0xe0);
        src += 0x38;
        out += 0x38;
    }
    mEnd = out;
}