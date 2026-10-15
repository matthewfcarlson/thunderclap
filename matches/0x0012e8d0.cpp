extern "C" void free(void*);
extern "C" void* malloc(unsigned int);
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
    free(str);
    if (!s) {
        str = 0;
        return 1;
    }
    char* d = (char*)malloc(strlen(s) + 1);
    str = d;
    Copy(d, s);
    return 1;
}