typedef unsigned int u32_24c310;
typedef int i32_24c310;
extern u32_24c310 table_24c310[64];
u32_24c310 __cdecl FUN_0024c310(i32_24c310* param_1) {
    return table_24c310[((*param_1 << 28) >> 28) * 6];
}