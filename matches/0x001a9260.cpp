struct Obj_1a9260 {
    Obj_1a9260* Get();
    Obj_1a9260* Tail();
    Obj_1a9260* Target();
};
extern int __cdecl FUN_00344e74(Obj_1a9260*, int, void*, void*, int);
extern void* g1_1a9260;
extern void* g2_1a9260;
Obj_1a9260* Obj_1a9260::Target() {
    Obj_1a9260* p = Get();
    if (FUN_00344e74(p, 0, &g1_1a9260, &g2_1a9260, 0))
        return p;
    return Tail();
}