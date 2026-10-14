extern "C" void __cdecl FUN_00267760(void*, int, const char*, float);
class Obj_62180 {
  public:
    char pad[0x50];
    char F(float v);
};
char Obj_62180::F(float v) {
    FUN_00267760((char*)this + 0x50, 0x40, "%s", v);
    return 1;
}
