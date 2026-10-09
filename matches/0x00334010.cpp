extern "C" void* __cdecl FUN_00266e00(void*, int);
struct Obj { int FUN_00333f10(); };
extern void* g_value;
extern "C" int __cdecl target(void* p) {
    g_value = p;
    Obj* q = (Obj*)FUN_00266e00(p, 0x1dc);
    if (q) return q->FUN_00333f10();
    return 0;
}