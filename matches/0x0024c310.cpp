typedef unsigned int u32;
typedef int i32;
extern u32 table[64];
u32 __cdecl FUN_0024c310(i32 *param_1) {
    return table[((*param_1 << 28) >> 28) * 6];
}