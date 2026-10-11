extern "C" void __cdecl thunk_FUN_00267090(char*);
extern "C" char* __cdecl FUN_0008d6d0(unsigned int);
extern "C" unsigned int strlen(const char*);
extern "C" char* strcpy(char*, const char*);
class Obj {
  public:
    char pad[0x15c];
    char* text;
    bool Set(char*);
};
bool Obj::Set(char* s) {
    thunk_FUN_00267090(text);
    if (!s) {
        text = 0;
        return true;
    }
    text = FUN_0008d6d0(strlen(s) + 1);
    strcpy(text, s);
    return true;
}
