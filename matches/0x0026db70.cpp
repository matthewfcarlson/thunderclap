typedef unsigned int u32;
extern "C" void* __stdcall ConvertThreadToFiber(void*);
struct Obj { char pad0[8]; int (__cdecl *fn)(int); int arg; char pad10[12]; u32 field1c; u32 field20; char pad24[4]; u32 field28; char pad2c[12]; unsigned char field38; char pad39[3]; int result; };
extern "C" int __stdcall FUN_0026db70(Obj* p)
{
    p->field20 = 0;
    p->field1c = (u32)ConvertThreadToFiber(0);
    p->result = p->fn(p->arg);
    p->field38 = 0;
    p->field28 = 0;
    return 0;
}