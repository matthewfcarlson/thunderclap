extern "C" char DAT_0043a0a8[];
typedef unsigned int u32_34976f;
struct Obj_34976f {
    u32_34976f vptr;
    Obj_34976f* init(u32_34976f);
};
extern void __stdcall FUN_003496b8(u32_34976f*);
Obj_34976f* Obj_34976f::init(u32_34976f arg) {
    FUN_003496b8(&arg);
    vptr = ((int)DAT_0043a0a8);
    return this;
}