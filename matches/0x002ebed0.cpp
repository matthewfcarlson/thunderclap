typedef unsigned int U32;
struct Obj {
    char pad[0x24];
    void (__cdecl *fn)(U32, U32);
    U32 arg;
};
void __cdecl FUN_002ebed0(U32 param_1, Obj *param_2) {
    param_2->fn(param_2->arg, param_1);
}
