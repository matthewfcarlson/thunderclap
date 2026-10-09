typedef unsigned int u32;
struct Obj { u32 vptr; Obj* init(u32); };
extern void __stdcall FUN_003496b8(u32*);
Obj* Obj::init(u32 arg) {
    FUN_003496b8(&arg);
    vptr = 0x43a0a8;
    return this;
}