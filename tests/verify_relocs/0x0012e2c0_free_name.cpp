// verify_relocs regression (integ2, D132): 0x0012e2c0 as it was at 365546d93, calling the game's operator delete[]
// (0x0008d340) under its address name FUN_0008d340. The byte match masks the name; free_by_other_name must report it.
typedef unsigned int size_t;
extern "C" void FUN_0008d340(void*);
extern "C++" __declspec(nothrow) void* FUN_0008d6d0(unsigned int);
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
