// Same code shape as 0x00066a50 (propagated; names are from that function)
typedef unsigned int u32_66b20;
struct Obj_66b20 {
    u32_66b20 a;
};
extern u32_66b20 __fastcall FUN_00230ea0(Obj_66b20*);
u32_66b20* __fastcall target(Obj_66b20* self, void*, u32_66b20* out) {
    u32_66b20 v = FUN_00230ea0(self);
    out[0] = v;
    out[1] = (u32_66b20)self;
    return out;
}