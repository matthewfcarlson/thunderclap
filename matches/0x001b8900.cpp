typedef unsigned int u32_1b8900;
struct Obj_1b8900 {
    void second();
};
Obj_1b8900* __stdcall FUN_001c3d90(u32_1b8900);
void __stdcall target(u32_1b8900 param_1) {
    Obj_1b8900* p = FUN_001c3d90(param_1);
    p->second();
}