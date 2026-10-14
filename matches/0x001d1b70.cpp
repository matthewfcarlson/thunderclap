typedef unsigned int U32_1d1b70;
extern int __cdecl Check(U32_1d1b70, int);
extern void __cdecl Fail(U32_1d1b70, int);
extern U32_1d1b70 __cdecl Make(U32_1d1b70, int);
class Obj_1d1b70 {
  public:
    char pad[8];
    U32_1d1b70 value;
    bool Target(U32_1d1b70* out);
};
bool Obj_1d1b70::Target(U32_1d1b70* out) {
    bool r = true;
    if (Check(value, -1) != 6) {
        r = false;
        Fail(value, -2);
    } else {
        *out = Make(value, -10000);
    }
    return r;
}