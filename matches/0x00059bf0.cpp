typedef unsigned int u32_59bf0;
struct Obj_59bf0 {
    char pad[0x18];
    u32_59bf0 value;
};
Obj_59bf0* __stdcall FUN_00059ba0(u32_59bf0);
u32_59bf0 __stdcall FUN_00059bf0(u32_59bf0 param) {
    Obj_59bf0* p = FUN_00059ba0(param);
    if (p)
        return p->value;
    return 0;
}