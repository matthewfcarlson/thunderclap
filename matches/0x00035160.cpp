struct Blk { unsigned int v[16]; };
struct X { void *get(); };
struct Y { char pad[0x10]; Blk *get(); };
struct Target { char pad[0x10]; X *x; bool f(Blk *out); };
bool Target::f(Blk *out) {
    void *p = x->get();
    if (p) {
        Blk *src = ((Y *)((char *)p + 0x10))->get();
        *out = *src;
        return true;
    }
    return false;
}
