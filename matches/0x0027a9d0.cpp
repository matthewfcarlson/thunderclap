int __cdecl FUN_00345804(char* dst, const char* fmt, int value);
bool __stdcall FUN_0027a970(int a);
extern const char formatString[];
class Obj {
  public:
    bool Target(int a, int b);
    char pad[0x10];
    int index;
    char more[0xd24];
};
bool Obj::Target(int a, int b) {
    if (FUN_0027a970(a)) {
        return FUN_00345804((char*)this + 0xd38 + index * 0x60, formatString, b) == 1;
    }
    return false;
}
