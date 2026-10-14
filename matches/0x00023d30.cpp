typedef unsigned int u32_23d30;
typedef unsigned __int64 u64_23d30;
extern u64_23d30 __cdecl get_value(u32_23d30);
struct Obj_23d30 {
    char pad[0x1b40];
    u64_23d30 value;
};
void __fastcall target(Obj_23d30* self, void*, u32_23d30 arg) {
    self->value = get_value(arg);
}