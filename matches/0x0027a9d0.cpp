int __cdecl FUN_00345804(char* dst, const char* fmt, int value);
bool __stdcall FUN_0027a970(int a);
extern const char formatString_27a9d0[];
class Obj_27a9d0 {
  public:
    bool Target(int a, int b);
    char pad[0x10];
    int index;
    char more[0xd24];
};
bool Obj_27a9d0::Target(int a, int b) {
    if (FUN_0027a970(a)) {
        return FUN_00345804((char*)this + 0xd38 + index * 0x60, formatString_27a9d0, b) == 1;
    }
    return false;
}
