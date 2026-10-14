extern "C" void* __cdecl FUN_00266e00(void*, int);
struct Obj_334010 {
    int FUN_00333f10();
};
extern void* g_value_334010;
extern "C" int __cdecl target(void* p) {
    g_value_334010 = p;
    Obj_334010* q = (Obj_334010*)FUN_00266e00(p, 0x1dc);
    if (q)
        return q->FUN_00333f10();
    return 0;
}