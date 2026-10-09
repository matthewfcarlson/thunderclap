typedef unsigned int u32;
struct Caller { u32 Get(); };
extern void __cdecl FUN_00246f50(u32, const char*, u32);
void __cdecl FUN_0025bcb0(u32* param_1, Caller* param_2) {
    u32 first = *param_1;
    u32 value = param_2->Get();
    FUN_00246f50(first, "%s", value);
}