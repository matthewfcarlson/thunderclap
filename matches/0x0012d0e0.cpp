extern "C" char DAT_00410ec0[];
typedef unsigned int u32_12d0e0;
extern u32_12d0e0 __cdecl FUN_002343e0(u32_12d0e0, void*);
struct Obj_12d0e0 {
    void Fn(u32_12d0e0);
};
struct Factory_12d0e0 {
    u32_12d0e0 vft;
};
void __cdecl target(Obj_12d0e0* a, u32_12d0e0 b) {
    Factory_12d0e0 local;
    local.vft = ((int)DAT_00410ec0);
    u32_12d0e0 x = FUN_002343e0(b, &local);
    a->Fn(x);
}
