// The name's hash key (0x0027afb0) kept at +0x1b40.
typedef unsigned __int64 u64_23d30;
extern "C" u64_23d30 __cdecl FUN_0027afb0(const char* name);
struct Obj_23d30 {
    char pad[0x1b40];
    u64_23d30 value;
};
void __fastcall target(Obj_23d30* self, void*, const char* name) {
    self->value = FUN_0027afb0(name);
}
