// cl-flags: /O2
extern "C" void __cdecl FUN_000964a0(char*, int, const char*, const char*);
class Obj {
    char pad[0x10];

  public:
    char Format(const char* s);
};
char Obj::Format(const char* s) {
    FUN_000964a0((char*)((char*)this + 0x10), 0x40, "%s", s);
    return 1;
}
