struct F {
    unsigned lo, hi;
};
inline F Or(const F& a, const F& b) {
    F r;
    r.lo = a.lo | b.lo;
    r.hi = a.hi | b.hi;
    return r;
}
struct Inner {
    char pad[0x58];
    F a, b;
};
struct Obj {
    char pad[0x74];
    Inner* in;
};
struct Mgr {
    void Apply(Inner*);
};
struct Foo {
    char pad[8];
    Mgr* mgr;
    bool Fn(Obj* o);
};
extern F g39e8, g39f0, g3a10, g3a18, g3a20;
bool Foo::Fn(Obj* o) {
    if (!o)
        return false;
    Inner* i = o->in;
    if (!i)
        return false;
    i->a = g3a10;
    i->b = Or(g3a20, Or(g3a18, Or(g39e8, g39f0)));
    mgr->Apply(i);
    return true;
}
