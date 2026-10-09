typedef unsigned int u32;
extern void __cdecl F1(void*, int, int);
extern void __cdecl F2(void*, int);
extern void __cdecl F3(void*, int);
extern void __cdecl F4(void*, const void*, int);
int __cdecl Target(void* p)
{
    F1(p, 1, 0);
    F1(p, 2, 0);
    F2(p, 2);
    F3(p, 0);
    F4(p, (const void*)0x33cdb0, 3);
    return 1;
}