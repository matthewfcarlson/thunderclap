extern "C" void freeBuf(void*);
extern "C" void* allocBuf(unsigned int);
extern "C" unsigned int strlen(const char*);
extern "C" char* strcpy(char*, const char*);
class X {
    char pad[0x11c];
    char* str;

  public:
    unsigned char Set(const char* s);
};
unsigned char X::Set(const char* s) {
    freeBuf(str);
    if (!s) {
        str = 0;
        return 1;
    }
    str = (char*)allocBuf(strlen(s) + 1);
    strcpy(str, s);
    return 1;
}