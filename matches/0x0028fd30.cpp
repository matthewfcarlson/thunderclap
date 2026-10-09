// Same code shape as 0x001a9260 (propagated; names are from that function)
struct Obj {
    Obj* Get();
    Obj* Tail();
    Obj* Target();
};
extern int __cdecl FUN_00344e74(Obj*, int, void*, void*, int);
extern void* g1;
extern void* g2;
Obj* Obj::Target() {
    Obj* p = Get();
    if (FUN_00344e74(p, 0, &g1, &g2, 0))
        return p;
    return Tail();
}