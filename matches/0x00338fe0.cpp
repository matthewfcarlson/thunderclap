typedef unsigned int u32;
extern int __cdecl Check(u32, u32);
extern void __cdecl Report(u32, const char *, u32);
void __cdecl FUN_00338fe0(u32 a, u32 b, u32 c) {
    if (!Check(a, b)) Report(a, "stack overflow (%s)", c);
}