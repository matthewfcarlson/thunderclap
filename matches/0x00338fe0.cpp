typedef unsigned int u32_338fe0;
extern int __cdecl Check(u32_338fe0, u32_338fe0);
extern void __cdecl Report(u32_338fe0, const char*, u32_338fe0);
void __cdecl FUN_00338fe0(u32_338fe0 a, u32_338fe0 b, u32_338fe0 c) {
    if (!Check(a, b))
        Report(a, "stack overflow (%s)", c);
}