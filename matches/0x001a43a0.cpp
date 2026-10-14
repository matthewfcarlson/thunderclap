extern "C" void release(void*);
extern "C" void* alloc(unsigned);
extern "C" unsigned strlen(const char*);
extern "C" char* strcpy(char*, const char*);
class Obj {
    char pad[0x13c];
    char* text;

  public:
    unsigned char Set(char* s);
};
unsigned char Obj::Set(char* s) {
    release(text);
    if (!s) {
        text = 0;
        return 1;
    }
    text = (char*)alloc(strlen(s) + 1);
    strcpy(text, s);
    return 1;
}