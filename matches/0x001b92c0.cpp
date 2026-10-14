// Same code shape as 0x001b8900 (propagated; names are from that function)
typedef unsigned int u32_1b92c0;
struct Obj_1b92c0 {
    void second();
};
Obj_1b92c0* __stdcall FUN_001c3d90(u32_1b92c0);
void __stdcall target(u32_1b92c0 param_1) {
    Obj_1b92c0* p = FUN_001c3d90(param_1);
    p->second();
}