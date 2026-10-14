extern "C" void __cdecl Free(void*);
extern "C" void* __cdecl Alloc(unsigned int);
extern "C" unsigned int __cdecl strlen(const char*);
inline void Copy(char* dst, const char* src) {
    char c;
    do {
        c = *src;
        ++src;
        *dst = c;
        ++dst;
    } while (c);
}
class Obj_1a42c0 {
    char pad[0x12c];
    char* str;

  public:
    unsigned char Set(const char* s);
};
unsigned char Obj_1a42c0::Set(const char* s) {
    Free(str);
    if (!s) {
        str = 0;
        return 1;
    }
    char* dst = (char*)Alloc(strlen(s) + 1);
    str = dst;
    Copy(dst, s);
    return 1;
}