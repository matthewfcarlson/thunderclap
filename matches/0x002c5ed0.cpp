typedef unsigned int U;
void __cdecl FUN_002c4cb0(float f, void* p, U a, U b, U c, U d);
class Obj {
  public:
    U a, b, c, d;
    void FUN_002c5ed0(void*, U);
};
void Obj::FUN_002c5ed0(void* arg, U unused) {
    U x = *(U*)((char*)arg + 0x14);
    b = x;
    FUN_002c4cb0(0.2f, (char*)arg + 0x18, a, x, c, d);
    FUN_002c4cb0(0.3f, (char*)arg + 0x18, a, b, c, d);
}