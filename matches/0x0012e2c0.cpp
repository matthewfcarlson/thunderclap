typedef unsigned int size_t;
extern "C" void FUN_0008d340(void*);
extern "C" void* FUN_0008d6d0(size_t);
extern "C" size_t strlen(const char*);
extern "C" char* strcpy(char*, const char*);
class X {
    char pad[12];
    char* str;

  public:
    bool Set(const char* s);
};
bool X::Set(const char* s) {
    FUN_0008d340(str);
    if (!s) {
        str = 0;
        return true;
    }
    str = (char*)FUN_0008d6d0(strlen(s) + 1);
    strcpy(str, s);
    return true;
}