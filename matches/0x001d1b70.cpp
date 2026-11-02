typedef unsigned int U32_1d1b70;
extern int __cdecl FUN_00212f00(U32_1d1b70, int);
extern void __cdecl FUN_00212d80(U32_1d1b70, int);
extern "C" int __cdecl FUN_00339650(int, int);
class Obj_1d1b70 {
  public:
    char pad[8];
    U32_1d1b70 value;
    bool Target(U32_1d1b70* out);
};
bool Obj_1d1b70::Target(U32_1d1b70* out) {
    bool r = true;
    if (FUN_00212f00(value, -1) != 6) {
        r = false;
        FUN_00212d80(value, -2);
    } else {
        *out = ((unsigned int)FUN_00339650((unsigned int)value, -10000));
    }
    return r;
}