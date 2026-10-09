// Same code shape as 0x0004a2d0 (propagated; names are from that function)
struct Obj { char pad[0x330]; int a; int b; int c; };
struct Helper { Obj* First(); };
struct ObjHelper { Obj* Second(); };
struct CGrappleMotionStateCondition { int vfunc_8(int); };
int CGrappleMotionStateCondition::vfunc_8(int p) {
    if (!p) return 0;
    Helper* h = (Helper*)p;
    Obj* x = h->First();
    x = ((ObjHelper*)x)->Second();
    if (x->b) return x->b;
    if (x->a) return x->a;
    return x->c;
}