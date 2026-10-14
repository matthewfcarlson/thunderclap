typedef unsigned int u32_1d19d0;
extern void __cdecl Callee(u32_1d19d0, u32_1d19d0);
class Obj_1d19d0 {
    char pad[8];
    u32_1d19d0 value;

  public:
    unsigned char Target(u32_1d19d0 arg);
};
unsigned char Obj_1d19d0::Target(u32_1d19d0 arg) {
    Callee(value, 0xffffffffu - arg);
    return 1;
}