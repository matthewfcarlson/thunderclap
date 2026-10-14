typedef unsigned int U32_2ebed0;
struct Obj_2ebed0 {
    char pad[0x24];
    void(__cdecl* fn)(U32_2ebed0, U32_2ebed0);
    U32_2ebed0 arg;
};
void __cdecl FUN_002ebed0(U32_2ebed0 param_1, Obj_2ebed0* param_2) {
    param_2->fn(param_2->arg, param_1);
}
