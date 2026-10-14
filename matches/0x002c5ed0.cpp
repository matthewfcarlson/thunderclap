typedef unsigned int U_2c5ed0;
void __cdecl FUN_002c4cb0(float f, void* p, U_2c5ed0 a, U_2c5ed0 b, U_2c5ed0 c, U_2c5ed0 d);
class Obj_2c5ed0 {
  public:
    U_2c5ed0 a, b, c, d;
    void FUN_002c5ed0(void*, U_2c5ed0);
};
void Obj_2c5ed0::FUN_002c5ed0(void* arg, U_2c5ed0 unused) {
    U_2c5ed0 x = *(U_2c5ed0*)((char*)arg + 0x14);
    b = x;
    FUN_002c4cb0(0.2f, (char*)arg + 0x18, a, x, c, d);
    FUN_002c4cb0(0.3f, (char*)arg + 0x18, a, b, c, d);
}