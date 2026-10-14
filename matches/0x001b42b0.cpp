struct F_1b42b0 {
    unsigned lo, hi;
};
inline F_1b42b0 Or(const F_1b42b0& a, const F_1b42b0& b) {
    F_1b42b0 r;
    r.lo = a.lo | b.lo;
    r.hi = a.hi | b.hi;
    return r;
}
struct Inner_1b42b0 {
    char pad[0x58];
    F_1b42b0 a, b;
};
struct Obj_1b42b0 {
    char pad[0x74];
    Inner_1b42b0* in;
};
struct Mgr_1b42b0 {
    void Apply(Inner_1b42b0*);
};
struct Foo_1b42b0 {
    char pad[8];
    Mgr_1b42b0* mgr;
    bool Fn(Obj_1b42b0* o);
};
extern F_1b42b0 g39e8, g39f0, g3a10, g3a18, g3a20;
bool Foo_1b42b0::Fn(Obj_1b42b0* o) {
    if (!o)
        return false;
    Inner_1b42b0* i = o->in;
    if (!i)
        return false;
    i->a = g3a10;
    i->b = Or(g3a20, Or(g3a18, Or(g39e8, g39f0)));
    mgr->Apply(i);
    return true;
}
