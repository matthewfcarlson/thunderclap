extern "C" void release(void*);
extern "C" void* alloc(unsigned int);
extern "C" unsigned int strlen(const char*);
extern "C" char* strcpy(char*, const char*);
class Obj_1a4250 {
    char pad[0x120];
    char* str;

  public:
    unsigned char Set(const char* s);
};
unsigned char Obj_1a4250::Set(const char* s) {
    release(str);
    if (!s) {
        str = 0;
        return 1;
    }
    str = (char*)alloc(strlen(s) + 1);
    strcpy(str, s);
    return 1;
}