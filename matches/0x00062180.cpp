extern "C" void __cdecl FUN_00267760(void*, int, const char*, float);
class Obj {
  public:
    char pad[0x50];
    char F(float v);
};
char Obj::F(float v) {
    FUN_00267760((char*)this + 0x50, 0x40, "%s", v);
    return 1;
}
