extern "C" void FUN_0008d340(void*);
extern "C" void* FUN_0008d6d0(unsigned int);
extern "C" unsigned int strlen(const char*);
inline void Copy(char* dst, const char* src) {
    char c;
    do {
        c = *src;
        ++src;
        *dst = c;
        ++dst;
    } while (c);
}
class X {
    char pad[16];
    char* str;

  public:
    char Set(const char* s);
};
char X::Set(const char* s) {
    FUN_0008d340(str);
    if (!s) {
        str = 0;
        return 1;
    }
    char* d = (char*)FUN_0008d6d0(strlen(s) + 1);
    str = d;
    Copy(d, s);
    return 1;
}