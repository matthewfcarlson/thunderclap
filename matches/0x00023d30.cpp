typedef unsigned int u32;
typedef unsigned __int64 u64;
extern u64 __cdecl get_value(u32);
struct Obj { char pad[0x1b40]; u64 value; };
void __fastcall target(Obj* self, void*, u32 arg) { self->value = get_value(arg); }