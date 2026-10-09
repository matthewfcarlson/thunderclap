typedef unsigned int u32;
struct Obj { char pad[0x18]; u32 value; };
Obj* __stdcall FUN_00059ba0(u32);
u32 __stdcall FUN_00059bf0(u32 param) {
    Obj* p = FUN_00059ba0(param);
    if (p) return p->value;
    return 0;
}