// Same code shape as 0x001b8900. FUN_001c3d90 is the 0-argument singleton getter; param_1 is the method's argument.
typedef unsigned int u32_1b92c0;
struct Registry_1b92c0 {
    void FUN_001c4090(u32_1b92c0);
};
Registry_1b92c0* FUN_001c3d90();
void __stdcall target(u32_1b92c0 param_1) {
    FUN_001c3d90()->FUN_001c4090(param_1);
}
