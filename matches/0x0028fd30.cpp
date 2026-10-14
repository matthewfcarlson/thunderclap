// Same code shape as 0x001a9260 (propagated; names are from that function)
struct Obj_28fd30 {
    Obj_28fd30* Get();
    Obj_28fd30* Tail();
    Obj_28fd30* Target();
};
extern int __cdecl FUN_00344e74(Obj_28fd30*, int, void*, void*, int);
extern void* g1_28fd30;
extern void* g2_28fd30;
Obj_28fd30* Obj_28fd30::Target() {
    Obj_28fd30* p = Get();
    if (FUN_00344e74(p, 0, &g1_28fd30, &g2_28fd30, 0))
        return p;
    return Tail();
}