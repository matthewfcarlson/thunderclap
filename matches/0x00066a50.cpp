typedef unsigned int u32;
struct Obj {
    u32 a;
};
extern u32 __fastcall FUN_00230ea0(Obj*);
u32* __fastcall target(Obj* self, void*, u32* out) {
    u32 v = FUN_00230ea0(self);
    out[0] = v;
    out[1] = (u32)self;
    return out;
}